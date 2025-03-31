#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

enum class BirdType {
  EuropeanSwallow = 0,
  AfricanSwallow,
  NorwegianBlueParrot,
  Unknown
};

struct Bird {
  Bird(const std::string& bname, BirdType btype, int bnum, int bvoltage,
       bool bnailed)
      : name(bname),
        type(btype),
        num_of_coconuts(bnum),
        voltage(bvoltage),
        is_nailed(bnailed) {}

  std::string name;
  BirdType type;
  int num_of_coconuts;
  int voltage;
  bool is_nailed;
};

std::string plumage(const Bird& bird) {
  switch (bird.type) {
    case BirdType::EuropeanSwallow:
      return "EuropeanSwallow";
    case BirdType::AfricanSwallow:
      return bird.num_of_coconuts > 2 ? "tired" : "average";
    case BirdType::NorwegianBlueParrot:
      return bird.voltage > 100 ? "scorched" : "beautiful";
    default:
      return "Unknown";
  }
}

int AirSpeedVelocity(const Bird& bird) {
  switch (bird.type) {
    case BirdType::EuropeanSwallow:
      return 35;
    case BirdType::AfricanSwallow:
      return 40 - 2 * bird.num_of_coconuts;
    case BirdType::NorwegianBlueParrot:
      return bird.is_nailed ? 0 : 10 + bird.voltage / 10;
    default:
      return -1;
  }
}

std::unordered_map<std::string, std::string> plumages(
    const std::vector<Bird>& birds) {
  std::unordered_map<std::string, std::string> result{};
  std::for_each(birds.begin(), birds.end(), [&result](const Bird& bird) {
    result[bird.name] = plumage(bird);
  });
  return result;
}

std::unordered_map<std::string, int> speed(const std::vector<Bird>& birds) {
  std::unordered_map<std::string, int> result{};
  std::for_each(birds.begin(), birds.end(), [&result](const Bird& bird) {
    result[bird.name] = AirSpeedVelocity(bird);
  });
  return result;
}

int main() {
  std::vector<Bird> birds{};
  birds.push_back({"bird1", BirdType::EuropeanSwallow, 200, 300, true});
  birds.push_back({"bird2", BirdType::AfricanSwallow, 200, 300, false});
  birds.push_back({"bird3", BirdType::NorwegianBlueParrot, 200, 300, true});

  std::unordered_map<std::string, std::string> plumage_map = plumages(birds);
  std::unordered_map<std::string, int> speed_map = speed(birds);

  for (auto it = plumage_map.begin(); it != plumage_map.end(); it++) {
    std::cout << it->first << ", " << it->second << std::endl;
  }

  for (auto it = speed_map.begin(); it != speed_map.end(); it++) {
    std::cout << it->first << ", " << it->second << std::endl;
  }

  return 0;
}