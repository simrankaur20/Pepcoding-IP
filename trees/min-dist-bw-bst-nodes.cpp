#include<iostream>
 #include<vector>
 #include<queue>
 #include<bits/stdc++.h>
 using namespace std;

 // TreeNode class for a node of a Binary Search Tree
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

 class BinaryTree {
     public:
 	 void helper(TreeNode* root , TreeNode* &curr , TreeNode*& prev ,int &dist)
 	 {

       if(!root) return;
       if(root->left != NULL)
        helper(root->left , curr , prev , dist );

       prev = curr;
       curr = root;

       if(prev !=NULL && curr !=NULL && prev !=curr)
         {
             dist = min(dist ,abs( curr->val - prev->val));
         }

       if(root->right!=NULL)
       helper(root->right , curr , prev, dist);

       //return min(x , min(y,x));
    }

     int minDiffInBST(TreeNode* root) {
        TreeNode * p =NULL;
        int dist = INT_MAX;
         helper(root , root , p  , dist);
         //helper(root->right,root->right,root ,dist);
        return dist;
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

     string levelOrder(TreeNode* node) {
 	 	 if(node==NULL){
             return "[]";
         }
         string output="";
 	 	 queue<TreeNode*> q;
 	 	 q.push(node);

 	 	 while (q.size() > 0) {
 	 	 	 TreeNode* curr = q.front();
             q.pop();
             if(curr==NULL){
                 output+="null ";
                 continue;
             }
 	 	     output+=to_string(curr->val)+" ";
             q.push(curr->left);
             q.push(curr->right);
 	 	 }
         return output;
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

 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string input) {
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
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     BinaryTree bt;
     cout<<bt.minDiffInBST(root)<<endl;

 }
