//
//  AdMobiusRewardVideoAdManager.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/26.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AdMobiusRewardVideoSlot;
@protocol AdMobiusRewardVideoAdManagerDelegate;


@interface AdMobiusRewardVideoAdManager : NSObject

@property(nonatomic, weak) id<AdMobiusRewardVideoAdManagerDelegate> delegate;

/// require
@property(nonatomic, weak, readonly) UIViewController *rootViewController;

- (instancetype)initWithSlot:(AdMobiusRewardVideoSlot * _Nullable) slot;
- (void)loadAdData;

/// show
@property(nonatomic, assign) BOOL autoPlay; /// default YES
- (BOOL)showAdFromRootViewController:(UIViewController *)rootvc;

/// check

@end


@interface AdMobiusRewardVideoSlot : NSObject
/// 广告位ID
@property(nonatomic, copy) NSString *slotId;
// default 3s
@property(nonatomic, assign) NSInteger tolerateTimeout;

@end


@protocol AdMobiusRewardVideoAdManagerDelegate <NSObject>

@optional

/// 广告数据加载
- (void)rewardVideoAdManagerDidSuccessLoad:(AdMobiusRewardVideoAdManager *)adManager;

/// 广告数据 或者 视频加载 失败
- (void)rewardVideoAdManager:(AdMobiusRewardVideoAdManager *)adManager
            didFailWithError:(NSError * _Nullable)error;

/// 视频下载成功｜或者缓存过立即回掉 ｜ 视频源不允许预先下载
/// 建议在此回调，跳用showAdFromRootViewController
- (void)rewardVideoAdManagerVideoDidLoad:(AdMobiusRewardVideoAdManager *)adManager;


- (void)rewardVideoAdManagerDidShow:(AdMobiusRewardVideoAdManager *)adManager;

- (void)rewardVideoAdManagerDidClick:(AdMobiusRewardVideoAdManager *)adManager;

- (void)rewardVideoAdManagerDidClose:(AdMobiusRewardVideoAdManager *)adManager;

/// 可以发奖励了 ????? TODO
- (void)rewardVideoAdManagerDidRewardEffective:(AdMobiusRewardVideoAdManager *)adManager;

/// 播放结束了
- (void)rewardVideoAdManagerDidPlayFinish:(AdMobiusRewardVideoAdManager *)adManager;

/// skip
- (void)rewardVideoAdManagerDidClickSkip:(AdMobiusRewardVideoAdManager *)adManager;


@end

NS_ASSUME_NONNULL_END
