#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename T>
bool cmp_des(T const& lhs, T const& rhs) {
  return rhs < lhs;
}

template <typename T>
struct CmpDes {
  bool operator() (T const& lhs, T const& rhs) const { return rhs < lhs; }
};

int main() {
  //std::set<int, bool (*)(int const&, int const&)> si(cmp_des<int>);
  std::set<int, CmpDes<int>> si(CmpDes<int>{});
  si.insert(-101); si.insert(-11); si.insert(31); si.insert(-21); si.insert(10);

  std::vector<int> vi(si.begin(), si.end());
  std::copy(std::begin(vi), std::end(vi), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}