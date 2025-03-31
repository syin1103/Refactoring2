#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

enum class BirdType {
  EuropeanSwallow = 0,
  AfricanSwallow,
  NorwegianBlueParrot,
  Unknown
};

class Bird {
 public:
  Bird(const std::string& bname, int bnum, int bvoltage, bool bnailed)
      : name_(bname),
        num_of_coconuts_(bnum),
        voltage_(bvoltage),
        is_nailed_(bnailed) {}

  virtual std::string Plumage() = 0;
  virtual int AirSpeedVelocity() = 0;
  virtual BirdType type() = 0;
  std::string name() { return name_; }

 protected:
  std::string name_;
  int num_of_coconuts_;
  int voltage_;
  bool is_nailed_;
};

class EuropeanSwallow : public Bird {
 public:
  EuropeanSwallow(const std::string& bname, int bnum, int bvoltage,
                  bool bnailed)
      : Bird(bname, bnum, bvoltage, bnailed) {}

  std::string Plumage() override { return "EuropeanSwallow"; }
  int AirSpeedVelocity() override { return 35; }
  BirdType type() override { return BirdType::EuropeanSwallow; }
};

class AfricanSwallow : public Bird {
 public:
  AfricanSwallow(const std::string& bname, int bnum, int bvoltage, bool bnailed)
      : Bird(bname, bnum, bvoltage, bnailed) {}

  std::string Plumage() override {
    return num_of_coconuts_ > 2 ? "tired" : "average";
  }

  int AirSpeedVelocity() override { return 40 - 2 * num_of_coconuts_; }
  BirdType type() override { return BirdType::AfricanSwallow; }
};

class NorwegianBlueParrot : public Bird {
 public:
  NorwegianBlueParrot(const std::string& bname, int bnum, int bvoltage,
                      bool bnailed)
      : Bird(bname, bnum, bvoltage, bnailed) {}

  std::string Plumage() override {
    return voltage_ > 100 ? "scorched" : "beautiful";
  }

  int AirSpeedVelocity() override {
    return is_nailed_ ? 0 : 10 + voltage_ / 10;
  }

  BirdType type() override { return BirdType::NorwegianBlueParrot; }
};

std::unordered_map<std::string, std::string> plumages(
    const std::vector<std::shared_ptr<Bird>>& birds) {
  std::unordered_map<std::string, std::string> result{};
  std::for_each(birds.begin(), birds.end(),
                [&result](std::shared_ptr<Bird> bird) {
                  result[bird->name()] = bird->Plumage();
                });
  return result;
}

std::unordered_map<std::string, int> speed(
    const std::vector<std::shared_ptr<Bird>>& birds) {
  std::unordered_map<std::string, int> result{};
  std::for_each(birds.begin(), birds.end(),
                [&result](std::shared_ptr<Bird> bird) {
                  result[bird->name()] = bird->AirSpeedVelocity();
                });
  return result;
}

int main() {
  std::vector<std::shared_ptr<Bird>> birds{};
  birds.push_back(std::make_shared<EuropeanSwallow>("bird1", 200, 300, true));
  birds.push_back(std::make_shared<AfricanSwallow>("bird2", 200, 300, false));
  birds.push_back(
      std::make_shared<NorwegianBlueParrot>("bird3", 200, 300, true));

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