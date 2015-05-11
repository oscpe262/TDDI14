#include<vector>
#include<iterator>
#include<algorithm>
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

template<typename T>
ostream& operator<<(ostream& os, const vectorr<T>& vt)
{
  copy(vt.cbegin(), vt.cent(), ostream_iterator<T>{os, " "} );
  return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& vt)
{
  copy(istream_iterator<T>{is},
       istream_iterator<T>{},
       back_inserter(vt));
  return is;
}

int main() {
  Wrapper<int> w {"Hejsan"};
  string temp;
  cout << w << endl;
  cin >> w;
  Wrapper<vector<int>> wv;
  cout << wv;
  return 0;
}

// x hemläxa
