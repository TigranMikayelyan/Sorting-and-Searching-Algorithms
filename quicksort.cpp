#include <iostream>
#include <vector>

int partition(std::vector<int>&, int, int);
void quick_sort(std::vector<int>&, int, int);
void print(std::vector<int>&);

int main()
{
    int size = 0;
    std::cout << "Enter the size" << std::endl;
    std::cin >> size;
    std::vector<int> arr(size);
    std::cout << "Enter the array" << std::endl;
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    std::cout << "Array before sorting" << std::endl;
    print(arr);
    quick_sort(arr, 0, arr.size() - 1);
    std::cout << "Array after sorting" << std::endl;
    print(arr);
}

int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    ++i;
    std::swap(arr[i], arr[high]);
    return i;
}

void quick_sort(std::vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void print(std::vector<int>& arr)
{
    for (auto i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// space complexity = O(log n)
// run-time complexity = O(n^2) in Worst case, O(n log n) in Average case