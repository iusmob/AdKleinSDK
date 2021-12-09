//
//  AdKleinSDKInterstitialAd.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/13.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN


@class AdKleinSDKInterstitialAd;

@protocol AdKleinSDKInterstitialAdDelegate <NSObject>
@optional
/**
 广告拉取成功
 @param interstitialAd 广告加载器实例
*/
- (void)ak_interstitialAdDidLoad:(AdKleinSDKInterstitialAd *)interstitialAd;
/**
 广告拉取失败
 @param interstitialAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_interstitialAdDidFail:(AdKleinSDKInterstitialAd *)interstitialAd withError:(NSError *)error;
/**
 广告视频数据下载完成。
 在此回调后才可执行show方法。
 @param interstitialAd 广告加载器实例
*/
- (void)ak_interstitialAdDidDownload:(AdKleinSDKInterstitialAd *)interstitialAd;
/**
 广告渲染成功
 @param interstitialAd 广告加载器实例
*/
- (void)ak_interstitialAdDidRenderSuccess:(AdKleinSDKInterstitialAd *)interstitialAd;
/**
 广告渲染失败
 @param interstitialAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_interstitialAdDidRenderFail:(AdKleinSDKInterstitialAd *)interstitialAd withError:(NSError *)error;
/**
 广告展示
 @param interstitialAd 广告加载器实例
*/
- (void)ak_interstitialAdDidShow:(AdKleinSDKInterstitialAd *)interstitialAd;
/**
 广告点击
 @param interstitialAd 广告加载器实例
*/
- (void)ak_interstitialAdDidClick:(AdKleinSDKInterstitialAd *)interstitialAd;
/**
 广告关闭
 @param interstitialAd 广告加载器实例
*/
- (void)ak_interstitialAdDidClose:(AdKleinSDKInterstitialAd *)interstitialAd;

@end

@interface AdKleinSDKInterstitialAd : AdKleinSDKBaseObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<AdKleinSDKInterstitialAdDelegate> delegate;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;
/**
 [可选]广告尺寸，仅在部分支持非全屏插屏的上游生效
 */
@property (nonatomic, assign) CGSize adSize;
/**
 [可选]播放视频是否静音，默认YES，仅部分上游有效
*/
@property (nonatomic, assign) BOOL videoMuted;
/**
 [可选]请求超时时间，默认为4秒，请设置不低于3秒的值，以免影响收益
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;
/**
 *  构造方法
 @param placementId 广告位 ID
 @param viewController 视图控制器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                     viewController:(UIViewController *)viewController;


@end

NS_ASSUME_NONNULL_END
