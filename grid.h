#pragma once
#include <vector>
#include <raylib.h>

class Grid{

    public:
        Grid();
        void Initialise();
        void Print();
        int grid[20][10];
        void Draw();
        bool isCellOutside(int row, int col);
        bool isCellEmpty(int row, int col);
        int ClearFullRows();


    private:

        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
};