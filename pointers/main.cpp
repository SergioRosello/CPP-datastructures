#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory> // unique_ptr

template <class T>
class SVec
{
  private:
    T* list;
    int size;
  public:
    SVec();
    SVec(std::initializer_list<T>);
    ~SVec();
    int& operator[](int) const;
};

template <class T>
SVec<T>::~SVec(){}

template <class T>
SVec<T>::SVec(){}

template <class T>
SVec<T>::SVec(std::initializer_list<T> lst) :list{new T[lst.size()]},size{int(lst.size())} {
  std::copy(lst.begin(), lst.end(), list);
}

template <class T>
int& SVec<T>::operator[](int i) const{
  if(i >= size || i < 0) throw std::out_of_range{"SVec::operator[]"};
  return list[i];
}


// Pointer syntax
//
// In declarations, [] means array of
// In declarations, *  means pointer to
// In declarations, &  neans reference to
//
// In expressions, * means contents of
// In expressions, & measn address of
int main(int argc, char *argv[])
{

  // Increasing the value of i throug a
  // pointer to i.
  auto i = 30;
  auto* p_i = &i;
  auto& r_i = i;
  auto j = *p_i;
  *p_i += 1;
  std::cout << i << std::endl;
  std::cout << r_i << std::endl;
  std::cout << *p_i << std::endl;
  std::cout << j << std::endl;

  // We have a list and we want to print
  // each element on the list.
  // We are using auto, because lists have
  // iterator capabilities
  // but we are also using a pointer to reference
  // the address of the element, instead of 
  // copying the element's value for each iteration
  // we are only increasing the address the pointer
  // points to.
  int list[] {0,1,2,3,4,5,6,7,8,9};
  for (auto& i : list) {
    std::cout << i;
    i++;
  }

  SVec<int> vector = {1, 2, 3, 4, 5, 6, 7, 8};

  

  std::cout << "Unique PTR inplementation" << std::endl;
  std::cout << vector[2];
  
  return 0;
}
