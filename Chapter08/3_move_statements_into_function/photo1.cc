#include <iostream>
#include <string>

struct Photo {
  Photo(const std::string& ititle, const std::string& iloc,
        const std::string& idate)
      : title(ititle), location(iloc), date(idate) {}

  std::string title;
  std::string location;
  std::string date;
};

struct Person {
  Person(const std::string& iname, Photo iphoto) : name(iname), photo(iphoto) {}
  std::string name;
  Photo photo;
};

std::string RenderPhoto(Photo photo) { return ""; }

std::string EmitPhotoData(Photo photo) {
  std::string result = "";
  result += ("<p> title: " + photo.title + "</p>");
  result += ("<p> location: " + photo.location + "</p>");
  result += ("<p> date: " + photo.date + "</p>");
  return result + "\n";
}

std::string PhotoDiv(Photo photo) {
  std::string result = EmitPhotoData(photo);
  return "<div>" + result + "</div>" + "\n";
}

std::string RenderPerson(Person person) {
  std::string result = "";
  result += ("<p>" + person.name + "</p>");
  result += RenderPhoto(person.photo);
  result += EmitPhotoData(person.photo);
  return result + "\n";
}

int main() {
  Photo photo("photo", "China", "20250101");
  Person person("person", photo);

  std::cout << RenderPerson(person) << std::endl;
  std::cout << PhotoDiv(person.photo) << std::endl;

  return 0;
}