#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class List{
    friend class Node;
    class Node{
    public:
        int val;
        Node* next;
        Node(int val, Node* next=NULL):val(val), next(next){};
    };
    Node* head;
    int len;
public:
    List(Node* head=NULL, int len=0):head(head), len(len){};
    void InsertNode(int val);
    bool DeleteNode(int val);
    void Display();
};
#endif