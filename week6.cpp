#include <iostream>
using namespace std;

// Week 6 – Arrays, Binary Search, and Pointers
// ------------------------------------------


// ----------- FUNCTION: Binary Search -----------
int binarySearch(int arr[], int size, int target) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;  //中间位置

        if (arr[mid] == target) {
            return mid;    // 找到返回索引
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // 去右边找
        }
        else {
            right = mid - 1; // 去左边找
        }
    }

    return -1; // 没找到
}


// ----------- MAIN PROGRAM -----------
int main() {

    // 1. Arrays（数组）
    // ---------------------------
    int numbers[10] = {3, 5, 8, 12, 14, 18, 25, 27, 33, 40};
    int size = 10;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;


 
    // 2. Pointer example（指针示例）
    // ---------------------------
    int value = 99;
    int* ptr = &value;   // ptr 指向 value 的地址

    cout << "\nPointer Example:" << endl;
    cout << "Value = " << value << endl;
    cout << "Address stored in pointer = " << ptr << endl;
    cout << "Value accessed through pointer = " << *ptr << endl;



    // 3. Binary Search（重点）
    // ---------------------------
    int target;
    cout << "\nEnter a number to search: ";
    cin >> target;

    int position = binarySearch(numbers, size, target);

    if (position != -1) {
        cout << "Found " << target << " at index " << position << "!" << endl;
    }
    else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}