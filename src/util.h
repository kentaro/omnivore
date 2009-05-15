#ifndef OMNIVORE_UTIL_H
#define OMNIVORE_UTIL_H

#include <cstdlib>

namespace Omnivore {
  void *duplicate_memory(const void *ptr, int size) {
    void *dupped;
    if (!(dupped = malloc(size))) return 0;
    memcpy(dupped, ptr, size);
    return dupped;
  }
}

#endif
