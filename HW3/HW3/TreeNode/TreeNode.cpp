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
    // Set the value
    this->value = data;
    
    // Update the left and right Nodes with NULL values
    left = right = NULL;
}

/// Get the height of the binary tree — the number of nodes/edges at each level of the binary tree.
/// @param root A TreeNode object representing the root of the binary tree.
int TreeNode::height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }
}

/// Recursively calculate the height of the binary tree by determining which of the lhs and the rhs of the tree is greater
/// @param root A TreeNode object representing the root of the binary tree.
int TreeNode::heightHelper(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        // Return the sum of 1 and the greater lhs or rhs of the node
        return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }
}

/// Get the size of the binary tree - the number of nodes in the binary tree.
/// @param root A TreeNode object representing the root of the binary tree.
int TreeNode::treeSize(TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + treeSize(root->left) + treeSize(root->right);
    }
}
