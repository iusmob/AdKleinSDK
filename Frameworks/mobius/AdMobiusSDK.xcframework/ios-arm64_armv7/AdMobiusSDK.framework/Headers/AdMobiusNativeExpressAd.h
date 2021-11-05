//
//  AdMobiusNativeExpressAd.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/10/9.
//  Copyright © 2021 AdMobius. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@class AdMobiusNativeExpressAd;

@protocol AdMobiusNativeExpressAdViewDelegate
/**
 渲染广告视图
 */
- (void)am_render;
/**
  信息流广告的视频视图，只有类型为视频(AM_NATIVE_AD_VIDEO)时可用
 */
@property (nonatomic, strong) UIView *mediaView;
/**
  该广告所属的广告加载器
 */
@property (nonatomic, weak) AdMobiusNativeExpressAd *adLoader;

@end

@protocol AdMobiusNativeExpressAdDelegate;

@interface AdMobiusNativeExpressAd : NSObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak, nullable) id <AdMobiusNativeExpressAdDelegate> delegate;
/**
 广告位id
*/
@property(nonatomic, copy) NSString *slotId;
/**
 请求超时时间,默认为4s,需要设置3s及以上
*/
@property (nonatomic, assign) NSInteger tolerateTimeout;
/**
 视频是否静音，默认为NO
*/
@property (nonatomic, assign) BOOL videoMuted;
/**
 [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;
/**
 拉取广告
*/
- (void)load;
/**
 *  构造方法
 @param adSize 广告尺寸
 */
- (instancetype)initWithAdSize:(CGSize)adSize;

@end

@protocol AdMobiusNativeExpressAdDelegate <NSObject>

@optional
/**
 广告拉取成功
 获取到广告view后，需要根据data数据进行自渲染
 @param nativeExpressAd 广告加载器实例
 @param adViews 自渲染广告视图数组
*/
- (void)am_nativeExpressAdDidLoad:(AdMobiusNativeExpressAd *)nativeExpressAd
             withAdViews:(NSArray<__kindof UIView<AdMobiusNativeExpressAdViewDelegate> *> *)adViews;
/**
 广告拉取失败
 @param nativeExpressAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_nativeExpressAdDidFail:(AdMobiusNativeExpressAd *)nativeExpressAd
              withError:(NSError *)error;
/**
 广告渲染成功
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)am_nativeExpressAdDidRenderSuccess:(AdMobiusNativeExpressAd *)nativeExpressAd
                       adView:(__kindof UIView<AdMobiusNativeExpressAdViewDelegate> *)adView;
/**
 广告渲染失败
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)am_nativeExpressAdDidRenderFail:(AdMobiusNativeExpressAd *)nativeExpressAd
                       adView:(__kindof UIView<AdMobiusNativeExpressAdViewDelegate> *)adView;
/**
 广告展示
 @param nativeExpressAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)am_nativeExpressAdDidShow:(AdMobiusNativeExpressAd *)nativeExpressAd
                       adView:(__kindof UIView<AdMobiusNativeExpressAdViewDelegate> *)adView;

/**
 广告点击
 @param nativeExpressAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)am_nativeExpressAdDidClick:(AdMobiusNativeExpressAd *)nativeExpressAd
                      adView:(__kindof UIView<AdMobiusNativeExpressAdViewDelegate> *)adView;

/**
 广告关闭
 @param nativeExpressAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)am_nativeExpressAdDidClose:(AdMobiusNativeExpressAd *)nativeExpressAd
                    adView:(__kindof UIView<AdMobiusNativeExpressAdViewDelegate> *)adView;

@end

NS_ASSUME_NONNULL_END
