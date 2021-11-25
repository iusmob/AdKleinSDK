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

@interface AMPromise<Value>(ReduceAdditions)

typedef id __nullable (^AMPromiseReducerBlock)(Value __nullable partial, id next)
    NS_SWIFT_UNAVAILABLE("");

/**
 Sequentially reduces a collection of values to a single promise using a given combining block
 and the value `self` resolves with as initial value.

 @param items An array of values to process in order.
 @param reducer A block to combine an accumulating value and an element of the sequence into
                the new accumulating value or a promise resolved with it, to be used in the next
                call of the `reducer` or returned to the caller.
 @return A new pending promise returned from the last `reducer` invocation.
         Or `self` if `items` is empty.
 */
- (AMPromise *)reduce:(NSArray *)items
               combine:(AMPromiseReducerBlock)reducer NS_SWIFT_UNAVAILABLE("");

/**
 Sequentially reduces a collection of values to a single promise using a given combining block
 and the value `self` resolves with as initial value.

 @param queue A queue to dispatch on.
 @param items An array of values to process in order.
 @param reducer A block to combine an accumulating value and an element of the sequence into
                the new accumulating value or a promise resolved with it, to be used in the next
                call of the `reducer` or returned to the caller.
 @return A new pending promise returned from the last `reducer` invocation.
         Or `self` if `items` is empty.
 */
- (AMPromise *)onQueue:(dispatch_queue_t)queue
                 reduce:(NSArray *)items
                combine:(AMPromiseReducerBlock)reducer NS_SWIFT_UNAVAILABLE("");

@end

/**
 Convenience dot-syntax wrappers for `AMPromise` `reduce` operators.
 Usage: promise.reduce(values, ^id(id partial, id next) { ... })
 */
@interface AMPromise<Value>(DotSyntax_ReduceAdditions)

- (AMPromise * (^)(NSArray *, AMPromiseReducerBlock))reduce AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
- (AMPromise * (^)(dispatch_queue_t, NSArray *, AMPromiseReducerBlock))reduceOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
