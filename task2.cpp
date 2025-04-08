#include <iostream>

void pt(int n) { // pt - pascal triangle
int arr[n];        
for (int i = 0; i < n; i++) {
        arr[0] = 1;
        std::cout << arr[0] << " ";

for (int j = 1; j <= i; j++) {
arr[j] = arr[j - 1] * (i - j + 1) / j;
std::cout << arr[j] << " ";
}
        std::cout << std::endl;
        }
}

int main() {

        int n;
        std::cout << "Write n: ";
        std::cin >> n;

        pt(n);
        return 0;
}

