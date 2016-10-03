//
//  Person.m
//  runtime
//
//  Created by Mac on 15/12/29.
//  Copyright © 2015年 hshd. All rights reserved.
//

#import "Person.h"
#import <objc/runtime.h>

@interface Person()//<NSCoding>
{
    NSString *var;
}
@property (nonatomic , copy) NSString * nickName;


@end

@implementation Person

+ (instancetype)persionWithDict:(NSDictionary *)dict
{

    return [[self alloc] initWithDict:dict];
}

- (instancetype)initWithDict:(NSDictionary *)dict
{
    if (self = [super init])
    {
        self = [super initWithDict:dict];
//        //字典转Model
//        uint count = 0;
//        
//        Ivar *ivar = class_copyIvarList([self class], &count);
//        
//        for (int i = 0; i < count; i++)
//        {
//            Ivar iv = ivar[i];
//            
//            const char *ivarN =  ivar_getName(iv);
//            
//            NSString *varNameStr = [[NSString alloc] initWithCString:ivarN encoding:NSUTF8StringEncoding];
//            
//            
//           NSString *varName = [varNameStr stringByReplacingOccurrencesOfString:@"_" withString:@""];
//            
//            id value = [dict objectForKey:varName];
//            
//            NSLog(@"varname -- %@ --- value --- %@",varNameStr,value);
//
//            
//            if (value)
//            {
//                [self setValue:value forKeyPath:varNameStr];
//            }
//            
//        }
//        
//        free(ivar);
        
        
    }
    
    return self;
}

//- (void)encodeWithCoder:(NSCoder *)aCoder
//{
//
//}
//
//
//- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder
//{
//    
//}



- (NSString *)description
{
    return [NSString stringWithFormat:@"\t\n  name -- %@ \t\n  age - %d",self.name,self.age];
}


@end
