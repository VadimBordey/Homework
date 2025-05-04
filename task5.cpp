#include <iostream>

bool palindrome(int n) {
	int initial = n, reversed = 0;
	while (n > 0) {
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}
	return initial == reversed;
}
	int main() {
		std::cout << "Palindromes: " << std::endl;
		for (int i = 1; i <= 99; i++) {
		if (palindrome(i)) {
			int square = i * i;
			if (palindrome(square)) {
				std::cout << "Number: " << i << " , Square: " << square << std::endl;
			}
		}
	}
	return 0;
}

