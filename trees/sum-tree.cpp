#include<iostream>
 #include<vector>
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
 class mp
 {
 public:
     bool isst;
     int sum ;
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

 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree. It should return true
 // if the given tree is a Sum Tree, else should return false.
 mp helper(TreeNode * node)
 {
     if(node == NULL)
     {
         mp mypair ;
         mypair.isst = true;
         mypair.sum = 0;
         return mypair;
     }
     if(node->left == NULL && node->right == NULL)
     {
         mp mypair ;
         mypair.isst = true;
         mypair.sum = node->val;
         return mypair;
     }

     mp lp = helper(node->left);
     mp rp = helper(node->right);
     mp ans ;
     ans.sum = lp.sum + rp.sum; + node->val;
     ans.isst = (lp.isst && rp.isst && ((lp.sum + rp.sum )== node->val));
    cout<<ans.isst<<" "<<node->val<<endl;
     return ans;
 }
 bool isSumTree(TreeNode* node) {
     return helper(node).isst;
     // write your code here.

 }

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
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     if(isSumTree(root)){
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }
 }
