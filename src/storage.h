#ifndef OMNIVORE_STORAGE_H
#define OMNIVORE_STORAGE_H

#include <string>

namespace Omnivore {
  namespace Storage {
    typedef struct {
      const void *data;
      int size;
    } data_t;

    template <class T>
    class Base {
      T _storage;

   public:
      Base () {};
      virtual ~Base () {};

      virtual bool open  (std::string name) = 0;
      virtual bool close () = 0;
      virtual Omnivore::Storage::data_t *
                   get   (const void *key, int key_size) = 0;
      virtual bool put   (const void *key, int key_size, const void *value, int value_size) = 0;
      virtual bool del   (const void *key, int key_size) = 0;
      virtual void free  () = 0;
    };
  }
}

#endif
