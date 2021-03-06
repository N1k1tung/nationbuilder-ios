# NationBuilder iOS SDK 

[![CI Status](http://img.shields.io/travis/nationbuilder/nationbuilder-ios.svg?style=flat)](https://travis-ci.org/nationbuilder/nationbuilder-ios)
[![Version](https://img.shields.io/cocoapods/v/NBClient.svg?style=flat)](http://cocoadocs.org/docsets/NBClient)
[![License](https://img.shields.io/cocoapods/l/NBClient.svg?style=flat)](http://cocoadocs.org/docsets/NBClient)
[![Platform](https://img.shields.io/cocoapods/p/NBClient.svg?style=flat)](http://cocoadocs.org/docsets/NBClient)

## Usage

To try out the sample app (NB Sample), follow these steps.

1. Make sure you clone this repo and download Xcode. You'll eventually need to
run and build the NBClientExample project. Before that you need to install some
dependencies:

  ```bash
  ~> sudo gem install -N cocoapods
  nationbuilder-ios> pod install
  ```

2. Open `NBClient.workspace`. Make sure to delete the configuration file at
`./NBClientExample/NBClientExample/NationBuilder-Info-Local.plist`. Build and
run using the `NBClientExample` scheme.

3. Using the NationBuilder Control Panel, go to `Settings` > `Apps` > `Install
new app install`. Install the `NBClientExample` app for your nation.

4. Open the previously built `NB Sample` app in the iOS Simulator.

5. In the app, click the signin button on the top left. Provide your nation's
slug. In an in-app Safari window (`SFSafariViewController`), sign into your
account on your nation and authorize the app.

Refer to the [documentation section][] and the [implementation checklist][] on
how to use the SDK to build your app. Note that the sample app intends to be a
modest example of using the NBClient library. It intends to use modern iOS
conventions, no external dependencies, and stock UIKit classes.

### Code Samples

If the code in the sample app is too much for you, we have code samples in
[Objective-C][code sample] and [Swift][swift code sample] that just contain a
sample `UIAppDelegate` subclass.

### Swift

Swift support is now available. It has only been tested on Xcode 6.3+. There
are a couple additional things to do for using Swift with the SDK, and they
are listed in the [code sample][swift code sample].

## Features

### Authentication & Authorization:

Via an in-app Safari window (`SFSafariViewController`), sign into your nation
and authorize the application.

![authentication gif][]

### Account Management & Persistence:

Sign into multiple nations or different accounts on the same nation. Accounts
get stored and persist across app uses. Note the authentication happens via an
in-app Safari window (`SFSafariViewController`).

![accounts gif][]

### Methods for API Endpoints:

Use the client to fetch and manipulate data via the NationBuilder API, to save
you time to focus on building the rest of your app.

![people crud gif][]

## Installation

NBClient is available through [CocoaPods][]. To install it, simply add the
following line to your Podfile:

```ruby
pod 'NBClient', '~> 1.3.0'
```

## Requirements

The SDK requires iOS 9 and above. All included UI components (the accounts
component, the sample app) are universal, supporting both iPhone and iPad.

## Documentation

Detailed guides and code samples are at NationBuilder [iOS developer
documentation][]. Or, if you prefer reading on Github or want to contribute
edits, the [guides][Github guides] are also available on Github.

## Testing

You can pass the arguments in `.travis.yml` to `xctool` (`brew install xctool`)
to run manually. The simpler alternative is to run tests in Xcode for the
`NBClient` scheme.

## License

NBClient is available under the MIT license. See the LICENSE file for more info.

## Credits

The NBClient/UI component uses the [Stroke 7 Icon Font Set by Pixeden][icon font].

__[Next: Installing ➔](Documentation/Guides/Installing.md)__

[documentation section]: #documentation
[implementation checklist]: Documentation/Guides/Using-Everything.md#implementation-checklist
[code sample]: https://gist.github.com/hlfcoding/0cf43f0dc72cc99e2ca6
[swift code sample]: https://gist.github.com/hlfcoding/fa2052a3c822792a6d20
[authentication gif]: https://cloud.githubusercontent.com/assets/100884/5255641/655d2b68-7972-11e4-96fa-3384747c5f87.gif
[accounts gif]: https://cloud.githubusercontent.com/assets/100884/5255636/6183ec8e-7972-11e4-8e14-8bec0d7b1e36.gif
[people crud gif]: https://cloud.githubusercontent.com/assets/100884/5256354/140ad198-797c-11e4-8064-8f3c5ffef795.gif
[CocoaPods]: http://cocoapods.org
[iOS developer documentation]: http://nationbuilder.com/api_documentation#ios_sdk
[Github guides]: Documentation/Guides
[icon font]: http://pixeden.com/icon-fonts/stroke-7-icon-font-set
