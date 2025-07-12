#include <iostream>
#include <string>

struct Photo {
  Photo(std::string t, std::string d, std::string l)
      : title(t), date(d), location(l) {}
  std::string title;
  std::string date;
  std::string location;
};

struct Person {
  Person(std::string n, std::string l, Photo p)
      : name(n), location(l), photo(p) {}
  std::string name;
  std::string location;
  Photo photo;
};

void RenderPhoto(Photo photo) { std::cout << "Render photo..." << std::endl; }

void EmitPhotoData(Photo photo) {
  std::cout << photo.title << std::endl;
  std::cout << photo.date << std::endl;
}

void RenderPerson(Person person) {
  std::cout << person.name << std::endl;
  RenderPhoto(person.photo);
  EmitPhotoData(person.photo);
  std::cout << person.photo.location << std::endl;
}

int main() {
  Photo photo("person-title", "20250520", "China");
  Person person("Jack", "China", photo);
  RenderPerson(person);

  return 0;
}