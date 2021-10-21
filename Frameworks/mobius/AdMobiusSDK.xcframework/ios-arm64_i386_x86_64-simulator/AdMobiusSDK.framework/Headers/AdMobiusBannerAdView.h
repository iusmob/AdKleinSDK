//
//  AdMobiusBannerAdView.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/7/8.
//  Copyright © 2021 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdMobiusBannerAdViewDelegate;

@interface AdMobiusBannerAdView : UIView
/**
 广告生命周期代理
*/
@property(nonatomic, weak, nullable) id<AdMobiusBannerAdViewDelegate> delegate;
/**
 广告位id
*/
@property(nonatomic, copy) NSString *slotId;
/**
 banner刷新时间间隔，30-120s之间.
*/
@property (nonatomic, assign) NSInteger refershTime;

/**
 请求超时时间,默认为4s,需要设置3s及以上
*/
@property (nonatomic, assign) NSInteger tolerateTimeout;
/**
 [必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
*/
@property (nonatomic, weak) UIViewController *controller;
/*
 初始化bannerView
 @param frame 期望的banner视图尺寸
*/
- (instancetype)initWithFrame:(CGRect)frame;
/**
 拉取广告
*/
- (void)load;

@end

@protocol AdMobiusBannerAdViewDelegate <NSObject>
@optional
/**
 广告拉取成功
 @param bannerAdView 广告加载器实例
*/
- (void)am_bannerAdViewDidLoad:(AdMobiusBannerAdView *)bannerAdView;
/**
 广告拉取失败
 @param bannerAdView 广告加载器实例
 @param error 错误描述
*/
- (void)am_bannerAdViewDidFail:(AdMobiusBannerAdView *)bannerAdView
            withError:(NSError * _Nullable)error;
/**
 广告展示
 @param bannerAdView 广告加载器实例
*/
- (void)am_bannerAdViewDidShow:(AdMobiusBannerAdView *)bannerAdView;
/**
 广告点击
 @param bannerAdView 广告加载器实例
*/
- (void)am_bannerAdViewDidClick:(AdMobiusBannerAdView *)bannerAdView;
/**
 广告关闭
 @param bannerAdView 广告加载器实例
*/
- (void)am_bannerAdViewDidClose:(AdMobiusBannerAdView *)bannerAdView;

@end

NS_ASSUME_NONNULL_END
