//
//  AdMobiusRewardVideoAd.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/7/15.
//  Copyright © 2021 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdMobiusRewardVideoAdDelegate;

@interface AdMobiusRewardVideoAd : NSObject
/**
 广告生命周期代理
*/
@property(nonatomic, weak, nullable) id<AdMobiusRewardVideoAdDelegate> delegate;
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

@protocol AdMobiusRewardVideoAdDelegate <NSObject>
@optional
/**
 广告基础数据拉取成功
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidLoad:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 广告拉取失败
 @param rewardVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_rewardVideoAdDidFail:(AdMobiusRewardVideoAd *)rewardVideoAd withError:(NSError *)error;
/**
 广告视频数据下载完成。
 建议在此回调执行show方法。
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidDownload:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 广告渲染成功。
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidRenderSuccess:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 广告渲染或播放中发生错误
 @param rewardVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_rewardVideoAdDidRenderFail:(AdMobiusRewardVideoAd *)rewardVideoAd withError:(NSError *)error;
/**
 广告展示
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidShow:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 广告点击
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidClick:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 点击跳过
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidSkip:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 完成奖励发放条件
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidRewardEffective:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 视频播放完成
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidComplete:(AdMobiusRewardVideoAd *)rewardVideoAd;
/**
 广告关闭
 @param rewardVideoAd 广告加载器实例
*/
- (void)am_rewardVideoAdDidClose:(AdMobiusRewardVideoAd *)rewardVideoAd;

@end

NS_ASSUME_NONNULL_END
