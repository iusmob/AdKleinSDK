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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSErrorDomain const AMPromiseErrorDomain NS_REFINED_FOR_SWIFT;

/**
 Possible error codes in `AMPromiseErrorDomain`.
 */
typedef NS_ENUM(NSInteger, AMPromiseErrorCode) {
  /** Promise failed to resolve in time. */
  AMPromiseErrorCodeTimedOut = 1,
  /** Validation predicate returned false. */
  AMPromiseErrorCodeValidationFailure = 2,
} NS_REFINED_FOR_SWIFT;

NS_INLINE BOOL AMPromiseErrorIsTimedOut(NSError *error) NS_SWIFT_UNAVAILABLE("") {
  return error.domain == AMPromiseErrorDomain &&
         error.code == AMPromiseErrorCodeTimedOut;
}

NS_INLINE BOOL AMPromiseErrorIsValidationFailure(NSError *error) NS_SWIFT_UNAVAILABLE("") {
  return error.domain == AMPromiseErrorDomain &&
         error.code == AMPromiseErrorCodeValidationFailure;
}

NS_ASSUME_NONNULL_END
