//
//  AdMobiusRespVideoObject.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/8.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdMobiusRespVideoObject : NSObject

//@ApiModelProperty("视频地址")
@property(nonatomic, copy) NSString * videoUrl;

//@ApiModelProperty("视频时长")
@property(nonatomic, copy) NSString * videoDuration;

//@ApiModelProperty("视频大小")
@property(nonatomic, assign) int64_t size;

//@ApiModelProperty("视频宽度")
@property(nonatomic, assign) NSInteger width;

//@ApiModelProperty("视频高度")
@property(nonatomic, assign) NSInteger height;

//@ApiModelProperty("视频封面")
//private List<String> coverUrls;
@property(nonatomic, strong) NSArray<NSString *> *coverUrls;

//@ApiModelProperty("视频完成后的Button")
@property(nonatomic, copy) NSString * buttonText;

//@ApiModelProperty("视频完成后的URL")
@property(nonatomic, copy) NSArray<NSString *> *endImgUrls;

//@ApiModelProperty("视频完成后的结束页面")
@property(nonatomic, copy) NSString * endHtml;

//@ApiModelProperty("视频完成后是否跳转默认clickURL")
@property(nonatomic, assign) BOOL autoLanding;

//@ApiModelProperty("是否预加载")
@property(nonatomic, assign) BOOL prefetch;

//@ApiModelProperty("视频播放中是否可以点击clickURL")
@property(nonatomic, assign) BOOL clickAble;

//@ApiModelProperty("播放多少秒可以Skip, > 0 才处理")
@property(nonatomic, assign) NSInteger skipSeconds;

@end

NS_ASSUME_NONNULL_END
