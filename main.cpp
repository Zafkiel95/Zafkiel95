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

// Функция вывода многострочного ASCII с отступами
void printCat(const vector<string>& cat, int offsetX, int offsetY) {
    // Печатаем пустые строки для вертикального смещения
    for (int i = 0; i < offsetY; i++)
        cout << "\n";

    // Печатаем кота построчно с горизонтальным смещением
    for (const string& line : cat) {
        cout << string(offsetX, ' ') << line << "\n";
    }
}

int main() {
    // Кадры кота вправо
    vector<vector<string>> rightFrames = {
        {
            " /\\_/\\ ",
            "( o.o )",
            " > ^ < "
        },
        {
            " /\\_/\\ ",
            "( -.- )",
            " >>^<< "
        }
    };

    // Кадры кота влево (зеркальные)
    vector<vector<string>> leftFrames = {
        {
            " /\\_/\\ ",
            "( o.o )",
            " < ^ < "
        },
        {
            " /\\_/\\ ",
            "( -.- )",
            " <<^>> "
        }
    };

    int width = 40;
    int height = 10;

    while (true) {
        // Вправо
        for (int x = 0; x < width; x++) {
            system("clear"); // Windows: system("cls")
            printCat(rightFrames[x % rightFrames.size()], x, 0);
            this_thread::sleep_for(chrono::milliseconds(120));
        }

        // Вниз
        for (int y = 0; y < height; y++) {
            system("clear");
            printCat(rightFrames[y % rightFrames.size()], width, y);
            this_thread::sleep_for(chrono::milliseconds(120));
        }

        // Влево
        for (int x = width; x >= 0; x--) {
            system("clear");
            printCat(leftFrames[x % leftFrames.size()], x, height);
            this_thread::sleep_for(chrono::milliseconds(120));
        }

        // Вверх
        for (int y = height; y >= 0; y--) {
            system("clear");
            printCat(leftFrames[y % leftFrames.size()], 0, y);
            this_thread::sleep_for(chrono::milliseconds(120));
        }
    }

    return 0;
}