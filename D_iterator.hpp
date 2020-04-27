#include "node.h"
template <typename T>
    class Diterator {
        private:
            typedef DNode<T> Node;
            DNode * pointer;
            
        public:
            Diterator():pointer(nullptr) {}
            Diterator(DNode * ptr): pointer(ptr){}

            ~Diterator(void){}
            
            T operator * (){
                return this->pointer->value;
            }
            
            void operator ++(){
                this->pointer = this->pointer->next;
            }
            
            void operator --(){
                this->pointer = this->pointer->prev;
            }

            bool operator == (const Diterator & it){
                return this->pointer == it.pointer;
            }
            
            bool operator != (const Diterator & it){
                return this->pointer != it.pointer;
            }

            bool operator <= (const Diterator & it){
                return this->pointer <= it.pointer;
            }
    
            bool operator >= (const Diterator & it){
                return this->pointer >= it.pointer;
            }    
            bool operator > (const Diterator & it){
                return this->pointer > it.pointer;
            }      

            bool operator < (const Diterator & it){
                return this->pointer < it.pointer;
            }  
    
    };
