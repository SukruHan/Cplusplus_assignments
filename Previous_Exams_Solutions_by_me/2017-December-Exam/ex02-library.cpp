#include "ex02-library.h"
#include <iostream>

//Do not modify
void printSet(set<string> s){
  if(s.size()==0){
    cout << " No nodes\n";
  }
  else{
    set<string>::iterator it;
    for (it=s.begin(); it!=s.end(); ++it){
      cout << ' ' << *it << "\n";
    }
  }
  cout << "\n";
}

//Exercise 2 (a) Check and correct if necessary
void computeParentNodes(Node *n, set<string> & parents){
  if(n->left != nullptr && n->right != nullptr){
    parents.insert(n->name);
    computeParentNodes(n->left,parents);
    computeParentNodes(n->right,parents);
  }
  else if (n->left == nullptr && n->right != nullptr){
    parents.insert(n->name);
    computeParentNodes(n->right, parents);
  }
  else if(n->left != nullptr && n->right == nullptr){
    parents.insert(n->name);
    computeParentNodes(n->left, parents);
  }/*
  else{
  }*/
}

//Exercise 2 (b) Implement this function
void computeMembersOfSubTree(Node * n, set<string> & members){
  //Put your code here
  if(n->left != nullptr && n->right != nullptr){
    members.insert(n->name);
    computeMembersOfSubTree(n->left,members);
    computeMembersOfSubTree(n->right,members);
  }
  else if (n->left == nullptr && n->right != nullptr){
    members.insert(n->name);
    computeMembersOfSubTree(n->right, members);
  }
  else if(n->left != nullptr && n->right == nullptr){
    members.insert(n->name);
    computeMembersOfSubTree(n->left, members);
  } 
  else{
    members.insert(n->name);
  }
}
