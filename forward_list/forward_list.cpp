#include "forward_list.h"

void Forward_list::print(){
  Node* tmp = first;
  for(int i = 0; i < len; ++i){
    std::cout << tmp->val << std::endl;
    tmp = tmp->next_node;
  }
}

void Forward_list::printReverse(){
  printReverse(first);
}

void Forward_list::printReverse(Node* current){
  if(current->next_node != nullptr){
    printReverse(current->next_node);
  }
  std::cout << current->val << std::endl;
}
