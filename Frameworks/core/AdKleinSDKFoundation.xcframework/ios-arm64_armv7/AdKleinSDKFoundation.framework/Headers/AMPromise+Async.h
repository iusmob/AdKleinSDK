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

@interface AMPromise<Value>(AsyncAdditions)

typedef void (^AMPromiseFulfillBlock)(Value __nullable value) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseRejectBlock)(NSError *error) NS_SWIFT_UNAVAILABLE("");
typedef void (^AMPromiseAsyncWorkBlock)(AMPromiseFulfillBlock fulfill,
                                         AMPromiseRejectBlock reject) NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise and executes `work` block asynchronously.

 @param work A block to perform any operations needed to resolve the promise.
 @return A new pending promise.
 */
+ (instancetype)async:(AMPromiseAsyncWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise and executes `work` block asynchronously on the given queue.

 @param queue A queue to invoke the `work` block on.
 @param work A block to perform any operations needed to resolve the promise.
 @return A new pending promise.
 */
+ (instancetype)onQueue:(dispatch_queue_t)queue
                  async:(AMPromiseAsyncWorkBlock)work NS_REFINED_FOR_SWIFT;

@end

/**
 Convenience dot-syntax wrappers for `AMPromise` `async` operators.
 Usage: AMPromise.async(^(AMPromiseFulfillBlock fulfill, AMPromiseRejectBlock reject) { ... })
 */
@interface AMPromise<Value>(DotSyntax_AsyncAdditions)

+ (AMPromise* (^)(AMPromiseAsyncWorkBlock))async AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");
+ (AMPromise* (^)(dispatch_queue_t, AMPromiseAsyncWorkBlock))asyncOn AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
