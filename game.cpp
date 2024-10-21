#include "game.h"
#include <random>
Game :: Game(){

    grid = Grid();
    blocks= GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;

}


Block Game:: GetRandomBlock(){

    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(),OBlock(),SBlock(),TBlock(),ZBlock(), LBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}

void Game::HandleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed !=0){
        gameOver = false;
        Reset();
    }

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;

    case KEY_RIGHT:
        MoveBlockRight();
        break;
    
    case KEY_DOWN:
        MoveBlockDown();
        break;

    case KEY_UP:
        RotateBlock();

        break;
    }
}


void Game::MoveBlockLeft(){
    if(!gameOver ){
        currentBlock.Move(0,-1);
        if(IsBlockOutside() || BlockFits() ==false)
        {
            currentBlock.Move(0,1);
        }
    }
}

void Game::MoveBlockRight(){
    if(!gameOver ){
        currentBlock.Move(0,1);
        if(IsBlockOutside() ||BlockFits() == false)
        {
            currentBlock.Move(0,-1);
        }   
    }
}

void Game:: MoveBlockDown(){
    if(!gameOver ){
        currentBlock.Move(1,0);
        if(IsBlockOutside() ||BlockFits() == false)
        {
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;

    }
    currentBlock = nextBlock;
    if(BlockFits() == false){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

void Game::RotateBlock()
{   
    if(!gameOver ){
        currentBlock.Rotate();
        if(IsBlockOutside()){
            currentBlock.UndoRotation();
        }
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for(Position item :tiles){
        if(grid.isCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if(grid.isCellEmpty(item.row, item.column) == false){
            return false;
        }
    }
    return true;
    
}

void Game::Reset()
{
    grid.Initialise();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
