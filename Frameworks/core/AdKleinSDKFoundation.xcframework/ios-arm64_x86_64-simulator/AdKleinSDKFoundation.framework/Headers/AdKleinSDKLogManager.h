//
//  AdKleinSDKLogManager.h
//  AdKleinSDKFoundation
//
//  Created by mirari on 2021/4/2.
//  Copyright © 2021 MobiusAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdKleinSDKLumberjack.h"

extern AKLogLevel akLogLevel;

@interface AdKleinSDKLogManager : NSObject
@property(nonatomic, strong)AKFileLogger *fileLogger;
+ (AdKleinSDKLogManager *)shareManager;
+ (void)debug;
- (void)start;                              // 配置日志信息
- (NSArray *)getAllLogFilePath;             // 获取日志路径
- (NSArray *)getAllLogFileContent;          // 获取日志内容
@end
