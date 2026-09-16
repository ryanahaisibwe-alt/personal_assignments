#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> key = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

vector<vector<char>> answers = {
    {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
    {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
    {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
    {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
    {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
    {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
    {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
    {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
};

int main() {
    cout << "--- Test Grading Results ---\n";

    for (size_t i = 0; i < answers.size(); i++) {
        int correctCount = 0;

        for (size_t j = 0; j < answers[i].size(); j++) {
            if (answers[i][j] == key[j]) {
                correctCount++;
            }
        }

        cout << "Student " << i << "'s correct count is " << correctCount << "\n";
    }

    return 0;
}
