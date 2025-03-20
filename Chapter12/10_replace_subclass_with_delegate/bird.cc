#include <iostream>
#include <memory>
#include <string>

enum class BirdType {
  EuropeanSwallow = 0,
  AfricanSwallow,
  NorwegianBlueParrot
};

struct Data {
  Data(std::string bname, std::string bplumage, BirdType btype, int bnumber,
       int bvoltage, bool bnailed)
      : name(bname),
        plumage(bplumage),
        type(btype),
        number_of_coconuts(bnumber),
        voltage(bvoltage),
        is_nailed(bnailed) {}

  std::string name;
  std::string plumage;
  BirdType type;
  int number_of_coconuts;
  int voltage;
  bool is_nailed;
};

class Bird {
 public:
  Bird(const Data& data) : name_(data.name), plumage_(data.plumage) {}
  ~Bird() = default;

  std::string name() { return name_; }
  virtual std::string plumage() {
    return plumage_.empty() ? "average" : plumage_;
  }
  virtual int AirSpeedVelocity() { return -1; };

 private:
  std::string name_;
  std::string plumage_;
};

class EuropeanSwallow : public Bird {
 public:
  EuropeanSwallow(const Data& data) : Bird(data) {}
  ~EuropeanSwallow() = default;
  int AirSpeedVelocity() override { return 35; }
};

class AfricanSwallow : public Bird {
 public:
  AfricanSwallow(const Data& data)
      : Bird(data), number_of_coconuts_(data.number_of_coconuts) {}

  int AirSpeedVelocity() override { return 40 - 2 * number_of_coconuts_; }

 private:
  int number_of_coconuts_;
};

class NorwegianBlueParrot : public Bird {
 public:
  NorwegianBlueParrot(const Data& data)
      : Bird(data), voltage_(data.voltage), is_nailed_(data.is_nailed) {}

  std::string plumage() override {
    if (voltage_ > 100) {
      return "scorched";
    } else {
      return Bird::plumage().empty() ? "beautiful" : Bird::plumage();
    }
  }

  int AirSpeedVelocity() override {
    return is_nailed_ ? 0 : 10 + voltage_ / 10;
  }

 private:
  int voltage_;
  bool is_nailed_;
};

std::shared_ptr<Bird> CreateBird(Data data) {
  switch (data.type) {
    case BirdType::EuropeanSwallow:
      return std::make_shared<EuropeanSwallow>(data);
    case BirdType::AfricanSwallow:
      return std::make_shared<AfricanSwallow>(data);
    case BirdType::NorwegianBlueParrot:
      return std::make_shared<NorwegianBlueParrot>(data);
    default:
      return std::make_shared<Bird>(data);
  }
}

int main() {
  Data eur_data("eur_bird", "plumage", BirdType::EuropeanSwallow, 4, 10, true);
  std::shared_ptr<Bird> eur = CreateBird(eur_data);
  std::cout << eur->name() << ", " << eur->AirSpeedVelocity() << std::endl;

  Data afr_data("afr_bird", "plumage", BirdType::AfricanSwallow, 4, 10, true);
  std::shared_ptr<Bird> afr = CreateBird(afr_data);
  std::cout << afr->name() << ", " << afr->AirSpeedVelocity() << std::endl;

  Data nor_data("nor_bird", "plumage", BirdType::NorwegianBlueParrot, 4, 10,
                true);
  std::shared_ptr<Bird> nor = CreateBird(nor_data);
  std::cout << nor->name() << ", " << nor->AirSpeedVelocity() << std::endl;

  return 0;
}