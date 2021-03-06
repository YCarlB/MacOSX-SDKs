/*
	NSSegmentedControl.h
	Application Kit
	Copyright (c) 2003-2016, Apple Inc.
	All rights reserved.
*/

#import <AppKit/NSControl.h>
#import <AppKit/NSCell.h>

NS_ASSUME_NONNULL_BEGIN

@class NSImage;

typedef NS_ENUM(NSUInteger, NSSegmentSwitchTracking) {
    NSSegmentSwitchTrackingSelectOne = 0,  // only one button can be selected
    NSSegmentSwitchTrackingSelectAny = 1,  // any button can be selected
    NSSegmentSwitchTrackingMomentary = 2,  // only selected while tracking
    NSSegmentSwitchTrackingMomentaryAccelerator NS_ENUM_AVAILABLE_MAC(10_10_3) = 3, // accelerator behavior, only selected while tracking
};

typedef NS_ENUM(NSInteger, NSSegmentStyle) {
    NSSegmentStyleAutomatic = 0, //Appearance is chosen depending on the type of window and the control's position inside it
    NSSegmentStyleRounded = 1,
    NSSegmentStyleRoundRect = 3,
    NSSegmentStyleTexturedSquare = 4,
    NSSegmentStyleSmallSquare = 6,
    NSSegmentStyleSeparated NS_ENUM_AVAILABLE_MAC(10_10) = 8,
    
    /* In Mac OS X 10.7, the following styles have artwork identical to NSSegmentStyleTexturedSquare, and their usage is discouraged.  Use NSSegmentStyleTexturedSquare instead because it has the correct metrics for this artwork. */
    NSSegmentStyleTexturedRounded NS_ENUM_AVAILABLE_MAC(10_5) = 2,
    NSSegmentStyleCapsule NS_ENUM_AVAILABLE_MAC(10_5) = 5
} NS_ENUM_AVAILABLE_MAC(10_5);

@interface NSSegmentedControl : NSControl {
  @private
    NSInteger _reserved1;
    NSInteger _reserved2;
    NSInteger _reserved3;
    id        _scAux;
}

@property NSInteger segmentCount;

@property NSInteger selectedSegment;

- (BOOL)selectSegmentWithTag:(NSInteger)tag;

- (void)setWidth:(CGFloat)width forSegment:(NSInteger)segment;
- (CGFloat)widthForSegment:(NSInteger)segment;

- (void)setImage:(nullable NSImage *)image forSegment:(NSInteger)segment;
- (nullable NSImage *)imageForSegment:(NSInteger)segment;


- (void)setImageScaling:(NSImageScaling)scaling forSegment:(NSInteger)segment NS_AVAILABLE_MAC(10_5);
- (NSImageScaling)imageScalingForSegment:(NSInteger)segment NS_AVAILABLE_MAC(10_5);


- (void)setLabel:(NSString *)label forSegment:(NSInteger)segment;
- (nullable NSString *)labelForSegment:(NSInteger)segment;

- (void)setMenu:(nullable NSMenu *)menu forSegment:(NSInteger)segment;
- (nullable NSMenu *)menuForSegment:(NSInteger)segment;

- (void)setSelected:(BOOL)selected forSegment:(NSInteger)segment;
- (BOOL)isSelectedForSegment:(NSInteger)segment;

- (void)setEnabled:(BOOL)enabled forSegment:(NSInteger)segment;
- (BOOL)isEnabledForSegment:(NSInteger)segment;

@property NSSegmentStyle segmentStyle NS_AVAILABLE_MAC(10_5);

@property (getter=isSpringLoaded) BOOL springLoaded NS_AVAILABLE_MAC(10_10_3); // sends action on deep-press or extended hover while dragging. Defaults to NO.

@property NSSegmentSwitchTracking trackingMode NS_AVAILABLE_MAC(10_10_3);

/*  This message is valid only for trackingMode=NSSegmentSwitchTrackingMomentaryAccelerator and provides the double value for the selected segment.
 */
@property (readonly) double doubleValueForSelectedSegment NS_AVAILABLE_MAC(10_10_3);

@property (nullable, copy) NSColor *selectedSegmentBezelColor NS_AVAILABLE_MAC(10_12_2); // The color of the selected segment's bevel, in appearances that support it

@end

@interface NSSegmentedControl (NSSegmentedControlConvenience)

/*!
 Creates a standard segmented control containing one segment for each of the provided labels.
 @param labels An array of localized label strings to use for the control's segments.
 @param trackingMode The selection mode for the control. The NSSegmentSwitchTracking enum describes the possible values and their effects.
 @param target The target object that receives action messages from the control.
 @param action The action message sent by the control.
 @return An initialized segmented control.
 */
+ (instancetype)segmentedControlWithLabels:(NSArray<NSString *> *)labels trackingMode:(NSSegmentSwitchTracking)trackingMode target:(nullable id)target action:(nullable SEL)action NS_AVAILABLE_MAC(10_12);

/*!
 Creates a standard segmented control containing one segment for each of the provided images. To ensure accessibility for this control, set the accessibilityDescription property on each of the provided images.
 @param images An array of image objects to use for the control's segments.
 @param trackingMode The selection mode for the control. The NSSegmentSwitchTracking enum describes the possible values and their effects.
 @param target The target object that receives action messages from the control.
 @param action The action message sent by the control.
 @return An initialized segmented control.
 */
+ (instancetype)segmentedControlWithImages:(NSArray<NSImage *> *)images trackingMode:(NSSegmentSwitchTracking)trackingMode target:(nullable id)target action:(nullable SEL)action NS_AVAILABLE_MAC(10_12);

@end

NS_ASSUME_NONNULL_END
