//
//  PBPrintShop.h
//  PBPrintShop
//
//  Copyright (c) 2014 Photobucket. All rights reserved.
//
#import <UIKit/UIKit.h>

FOUNDATION_EXPORT double PBPrintShopVersionNumber;
FOUNDATION_EXPORT const unsigned char PBPrintShopVersionString[];

// Initialize parameter dictionary keys
extern NSString * const kPBPSClientId;
extern NSString * const kPBPSClientSecret;
extern NSString * const kPBPSEmailAddress;
extern NSString * const kPBPSDataSources;
extern NSString * const kPBPSVerizonLCID;
extern NSString * const kPBPSVerizonMDN;

// Launch parameter dictionary keys
extern NSString * const kPBPSImageUrls;
extern NSString * const kPBPSImageChecksums;
extern NSString * const kPBPSAlbumId;
extern NSString * const kPBPSProductId;
extern NSString * const kPBPSPromoCode;
extern NSString * const kPBPSVerizonAPI;
extern NSString * const kPBPSParentViewController;

// Shopping Cart Info property keys
extern NSString * const kPBPSCartItemCount;
extern NSString * const kPBPSFirstCartItemTimestamp;
extern NSString * const kPBPSLastCartItemTimestamp;
extern NSString * const kPBPSLastViewedTimestamp;

typedef NS_ENUM(NSInteger, PBPSInitResult) {
    PBPSInitResultNetworkError = -3,
    PBPSInitResultMissingPlist = -2,
    PBPSInitResultInvalidParameters = -1,
    PBPSInitResultSuccess = 0,
};

typedef NS_ENUM(NSInteger, PBPSLaunchResult) {
    PBPSLaunchResultNotInitialized = -2,
    PBPSLaunchResultInvalidParameters = -1,
    PBPSLaunchResultSuccess = 0,
};

typedef NS_ENUM(NSInteger, PBPSDataSource) {
    PBPSDataSourcePhone = 1,
    PBPSDataSourcePhotobucket,
    PBPSDataSourceVZCloud,
    PBPSDataSourceFacebook,
    PBPSDataSourceInstagram,
};

@protocol PBPrintShopDelegate
- (void)printShopDidClose:(NSDictionary *)cartInfo;
@end

@interface PBPrintShop : NSObject

@property (nonatomic, weak) NSObject<PBPrintShopDelegate> *delegate;

/**
 Photobucket PrintShop singleton
 */
+ (PBPrintShop *)printShop;

/**
 Initialize the PrintShop SDK. No UI is presented. Should be called once from AppDelegate
 didFinishLaunchingWithOptions:
 */
- (PBPSInitResult)initializeWithParameters:(NSDictionary *)initParameters
                         completionHandler:(void (^)(NSError *error))completionHandler;

/**
 Presents the PrintShop UI based on launchParameters.
 */
- (PBPSLaunchResult)launchWithParameters:(NSDictionary *)launchParameters;

/**
 Returns the customer's shopping cart info.
 */
- (void)getShoppingCart:(void (^)(NSDictionary *cartInfo, NSError *error))completionHandler;

@end
