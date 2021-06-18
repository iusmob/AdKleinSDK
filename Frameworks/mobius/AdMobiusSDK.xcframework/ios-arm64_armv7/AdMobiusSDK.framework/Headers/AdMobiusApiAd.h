//
//  AdMobiusApiAd.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/8.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdMobiusRespVideoObject.h"

typedef NS_ENUM(NSInteger, AdMobiusAdStyle) {
    AdMobiusAdStyleText = 1,  // 文字
    AdMobiusAdStyleTextImage = 2, // 静态图片
    AdMobiusAdStyleRichText = 3,   // 图文
};

typedef NS_ENUM(NSInteger, AdMobiusAdInteractionType) {
    AdMobiusAdInteractionTypeWeb = 1, //open brow
    AdMobiusAdInteractionTypeWebInApp = 2, // open web in app
    AdMobiusAdInteractionTypeDownload = 3, // download app
    AdMobiusAdInteractionTypeDeeplink = 4, /// 可能是有deeplink
    AdMobiusAdInteractionTypeURL = 5, // 浏览器应用内均可
    AdMobiusAdInteractionTypeDetail = 6, /// 访问后下载(1nmob)=6
};

typedef NS_ENUM(NSInteger, AdMobiusAdType) {
    AdMobiusAdTypeSplash = 0,
    AdMobiusAdTypeBanner = 1,
    AdMobiusAdTypeInterstitial = 2, ///插屏
    AdMobiusAdTypeFullVideo = 3, ///全屏
    AdMobiusAdTypeRewardVideo = 4,  /// 激励视频
    AdMobiusAdTypeDataFlow = 5,
};

// 顶部=1;底部=2;信息流内=3; 中部=4;全屏=5"
typedef NS_ENUM(NSInteger, AdMobiusAdPosition) {
    AdMobiusAdPositionTop = 1,
    AdMobiusAdPositionBottom = 2,
    AdMobiusAdPositionInFlow = 3,
    AdMobiusAdPositionCenter = 4,
    AdMobiusAdPositionFullScreen = 5,
};



NS_ASSUME_NONNULL_BEGIN

@interface AdMobiusApiAd : NSObject

//@ApiModelProperty("广告 ID")
@property(nonatomic, copy) NSString * adId;

//@ApiModelProperty(value = "广告的类型 文字=1;静态图片=2;图文=3", example = "3")
@property(nonatomic, assign) AdMobiusAdStyle creativeType;

//@ApiModelProperty(value = "广告的交互类型 使用浏览器打开=1; 应用内打开=2; 下载应用=3; deeplink类型=4; 浏览器应用内均可=5; 访问后下载(1nmob)=6", example = "1")
@property(nonatomic, assign) AdMobiusAdInteractionType interactionType;

//@ApiModelProperty("标题")
@property(nonatomic, copy) NSString * title;

//@ApiModelProperty("广告描述")
@property(nonatomic, copy) NSString * desc;

//@ApiModelProperty("落地页来源")
@property(nonatomic, copy) NSString * source;

//@ApiModelProperty("广告图标地址")
//private List<String> icons;
@property(nonatomic, strong) NSArray<NSString *> *icons;

//@ApiModelProperty("广告图片地址，单个广告可能存在多个图片地址")
//private List<String> images;
@property(nonatomic, strong) NSArray<NSString *> *images;

//@ApiModelProperty("视频素材")
//private List<VideoInfo> videos;
@property(nonatomic, strong) NSArray<AdMobiusRespVideoObject*> *videos;

//@ApiModelProperty("app 端 deeplink 链接，")
@property(nonatomic, copy) NSString * deeplink;

//@ApiModelProperty("落地页地址")
@property(nonatomic, copy) NSString * clickAdUrl;

//@ApiModelProperty("针对应用下载类广告")
@property(nonatomic, copy) NSString * appName;

//@ApiModelProperty("应用下载包名")
@property(nonatomic, copy) NSString * packageName;

///GDT 目前APP下载类广告只出现在安卓设备上。
//@ApiModelProperty("下载链接")
@property(nonatomic, copy) NSString * downloadUrl;


@end

NS_ASSUME_NONNULL_END
