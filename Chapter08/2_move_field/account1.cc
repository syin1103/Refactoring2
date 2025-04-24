#include <iostream>
#include <string>

class AccountType {
 public:
  AccountType(const std::string& name, double rate)
      : name_(name), interest_rate_(rate) {}
  double interest_rate() { return interest_rate_; }

 private:
  std::string name_;
  double interest_rate_;
};

class Account {
 public:
  Account(const std::string& name, AccountType type)
      : name_(name), type_(type) {}
  double interest_rate() { return type_.interest_rate(); }

 private:
  std::string name_;
  AccountType type_;
  double interest_rate_;
};

int main() {
  AccountType account_type("type", 0.3);
  Account account("account", account_type);
  std::cout << account.interest_rate() << std::endl;
  return 0;
}