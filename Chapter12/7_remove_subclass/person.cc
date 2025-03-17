#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class GenderType { M = 0, F, X };

class Person {
 public:
  Person(std::string name) : name_(name) {}
  ~Person() = default;

  virtual GenderType GenderCode() { return GenderType::X; }
  std::string name() { return name_; }

 private:
  std::string name_;
};
using PersonPtr = std::shared_ptr<Person>;

class Male : public Person {
 public:
  Male(std::string name) : Person(name) {}
  ~Male() = default;
  GenderType GenderCode() override { return GenderType::M; }
};

class Female : public Person {
 public:
  Female(std::string name) : Person(name) {}
  ~Female() = default;
  GenderType GenderCode() override { return GenderType::F; }
};

struct Record {
  std::string name;
  GenderType gender;
};

std::vector<PersonPtr> LoadFromData(const std::vector<Record>& data) {
  std::vector<PersonPtr> result;
  for (const Record& record : data) {
    PersonPtr p = nullptr;
    switch (record.gender) {
      case GenderType::M:
        p = std::make_shared<Male>(record.name);
        break;
      case GenderType::F:
        p = std::make_shared<Female>(record.name);
        break;
      default:
        p = std::make_shared<Person>(record.name);
        break;
    }
    result.push_back(p);
  }
  return result;
}

int main() {
  std::vector<Record> data{{"John", GenderType::M},
                           {"Lucy", GenderType::F},
                           {"Unknown", GenderType::X}};
  std::vector<PersonPtr> result = LoadFromData(data);

  for (PersonPtr person : result) {
    std::cout << person->name() << ", "
              << static_cast<int>(person->GenderCode()) << std::endl;
  }

  return 0;
}