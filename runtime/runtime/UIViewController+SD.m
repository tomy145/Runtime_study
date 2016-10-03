//
//  UIViewController+SD.m
//  runtime
//
//  Created by Mac on 2016/9/23.
//  Copyright © 2016年 hshd. All rights reserved.
//

#import "UIViewController+SD.h"
#import <objc/objc.h>
#import <objc/runtime.h>
#import <objc/NSObjCRuntime.h>
#import <objc/objc-runtime.h>
#import <objc/objc-class.h>
#import <objc/Object.h>
#import <objc/objc-api.h>
#import <objc/objc-sync.h>

@implementation UIViewController (SD)

+ (void)initialize
{
    NSLog(@" --- self -- %@",self);
    const char * className = class_getName(self);

//    class_copyMethodList
    unsigned  int count = 0;
    Method *list = NULL;
    
    list = class_copyMethodList(objc_getClass(className), &count);


    for (int i = 0; i < count; i++)
    {
        Method m = list[i];

        struct objc_method_description *ls =  method_getDescription(m);
        IMP im1 = class_getMethodImplementation(objc_getClass(className), ls->name);



        NSLog(@"selname -- %s",sel_getName(ls->name));

        NSLog(@"sel_type -- %s",ls->types);


//        OBJC_EXPORT IMP class_getMethodImplementation(Class cls, SEL name)

        

    }

    if (list != NULL)
    {
        free(list);
        list = NULL;
    }

}

@end
