#include "node.h"
template <typename T>
    class Fiterator {
        private:
            typedef Node<T> Node;
            Node * pointer;
            
        public:
            Fiterator():pointer(nullptr) {}
            Fiterator(Node * ptr): pointer(ptr){}

            ~Fiterator(void){}
            
            T operator * (){
                return this->pointer->value;
            }
            
            void operator ++(){
                this->pointer = this->pointer->next;
            }

            bool operator == (const Fiterator & it){
                return this->pointer == it.pointer;
            }
            
            bool operator != (const Fiterator & it){
                return this->pointer != it.pointer;
            }

            bool operator <= (const Fiterator & it){
                return this->pointer <= it.pointer;
            }
    
            bool operator >= (const Fiterator & it){
                return this->pointer >= it.pointer;
            }    
            bool operator > (const Fiterator & it){
                return this->pointer > it.pointer;
            }      

            bool operator < (const Fiterator & it){
                return this->pointer < it.pointer;
            }  
    
    };

