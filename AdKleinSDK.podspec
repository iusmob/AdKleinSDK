Pod::Spec.new do |s|
  s.name         = 'AdKleinSDK'
  s.version      = '3.0.1'
  s.summary      = '莫比乌斯广告聚合SDK'
  s.description  = <<-DESC
聚合全球优质广告资源，一站式快速接入，轻松变现
                   DESC
  s.homepage     = 'https://www.iusmob.com'
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { 'iusmob' => 'mobius@iusmob.com' }
  s.source       = { :git => 'https://github.com/iusmob/AdKleinSDK.git', :tag => "v#{s.version.to_s}" }
  s.platform     = :ios

  s.ios.deployment_target = '9.0'

  s.frameworks = 'WebKit','Security','QuartzCore','CoreData','ImageIO', 'MediaPlayer', 'CoreLocation', 'AdSupport', 'CoreMedia', 'AVFoundation', 'CoreTelephony', 'StoreKit', 'SystemConfiguration', 'MobileCoreServices', 'CoreMotion', 'Accelerate', 'MessageUI', 'SafariServices', 'UIKit', 'MapKit', 'AudioToolbox','JavaScriptCore'

  s.libraries = 'xml2', 'c++', 'c++abi', 'z', 'sqlite3','bz2', 'xml2', 'iconv', 'resolv'

  s.default_subspecs = 'core'

  # base
  s.subspec 'AdKleinSDKFoundation' do |sp|
    sp.vendored_frameworks = 'Frameworks/core/AdKleinSDKFoundation.xcframework'
  end

  # perf
  s.subspec 'NxPerfSDK' do |sp|
    sp.vendored_frameworks = 'Frameworks/kit/NxPerfSDK.xcframework'
  end

  # api
  s.subspec 'AdMobiusSDK' do |sp|
    sp.vendored_frameworks = 'Frameworks/mobius/AdMobiusSDK.xcframework'
    sp.resources = 'Frameworks/mobius/AdMobiusSDKBundle.bundle'
  end

  # Core SDK
  s.subspec 'core' do |sp|
    sp.vendored_frameworks = 'Frameworks/core/AdKleinSDK.xcframework'
    sp.dependency 'AdKleinSDK/AdKleinSDKFoundation'
    sp.dependency 'AdKleinSDK/NxPerfSDK'
  end

  # platforms
  s.subspec 'AdKleinSDKPlatforms' do |sp|

    #mobius
    sp.subspec 'Mobius' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/mobius/AdKleinMobiusAdapter.xcframework'
      spsub.dependency 'AdKleinSDK/core'
      spsub.dependency 'AdKleinSDK/AdMobiusSDK'
    end

    #gdt
    sp.subspec 'GDT' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/gdt/AdKleinGDTAdapter.xcframework'
      spsub.dependency 'GDTMobSDK', '~> 4.12.61'
      spsub.dependency 'AdKleinSDK/core'
    end

    #csj
    sp.subspec 'CSJ' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/csj/AdKleinCSJAdapter.xcframework'
      spsub.dependency 'Ads-CN', '~> 3.6.1.5'
      spsub.dependency 'AdKleinSDK/core'
    end

    #baidu
    sp.subspec 'BaiDu' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/bqt/AdKleinBQTAdapter.xcframework'
      spsub.dependency 'BaiduMobAdSDK', '~> 4.771'
      spsub.dependency 'AdKleinSDK/core'
      spsub.frameworks = 'UIKit', 'MediaPlayer' , 'CoreMedia', 'AVFoundation', 'CoreMotion', 'SafariServices', 'EventKit', 'EventKitUI', 'CoreGraphics', 'MessageUI', 'StoreKit', 'Security', 'WebKit', 'CoreTelephony', 'SystemConfiguration', 'QuartzCore', 'CoreLocation', 'AdSupport'
      spsub.libraries = 'c++', 'xml2', 'z'
    end

    #google
    sp.subspec 'Google' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/google/AdKleinGoogleAdapter.xcframework'
      spsub.dependency 'Google-Mobile-Ads-SDK', '~> 8.4.0'
      spsub.dependency 'AdKleinSDK/core'
      spsub.xcconfig = {
        'OTHER_LDFLAGS' => '-ObjC'
      }
    end

    #smaato
    sp.subspec 'Smaato' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/smaato/AdKleinSmaatoAdapter.xcframework'
      spsub.dependency 'smaato-ios-sdk', '~> 21.6.11'
      spsub.dependency 'AdKleinSDK/core'
      spsub.xcconfig = {
        'OTHER_LDFLAGS' => '-ObjC'
      }
    end
  end
end
