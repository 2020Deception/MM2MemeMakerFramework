//
//  MM2Label.h
//  MM2MemeMakerFramework
//
//  Created by Brian Bowman on 8/30/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MM2Label : UILabel

/*!
 If you pass YES the label will use the Meme font (Impact) otherwise it will default to Apple Casual.
 */
- (instancetype)initWithMemeFont:(BOOL)useMemeFont NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
