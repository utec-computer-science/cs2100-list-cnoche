#include<iostream>
using namespace std;
//-----------------------------Nodes----------------------------------------------------
template <typename T>
class Node {
    public: 
        typedef T value_t;
        typedef unsigned int size_t;

    public:
        value_t value;

    public:
        Node(const value_t& _value):value(_value){
        }

        size_t size(){
          return 0;
        }

        ~Node(void){
        }

        value_t& operator*(void){
            return value;
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
            _out << "Nodo: " <<  _node.value;
            return _out;
        }
};
//------------------------------Singly Node----------------------------------------------
template <typename T>
class ForwardListNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        ForwardListNode<T>* next;

    public:
        ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~ForwardListNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
            _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
            return _out;
        }
};
//------------------------------------------Doubly Node--------------------------------------
template <typename T>
class DoubleListNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        DoubleListNode<T>* next;
        DoubleListNode<T>* prev;

    public:
        DoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~DoubleListNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const DoubleListNode<_T>& _node){
            _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
            return _out;
        }
};
//------------------------------------------Circular Node------------------------------------
template <typename T>
class CircularNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        CircularNode<T>* next;

    public:
        CircularNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~CircularNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const CircularNode<_T>& _node){
            _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
            return _out;
        }
};

//-------------------------------------Circular Double Node---------------------------------
template <typename T>
class CircularDoubleNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        CircularDoubleNode<T>* next;
        CircularDoubleNode<T>* prev;

    public:
        CircularDoubleNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~CircularDoubleNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const CircularDoubleNode<_T>& _node){
            _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
            return _out;
        }
};

//----------------------------------Iterator--------------------------------------------
template <typename Node>
class Iterator{
    public:
        typedef Node node_t;
        typedef typename node_t::value_t value_t;

    protected:
        node_t * pointer; 
        public: 

        Iterator(node_t* _pointer = nullptr):pointer(_pointer){
        }

        ~Iterator(void){
        }

        virtual bool operator!= (Iterator it){
            return pointer != it.pointer;
        }

        virtual value_t& operator* (void) {
            return **pointer;
        }
    };


//--------------------------node traits---------------------
#define DEFAULT_NODE 0
#define SINGLE_NODE 1
#define DOUBLE_NODE 2
#define CIRULAR_NODE 3
#define DOUBLE_CIRCULAR_NODE 4

template <typename T, typename NT>
struct NodeTraits{
  static const int nodeType = DEFAULT_NODE;
};

template <typename NT>
struct NodeTraits< ForwardListNode<NT>, NT >{
  static const int nodeType = SINGLE_NODE;
};

template <typename NT>
struct NodeTraits< DoubleListNode<NT>, NT >{
  static const int nodeType = DOUBLE_NODE;
};

template <typename NT>
struct NodeTraits< CircularNode<NT>, NT >{
  static const int nodeType = CIRULAR_NODE;
};

template <typename NT>
struct NodeTraits< CircularDoubleNode<NT>, NT >{
  static const int nodeType = DOUBLE_CIRCULAR_NODE;
};


//---------------------------LISTAS----------------------

template <typename Node>
class List {
    protected:
        typedef Node node_t;
        typedef typename node_t::value_t value_t;
        typedef std::size_t size;

        node_t* head;
        node_t* tail;   

        template<int nodeType>
        void __push_back__(Node**&,Node**&,value_t);

        template<int nodeType>
        void __push_front__(Node**&,Node**&,value_t);

        template<int nodeType>
        void __insert__(Node**&,Node**&,value_t, Node*&);

        template<int nodeType>
        void __pop_back__(Node**&,Node**&);

        template<int nodeType>
        void __pop_front__(Node**&,Node**&);

        template<int nodeType>
        void __remove__(Node**&,Node**&,value_t);

        template<int nodeType>
        void __erase__(Node**&,Node**&,Node*&);

        template<int nodeType>
        void __sort__(Node**&,Node**&);

        template<int nodeType>
        void __reverse__(Node**&,Node**&);

        template<int nodeType>
        std::size_t __size__(Node**&,Node**&);


    public:
        List(const List&):head(nullptr){ 
        }
        
        List(value_t*):head(nullptr){ 
        }

        List(node_t*):head(nullptr){ 
        }

        List(int):head(nullptr){ 
        }

        List(void):head(nullptr){ 
        }

        ~List(void){
        }
        
  /*      
        virtual void push_back(const value_t& element) = 0; 
        virtual void push_front(const value_t& element) = 0; 

        virtual value_t& front(void) = 0; 
        virtual value_t& back(void) = 0; 

        virtual node_t* pop_back(void) = 0;
        virtual node_t* pop_front(void) = 0;  

        virtual value_t& operator[] (const int&) = 0; 
        
        virtual bool empty(void){
            return head == nullptr;
        }; 

        virtual unsigned int size(void) = 0; 
*/
        template<typename _T>
        inline friend ostream& operator<< (ostream& out, const List<_T>&){
            out << "Nothing to print in father" << endl;
            return out;
        }

        
        List& operator<< (const value_t& _value){
            this->push_back(_value);
            return *this;
        }

        List& operator>> (const value_t& _value){
            this->push_front(_value);
            return *this;
        }
};

template <typename Node>
class ForwardList : public List<Node>{
public:
    typedef Node node_t;
    typedef typename node_t::value_t value_t;
    typedef 
    
