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

@interface AMPromise<Value>(AlwaysAdditions)

typedef void (^AMPromiseAlwaysWorkBlock)(void) NS_SWIFT_UNAVAILABLE("");

/**
 @param work A block that always executes, no matter if the receiver is rejected or fulfilled.
 @return A new pending promise to be resolved with same resolution as the receiver.
 */
- (AMPromise *)always:(AMPromiseAlwaysWorkBlock)work NS_SWIFT_UNAVAILABLE("");

/**
 @param queue A queue to dispatch on.
 @param work A block that always executes, no matter if the receiver is rejected or fulfilled.
 @return A new pending promise to be resolved with same resolution as the receiver.
 */
- (AMPromise *)onQueue:(dispatch_queue_t)queue
                 always:(AMPromiseAlwaysWorkBlock)work NS_REFINED_FOR_SWIFT;

@end

/**
 Convenience dot-syntax wrappers for `AMPromise` `always` operators.
 Usage: promise.always(^{...})
 */
@interface AMPromise<Value>(DotSyntax_AlwaysAdditions)

- (AMPromise* (^)(AMPromiseAlwaysWorkBlock))always AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
- (AMPromise* (^)(dispatch_queue_t, AMPromiseAlwaysWorkBlock))alwaysOn AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
