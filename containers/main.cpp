#include <algorithm>
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
  MyClass newClass = MyClass {1, 2, 3, 4, 5};
  newClass.printList();
  return 0;
}
