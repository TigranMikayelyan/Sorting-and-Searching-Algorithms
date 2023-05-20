#include <iostream>
#include <vector>

int binary_search(std::vector<int>&, int);

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
    std::cout << "Index of the number = " << binary_search(arr, num) << std::endl; 
}

int binary_search(std::vector<int>& arr, int key)
{
    int first = 0;
    int last = arr.size();
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            last = mid - 1;
        }
        if (arr[mid] < key)
        {
            first = mid + 1;
        }
    }
    return -1;
}

// space complexity = O(1)
// run-time complexity = O(log n)