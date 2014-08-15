//
//  NBPersonViewController.h
//  NBClientExample
//
//  Created by Peng Wang on 7/24/14.
//  Copyright (c) 2014 NationBuilder. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NBUIDefines.h"

typedef NS_ENUM(NSUInteger, NBPersonViewControllerMode) {
    NBPersonViewControllerModeViewAndEdit,
    NBPersonViewControllerModeCreate,
};

@interface NBPersonViewController : UIViewController <NBViewController>

@property (nonatomic, strong) NSNumber *editingAnimationDuration UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *editingBackgroundColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) NSNumber *subviewCornerRadius UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) NSString *tagDelimiterString UI_APPEARANCE_SELECTOR;
@property (nonatomic) CGSize textFieldInsetSize UI_APPEARANCE_SELECTOR;

@property (nonatomic) NBPersonViewControllerMode mode;

@end

@interface NBTextField : UITextField @end