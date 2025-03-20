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

class SpeciesDelegate;
class Bird {
 public:
  Bird(const Data& data) : name_(data.name) {
    species_ = SelectSpeciesDelegate(data);
  }
  ~Bird() = default;

  std::string name() { return name_; }
  std::string plumage();
  int AirSpeedVelocity();

 private:
  std::shared_ptr<SpeciesDelegate> SelectSpeciesDelegate(const Data& data);

  std::shared_ptr<SpeciesDelegate> species_;
  std::string name_;
};

class SpeciesDelegate {
 public:
  SpeciesDelegate(const Data& data, Bird* bird)
      : bird_(bird), plumage_(data.plumage) {}
  ~SpeciesDelegate() = default;

  virtual int AirSpeedVelocity() { return -1; };
  virtual std::string plumage() {
    return plumage_.empty() ? "average" : plumage_;
  }

 protected:
  Bird* bird_;
  std::string plumage_;
};

class EuropeanSwallowDelegate : public SpeciesDelegate {
 public:
  EuropeanSwallowDelegate(const Data& data, Bird* bird)
      : SpeciesDelegate(data, bird) {};
  ~EuropeanSwallowDelegate() = default;
  int AirSpeedVelocity() override { return 35; }
};

class AfricanSwallowDelegate : public SpeciesDelegate {
 public:
  AfricanSwallowDelegate(const Data& data, Bird* bird)
      : SpeciesDelegate(data, bird),
        number_of_coconuts_(data.number_of_coconuts) {}
  ~AfricanSwallowDelegate() = default;

  int AirSpeedVelocity() override { return 40 - 2 * number_of_coconuts_; }

 private:
  int number_of_coconuts_;
};

class NorwegianBlueParrotDelegate : public SpeciesDelegate {
 public:
  NorwegianBlueParrotDelegate(const Data& data, Bird* bird)
      : SpeciesDelegate(data, bird),
        voltage_(data.voltage),
        is_nailed_(data.is_nailed) {}
  ~NorwegianBlueParrotDelegate() = default;

  std::string plumage() override {
    if (voltage_ > 100) {
      return "scorched";
    } else {
      return plumage_.empty() ? "beautiful" : plumage_;
    }
  }

  int AirSpeedVelocity() override {
    return is_nailed_ ? 0 : 10 + voltage_ / 10;
  }

 private:
  int voltage_;
  bool is_nailed_;
};

std::string Bird::plumage() { return species_->plumage(); }

int Bird::AirSpeedVelocity() { return species_->AirSpeedVelocity(); }

std::shared_ptr<SpeciesDelegate> Bird::SelectSpeciesDelegate(const Data& data) {
  switch (data.type) {
    case BirdType::EuropeanSwallow:
      return std::make_shared<EuropeanSwallowDelegate>(data, this);
    case BirdType::AfricanSwallow:
      return std::make_shared<AfricanSwallowDelegate>(data, this);
    case BirdType::NorwegianBlueParrot:
      return std::make_shared<NorwegianBlueParrotDelegate>(data, this);
    default:
      throw std::runtime_error("Undefined bird type");
  }
}

std::shared_ptr<Bird> CreateBird(const Data& data) {
  return std::make_shared<Bird>(data);
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