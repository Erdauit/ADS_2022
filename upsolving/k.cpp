#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int n;
  cin >> n;
  deque<int> dq;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if (x == 1)
    {
      int c;
      cin >> c;
      if (cnt % 2 == 0)
      {
        dq.push_back(c);
      }
      else
      {
        dq.push_front(c);
      }
    }
    else if (x == 2)
    {
      cnt += 1;
    }
  }

  if (cnt % 2 == 0)
  {
    while (!dq.empty())
    {
      cout << dq.front() << " ";
      dq.pop_front();
    }
  }
  else if (cnt % 2 == 1)
  {
    while (!dq.empty()){
      cout << dq.back() << " ";
      dq.pop_back();
    }
  }
}