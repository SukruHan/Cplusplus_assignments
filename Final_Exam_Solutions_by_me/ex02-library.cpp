#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    // Write your code here
    unsigned int len = 0;
    if(list == nullptr) {
        return len;
    }
    while(list != nullptr) {
        len += list->times;
        list = list->next;
    }
    return len;
}
// Task 2(b).  Implement this function

Elem* append(Elem *list, int v){
  if (list == nullptr) {
        list = new Elem();
        list->value = v;
        list->times = 1;
        list->next = nullptr;
        return list;
    }
    if (length(list) == 0) {
        list->value = v;
        list->times = 1;
        list->next = nullptr;
        return list;
    }

    Elem *result = new Elem();
    result = list;

    while (result != nullptr) {
        if (result->value == v) {
            result->times += 1;
            return list;
        }
        if (result->next == nullptr) {
            Elem* last = new Elem();
            last->value = v;
            last->times = 1;
            last->next = nullptr;
            result->next = last;
            return list;
        }
        result = result->next;
    }
    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    // Write your code here
    Elem *result = new Elem();
    for (int i=0; i<n; i++) {
        result = append(result, data[i]);
    }
    return result;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
