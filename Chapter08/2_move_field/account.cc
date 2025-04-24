#include <iostream>
#include <string>

class AccountType {
 public:
  AccountType(const std::string& name) : name_(name) {}

 private:
  std::string name_;
};

class Account {
 public:
  Account(const std::string& name, AccountType type, double rate)
      : name_(name), type_(type), interest_rate_(rate) {}
  double interest_rate() { return interest_rate_; }

 private:
  std::string name_;
  AccountType type_;
  double interest_rate_;
};

int main() {
  AccountType account_type("type");
  Account account("account", account_type, 0.3);
  std::cout << account.interest_rate() << std::endl;
  return 0;
}