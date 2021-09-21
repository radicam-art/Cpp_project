#include <cmath>
#include <iostream>
using namespace std;
 
int main()
{
  unsigned long long a;
  int count = 0;
  
  cin >> a;
  if (a < 0)
  {
      cout << 0 << endl;
      return 0;
  }
  //cout << a << endl;
  while (pow(2, count) <= a)
  {
    count++;
  }
  
  cout << count - 1 << endl;
}