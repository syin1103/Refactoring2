#include <iostream>

struct Scenario {
  int primary_force = 10;
  int mass = 9;
  int delay = 288;
  int secondary_force = 110;
};

double DistanceTravelled(Scenario scenario, int time) {
  double result = 0.0;
  double primary_acceleration = scenario.primary_force / scenario.mass;
  int primary_time = std::min(time, scenario.delay);
  result = 0.5 * primary_acceleration * primary_time * primary_time;
  int secondary_time = time - scenario.delay;
  if (secondary_time > 0) {
    double primary_velocity = primary_acceleration * scenario.delay;
    double secondary_acceleration =
        (scenario.primary_force + scenario.secondary_force) / scenario.mass;
    result += primary_velocity * secondary_time +
              0.5 * secondary_acceleration * secondary_time * secondary_time;
  }
  return result;
}

int Discount(int input_value, int quantity) {
  int result = input_value;
  if (input_value > 50) {
    result = result - 2;
  }

  if (quantity > 100) {
    result = result - 1;
  }
  return result;
}

int main() {
  std::cout << DistanceTravelled(Scenario(), 110) << std::endl;
  std::cout << Discount(101, 80) << std::endl;

  return 0;
}