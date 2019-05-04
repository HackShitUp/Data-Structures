//
//  TreeNode.hpp
//  HW3
//
//  Created by Joshua Choi on 4/24/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>
#include "../TreeNode/TreeNode.hpp"
using namespace std;

/**
 Abstract: A binary tree
 */
class TreeNode {
public:
    // MARK: - Class Vars
    /// Initialized Int value used representing the value of the node in the Tree
    int value;
    // MARK: - TreeNode
    TreeNode* left;
    // MARK: - TreeNode
    TreeNode* right;
    
    // MARK: - Class Methods
    int heightHelper(TreeNode* root);
    int height(TreeNode* root);
    int treeSize(TreeNode* root);
    
    /// MARK: - Init
    /// \param data An Int value representing the TreeNode's value.
    TreeNode(int data);
};

#endif /* TreeNode_hpp */
