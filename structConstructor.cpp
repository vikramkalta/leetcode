#include <iostream>
using namespace std;
struct Student
{
  int roll;

  Student(int x)
  {
    roll = x;
  }
};

int main()
{
  struct Student s(2);
  cout << s.roll;
  return 0;
  // cout << "c.it" << p.item;
  // cout << "c.nm" << p.name;
}