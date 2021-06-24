//
//  AdMobiusSplashAdView.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/9.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AdMobiusSplashAdViewDelegate;

NS_ASSUME_NONNULL_BEGIN


@interface AdMobiusSplashAdView : UIView

/**
 Maximum allowable load timeout, default 3s, unit s.
 */
@property(nonatomic, assign) NSTimeInterval tolerateTimeout;

@property(nonatomic, weak, nullable) id<AdMobiusSplashAdViewDelegate> delegate;

//是否需要自定义跳过 yes 自定义跳过按钮  NO 使用原生
@property(nonatomic, assign) BOOL hideSkipButton;

/*
 required.
 Root view controller for handling ad actions.
 */
@property(nonatomic, weak) UIViewController *rootViewController;

- (instancetype)initWithSlotID:(NSString *)slotID
                         frame:(CGRect)frame;


- (void)loadAdData;

@end


@protocol AdMobiusSplashAdViewDelegate <NSObject>

@optional

/**
 This method is called when splash ad material loaded successfully.
 */
- (void)splashAdDidLoad:(AdMobiusSplashAdView *)splashAd;

/**
 This method is called when splash ad material failed to load.
 @param error : the reason of error
 */
- (void)splashAd:(AdMobiusSplashAdView *)splashAd didFailWithError:(NSError * _Nullable)error;

/**
 This method is called when splash ad slot will be showing.
 */
- (void)splashAdDidShow:(AdMobiusSplashAdView *)splashAd;
/**
 This method is called when splash ad is clicked.
 */
- (void)splashAdDidClick:(AdMobiusSplashAdView *)splashAd;

/**
 This method is called when spalashAd countdown equals to zero
 */
- (void)splashAdTimeOver:(AdMobiusSplashAdView *)splashAd;

/**
 This method is called when spalashAd skip button  is clicked.
 */
- (void)splashAdDidClickSkip:(AdMobiusSplashAdView *)splashAd;

@end


NS_ASSUME_NONNULL_END
