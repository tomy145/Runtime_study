//
//  Person.h
//  runtime
//
//  Created by Mac on 15/12/29.
//  Copyright © 2015年 hshd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDBaseModel.h"

@interface Person : SDBaseModel

@property (nonatomic , copy) NSString * name;
@property (nonatomic , assign) int  age;

+ (instancetype)persionWithDict:(NSDictionary *)dict;
- (instancetype)initWithDict:(NSDictionary *)dict;


@end
