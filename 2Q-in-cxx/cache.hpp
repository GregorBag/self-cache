#pragma once

#include <cmath>
#include <cstddef>
#include <list>
#include <unordered_map>

namespace caches {

template <typename T, typename KeyT = int> struct cache_t {
  using KeyList = std::list<KeyT>;
  using KeyIt = typename KeyList::iterator;

  enum class Queue {
    A1in,
    Am
  };

  struct Entry {
    T value;
    Queue queue;
    KeyIt position;
  };

  KeyList a1in_;
  KeyList a1out_;
  KeyList am_;
  
  std::unordered_map<KeyT, Entry> entries_;
  std::unordered_map<KeyT, KeyIt> history_;
  
  std::size_t capacity_;

  explicit cache_t(std::size_t capacity): capacity_(capacity) {}

  std::size_t capacity_Ain_ = capacity_ / 4;
  std::size_t capacity_Aout_ = capacity_ / 2;

  //end of data structures
};

}