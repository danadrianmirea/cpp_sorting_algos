#include <climits>
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

void selection_sort(std::vector<int> &v)
{
  int startIndex = 0;
  int n = v.size();
  int minIndex;

  for (int startIndex = 0; startIndex < n - 1; ++startIndex)
  {
    // select smallest item
    minIndex = startIndex;
    for (int i = startIndex + 1; i < n; ++i)
    {
      if (v[i] < v[minIndex])
      {
        minIndex = i;
      }
    }

    // put it at the start
    if (startIndex != minIndex)
    {
      std::swap(v[startIndex], v[minIndex]);
    }
  }
}

int main()
{
  std::vector<int> v = {2, 5, -2, 55, -7};
  selection_sort(v);

  for (auto &e : v)
  {
    std::cout << e << " ";
  }

  std::cout << "\n";
  return 0;
}