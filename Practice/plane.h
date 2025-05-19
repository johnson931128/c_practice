#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include <iostream>

class Plane
{
private:
    int x, y; // Plane coordinates

public:
    // Constructor
    Plane(int startX, int startY) : x(startX), y(startY) {}

    // Function to draw the plane on the board
    void draw(std::vector<std::vector<char>> &board)
    {
        // Plane shape (simple example)
        board[y][x] = '^';
        board[y + 1][x - 1] = '/';
        board[y + 1][x + 1] = '\\';
        board[y + 2][x] = '|';
    }

    // Function to clear the plane position from the board
    void clear(std::vector<std::vector<char>> &board)
    {
        board[y][x] = ' ';
        board[y + 1][x - 1] = ' ';
        board[y + 1][x + 1] = ' ';
        board[y + 2][x] = ' ';
    }

    // Function to move the plane
    void move(int dx, int dy, std::vector<std::vector<char>> &board)
    {
        // Clear current position
        clear(board);

        // Update position
        x += dx;
        y += dy;

        // Make sure the plane doesn't move out of bounds
        if (x < 1)
            x = 1;
        if (x >= board[0].size() - 1)
            x = board[0].size() - 2;
        if (y < 1)
            y = 1;
        if (y >= board.size() - 3)
            y = board.size() - 3;

        // Draw plane at new position
        draw(board);
    }

    // Getter for x and y coordinates
    int getX() const { return x; }
    int getY() const { return y; }
};

#endif
