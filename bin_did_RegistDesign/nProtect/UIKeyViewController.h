//
//  UIKeyViewController.h
//  viewTest
//
//  Created by 잉카 u-biz on 12. 2. 21..
//  Copyright (c) 2012년 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ixcPredefConst.h"
#import "ixcCryptoPlugin.h"

@class IxcInputResult;

// 입력 결과 클래스
@interface IxcInputCipherResult : NSObject
@property(nonatomic) int encDataLength;             // 입력 길이
@property(nonatomic, retain) NSString *encData;     // 암호화된 입력 데이터
@property(nonatomic, retain) NSString *key;         // 암호화 키
@property(nonatomic, retain) NSData *masterKey;     // 암호화 키
@end

@interface UIKeyViewController : UIViewController <UITextFieldDelegate>
@property (readonly, copy) NSString *configDescription; // 사용자 설정 값 들을 서술

- (void)registerViews:(UIView *)view forced:(BOOL)forced;
- (void)addSecureField:(UITextField *)textField;
- (void)addSecureField:(UITextField *)textField label:(NSString *)label;
- (void)addSecureField:(UITextField *)textField configId:(NSString *) configId;
- (void)delSecureField:(UITextField *)textField;
- (BOOL)isSecureField:(UITextField *)textField;
- (void)setShuffleType:(int)nType;
- (void)setMixedField:(UITextField *)textField setFormat:(NSString *) format;
- (void)setHoverButtonSizeRatio:(float)portraitRatio setLandscapeRatio:(float) landscapeRatio;
- (void)setWaitingIndicatorEnable:(BOOL)enabled;
- (void)setKeyPadImagePreLoad:(BOOL)preLoad;
- (void)setMaxLength:(unsigned long)length Of:(UITextField *)textField;
- (void)setMinLength:(unsigned long)length Of:(UITextField *)textField;
- (void)setInputCheckPolicy:(unsigned long)policy To:(UITextField *)textField;
- (t_STRENGTH_CHECK_POLICY)checkInputTypeStrength:(UITextField *)textField;
- (BOOL)setInputTypeStrengthPolicy:(unsigned long) policy Of:(UITextField *)textField;
- (void)setCryptoPlugin:(t_CRYPTO_PLUGIN)pluginId;
- (void)resetCryptoPlugin;
- (int)validateInputs:(NSArray *)patterns To:(UITextField *)textField FoundIndex:(uint *)pFoundIndex;

- (void)setAutoMoveMode:(BOOL)mode ofField:(UITextField *)textField;
- (void)setAutoMoveMode:(BOOL)mode ofField:(UITextField *)textField nextField:(UITextField *)nextField;
- (void)setAutoMoveModeOverAll:(BOOL)mode;
- (void)setAutoMoveWithChains:(NSArray *)inputFields;
- (UITextField *)moveToPrevInputBox;
- (UITextField *)moveToNextInputBox;

- (void)clearInput:(UITextField*)textField;
- (int)setServerKey:(NSString *)key To:(UITextField *)textField;
- (IxcInputCipherResult *)getInputResultOf:(UITextField *)textField;
- (IxcInputCipherResult *)getInputResultOf:(UITextField *)textField WithMasterKey:(NSData *)masterKey;
- (IxcInputCipherResult *)repackResultOf:(UITextField *)textField WithServerKey:(NSString *)serverKey;
- (IxcInputCipherResult *)packResultOf:(NSString *)plainText WithServerKey:(NSString *)serverKey;
- (NSString *)getRealText:(UITextField *)textField;
- (NSData *)getRealTextS:(UITextField *)textField;
- (BOOL)getRealText:(UITextField*)textField realText:(unsigned char *) realText;
- (NSComparisonResult)compare:(UITextField *)textField1 With:(UITextField *)textField2;
- (BOOL)putPlainText:(NSString *)text To:(UITextField *)textField;

- (void)disableHideButton;
- (void)setExtraToolbar:(UIView *)toolBar;
- (void)showExtraToolbar:(BOOL)isShow;
- (void)createHiddenUITextField:(int)keypadType;
- (UITextField *)hiddenUITextField;
- (void)showKeypad:(UITextField *)textField;
- (void)hideKeypad;
- (BOOL)isMixedField:(UITextField *)textField;
- (NSInteger)checkMixedFieldFormat:(NSInteger) index;
- (NSString *)mixedFieldFormatCharacterAtIndex:(NSInteger) index;
- (BOOL)isAnimation;

/*
 * Callback
 */
- (void)syncViewChangeHeight:(CGFloat)padHeight;
- (void)inputViolationOccured:(unsigned long)errorCode;
- (void)inputDone:(UITextField *)textField;
- (void)keypadTouchesEnded;
- (void)keypadTouchesEnded:(NSString *)lastKey;
- (void)keypadTouchesEnded:(NSString *)lastKey InputLength:(NSUInteger)inputLength;
- (void)beginWaitingIndicator;
- (void)endedWaitingIndicator;

/*
 * Deprecated 메소드 들
 */

// Deprecated - (void)setMaxLength:(unsigned long)length Of:(UITextField *)textField; 사용 추천, 같은 함수 임
- (void)setMaxLength:(UITextField *)textField :(unsigned long)length;

// Deprecated - (void)setMinLength:(unsigned long)length Of:(UITextField *)textField; 사용 추천, 같은 함수 임
- (void)setMinLength:(UITextField *)textField :(unsigned long)length;

// Deprecated - (BOOL)getServerData:(NSString **)cipherData AndKey:(NSString **)keyData Of:(UITextField *)textField; 사용 추천, 같은 함수 임
- (BOOL)getServerData:(UITextField *)textField :(NSString **)cipherData Key:(NSString **)keyData;

// Deprecated - (NSString *)getRealText:(UITextField *)textField; 사용 추천, 입력 결과를 객체로 받는다.
- (BOOL)getServerData:(NSString **)cipherData AndClientKey:(NSString **)clientKey Of:(UITextField *)textField;

// Deprecated - (
- (BOOL)repackResult:(NSString **)cipherData AndClientKey:(NSString **)clientKey WithServerKey:(NSString *)serverKey Of:(UITextField *)textField;

// Deprecated - [ixcSecureManager getVersion]; 사용 추천, 같은 함수 임
+ (int)getVersion;

// Deprecated - [ixcSecureManager getVersionString]; 사용 추천, 같은 함수 임
+ (NSString *)getVersionString;
@end

