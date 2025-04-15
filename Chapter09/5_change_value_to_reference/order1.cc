#include <iostream>
#include <memory>
#include <unordered_map>

struct Data {
  Data(int n = 0, int i = 0) : number(n), id(i) {}
  int number;
  int id;
};

class Customer {
 public:
  Customer(int id) : id_(id) {}
  int id() { return id_; }

 private:
  int number_;
  int id_;
};

class RepositoryData {
 public:
  static std::shared_ptr<Customer> RegisterCustomer(int id) {
    if (repo_.find(id) == repo_.end()) {
      repo_[id] = std::make_shared<Customer>(id);
    }
    return repo_[id];
  }

  static std::shared_ptr<Customer> FindCustomer(int id) {
    if (repo_.find(id) == repo_.end()) {
      return nullptr;
    }
    return repo_[id];
  }

 private:
  static std::unordered_map<int, std::shared_ptr<Customer>> repo_;
};

std::unordered_map<int, std::shared_ptr<Customer>> RepositoryData::repo_{};

class Order {
 public:
  Order(Data data) : number_(data.number) {
    customer_ = RepositoryData::RegisterCustomer(data.id);
  }
  std::shared_ptr<Customer> customer() { return customer_; }
  int number() { return number_; }

 private:
  int number_;
  std::shared_ptr<Customer> customer_;
};

int main() {
  Data data(20, 30);
  Order order(data);

  auto customer = order.customer();
  std::cout << order.number() << "," << customer->id() << std::endl;
  return 0;
}