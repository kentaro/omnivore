#ifndef OMNIVORE_STORAGE_TOKYOCABINET_H
#define OMNIVORE_STORAGE_TOKYOCABINET_H

#include <tcadb.h>
#include "storage.h"

namespace Omnivore {
  namespace Storage {
    class TokyoCabinet : public Omnivore::Storage::Base<TCADB> {
   public:
      TokyoCabinet  () {};
      ~TokyoCabinet () {};

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
