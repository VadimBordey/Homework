#include <iostream>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++) {  
        if (n % i == 0) return false;
    }
    return true;
}

void prime_pairs(int n) {
    for (int i = n; i <= 2 * n - 2; i++) {
        if (is_prime(i) && is_prime(i + 2)) {
            std::cout << "(" << i << ", " << i + 2 << ")\n";
        }
    }
}

int main() {
    int n;
    std::cout << "Put number n: ";
    std::cin >> n;

    std::cout << "pairs of prime numbers between " << n << " і " << 2 * n << ", the difference between which is equal to 2:\n";
    prime_pairs(n);

    return 0;
}
