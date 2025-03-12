#include <iostream>

void edit_text(char* text, int n) {
    char* result = new char[10000];
    int line_length = 0, res_index = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            result[res_index++] = '\n';
            line_length = 0;
        } else if (text[i] == ' ') {
            if (line_length + 1 > n) {
                result[res_index++] = '\n';
                line_length = 0;
            } else {
                result[res_index++] = ' ';
                line_length++;
            }
        } else {
            result[res_index++] = text[i];
            line_length++;
        }
    }
    result[res_index] = '\0';
    
    for (int i = 0; result[i] != '\0'; i++) {
        text[i] = result[i];
    }
    text[res_index] = '\0';
    
    delete[] result;
}

int main() {
    int n;
    std::cout << "Enter line width: ";
    std::cin >> n;
    std::cin.ignore();

    std::cout << "Enter text (end input with two new lines):\n";
    char* text = new char[10000];
    char* line = new char[1000];
    int text_index = 0;
    
    while (std::cin.getline(line, 1000)) {
        if (line[0] == '\0') {
            break;
        }
        int i = 0;
        while (line[i] != '\0' && text_index < 9999) {
            text[text_index++] = line[i++];
        }
        text[text_index++] = '\n';
    }
    text[text_index] = '\0';

    edit_text(text, n);

    std::cout << "\nEdited text:\n";
    std::cout << text;
    
    delete[] text;
    delete[] line;

    return 0;
}
