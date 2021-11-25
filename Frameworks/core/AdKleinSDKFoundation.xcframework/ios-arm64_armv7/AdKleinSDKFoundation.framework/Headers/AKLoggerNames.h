// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2021, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *AKLoggerName NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXPORT AKLoggerName const AKLoggerNameOS NS_SWIFT_NAME(AKLoggerName.os);     // AKOSLogger
FOUNDATION_EXPORT AKLoggerName const AKLoggerNameFile NS_SWIFT_NAME(AKLoggerName.file); // AKFileLogger

FOUNDATION_EXPORT AKLoggerName const AKLoggerNameTTY NS_SWIFT_NAME(AKLoggerName.tty);   // AKTTYLogger

API_DEPRECATED("Use AKOSLogger instead", macosx(10.4, 10.12), ios(2.0, 10.0), watchos(2.0, 3.0), tvos(9.0, 10.0))
FOUNDATION_EXPORT AKLoggerName const AKLoggerNameASL NS_SWIFT_NAME(AKLoggerName.asl);   // AKASLLogger

NS_ASSUME_NONNULL_END
