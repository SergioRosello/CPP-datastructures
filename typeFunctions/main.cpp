#include <iostream>
#include <forward_list>
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>

template<typename C> using Iterator_type = typename C::iterator;
template<typename T> using Value_type = typename std::vector<T>::value_type;
template<typename Iter> using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;

template<class C> void my_sort(C&);
template <typename For> void sort_helper(For , For , std::forward_iterator_tag);
template <typename Ran> void sort_helper(Ran , Ran , std::random_access_iterator_tag);
void test(std::vector<int>&, std::forward_list<int>&);

int main(int argc, char *argv[])
{
  std::forward_list<int>l{5, -1, 9, 1, 8, 10, 4, 18, 6};
  std::vector<int>v{5, -1, 9, 1, 8, 10, 4, 18, 6};
  test(v, l);
  std::cout << "list in main: ";
  for(auto i : l) std::cout << i << ", ";
  std::cout << std::endl;
  std::cout << "Vector in main: ";
  for(auto i : v) std::cout << i << ", ";
  std::cout << std::endl;
  return 0;
}

template <typename For> // for forward iterators
void sort_helper(For begin, For end, std::forward_iterator_tag){
  // Copy forward iterator container into random access container
  std::vector<typename std::iterator_traits<For>::value_type>v{begin, end}; // Initialise a vector of the type of the contents of begin
  // sort random access container
  sort(v.begin(), v.end());
  // copy sorted container into forward iterator container
  copy(v.begin(), v.end(), begin);
}

template<class C>
void my_sort(C& c){
  using Iter = Iterator_type<C>;
  sort_helper(c.begin(), c.end(), Iterator_category<Iter>{});
}

template <typename Ran> // Random access iterators
void sort_helper(Ran begin, Ran end, std::random_access_iterator_tag){
  sort(begin, end);
}

void test(std::vector<int>& v, std::forward_list<int>& l){
  my_sort(v);
  my_sort(l);
}

