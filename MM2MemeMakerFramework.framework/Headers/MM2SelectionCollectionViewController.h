//
//  Created by Brian Sharrief Alim Bowman on 8/24/16.
//  Copyright © 2016 Brian Sharrief Alim Bowman. All rights reserved.
//

#import "BaseCollectionViewController.h"
#import "MM2SelectionCollectionViewLayout.h"

NS_ASSUME_NONNULL_BEGIN

@interface MM2SelectionCollectionViewController : BaseCollectionViewController

- (instancetype)initWithDataSource:(id<UICollectionViewDataSource> _Nullable)datasource
                          delegate:(id<UICollectionViewDelegate> _Nullable)delegate NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDataSource:(id<UICollectionViewDataSource> _Nullable)datasource
                          delegate:(id<UICollectionViewDelegate> _Nullable)delegate
                            layout:(UICollectionViewLayout * _Nullable)layout NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
