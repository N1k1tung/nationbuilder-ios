//
//  NBClient_Internal.h
//  NBClient
//
//  Copyright (c) 2014-2015 NationBuilder. All rights reserved.
//

#import "NBClient.h"

@interface NBClient ()

@property (nonatomic, copy, readwrite, nonnull) NSString *nationSlug;
@property (nonatomic, readwrite, nonnull) NSURLSession *urlSession;
@property (nonatomic, readwrite, nonnull) NSURLSessionConfiguration *sessionConfiguration;

@property (nonatomic, readwrite, nullable) NBAuthenticator *authenticator;

@property (nonatomic, readwrite, nonnull) NSURL *baseURL;
@property (nonatomic, null_resettable) NSURLComponents *baseURLComponents;
@property (nonatomic, copy, nonnull) NSString *defaultErrorRecoverySuggestion;

- (void)commonInitWithNationSlug:(nonnull NSString *)nationSlug
                customURLSession:(nullable NSURLSession *)urlSession
   customURLSessionConfiguration:(nullable NSURLSessionConfiguration *)sessionConfiguration;

- (void)updateBaseURLComponents;

- (nonnull NSURLSessionDataTask *)baseFetchTaskWithURLComponents:(nonnull NSURLComponents *)components
                                                      resultsKey:(nonnull NSString *)resultsKey
                                                  paginationInfo:(nullable NBPaginationInfo *)paginationInfo
                                               completionHandler:(nullable NBClientResourceListCompletionHandler)completionHandler;
- (nonnull NSURLSessionDataTask *)baseFetchTaskWithURLComponents:(nonnull NSURLComponents *)components
                                                      resultsKey:(nullable NSString *)resultsKey
                                               completionHandler:(nullable NBClientResourceItemCompletionHandler)completionHandler;

// This is the common save method.
- (nonnull NSURLSessionDataTask *)baseCreateTaskWithURL:(nonnull NSURL *)url
                                             parameters:(nonnull NSDictionary *)parameters
                                             resultsKey:(nullable NSString *)resultsKey
                                      completionHandler:(nullable NBClientResourceItemCompletionHandler)completionHandler;
// This is the more common save method.
- (nonnull NSURLSessionDataTask *)baseSaveTaskWithURL:(nonnull NSURL *)url
                                           parameters:(nonnull NSDictionary *)parameters
                                           resultsKey:(nonnull NSString *)resultsKey
                                    completionHandler:(nullable NBClientResourceItemCompletionHandler)completionHandler;
// This is the less common one, for custom requests.
// NOTE: We use a dynamically typed block (to allow both resource item and list
//       completion handlers) because there's no other different in method selector
//       if it were to be two methods, unlike the base fetch task methods.
- (nonnull NSURLSessionDataTask *)baseSaveTaskWithURLRequest:(nonnull NSURLRequest *)request
                                                  resultsKey:(nonnull NSString *)resultsKey
                                           completionHandler:(nullable id)completionHandler;

// This is the more common delete method.
- (nonnull NSURLSessionDataTask *)baseDeleteTaskWithURL:(nonnull NSURL *)url
                                      completionHandler:(nullable NBClientResourceItemCompletionHandler)completionHandler;
// This is a less common one, for partial deletes.
- (nonnull NSURLSessionDataTask *)baseDeleteTaskWithURL:(nonnull NSURL *)url
                                             parameters:(nonnull NSDictionary *)parameters
                                             resultsKey:(nullable NSString *)resultsKey
                                      completionHandler:(nullable NBClientResourceItemCompletionHandler)completionHandler;
// This is a less common one, for custom requests.
- (nonnull NSURLSessionDataTask *)baseDeleteTaskWithURLRequest:(nonnull NSURLRequest *)request
                                                    resultsKey:(nullable NSString *)resultsKey
                                             completionHandler:(nullable NBClientResourceItemCompletionHandler)completionHandler;

- (nonnull NSMutableURLRequest *)baseRequestWithURL:(nonnull NSURL *)url
                                         parameters:(nullable NSDictionary *)parameters
                                              error:(NSError * __nullable * __nullable)error;

- (nonnull NSURLSessionDataTask *)startTask:(nonnull NSURLSessionDataTask *)task;

- (nonnull void (^)(NSData * __nonnull, NSURLResponse * __nonnull, NSError * __nullable))
  dataTaskCompletionHandlerForFetchResultsKey:(nullable NSString *)resultsKey
                              originalRequest:(nonnull NSURLRequest *)request
                            completionHandler:(nullable void (^)(id __nullable results, NSDictionary * __nullable jsonObject, NSError * __nullable error))completionHandler;

- (nonnull NSError *)errorForResponse:(nonnull NSHTTPURLResponse *)response jsonData:(nonnull NSDictionary *)data;
- (nonnull NSError *)errorForJsonData:(nonnull NSDictionary *)data resultsKey:(nonnull NSString *)resultsKey;
- (void)logResponse:(nullable NSHTTPURLResponse *)response data:(nullable id)data;

@end
