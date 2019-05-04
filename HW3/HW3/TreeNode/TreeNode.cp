//
//  TreeNode.cpp
//  HW3
//
//  Created by Joshua Choi on 4/24/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#include "TreeNode.hpp"

/// MARK: - Init
/// \param data An Int value representing the TreeNode's 'data' value.
TreeNode::TreeNode(int data) {
    // Update the left and right nodes
    left = right = NULL;
    // Set the value
    this->value = data;
}

/// Adds a node to the binary tree.
/// \param root A TreeNode pointer object to add values to the tree to.
/// \param data An Int value representing the value to add to the tree.
TreeNode* add(TreeNode* root, int data) {
    if (root == NULL) {
        TreeNode* res = new TreeNode(data);
        return res;
    }
    
    if (root->maxDepth(root->left) > root->maxDepth(root->right)) {
        root->right = add(root->right, data);
    } else {
        root->left = add(root->left, data);
    }
    
    return root;
}


/// Determines if
/// - \param root A TreeNode pointer.
int TreeNode::maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}



/// Calculates the sum of the binary tree at each hierarchy/
/// \param root A TreeNode pointer.
int TreeNode::getSum(TreeNode* root) {
    int sum = 0;
    int currentValue = 0;
    
    if (!root) {
        return 0;
    }
    
//    currentValue = currentValue * 10 + root->value;
//    
//    if (!root->left && !root->right) {
//        sum += currentValue;
//    }
//    
//    if (root->left) {
//        getSum(root->left);
//    }
//    
//    if (root->right) {
//        getSum(root->right);
//    }
    
    return 0;
}
