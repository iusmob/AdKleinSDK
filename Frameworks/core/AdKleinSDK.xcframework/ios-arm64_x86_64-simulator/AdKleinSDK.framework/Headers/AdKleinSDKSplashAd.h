//
//  AdKleinSDKSplashAd.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/7.
//

#import <AdKleinSDK/AdKleinSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class AdKleinSDKSplashAd;

@protocol AdKleinSDKSplashAdDelegate <NSObject>

@optional

/**
 广告拉取成功
 @param splashAd 广告加载器实例
*/
- (void)ak_splashAdDidLoad:(AdKleinSDKSplashAd *)splashAd;
/**
 广告拉取失败
 @param splashAd 广告加载器实例
 @param error 错误描述
*/
- (void)ak_splashAdDidFail:(AdKleinSDKSplashAd *)splashAd withError:(NSError *)error;
/**
 广告展示
 @param splashAd 广告加载器实例
*/
- (void)ak_splashAdDidShow:(AdKleinSDKSplashAd *)splashAd;
/**
 广告点击
 @param splashAd 广告加载器实例
*/
- (void)ak_splashAdDidClick:(AdKleinSDKSplashAd *)splashAd;
/**
 点击跳过
 @param splashAd 广告加载器实例
*/
- (void)ak_splashAdDidSkip:(AdKleinSDKSplashAd *)splashAd;
/**
 倒计时结束
 @param splashAd 广告加载器实例
*/
- (void)ak_splashAdTimeOver:(AdKleinSDKSplashAd *)splashAd;
/**
 广告关闭
 @param splashAd 广告加载器实例
*/
- (void)ak_splashAdDidClose:(AdKleinSDKSplashAd *)splashAd;

@end


@interface AdKleinSDKSplashAd : AdKleinSDKBaseObject
/**
 广告生命周期代理
*/
@property (nonatomic, weak) id<AdKleinSDKSplashAdDelegate> delegate;

/**
 [必选]广告加载window
*/
@property (nonatomic, weak) UIWindow* window;

/**
 [可选]底部bottomView
 详解：传入自定义view，用来显示广告接入方品牌，如果不传，则广告铺满全屏
 请注意：
 1、需设置高度，所占的空间不能过大，并保证高度不超过屏幕高度的25%，宽度为屏幕宽度
 2、需要设置为全局变量（兼容不同SDK）
*/
@property (nonatomic, weak) UIView* bottomView;

/**
 [可选]自定义跳过Button
 详解：传入自定义view，用来自定义跳过按钮，如果不传，会有默认跳过按钮
 请注意：
 1、需要设置为全局变量（兼容不同SDK）
 */
@property (nonatomic, weak) UIView* skipView;

/**
 [可选]拉取广告超时时间，默认为3秒
 详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) NSInteger timeout;

/**
 [可选]占位图
 详解：在发起请求到被成功展现前用于填充的占位图，避免当前页面内容先于开屏广告被看到，造成闪屏。默认是App启动图。
 */
@property (nonatomic, strong) UIView *placeholderView;

/**
 构造方法
 详解：
 @param placementId 广告位 ID
 @param window 展示开屏的容器
 */
- (instancetype)initWithPlacementId:(NSString *)placementId window:(UIWindow *)window;

/**
 移除广告
 详解：用于自定义跳过按钮点击事件调用
 */
- (void)removeSplashAd;

@end

NS_ASSUME_NONNULL_END

