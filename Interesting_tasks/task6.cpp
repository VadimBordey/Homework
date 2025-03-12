#include <iostream>

const char* ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                      "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                      "sixteen", "seventeen", "eighteen", "nineteen" };

const char* tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                      "eighty", "ninety" };

const char* hundreds[] = { "", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred",
                          "eight hundred", "nine hundred" };

void convert(int n) {
    if (n == 1000) {
        std::cout << "one thousand";
        return;
    }

    if (n >= 100) {
        std::cout << hundreds[n / 100];
        n %= 100;
        if (n > 0) std::cout << " ";
    }

    if (n >= 20) {
        std::cout << tens[n / 10];
        n %= 10;
        if (n > 0) std::cout << " ";
    }

    if (n > 0) {
        std::cout << ones[n];
    }
}

int main() {
    int n;
    std::cout << "Enter a number (1 to 1000): ";
    std::cin >> n;

    if (n < 1 || n > 1000) {
        std::cout << "Number must be between 1 and 1000." << std::endl;
    } else {
        convert(n);
        std::cout << std::endl;
    }

    return 0;
}

