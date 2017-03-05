/*
https://leetcode.com/problems/minimum-depth-of-binary-tree

Problem:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minimum(int x, int y) {
        return (x > y) ? y : x;
    }
    
    int maximum(int x, int y) {
        return (x > y) ? x : y;
    }
    
    int minDepthRecursive(TreeNode* root, int currentDepth = 0) {
        if(root == NULL)
            return currentDepth;
            
        if (root->left == NULL || root->right == NULL) {
            //If there is only one subtree (or no subtree)
            //Then only that subtree will be considered in the depth
            //This of BST with all children in the left side. Depth != 0 in that case.
            return maximum(minDepthRecursive(root->left, currentDepth+1), minDepthRecursive(root->right, currentDepth+1));
        } else {
            return minimum(minDepthRecursive(root->left, currentDepth+1), minDepthRecursive(root->right, currentDepth+1));
        }
    }
    
    int minDepth(TreeNode* root) {
        return minDepthRecursive(root);
    }
};