#include <iostream>
#include <vector>

int binary_search(std::vector<int>&, int, int, int);

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
    int num = 0;
    std::cout << "Enter the number" << std::endl;
    std::cin >> num;
    std::cout << "Index of the number = " << binary_search(arr, num, 0, arr.size() - 1) << std::endl; 
}

int binary_search(std::vector<int>& arr, int key, int first, int last)
{
    if (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            return binary_search(arr, key, first, mid - 1);
        }
        if (arr[mid] < key)
        {
            return binary_search(arr, key, mid + 1, last);
        }
    }
    return -1;
}

// space complexity = O(1)
// run-time complexity = O(log n)