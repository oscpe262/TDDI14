#include "Name.h"

void Name::swap(Name& other) noexcept {
  std::swap(fname_, other.fname_);
}
