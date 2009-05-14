#ifndef OMNIVORE_STORAGE_LUXIO_H
#define OMNIVORE_STORAGE_LUXIO_H

#include <luxio/btree.h>
#include "storage.h"

namespace Omnivore {
  namespace Storage {
    class LuxIO : public Omnivore::Storage::Base<Lux::IO::Btree *> {
      Lux::IO::Btree *_storage;
   public:
      LuxIO  () {};
      ~LuxIO () {};

      bool open  (std::string name);
      bool close ();
      Omnivore::Storage::data_t *
           get   (const void *key, int key_size);
      bool put   (const void *key, int key_size, const void *value, int value_size);
      bool del   (const void *key, int key_size);
      void free  ();
    };
  }
}

#endif
