//
//  HttpRequest.h
//  TEST_E2E_Engine
//
//  Created by Ko Jaewan on 2015. 2. 4..
//  Copyright (c) 2015년 INCA Internet INC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HttpRequest : NSObject
{
    NSMutableData *receivedData;
    NSURLResponse *response;
    NSString *result;
    id target;
    SEL selector;
}

- (BOOL)requestUrl:(NSString *)url bodyObject:(NSDictionary *)bodyObject;
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)aResponse;
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
- (void)setDelegate:(id)aTarget selector:(SEL)aSelector;

@property (nonatomic, retain) NSMutableData *receivedData;
@property (nonatomic, retain) NSURLResponse *response;
@property (nonatomic) NSString *result;
@property (nonatomic) id target;
@property (nonatomic, assign) SEL selector;
@end
