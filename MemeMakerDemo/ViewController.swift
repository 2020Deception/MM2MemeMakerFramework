//
//  ViewController.swift
//  MemeMakerDemo
//
//  Created by Brian Bowman on 8/30/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

import UIKit

class ViewController:
    UIViewController,
    UINavigationControllerDelegate,
    UIImagePickerControllerDelegate,
    MM2CaptionViewControllerDelegate
{
    
    var picker: UIImagePickerController!
    var captioner: MM2CaptionViewController!
    var navController: UINavigationController!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let button = UIButton(frame: CGRect(x: 0, y: 0, width: 90, height: 30))
        button.center = view.center
        button.setTitle("start", for: .normal)
        button.titleLabel?.font = MM2Helper.defaultFont(ofSize: 48)
        button.setTitleColor(UIColor.black, for: .normal)
        view.addSubview(button)
        button.addTarget(self, action: #selector(ViewController.showPicker), for: .touchUpInside)
    }
    
    @IBAction func showPicker() {
        picker = UIImagePickerController()
        picker.sourceType = .photoLibrary
        picker.modalPresentationStyle = .currentContext
        picker.delegate = self
        present(picker, animated: false, completion: nil)
    }
    
    func imagePickerController(_ picker: UIImagePickerController,
                               didFinishPickingMediaWithInfo info: [String : Any]) {
        let img = info[UIImagePickerControllerOriginalImage] as! UIImage
        dismiss(animated: true, completion: nil)
        captioner = MM2CaptionViewController(image: img, delegate: self)
        navController = UINavigationController(rootViewController: captioner)
        present(navController, animated: true, completion: nil)
    }

    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        dismiss(animated: true, completion: nil)
    }
    
    func controller(_ captionViewController: MM2CaptionViewController,
                    didFinishWithCaption caption: String,
                    oldImage: UIImage,
                    memeImage: UIImage) {
        print(caption)
    }
    
    func didFinishWithTrashCan() {
        dismiss(animated: true, completion: nil)
    }

}

