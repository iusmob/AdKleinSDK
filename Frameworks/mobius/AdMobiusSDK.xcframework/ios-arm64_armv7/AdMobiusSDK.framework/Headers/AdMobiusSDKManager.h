//
//  AdMobiusSDKManager.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/9.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdMobiusSDKManager : NSObject

+ (void)debugMode;
+ (void)setAppID:(NSString *)appID;
+ (NSString *)appID;

//MARK:- Get
+ (NSString *)sdkVersion;
+ (NSInteger)sdkBuildVersion;
+ (NSString *)sdkName;

@end

NS_ASSUME_NONNULL_END
