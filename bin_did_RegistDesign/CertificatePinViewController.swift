//
//  CertificatePinViewController.swift
//  ezDIDHolder_RegistDesign
//
//  Created by 이순빈 on 2021/09/07.
//

import UIKit

class CertificatePinViewController: ViewController, CustomOTPFieldProtocol, CustomOTPFieldDelegate {
    func valueUpdated(sender: Any, value: String) {
        
    }
    func didUserFinishEnter(the code: String) {
        
    }


    

    @IBOutlet weak var numberPad: CustomOTPField!
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        //numberPad.becomeFirstResponder()
        
        //number.text(in: UITextRange)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.hidesBackButton = true
        //self.navigationController?.setNavigationBarHidden(true, animated: true)
        setupOTPTextField()
        self.registerViews(self.view, forced: false)
        self.addSecureField(numberPad)
        //addSecureField(numberPad)

        // Do any additional setup after loading the view.
    }
    func setupOTPTextField() {
        
        numberPad.otpProtocol = self
        numberPad.otpDelegate = self
        numberPad.otpFontSize = 16
        numberPad.otpTextColor = .white
        numberPad.otpFilledBorderWidth = 0
        numberPad.configure()
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
