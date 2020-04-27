#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T>
class Node{
    public:
        T value;
        Node<T> * next;    
        Node(void){next = nullptr;}
        Node(const T& a, const Node<T> * b){value = a; next = b;}
        ~Node(void){next = nullptr;}
};

template <typename T>
class DNode{
    public:
        T value;
        DNode<T> * next;    
        DNode<T> * prev;
        DNode(void){next = nullptr;}
        DNode(const T& a, const DNode<T> * b, const DNode<T> * c) : value(a), next(b), prev(c) {}
        ~DNode(void){next = nullptr;}
};
#endif