#import <UIKit/UIKit.h>

/*!
 @abstract NSNotification register name for flush message.
 @const WebViewJavascriptBridgeFlushMessage    PostNotification name of flush message.
 */
extern NSString *const WebViewJavascriptBridgeFlushMessage;
/*!
 @abstract NSNotification userInfo key names.
 @const JavascriptBridge            javascriptBridge key.
 @const JavascriptBridgeMessage     javascript string key.
 @const JavascriptBridgeWebView     webView key.
 */
extern NSString *const JavascriptBridge;
extern NSString *const JavascriptBridgeMessage;
extern NSString *const JavascriptBridgeWebView;

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
