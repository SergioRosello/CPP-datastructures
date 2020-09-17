#include "forward_list.h"

Forward_list::Forward_list(std::initializer_list<int>l){
  for(auto n : l){
    emplace_back(n);
  }
}

Forward_list::~Forward_list(){
  remove_nodes(first);
}

void Forward_list::remove_last(){
  Node* prev = first;
  while(prev->next != last){
    prev = prev->next;
  }
  delete last;
  prev->next = nullptr;
  last = prev;
}

void Forward_list::remove_nodes(Node* n){
  if(n != nullptr){
    remove_nodes(n->next);
  }
  delete n;
}

void Forward_list::print(){
  Node* n = first;
  while(n != nullptr){
    std::cout << n->value << std::endl;
    n = n->next;
  }
}

void Forward_list::printReverse(){
  printReverse(first);
}

void Forward_list::emplace_back(const int v){
  Node* n = new Node(v);
  if(first == nullptr && last == nullptr){
    first = n;
    last = n;
  }
  else{
    last->next = n;
    last = n;
  }
  ++len;
}

void Forward_list::reverse(){
  Node* orig_list = first;
  Node* reversed_list_head = nullptr;
  while (orig_list != nullptr) {
    Node* orig_list_tail = orig_list->next;
    orig_list->next = reversed_list_head;
    reversed_list_head = orig_list;
    orig_list = orig_list_tail;
  }
  first = reversed_list_head;
}

void Forward_list::printReverse(Node* current){
  if(current->next != nullptr){
    printReverse(current->next);
  }
  std::cout << current->value << std::endl;
}

