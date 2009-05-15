#include "luxio.h"
#include "util.h"

bool Omnivore::Storage::LuxIO::open (std::string name) {
  Lux::IO::Btree* db = new Lux::IO::Btree(Lux::IO::NONCLUSTER);
  if (!db) return false;
  if (!db->open(name, Lux::IO::DB_CREAT)) return false;
  _storage = db;
  return true;
}

bool Omnivore::Storage::LuxIO::close () {
  return _storage->close();
}

void Omnivore::Storage::LuxIO::free () {
  return delete _storage;
}

Omnivore::Storage::data_t
Omnivore::Storage::LuxIO::get (const void *key, int key_size) {
  Lux::IO::data_t *value = _storage->get(key, key_size);
  Omnivore::Storage::data_t result;
  if (value != NULL) {
    result.data = Omnivore::duplicate_memory(value->data, value->size);
    result.size = value->size;
  }
  else {
    result.data = NULL;
    result.size = 0;
  }
  _storage->clean_data(value);
  return result;
}

bool Omnivore::Storage::LuxIO::put (const void *key, int key_size, const void *value, int value_size) {
  return _storage->put(key, key_size, value, value_size);
}

bool Omnivore::Storage::LuxIO::del (const void *key, int key_size) {
  return _storage->del(key, key_size);
}
