//
//  IJSVideoCutController.h
//  IJSPhotoSDKProject
//
//  Created by shange on 2017/8/14.
//  Copyright © 2017年 shanshen. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 * 视频裁剪类
 */

#import "IJSVideoManager.h"

@protocol IJSVideoCutControllerDelegate;

@interface IJSVideoCutController : UIViewController

@property (nonatomic, strong) NSURL *inputPath; // 传进需要裁剪的视频路径

@property (nonatomic, assign) CGFloat minCutTime; // 最小截取时间 > 1
@property (nonatomic, assign) CGFloat maxCutTime; // 最大截取时间 > 10

@property (nonatomic, strong) NSMutableArray *mapImageArr; // 贴图数据

@property (nonatomic, assign) BOOL canEdit; // 进入编辑界面

@property(nonatomic,weak) id<IJSVideoCutControllerDelegate > delegate;  // 代理属性

@end

@protocol IJSVideoCutControllerDelegate <NSObject>

-(void)didFinishCutVideoWithController:(IJSVideoCutController *)controller  outputPath:(NSURL *)outputPath error:(NSError *)error state:(IJSVideoState)state;

@end
