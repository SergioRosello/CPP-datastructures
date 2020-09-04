#include <iostream>
#include <string.h>

enum class Color{
  RED,
  GREEN,
  ORANGE
};

Color& operator++(Color& col){
  if(col == Color::GREEN) col = Color::ORANGE;
  else if(col == Color::RED) col = Color::GREEN;
  else if(col == Color::ORANGE) col = Color::RED;
  return col;
}

std::ostream& operator<<(std::ostream& output, Color& col){
  switch (col) {
    case Color::RED:
      output << "RED";
      break;
    case Color::GREEN: 
      output << "GREEN";
      break;
    case Color::ORANGE:
      output << "ORANGE";
      break;
  }
  return output;
}

int main(int argc, char *argv[])
{
  Color col = Color::GREEN;
  ++col;
  std::cout << col << std::endl;
}
