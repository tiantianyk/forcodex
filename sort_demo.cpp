#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

// 原始数据
int data[] = {42, 7, 19, 88, 3, 66, 25, 91, 14, 53};
const int N = sizeof(data) / sizeof(data[0]);

void print_array(const std::string& label, int arr[], int n) {
    std::cout << label << ": ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : ", ");
    }
    std::cout << std::endl;
}

int main() {
    // 拷贝三份分别用不同方式排序
    int a1[N], a2[N], a3[N];
    std::copy(data, data + N, a1);
    std::copy(data, data + N, a2);
    std::copy(data, data + N, a3);

    print_array("原始数组", data, N);

    // 方式一：STL sort，升序
    std::sort(a1, a1 + N);
    print_array("升序排列", a1, N);

    // 方式二：STL sort，降序
    std::sort(a2, a2 + N, std::greater<int>());
    print_array("降序排列", a2, N);

    // 方式三：快速排序（手写递归实现）
    auto quick_sort = [](auto& self, int arr[], int low, int high) -> void {
        if (low >= high) return;
        int pivot = arr[high];      // 选最后一个元素为基准
        int i = low;
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                std::swap(arr[i], arr[j]);
                ++i;
            }
        }
        std::swap(arr[i], arr[high]);
        self(self, arr, low, i - 1);
        self(self, arr, i + 1, high);
    };
    quick_sort(quick_sort, a3, 0, N - 1);
    print_array("快速排序", a3, N);
    int b;

    return 0;
}
