//
//  AdKleinSDKBannerAd.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/12.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN


@class AdKleinSDKBannerAd;

@protocol AdKleinSDKBannerAdDelegate <NSObject>
@optional

/**
 广告拉取成功
 @param bannerAd 广告加载器实例
*/
- (void)ak_bannerAdDidLoad:(AdKleinSDKBannerAd *)bannerAd;
/**
 广告拉取失败
 @param bannerAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_bannerAdDidFail:(AdKleinSDKBannerAd *)bannerAd withError:(NSError *)error;
/**
 广告展示
 @param bannerAd 广告加载器实例
*/
- (void)ak_bannerAdDidShow:(AdKleinSDKBannerAd *)bannerAd;
/**
 广告点击
 @param bannerAd 广告加载器实例
*/
- (void)ak_bannerAdDidClick:(AdKleinSDKBannerAd *)bannerAd;
/**
 广告关闭
 @param bannerAd 广告加载器实例
*/
- (void)ak_bannerAdDidClose:(AdKleinSDKBannerAd *)bannerAd;

@end

@interface AdKleinSDKBannerAd : AdKleinSDKBaseObject

/**
 [可选]Banner展现和轮播时的动画效果开关，仅在部分上游可选。
*/
@property (nonatomic) BOOL animated;
/**
 [可选]广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
*/
@property (nonatomic) int autoSwitchInterval;
/**
 [必选]期望的banner视图尺寸
 */
@property (nonatomic, assign) CGRect bannerFrame;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;
/**
 [必选]展现横幅广告的容器
*/
@property (nonatomic, weak) UIView *adContainer;
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<AdKleinSDKBannerAdDelegate> delegate;

/**
 构造方法
 @param placementId 广告位 ID
 @param viewController 视图控制器
*/
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController;
/**
 立即移除广告
*/
- (void)removeAd;

@end

NS_ASSUME_NONNULL_END
