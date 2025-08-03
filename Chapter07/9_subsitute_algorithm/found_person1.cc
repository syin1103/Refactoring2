#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::string FoundPerson(const std::vector<std::string>& people) {
  std::unordered_set<std::string> candidates{"Don", "John", "Kent"};
  auto it =
      std::find_if(people.begin(), people.end(), [&](const std::string& p) {
        return candidates.find(p) != candidates.end();
      });

  return it != people.end() ? *it : "";
}

int main() {
  std::vector<std::string> people{"Jack", "Tom", "Kent"};
  std::cout << FoundPerson(people) << std::endl;
  return 0;
}