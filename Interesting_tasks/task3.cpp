#include <iostream>

void sieve(int n) {
    bool* prime = new bool[n + 1];
    
    for (int i = 0; i <= n; ++i) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    delete[] prime;
}

int main() {
    int limit = 1000;
    sieve(limit);
    return 0;
}
