#include "linkedlist.h"

// Run the linked list.
int main(int argc, char *argv[])
{
  Node<std::string>* firstNode = new Node<std::string>("Fisrst Node");
  Linkedlist *list = new Linkedlist(firstNode);

  Node<std::string>* secondNode = new Node<std::string>("Second Node");
  list->append(secondNode);
  Node<std::string>* thirdNode = new Node<std::string>("Third Node");
  list->append(thirdNode);

  Node<std::string>* fourthNode = new Node<std::string>("Fourth Node");
  list->prepend(fourthNode);

  Node<std::string>* fifthNode = new Node<std::string>("Fifth Node");
  list->addToIndex(fifthNode, 2);

  list->print();

  list->removeFromIndex(1);
  list->removeFromIndex(1);
  list->removeLast();
  list->removeLast();
  list->removeFirst();

  list->print();
  delete list;
  return 0;
}
