#include <iostream>
#include <vector>
#include <conio.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include <sstream> // Include for std::ostringstream
#include "plane.h"

// Define screen dimensions here to avoid duplication
const int WIDTH = 80;
const int HEIGHT = 25;

void hideCursor()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}

std::string createGameDisplay(const std::vector<std::vector<char>> &board)
{
    std::ostringstream displayStream;

    displayStream << "+";
    for (int i = 0; i < WIDTH; i++)
    {
        displayStream << "-";
    }
    displayStream << "+";

    for (int i = 0; i < HEIGHT; i++)
    {
        displayStream << "\n|";
        for (int j = 0; j < WIDTH; j++)
        {
            displayStream << board[i][j];
        }
        displayStream << "|";
    }

    displayStream << "\n+";
    for (int i = 0; i < WIDTH; i++)
    {
        displayStream << "-";
    }
    displayStream << "+";

    return displayStream.str();
}

void updateScreen(const std::string &display)
{
    std::cout << display;
}

int main()
{
    hideCursor();

    std::vector<std::vector<char>> board(HEIGHT, std::vector<char>(WIDTH, ' '));
    Plane plane(WIDTH / 2, HEIGHT - 5);

    bool gameRunning = true;
    while (gameRunning)
    {
        plane.clear(board);

        if (_kbhit())
        {
            char key = getch();
            switch (key)
            {
            case 'w':
                plane.move(0, -1, board);
                break;
            case 's':
                plane.move(0, 1, board);
                break;
            case 'a':
                plane.move(-1, 0, board);
                break;
            case 'd':
                plane.move(1, 0, board);
                break;
            case 'q':
                gameRunning = false;
                break;
            }
        }

        plane.draw(board);
        std::string display = createGameDisplay(board);
        updateScreen(display);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "\nGame Over" << std::endl;
    return 0;
}
