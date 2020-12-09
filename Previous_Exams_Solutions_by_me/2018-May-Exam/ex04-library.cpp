#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
mystack<T>::mystack() {
  size=0;
  top=nullptr;
}

//Do not modify
template<class T>
int mystack<T>::getSize() {
  return size;
}

//Do not modify
template<class T>
void mystack<T>::print() {
  if(size==0){
    cout << "The stack is empty.\n";
  }
  else{
    cout << "The stack has size " << size << ":\n";
    Node<T> * current = top;
    while(current!=nullptr){
      cout << "  " <<current->content << "\n";
      current = current->next;
    }
  }
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
mystack<T>::~mystack() {
  Node<T> * current = top;
  eraseR(current);
  current = nullptr;
  size = 0;
  /*
  while(current!=nullptr){
    delete current->content;  //current
    Node<T> * next = current->next;
    current = next;
  }*/
  cout << "Destructor completed\n";
}

template<class T>
void eraseR(Node<T> *p) {
    if (p == nullptr) return;
    eraseR(p->next);
    delete p;
}

//Exercise 4 (b) Implement this function
template<class T>
void mystack<T>::print_top() {
  //Put your code here
  if(top){
    cout << top->content;
  }else{
    cout << "The stack is empty.";
  }
}

//Exercise 4 (b) Implement this function
template<class T>
void mystack<T>::push(T v) {
  //Node<T> * current = top;
  if (top == nullptr) {
      //cout << "empty" << endl;
      top = new Node<T>;
      top->next = nullptr;
      top->content = v;
      size += 1;
      //cout <<"content in empty: ";
      //cout << top->content << endl;
  }
  else {
      //cout << "is it here" << endl;
      Node<T>* temp = new Node<T>;
      temp->content = v;
      temp->next = top;
      top = temp;
      size += 1;
      //cout <<"content is: ";
      //cout << top->content << endl;
  }
}

//Exercise 4 (d) Implement this function
template<class T>
bool mystack<T>::pop() {
  //Put your code here
  if (top == nullptr) {
        return false;
    }
  else {
      Node<T>* temp = top;
      top = top->next;
      delete temp;
      size -= 1;
      return true;
  }
    
}

//Do not modify
template class mystack<int>;