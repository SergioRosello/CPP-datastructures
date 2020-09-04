#include <iostream>
#include <stdexcept>

class Vector{
  private:
    double* data;
    int size;
  public:
    Vector();
    Vector(int);
    int getSize();
    double& operator[](int);
};

Vector::Vector(int size) :data{new double[size]},size{size} {}

int Vector::getSize(){ return size; }

double& Vector::operator[](int i){
  if(i >= size || i < 0) throw std::out_of_range{"Vector::operator[]"};
  return data[i];
}

int main(int argc, char *argv[])
{
  Vector* vec = new Vector(3);
  try {
  vec[vec->getSize()] = 4;
  } catch (std::out_of_range) {
  }
  
  return 0;
}
