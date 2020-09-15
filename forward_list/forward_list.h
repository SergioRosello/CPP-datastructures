#include <iostream>
#include "node.h"

class Forward_list{
  public:
    inline Forward_list(){first = nullptr; len = 0; last = nullptr;};
    inline Forward_list(Node* node):first{node}{len = 1; last = node;};
    inline ~Forward_list(){};
    inline Node* getNextNode(Node* current) { return current->next_node; };
    inline void addNode(Node* node) { last->next_node = node; last = node; ++len;};
    void print();
    void printReverse(Node* current);
    void printReverse();
  private:
    Node* first;
    Node* last;
    int len;
};
