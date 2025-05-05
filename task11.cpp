#include <iostream>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[i]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main() {
    const int max = 100;
    int x[max], y[max], N;

    std::cout << "Enter number of cities: ";
    std::cin >> N;

    if (N <= 0 || N > max) {
	    std::cout << "Incorrect N\n";
        return 1;
    }

    std::cout << "Enter coordinate of cities (x y):\n";
    for (int i = 0; i < N; ++i)
        std::cin >> x[i] >> y[i];

    sort(x, N);
    sort(y, N);

    int capital_x = x[N / 2];
    int capital_y = y[N / 2];

    std::cout << "Optimal coordinates of the capital: " << capital_x << " " << capital_y << "\n";

    return 0;
}
