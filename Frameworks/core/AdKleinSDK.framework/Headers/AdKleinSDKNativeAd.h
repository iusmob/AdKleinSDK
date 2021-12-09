//
//  AdKleinSDKNativeAd.h
//  AdKleinSDK
//
//  Created by mirari on 2021/5/10.
//  Copyright © 2021 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>
#import "AdKleinSDKNativeAdData.h"

NS_ASSUME_NONNULL_BEGIN

@class AdKleinSDKNativeAd;

@protocol AdKleinSDKNativeAdDelegate <NSObject>

@optional
/**
 广告拉取成功
 获取到广告view后，需要根据data数据进行自渲染
 @param nativeAd 广告加载器实例
 @param adViews 自渲染广告视图数组
*/
- (void)ak_nativeAdDidLoad:(AdKleinSDKNativeAd *)nativeAd
             withAdViews:(NSArray<__kindof UIView<AdKleinSDKNativeAdViewDelegate> *> *)adViews;
/**
 广告拉取失败
 @param nativeAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_nativeAdDidFail:(AdKleinSDKNativeAd *)nativeAd
              withError:(NSError *)error;

/**
 广告展示
 @param nativeAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)ak_nativeAdDidShow:(AdKleinSDKNativeAd *)nativeAd
                       adView:(__kindof UIView<AdKleinSDKNativeAdViewDelegate> *)adView;

/**
 广告点击
 @param nativeAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)ak_nativeAdDidClick:(AdKleinSDKNativeAd *)nativeAd
                      adView:(__kindof UIView<AdKleinSDKNativeAdViewDelegate> *)adView;

/**
 广告关闭
 @param nativeAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)ak_nativeAdDidClose:(AdKleinSDKNativeAd *)nativeAd
                    adView:(__kindof UIView<AdKleinSDKNativeAdViewDelegate> *)adView;

@end

/// 信息流 - 自渲染
@interface AdKleinSDKNativeAd : AdKleinSDKBaseObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id <AdKleinSDKNativeAdDelegate> delegate;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;
/**
 [可选]加载广告的个数，默认为1，部分上游只能为1
*/
@property (nonatomic, assign) NSInteger adCount;
/**
 [可选]播放视频是否静音，默认YES，仅部分上游有效
*/
@property (nonatomic, assign) BOOL videoMuted;
/**
 [可选]请求超时时间，默认为4秒，请设置不低于3秒的值，以免影响收益
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;
/**
   获取到的广告视图数组
*/
@property(nonatomic, strong) NSArray *adViews;
/**
 *  构造方法
 @param placementId 广告位 ID
 @param viewController 视图控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController;
/**
 *  构造方法
 @param adView 自渲染广告视图
 @param views 要点击事件的视图
 */
- (void)registViews:(UIView<AdKleinSDKNativeAdViewDelegate> *)adView withViews:(NSArray <UIView *>*)views;
@end

NS_ASSUME_NONNULL_END

