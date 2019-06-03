#include <iostream>

const int rows = 7, cols = 3;

void revealPassword(char* a[][cols], int m, int n) {
    bool isOrdered;
    int idxOfMidBook = n % 2 ? (n / 2) : (n / 2 - 1);

    for (int i = 0; i < m; i++) {
        isOrdered = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j][0] > a[i][j+1][0]) {
                isOrdered = false;
                break;
            }
        }

        if (isOrdered) {
            int wordLength = 0;
            bool isWhitespace;
            for (int k = 0; a[i][idxOfMidBook][k]; k++) {
                isWhitespace = a[i][idxOfMidBook][k] == ' ';
                if (!isWhitespace) {
                    wordLength++;
                }

                if (isWhitespace || (strlen(a[i][idxOfMidBook]) == k + 1)) {
                    std::cout << wordLength << " ";
                    wordLength = 0;
                }
            }
        }
    }
}

int main() {
    char* library[rows][cols] = {
            {"Algebra", "Analytical geometry", "Calculus"}, // ordered -> 10 8
            {"Introduction to programming", "Object Oriented Programming", "Data Structures and Algorithms"},
            {"Databases", "Artificial Intelligence", "Functional Programming"},
            {"Discrete Mathematics", "Geometry", "Statistics"}, // ordered -> 8 
            {"C++", "Go", "Java"}, // ordered -> 2
            {"Arnold", "C", "Python"}, //ordered -> 1
            {"Harvard", "FMI", "Princeton"}
    };

    revealPassword(library, rows, cols); // 10 8 8 2 1
    return 0;
}
