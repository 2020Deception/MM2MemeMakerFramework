//
//
//  Created by Brian Sharrief Alim Bowman on 8/24/16.
//  Copyright © 2016 Brian Sharrief Alim Bowman. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface MM2SelectionCollectionViewCell : UICollectionViewCell

- (void)setImageView:(UIImageView *)imageView;
- (void)setImage:(UIImage *)image;

@property (nonatomic, readonly) UIImageView *imageView;
@property (nonatomic, readonly) UIImage *image;

@end

NS_ASSUME_NONNULL_END
