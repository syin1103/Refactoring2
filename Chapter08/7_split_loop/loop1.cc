#include <iostream>
#include <vector>

struct People {
  int age = 30;
  int salary = 100;
};

int YoungestAge(const std::vector<People>& people) {
  int youngest = people.empty() ? INT32_MAX : people[0].age;
  for (const auto& p : people) {
    if (p.age < youngest) {
      youngest = p.age;
    }
  }
  return youngest;
}

int TotalSalaryAge(const std::vector<People>& people) {
  int total_salary = 0;
  for (const auto& p : people) {
    total_salary += p.salary;
  }
  return total_salary;
}

int main() {
  std::vector<People> people(10, People());
  int youngest = YoungestAge(people);
  int total_salary = TotalSalaryAge(people);
  std::cout << youngest << ", " << total_salary << std::endl;
  return 0;
}