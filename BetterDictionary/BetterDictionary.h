//
//  BetterDictionary.h
//  BetterDictionary
//
//  Created by Pooria Azimi on 27/8/2011.
//  Copyright 2011-2012 Pooria Azimi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "objc/runtime.h"
#import "DebugLog.h"
#import "NSObjectAdditions.h"
#import "NSAttributedString+Hyperlink.h"
#import "NSView+ExploreViews.h"
#import "SparkleHelper.h"

typedef enum {
	SNOW_LEOPARD, LION
} DictionaryVersion;

@interface BetterDictionary : NSObject<NSTableViewDelegate, NSTableViewDataSource> {
	NSBundle* betterDictionaryBundle;
	
	NSApplication* mainApplication;
	NSWindowController* dictionaryBrowserWindowController;
	NSWindow* dictionaryBrowserWindow;
	NSObject* dictionaryController;
    NSToolbar* dictionaryBrowserToolbar;
	NSView* dictionaryWebView;
	NSView* dictionarySearchView;
	
	NSButton* showAllToolbarButton;
	NSButton* saveOrRemoveWordToolbarButton;
	
	NSMenuItem* removeWordMenuItem;
	NSMenuItem* saveWordMenuItem;
	
	float sidebarWidth;
	BOOL sidebarIsVisible;
	
	NSTableView* dictionarySidebar;
	NSScrollView* dictionarySidebarScrollView;
	NSImage* sidebarShowAllImageDarkImage;
	NSImage* sidebarShowAllImageLightImage;
	NSImage* saveWordImage;
	NSImage* removeWordImage;
	
	NSString* searchedWord;
	NSString* lastSearchedWord;
	NSMutableArray* savedWordsArray;
	DictionaryVersion appVersion;
	
	NSToolbarItem* testToolbarItem;//TEST!!
}


+ (void)load;

- (void)determineApplicationVersion;

- (void)initToolbarItems;
- (void)setSaveOrRemoveToolbarButtonAccordingly;

- (void)createMenuItems;
- (void)showAboutBetterDictionaryWindow:(id)sender;

- (float)viewWidth;
- (float)viewHeight;

- (void)addSidebar;
- (void)_showHideSidebar:(id)sender;
- (void)showSidebar;
- (void)hideSidebar;

- (void)_saveWord:(id)sender;
- (void)saveWord:(NSString*)wordToSave;
- (void)_removeWord:(id)sender;
- (void)removeWord:(NSString*)wordToRemove;
- (void)_removeAllSavedWords:(id)sender;
- (void)removeAllSavedWords;

- (BOOL)hasAlreadySavedWord:(NSString*)word;

- (NSString*)searchedWord;
- (NSString*)searchedWordCapitalized;
-(void) searchWord:(NSString*)wordToSearch;

- (void)initSavedWordsArray;
- (void)writeSavedWordsArrayToDisk;

- (void)startInterceptingSearchTextMethod;
static void interceptSetSearchText(id self, SEL oldSelector, id arg1, ...);
static void interceptAsyncDictionarySearchDidFound(id self, SEL oldSelector, id arg1, ...);
static void interceptClearSearchResult(id self, SEL oldSelector, ...);

- (void)addMethod:(IMP)newMethodIMP forSelector:(SEL)oldMethodSelector toClass:(Class)class;
- (void)addMethod:(SEL)newMethodSelector toClass:(Class)class;
- (void)swizzleMethodWithSelector:(SEL)origSelector fromClass:(Class)origClass WithMwthodWithSelector:(SEL)replSelector fromClass:(Class)replClass;

@property (assign) NSMutableArray* savedWordsArray;

@end
