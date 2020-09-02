#include "stack.h"
#include <iostream>
#include <string>

using namespace::std;

int main(int argc, char *argv[])
{
  string first = "First string";
  string second = "Second string";
  Stack<string> stack;

  stack.Push(first);
  stack.Push(second);


  while (!stack.isEmpty()) {
    cout << stack.Pop() << endl;
  }

  return 0;
}


