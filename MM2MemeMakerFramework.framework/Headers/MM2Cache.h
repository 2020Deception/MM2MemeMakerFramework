//
//  MM2Cache.h
//  MM2MemeMakerFramework
//
//  Created by Brian Bowman on 9/6/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

@import Foundation;
@import Messages;

NS_ASSUME_NONNULL_BEGIN

@interface MM2Cache : NSObject

+ (instancetype)new NS_UNAVAILABLE;

+ (MM2Cache *)sharedCache;

/*!
 stickerFromImage takes an image, caches it and returns a nice sticker for you.
 @param image the input image
 @param completionBlock the completion block once the process returns
 */
- (void)stickerFromImage:(UIImage *)image completionBlock:(void (^)(MSSticker *sticker, NSError *error))completionBlock;

@property (nonatomic, readonly) NSArray<NSString *> *cacheURLs;
@property (nonatomic) NSArray<NSString *> *instagramURLs;

@property (nonatomic, readonly) MSSticker *placeholderSticker;

@end

NS_ASSUME_NONNULL_END
