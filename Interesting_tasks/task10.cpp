#include <iostream>

void find_magical_arrays_helper(int arr[], int index, int N, int sum, int product, int last) {
    if (index == N) {
        if (sum == product) {
            for (int i = 0; i < N; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    
    for (int num = last; num <= 10; num++) {
        arr[index] = num;
        find_magical_arrays_helper(arr, index + 1, N, sum + num, product * num, num);
    }
}

void find_magical_arrays(int N) {
    int arr[N];
    find_magical_arrays_helper(arr, 0, N, 0, 1, 1);
}

int main() {
    int N;
    std::cout << "Enter number of elements in magical array: ";
    std::cin >> N;
    
    find_magical_arrays(N);
    return 0;
}
