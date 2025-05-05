#include <iostream>

const int max_n = 10; 
int vec[max_n];

void fmv(int n, int index, int start, int sum, int product) { // fmv - find magic vectors
    if (index == n) {
        if (sum == product) {
            for (int i = 0; i < n; ++i)
               std:: cout << vec[i] << (i < n - 1 ? "," : "");
	    std::cout << std::endl;
        }
        return;
    }

    for (int i = start; i <= 100; ++i) {
        vec[index] = i;
        fmv(n, index + 1, i, sum + i, product * i);
    }
}

int main() {
    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    if (N < 1 || N > max_n) {
	    std::cout << "N must be from 1 to  " << max_n << ".\n";
        return 1;
    }

    std::cout << "magic vectors of length " << N << ":\n";
    fmv(N, 0, 1, 0, 1);

    return 0;
}
