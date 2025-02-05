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

void stalin_sort(std::vector<int> &vec)
{
  for (int i = 0; i < vec.size() - 1;)
  {
    if (vec[i + 1] < vec[i])
    {
      vec.erase(vec.begin() + i + 1);
    }
    else
    {
      ++i;
    }
  }
}

int main()
{
  std::vector<int> v = {2, 5, -2, 55, -7};
  // stalin_sort(v);
  bubble_sort(v);

  for (auto &e : v)
  {
    std::cout << e << " ";
  }

  std::cout << "\n";
  return 0;
}