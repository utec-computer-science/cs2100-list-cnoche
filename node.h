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
class SNode{
    public:
        T value;
        SNode<T> * next;    
        SNode<T> * prev;
        SNode(void){next = nullptr;}
        SNode(const T& a, const SNode<T> * b, const SNode<T> * c) : value(a), next(b), prev(c) {}
        ~SNode(void){next = nullptr;}
};
#endif