/**
 Copyright 2018 Google Inc. All rights reserved.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at:

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "AMPromise.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Different types of completion handlers available to be wrapped with promise.
 */
typedef void (^AMPromiseCompletion)(void) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseObjectCompletion)(id __nullable) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseErrorCompletion)(NSError* __nullable) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseObjectOrErrorCompletion)(id __nullable, NSError* __nullable)
    NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseErrorOrObjectCompletion)(NSError* __nullable, id __nullable)
    NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromise2ObjectsOrErrorCompletion)(id __nullable, id __nullable,
                                                    NSError* __nullable) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseBoolCompletion)(BOOL) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseBoolOrErrorCompletion)(BOOL, NSError* __nullable) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseIntegerCompletion)(NSInteger) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseIntegerOrErrorCompletion)(NSInteger, NSError* __nullable)
    NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseDoubleCompletion)(double) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseDoubleOrErrorCompletion)(double, NSError* __nullable)
    NS_SWIFT_UNAVAILABLE("");

/**
 Provides an easy way to convert methods that use common callback patterns into promises.
 */
@interface AMPromise<Value>(WrapAdditions)

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with `nil` when completion handler is invoked.
 */
+ (instancetype)wrapCompletion:(void (^)(AMPromiseCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with `nil` when completion handler is invoked.
 */
+ (instancetype)onQueue:(dispatch_queue_t)queue
         wrapCompletion:(void (^)(AMPromiseCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an object provided by completion handler.
 */
+ (instancetype)wrapObjectCompletion:(void (^)(AMPromiseObjectCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an object provided by completion handler.
 */
+ (instancetype)onQueue:(dispatch_queue_t)queue
    wrapObjectCompletion:(void (^)(AMPromiseObjectCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an error provided by completion handler.
 If error is `nil`, fulfills with `nil`, otherwise rejects with the error.
 */
+ (instancetype)wrapErrorCompletion:(void (^)(AMPromiseErrorCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an error provided by completion handler.
 If error is `nil`, fulfills with `nil`, otherwise rejects with the error.
 */
+ (instancetype)onQueue:(dispatch_queue_t)queue
    wrapErrorCompletion:(void (^)(AMPromiseErrorCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an object provided by completion handler if error is `nil`.
 Otherwise, rejects with the error.
 */
+ (instancetype)wrapObjectOrErrorCompletion:
    (void (^)(AMPromiseObjectOrErrorCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an object provided by completion handler if error is `nil`.
 Otherwise, rejects with the error.
 */
+ (instancetype)onQueue:(dispatch_queue_t)queue
    wrapObjectOrErrorCompletion:(void (^)(AMPromiseObjectOrErrorCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an error or object provided by completion handler. If error
 is not `nil`, rejects with the error.
 */
+ (instancetype)wrapErrorOrObjectCompletion:
    (void (^)(AMPromiseErrorOrObjectCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an error or object provided by completion handler. If error
 is not `nil`, rejects with the error.
 */
+ (instancetype)onQueue:(dispatch_queue_t)queue
    wrapErrorOrObjectCompletion:(void (^)(AMPromiseErrorOrObjectCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an array of objects provided by completion handler in order
 if error is `nil`. Otherwise, rejects with the error.
 */
+ (AMPromise<NSArray*>*)wrap2ObjectsOrErrorCompletion:
    (void (^)(AMPromise2ObjectsOrErrorCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an array of objects provided by completion handler in order
 if error is `nil`. Otherwise, rejects with the error.
 */
+ (AMPromise<NSArray*>*)onQueue:(dispatch_queue_t)queue
    wrap2ObjectsOrErrorCompletion:(void (^)(AMPromise2ObjectsOrErrorCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping YES/NO.
 */
+ (AMPromise<NSNumber*>*)wrapBoolCompletion:(void (^)(AMPromiseBoolCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping YES/NO.
 */
+ (AMPromise<NSNumber*>*)onQueue:(dispatch_queue_t)queue
               wrapBoolCompletion:(void (^)(AMPromiseBoolCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping YES/NO when error is `nil`.
 Otherwise rejects with the error.
 */
+ (AMPromise<NSNumber*>*)wrapBoolOrErrorCompletion:
    (void (^)(AMPromiseBoolOrErrorCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping YES/NO when error is `nil`.
 Otherwise rejects with the error.
 */
+ (AMPromise<NSNumber*>*)onQueue:(dispatch_queue_t)queue
        wrapBoolOrErrorCompletion:(void (^)(AMPromiseBoolOrErrorCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping an integer.
 */
+ (AMPromise<NSNumber*>*)wrapIntegerCompletion:(void (^)(AMPromiseIntegerCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping an integer.
 */
+ (AMPromise<NSNumber*>*)onQueue:(dispatch_queue_t)queue
            wrapIntegerCompletion:(void (^)(AMPromiseIntegerCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping an integer when error is `nil`.
 Otherwise rejects with the error.
 */
+ (AMPromise<NSNumber*>*)wrapIntegerOrErrorCompletion:
    (void (^)(AMPromiseIntegerOrErrorCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping an integer when error is `nil`.
 Otherwise rejects with the error.
 */
+ (AMPromise<NSNumber*>*)onQueue:(dispatch_queue_t)queue
     wrapIntegerOrErrorCompletion:(void (^)(AMPromiseIntegerOrErrorCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping a double.
 */
+ (AMPromise<NSNumber*>*)wrapDoubleCompletion:(void (^)(AMPromiseDoubleCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping a double.
 */
+ (AMPromise<NSNumber*>*)onQueue:(dispatch_queue_t)queue
             wrapDoubleCompletion:(void (^)(AMPromiseDoubleCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping a double when error is `nil`.
 Otherwise rejects with the error.
 */
+ (AMPromise<NSNumber*>*)wrapDoubleOrErrorCompletion:
    (void (^)(AMPromiseDoubleOrErrorCompletion handler))work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @returns A promise that resolves with an `NSNumber` wrapping a double when error is `nil`.
 Otherwise rejects with the error.
 */
+ (AMPromise<NSNumber*>*)onQueue:(dispatch_queue_t)queue
      wrapDoubleOrErrorCompletion:(void (^)(AMPromiseDoubleOrErrorCompletion handler))work
    NS_SWIFT_UNAVAILABLE("");

@end

/**
 Convenience dot-syntax wrappers for `AMPromise` `wrap` operators.
 Usage: AMPromise.wrapCompletion(^(AMPromiseCompletion handler) {...})
 */
@interface AMPromise<Value>(DotSyntax_WrapAdditions)

+ (AMPromise* (^)(void (^)(AMPromiseCompletion)))wrapCompletion AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(dispatch_queue_t, void (^)(AMPromiseCompletion)))wrapCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(void (^)(AMPromiseObjectCompletion)))wrapObjectCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(dispatch_queue_t, void (^)(AMPromiseObjectCompletion)))wrapObjectCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(void (^)(AMPromiseErrorCompletion)))wrapErrorCompletion AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(dispatch_queue_t, void (^)(AMPromiseErrorCompletion)))wrapErrorCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(void (^)(AMPromiseObjectOrErrorCompletion)))wrapObjectOrErrorCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(dispatch_queue_t,
                   void (^)(AMPromiseObjectOrErrorCompletion)))wrapObjectOrErrorCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(void (^)(AMPromiseErrorOrObjectCompletion)))wrapErrorOrObjectCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(dispatch_queue_t,
                   void (^)(AMPromiseErrorOrObjectCompletion)))wrapErrorOrObjectCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSArray*>* (^)(void (^)(AMPromise2ObjectsOrErrorCompletion)))
    wrap2ObjectsOrErrorCompletion AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSArray*>* (^)(dispatch_queue_t, void (^)(AMPromise2ObjectsOrErrorCompletion)))
    wrap2ObjectsOrErrorCompletionOn AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(void (^)(AMPromiseBoolCompletion)))wrapBoolCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(dispatch_queue_t,
                              void (^)(AMPromiseBoolCompletion)))wrapBoolCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(void (^)(AMPromiseBoolOrErrorCompletion)))wrapBoolOrErrorCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(dispatch_queue_t,
                              void (^)(AMPromiseBoolOrErrorCompletion)))wrapBoolOrErrorCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(void (^)(AMPromiseIntegerCompletion)))wrapIntegerCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(dispatch_queue_t,
                              void (^)(AMPromiseIntegerCompletion)))wrapIntegerCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(void (^)(AMPromiseIntegerOrErrorCompletion)))
    wrapIntegerOrErrorCompletion AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(dispatch_queue_t, void (^)(AMPromiseIntegerOrErrorCompletion)))
    wrapIntegerOrErrorCompletionOn AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(void (^)(AMPromiseDoubleCompletion)))wrapDoubleCompletion
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(dispatch_queue_t,
                              void (^)(AMPromiseDoubleCompletion)))wrapDoubleCompletionOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(void (^)(AMPromiseDoubleOrErrorCompletion)))
    wrapDoubleOrErrorCompletion AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise<NSNumber*>* (^)(dispatch_queue_t, void (^)(AMPromiseDoubleOrErrorCompletion)))
    wrapDoubleOrErrorCompletionOn AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
