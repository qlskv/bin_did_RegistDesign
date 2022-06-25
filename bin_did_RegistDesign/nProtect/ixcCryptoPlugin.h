//
//  ixcCryptoPlugin.h
//  ShuffleKey
//
//  Created by Ko Jaewan on 2016. 8. 11..
//
//

#import <Foundation/Foundation.h>


typedef enum {
    kCRYPTO_PLUGIN_XECURE_SMART = 0x800,
    kMAX_CRYPTO_PLUGIN,
    kTEST_XECURE_SMART
} t_CRYPTO_PLUGIN;

@interface ixcCryptoPlugin : NSObject

- (instancetype)initWithId:(int)pluginId;
- (void)reset;
- (NSData *)getMasterKey;
- (NSData *)encrypt:(NSString *)plainText;
- (NSData *)encrypt:(NSString *)plainText WithMasterKey:(NSData *)masterKey;
@end
