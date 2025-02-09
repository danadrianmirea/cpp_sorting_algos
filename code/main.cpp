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

// merges two already sorted vectors
void merge(std::vector<int>& v, int left, int mid, int right)
{
  int n1 = (mid - left) + 1;
  int n2 = (right - mid);

  std::vector<int> leftVector(n1);
  std::vector<int> rightVector(n2);

  for (int i = 0; i < n1; ++i)
  {
    leftVector[i] = v[left+i];
  }

  for (int i = 0; i < n2; ++i)
  {
    rightVector[i] = v[mid+i+1];
  }

  int leftIndex = 0;
  int rightIndex = 0;
  int cIndex = left;

  while (leftIndex < n1 && rightIndex < n2)
  {
    if (leftVector[leftIndex] < rightVector[rightIndex])
    {
      v[cIndex] = v[leftIndex];
      leftIndex++;
      cIndex++;
    }
    else
    {
      v[cIndex] = v[rightIndex];
      rightIndex++;
      cIndex++;
    }
  }

  while (leftIndex < n1)
  {
    v[cIndex] = leftVector[leftIndex];
    leftIndex++;
    cIndex++;
  }

  while (rightIndex < n2)
  {
    v[cIndex] = rightVector[rightIndex];
    rightIndex++;
    cIndex++;
  }
}

// recursively split the array and merge the bits
void merge_sort(std::vector<int>& v, int left, int right)
{
  int mid = (right-left)/2;
  if (left < right)
  {
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    merge(v, left, mid, right);
  }
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
  merge_sort(testVector, 0, v.size()-1);

  //measure_sort_time(testVector, monkey_sort, "Monkey Sort");
  //testVector = v;
  //measure_sort_time(testVector, bubble_sort, "Bubble Sort");
  //testVector = v;
  //measure_sort_time(testVector, merge_sort, "Bubble Sort");

  for (auto& e : testVector)
  {
    std::cout << e << " ";
  }

  std::cout << "\n";
  return 0;
}