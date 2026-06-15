#include <iostream>
#include <algorithm>

// 原始数据
int data[] = {42, 7, 19, 88, 3, 66, 25, 91, 14, 53, 31, 77};
const int N = sizeof(data) / sizeof(data[0]);

void print_array(const std::string& label, int arr[], int n) {
    std::cout << label << ": ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : ", ");
    }
    std::cout << std::endl;
}

// 快速排序
void quick_sort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[i], arr[high]);
    quick_sort(arr, low, i - 1);
    quick_sort(arr, i + 1, high);
}

// 二分查找，返回目标值在有序数组中的位置，未找到返回 -1
int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[N];
    std::copy(data, data + N, arr);

    print_array("原始数组", arr, N);

    // 快速排序
    quick_sort(arr, 0, N - 1);
    print_array("排序后  ", arr, N);

    // 查找目标数字
    int targets[] = {25, 77, 100};
    for (int target : targets) {
        int pos = binary_search(arr, N, target);
        if (pos != -1)
            std::cout << "查找 " << target << " → 位置: " << pos << std::endl;
        else
            std::cout << "查找 " << target << " → 未找到" << std::endl;
    }

    return 0;
}
