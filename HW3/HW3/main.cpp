//
//  TreeNode.hpp
//  HW3
//
//  Created by Joshua Choi on 4/24/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include "TreeNode/TreeNode.hpp"
using namespace std;

// MARK: - Class Methods
void levelOrderTraversal(TreeNode* root);
void inorderTraversal(TreeNode* root);
int sumRootToLeaf(TreeNode* root, int currentValue);
TreeNode* constructBalancedBinarySearchTree(int array[], int first, int last);
TreeNode* insertNodeToBinarySearchTree(TreeNode* root, TreeNode* node);
// MARK: - Kth Smallest Element
int kthsmallest(TreeNode* root, int k);
void inorderTraversalForKthElement(TreeNode* root, int& smallest, int k, int& it);


// MARK: - Main
int main() {
    
    /**
     1. Given a non-empty binary tree, return the sum value of the nodes on each level in the form of a vector in C++.
     Given binary tree [3, 9, 20, NULL, NULL, 15, 7], return [3, 29, 22]
     */
    
    cout << "Given: \n";
    cout << "   3   \n";
    cout << "  / \\   \n";
    cout << " 9   20   \n";
    cout << "     / \\  \n";
    cout << "   15   7   \n\n";
    
    // MARK: - TreeNode
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    // Traverse through the binary tree in level order.
    cout << "* Level-Order Traversal: ";
    levelOrderTraversal(root);
    
    /**
     2. Given a binary tree, return the inorder traversal of its nodes’ values using stack.
     For example:
     Given binary tree below, return [9,3,15,20,7]
     3
     / \
     9 20
        / \
        15 7
     */
    cout << "* Inorder Traversal: ";
    inorderTraversal(root);
    
    
    /**
     3. Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number. Find the total sum of all root-to-leaf numbers (Note: You just need to return the total sum, not the path) For example:
         6
        / \
       3   5
      / \   \
     2   5   4
        / \
       7   4
     */
    
    cout << "Given: \n";
    cout << "     6\n";
    cout << "    / \\\n";
    cout << "   3    5\n";
    cout << "  / \\    \\\n";
    cout << " 2   5    4\n";
    cout << "    / \\\n";
    cout << "   7    4\n";
    
    // MARK: - TreeNode
    TreeNode* root2 = new TreeNode(6);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(5);
    root2->left->right->left = new TreeNode(7);
    root2->left->right->right = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->right->right = new TreeNode(4);
    cout << "Sum of all root-to-leaf paths: " << sumRootToLeaf(root2, 0);
    
    /**
     4. Given sorted array, write a C++ function that converts this sorted array into a balanced binary search tree. For example, input [2,3,4], returns
      3
     / \
     2 4
     */
    
    /// Initialized Int array used to sort into a balanced binary search tree
    int sortedArray[3] = {
        1,
        2,
        3
    };
    
    // MARK: - TreeNode
    TreeNode* node = constructBalancedBinarySearchTree(sortedArray, 0, 2);
    cout << "* Sorted array into balanced binary search tree: ";
    levelOrderTraversal(node);
    cout << endl;
    
    
    /**
     5. Given a Binary Search Tree (BST), write a C++ function to find the kth smallest element in it. You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
     For example, Given binary tree below with k = 2, return 3
        4
       / \
      3   6
     /
    2
     */
    // MARK: - TreeNode
    TreeNode* bst = new TreeNode(4);
    insertNodeToBinarySearchTree(bst, new TreeNode(3));
    insertNodeToBinarySearchTree(bst, new TreeNode(6));
    insertNodeToBinarySearchTree(bst, new TreeNode(2));
    levelOrderTraversal(bst);
    cout << "* Finding kth smallest element in binary search tree: ";
    levelOrderTraversal(bst);
    cout << "- kth smalles element: " << kthsmallest(bst, 2) << endl << endl << endl;
    
    
    return 0;
}


/// Traverse through the binary tree in level order (lhs -> rhs per each level of binary tree) using a queue (FIFO).
/// @param root A TreeNode object representing the root of the binary tree
void levelOrderTraversal(TreeNode* root) {
    
    /**
     Logic:
     1. Determine if the root exists. IF not, exit this method.
     2. Initialize a Queue of the nodes in the binary tree.
     3. Traverse through the binary tree from the bottom-up.
     */
    
    if (root == NULL) {
        return;
    } else {
        // MARK: - Queue<TreeNode>
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        cout << "[";
        
        // Execute continuously
        while (1) {
            /// Initialized Int indicating the number of nodes at the current level of the binary tree. We start from the bottom-up
            int count = nodeQueue.size();
            
            // Exit if the count is currently 0
            if (count == 0) {
                break;
            }
            
            /**
             Here, we dequeue all nodes at the current level and enqueue all nodes of the next level
             */
            while (count > 0) {
                // MARK: - TreeNode
                TreeNode* node = nodeQueue.front();
                cout << node->value << ",";
                nodeQueue.pop();
                
                // Append the lhs node to the queue if its lhs is NULL
                if (node->left != NULL) {
                    nodeQueue.push(node->left);
                }
                
                // Append the rhs node to the queue if its rhs is NULL
                if (node->right != NULL) {
                    nodeQueue.push(node->right);
                }
                
                // Decrement the count
                count -= 1;
            }
        }
        
        cout << "]\n";
    }
}

