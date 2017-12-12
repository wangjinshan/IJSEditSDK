
Pod::Spec.new do |s|

 
  s.name         = "IJSEditSDK"
  s.version      = "0.1.0"

  s.summary      = "图片视频编辑框架"

  s.license          = 'MIT'

  s.author           = { "wangjinshan" => "1096452045@qq.com" }
  s.homepage         = 'https://github.com/wangjinshan/IJSEditSDK'
  s.platform         = :ios
  s.ios.deployment_target = "8.0"
  s.requires_arc = true
  s.description  = 'You can edit pictures and videos'
                
  s.source       = { :git => "https://github.com/wangjinshan/IJSEditSDK.git", :tag => "#{s.version}" ,:submodules => true}


  s.frameworks       = 'UIKit','Photos','AVFoundation'
  
  # 依赖的公共库, Core 的所有文件都将依赖这两个库
  s.dependency 'IJSFoundation'
  s.dependency 'IJSUExtension'

  # 依赖的资源 
  s.resource = "SDK/Resources/JSPhotoSDK.bundle"
  

  # UI 基础组件
  
  s.subspec 'IJSVideoDrawTool' do |sp|
    sp.source_files = 'SDK/IJSUIBase/IJSVideoDrawTool/*.{h,m}'
  
    end
    
  s.subspec 'IJSMapView' do |sp|
      sp.source_files = 'SDK/IJSUIBase/IJSMapView/*.{h,m}' 

    end

  s.subspec 'TOCropViewController' do |sp|
      sp.source_files = 'SDK/IJSUIBase/TOCropViewController/*.{h,m}' 
    
    end

    
  # IJSPhoto 核心代码库    

  # s.subspec 'Core' do |sp|

  #     sp.source_files = 'SDK/Core/ConstantFile/*.{h,m}','SDK/Core/Controllers/*.{h,m}','SDK/Core/Model/*.{h,m}','SDK/Core/View/*.{h,m}' 

  #     sp.dependency 'IJSEditSDK/IJSVideoDrawTool'
  #     sp.dependency 'IJSEditSDK/TOCropViewController'
  #     sp.dependency 'IJSEditSDK/IJSMapView'
  #   end 

end






























