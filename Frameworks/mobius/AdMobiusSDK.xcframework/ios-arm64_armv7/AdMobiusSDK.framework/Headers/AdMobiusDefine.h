//
//  AdMobiusDefine.h
//  AdMobiusSDK
//
//  Created by Grand on 2020/9/9.
//  Copyright © 2020 AdMobius. All rights reserved.
//

#ifndef AdMobiusDefine_h
#define AdMobiusDefine_h

#import <UIKit/UIKit.h>

#define kAdMobiusSWindowSize   (UIScreen.mainScreen.bounds.size)
#define kAdMobiusSWindowWidth  MIN(kAdMobiusSWindowSize.width, kAdMobiusSWindowSize.height)
#define kAdMobiusSWindowHeight MAX(kAdMobiusSWindowSize .width, kAdMobiusSWindowSize.height)
#define kAdMobiusSWindowScale  (UIScreen.mainScreen.scale)


/**
 Synthsize a weak or strong reference.

 Example:
    @weakify(self)
    [self doSomething^{
        @strongify(self)
        if (!self) return;
        ...
    }];
 */
#ifndef weakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef strongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

#endif /* AdMobiusDefine_h */
