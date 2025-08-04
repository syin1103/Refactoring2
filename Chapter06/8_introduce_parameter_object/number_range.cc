#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Record {
  int temp;
  std::string time;
};

struct Station {
  std::string name;
  std::vector<Record> readings;
};

std::vector<Record> ReadingsOutsideRange(const Station& station, int min,
                                         int max) {
  std::vector<Record> result{};
  std::copy_if(station.readings.begin(), station.readings.end(),
               std::back_inserter(result), [min, max](const Record& r) {
                 return r.temp < min || r.temp > max;
               });
  return result;
}

int main() {
  Station station;
  station.name = "ZB1";
  station.readings = {{47, "2016-11-10 09:10"},
                      {53, "2016-11-10 09:20"},
                      {58, "2016-11-10 09:30"},
                      {53, "2016-11-10 09:30"},
                      {51, "2016-11-10 09:50"}};

  auto result = ReadingsOutsideRange(station, 48, 55);
  for (const auto& record : result) {
    std::cout << record.temp << ", " << record.time << std::endl;
  }

  return 0;
}