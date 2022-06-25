//
//  RegistPin1ViewController.swift
//  ezDIDHolder_RegistDesign
//
//  Created by 이순빈 on 2021/09/08.
//

import UIKit

class RegistPin1ViewController: UIViewController, NumberPadViewProtocol {
    func valueUpdated(sender: Any, value: String) {
        
    }
    
    @IBOutlet var numPadView: NumberPadView!

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        numPadView.delegate = self
        numPadView.maxLength = 6
        numPadView.font = UIFont.systemFont(ofSize: 20)
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
