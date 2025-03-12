#include <iostream>

void print_pascals_triangle(int n) {
    int** triangle = new int*[n];  
    for (int i = 0; i < n; i++) {
        triangle[i] = new int[i + 1];
        triangle[i][0] = 1;  
        triangle[i][i] = 1;  
    }

    for (int i = 2; i < n; i++) {  
        for (int j = 1; j < i; j++) {  
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}

int main() {
    int n;
    std::cout << "Enter number of rows for Pascal's Triangle: ";
    std::cin >> n;

    print_pascals_triangle(n);

    return 0;
}
