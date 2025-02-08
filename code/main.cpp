#include <climits>
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& v)
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

void selection_sort(std::vector<int>& v)
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

void stalin_sort(std::vector<int>& v)
{
  // remove elements that are not in order
  // basically just send them to gulag, hence the name of the joke sorting algorithm :)
  int n = v.size();
  for (int i = 0; i < v.size() - 1;)
  {
    if (v[i + 1] < v[i])
    {
      v.erase(v.begin() + i + 1);
    }
    else
    {
      i++;
    }
  }
}

void optimized_stalin_sort(std::vector<int>& v)
{
  // to avoid the complexity of std::erase we can directly construct the final vector
  int n = v.size();
  std::vector<int> sorted;
  sorted.push_back(v[0]);
  for (auto& e : v)
  {
    if (e > sorted.back())
    {
      sorted.push_back(e);
    }
  }
  v = sorted;
}

int main()
{
  std::vector<int> v = {-8, 1, 2, -5, 13, -9};
  // bubble_sort(v);
  // selection_sort(v);
  // stalin_sort(v);
  optimized_stalin_sort(v);

  for (auto& e : v)
  {
    std::cout << e << " ";
  }

  std::cout << "\n";
  return 0;
}