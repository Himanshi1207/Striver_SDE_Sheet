#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findpred(Node* root, Node* &pre, int key){
    if(!root)
    return;
    if(root->key<key){
        pre=root;
        findpred(root->right, pre,key);
    }
    else
    findpred(root->left, pre, key);
}
void findsuc(Node* root, Node* &suc, int key){
    if(!root)
    return;
    if(root->key>key){
        suc=root;
        findsuc(root->left, suc, key);
    }
    else
    findsuc(root->right, suc, key);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    findpred(root, pre, key);
    findsuc(root, suc, key);
}

    