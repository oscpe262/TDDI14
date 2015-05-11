#include<iostream>
#include<string>
template<typename T>
class Wrapper {
public:
  Wrapper(const T& = T() ) : value_{value} {}
  void set_value(const T& value) { value_ = value;  }
  T get_value() const { return value_; }
private:
  T value_;
};
template<typename T>
ostream& operator<<(ostream& os, const Wrapper<T>&)
{
  return os << w.get_value() << endl;
}

template<typename T>
istream& operator>>(istream& is, Wrapper<T>& w)
{
  T temp;
  is >> temp;
  w.set_value(temp);
  return is;
}

int main() {
  Wrapper<int> w {"Hejsan"};
  string temp;
  cout << w << endl;
  cin >> w;
  return 0;
}
