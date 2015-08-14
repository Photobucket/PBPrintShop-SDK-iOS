# PBPrintShop-SDK-iOS
Photobucket PrintShop Software Development Kit for iOS

Allows customizing and purchasing of print products available in Photobucket's PrintShop. Examples of current products include: Prints, Framed Prints, Canvas Prints, and Metal Prints.

## Requirements
* Xcode 5 or later
* Deployment on iOS 7 or above
* ARC only
* [SDWebImage](https://github.com/rs/SDWebImage)
* [Braintree](https://github.com/braintree/braintree_ios)

## Installation

### On iOS 7 (static library and resource bundle):
1. Drag PBPrintShop.h, PBPrintShop.plist, PBPrintShop.bundle, and libPBPrintShop.a into your project. Make sure the Copy option is selected.
2. In your target's settings, under the General tab, make sure libPBPrintShop.a is listed under the Linked Frameworks and Libraries section

### On iOS 8 and above (iOS framework):
1. In your target's settings, select the General tab
2. Drag the PBPrintShop.plist into your project.
3. Drag the PBPrintShop.framework into Embedded Binaries section. Make sure the Copy option is selected.

## Using the SDK

In the AppDelegate application:didFinishLaunchingWithOptions: method add code similar to the following:
```obj-c
    #import "PBPrintShop.h"
    
    NSDictionary *params = @{ kPBPSEmailAddress : @"joe@blow.com",
                             };
    PBPSInitResult result = [[PBPrintShop printShop] initializeWithParameters:params
                                                            completionHandler:^(NSError *error)
                             {
                                 if (error)
                                     NSLog(@"PBPrintShop init error: %@", error);
                                 else
                                     NSLog(@"PrintShop SDK initialized!");
                             }];
    if (result) {
        NSLog(@"PBPrintShop init error: %ld", (long)result);
    }
```

To invoke the PrintShop UI, declare your view controller as a PBPrintShopDelegate and use code similar to the following:
```
#import "PBPrintShop.h"

- (IBAction)openPrintShop:(id)sender {
    [PBPrintShop printShop].delegate = self;
    NSDictionary *params = @{kPBPSParentViewController : self,
                             };
    PBPSLaunchResult result = [[PBPrintShop printShop] launchWithParameters:params];
    if (result) {
        NSLog(@"PBPrintShop launch error: %ld", (long)result);
    }
}

- (void)printShopDidClose:(NSDictionary *)info {
    NSLog(@"PrintShopDidClose:%@", info);
}
```

## Initialization Parameters
TBD

## Launch Parameters
TBD

## Customization Plist Values
TBD
