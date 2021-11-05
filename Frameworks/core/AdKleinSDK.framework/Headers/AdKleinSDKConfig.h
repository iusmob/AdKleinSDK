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
 * 初始化SDK
 * @param mediaId 媒体ID
 * 初始化SDK，并立即尝试获取媒体配置；
 * 后续请求广告位配置时，会等待获取媒体配置这个前置操作完成后再继续。
*/
+ (void)initMediaId:(NSString *)mediaId;
/**
 * 初始化SDK
 * @param mediaId 媒体ID
 * @param complete 媒体初始化完毕的回调方法
 * 初始化SDK，并立即尝试获取媒体配置；
 * 后续请求广告位配置时，会等待获取媒体配置这个前置操作完成后再继续。
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
