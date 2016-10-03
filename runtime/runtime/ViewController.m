//
//  ViewController.m
//  runtime
//
//  Created by Mac on 15/12/29.
//  Copyright © 2015年 hshd. All rights reserved.
//

#import "ViewController.h"
#import "Person.h"
#import <objc/runtime.h>
#import "NSObject+Associate.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];


    self.associate = @"";

    NSDictionary *dict = @{@"name":@"张三",@"age":@"20"};
    Person *per = [Person persionWithDict:dict];
    NSLog(@"per--- %@",per);
    
    
//    1、模型转字典
    NSDictionary *dic = [per modelToDictionrary:per];
    NSLog(@"dic -- %@",dic);
    
//    2、自动解档归档
    NSLog(@"是否保存成功 -- %d",[Person saveModel:per]);
    NSLog(@"读取 --- %@",[Person modelUserInfo]);
    
    
//    3、给分类添加属性
    NSObject *obj = [[NSObject alloc] init];
    obj.associate = @"关联对象。。。。";
    NSLog(@"associate --- %@ --- per -- %@",obj.associate,per.associate);
    NSLog(@"取消关联....");
    objc_setAssociatedObject(obj, @selector(associate), nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    NSLog(@"associate --- %@",obj.associate);
    
//    4、动态修改属性
    uint outCount = 0;
    
    Ivar *ivarList = class_copyIvarList(per.class, &outCount);
    
    for (int i = 0 ; i < outCount; i++)
    {
        Ivar ivar = ivarList[i];
        
        NSString *varName = [NSString stringWithUTF8String:ivar_getName(ivar)];
        
        if ([varName isEqualToString:@"_name"])
        {
            object_setIvar(per, ivar, @"动态修改属性值");
        }
        
    }
    
    NSLog(@"修改后的值 --- %@",per.name);
    
//    动态添加属性
//    class_addProperty(<#__unsafe_unretained Class cls#>, <#const char *name#>, <#const objc_property_attribute_t *attributes#>, <#unsigned int attributeCount#>)
    
    const char *hei = "_height";
    const objc_property_attribute_t attr = {"d",""};
    
    bool state = class_addProperty(per.class, hei, &attr, 0);
    
    if (state)
    {
        NSLog(@"添加成功 --- %@",per);
    }
    
    Person *p1 = [[Person alloc] init];
    NSLog(@"p1 --- %@",p1);
    
    
    
//    动态移除属性
//    class_replaceProperty(<#__unsafe_unretained Class cls#>, <#const char *name#>, <#const objc_property_attribute_t *attributes#>, <#unsigned int attributeCount#>)

    
    
    
    
    
//    添加成员变量
//    class_addIvar(<#__unsafe_unretained Class cls#>, <#const char *name#>, <#size_t size#>, <#uint8_t alignment#>, <#const char *types#>)
//    动态设置成员变量的值
//    object_setIvar(<#id obj#>, <#Ivar ivar#>, <#id value#>)
//    动态添加方法 和移除方法
//    class_addMethod(<#__unsafe_unretained Class cls#>, <#SEL name#>, <#IMP imp#>, <#const char *types#>)
//    class_replaceMethod(<#__unsafe_unretained Class cls#>, <#SEL name#>, <#IMP imp#>, <#const char *types#>)
    
//     获取实例变量
//    class_getInstanceVariable(<#__unsafe_unretained Class cls#>, <#const char *name#>)
//     获取类名
//    class_getName(<#__unsafe_unretained Class cls#>)
//    获取属性
//    class_getProperty(<#__unsafe_unretained Class cls#>, <#const char *name#>)
//    获取父类
//    class_getSuperclass(<#__unsafe_unretained Class cls#>)
//    获取类方法
//    class_getClassMethod(<#__unsafe_unretained Class cls#>, <#SEL name#>)
//    获取实例大小
//    class_getInstanceSize(<#__unsafe_unretained Class cls#>)
//    获取类变量
//    class_getClassVariable(<#__unsafe_unretained Class cls#>, <#const char *name#>)
//    获取实例方法
//    class_getInstanceMethod(<#__unsafe_unretained Class cls#>, <#SEL name#>)
//    获取实例方法实现
//    class_getMethodImplementation(<#__unsafe_unretained Class cls#>, <#SEL name#>)

    
    
//    对象相关方法
//    获取一个对象的成员变量的值
//    object_getIvar(<#id obj#>, <#Ivar ivar#>)
//    设置一个对象的成员变量值
//    object_setIvar(<#id obj#>, <#Ivar ivar#>, <#id value#>)
    
//    根据一个对象获取一个类
//    object_getClass(<#id obj#>)
//    设置一个类
//    object_setClass(<#id obj#>, <#__unsafe_unretained Class cls#>)
    
//    根据对象获取类名
//    object_getClassName(<#id obj#>)
    
//    获取关联对象
//    objc_getAssociatedObject(<#id object#>, <#const void *key#>)
//    设置关联对象
//    objc_setAssociatedObject(<#id object#>, <#const void *key#>, <#id value#>, <#objc_AssociationPolicy policy#>)
    
//    获取一个类
//    objc_getClass(<#const char *name#>)
    
//    获取一个协议
//    objc_getProtocol(<#const char *name#>)
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}














//#include <objc/runtime.h>
//#import <Foundation/Foundation.h>
//
//@interface SomeClass : NSObject {
//    NSString *_privateName;
//}
//@end
//
//@implementation SomeClass
//- (id)init {
//    self = [super init];
//    if (self) _privateName = @"Steve";
//    return self;
//}
//@end
//NSString *nameGetter(id self, SEL _cmd) {
//    Ivar ivar = class_getInstanceVariable([SomeClass class], "_privateName");
//    return object_getIvar(self, ivar);
//}
//
//void nameSetter(id self, SEL _cmd, NSString *newName) {
//    Ivar ivar = class_getInstanceVariable([SomeClass class], "_privateName");
//    id oldName = object_getIvar(self, ivar);
//    if (oldName != newName) object_setIvar(self, ivar, [newName copy]);
//}
//
//int main(void)
//{
//    @autoreleasepool
//    {
//        objc_property_attribute_t type = { "T", "@\"NSString\"" };
//        
//        objc_property_attribute_t ownership = { "C", "" }; // C = copy
//        
//        objc_property_attribute_t backingivar  = { "V", "_privateName" };
//        
//        objc_property_attribute_t attrs[] = { type, ownership, backingivar };
//        
//        class_addProperty([SomeClass class], "name", attrs, 3);
//        
//        class_addMethod([SomeClass class], @selector(name), (IMP)nameGetter, "@@:");
//        
//        class_addMethod([SomeClass class], @selector(setName:), (IMP)nameSetter, "v@:@");
//        
//        id o = [SomeClass new];
//        NSLog(@"%@", [o name]);
//        [o setName:@"Jobs"];
//        NSLog(@"%@", [o name]);
//    }
//}









@end
