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

@interface AMPromise<Value>(ValidateAdditions)

typedef BOOL (^AMPromiseValidateWorkBlock)(Value __nullable value) NS_SWIFT_UNAVAILABLE("");

/**
 Validates a fulfilled value or rejects the value if it can not be validated.

 @param predicate An expression to validate.
 @return A new pending promise that gets either resolved with same resolution as the receiver or
         rejected with `AMPromiseErrorCodeValidationFailure` error code in `AMPromiseErrorDomain`.
 */
- (AMPromise *)validate:(AMPromiseValidateWorkBlock)predicate NS_SWIFT_UNAVAILABLE("");

/**
 Validates a fulfilled value or rejects the value if it can not be validated.

 @param queue A queue to dispatch on.
 @param predicate An expression to validate.
 @return A new pending promise that gets either resolved with same resolution as the receiver or
         rejected with `AMPromiseErrorCodeValidationFailure` error code in `AMPromiseErrorDomain`.
 */
- (AMPromise *)onQueue:(dispatch_queue_t)queue
               validate:(AMPromiseValidateWorkBlock)predicate NS_REFINED_FOR_SWIFT;

@end

/**
 Convenience dot-syntax wrappers for `AMPromise` `validate` operators.
 Usage: promise.validate(^BOOL(id value) { ... })
 */
@interface AMPromise<Value>(DotSyntax_ValidateAdditions)

- (AMPromise * (^)(AMPromiseValidateWorkBlock))validate AM_PROMISES_DOT_SYNTAX
    NS_SWIFT_UNAVAILABLE("");
- (AMPromise * (^)(dispatch_queue_t, AMPromiseValidateWorkBlock))validateOn
    AM_PROMISES_DOT_SYNTAX NS_SWIFT_UNAVAILABLE("");

@end

NS_ASSUME_NONNULL_END
