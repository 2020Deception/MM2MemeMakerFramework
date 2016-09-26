/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Florent Vilmart
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <MM2MemeMakerFramework/SDWebImageCompat.h>

#if SD_UIKIT
#import <UIKit/UIKit.h>
#endif

//! Project version number for WebImage.
FOUNDATION_EXPORT double WebImageVersionNumber;

//! Project version string for WebImage.
FOUNDATION_EXPORT const unsigned char WebImageVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <WebImage/PublicHeader.h>

#import <MM2MemeMakerFramework/SDWebImageManager.h>
#import <MM2MemeMakerFramework/SDImageCacheConfig.h>
#import <MM2MemeMakerFramework/SDImageCache.h>
#import <MM2MemeMakerFramework/UIView+WebCache.h>
#import <MM2MemeMakerFramework/UIImageView+WebCache.h>
#import <MM2MemeMakerFramework/UIImageView+HighlightedWebCache.h>
#import <MM2MemeMakerFramework/SDWebImageDownloaderOperation.h>
#import <MM2MemeMakerFramework/UIButton+WebCache.h>
#import <MM2MemeMakerFramework/SDWebImagePrefetcher.h>
#import <MM2MemeMakerFramework/UIView+WebCacheOperation.h>
#import <MM2MemeMakerFramework/UIImage+MultiFormat.h>
#import <MM2MemeMakerFramework/SDWebImageOperation.h>
#import <MM2MemeMakerFramework/SDWebImageDownloader.h>
#if SD_MAC || SD_UIKIT
#import <MM2MemeMakerFramework/MKAnnotationView+WebCache.h>
#endif
#import <MM2MemeMakerFramework/SDWebImageDecoder.h>
#import <MM2MemeMakerFramework/UIImage+WebP.h>
#import <MM2MemeMakerFramework/UIImage+GIF.h>
#import <MM2MemeMakerFramework/NSData+ImageContentType.h>
#if SD_MAC
#import <MM2MemeMakerFramework/NSImage+WebCache.h>
#endif
#if SD_UIKIT
#import <MM2MemeMakerFramework/FLAnimatedImageView+WebCache.h>
#endif
