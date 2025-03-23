#include <iostream>

struct Control {
  Control(int selected, int current)
      : selected_temperature(selected), current_temperature(current) {};
  int selected_temperature;
  int current_temperature;
};

Control thermostat(110, 20);

class HeatingPlan {
 public:
  HeatingPlan(int min, int max) : min_(min), max_(max) {}

  int TargetTemperature() {
    if (thermostat.selected_temperature > max_) {
      return max_;
    } else if (thermostat.selected_temperature < min_) {
      return min_;
    } else {
      return thermostat.selected_temperature;
    }
  }

 private:
  int max_;
  int min_;
};

void SetToHeat() { std::cout << "set to heat ... " << std::endl; }
void SetToCool() { std::cout << "set to cool ... " << std::endl; }
void SetOff() { std::cout << "set off ... " << std::endl; }

int main() {
  HeatingPlan plan(10, 100);

  if (plan.TargetTemperature() > thermostat.current_temperature) {
    SetToHeat();
  } else if (plan.TargetTemperature() < thermostat.current_temperature) {
    SetToCool();
  } else {
    SetOff();
  }
  return 0;
}