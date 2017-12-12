//
//  IJSVideoEditController.h
//  IJSPhotoSDKProject
//
//  Created by shange on 2017/8/21.
//  Copyright © 2017年 shanshen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "IJSVideoManager.h"
/**
 * 视频编辑类
 */

@protocol IJSVideoEditControllerDelegate;

@interface IJSVideoEditController : UIViewController

@property (nonatomic, strong) NSURL *inputPath; // 传进需要裁剪的视频路径

@property (nonatomic, strong) NSMutableArray *mapImageArr; // 贴图数据

@property(nonatomic,weak) id<IJSVideoEditControllerDelegate> delegate;  // 代理属性

@property(nonatomic,assign) NSInteger minVideoCut;  // 最小裁剪尺寸

@property(nonatomic,assign) NSInteger maxVideoCut;  // 最大裁剪尺寸

@property(nonatomic,copy) void(^didFinishEditVideoCallBack)(IJSVideoEditController *controller ,NSURL *outputPath,NSError *error,IJSVideoState state) ;  // 数据回调

@end

@protocol IJSVideoEditControllerDelegate <NSObject>

-(void)didFinishEditVideoWithController:(IJSVideoEditController *)controller outputPath:(NSURL *)outputPath error:(NSError *)error state:(IJSVideoState)state;

@end

