#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

//struct template; not class cuz you don't want it to store data
template <typename T>
struct CmpDes {
  bool operator() (T const& lhs, T const& rhs) const { return rhs < lhs; }
};

//function
template <typename T>
bool cmp_des(T const& lhs, T const& rhs) {
  return rhs < lhs;
}

int main() {
  std::vector<int> vi1{101, -11, 31, -21, 10};
  std::vector<int> vi2(std::begin(vi1), std::end(vi1));
  std::vector<int> vi3(std::begin(vi1), std::end(vi1));

  std::sort(vi1.begin(), vi1.end());
  std::copy(vi1.begin(), vi1.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";

  std::sort(vi2.begin(), vi2.end(), CmpDes<int>()); //cmp_des);
  std::copy(vi2.begin(), vi2.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";

  CmpDes<int> c1;
  std::cout << c1(10, 20) << "\n"; // c1.operator() (10, 20)
  std::cout << cmp_des(10, 20) << "\n"; // c1.operator() (10, 20)
  std::cout << c1(20, 10) << "\n";

  std::sort(vi3.begin(), vi3.end(), [](int lhs, int rhs) { return rhs < lhs; });
  std::copy(vi3.begin(), vi3.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";

}