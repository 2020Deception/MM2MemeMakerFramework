//
//  MM2AlertContentViewController.h
//  MM2MemeMakerFramework
//
//  Created by Brian Sharrief Alim Bowman on 9/10/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

@import UIKit;
@class MM2AlertContentViewController;

NS_ASSUME_NONNULL_BEGIN

@protocol MM2AlertContentViewControllerDelegate <NSObject>
@required
- (void)MM2AlertContentViewController:(MM2AlertContentViewController *)controller didReturnWithCaption:(NSString *)caption;
@end

@interface MM2AlertContentViewController : UIViewController<UITextFieldDelegate, UITextViewDelegate>

@property (nonatomic, readonly) UITextField *textField;
@property (nonatomic, readonly) UITextView *textView;
@property (nonatomic, readonly) BOOL longCaption;
@property (nonatomic, weak, readonly) id<MM2AlertContentViewControllerDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil NS_UNAVAILABLE;

/**
 @param delegate the delegate
 @param longCaption if enabled, the popup will use a textView instead of a textField. 
 This is more in line with Meme's that display text above or below the picture as opposed to memes where the text appears overlayed on an image.
 */
- (instancetype)initWithDelegate:(id<MM2AlertContentViewControllerDelegate>)delegate longCaption:(BOOL)longCaption NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
