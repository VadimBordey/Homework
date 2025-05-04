#include <iostream>

int main() {
	const int N = 1000;
		bool prime[N + 1];
	for (int i = 0; i < N; i++) {
		prime[i] = true;
	}
		prime[0] = prime[1] = prime[1000] = false;
		for (int i = 2; i * i <= N; i++) {
			if (prime[i]) {
			for (int j = i * i; j < N; j += i) {
				prime[j] = false;
			}
		}
	}
	
	std::cout << "Prime from 2 to " << N << std::endl;
	for (int i = 2; i <= N; i++) {
		if (prime[i]) {
			std::cout << i << " ";
		}
	}

	std::cout << std::endl;
	return 0;
}

		