    friend class ForwardIterator;
    class ForwardIterator: public Iterator<node_t> {
        public:
            typedef typename Iterator<node_t>::node_t node_t;
            typedef typename Iterator<node_t>::value_t value_t;

        public: 
            ForwardIterator (node_t* pointer = nullptr)
            :Iterator<node_t>(pointer){
            }

            ~ForwardIterator (void){
            }

            ForwardIterator& operator++ (void){
                Iterator<node_t>::pointer = Iterator<node_t>::pointer->next; 
                return *this;
            }

    };

    protected:
        node_t *head;
        node_t *tail;
    public:

        ForwardList(void)
        :List<node_t>(), head(nullptr), tail(nullptr){
        }

        ~ForwardList (void){
        }

        ForwardIterator begin(){
            return ForwardIterator(head);
        }

        ForwardIterator end(){
            return ForwardIterator(tail);
        }

        void push_front(const value_t& element){
            node_t *new_node = new node_t(element);
            if (!head){
                tail = head = new_node;
            } else {
                node_t * tmp = head;
                head = new_node;
                head->next = tmp;
            }
        }

        value_t& front(void){
            return head->value;
        }; 

        value_t& back(void){
            return tail->value;
        }; 

        node_t* pop_back(void){
            node_t* tmpRes = new node_t(tail->value);
            node_t * tmpPointer = head;
            while(tmpPointer->next!=tail){
                 tmpPointer = tmpPointer->next;
            }
            tail = tmpPointer;
            delete tail->next;
            tail->next = nullptr;
            return  tmpRes;
        };

        node_t* pop_front(void){
            node_t* tmpRes = new node_t(head->value);
            node_t * tmpPointer = head;
            head = head->next;
            delete tmpPointer;
            return tmpRes;
        };  

        value_t& operator[] (const int& _position){
            node_t * tmp = head;
            for (int i = 0; i < _position; i++, tmp = tmp->next);
            return tmp->value;
        }

        bool empty(void){
            return head == nullptr;
        }

        unsigned int size(void){
            int i = 0;
            for (node_t * tmp = head; tmp != nullptr; i++, tmp = tmp->next);
            return i;
        }

        template<typename _T>
        inline friend ostream& operator<< (ostream& out, ForwardList<_T>& _list){
            typename ForwardList<_T>::ForwardIterator it = _list.begin();
            for(; it != _list.end(); ++it){
                out << *it << " -> ";
            }
            out << *it << " -> ";
            /*
            if (!_list.head) return out;
            ForwardListNode<T> *tmp = _list.head;
            while(tmp){
                out << *tmp << " -> ";
                tmp = tmp->next;
            }
            */
            return out;
        }
};


//-------------------------------list helper------------------------------
template <typename Node, typename ValueNode, int nodeType>
class ListHelper{
  public:
  static void push_back(Node** head, Node** tail, ValueNode element){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void push_front(Node** head, Node** tail, ValueNode element){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void insert(Node** head, Node** tail, Node* &ref, ValueNode element){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void pop_back(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void pop_front(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void remove(Node** head, Node** tail, ValueNode element){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void print(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void erase(Node** head, Node** tail, Node* &ref){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void sort(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void reverse(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
  static void clear(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
    s clear(Node** head, Node** tail){
    cout << "Hola no tengo trait definido" << endl;
  }
};

//-----------------------------Override-------------------------------------------------
template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,SINGLE_NODE>{
  public:
  static void push_front(Node** head, Node** tail, ValueNode element){
      cout << "Hola soy el push_back para una forward list." << endl;    
          Node * new_node = new Node(element);
          if (*head == nullptr)
          {
            *head = new_node;
            (*tail) = new_node;
          } else
          {
            new_node->next = *head;
            *head = new_node;
            len++;
          }

  } 
};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,DOUBLE_NODE>{
  public:
  static void add(Node** head, Node** tail, ValueNode element){
    cout << "Hola soy el push_back para una double list." << endl;

  } 
};

template< typename Node>  template <int nodeType>
void List<Node>::__push_back__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail, 
  typename List<Node>::value_t element){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail,element);
}

template< typename Node>  template <int nodeType>
void List<Node>::__push_front__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail, 
  typename List<Node>::value_t element){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail,element);
}
template< typename Node>  template <int nodeType>
void List<Node>::__pop_back__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail);
}
template< typename Node>  template <int nodeType>
void List<Node>::__pop_front__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail);
}
template< typename Node>  template <int nodeType>
void List<Node>::__insert__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail, 
  typename List<Node>::value_t element,
  typename List<Node>::node_t * &ref){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail,element,ref);
}
template< typename Node>  template <int nodeType>
void List<Node>::__remove__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail, 
  typename List<Node>::value_t element){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail,element);
}
template< typename Node>  template <int nodeType>
void List<Node>::__erase__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail, 
  typename List<Node>::node_t * &ref){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail,ref);
}
template< typename Node>  template <int nodeType>
void List<Node>::__sort__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail);
}
template< typename Node>  template <int nodeType>
void List<Node>::__reverse__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail);
}
template< typename Node>  template <int nodeType>
std::size_t List<Node>::__size__(
  typename List<Node>::node_t ** &head, 
  typename List<Node>::node_t ** &tail){
  
  ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::add(head,tail);
}


typedef ForwardListNode<float> forward_node_t;
typedef ForwardList<forward_node_t> list_t;
typedef list_t::ForwardIterator iterator_t;

typedef DoubleListNode<float> double_node_t;
typedef ForwardList<double_node_t> dlist_t;

