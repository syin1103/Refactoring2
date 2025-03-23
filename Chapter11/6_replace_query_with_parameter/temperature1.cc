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

  int TargetTemperature(int tempearture) {
    if (tempearture > max_) {
      return max_;
    } else if (tempearture < min_) {
      return min_;
    } else {
      return tempearture;
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

  int selected = thermostat.selected_temperature;
  int current = thermostat.current_temperature;
  if (plan.TargetTemperature(selected) > current) {
    SetToHeat();
  } else if (plan.TargetTemperature(selected) < current) {
    SetToCool();
  } else {
    SetOff();
  }
  return 0;
}