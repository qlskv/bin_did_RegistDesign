//
//  IntroViewController.swift
//  ezDIDHolder_RegistDesign
//
//  Created by 이순빈 on 2021/09/07.
//

import UIKit

class IntroViewController: UIViewController {
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        self.initView()
    }
    func initView() {
        let vc = self.storyboard?.instantiateViewController(
            withIdentifier: "CertificatePinViewController")
        self.navigationController?.pushViewController(vc!, animated: true)
    }
}
