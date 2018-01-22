#include <iostream>
using namespace std;

void SwapWithRef(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main(void) {
  int a, b;
  cin >> a >> b;
  SwapWithRef(a, b);
  cout << a << ' ' << b << endl;
  return 0;
}