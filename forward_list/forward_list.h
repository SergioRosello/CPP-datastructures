#include <initializer_list>
#include <iostream>

class Forward_list{
  struct Node{
    int value;
    Node* next = nullptr;
    explicit Node(const int value) :value{ value } {}
  };
  Node* first = nullptr;
  Node* last = nullptr;
  std::size_t len = 0;

  void printReverse(Node* current);
  void remove_nodes(Node*);

  public:
    inline Forward_list() = default;
    Forward_list(std::initializer_list<int>l);
    ~Forward_list(); // Ensure all nodes are deleted
    void reverse();
    void print();
    void emplace_back(const int);
    void remove_last();
    void printReverse();
};
