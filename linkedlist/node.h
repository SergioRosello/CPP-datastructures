#ifndef NODE_H
#define NODE_H

#include <assert.h>

template<typename T>
class Node
{
private:
  T data;
  Node* previousNode;
  Node* nextNode;

public:
  Node();
  Node(T);
  // Getters and setters
  inline const bool setNextNode(Node*);
  inline const bool setPreviousNode(Node*);
  inline Node* getNextNode();
  inline Node* getPreviousNode();
  inline const bool eliminate();
  inline const T getData();
  virtual ~Node();
};


template<typename T>
Node<T>::Node(T data){ 
  this->previousNode = nullptr;
  this->nextNode = nullptr;
  this->data = data;
}

template<typename T>
Node<T>::Node(){ 
  this->previousNode = nullptr;
  this->nextNode = nullptr;
  this->data = nullptr;
}

template<typename T>
Node<T>::~Node(){ }

template<typename T>
inline const bool Node<T>::setPreviousNode(Node* previousNode){ 
  this->previousNode = previousNode;
  return true;
}

template<typename T>
inline const bool Node<T>::setNextNode(Node* nextNode){ 
  this->nextNode = nextNode;
  return true;
}

template<typename T>
inline Node<T>* Node<T>::getNextNode(void) {
  return this->nextNode;
}

template<typename T>
inline Node<T>* Node<T>::getPreviousNode(){
  return this->previousNode;
}

template<typename T>
inline const bool Node<T>::eliminate(){
  return true;
}

template<typename T>
inline const T Node<T>::getData(){
  return this->data;
}
#endif /* NODE_H */
