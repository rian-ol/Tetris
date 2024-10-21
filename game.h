#pragma once
#include "grid.h"
#include "blocks.cpp"


class Game
{

    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        Grid grid;
        bool gameOver;

    private:
        void LockBlock();
        void RotateBlock();
        bool IsBlockOutside();
        bool BlockFits();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        void Reset();
};
