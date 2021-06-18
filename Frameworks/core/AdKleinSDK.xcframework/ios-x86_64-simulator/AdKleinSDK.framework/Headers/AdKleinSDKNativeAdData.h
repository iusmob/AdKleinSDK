//
//  AdKleinSDKNativeAdData.h
//  AdKleinSDK
//
//  Created by mirari on 2021/5/10.
//  Copyright © 2021 MobiusAd. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AK_NATIVE_AD_TYPE) {
    AK_NATIVE_AD_SMALL_IMAGE = 1,         // 小图
    AK_NATIVE_AD_LARGE_IMAGE = 2,         // 大图
    AK_NATIVE_AD_THREE_SMALL = 3,         // 三张小图
    AK_NATIVE_AD_VIDEO = 4,               // 视频
};

@class AdKleinSDKNativeAdData;

@protocol AdKleinSDKNativeAdViewDelegate
/**
 注册广告视图
 @param clickViews 要点击事件的视图
 */
- (void)ak_registViews:(NSArray<UIView *> *)clickViews;

/**
 取消注册
 必须调用，否则会有内存泄漏
 */
- (void)ak_unRegistView;

/**
 广告关闭事件，手动调用
 */
- (void)ak_close;

/**
 自渲染广告数据
 */
@property (nonatomic, strong) AdKleinSDKNativeAdData *data;

/**
  信息流广告的视频视图，只有类型为视频(AK_NATIVE_AD_VIDEO)时可用
 */
@property (nonatomic, strong) UIView *mediaView;

@end

/**
 自渲染广告数据
 */
@interface AdKleinSDKNativeAdData : NSObject

/**
 标题
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 描述
 */
@property (nonatomic, copy, nullable) NSString *desc;

/**
 图片列表
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *images;

/**
 渲染类型
 */
@property (nonatomic, assign) AK_NATIVE_AD_TYPE imageMode;

/**
  信息流广告数据的上游原始数据
 */
@property (nonatomic, strong) id sourceData;

@end

NS_ASSUME_NONNULL_END
