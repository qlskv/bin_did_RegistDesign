//
//  ixcConfig.h
//  ShuffleKey
//
//  Created by Ko Jaewan on 2015. 7. 29..
//
//

#import <UIKit/UIKit.h>

@interface ixcConfig : NSObject

+ (instancetype)defaultConfig;
+ (instancetype)configWithId:(NSString *) configId;

@property (nonatomic) int spaceBtnType;
@property (nonatomic) BOOL enableSecureAccesibility;
@property (nonatomic) BOOL enableCryptoContainer;
@property (readonly, copy) NSString *configDescription;

- (NSString *)keyPadBgColor:(int) keyPadType;
- (NSString *)keyPadBgColorDark:(int) keyPadType;
- (NSString *)lowerCaseKeyCode:(int) rowIndex colIndex:(int) colIndex;
- (NSString *)upperCaseKeyCode:(int) rowIndex colIndex:(int) colIndex;
- (NSString *)specialKeyCode:(int) rowIndex colIndex:(int) colIndex;
- (NSString *)numberKeyCode:(int) rowIndex colIndex:(int) colIndex;
- (NSString *)lowerCaseAccKeyCode:(int) rowIndex colIndex:(int) colIndex langType:(int) langType;
- (NSString *)upperCaseAccKeyCode:(int) rowIndex colIndex:(int) colIndex langType:(int) langType;
- (NSString *)specialAccKeyCode:(int) rowIndex colIndex:(int) colIndex langType:(int) langType;
- (NSString *)numberAccKeyCode:(int) rowIndex colIndex:(int) colIndex langType:(int) langType;
- (NSString *)accKeyHint:(int) keyType langType:(int) langType;
- (NSString *)quertyGapKeyBgColor:(int) index;
- (NSString *)imageBundleName;
- (NSString *)imageBundleNameDark;
- (NSArray *)numberKeyCode;
- (NSArray *)lowerCaseKeyCode;
- (NSArray *)upperCaseKeyCode;
- (NSArray *)specialCaseKeyCode;
- (NSArray *)showAnimationValue:(int) keyPadType;
- (NSArray *)hideAnimationValue:(int) keyPadType;
- (NSArray *)keyBgColor:(int) keyPadType;
- (NSArray *)keyPushBgColor:(int) keyPadType;

- (CGFloat)keySizeRatio:(int) keyType keyPadType:(int) keyPadType;
- (CGSize)keyPadOriginalSize:(int) keyPadType;
- (CGSize)keyOriginalSize:(int) keyPadType;
- (UIEdgeInsets)keyPadMargin:(int) keyPadType;

- (BOOL) isFuncKeyBGCustom:(int) nFuncKeyType keyPadType:(int) keyPadType;
- (BOOL) isVibrateMode:(int) keyPadType;
- (BOOL) isDrawingMode:(int) keyPadType;
- (BOOL) numberGapKeyEnable;
- (int) hapticMode:(int) keyPadType;


- (void)setKeyPadBgColor:(NSString *) bgColor keyPadType:(int) keyPadType;
- (void)setKeyPadBgColorDark:(NSString *) bgColor keyPadType:(int) keyPadType;
- (void)setQuertyGapKeyBgColor:(NSString *) firstLineBgColor otherLineBgColor:(NSString *) otherLineBgColor;
- (void)setKeyBgColor:(NSArray*) bgColor keyPadType:(int) keyPadType;
- (void)setKeyPushBgColor:(NSArray*) bgColor keyPadType:(int) keyPadType;
- (void)setKeySizeRatio:(CGFloat) ratio keyType:(int) keyType keyPadType:(int) keyPadType;
- (void)setKeyPadOriginalSize:(CGSize)keyPadSize keyPadType:(int) keyPadType;
- (void)setKeyOriginalSize:(CGSize)keySize keyPadType:(int) keyPadType;
- (void)setKeyPadMargin:(UIEdgeInsets)margin keyPadType:(int) keyPadType;

- (void)setLowerCaseKeyCode:(NSArray *) keyCode;
- (void)setUpperCaseKeyCode:(NSArray *) keyCode;
- (void)setSpecialKeyCode:(NSArray *) keyCode;
- (void)setNumberKeyCode:(NSArray *) keyCode;
- (void)setLowerCaseAccKeyCode:(NSArray *) accKeyCode langType:(int) langType;
- (void)setUpperCaseAccKeyCode:(NSArray *) accKeyCode langType:(int) langType;
- (void)setSpecialAccKeyCode:(NSArray *) accKeyCode langType:(int) langType;
- (void)setNumberAccKeyCode:(NSArray *) accKeyCode langType:(int) langType;
- (void)setSpaceBtnType:(int) btnType;
- (void)setFuncKeyBGCustom:(int) nFuncKeyType keyPadType:(int) keyPadType;
- (void)setEnableSecureAccesibility:(BOOL) enableSecure;
- (void)setAccKeyHint:(NSString *) accHint keyType:(int) keyType langType:(int) langType;
- (void)setVibrateMode:(BOOL) vibrateMode keyPadType:(int) keyPadType;
- (void)setHapticMode:(int) hapticMode keyPadType:(int) keyPadType;
- (void)setShowAnimation:(CGFloat) timeInterval options:(int)animationType repeat:(CGFloat)repeat keyPadType:(int) keyPadType;
- (void)setHideAnimation:(CGFloat) timeInterval options:(int)animationType repeat:(CGFloat)repeat keyPadType:(int) keyPadType;
- (void)setNumberGapKeyEnable:(BOOL) enableGapKey;
- (void)setImageBundleName:(NSString *) bundleName;
- (void)setImageBundleNameDark:(NSString *) bundleName;

@end

