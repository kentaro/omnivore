#include "../src/luxio.h"
#include <string>
#include <iostream>

int main () {
  std::string key("foo");
  std::string value("bar");
  Omnivore::Storage::LuxIO *db = new Omnivore::Storage::LuxIO();

  db->open("test");
  db->put(key.c_str(), key.length(), value.c_str(), value.length());
  Omnivore::Storage::data_t *result = db->get(key.c_str(), key.length());
  std::cout << "key: " << key << std::endl;
  std::cout << "val: " << result->data << std::endl;
  db->close();
  db->free();

  return 0;
}
