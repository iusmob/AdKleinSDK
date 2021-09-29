//
//  AdKleinSDKBannerAdView.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/12.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN


@class AdKleinSDKBannerAdView;

@protocol AdKleinSDKBannerAdViewDelegate <NSObject>
@optional

/**
 广告拉取成功
 @param bannerAdView 广告加载器实例
*/
- (void)ak_bannerAdDidLoad:(AdKleinSDKBannerAdView *)bannerAdView;
/**
 广告拉取失败
 @param bannerAdView 广告加载器实例
 @param error 错误描述
*/
- (void)ak_bannerAdDidFail:(AdKleinSDKBannerAdView *)bannerAdView withError:(NSError *)error;
/**
 广告展示
 @param bannerAdView 广告加载器实例
*/
- (void)ak_bannerAdDidShow:(AdKleinSDKBannerAdView *)bannerAdView;
/**
 广告点击
 @param bannerAdView 广告加载器实例
*/
- (void)ak_bannerAdDidClick:(AdKleinSDKBannerAdView *)bannerAdView;
/**
 广告关闭
 @param bannerAdView 广告加载器实例
*/
- (void)ak_bannerAdDidClose:(AdKleinSDKBannerAdView *)bannerAdView;

@end

@interface AdKleinSDKBannerAdView : AdKleinSDKBaseObject

/**
 [可选]Banner展现和轮播时的动画效果开关，仅在部分上游可选。
*/
@property (nonatomic) BOOL animated;
/**
 [可选]广告刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
*/
@property (nonatomic) int autoSwitchInterval;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<AdKleinSDKBannerAdViewDelegate> delegate;

/**
 构造方法
 @param placementId 广告位 ID
 @param viewController 视图控制器
*/
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
