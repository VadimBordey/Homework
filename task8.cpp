#include <iostream>

void reformatText(const char* text, int n) {
    char word[100], line[1000];
    int word_len = 0, line_len = 0;
    bool firstWordInLine = true;

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (ch == ' ' || ch == '\n') {
            if (word_len > 0) {
                word[word_len] = '\0';
                if (line_len + word_len + (firstWordInLine ? 0 : 1) > n) {
                    std::cout << line << std::endl;
                    line_len = 0;
                }
                if (line_len > 0) {
                    line[line_len++] = ' ';
                }
                for (int j = 0; j < word_len; ++j) {
                    line[line_len++] = word[j];
                }
                firstWordInLine = false;
                word_len = 0;
            }
            if (ch == '\n') {
                if (line_len > 0) {
                    line[line_len] = '\0';
                    std::cout << line << std::endl;
                }
                line_len = 0;
                firstWordInLine = true;
            }
        } else {
            word[word_len++] = ch;
        }
    }

    if (line_len > 0) {
        line[line_len] = '\0';
        std::cout << line << std::endl;
    }
}

int main() {
    int n;
    const char* text = "This is a basic text used to test the text wrapping logic. Each paragraph remains distinct.\n"
                        "Here is another paragraph for testing the wrapping feature.";

    std::cout << "Enter line width n (> 50): ";
    std::cin >> n;
    std::cin.ignore();

    reformatText(text, n);

    return 0;
}
