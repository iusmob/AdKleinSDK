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

@property(nonatomic, copy) NSString *slotId;
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

- (instancetype)initWithSlotId:(NSString *)slotId
                         frame:(CGRect)frame;


- (void)load;

@end


@protocol AdMobiusSplashAdViewDelegate <NSObject>

@optional

/**
 This method is called when splash ad material loaded successfully.
 */
- (void)am_splashAdDidLoad:(AdMobiusSplashAdView *)splashAd;

/**
 This method is called when splash ad material failed to load.
 @param error : the reason of error
 */
- (void)am_splashAdDidFail:(AdMobiusSplashAdView *)splashAd withError:(NSError * _Nullable)error;

/**
 This method is called when splash ad slot will be showing.
 */
- (void)am_splashAdDidShow:(AdMobiusSplashAdView *)splashAd;
/**
 This method is called when splash ad is clicked.
 */
- (void)am_splashAdDidClick:(AdMobiusSplashAdView *)splashAd;

/**
 This method is called when spalashAd countdown equals to zero
 */
- (void)am_splashAdTimeOver:(AdMobiusSplashAdView *)splashAd;

/**
 This method is called when spalashAd skip button  is clicked.
 */
- (void)am_splashAdDidSkip:(AdMobiusSplashAdView *)splashAd;
/**
 This method is called when splash ad is closed.
 */
- (void)am_splashAdDidClose:(AdMobiusSplashAdView *)splashAd;

@end


NS_ASSUME_NONNULL_END
