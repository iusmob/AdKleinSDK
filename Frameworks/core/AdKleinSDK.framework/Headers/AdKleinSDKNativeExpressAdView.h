//
//  AdKleinSDKNativeExpressAdView.h
//  AdKleinSDK
//
//  Created by mac on 2020/9/25.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AdKleinSDKNativeExpressAdViewDelegate

/**
  渲染广告，穿山甲广告在渲染后才能得到真实高度
 */
- (void)render;

@end

@interface AdKleinSDKNativeExpressAdView : UIView <AdKleinSDKNativeExpressAdViewDelegate>
/**
  该广告所属的广告加载器
 */
@property (nonatomic, weak) id adLoader;
/**
  信息流广告view的上游原始广告视图
 */
@property (nonatomic, strong) id sourceView;

@end

