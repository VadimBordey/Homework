#include <iostream>

void prime(int n) {
	std::cout << n << " = ";
	bool first = true;

	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			if (!first) std::cout << ", ";
			std::cout << i;
			n /= i;
			first = false;
		}
	}
	
	if (n < 1) {
		if (!first) std::cout << ", ";
		std::cout << n;
	}
	std::cout << std::endl;
}
	int main() {
		int number;
		std::cout << "Your number: ";
		std::cin >> number;
		prime(number);
		return 0;
	}

