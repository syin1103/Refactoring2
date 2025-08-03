#include <iostream>
#include <string>
#include <unordered_map>

using LinesMap = std::unordered_map<std ::string, std::string>;

struct Customer {
  Customer(const std::string& cname, const std::string& cloc)
      : name(cname), location(cloc) {}
  ~Customer() {}

  std::string name;
  std::string location;
};

// void GatherCustomerData(LinesMap& out, const Customer& customer) {
//   out.insert({"name", customer.name});
//   out.insert({"location", customer.location});
// }

LinesMap ReportLines(const Customer& customer) {
  LinesMap lines{};
  lines.insert({"name", customer.name});
  lines.insert({"location", customer.location});

  return lines;
}

int main() {
  Customer customer("Jack", "China");

  LinesMap lines = ReportLines(customer);
  for (const auto& pair : lines) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}