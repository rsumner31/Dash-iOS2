//
//  Copyright (C) 2016  Kapeli
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>
#import "DHRepoTableViewCell.h"
#import "DHFeedResult.h"

@interface DHFeed : NSObject

@property (strong) NSString *feed;
@property (strong) NSString *feedURL;
@property (strong) NSString *iconName;
@property (strong) NSArray *aliases;
@property (strong) NSString *size;
@property (assign) BOOL doesNotHaveVersions;
@property (assign) BOOL waiting;
@property (assign) BOOL isCustom;

@property (assign) BOOL progressShown;
@property (assign) BOOL checkingForUpdates;
@property (assign) BOOL installing, installed;
@property (strong) NSString *installedVersion;
@property (assign) float progress;
@property (retain) NSString *detailString;
@property (strong) NSString *error;
@property (strong) DHFeedResult *feedResult;
@property (retain) NSObject *identifier;
@property (weak) DHRepoTableViewCell *cell;
@property (assign) CGFloat maxRightDetailWidth;

+ (instancetype)feedWithFeed:(NSString *)aFeed icon:(NSString *)aIcon aliases:(id)someAliases doesNotHaveVersions:(BOOL)doesNotHaveVersions;
+ (DHFeed *)feedWithDictionaryRepresentation:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryRepresentation;
- (NSString *)docsetNameWithVersion:(BOOL)withVersion;
- (NSString *)stringValue;
- (void)prepareCell:(DHRepoTableViewCell *)cell;
- (NSString *)sortName;
- (void)adjustTitleLabelWidthBasedOnButtonsShown;
- (UIImage *)icon;
- (NSString *)uniqueIdentifier; // Used to find a corresponding feed from a installed docset

@end
