#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class TreeNode {
     public:
 	 int val;
 	 TreeNode* left;
 	 TreeNode* right;

 	 TreeNode(int x) {
 	 	 val = x;
         left = NULL;
         right = NULL;
 	 }
 };

 // utility function to display a binary tree
 void display(TreeNode* node) {
     if (node == NULL) {
         return;
     }
     string str = "";

     str += node->left == NULL ? "." : to_string(node->left->val);
     str += " <= " + to_string(node->val) + " => ";
     str += node->right == NULL ? "." : to_string(node->right->val);

     cout<<str<<endl;

     display(node->left);
     display(node->right);
 }

 class BinaryTree {
     public:

     bool helper(TreeNode * root , bool & f)
     {
         if(!root)
            return false;
        if(!root->left && !root->right)
            return true;

       bool x = f && helper(root->left,f);
       bool y = f && helper(root->right,f);
       bool r = true;
       if(root->left)
       {
           r = (root->val > root->left ->val);
       }
       if(root->right)
       {
           r = r && (root->val > root->right ->val);
       }
       f = f && x && y && r;
        return f;
     }
 	 bool isHeap(TreeNode* tree) {
 	 	 bool f = 1;
 	 	 f = helper(tree , f);
 	 	 return f;

 	 }

     string levelOrder(TreeNode* node) {
 	 	 if(node == NULL){
             return "[]";
         }
         string output = "";
 	 	 queue<TreeNode*> nodeQueue;
 	 	 nodeQueue.push(node);
 	 	 while (nodeQueue.size() > 0) {
 	 	 	 TreeNode* node = nodeQueue.front();
             nodeQueue.pop();

 	 	 	 if (node == NULL) {
 	 	 	 	 output += "null ";
 	 	 	 	 continue;
 	 	 	 }

 	 	 	 output += to_string(node->val) + " ";
 	 	 	 nodeQueue.push(node->left);
 	 	 	 nodeQueue.push(node->right);
 	 	 }
 	 	 return output;
 	 }

 	 // Don't make any changes here
 	 void inOrder(TreeNode* node) {
 	 	 if (node == NULL) {
 	 	 	 return;
 	 	 }

 	 	 inOrder(node->left);
 	 	 cout<<node->val<<" ";
 	 	 inOrder(node->right);
 	 }

     void printPostorder(TreeNode* node) {
 	 	 if (node == NULL)
 	 	 	 return;

 	 	 printPostorder(node->left);
 	 	 printPostorder(node->right);
 	 	 cout<<node->val<<" ";
 	 }

 	 void printPreorder(TreeNode* node) {
 	 	 if (node == NULL)
 	 	 	 return;

 	 	 cout<<node->val<<" ";
 	 	 printPostorder(node->left);
 	 	 printPostorder(node->right);
 	 }

 };

 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string &input) {
     int first = input.find_first_not_of(' ');
     int last = input.find_last_not_of(' ');
     input = input.substr(first, (last - first + 1));
     if (!input.size()) {
         return nullptr;
     }

     string item;
     stringstream ss;
     ss.str(input);

     getline(ss, item, ' ');
     TreeNode* root = new TreeNode(stoi(item));
     queue<TreeNode*> nodeQueue;
     nodeQueue.push(root);

     while (true) {
         TreeNode* node = nodeQueue.front();
         nodeQueue.pop();
         if (!getline(ss, item, ' ')) {
             break;
         }

         if (item != "null") {
             int leftNumber = stoi(item);
             node->left = new TreeNode(leftNumber);
             nodeQueue.push(node->left);
         }

         if (!getline(ss, item, ' ')) {
             break;
         }

         if (item != "null") {
             int rightNumber = stoi(item);
             node->right = new TreeNode(rightNumber);
             nodeQueue.push(node->right);

         }
     }
     return root;
 }

 int main(int argc, char** argv){
     string str;
     getline(cin, str);
     TreeNode* root = stringToTreeNode(str);
     BinaryTree bt;
     if(bt.isHeap(root)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }
