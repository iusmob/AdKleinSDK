//
//  AdMobiusNativeAd.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/7/22.
//  Copyright © 2021 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdMobiusNativeAdData.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdMobiusNativeAdDelegate;

@interface AdMobiusNativeAd : NSObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak, nullable) id <AdMobiusNativeAdDelegate> delegate;
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
 拉取广告
*/
- (void)load;
/**
 *  构造方法
 @param adSize 广告尺寸
 */
- (instancetype)initWithAdSize:(CGSize)adSize;

@end

@protocol AdMobiusNativeAdDelegate <NSObject>

@optional
/**
 广告拉取成功
 获取到广告view后，需要根据data数据进行自渲染
 @param nativeAd 广告加载器实例
 @param adViews 自渲染广告视图数组
*/
- (void)am_nativeAdDidLoad:(AdMobiusNativeAd *)nativeAd
             withAdViews:(NSArray<__kindof UIView<AdMobiusNativeAdViewDelegate> *> *)adViews;
/**
 广告拉取失败
 @param nativeAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_nativeAdDidFail:(AdMobiusNativeAd *)nativeAd
              withError:(NSError *)error;

/**
 广告展示
 @param nativeAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)am_nativeAdDidShow:(AdMobiusNativeAd *)nativeAd
                       adView:(__kindof UIView<AdMobiusNativeAdViewDelegate> *)adView;

/**
 广告点击
 @param nativeAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)am_nativeAdDidClick:(AdMobiusNativeAd *)nativeAd
                      adView:(__kindof UIView<AdMobiusNativeAdViewDelegate> *)adView;

/**
 广告关闭
 @param nativeAd 广告加载器实例
 @param adView 自渲染广告视图
 */
- (void)am_nativeAdDidClose:(AdMobiusNativeAd *)nativeAd
                    adView:(__kindof UIView<AdMobiusNativeAdViewDelegate> *)adView;

@end

NS_ASSUME_NONNULL_END


