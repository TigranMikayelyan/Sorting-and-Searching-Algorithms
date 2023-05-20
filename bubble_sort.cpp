#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>&);
void print(std::vector<int>&);

int main()
{
    int size = 0;
    std::cout << "Enter the size" << std::endl;
    std::cin >> size;
    std::vector<int> arr(size); // 8 2 4 7 1 3 9 6 5
    std::cout << "Enter the array" << std::endl;
    for (int i = 0; i < arr.size(); ++i)
    {
        std::cin >> arr[i];
    }
    std::cout << "Array before sorting" << std::endl;
    print(arr);
    bubble_sort(arr);
    std::cout << "Array after sorting" << std::endl;
    print(arr);
}

void bubble_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr.size() - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
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

// space complexity = O(n^2)
// run-time complexity = O(n^2)