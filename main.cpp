
#include <iostream>
#include "list.hpp"
int main (int, char*[]){
    List<int> list;
    List<int>::iterator it;
    list.push_back(4);
    list.push_front(3);
    list.push_back(5);
    list.push_front(2);
    list.push_back(6);
    list.push_front(1);

    //list.remove(3);
    
    std::cout << list;

    std::cout<<std::endl;
    int arr[5] = {1,2,3,4,5};
    List<int> arrlist(arr, 5);
    List<int>::iterator ait;
    for (int i = 0; i <= arrlist.len; i++){
        std::cout << arrlist[i] << " ";
    }
    std::cout << "\n";
    arrlist.push_back(6);

    for (int i = 0; i <= arrlist.len; i++){
        std::cout << arrlist[i] << " ";
    }
    std::cout << std::endl;
    return 1;
}
