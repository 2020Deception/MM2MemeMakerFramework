//
//  BaseCollectionViewController.h
//
//  Created by Brian Sharrief Alim Bowman on 8/24/16.
//  Copyright © 2016 Brian Sharrief Alim Bowman. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface BaseCollectionViewController : UICollectionViewController

- (instancetype)initWithDataSource:(id<UICollectionViewDataSource>)datasource
                          delegate:(id<UICollectionViewDelegate>)delegate
                            layout:(UICollectionViewLayout *)layout NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout *)layout NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
