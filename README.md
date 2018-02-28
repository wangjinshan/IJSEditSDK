# IJSEditSDK 使用文档

地址: https://github.com/wangjinshan/IJSEditSDK

IJSEditSDK主要是处理图片和视频的框架,主要包括 视频处理包括,裁剪,涂鸦,水印,贴图等等

使用:

如果需要贴图请先设置贴图数据,如果不设置就使用内部自带的

```
#import <IJSFoundation/IJSFoundation.h>
#import "IJSEditSDK.h"

// 设置贴图数据
    NSString *bundlePath = [[NSBundle mainBundle] pathForResource:@"JSPhotoSDK" ofType:@"bundle"];
    NSString *filePath = [bundlePath stringByAppendingString:@"/Expression"];
    [IJSFFilesManager ergodicFilesFromFolderPath:filePath completeHandler:^(NSInteger fileCount, NSInteger fileSzie, NSMutableArray *filePath) {
        IJSMapViewModel *model = [[IJSMapViewModel alloc] initWithImageDataModel:filePath];
        [self.mapDataArr addObject:model];
    }];
    
```

### 处理图片

```
  __weak typeof (self) weakSelf = self;
    UIImage *image =[UIImage imageNamed:@"8"]; //资源
    IJSImageManagerController *vc =[[IJSImageManagerController alloc]initWithEditImage:image];
    // 回调数据
    [vc loadImageOnCompleteResult:^(UIImage *image, NSURL *outputPath, NSError *error) {
        weakSelf.backImageView.image = image;
    }];
    vc.mapImageArr = self.mapDataArr;
    [self presentViewController:vc animated:YES completion:nil];
    
```

### 裁剪视频


```
 IJSVideoCutController *vc =[[IJSVideoCutController alloc] init];
   NSString *str =  [[NSBundle mainBundle] pathForResource:@"test" ofType:@"mp4"];
//    http://dvideo.spriteapp.cn/video/2017/1210/5a2d27ea6e697_wpd.mp4
    NSURL *inputPath= [NSURL URLWithString:[NSString stringWithFormat:@"file://%@", str]];  //注意本地视频需要加头
//     NSURL *inputPath= [NSURL URLWithString:@"http://dvideo.spriteapp.cn/video/2017/1210/5a2d27ea6e697_wpd.mp4"];  //注意本地视频需要加头
    vc.canEdit = NO;   //裁剪完了不会进入编辑界面
    vc.inputPath = inputPath;
    vc.didFinishCutVideoCallBack = ^(IJSVideoManagerController *controller, NSURL *outputPath, NSError *error, IJSVideoState state) {
        NSLog(@"%@",controller);
        NSLog(@"%@",outputPath);
        NSLog(@"%@",error);
        NSLog(@"%lu",(unsigned long)state);
    };
    vc.delegate = self;
    [self presentViewController:vc animated:YES completion:nil];

```

### 视频编辑

```
 IJSVideoEditController *vc =[[IJSVideoEditController alloc]init];
    NSString *str =  [[NSBundle mainBundle] pathForResource:@"test" ofType:@"mp4"];
    NSURL *inputPath= [NSURL URLWithString:[NSString stringWithFormat:@"file://%@", str]];  //注意本地视频需要加头
//         NSURL *inputPath= [NSURL URLWithString:@"http://dvideo.spriteapp.cn/video/2017/1210/5a2d27ea6e697_wpd.mp4"];  //注意本地视频需要加头
    vc.inputPath = inputPath;
    vc.didFinishCutVideoCallBack = ^(IJSVideoManagerController *controller, NSURL *outputPath, NSError *error, IJSVideoState state) {
        NSLog(@"--block------%@",controller);
        NSLog(@"--block------%@",outputPath);
        NSLog(@"--block------%@",error);
        NSLog(@"--block------%lu",(unsigned long)state);
    };
    vc.delegate = self;  // 可以通过代理方法返回数据
    [self.navigationController pushViewController:vc animated:YES];
    
//    [self presentViewController:vc animated:YES completion:nil];

```

#####代理方法可以不写

```
-(void)didFinishCutVideoWithController:(IJSVideoManagerController *)controller outputPath:(NSURL *)outputPath error:(NSError *)error state:(IJSVideoState)state
{
            IJSVideoTestController *testVc = [[IJSVideoTestController alloc] init];
            AVAsset *avaseet = [AVAsset assetWithURL:outputPath];
            testVc.avasset = avaseet;
            [self presentViewController:testVc animated:YES completion:nil];
}
-(void)didFinishCutVideoWithController:(IJSVideoManagerController *)controller outputPath:(NSURL *)outputPath error:(NSError *)error state:(IJSVideoState)state
{
            IJSVideoTestController *testVc = [[IJSVideoTestController alloc] init];
            AVAsset *avaseet = [AVAsset assetWithURL:outputPath];
            testVc.avasset = avaseet;
            [self presentViewController:testVc animated:YES completion:nil];
}
```
### cocopods 集成方法


```
pod 'IJSEditSDK'
```
代码部分和上面一样
