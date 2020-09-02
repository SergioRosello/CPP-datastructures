#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>
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
  void prepend(Node<std::string> *node);
  void append(Node<std::string>* node);
  void addToIndex(Node<std::string>*, int);
  void removeFromIndex(int);
  void removeLast();
  void removeFirst();
  virtual void print();
  virtual ~Linkedlist();
};

#endif /* LINKEDLIST_H */
