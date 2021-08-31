Pod::Spec.new do |s|
  s.name         = 'AdKleinSDK'
  s.version      = '3.2.0'
  s.summary      = '莫比乌斯广告聚合SDK'
  s.description  = <<-DESC
聚合全球优质广告资源，一站式快速接入，轻松变现
                   DESC
  s.homepage     = 'https://www.iusmob.com'
  s.license      = 'MIT'
  s.author       = { 'iusmob' => 'mobius@iusmob.com' }
  s.source       = { :git => 'https://github.com/iusmob/AdKleinSDK.git', :tag => "v#{s.version.to_s}" }
  s.platform     = :ios
  s.ios.deployment_target = '9.0'
  s.cocoapods_version = '>= 1.10.1'
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
      spsub.dependency 'AdKleinSDK/AdMobiusSDK'
      spsub.dependency 'AdKleinSDK/core'
    end

    #gdt
    sp.subspec 'GDT' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/gdt/AdKleinGDTAdapter.xcframework'
      spsub.dependency 'GDTMobSDK', '~> 4.13.01'
      spsub.dependency 'AdKleinSDK/core'
    end

    #csj
    sp.subspec 'CSJ' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/csj/AdKleinCSJAdapter.xcframework'
      spsub.dependency 'Ads-CN', '~> 3.8.1.0'
      spsub.dependency 'AdKleinSDK/core'
    end

    #baidu
    sp.subspec 'BaiDu' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/bqt/AdKleinBQTAdapter.xcframework'
      spsub.dependency 'BaiduMobAdSDK', '~> 4.81'
      spsub.dependency 'AdKleinSDK/core'
    end

    #google
    sp.subspec 'Google' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/google/AdKleinGoogleAdapter.xcframework'
      spsub.dependency 'Google-Mobile-Ads-SDK', '~> 8.9.0'
      spsub.dependency 'AdKleinSDK/core'
    end

    #smaato
    sp.subspec 'Smaato' do |spsub|
      spsub.vendored_frameworks = 'Frameworks/platforms/smaato/AdKleinSmaatoAdapter.xcframework'
      spsub.dependency 'smaato-ios-sdk', '~> 21.6.16'
      spsub.dependency 'AdKleinSDK/core'
    end
  end
end
