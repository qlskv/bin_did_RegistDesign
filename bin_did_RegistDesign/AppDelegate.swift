//
//  AppDelegate.swift
//  ezDIDHolder_RegistDesign
//
//  Created by 이순빈 on 2021/09/07.
//

import UIKit

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    var config = ixcConfig.default()
    var numberKeyCode :Array<Any>!



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        ixcSecureManager.initLicense("LICENSE-3", andCustomID: "CUSTOMERID")
        config?.setImageBundleName("zix_resources.bundle")
        let numberKeyCode = [["1", "2", "3"],
                             ["4", "5", "6"],
                             ["7", "8", "9"],
                             [FUNC_KEY_CODE_RESET, "0", FUNC_KEY_CODE_BACK]]
        let numberAccKeyCondeEng = [["1", "2", "3"],
                                    ["4", "5", "6"],
                                    ["7", "8", "9"],
                                    ["reset", "0", "delete"]]
        let numberAccKeyCodeKor = [["1", "2", "3"],
                                   ["4", "5", "6"],
                                   ["7", "8", "9"],
                                   ["전체삭제", "0", "삭제"]]
        config?.setNumberKeyCode(numberKeyCode)
        config?.setNumberAccKeyCode(numberAccKeyCodeKor, langType: 1)
        config?.setNumberAccKeyCode(numberAccKeyCondeEng, langType: 2)
        config!.setKeyPadBgColor("#FF633EE3", keyPadType: 1)
        //config!.setKeyPadOriginalSize(CGSize(width: UIScreen.main.bounds.width, height: UIScreen.main.bounds.height*0.43), keyPadType: 1)
        config!.setKeyPadOriginalSize(CGSize(width: 750, height: 530), keyPadType: 1)
        config?.setKeyPadMargin(UIEdgeInsets(top: 20, left: 20, bottom: 20, right: 20), keyPadType: 1)
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

