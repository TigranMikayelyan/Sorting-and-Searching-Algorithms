#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>&);
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
    insertion_sort(arr);
    std::cout << "Array after sorting" << std::endl;
    print(arr);
}

void insertion_sort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int tmp = arr[i];
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > tmp)
            {
                arr[j + 1] = arr[j];
                arr[j] = tmp;
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

// space complexity = O(1)
// run-time complexity = O(n^2)