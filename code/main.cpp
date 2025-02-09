#include <sys/time.h>

#include <algorithm>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <random>
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

void insertion_sort(std::vector<int>& v)
{
  int n = v.size();
  for (int i = 1; i < n; ++i)
  {
    int tmp = v[i];
    int cInd = i;
    while (cInd > 0 && tmp < v[cInd - 1])
    {
      v[cInd] = v[cInd - 1];
      cInd--;
    }
    v[cInd] = tmp;
  }
}

bool is_sorted(std::vector<int>& v)
{
  int n = v.size();
  for (int i = 1; i < n; i++)
  {
    if (v[i] < v[i - 1])
    {
      return false;
    }
  }
  return true;
}

void random_swap_sort(std::vector<int>& v)
{
  static bool is_seeded = false;

  int n = v.size();

  if (is_seeded == false)
  {
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    srand(tv.tv_usec);
    is_seeded = true;
  }

  while (!is_sorted(v))
  {
    int index1 = rand() % n;
    int index2 = rand() % n;

    while (index1 == index2)
    {
      index2 = rand() % n;
    }
    std::swap(v[index1], v[index2]);
  }
}

// monkey sort, also known as bogosort
void monkey_sort(std::vector<int>& v)
{
  std::random_device rd;
  std::mt19937 rng(rd());

  while (is_sorted(v) == false)
  {
    std::shuffle(v.begin(), v.end(), rng);
  }
}

void measure_sort_time(std::vector<int>& v, void (*sorting_function)(std::vector<int>&), std::string name = "Unknown name")
{
  auto start = std::chrono::high_resolution_clock::now();
  sorting_function(v);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;
  std::cout << "Sorting with " << name << " took " << duration.count() << " milliseconds." << std::endl;
}

int main()
{
  std::vector<int> v = {26, 53, 61, 5, 67, 90, 23, -24, 35, -71};
  std::vector<int> testVector = v;
  // bubble_sort(v);
  // selection_sort(v);
  // stalin_sort(v);
  // optimized_stalin_sort(v);
  // insertion_sort(v);
  // random_swap_sort(v);
  // insertion_sort(v);

  measure_sort_time(testVector, monkey_sort, "Monkey Sort");
  testVector = v;
  measure_sort_time(testVector, bubble_sort, "Bubble Sort");

  for (auto& e : testVector)
  {
    std::cout << e << " ";
  }

  std::cout << "\n";
  return 0;
}