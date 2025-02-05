#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &v) 
{
  int n = v.size();

  for (int end = n - 1; end > 0; end--) 
  {
    for (int j = 0; j < end; j++) 
    {
      if (v[j] > v[j + 1]) 
      {
        std::swap(v[j], v[j + 1]);
      }
    }
  }
}

int main() 
{
  std::vector<int> v = {55, -43, 1, 9, -2};
  bubble_sort(v);

  for (auto &e : v) 
  {
    std::cout << e << " ";
  }

  std::cout << "\n";
  return 0;
}