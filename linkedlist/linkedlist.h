#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include "node.h"

class Linkedlist
{
private:
  Node<std::string>* firstNode;
  int size;
  Node<std::string>* getNodeIndex(int);
  Node<std::string>* getLastNode();

public:
  Linkedlist();
  Linkedlist(Node<std::string>*);
  bool prepend(Node<std::string> *node);
  bool append(Node<std::string>* node);
  bool addToIndex(Node<std::string>*, int);
  bool removeFromIndex(int);
  bool removeLast();
  bool removeFirst();
  virtual void print();
  virtual ~Linkedlist();
};

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

bool Linkedlist::removeLast(){
  assert(this->size > 0);
  if (this->size > 1) {
    Node<std::string>* lastNode = this->getLastNode();
    lastNode->getPreviousNode()->setNextNode(nullptr);
    delete lastNode;
  }else{
    delete this->firstNode;
  }
  this->size--;
  return true;
}

bool Linkedlist::removeFirst(){
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
  return true;
}

bool Linkedlist::append(Node<std::string> *node){
  Node<std::string>* lastNode = this->getLastNode();
  lastNode->setNextNode(node);
  node->setPreviousNode(lastNode);
  this->size++;
  return true;
}

bool Linkedlist::prepend(Node<std::string> *node){
  node->setNextNode(this->firstNode);
  node->getNextNode()->setPreviousNode(node);
  node->setPreviousNode(nullptr);
  this->firstNode = node;
  this->size++;
  return true;
}

bool Linkedlist::addToIndex(Node<std::string> *node, int index){
  assert(node != nullptr);
  assert(index > 0 && index < this->size);
  Node<std::string>* tmp = this->getNodeIndex(index);
  std::cout << "addToIndex tmp->data:" + tmp->getData() << std::endl;
  tmp->getPreviousNode()->setNextNode(node);
  node->setPreviousNode(tmp->getPreviousNode());
  node->setNextNode(tmp);
  tmp->setPreviousNode(node);
  this->size++;
  return true;
}

bool Linkedlist::removeFromIndex(int index){
  assert(index > 0 && index < this->size);
  Node<std::string>* tmp = this->getNodeIndex(index);

  tmp->getPreviousNode()->setNextNode(tmp->getNextNode());
  tmp->getNextNode()->setPreviousNode(tmp->getPreviousNode());
  delete tmp;
  this->size--;
  return true;
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

#endif /* LINKEDLIST_H */


