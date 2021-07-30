//
//  AdMobiusNativeAdData.h
//  AdMobiusSDK
//
//  Created by mirari on 2021/7/22.
//  Copyright © 2021 AdMobius. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AM_NATIVE_AD_TYPE) {
    AM_NATIVE_AD_SMALL_IMAGE = 1,         // 小图
    AM_NATIVE_AD_LARGE_IMAGE = 2,         // 大图
    AM_NATIVE_AD_THREE_SMALL = 3,         // 三张小图
    AM_NATIVE_AD_VIDEO = 4,               // 视频
};

@class AdMobiusNativeAdData;

@protocol AdMobiusNativeAdViewDelegate
/**
 注册广告视图
 @param clickViews 要点击事件的视图
 */
- (void)am_registViews:(NSArray<UIView *> *)clickViews;

/**
 取消注册
 必须调用，否则会有内存泄漏
 */
- (void)am_unRegistView;

/**
 广告关闭事件，手动调用
 */
- (void)am_close;

/**
 自渲染广告数据
 */
@property (nonatomic, strong) AdMobiusNativeAdData *data;

/**
  信息流广告的视频视图，只有类型为视频(AM_NATIVE_AD_VIDEO)时可用
 */
@property (nonatomic, strong) UIView *mediaView;
/**
  该广告所属的广告加载器
 */
@property (nonatomic, weak) id adLoader;

@end

/**
 自渲染广告数据
 */
@interface AdMobiusNativeAdData : NSObject

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
@property (nonatomic, assign) AM_NATIVE_AD_TYPE imageMode;

@end
NS_ASSUME_NONNULL_END
