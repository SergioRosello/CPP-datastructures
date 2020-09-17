#include "forward_list.h"

int main(int argc, char *argv[])
{
  Forward_list list{1, 2, 3, 4, 5};

  list.print();
  list.remove_last();
  list.emplace_back(6);
  list.print();
  return 0;
}
