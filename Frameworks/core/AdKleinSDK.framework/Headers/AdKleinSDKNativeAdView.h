//
//  AdKleinSDKNativeAdView.h
//  AdKleinSDK
//
//  Created by mirari on 2021/4/17.
//  Copyright © 2021 MobiusAd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AdKleinSDKNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface AdKleinSDKNativeAdView : UIView <AdKleinSDKNativeAdViewDelegate>
/**
  该广告所属的广告加载器
 */
@property (nonatomic, weak) id adLoader;
/**
  信息流广告view的上游原始广告视图
 */
@property (nonatomic, strong) id sourceView;
/**
  信息流广告view的上游原始广告对象
 */
@property (nonatomic, strong) id sourceAd;

@end

NS_ASSUME_NONNULL_END
