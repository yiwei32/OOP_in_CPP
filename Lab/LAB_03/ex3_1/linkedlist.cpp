#include <iostream>
#include "linkedlist.h"


void List::InsertNode(int val){
    Node* dummy = new Node(0, head);
    Node* prev = dummy;
    Node* cur = this->head;
    
    while (cur != NULL){
        prev = cur;
        cur = cur->next; 
    }
    Node* newNode = new Node(val);
    prev->next = newNode;
    head = dummy->next;
    this->len += 1;
};
bool List::DeleteNode(int val){
    if (this->len == 0) return false;
    Node* dummy = new Node(0, head);
    Node* cur = head;
    Node* prev = dummy;
    while (cur != NULL && cur->val != val){
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) return false;
    prev->next = cur->next;
    delete cur;
    this->len -= 1;
    this->head = dummy->next;
    return true;
};
void List::Display(){
    Node* cur = head;
    while (cur){
        std::cout << cur->val << "->";
        cur = cur->next;
    }
    std::cout << "NULL" << std::endl;
};


class Node{
public:
    int val;
    Node* next;
};

void deleteN(Node* head, int key){
    
    Node* dummy(0);
    dummy->next = head;
    Node* cur = head;
    Node* prev = dummy;
    while (cur && cur->val != key){
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) return;
    prev->next = cur->next;
    delete cur;
    head = dummy->next;
}