//
//  AdKleinSDKRewardVideoAd.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/12.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class AdKleinSDKRewardVideoAd;

@protocol AdKleinSDKRewardVideoAdDelegate <NSObject>

@optional

/**
 广告基础数据拉取成功
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidLoad:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 广告拉取失败
 @param rewardVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_rewardVideoAdDidFail:(AdKleinSDKRewardVideoAd *)rewardVideoAd withError:(NSError *)error;
/**
 广告视频数据下载完成。
 在此回调后才可执行show方法。
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidDownload:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 广告播放中发生错误
 @param rewardVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_rewardVideoAdDidRenderFail:(AdKleinSDKRewardVideoAd *)rewardVideoAd withError:(NSError *)error;
/**
 广告展示
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidShow:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 广告点击
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidClick:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 点击跳过
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidSkip:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 完成奖励发放条件
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidRewardEffective:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 视频播放完成
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidComplete:(AdKleinSDKRewardVideoAd *)rewardVideoAd;
/**
 广告关闭
 @param rewardVideoAd 广告加载器实例
*/
- (void)ak_rewardVideoAdDidClose:(AdKleinSDKRewardVideoAd *)rewardVideoAd;

@end

@interface AdKleinSDKRewardVideoAd : AdKleinSDKBaseObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<AdKleinSDKRewardVideoAdDelegate> delegate;
/**
 [可选]播放视频是否静音
 */
@property (nonatomic) BOOL videoMuted;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;

/**
 *  构造方法
 @param placementId 广告位 ID
 @param viewController 视图控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
