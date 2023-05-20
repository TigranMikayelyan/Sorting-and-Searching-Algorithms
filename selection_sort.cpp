#include <iostream>
#include <vector>

void selection_sort(std::vector<int>&);
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
    selection_sort(arr);
    std::cout << "Array after sorting" << std::endl;
    print(arr);
}

void selection_sort(std::vector<int>& arr)
{
    int min_index = 0;
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        min_index = i;
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
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

// space complexity = O(1)
// run-time complexity = O(n^2)