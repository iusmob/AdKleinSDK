//
//  AdKleinSDKConfig.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdKleinSDKConfig : NSObject

/**
 初始化SDK
 @param mediaId 媒体ID
*/
+ (void)initMediaId:(NSString *)mediaId;
/**
 初始化SDK
 @param mediaId 媒体ID
 @param complete 回调方法
*/
+ (void)initMediaId:(NSString *)mediaId onComplete:(nullable void(^)(NSError *_Nullable error))complete;
/**
 开启debug模式，输出详细日志
*/
+ (void)debugMode;
/**
 当前SDK版本号
*/
+ (NSString *)sdkVersion;
/**
 当前SDK版本Code
*/
+ (NSString *)sdkVersionCode;


@end

NS_ASSUME_NONNULL_END
