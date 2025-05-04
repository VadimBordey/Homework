#include <iostream>

void dc(int n) { // dc - decomposition
	while (n % 2 == 0) {
		std::cout << 2 << ", ";
		n /= 2;
	}

	for (int i = 3; i * i <= n; i += 2) {
	while (n % i == 0) {
		std::cout << i << ", ";
		n /= i;
	}
}
}	
	int main () {
		int n;
		std::cout << "Enter your number: " << std::endl;
		std::cin >> n;

		std::cout << "Decomposition " << n << " for prime factors: " << std::endl;
	        dc(n);
		return 0;
	}	

