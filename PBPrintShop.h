//
//  PBPrintShop.h
//  PBPrintShop
//
//  Copyright (c) 2014 Photobucket. All rights reserved.
//
#import <UIKit/UIKit.h>

FOUNDATION_EXPORT double PBPrintShopVersionNumber;
FOUNDATION_EXPORT const unsigned char PBPrintShopVersionString[];

// NSError domain
extern NSString * const kPBPSErrorDomain;

// NSError error codes
extern NSInteger const kPBPSErrorInvalidResponse;

// NSError userInfo dictionary keys
extern NSString * const kPBPSErrorResponseHeaders;
extern NSString * const kPBPSErrorResponseBody;

// Initialize parameter dictionary keys
extern NSString * const kPBPSClientId;
extern NSString * const kPBPSClientSecret;
extern NSString * const kPBPSBaseUrl;
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
extern NSString * const kPBPSLaunchScreen;

// Launch screen values
extern NSString * const kPBPSLaunchScreenHome;
extern NSString * const kPBPSLaunchScreenShoppingCart;

// Shopping Cart Info property keys
extern NSString * const kPBPSCartItemCount;
extern NSString * const kPBPSCartTimestamp;

typedef NS_ENUM(NSInteger, PBPSInitResult) {
    PBPSInitResultNetworkError = -4,
    PBPSInitResultInvalidPlist = -3,
    PBPSInitResultMissingPlist = -2,
    PBPSInitResultInvalidParameters = -1,
    PBPSInitResultSuccess = 0,
};

typedef NS_ENUM(NSInteger, PBPSLaunchResult) {
    PBPSLaunchResultNetworkError = -3,
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
@property (nonatomic, readonly, getter=isInitialized) BOOL initialized;
@property (nonatomic, readonly) NSString *baseUrl;
@property (nonatomic, readonly) NSUInteger cartItemCount;
@property (nonatomic, readonly) NSString *cartTimestamp;

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
 Clears the customer's shopping cart of all products.
 */
- (void)clearShoppingCart;

@end
