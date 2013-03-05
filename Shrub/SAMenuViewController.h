//
//  SAMenuViewController.h
//  Shrub
//
//  Created by Andrew Carter on 3/4/13.
//  Copyright (c) 2013 Pinch Studios. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SAMenuViewController;

@protocol SAMenuViewControllerDatasource <NSObject>

@required

- (NSUInteger)numberOfRowsInMenuViewController:(SAMenuViewController *)menuViewController;

@optional

- (NSString *)menuViewController:(SAMenuViewController *)menuViewController titleForRowAtIndex:(NSUInteger)index;
- (UIImage *)menuViewController:(SAMenuViewController *)menuViewController imageForRowAtIndex:(NSUInteger)index;

@end

@interface SAMenuViewController : UIViewController

- (void)toggleMenuHidden;
- (void)reloadData;

@property (nonatomic, assign, getter = isMenuHidden) BOOL menuHidden;
@property (nonatomic, weak) id <SAMenuViewControllerDatasource> datasource;
@property (nonatomic, strong) UIViewController *contentViewController;

@end

@interface UIViewController (SAMenuViewController)

@property (nonatomic, readonly) SAMenuViewController *menuViewController;

@end