#include <iostream>

// PRIYANSH MEHTA
// 20BCE2292

void MinMaxIterative(int arr[], int n){
    //std::cout << n << std::endl;
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    std::cout << "Max element using iterative function: " << max << std::endl;
    std::cout << "Min element using iterative function: " << min << std::endl;
}

void MinMaxDaC(int arr[], int l, int h, int &min, int &max){
    
    if (l == h){
        if (max < arr[l]) {
            max = arr[l];
        }
        if (min > arr[h]) {
            min = arr[h];
        }
        return;
    }
    
    if (h - l == 1){
        if (arr[l] < arr[h]){
            if (min > arr[l]){
                min = arr[l];
            }
            
            if (max < arr[h]) {
                max = arr[h];
            }
        }
        else {
            if (min > arr[h]) {
                min = arr[h];
            }
            
            if (max < arr[l]) {
                max = arr[l];
            }
        }
        return;
    }
    
    int mid = (l + h) / 2;
    MinMaxDaC(arr, l, mid, min, max);
    MinMaxDaC(arr, mid + 1, h, min, max);
}

int main() {
    int arr[] = {92, 4, 47, 8, 32, 13, 94, 97, 74, 52, 79, 17, 95, 67, 30, 35, 98, 93, 100, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    MinMaxIterative(arr,n);
    int max = INT_MIN, min = INT_MAX;
    MinMaxDaC(arr, 0, n - 1, min, max);
    
    std::cout << std::endl;
    std::cout << "The max array element using divide and conquer is " << min << std::endl;
    std::cout << "The min array element using divide and conquer is " << max << std::endl;
    return 0;
}