/// Traverse through the binary tree in inorder (visit lhs, then root, then rhs) using a stack (LIFO).
/// @param root A TreeNode object representing the root of the binary tree
void inorderTraversal(TreeNode* root) {

    // MARK: - Stack<TreeNode>
    stack<TreeNode*> nodeStack;
    
    // MARK: - TreeNode
    TreeNode* currentNode = root;
    
    while (!nodeStack.empty() || currentNode) {
        // Append the current node to the stack - then update the current node to the lhs node
        if (currentNode) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            // Update the current node with the top of the stack — then remove it
            currentNode = nodeStack.top();
            nodeStack.pop();
            
            // Log the value of the current node and update it to the rhs (indicates we've finished traversing a
            cout << currentNode->value << " ";
            currentNode = currentNode->right;
        }
    }
}

/// Returns the sum of the binary tree by traversing through its root-to-leaf paths and extracting its values.
/// @param root A TreeNode object representing the root of the binary tree
/// @param currentValue An Int value representing the current value of the combination/sum of numbers in the current binary tree's path
int sumRootToLeaf(TreeNode* root, int currentValue) {
    
    // Empty binary tree
    if (root == NULL) {
        return 0;
    } else {

        // Update the current value
        currentValue = (currentValue * 10 + root->value);
        
        // If the current node is leaf, return the current value of val
        if (root->left == NULL && root->right == NULL) {
            return currentValue;
        }
        
        // Recursively get the sum of the values for the lhs and rhs sub trees
        return sumRootToLeaf(root->left, currentValue) + sumRootToLeaf(root->right, currentValue);
    }
    
}

/// Constructs a balanced binary tree — meaning all values to the lhs are less than its root while all values to the rhs are greater than its root
/// @param array A sorted Int array
/// @param first An Int value representing the first index in the sorted array
/// @param last An Int value representing the last index in the sorted array
TreeNode* constructBalancedBinarySearchTree(int array[], int first, int last) {
    /**
     Logic:
     1. Get the middle of the array and make it root.
     2. Recursively do same for left half and right half.
        a) Get the middle of left half and make it left child of the root created in step 1.
        b) Get the middle of right half and make it right child of the root created in step 1.
     */
    
    // Array is not sorted
    if (first > last) {
        return NULL;
    }
    
    // Get the midpoint
    int median = (first + last)/2;
    
    // MARK: - TreeNode
    TreeNode *root = new TreeNode(array[median]);
    
    // Recursively construct the left subtree and make it left child of root
    root->left = constructBalancedBinarySearchTree(array, first, median - 1);
    
    // Recursively construct the right subtree and make it right child of root
    root->right = constructBalancedBinarySearchTree(array, median + 1, last);

    return root;
}

// Recursive function to insert a new node to the binary search tree
/// @param root A TreeNode object representing the root of the binary tree
/// @param node A new TreeNode object to add to the binary tree's lhs or rhs
TreeNode* insertNodeToBinarySearchTree(TreeNode* root, TreeNode* node) {
    // Return the root
    if (root == NULL) {
        return (node != NULL ? node : new TreeNode(0));
    }

    // If the new node's value is less than the current root's value
    if (node->value < root->value) {
        /// Insert to the left
        root->left = insertNodeToBinarySearchTree(root->left, node);
    } else {
        /// Insert to the right
        root->right = insertNodeToBinarySearchTree(root->right, node);
    }
    
    return root;
}

/**
 Getting the kth smallest element in a binary search tree requires a reverse inorder.
 - In a BST, the left subtree of node T contains only elements smaller than the value stored in T. If k is smaller than the number of elements in the left subtree, the kth smallest element must belong to the left subtree. Otherwise, if k is larger, then the kth smallest element is in the right subtree.
 - We can augment the BST to have each node in it store the number of elements in its left subtree (assume that the left subtree of a given node includes that node). With this piece of information, it is simple to traverse the tree by repeatedly asking for the number of elements in the left subtree, to decide whether to do recurse into the left or right subtree.
 @param root A TreeNode object representing the root of a binary tree.
 @param k An Int value represneting the kth element.
 */
int kthsmallest(TreeNode* root, int k) {
    int smallest = -1;
    int it = 0;
    inorderTraversalForKthElement(root, smallest, k, it);
    return smallest;
}

//// MARK: - Helper Method
void inorderTraversalForKthElement(TreeNode* root, int& smallest, int k, int& it) {
    if (!root) {
        return;
    }
    inorderTraversalForKthElement(root->left, smallest, k, it);
    ++it;
    if (it == k) {
        smallest = root->value;
        return;
    }
    inorderTraversalForKthElement(root->right, smallest, k, it);
}
