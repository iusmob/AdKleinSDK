//
//  AdKleinSDKNativeExpressAd.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/13.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class AdKleinSDKNativeExpressAd;

@protocol AdKleinSDKNativeExpressAdViewDelegate

/**
  渲染广告，穿山甲广告在渲染后才能得到真实高度
 */
- (void)render;

@end

@protocol AdKleinSDKNativeExpressAdDelegate <NSObject>

@optional
/**
 广告拉取成功
 获取到广告view后，需要执行render方法进行渲染
 @param nativeExpressAd 广告加载器实例
 @param adViews 模板广告视图数组
*/
- (void)ak_nativeExpressAdDidLoad:(AdKleinSDKNativeExpressAd *)nativeExpressAd
             withAdViews:(NSArray<__kindof UIView<AdKleinSDKNativeExpressAdViewDelegate> *> *)adViews;
/**
 广告拉取失败
 @param nativeExpressAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_nativeExpressAdDidFail:(AdKleinSDKNativeExpressAd *)nativeExpressAd
              withError:(NSError *)error;
/**
 广告渲染成功
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)ak_nativeExpressAdDidRenderSuccess:(AdKleinSDKNativeExpressAd *)nativeExpressAd
                       adView:(__kindof UIView<AdKleinSDKNativeExpressAdViewDelegate> *)adView;
/**
 广告渲染失败
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)ak_nativeExpressAdDidRenderFail:(AdKleinSDKNativeExpressAd *)nativeExpressAd
                       adView:(__kindof UIView<AdKleinSDKNativeExpressAdViewDelegate> *)adView;
/**
 广告展现
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)ak_nativeExpressAdDidShow:(AdKleinSDKNativeExpressAd *)nativeExpressAd
                      adView:(__kindof UIView<AdKleinSDKNativeExpressAdViewDelegate> *)adView;
/**
 广告点击
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)ak_nativeExpressAdDidClick:(AdKleinSDKNativeExpressAd *)nativeExpressAd
                      adView:(__kindof UIView<AdKleinSDKNativeExpressAdViewDelegate> *)adView;

/**
 广告关闭
 @param nativeExpressAd 广告加载器实例
 @param adView 模板广告视图
 */
- (void)ak_nativeExpressAdDidClose:(AdKleinSDKNativeExpressAd *)nativeExpressAd
                    adView:(__kindof UIView<AdKleinSDKNativeExpressAdViewDelegate> *)adView;

@end


/// 信息流 - 模版渲染
@interface AdKleinSDKNativeExpressAd : AdKleinSDKBaseObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id <AdKleinSDKNativeExpressAdDelegate> delegate;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;
/**
 [必选]广告尺寸
*/
@property (nonatomic, assign) CGSize adSize;
/**
 [可选]加载广告的个数，默认为1，部分上游只能为1
*/
@property (nonatomic, assign) NSInteger adCount;
/**
 [可选]非 WiFi 网络是否自动播放。默认 NO。loadAd 前设置。
*/
@property (nonatomic, assign) BOOL videoAutoPlayOnWWAN;
/**
 [可选]自动播放时，是否静音。默认 YES。loadAd 前设置。
*/
@property (nonatomic, assign) BOOL videoMuted;
/**
 [可选]视频详情页播放时是否静音。默认NO。loadAd 前设置。
 */
@property (nonatomic, assign) BOOL detailPageVideoMuted;
/**
 [可选]请求视频的时长下限，视频时长有效值范围为[5,60]。
 以下两种情况会使用系统默认的最小值设置，1:不设置  2:minVideoDuration大于maxVideoDuration
*/
@property (nonatomic) NSInteger minVideoDuration;
/**
 [可选]请求视频的时长上限，视频时长有效值范围为[5,60]。
 */
@property (nonatomic) NSInteger maxVideoDuration;
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


@end

@interface AdKleinSDKNativeExpressAdView : UIView <AdKleinSDKNativeExpressAdViewDelegate>
/**
  该广告所属的广告加载器
 */
@property (nonatomic, weak) AdKleinSDKNativeExpressAd *adLoader;
/**
  信息流广告view的上游原始广告视图
 */
@property (nonatomic, strong) id sourceView;
/**
  信息流广告view的上游原始广告加载器
 */
@property (nonatomic, strong) id sourceLoader;
@end

NS_ASSUME_NONNULL_END


