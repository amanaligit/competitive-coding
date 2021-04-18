#include <iostream>

int gcd(int a, int b) {
  if(!b)
    return a;
  else
    return gcd(b,a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  if (b > a)
  {
    int temp;
    temp= a;
    a= b;
    b=temp;
  }
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
