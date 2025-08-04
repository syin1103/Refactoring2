#include <cmath>
#include <iostream>

#define _USE_MATH_DEFINES

double Circumference(double radius) { return 2 * M_PI * radius; }

int main() {
  std::cout << Circumference(23) << std::endl;
  return 0;
}