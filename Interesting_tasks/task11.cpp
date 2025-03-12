#include <iostream>

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int N;
    std::cout << "Enter number of cities: ";
    std::cin >> N;

    int* x_coords = new int[N];
    int* y_coords = new int[N];

    std::cout << "Enter city coordinates (x, y): \n";
    for (int i = 0; i < N; ++i) {
        std::cin >> x_coords[i] >> y_coords[i];
    }

    bubble_sort(x_coords, N);
    bubble_sort(y_coords, N);

    int median_x = x_coords[N / 2];
    int median_y = y_coords[N / 2];

    std::cout << "Capital coordinates: (" << median_x << ", " << median_y << ")\n";

    delete[] x_coords;
    delete[] y_coords;
    
    return 0;
}
