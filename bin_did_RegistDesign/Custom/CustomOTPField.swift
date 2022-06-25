//
//  CustomOTPField.swift
//  ezHION
//
//  Created by 이순빈 on 2021/09/30.
//

import UIKit

public protocol CustomOTPFieldDelegate: AnyObject {
    func didUserFinishEnter(the code: String)
    
    
}

public protocol CustomOTPFieldProtocol: AnyObject {
    func valueUpdated(sender: Any, value: String)
}

class CustomOTPField: UITextField {
    
    public var maxLength: Int?
    var value: String = "" {
        willSet(newValue) {
            _ = maxLength ?? value.count
            _ = maxLength ?? newValue.count
        }
    }
    
    
    public var otpDefaultCharacter = ""
    public var otpBackgroundColor: UIColor = #colorLiteral(red: 0.8, green: 0.8, blue: 0.8, alpha: 1)
    public var otpFilledBackgroundColor: UIColor = #colorLiteral(red: 0.4039215686, green: 0.2156862745, blue: 1, alpha: 1)
    public var otpDefaultBorderColor: UIColor = .blue
    public var otpFilledBorderColor: UIColor = #colorLiteral(red: 0.1960784346, green: 0.3411764801, blue: 0.1019607857, alpha: 1)
    public var otpDefaultBorderWidth: CGFloat = 0
    public var otpFilledBorderWidth: CGFloat = 1
    public var otpTextColor: UIColor = .black
    public var otpFontSize: CGFloat = 14
    public weak var otpDelegate: CustomOTPFieldDelegate?
    public weak var otpProtocol: CustomOTPFieldProtocol?
    public var otpFont: UIFont = UIFont.systemFont(ofSize: 14)
    
    private var isConfigured = false
    private var digitLabels = [UILabel]()
    private lazy var tapRecognizer: UITapGestureRecognizer = {
        let recognizer = UITapGestureRecognizer()
        recognizer.addTarget(self, action: #selector(becomeFirstResponder))
        return recognizer
    }()
    
    public func configure(with slotCount: Int = 6) {
        guard isConfigured == false else { return }
        isConfigured.toggle()
        configureTextField()
        
        let labelsStackView = createLabelsStackView(with: slotCount)
        addSubview(labelsStackView)
        addGestureRecognizer(tapRecognizer)
        NSLayoutConstraint.activate([
            labelsStackView.topAnchor.constraint(equalTo: topAnchor),
            labelsStackView.leadingAnchor.constraint(equalTo: leadingAnchor),
            labelsStackView.trailingAnchor.constraint(equalTo: trailingAnchor),
            labelsStackView.bottomAnchor.constraint(equalTo: bottomAnchor)
        ])
    }
    
    private func configureTextField() {
        tintColor = .clear
        textColor = .clear
        keyboardType = .numberPad
        textContentType = .oneTimeCode
        borderStyle = .none
        addTarget(self, action: #selector(textDidChange), for: .editingChanged)
    }
    
    private func createLabelsStackView(with count: Int) -> UIStackView {
        let stackView = UIStackView()
        stackView.translatesAutoresizingMaskIntoConstraints = false
        stackView.axis = .horizontal
        stackView.alignment = .fill
        stackView.distribution = .fillEqually
        stackView.spacing = 8.44
        for _ in 1 ... count {
            let label = createLabel()
            stackView.addArrangedSubview(label)
            digitLabels.append(label)
        }
        return stackView
    }
    
    private func createLabel() -> UILabel {
        let label = UILabel()
        label.backgroundColor = otpBackgroundColor
        //label.layer.cornerRadius = otpCornerRaduis
        label.layer.cornerRadius = self.frame.height / 2.133
        label.translatesAutoresizingMaskIntoConstraints = false
        label.textAlignment = .center
        label.textColor = otpTextColor
        label.font = label.font.withSize(otpFontSize)
        label.font = otpFont
        label.isUserInteractionEnabled = true
        label.layer.masksToBounds = true
        label.text = otpDefaultCharacter
        return label
    }
    private func deleteData() {
        self.text = ""
        self.text?.removeAll()
    }
    
    @objc
    private func textDidChange() {
        otpProtocol?.valueUpdated(sender: self, value: self.text!)
        DispatchQueue.main.async { [self] in
            guard let text = self.text, text.count <= digitLabels.count else { return }
            
            for labelIndex in 0 ..< digitLabels.count {
                let currentLabel = digitLabels[labelIndex]
                if labelIndex < text.count {
                    let index = text.index(text.startIndex, offsetBy: labelIndex)
                                        //urrentLabel.text = String(text[index])
                    //currentLabel.text = String(text[index])
                    currentLabel.layer.borderWidth = otpFilledBorderWidth
                    currentLabel.layer.borderColor = otpFilledBorderColor.cgColor
                    
                    currentLabel.backgroundColor = otpFilledBackgroundColor
                } else {
                    currentLabel.text = otpDefaultCharacter
                    currentLabel.layer.borderWidth = otpDefaultBorderWidth
                    currentLabel.layer.borderColor = otpDefaultBorderColor.cgColor
                    currentLabel.backgroundColor = otpBackgroundColor
                }
            }
            if text.count == digitLabels.count  {
                //print("렌지")
                if UserDefaults.standard.string(forKey: "USER_VERIFY_PIN_PASSWORD") != nil {
                    print("등록된 사용자")
                }
                //self.text = ""
                //self.text?.removeAll()
                //self.offset(from: self.beginningOfDocument, to: beginningOfDocument)
                otpDelegate?.didUserFinishEnter(the: text)
                //text.index
                //text.index(text.startIndex, offsetBy: 0)
                for x in 0...5{
                    digitLabels[x].layer.borderColor = otpDefaultBorderColor.cgColor
                    digitLabels[x].backgroundColor = otpBackgroundColor
                }
            }
        }
    }
}

