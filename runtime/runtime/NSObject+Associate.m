//
//  NSObject+Associate.m
//  runtime
//
//  Created by Mac on 16/2/17.
//  Copyright © 2016年 hshd. All rights reserved.
//

#import "NSObject+Associate.h"
#import <objc/runtime.h>


@implementation NSObject (Associate)

- (id)associate
{
    return objc_getAssociatedObject(self, @selector(associate));
}

- (void)setAssociate:(id)associate
{
    objc_setAssociatedObject(self, @selector(associate), associate, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}


@end
