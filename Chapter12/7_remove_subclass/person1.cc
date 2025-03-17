#include <iostream>
#include <memory>
#include <string>
#include <vector>

enum class GenderType { M = 0, F, X };

class Person {
 public:
  Person(std::string name, GenderType gender)
      : name_(name), gender_code_(gender) {}
  ~Person() = default;

  virtual GenderType GenderCode() { return gender_code_; }
  std::string name() { return name_; }

 private:
  GenderType gender_code_;
  std::string name_;
};
using PersonPtr = std::shared_ptr<Person>;

struct Record {
  std::string name;
  GenderType gender;
};

PersonPtr CreatePerson(const Record& record) {
  switch (record.gender) {
    case GenderType::M:
      return std::make_shared<Person>(record.name, GenderType::M);
    case GenderType::F:
      return std::make_shared<Person>(record.name, GenderType::F);
    default:
      return std::make_shared<Person>(record.name, GenderType::X);
  }
}

std::vector<PersonPtr> LoadFromData(const std::vector<Record>& data) {
  std::vector<PersonPtr> result;
  for (const Record& record : data) {
    result.push_back(CreatePerson(record));
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