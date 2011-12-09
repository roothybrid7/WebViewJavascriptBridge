#import <UIKit/UIKit.h>

/*!
 @abstract NSNotification register name for flush message.
 @const kWebViewJavascriptBridgeFlushMessage    PostNotification name of flush message.
 */
extern NSString *const kWebViewJavascriptBridgeFlushMessage;
/*!
 @abstract NSNotification userInfo key names.
 @const kJavascriptBridge            javascriptBridge key.
 @const kJavascriptBridgeMessage     javascript string key.
 @const kJavascriptBridgeWebView     webView key.
 */
extern NSString *const kJavascriptBridge;
extern NSString *const kJavascriptBridgeMessage;
extern NSString *const kJavascriptBridgeWebView;

@class WebViewJavascriptBridge;

@protocol WebViewJavascriptBridgeDelegate <UIWebViewDelegate>

- (void)javascriptBridge:(WebViewJavascriptBridge *)bridge receivedMessage:(NSString *)message fromWebView:(UIWebView *)webView;

@end

@interface WebViewJavascriptBridge : NSObject <UIWebViewDelegate>

@property (nonatomic, assign) IBOutlet id <WebViewJavascriptBridgeDelegate> delegate;

/* Create a javascript bridge with the given delegate for handling messages */
+ (id)javascriptBridgeWithDelegate:(id <WebViewJavascriptBridgeDelegate>)delegate;

/* Send a message to the web view. Make sure that this javascript bridge is the delegate
 * of the webview before calling this method (see ExampleAppDelegate.m) */
- (void)sendMessage:(NSString *)message toWebView:(UIWebView *)webView;

@end
