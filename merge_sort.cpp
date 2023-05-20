#include <iostream>
#include <vector>

void merge_sort(std::vector<int>&, int, int);
void merge(std::vector<int>&, int, int, int);
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
    merge_sort(arr, 0, arr.size() - 1);
    std::cout << "Array after sorting" << std::endl;
    print(arr);
}

void merge_sort(std::vector<int>& arr, int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void merge(std::vector<int>& arr, int first, int mid, int last)
{
    int start1 = first;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = last;
    int index = 0;
    std::vector<int> tmp(last);
    while (start1 <= end1 && start2 <= end2)
    {
        if (arr[start1] <= arr[start2])
        {
            tmp[index++] = arr[start1++];
        }
        else
        {
            tmp[index++] = arr[start2++];
        }
    }
    while (start1 <= end1)
    {
        tmp[index++] = arr[start1++];
    }
    while (start2 <= end2)
    {
        tmp[index++] = arr[start2++];
    }
    for (int i = first; i <= last; ++i)
    {
        arr[i] = tmp[i - first];
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

// space complexity = O(n)
// run-time complexity = O(n log n)