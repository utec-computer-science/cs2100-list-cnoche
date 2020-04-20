#ifndef LIST_S_LIST_HPP
#define LIST_S_LIST_HPP

#include "node.h"
#include <ostream>
#include "iterator.hpp"
template <typename T>
class SList {
    protected:
        SNode<T> *head;
        SNode<T> *tail;
        typedef SNode<T> Node;
    public:
        int len;
        typedef iterator<T> iterator;
        SList(const SList<T> &SList){head=SList.head; tail=SList.tail; len = SList.len;}
        
        SList(T* arr, int size){
          for (int i = size; i != -1; i--)
          {
            push_front(arr[i]);
          }
        }

        SList(Node * node){ 
          push_front(node->value);
        }

        SList(int n){ 
			//Constructor por parametro, 
			//retorna un SLista de randoms de tamaño n
        }

        SList(void){head=nullptr; len=0;}

        ~SList(void){
          if (!isEmpty()){pop_front();}
        }

        // Retorna una referencia al primer elemento
        T front()
        {
          return head->value;
        }
          
        // Retorna una referencia al ultimo elemento
        T back(void)
        {
          return tail->value;
        } 

        // Inserta un elemento al final
        void push_back(const T& element)
        {
          Node * new_node = new Node{element, nullptr};
          if (head == nullptr)
          {
            head = new_node;
            tail = new_node;
          } else
          {
            tail->next = new_node;
            tail = new_node;
            len++;
          }
          
        } 

      // Inserta un elemento al inicio
        void push_front(const T& element)
        {
          Node * new_node = new Node{element, nullptr};
          if (head == nullptr)
          {
            head = new_node;
            tail = new_node;
          } else
          {
            new_node->next = head;
            head = new_node;
            len++;
          }
          
        }
      // Quita el ultimo elemento y retorna una referencia
        Node * pop_back(void)
        {
          if (head != nullptr)
          {
            Node * iter = head;
            while (iter->next != tail)
            {
              iter= iter->next;
            }
            iter->next = nullptr;
            delete tail;
            tail = iter;
            return tail;
            len--;
          }
        }

        // Quita el primer elemento y retorna una referencia
        Node * pop_front(void)
        {
          if (head != nullptr)
          {
            Node * iter = head;
            head = iter->next;
            iter->next = nullptr;

            delete iter;
            return head;
            len--;
          }
        }
        
      // la SLista esta vacia?
        bool isEmpty(void)
        {
          return head==nullptr;
        }

        T& operator[] (const int& pos){
        Node * iter = head;
        if(iter != nullptr){
          for (int i = 0; i < pos ; ++i) {
          iter = iter->next;
          }
          return iter->value;
        }
      } 
    // retorna el tamaño de la SLista
      unsigned int size(void){
        return len;
      }

    // Elimina toda la SLista
      void clear(void)
      {
        if (!isEmpty)
        {
          pop_front();
        }
      } 

    // Elimina un elemento en base a un puntero
      void erase(Node * node)
      {
        Node * iter = head;
        while (iter != nullptr && iter->next != node){
          iter=iter->next;
        }
        if (iter == nullptr)
        {
          return;
        }
        if (iter == head)
        {
          pop_front();
        } else if (iter == tail){
          pop_back();
        } else
        {
          Node * next_node = iter->next->next;
          delete iter->next;
          iter->next = next_node;
        }
      }


		  // Inserta un elemento  en base a un puntero
        void insert(Node * node, const T& element)
        {
          if (head == nullptr)
          {
            Node * new_node = new Node{element, nullptr};
            head = new_node;
          } else {
            Node * new_node = new Node{element, nullptr};
            Node * iter = head;
            while (iter != nullptr && iter->next != node)
            {
              iter=iter->next;
            }
            if (iter == nullptr)
            {
              return;
            } else {
              iter->next = new_node;
              new_node->next = iter->next->next;
            }
          }

        } 

		  // Elimina todos los elementos por similitud
        void remove(const T& element)
        {
          Node * iter = head;
          while (iter != nullptr && iter->next->value != element){
            iter=iter->next;
          }
          if (iter == head)
          {
            pop_front();
          }
          else if (iter == tail){
            pop_back();
          } 
          else
          {
            Node * next_node = iter->next->next;
            delete iter->next;
            iter->next = next_node;
          }
        }

		  // ordena la SLista
        SList& sort(void); 

		  // invierte la SLista
        SList& reverse(void); 

		  // Imprime la SLista con cout
        template<typename __T>
        inline friend std::ostream& operator<<
			  (std::ostream& os , const SList<__T>& SList){
          Node * iter = SList.head;
          while (iter != nullptr)
          {
            os << iter->value << " "; iter = iter->next;
          }
          std::cout << "\n";
          return os;
        }
};
#endif