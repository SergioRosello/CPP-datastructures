#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
#include <initializer_list>  // std::initializer_list

class MyClass
{
  public:
    MyClass();
    MyClass(std::initializer_list<int>);
    void printList();
  private:
    int* list;
    int size;
};

MyClass::MyClass(std::initializer_list<int> lst) :list{new int[lst.size()]}, size{(int) lst.size()} {
  std::copy(lst.begin(), lst.end(), list);
}

void MyClass::printList(){
  for(auto i = 0; i < size; ++i){
    std::cout << list[i] << std::endl;
  }
}

int main(int argc, char *argv[])
{
  //MyClass newClass = MyClass {1, 2, 3, 4, 5};
  //newClass.printList();

  std::ostream_iterator<std::string> oo{std::cout};
  *oo = "Hello, ";  // Equivalent to "cout << "Hello, ";
  //++oo;
  *oo = "World!\n"; // Equivalent to "cout << "World!\n";
  return 0;
}
