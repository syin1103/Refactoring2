#include <iostream>
#include <vector>

struct People {
  int age = 30;
  int salary = 100;
};

int main() {
  std::vector<People> people(10, People());
  int youngest = people.empty() ? INT32_MAX : people[0].age;
  int total_salary = 0;
  for (const auto& p : people) {
    if (p.age < youngest) {
      youngest = p.age;
    }
    total_salary += p.salary;
  }

  std::cout << youngest << ", " << total_salary << std::endl;
  return 0;
}