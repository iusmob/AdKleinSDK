//
//  AdKleinSDKBaseObject.h
//  AdKleinSDK
//
//  Created by mac on 2020/8/12.
//  Copyright © 2020 MobiusAd. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AdKleinSDKBaseObject : UIView

/**
 [可选]请求超时时间，默认为4秒，请设置不低于3秒的值，以免影响收益
 */
@property (nonatomic, assign) NSInteger tolerateTimeout;

- (void)load;
- (void)show;

@end

