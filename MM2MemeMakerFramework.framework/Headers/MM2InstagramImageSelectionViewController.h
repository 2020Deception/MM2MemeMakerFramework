//
//  InstagramImageSelectionViewController.h
//  memer
//
//  Created by Brian Sharrief Alim Bowman on 10/6/16.
//  Copyright © 2016 Brian Sharrief Alim Bowman. All rights reserved.
//

#import "BaseCollectionViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface MM2InstagramImageSelectionViewController : BaseCollectionViewController

- (instancetype)initWithDataSource:(id<UICollectionViewDataSource> _Nullable)datasource
                          delegate:(id<UICollectionViewDelegate> _Nullable)delegate NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDataSource:(id<UICollectionViewDataSource> _Nullable)datasource
                          delegate:(id<UICollectionViewDelegate> _Nullable)delegate
                            layout:(UICollectionViewLayout * _Nullable)layout NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
