#include <iostream>

bool palindrome(int n) {
	int original = n, reversed = 0, remainder;
	while (n != 0) {
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	return original == reversed;
}

int main() {
	std::cout << "Palindromes who squares are also palindromes:/n";

	for (int i = 1; i < 100; i++) {
		if (palindrome(i) && palindrome(i * i)) {
			std::cout << i << " -> " << i * i << std::endl;
		}
	}
	return 0;
}

