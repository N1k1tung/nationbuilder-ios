//
//  NBClientDonationsTests.m
//  NBClient
//
//  Copyright (MIT) 2014-present NationBuilder
//

#import "NBTestCase.h"

#import "FoundationAdditions.h"

#import "NBClient.h"
#import "NBClient+Donations.h"
#import "NBPaginationInfo.h"

@interface NBClientDonationsTests : NBTestCase

@property (nonatomic) NSDictionary *paginationParameters;

- (void)assertDonationsArray:(NSArray *)array;
- (void)assertDonationDictionary:(NSDictionary *)dictionary;

@end

@implementation NBClientDonationsTests

- (void)setUp
{
    [super setUp];
    [self setUpSharedClient];
    self.paginationParameters = @{ NBClientPaginationLimitKey: @5, NBClientPaginationTokenOptInKey: @1 };
}

- (void)tearDown
{
    [super tearDown];
}

#pragma mark - Helpers

- (void)assertDonationsArray:(NSArray *)array
{
    XCTAssertNotNil(array, @"Client should have received list of donations.");
    for (NSDictionary *dictionary in array) { [self assertDonationDictionary:dictionary]; }
}

- (void)assertDonationDictionary:(NSDictionary *)dictionary
{
    static NSArray *keys; static dispatch_once_t onceToken; dispatch_once(&onceToken, ^{
        keys = @[ @"id", @"amount_in_cents", @"donor_id", @"is_private", @"note", @"payment_type_name", @"succeeded_at" ];
    });
    return XCTAssertTrue([dictionary nb_hasKeys:keys], "Donation has correct attributes.");
}

#pragma mark - Tests

- (void)testFetchDonations
{
    [self setUpAsync];
    if (self.shouldUseHTTPStubbing) {
        [self stubRequestUsingFileDataWithMethod:@"GET" path:@"donations" queryParameters:self.paginationParameters];
    }
    NBPaginationInfo *requestPaginationInfo = [[NBPaginationInfo alloc] initWithDictionary:self.paginationParameters legacy:NO];
    NSURLSessionDataTask *task =
    [self.client fetchDonationsWithPaginationInfo:requestPaginationInfo completionHandler:^(NSArray *items, NBPaginationInfo *paginationInfo, NSError *error) {
        [self assertServiceError:error];
        [self assertDonationsArray:items];
        [self assertPaginationInfo:paginationInfo withPaginationParameters:self.paginationParameters];
        [self completeAsync];
    }];
    [self assertSessionDataTask:task];
    [self tearDownAsync];
}

- (void)testCreateDonation
{
    if (!self.shouldUseHTTPStubbing) { return; }
    [self setUpAsync];
    NSDictionary *parameters = @{ NBClientDonationAmountInCentsKey: @"100",
                                  NBClientDonationDonorIdentifierKey: @(self.supporterIdentifier),
                                  NBClientDonationPaymentTypeNameKey: @"Cash" };
    [self stubRequestUsingFileDataWithMethod:@"POST" path:@"donations" queryParameters:nil];
    NSURLSessionDataTask *task =
    [self.client createDonationWithParameters:parameters completionHandler:^(NSDictionary *item, NSError *error) {
        [self assertServiceError:error];
        [self assertDonationDictionary:item];
        [self completeAsync];
    }];
    [self assertSessionDataTask:task];
    [self tearDownAsync];
}

- (void)testSaveDonation
{
    if (!self.shouldUseHTTPStubbing) { return; }
    [self setUpAsync];
    NSUInteger identifier = 3;
    NSDictionary *parameters = @{ NBClientDonationAmountInCentsKey: @"200" };
    [self stubRequestUsingFileDataWithMethod:@"PUT" pathFormat:@"donations/:id" pathVariables:@{ @"id": @(identifier) } queryParameters:nil];
    NSURLSessionDataTask *task =
    [self.client saveDonationByIdentifier:identifier withParameters:parameters completionHandler:^(NSDictionary *item, NSError *error) {
        [self assertServiceError:error];
        [self assertDonationDictionary:item];
        [self completeAsync];
    }];
    [self assertSessionDataTask:task];
    [self tearDownAsync];
}

- (void)testDeleteDonation
{
    if (!self.shouldUseHTTPStubbing) { return; }
    [self setUpAsync];
    NSUInteger identifier = 3;
    [self stubRequestUsingFileDataWithMethod:@"DELETE" pathFormat:@"donations/:id" pathVariables:@{ @"id": @(identifier) } queryParameters:nil];
    NSURLSessionDataTask *task = [self.client deleteDonationByIdentifier:identifier completionHandler:^(NSDictionary *item, NSError *error) {
        [self assertServiceError:error];
        XCTAssertNil(item, @"Donation dictionary should not exist.");
        [self completeAsync];
    }];
    [self assertSessionDataTask:task];
    [self tearDownAsync];
}

@end
