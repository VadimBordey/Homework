#include <iostream>

int bcd(int a, int b) { // bcd - biggest common divisor
	while(b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void uf(int n) { // uf - undivided fractions
	for (int num = 1; num < n; ++num) { // num - numeral ; n - dominator
	if (bcd(num, n) == 1) {
		std::cout << num << "/" << n << " ";
	}
	}
	std::cout << std::endl;
}
	int main() {
		int n;
		std::cout << "write the dominator: ";
		std::cin >> n;
		
		if (n <= 0) {
			std::cout << "the dominator must be greater than 0" << std::endl;
			return 1;
		}
		std::cout << "Undivided fractions with the dominator " << n << std::endl;
		uf(n);
	return 0;
	}


