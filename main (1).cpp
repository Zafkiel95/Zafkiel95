/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

// Печать поля со следами и котом
void printScene(const vector<string>& cat, int catX, int catY,
                const vector<vector<char>>& field) {

    system("clear"); // Windows: system("cls")

    for (int y = 0; y < field.size(); y++) {
        for (int x = 0; x < field[0].size(); x++) {

            // Проверяем, занимает ли кот эту позицию
            bool printed = false;
            for (int cy = 0; cy < cat.size(); cy++) {
                if (y == catY + cy) {
                    const string& line = cat[cy];
                    if (x >= catX && x < catX + line.size()) {
                        cout << line[x - catX];
                        printed = true;
                        break;
                    }
                }
            }

            if (!printed) {
                cout << field[y][x];
            }
        }
        cout << "\n";
    }
}

int main() {
    // Кадры кота вправо
    vector<vector<string>> rightFrames = {
        { " /\\_/\\ ", "( o.o )", " / > <\\" },
        { " /\\_/\\ ", "( -.- )", " / >> \\" }
    };

    // Кадры кота влево
    vector<vector<string>> leftFrames = {
        { " /\\_/\\ ", "( o.o )", " / < <\\" },
        { " /\\_/\\ ", "( -.- )", " / << \\" }
    };

    const int W = 60;
    const int H = 20;

    // Поле со следами
    vector<vector<char>> field(H, vector<char>(W, ' '));

    int catW = rightFrames[0][0].size();
    int catH = rightFrames[0].size();

    while (true) {

        // Вправо
        for (int x = 0; x < W - catW; x++) {
            field[0][x] = '*'; // след лапки
            printScene(rightFrames[x % 2], x, 0, field);
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Вниз
        for (int y = 0; y < H - catH; y++) {
            field[y][W - catW - 1] = '*';
            printScene(rightFrames[y % 2], W - catW - 1, y, field);
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Влево
        for (int x = W - catW - 1; x >= 0; x--) {
            field[H - catH - 1][x] = '*';
            printScene(leftFrames[x % 2], x, H - catH - 1, field);
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        // Вверх
        for (int y = H - catH - 1; y >= 0; y--) {
            field[y][0] = '*';
            printScene(leftFrames[y % 2], 0, y, field);
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    return 0;
}