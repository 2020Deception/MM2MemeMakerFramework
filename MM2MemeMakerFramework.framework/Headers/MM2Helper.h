//
//  MM2Helper.h
//  MM2MemeMakerFramework
//
//  Created by Brian Bowman on 8/30/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

@import Foundation;
@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface MM2Helper : NSObject

+ (CGFloat)defaultMemeLabelHeight;

+ (UIFont *)defaultFont;
+ (UIFont *)defaultFontOfSize:(CGFloat)size;

+ (UIFont *)memeFont;
+ (UIFont *)memeFontOfSize:(CGFloat)size;

+ (CGFloat)sizeSmall;
+ (CGFloat)sizeNormal;
+ (CGFloat)sizeLarge;
+ (CGFloat)sizeXL;
+ (CGFloat)sizeXXL;

+ (UIColor *)defaultTextColor;
+ (UIColor *)defaultShadowColor;
+ (UIColor *)defaultThemeColor;
+ (UIColor *)defaultBackgroundColor;

+ (MM2Helper *)sharedInstance;

+ (void)storeAuthToken:(NSString *)token;
+ (NSString * _Nullable)authToken;

+ (UIImage *)renderImageView:(UIImageView *)imageView;

+ (UIImage *)imageWithImage:(UIImage *)image scaledToSize:(CGSize)newSize;

+ (void)saveToCameraRoll:(UIImageView *)imageView;
+ (void)showShareOptions:(UIImageView *)imageView onViewController:(UIViewController *)viewController;

@property (nonatomic, readonly) NSSet<UIFont *> *availableFonts;

@property (nonatomic) UIColor *captionColor;
@property (nonatomic) UIColor *captionShadowColor;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
