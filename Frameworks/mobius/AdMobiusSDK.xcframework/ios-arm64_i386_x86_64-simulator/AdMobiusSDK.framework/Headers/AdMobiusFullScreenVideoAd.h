//
//  AdMobiusFullScreenVideoAd.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/11/29.
//  Copyright © 2021 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdMobiusFullScreenVideoAdDelegate;

@interface AdMobiusFullScreenVideoAd : NSObject
/**
 广告生命周期代理
*/
@property(nonatomic, weak, nullable) id<AdMobiusFullScreenVideoAdDelegate> delegate;
/**
 广告位id
*/
@property(nonatomic, copy) NSString *slotId;
/**
 请求超时时间,默认为4s,需要设置3s及以上
*/
@property (nonatomic, assign) NSInteger tolerateTimeout;
/**
 [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;
/**
 视频是否静音，默认为NO
*/
@property (nonatomic, assign) BOOL videoMuted;
/**
 拉取广告
*/
- (void)load;
/**
 展现广告
*/
- (void)show;

@end

@protocol AdMobiusFullScreenVideoAdDelegate <NSObject>
@optional
/**
 广告基础数据拉取成功
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidLoad:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告拉取失败
 @param fullScreenVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_fullScreenVideoAdDidFail:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd withError:(NSError *)error;
/**
 广告视频数据下载完成。
 建议在此回调执行show方法。
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidDownload:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告渲染成功。
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidRenderSuccess:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告播放中发生错误
 @param fullScreenVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_fullScreenVideoAdDidRenderFail:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd withError:(NSError *)error;
/**
 广告展示
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidShow:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告点击
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidClick:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 点击跳过
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidSkip:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 视频播放完成
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidComplete:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告关闭
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)am_fullScreenVideoAdDidClose:(AdMobiusFullScreenVideoAd *)fullScreenVideoAd;

@end

NS_ASSUME_NONNULL_END
