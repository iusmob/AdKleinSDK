//
//  AdMobiusInterstitialAd.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/11/29.
//  Copyright © 2021 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdMobiusInterstitialAdDelegate;

@interface AdMobiusInterstitialAd : NSObject
/**
 广告生命周期代理
*/
@property(nonatomic, weak, nullable) id<AdMobiusInterstitialAdDelegate> delegate;
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
 广告尺寸，传入宽度即可，高度自适应
 */
@property (nonatomic, assign) CGSize adSize;
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

@protocol AdMobiusInterstitialAdDelegate <NSObject>
@optional
/**
 广告基础数据拉取成功
 @param interstitialAd 广告加载器实例
*/
- (void)am_interstitialAdDidLoad:(AdMobiusInterstitialAd *)interstitialAd;
/**
 广告拉取失败
 @param interstitialAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_interstitialAdDidFail:(AdMobiusInterstitialAd *)interstitialAd withError:(NSError *)error;
/**
 广告视频数据下载完成。
 建议在此回调执行show方法。
 @param interstitialAd 广告加载器实例
*/
- (void)am_interstitialAdDidDownload:(AdMobiusInterstitialAd *)interstitialAd;
/**
 广告渲染成功。
 @param interstitialAd 广告加载器实例
*/
- (void)am_interstitialAdDidRenderSuccess:(AdMobiusInterstitialAd *)interstitialAd;
/**
 广告播放中发生错误
 @param interstitialAd 广告加载器实例
 @param error 错误描述
*/
- (void)am_interstitialAdDidRenderFail:(AdMobiusInterstitialAd *)interstitialAd withError:(NSError *)error;
/**
 广告展示
 @param interstitialAd 广告加载器实例
*/
- (void)am_interstitialAdDidShow:(AdMobiusInterstitialAd *)interstitialAd;
/**
 广告点击
 @param interstitialAd 广告加载器实例
*/
- (void)am_interstitialAdDidClick:(AdMobiusInterstitialAd *)interstitialAd;
/**
 广告关闭
 @param interstitialAd 广告加载器实例
*/
- (void)am_interstitialAdDidClose:(AdMobiusInterstitialAd *)interstitialAd;

@end

NS_ASSUME_NONNULL_END
