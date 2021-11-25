#import <Foundation/Foundation.h>

//! Project version number for AdKleinSDKLumberjack.
FOUNDATION_EXPORT double AdKleinSDKLumberjackVersionNumber;

//! Project version string for AdKleinSDKLumberjack.
FOUNDATION_EXPORT const unsigned char AdKleinSDKLumberjackVersionString[];

// Disable legacy macros
#ifndef AK_LEGACY_MACROS
    #define AK_LEGACY_MACROS 0
#endif

// Core
#import "AKLog.h"

// Main macros
#import "AKLogMacros.h"
#import "AKAssertMacros.h"

// Capture ASL
#import "AKASLLogCapture.h"

// Loggers
#import "AKLoggerNames.h"

#import "AKTTYLogger.h"
#import "AKASLLogger.h"
#import "AKFileLogger.h"
#import "AKOSLogger.h"

// Extensions
//#import "AKContextFilterLogFormatter.h"
//#import "AKDispatchQueueLogFormatter.h"
//#import "AKMultiFormatter.h"
//#import "AKFileLogger+Buffering.h"

// CLI
//#import "CLIColor.h"

// etc
//#import "AKAbstractDatabaseLogger.h"
//#import "AKLog+LOGV.h"
//#import "AKLegacyMacros.h"
