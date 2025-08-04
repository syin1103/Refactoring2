#include <cmath>
#include <iostream>

#define _USE_MATH_DEFINES

double Circum(double radius) { return 2 * M_PI * radius; }

int main() {
  std::cout << Circum(23) << std::endl;
  return 0;
}