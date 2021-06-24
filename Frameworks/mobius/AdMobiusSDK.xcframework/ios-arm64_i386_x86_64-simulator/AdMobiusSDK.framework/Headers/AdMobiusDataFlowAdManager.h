//
//  AdMobiusDataFlowAdManager.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/9.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdMobiusNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@class AdMobiusDataFlowSlot;
@protocol AdMobiusDataFlowAdManagerDelegate;

@interface AdMobiusDataFlowAdManager : NSObject

@property(nonatomic, weak) id<AdMobiusDataFlowAdManagerDelegate> delegate;

- (instancetype)initWithSlot:(AdMobiusDataFlowSlot * _Nullable) slot;

- (void)loadAdData;

@end


@interface AdMobiusDataFlowSlot : NSObject
/// 广告位ID
@property(nonatomic, copy) NSString *slotId;
// default 3s
@property(nonatomic, assign) NSInteger tolerateTimeout;

/// 广告位宽度  px像素单位
@property(nonatomic) NSInteger slotWidth;
@property(nonatomic) NSInteger slotHeight;

@end


@protocol AdMobiusDataFlowAdManagerDelegate <NSObject>

@optional
- (void)dataFlowAdManager:(AdMobiusDataFlowAdManager *)adsManager
           didSuccessLoad:(NSArray<AdMobiusNativeAd *> * _Nullable)ads;

- (void)dataFlowAdManager:(AdMobiusDataFlowAdManager *)adsManager
         didFailWithError:(NSError * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
