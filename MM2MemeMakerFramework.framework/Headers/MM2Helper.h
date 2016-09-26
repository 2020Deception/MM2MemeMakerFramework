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

/*!
 pins the subview to the top of the superview
 @param superview the superview
 @param subview the subview
 @param height the height of the subview
 @returns the layout constraints
 */
+ (NSArray<NSLayoutConstraint *> *)pinItemToTopWithSuperView:(UIView *)superview
                                                     subview:(UIView *)subview
                                                      height:(CGFloat)height;

/*!
 sets the subview constraints to match the superview
 @param superview the superview
 @param subview the subview
 */
+ (void)widthHeightEquivalentsConstraintsWithSuperView:(UIView *)superview
                                               subview:(UIView *)subview;

/*!
 sets the subviews constraints to be evenly distributed vertically
 @param superview the superview
 @param subviews the subview
 */
+ (void)evenVerticalConstraintsWithSuperView:(UIView *)superview
                                    subviews:( NSArray<UIView *> *)subviews;

/*!
 sets the subviews constraints to be evenly distributed horizontally
 @param superview the superview
 @param subviews the subview
 */
+ (void)evenHorizontalConstraintsWithSuperView:(UIView *)superview
                                      subviews:( NSArray<UIView *> *)subviews;

/*!
 centers the subview on the the superview
 @param superview the superview
 @param subview the subview
 @param height the height of the subview
 @returns the layout constraints
 */
+ (NSArray<NSLayoutConstraint *> *)pinItemtoCenterOfSuperView:(UIView *)superview
                                                      subview:(UIView *)subview
                                                        width:(CGFloat)width
                                                       height:(CGFloat)height;

/*!
 sets the subview on the the superview with height and width contraints only
 @param superview the superview
 @param subview the subview
 @param height the height of the subview
 @returns the layout constraints
 */
+ (NSArray<NSLayoutConstraint *> *)constraintsForWidthAndHeightOnSuperView:(UIView *)superview
                                                                forSubview:(UIView *)subview
                                                                     width:(CGFloat)width
                                                                    height:(CGFloat)height;

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
