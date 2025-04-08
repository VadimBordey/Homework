#include <iostream>

int main() {
	int n;
	std::cout << "Write n: " << std::endl;
	std::cin >> n;

	for (int a = 0; a <= n; a++) {
		for (int b = 0; b <= n; b++) {
			for (int c = 0; c <= n; c++) {
				if (a * a + b * b == c * c) {
					std::cout << "Correct answer: " << a << " " << b << " " << c << std::endl;
				}
			}
		}
	}
	return 0;
}
