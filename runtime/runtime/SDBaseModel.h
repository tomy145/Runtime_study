//
//  SDBaseModel.h
//  runtime
//
//  Created by Mac on 16/2/14.
//  Copyright © 2016年 hshd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SDBaseModel : NSObject

+ (instancetype)modelWithDict:(NSDictionary *)dict;
- (instancetype)initWithDict:(NSDictionary *)dict;

/**
 *  model转字典
 *
 *  @param model 模型
 *
 *  @return 字典
 */
- (NSDictionary *)modelToDictionrary:( NSObject *)model;

/**
 *  保存Model
 *
 *  @param objct 对象
 *
 *  @return 是否保存成功
 */
+ (BOOL)saveModel:(NSObject *)objct;

/**
 *  获取保存沙盒的对象
 */
+ (instancetype)modelUserInfo;


@end
