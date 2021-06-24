//
//  AdMobiusDataFlowAd.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/15.
//  Copyright © 2020 AdMobius. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AdMobiusApiAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdMobiusNativeAdDelegate;

@interface AdMobiusNativeAd : NSObject

/// really ad data
@property(nonatomic, strong, readonly) AdMobiusApiAd *adData;

/**
 required.
 Root view controller for handling ad actions.
 Action method includes is 'presentViewController'.
 */
@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, weak, nullable) id<AdMobiusNativeAdDelegate> delegate;


/// bind event
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

@end

@protocol AdMobiusNativeAdDelegate <NSObject>

/// 曝光上报
- (void)nativeAdDidDidShow:(AdMobiusNativeAd *)nativeAd;

///点击上报
- (void)nativeAdDidClick:(AdMobiusNativeAd *)nativeAd
                withView:(UIView *_Nullable)view;

@end

NS_ASSUME_NONNULL_END
