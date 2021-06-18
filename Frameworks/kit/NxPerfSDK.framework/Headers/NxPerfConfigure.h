//
//  NxPerfConfigure.h
//  NxPerfSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**拉取广告回调
 code  0 拉取失败  loadID为nil
 code  1 拉取成功  loadID为为loadID
 */
typedef void (^NxCallbackLoadIDBlock)(NSString *loadID);


typedef NS_ENUM(NSInteger, GPSType) {
    GPSTypeNone = 0, //未知
    GPSTypeBD  = 1, //百度坐标系
    GPSTypeWGS = 2, //GPS坐标 谷歌地图
    GPSTypeGCJ = 3, //国测局坐标，谷歌中国地图、腾讯地图、高德地图使用
};

typedef NS_ENUM(NSInteger, NetworkType) {
    NetworkTypeNone     = 0, //网络未知
    NetworkTypeWIFI     = 1, //wifi
    NetworkType2G       = 2, //2g
    NetworkType3G       = 3, //3G
    NetworkType4G       = 4, //4G  移动网络默认情况
    NetworkType5G       = 5, //5g
};


@interface NxPerfConfigure : NSObject


/** 初始化SDK方法1
 @param appID 开发者申请的appID.
 */
+ (void)initWithAppID:(NSString *)appID ;


/** 初始化SDK方法2
 此方法适用于需要传入UDID的方案，如果没有特别要求，使用方法1即可，不可与 初始化SDK方法1 同时调用
 @param appID 开发者申请的appID.
 @param UDIDStr UDID
 */
+ (void)initWithAppID:(NSString *)appID UDID:(NSString *)UDIDStr;


/** 设定网络状态
 @param type 网络状态 见上方枚举
 若无法判断移动网络具体情况 可统一设定为NetworkType4G
 */
+ (void)setNetWorkType:(NetworkType)type;



/** 请求加载广告
 @param slotld     NxPerf分配的广告位id
 @param adwidth    当前广告位宽度
 @param adheight   当前广告位高度
 
 callBackBlock     拉取广告回调loadID

 @param gpsType  gps坐标系 见上方枚举 未知传GPSTypeNone
 @param lng      经度 未知传0
 @param lat      纬度 未知传0
 
 callBackBlock 返回loadID
 loadID为本次广告对应的唯一ID（NSString）
  */
+ (void)ADLoadWithSlotId:(NSString *)slotld
                 adwidth:(double)adwidth
                adheight:(double)adheight
            LocationType:(GPSType)gpsType
               longitude:(double)lng
                latitude:(double)lat
                callback:(NxCallbackLoadIDBlock)callBackBlock;




/** 广告位展示后回调
 @param loadID NxCallbackLoadIDBlock 返回的loadID
 */
+ (void)ADShowWithLoadID:(NSString *)loadID;





/** 广告位点击后回调
 @param loadID NxCallbackLoadIDBlock 返回的loadID
 @param offsetX 范围0-1
    如果无法获得用户点击的坐标，则传入0。
    若能获取到用户点击的坐标，则值的计算方式如下。
    广告view的宽=w、高=h
    以左下角坐标0,0，右上角是w, h
    点击坐标相对于左下角是x, y
    offsetX =  x / w

 @param offsetY  范围0-1
    如果无法获得用户点击的坐标，则传入0。
    若能获取到用户点击的坐标，则值的计算方式如下。
    广告view的宽=w、高=h
    以左下角为0,0，右上角是w, h
    点击坐标相对于左下角是x, y
    offsetY = y / h
 */
+ (void)ADClickWithLoadID:(NSString *)loadID
                  offsetX:(double)offsetX
                  offsetY:(double)offsetY;


@end

NS_ASSUME_NONNULL_END
