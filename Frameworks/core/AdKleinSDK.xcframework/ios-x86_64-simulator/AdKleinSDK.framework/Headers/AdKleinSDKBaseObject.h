//
//  AdKleinSDKBaseObject.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/12.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AdKleinSDKBaseObject : UIView
/// PerfSDK需要的loadId
@property(nonatomic, strong) NSString * nxPerfLoadId;
/// 不建议对同一个object，多次load
- (void)load;
- (void)show;

@end

