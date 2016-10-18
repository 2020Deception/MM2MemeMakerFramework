//
//  MM2CaptionViewController.h
//  MM2MemeMakerFramework
//
//  Created by Brian Bowman on 8/30/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MM2AlertContentViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class MM2CaptionViewController;

@protocol MM2CaptionViewControllerDelegate <NSObject>

@required

/*!
 called once the share or save is completed
 @param captionViewController self explanatory
 @param caption the caption they added
 @param oldImage the original image
 @param memeImage the memed image
 */
- (void)controller:(MM2CaptionViewController *)captionViewController
didFinishWithCaption:(NSString *)caption
          oldImage:(UIImage *)oldImage
         memeImage:(UIImage *)memeImage;

@optional

/*!
 didTriggerCaptionGestureWithImage is called when they tap the image which typically displays an AlertView
 */
- (void)didTriggerCaptionGestureWithImage:(UIImage *)image;

/*!
 didTriggerShowOptionsGesture is called when they long press which typically triggers display of share options
 */
- (void)didTriggerShowOptionsGestureWithImage:(UIImage *)image;

/*! 
 didFinishWithTrashCan is called when they press the trash can. It means they want to exit (back button pressed)
 */
- (void)didFinishWithTrashCan;

@end

/*!
 MM2CaptionViewController is your one stop shop to making cool memes
 */
@interface MM2CaptionViewController : UIViewController<UITextFieldDelegate, MM2AlertContentViewControllerDelegate>

// DONT use these
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil NS_UNAVAILABLE;

// USE these
- (instancetype)initWithImage:(UIImage *)image NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithImage:(UIImage *)image delegate:(id<MM2CaptionViewControllerDelegate>)delegate NS_DESIGNATED_INITIALIZER;

// you can override these if you want to subclass MM2CaptionViewController
- (void)showOptions:(UIGestureRecognizer *)gesture;
- (void)showPrompt:(UIGestureRecognizer *)gesture;

@property (nonatomic, readonly) UIImage *imageToBeMemed;
@property (nonatomic, readonly) UIImageView *imageView;
@property (nonatomic, readonly, weak) id<MM2CaptionViewControllerDelegate> delegate;

/*!
 enable this to disable touch to caption and long press to save, including the delegate callbacks.
 */
@property (nonatomic) BOOL disableTouchGestures;

/*!
 enable this to disable touch to drag on created meme lines.
 */
@property (nonatomic) BOOL disableTouchDrag;

@end

NS_ASSUME_NONNULL_END
