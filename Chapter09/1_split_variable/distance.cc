#include <iostream>

struct Scenario {
  int primary_force = 10;
  int mass = 9;
  int delay = 288;
  int secondary_force = 110;
};

double DistanceTravelled(Scenario scenario, int time) {
  double result = 0.0;
  double acc = scenario.primary_force / scenario.mass;
  int primary_time = std::min(time, scenario.delay);
  result = 0.5 * acc * primary_time * primary_time;
  int secondary_time = time - scenario.delay;
  if (secondary_time > 0) {
    double primary_velocity = acc * scenario.delay;
    acc = (scenario.primary_force + scenario.secondary_force) / scenario.mass;
    result += primary_velocity * secondary_time +
              0.5 * acc * secondary_time * secondary_time;
  }
  return result;
}

int Discount(int input_value, int quantity) {
  if (input_value > 50) {
    input_value = input_value - 2;
  }

  if (quantity > 100) {
    input_value = input_value - 1;
  }
  return input_value;
}

int main() {
  std::cout << DistanceTravelled(Scenario(), 110) << std::endl;
  std::cout << Discount(101, 80) << std::endl;
  return 0;
}