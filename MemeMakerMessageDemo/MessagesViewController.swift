//
//  MessagesViewController.swift
//  MemeMakerMessageDemo
//
//  Created by Brian Bowman on 8/30/16.
//  Copyright © 2016 2020Deception. All rights reserved.
//

import UIKit
import Messages

class MessagesViewController:
    MSMessagesAppViewController,
    UINavigationControllerDelegate,
    UIImagePickerControllerDelegate,
    MM2CaptionViewControllerDelegate,
    UICollectionViewDataSource,
    UICollectionViewDelegate,
    UICollectionViewDelegateFlowLayout {
    
    /// An enumeration that represents an item in the collection view.
    enum CollectionViewItem {
        case sticker(MSSticker)
        case camera
        case library
    }
    
    let padding = CGFloat(1)
    
    var picker: UIImagePickerController!
    var captioner: MM2CaptionViewController!
    var currentController: UIViewController!
    var renderedImage: UIImage!
    var selectionViewController: MM2SelectionCollectionViewController!
    var imageArray: [CollectionViewItem]!
    
    // MARK: View
    
    override func willBecomeActive(with conversation: MSConversation) {
        showCollection()
    }
    
    override func willTransition(to presentationStyle: MSMessagesAppPresentationStyle) {
        super.willTransition(to: presentationStyle)
        setViewFrame(for: presentationStyle)
    }
    
    final private func setViewFrame(for presentationStyle: MSMessagesAppPresentationStyle) {
        
        if currentController == nil {
            return
        }
        
        if currentController == selectionViewController {
            
            currentController.view.frame = view.bounds
            
        } else if presentationStyle == .expanded {
            
            if currentController == picker {
            
                if picker.sourceType == .camera {
                
                    currentController.view.frame = CGRect(x: view.bounds.origin.x, y: view.bounds.origin.y + 85, width: view.bounds.width, height: view.bounds.height - 120)
                
                } else {
                    
                    currentController.view.frame = CGRect(x: view.bounds.origin.x, y: view.bounds.origin.y + 85, width: view.bounds.width, height: view.bounds.height - 80)
                    
                }
                
            } else {
                
                currentController.view.frame = CGRect(x: view.bounds.origin.x, y: view.bounds.origin.y + 85, width: view.bounds.width, height: view.bounds.height - 80)
                
            }
            
        } else {
            
            if currentController == picker {
            
                if picker.sourceType == .camera {
                
                    currentController.view.frame = CGRect(x: view.bounds.origin.x, y: view.bounds.origin.y, width: view.bounds.width, height: view.bounds.height - 40)
                    
                } else {
                    
                    currentController.view.frame = view.bounds
                    
                }
                
            } else {
                
                currentController.view.frame = CGRect(x: view.bounds.origin.x, y: view.bounds.origin.y, width: view.bounds.width, height: view.bounds.height - 50)
                
            }
            
        }
        
    }
    
    final private func populateImageArray() {
        imageArray = [CollectionViewItem]()
        imageArray.insert(.library, at: 0)
        if UIImagePickerController.isCameraDeviceAvailable(.rear) == true || UIImagePickerController.isCameraDeviceAvailable(.front) == true {
            imageArray.insert(.camera, at: 1)
        }
        
        for path in MM2Cache().cacheURLs {
            do {
                let url = URL(fileURLWithPath: path)
                let data = try Data(contentsOf: url)
                
                let image = UIImage(data: data)
                
                if image == nil {
                    continue
                }
                
                let sticker = try MSSticker(contentsOfFileURL: url, localizedDescription: "sticker")
                self.imageArray.insert(.sticker(sticker), at: self.imageArray.count)
            } catch  {
                print("sticker error \(error)")
            }
        }
    }
    
    // MARK: Image Picker Actions
    
    @IBAction func showCollection() {
        populateImageArray()
        selectionViewController = MM2SelectionCollectionViewController(dataSource: self, delegate: self)
        selectionViewController.collectionView?.register(MM2SelectionCollectionViewCell.self, forCellWithReuseIdentifier: "cell")
        selectionViewController.collectionView?.register(MM2HeaderCollectionReusableView.self,
                                                         forSupplementaryViewOfKind:UICollectionElementKindSectionHeader, withReuseIdentifier:"header")
        selectionViewController.collectionView?.backgroundColor = UIColor.white
        presentViewController(controller: selectionViewController, with: presentationStyle)
    }

    @IBAction func showPicker(type: Int) {
        picker = UIImagePickerController()
        picker.sourceType = type == 0 ? .photoLibrary : .camera
        picker.modalPresentationStyle = .currentContext
        picker.delegate = self
        presentViewController(controller: picker, with: .expanded)
    }
    
    // MARK: Image Picker Delegate
    
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        let img = info[UIImagePickerControllerOriginalImage] as! UIImage
        dismiss(animated: true, completion: nil)
        captioner = MM2CaptionViewController(image: img, delegate: self)
        let nav = UINavigationController(rootViewController: captioner)
        presentViewController(controller: nav, with: .expanded)
    }
    
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        showCollection()
    }
    
    // MARK: Caption Controller Delegate
    
    func controller(_ captionViewController: MM2CaptionViewController, didFinishWithCaption caption: String, oldImage: UIImage, memeImage: UIImage) {
        dismiss(animated: true, completion: nil)
    }
    
    func didTriggerCaptionGesture(with image: UIImage) {
        requestPresentationStyle(.expanded)
    }
    
    func didFinishWithTrashCan() {
        showCollection()
    }
    
    func didTriggerShowOptionsGesture(with image: UIImage) {
        renderedImage = image
        insert()
    }
    
    // MARK: Conversation Handling
    
    /*!
     * presentViewController custom presenter of a controller
     */
    final private func presentViewController(controller: UIViewController, with presentationStyle: MSMessagesAppPresentationStyle) {
        requestPresentationStyle(presentationStyle)
        
        currentController = controller
        
        for child in childViewControllers {
            child.willMove(toParentViewController: nil)
            child.view.removeFromSuperview()
            child.removeFromParentViewController()
        }
        
        setViewFrame(for: presentationStyle)
        
        addChildViewController(currentController)
        view.addSubview(currentController.view)
        currentController.didMove(toParentViewController: self)
    }
    
    /*!
     * saves an image, then inserts it into the convo
     */
    final private func insert() {
        requestPresentationStyle(.compact)
        MM2Cache().sticker(from: renderedImage, completionBlock: { (sticker, error) in
            if error != nil {
                print("sticker errror \(error)")
            } else {
                self.imageArray.insert(.sticker(sticker!), at: self.imageArray.count)
                let imageURL = sticker?.imageFileURL
                self.activeConversation?.insertAttachment(imageURL!, withAlternateFilename: "meme", completionHandler: { (error) in
                    print("insert errror \(error)")
                })
            }
        })
    }

    // MARK: Collection View Delegate
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        switch imageArray[indexPath.row] {
        case .sticker(let sticker):
            self.activeConversation?.insert(sticker, completionHandler: { (error) in
                print("insert errror \(error)")
            })
        default:
            self.showPicker(type: indexPath.row)
        }
    }
    
    // MARK: Collection View Data Source
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return imageArray.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        guard let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell", for: indexPath) as? MM2SelectionCollectionViewCell
            else { fatalError("Unable to MM2SelectionCollectionViewCell") }
        switch imageArray[indexPath.row] {
        case .camera:
            let imageView = UIImageView(image: UIImage(named: "camera"))
            imageView.contentMode = .scaleAspectFit
            imageView.isUserInteractionEnabled = true
            MM2Helper.widthHeightEquivalentsConstraints(withSuperView: cell, subview: imageView)
        case .library:
            let imageView = UIImageView(image: UIImage(named: "library"))
            imageView.contentMode = .scaleAspectFit
            imageView.isUserInteractionEnabled = true
            MM2Helper.widthHeightEquivalentsConstraints(withSuperView: cell, subview: imageView)
        case .sticker(let sticker):
            let stickerView = MSStickerView()
            stickerView.sticker = sticker
            MM2Helper.widthHeightEquivalentsConstraints(withSuperView: cell, subview: stickerView)
            cell.backgroundColor = MM2Helper.defaultBackgroundColor()
        }
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
        var reusableView : MM2HeaderCollectionReusableView? = nil
        if kind == UICollectionElementKindSectionHeader {
            let headerView = collectionView.dequeueReusableSupplementaryView(ofKind: kind,
                                                                             withReuseIdentifier: "header",
                                                                             for: indexPath) as! MM2HeaderCollectionReusableView
            reusableView = headerView
        }
        return reusableView!
    }
    
    // MARK: Collection View Layout
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        return CGSize(
            width: collectionView.frame.width / 2 - padding,
            height: collectionView.frame.width / 2 - padding)
    }
    
}


