#include "linkedlist.h"

Linkedlist::Linkedlist(Node<std::string>* firstNode){
  this->firstNode = firstNode;
  this->size = 1;
}

Linkedlist::Linkedlist(){
  this->firstNode = nullptr;
  this->size = 0;
}

Linkedlist::~Linkedlist(){ }

Node<std::string>* Linkedlist::getLastNode(){
  // Iterate over the list's nodes
  // until the last node is reached
  Node<std::string>* tmp = this->firstNode;
  while (tmp->getNextNode() != nullptr) {
    tmp = tmp->getNextNode();
  }
  return tmp;
}

void Linkedlist::removeLast(){
  assert(this->size > 0);
  if (this->size > 1) {
    Node<std::string>* lastNode = this->getLastNode();
    lastNode->getPreviousNode()->setNextNode(nullptr);
    delete lastNode;
  }else{
    delete this->firstNode;
  }
  this->size--;
}

void Linkedlist::removeFirst(){
  assert(this->size > 0);
  if (this->size > 1) {
    Node<std::string>* tmp = this->getNodeIndex(1);
    delete this->firstNode;
    this->firstNode = tmp;
    tmp->setPreviousNode(nullptr);
  }else {
    // We only have this node on the list
    delete this->firstNode;
    this->firstNode = nullptr;
  }
  this->size--;
}

void Linkedlist::append(Node<std::string> *node){
  Node<std::string>* lastNode = this->getLastNode();
  lastNode->setNextNode(node);
  node->setPreviousNode(lastNode);
  this->size++;
}

void Linkedlist::prepend(Node<std::string> *node){
  node->setNextNode(this->firstNode);
  node->getNextNode()->setPreviousNode(node);
  node->setPreviousNode(nullptr);
  this->firstNode = node;
  this->size++;
}

void Linkedlist::addToIndex(Node<std::string> *node, int index){
  assert(node != nullptr);
  assert(index > 0 && index < this->size);
  Node<std::string>* tmp = this->getNodeIndex(index);
  std::cout << "addToIndex tmp->data:" + tmp->getData() << std::endl;
  tmp->getPreviousNode()->setNextNode(node);
  node->setPreviousNode(tmp->getPreviousNode());
  node->setNextNode(tmp);
  tmp->setPreviousNode(node);
  this->size++;
}

void Linkedlist::removeFromIndex(int index){
  assert(index > 0 && index < this->size);
  Node<std::string>* tmp = this->getNodeIndex(index);

  tmp->getPreviousNode()->setNextNode(tmp->getNextNode());
  tmp->getNextNode()->setPreviousNode(tmp->getPreviousNode());
  delete tmp;
  this->size--;
}

Node<std::string>* Linkedlist::getNodeIndex(int index){
  Node<std::string>* tmp = this->firstNode;
  for (int i = 0; i < index; ++i) {
    tmp = tmp->getNextNode();
  }
  return tmp;
}

void Linkedlist::print(){
  std::cout << "LinkedList::Print():" << std::endl; 
  for (int i = 0; i < this->size; ++i) {
    std::cout << "\t" + this->getNodeIndex(i)->getData() << std::endl;

  }
}




