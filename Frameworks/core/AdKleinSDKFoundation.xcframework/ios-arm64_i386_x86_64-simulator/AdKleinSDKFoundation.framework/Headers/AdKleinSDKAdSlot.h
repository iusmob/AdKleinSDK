//
//  AdKleinSDKAdSlot.h
//  AdKleinSDKFoundation
//
//  Created by Grand on 2020/10/15.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdKleinSDKAdSlot : NSObject

//optional
@property(nonatomic, strong) id originSlot;
@property(nonatomic, strong) id adapter;

@property(nonatomic, copy) NSString *slotId;
@property(nonatomic, assign) NSInteger tolerateTimeout;

/// Point
@property(nonatomic, assign) NSInteger width;
@property(nonatomic, assign) NSInteger height;

/// px
@property(nonatomic, assign) NSInteger px_width;
@property(nonatomic, assign) NSInteger px_height;

/// Reward Video
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *rewardName;
@property (nonatomic, assign) NSInteger rewardAmount;
@property (nonatomic, copy) NSString *extra;

/// Banner
@property (nonatomic, assign) CGRect bannerFrame;
@property(nonatomic, weak) UIViewController *viewController;
@property(nonatomic, weak) UIView *adContainer;
@property(nonatomic, assign) BOOL isSupportDeepLink;
@property(nonatomic, assign) NSInteger autoSwitchInterval;

/// Native feed
@property (nonatomic, assign) NSInteger AdType;
@property (nonatomic, assign) NSInteger position;
@property (nonatomic, assign) NSInteger imgSize;





@end

NS_ASSUME_NONNULL_END
