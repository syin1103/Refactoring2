#include <iostream>

struct Range {
  Range(int l, int h) : low(l), high(h) {}
  int low;
  int high;
};

struct Room {
  Range days_temp_range;
};

class Plan {
 public:
  Plan(Range range) : temperature_range_(range) {};
  bool WithinRange(const Range& range) {
    return (range.low >= temperature_range_.low) &&
           (range.high <= temperature_range_.high);
  }

 private:
  Range temperature_range_;
};

int main() {
  Room room{{20, 40}};
  Plan plan{{10, 30}};

  int low = room.days_temp_range.low;
  int high = room.days_temp_range.high;
  if (!plan.WithinRange(room.days_temp_range)) {
    std::cout << "room temperature went outside range" << std::endl;
  }

  return 0;
}