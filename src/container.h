#ifndef OMNIVORE_CONTAINER_H
#define OMNIVORE_CONTAINER_H

#include <map>

namespace Omnivore {
  template<class T>
      class Container {
 public:
    Container  () {};
    ~Container () {};
 private:
    std::map _container;
  };
};

#endif
