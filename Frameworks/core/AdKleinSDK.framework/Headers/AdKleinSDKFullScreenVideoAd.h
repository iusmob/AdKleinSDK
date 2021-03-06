//
//  AdKleinSDKFullScreenVideoAd.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/13.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN


@class AdKleinSDKFullScreenVideoAd;

@protocol AdKleinSDKFullScreenVideoAdDelegate <NSObject>
@optional
/**
 广告拉取成功
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidLoad:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告拉取失败
 @param fullScreenVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_fullScreenVideoAdDidFail:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd withError:(NSError *)error;
/**
 广告视频数据下载完成。
 在此回调后才可执行show方法。
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidDownload:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告渲染成功
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidRenderSuccess:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告播放中发生错误
 @param fullScreenVideoAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_fullScreenVideoAdDidRenderFail:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd withError:(NSError *)error;
/**
 广告展示
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidShow:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告点击
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidClick:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 点击跳过
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidSkip:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 视频播放完成
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidComplete:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;
/**
 广告关闭
 @param fullScreenVideoAd 广告加载器实例
*/
- (void)ak_fullScreenVideoAdDidClose:(AdKleinSDKFullScreenVideoAd *)fullScreenVideoAd;

@end

@interface AdKleinSDKFullScreenVideoAd : AdKleinSDKBaseObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<AdKleinSDKFullScreenVideoAdDelegate> delegate;
/**
 在initWithPlacementId方法中传入的视图控制器
*/
@property (nonatomic, weak) UIViewController *viewController;
/**
 [可选]播放视频是否静音，仅部分上游有效
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
