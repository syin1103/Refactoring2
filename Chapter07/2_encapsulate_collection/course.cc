#include <iostream>
#include <list>
#include <string>

class Course {
 public:
  Course(const std::string& name, bool is_advanced)
      : name_(name), is_advanced_(is_advanced) {}
  ~Course() {}

  std::string name() const { return name_; }
  bool is_advanced() const { return is_advanced_; }

 private:
  std::string name_;
  bool is_advanced_;
};

class Person {
 public:
  Person(const std::string& name) : name_(name) {}
  ~Person() {}

  std::string name() const { return name_; }
  std::list<Course>& courses() { return courses_; }
  void set_courses(const std::list<Course>& courses) { courses_ = courses; }

 private:
  std::string name_;
  std::list<Course> courses_{};
};

int main() {
  Course course1("Chinese", true);
  Course course2("Math", false);
  Course course3("English", false);
  std::list<Course> courses{course1, course2, course3};

  Person person("Tom");
  person.set_courses(courses);

  std::cout << person.name() << std::endl;
  for (const auto& course : person.courses()) {
    std::cout << course.name() << ", " << course.is_advanced() << std::endl;
  }

  return 0;
}