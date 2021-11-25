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

/** The default number of retry attempts is 1. */
FOUNDATION_EXTERN NSInteger const AMPromiseRetryDefaultAttemptsCount NS_REFINED_FOR_SWIFT;

/** The default delay interval before making a retry attempt is 1.0 second. */
FOUNDATION_EXTERN NSTimeInterval const AMPromiseRetryDefaultDelayInterval NS_REFINED_FOR_SWIFT;

@interface AMPromise<Value>(RetryAdditions)

typedef id __nullable (^AMPromiseRetryWorkBlock)(void) NS_SWIFT_UNAVAILABLE("");
typedef BOOL (^AMPromiseRetryPredicateBlock)(NSInteger, NSError *) NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise that fulfills with the same value as the promise returned from `work`
 block, which executes asynchronously, or rejects with the same error after all retry attempts have
 been exhausted. Defaults to `AMPromiseRetryDefaultAttemptsCount` attempt(s) on rejection where the
 `work` block is retried after a delay of `AMPromiseRetryDefaultDelayInterval` second(s).

 @param work A block that executes asynchronously on the default queue and returns a value or an
             error used to resolve the promise.
 @return A new pending promise that fulfills with the same value as the promise returned from `work`
         block, or rejects with the same error after all retry attempts have been exhausted.
 */
+ (AMPromise *)retry:(AMPromiseRetryWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise that fulfills with the same value as the promise returned from `work`
 block, which executes asynchronously on the given `queue`, or rejects with the same error after all
 retry attempts have been exhausted. Defaults to `AMPromiseRetryDefaultAttemptsCount` attempt(s) on
 rejection where the `work` block is retried on the given `queue` after a delay of
 `AMPromiseRetryDefaultDelayInterval` second(s).

 @param queue A queue to invoke the `work` block on.
 @param work A block that executes asynchronously on the given `queue` and returns a value or an
             error used to resolve the promise.
 @return A new pending promise that fulfills with the same value as the promise returned from `work`
         block, or rejects with the same error after all retry attempts have been exhausted.
 */
+ (AMPromise *)onQueue:(dispatch_queue_t)queue
                  retry:(AMPromiseRetryWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise that fulfills with the same value as the promise returned from `work`
 block, which executes asynchronously, or rejects with the same error after all retry attempts have
 been exhausted.

 @param count Max number of retry attempts. The `work` block will be executed once if the specified
              count is less than or equal to zero.
 @param work A block that executes asynchronously on the default queue and returns a value or an
             error used to resolve the promise.
 @return A new pending promise that fulfills with the same value as the promise returned from `work`
         block, or rejects with the same error after all retry attempts have been exhausted.
 */
+ (AMPromise *)attempts:(NSInteger)count
                   retry:(AMPromiseRetryWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise that fulfills with the same value as the promise returned from `work`
 block, which executes asynchronously on the given `queue`, or rejects with the same error after all
 retry attempts have been exhausted.

 @param queue A queue to invoke the `work` block on.
 @param count Max number of retry attempts. The `work` block will be executed once if the specified
              count is less than or equal to zero.
 @param work A block that executes asynchronously on the given `queue` and returns a value or an
             error used to resolve the promise.
 @return A new pending promise that fulfills with the same value as the promise returned from `work`
         block, or rejects with the same error after all retry attempts have been exhausted.
 */
+ (AMPromise *)onQueue:(dispatch_queue_t)queue
               attempts:(NSInteger)count
                  retry:(AMPromiseRetryWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise that fulfills with the same value as the promise returned from `work`
 block, which executes asynchronously, or rejects with the same error after all retry attempts have
 been exhausted. On rejection, the `work` block is retried after the given delay `interval` and will
 continue to retry until the number of specified attempts have been exhausted or will bail early if
 the given condition is not met.

 @param count Max number of retry attempts. The `work` block will be executed once if the specified
              count is less than or equal to zero.
 @param interval Time to wait before the next retry attempt.
 @param predicate Condition to check before the next retry attempt. The predicate block provides the
                  the number of remaining retry attempts and the error that the promise was rejected
                  with.
 @param work A block that executes asynchronously on the default queue and returns a value or an
             error used to resolve the promise.
 @return A new pending promise that fulfills with the same value as the promise returned from `work`
         block, or rejects with the same error after all retry attempts have been exhausted or if
         the given condition is not met.
 */
+ (AMPromise *)attempts:(NSInteger)count
                   delay:(NSTimeInterval)interval
               condition:(nullable AMPromiseRetryPredicateBlock)predicate
                   retry:(AMPromiseRetryWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 Creates a pending promise that fulfills with the same value as the promise returned from `work`
 block, which executes asynchronously on the given `queue`, or rejects with the same error after all
 retry attempts have been exhausted. On rejection, the `work` block is retried after the given
 delay `interval` and will continue to retry until the number of specified attempts have been
 exhausted or will bail early if the given condition is not met.

 @param queue A queue to invoke the `work` block on.
 @param count Max number of retry attempts. The `work` block will be executed once if the specified
              count is less than or equal to zero.
 @param interval Time to wait before the next retry attempt.
 @param predicate Condition to check before the next retry attempt. The predicate block provides the
                  the number of remaining retry attempts and the error that the promise was rejected
                  with.
 @param work A block that executes asynchronously on the given `queue` and returns a value or an
             error used to resolve the promise.
 @return A new pending promise that fulfills with the same value as the promise returned from `work`
         block, or rejects with the same error after all retry attempts have been exhausted or if
         the given condition is not met.
 */
+ (AMPromise *)onQueue:(dispatch_queue_t)queue
               attempts:(NSInteger)count
                  delay:(NSTimeInterval)interval
              condition:(nullable AMPromiseRetryPredicateBlock)predicate
                  retry:(AMPromiseRetryWorkBlock)work NS_REFINED_FOR_SWIFT;

@end

/**
 Convenience dot-syntax wrappers for `AMPromise+Retry` operators.
 Usage: AMPromise.retry(^id { ... })
 */
@interface AMPromise<Value>(DotSyntax_RetryAdditions)

+ (AMPromise * (^)(AMPromiseRetryWorkBlock))retry AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
+ (AMPromise * (^)(dispatch_queue_t, AMPromiseRetryWorkBlock))retryOn AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
+ (AMPromise * (^)(NSInteger, NSTimeInterval, AMPromiseRetryPredicateBlock __nullable,
                    AMPromiseRetryWorkBlock))retryAgain AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
+ (AMPromise * (^)(dispatch_queue_t, NSInteger, NSTimeInterval,
                    AMPromiseRetryPredicateBlock __nullable,
                    AMPromiseRetryWorkBlock))retryAgainOn AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
