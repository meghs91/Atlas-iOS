//
//  ATLMediaAttachment.h
//  Atlas
//
//  Created by Klemen Verdnik on 2/14/15.
//  Copyright (c) 2015 Layer, Inc. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSUInteger, ATLMediaAttachmentType) {
    /**
     @constant Media attachment containing text.
     @discussion Sets mediaMIMEType = @"text/plain"; textRepresentation = input text defined at init;
     */
    ATLMediaAttachmentTypeText,
    /**
     @constant Media attachment containing GPS location.
     @discussion Sets mediaMIMEType = @"location/coordinate"; textRepresentation = @"Attachment: location";
     */
    ATLMediaAttachmentTypeLocation,
    /**
     @constant Media attachment containing image data.
     @discussion Sets mediaMIMEType = @"image/jpeg"; thumbnailMIMEType = @"image/jpeg+preview"; metadataMIMEType = @"application/json+imageSize"; textRepresentation = @"Attachment: Image";
     */
    ATLMediaAttachmentTypeImage,
    /**
     @constant Media attachment containing image data.
     @discussion Sets mediaMIMEType = @"audio/aacp"; thumbnailMIMEType = @"image/jpeg+preview"; metadataMIMEType = @"application/json+length"; textRepresentation = @"Attachment: Audio";
     */
    ATLMediaAttachmentTypeAudio,
    /**
     @constant Media attachment containing image data.
     @discussion Sets mediaMIMEType = @"video/mp4"; thumbnailMIMEType = @"image/jpeg+preview"; metadataMIMEType = @"application/json+length"; textRepresentation = @"Attachment: Video";
     */
    ATLMediaAttachmentTypeVideo,
};

/**
 @abstract The `ATLMediaAttachment` class serves as a media container and as
 an inlined text attachment for the UITextView. Use an appropriate initializer
 for desired media type.
 */
@interface ATLMediaAttachment : NSTextAttachment

///-------------------
/// @name Initializers
///-------------------

/**
 @abstract Creates a new `ATLMediaAttachment` instance of type `ATLMediaAttachmentTypeImage` based on Apple's Photo Library's `ALAsset` URL identifier.
 @param assetURL URL path of the media asset.
 @param thumbnailSize The size of the thumbnail.
 @return Instance of `ATLMediaAttachment` containing streams.
 */
+ (instancetype)mediaAttachmentWithAssetURL:(NSURL *)assetURL thumbnailSize:(NSUInteger)thumbnailSize;

/**
 @abstract Creates a new `ATLMediaAttachment` instance of type `ATLMediaAttachmentTypeImage` based on `UIImage`.
 @param assetURL Image in a form of `UIImage`.
 @param thumbnailSize The size of the thumbnail.
 @return Instance of `ATLMediaAttachment` containing streams.
 */
+ (instancetype)mediaAttachmentWithImage:(UIImage *)image thumbnailSize:(NSUInteger)thumbnailSize;

/**
 @abstract Creates a new `ATLMediaAttachment` instance of type `ATLMediaAttachmentTypeText` based on `NSString` text.
 @param text Text in a form of `NSString`.
 @return Instance of `ATLMediaAttachment` containing streams.
 */
+ (instancetype)mediaAttachmentWithText:(NSString *)text;

/**
 @abstract Creates a new `ATLMediaAttachment` instance of type `ATLMediaAttachmentTypeLocation` based on `CLLocation` GPS coordinates.
 @param location Location data in a form of `CLLocation`.
 @return Instance of `ATLMediaAttachment` containing streams.
 */
+ (instancetype)mediaAttachmentWithLocation:(CLLocation *)location;

///----------------------------
/// @name Media Item Attributes
///----------------------------

@property (nonatomic, readonly) ATLMediaAttachmentType mediaType;
@property (nonatomic, readonly) NSUInteger thumbnailSize;

///----------------------------
/// @name Consumable Attributes
///----------------------------

/* A text representation of the media, useful for push alert texts or cells that don't display media items (like conversation list view) */
@property (nonatomic, readonly) NSString *textRepresentation;

/* MIMEType of the asset and input stream providing content. */
@property (nonatomic, readonly) NSString *mediaMIMEType;
@property (nonatomic, readonly) NSInputStream *mediaInputStream;

/* MIMEType of the thumbnail and input stream providing the thumbnail content. */
@property (nonatomic, readonly) NSString *thumbnailMIMEType;
@property (nonatomic, readonly) NSInputStream *thumbnailInputStream;

/* MIMEType of additional data that accompanies the main media and an input stream providing serialized data. */
@property (nonatomic, readonly) NSString *metadataMIMEType;
@property (nonatomic, readonly) NSInputStream *metadataInputStream;

@end
