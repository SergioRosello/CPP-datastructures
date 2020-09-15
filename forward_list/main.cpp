#include "forward_list.h"

int main(int argc, char *argv[])
{
  Node first{1, nullptr};
  Forward_list list{&first};
  
  Node second{2, nullptr};
  list.addNode(&second);

  // list.print();
  list.printReverse();
  return 0;
}
