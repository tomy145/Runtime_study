//
//  SDBaseModel.m
//  runtime
//
//  Created by Mac on 16/2/14.
//  Copyright © 2016年 hshd. All rights reserved.
//

#import "SDBaseModel.h"
#import <objc/runtime.h>

@interface SDBaseModel()<NSCoding>

@end

@implementation SDBaseModel

+ (instancetype)modelWithDict:(NSDictionary *)dict
{
    return [[self alloc] initWithDict:dict];
}

- (instancetype)initWithDict:(NSDictionary *)dict
{
    if (self = [super init])
    {

//第二种方式 获取属性
        uint outCount = 0;
        objc_property_t *proList = class_copyPropertyList(self.class, &outCount);

        for (int i = 0; i < outCount; i++)
        {
            objc_property_t pro = proList[i];
            const char *proName = property_getName(pro);
            NSString *p_Name = [[NSString alloc] initWithCString:proName encoding:NSUTF8StringEncoding];
            id value = [dict objectForKey:p_Name];
            if (value)
            {
                [self setValue:value forKeyPath:p_Name];
            }
            NSLog(@"proname -- %@",p_Name);

        }
        free(proList);

    }

    return self;
}

/**
 *  归档
 *
 *  @param enCoder 归档
 */
- (void)encodeWithCoder:(NSCoder *)enCoder
{
    uint count = 0;
    objc_property_t *propertyList = class_copyPropertyList(self.class, &count);
    for (int i = 0; i<count; i++)
    {
        objc_property_t property = propertyList[i];
        const char *name = property_getName(property);
        NSString *key = [NSString stringWithUTF8String:name];
        id value = [self valueForKey:key];
        [enCoder encodeObject:value forKey:key];
    }
    free(propertyList);
}

/**
 *  解档
 *
 *  @param decoder 解档
 *
 *  @return 实例
 */
- (nullable instancetype)initWithCoder:(NSCoder *)decoder
{
    self = [super init];
    if (self)
    {
        uint count = 0;
        objc_property_t *propertyList = class_copyPropertyList(self.class, &count);
        for (int i = 0; i<count; i++)
        {
            objc_property_t property = propertyList[i];
            const char *name = property_getName(property);
            NSString *key = [NSString stringWithUTF8String:name];
            id value = [decoder decodeObjectForKey:key];
            // 设置到成员变量身上
            [self setValue:value forKey:key];
        }
        free(propertyList);
    }
    return self;
}

/**
 *  保存Model
 *
 *  @param objct 对象
 *
 *  @return 是否保存成功
 */
+ (BOOL)saveModel:(NSObject *)objct
{
    NSString *docPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    const char *className = class_getName(objct.class);
    NSString *classN = [[NSString alloc] initWithCString:className encoding:NSUTF8StringEncoding];
    NSString *filePath = [docPath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.file",classN]];
    //    NSLog(@"filePath -- %@",filePath);
    return  [NSKeyedArchiver archiveRootObject:objct toFile:filePath];

}


/**
 *  获取保存沙盒的对象
 */
+ (instancetype)modelUserInfo
{
    NSString *docPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    const char *className = class_getName(self.class);
    NSString *classN = [[NSString alloc] initWithCString:className encoding:NSUTF8StringEncoding];
    NSString *filePath = [docPath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.file",classN]];
    id obj = [NSKeyedUnarchiver unarchiveObjectWithFile:filePath];
    return obj;
}



/**
 *  Model转字典
 *
 *  @param model
 *
 *  @return 字典
 */
- ( NSDictionary *)modelToDictionrary:(NSObject *)model
{
    NSMutableDictionary *dictM = [NSMutableDictionary dictionary];

//  获取属性数量
    uint outCount = 0;
//    拷贝所有属性链表
    objc_property_t *proList = class_copyPropertyList(self.class, &outCount);
    for (int i = 0; i < outCount; i++)
    {
//      遍历链表
        objc_property_t pro = proList[i];
//      取出属性名
        const char *proName = property_getName(pro);
        NSString *p_Name = [[NSString alloc] initWithCString:proName encoding:NSUTF8StringEncoding];
        id value = [model valueForKey:p_Name];
        if (value)
        {
            [dictM setValue:value forKeyPath:p_Name];
        }
        else
        {
            [dictM setValue:@"" forKeyPath:p_Name];
        }
        NSLog(@"proname -- %@   --- value -- %@",p_Name,value);
    }
    free(proList);

    return dictM;
}


@end
