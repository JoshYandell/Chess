#include <iostream>
#include <SFML/Graphics.hpp>
#include "piecemovement.h"
#include <vector>

using namespace sf;

int squareSize = 100;

Sprite pieces[32];
std::vector<Sprite> moves;

//will be manipulated when moving pieces around
int board[8][8] =
{ -1, -2, -3, -4, -5, -3, -2, -1,
 -6, -6, -6, -6, -6, -6, -6, -6,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  6,  6,  6,  6,  6,  6,  6,  6,
  1,  2,  3,  4,  5,  3,  2,  1 };

void loadPieces(){

    int k = 0;

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            int n = board[i][j];
            if (n == 0) continue;
            int x = abs(n) - 1;
            int y = n>0?1:0;
            pieces[k].setTextureRect(IntRect(squareSize * x, squareSize * y, squareSize, squareSize));
            pieces[k].setPosition(squareSize*j, squareSize*i);
            k++;
        }
    }
}

void movePiece(std::vector<int> posToSwap){
    board[posToSwap.at(1)][posToSwap.at(0)] = board[posToSwap.at(3)][posToSwap.at(2)];
    board[posToSwap.at(3)][posToSwap.at(2)] = 0;
}

int main()
{

    RenderWindow window(VideoMode(1200, 800), "Chess", Style::Close);

    Texture chessBoard;
    Texture chessPieces;
    Texture validMoves;

    piecemovement pm;

    if (!chessBoard.loadFromFile("chessboard.png"))
    {
        return EXIT_FAILURE;
    }
    if (!chessPieces.loadFromFile("chessPieces.png"))
    {
        return EXIT_FAILURE;
    }
    if (!validMoves.loadFromFile("validmoves.png"))
    {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 32; i++) pieces[i].setTexture(chessPieces);

    loadPieces();

    Sprite boardSprite(chessBoard);

    Event event;

    int moveState = 0;
    int selectedPieceX = -1;
    int selectedPieceY = -1;

    while (window.isOpen())
    {        
        

        while (window.pollEvent(event))
        {
            
            switch (event.type)
            {

                case Event::Closed:
                    window.close();
                    break;

                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Left && boardSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        if (moveState == 0) {
                            moves = pm.calculateValidMoves(board, event.mouseButton.x, event.mouseButton.y, &validMoves);
                            
                            if (!moves.empty()) {
                                selectedPieceX = event.mouseButton.x / 100;
                                selectedPieceY = event.mouseButton.y / 100;
                                moveState = 1;
                            }
                        }
                        else if (moveState == 1) {
                            std::vector<Sprite> newMoves = pm.calculateValidMoves(board, event.mouseButton.x, event.mouseButton.y, &validMoves);
                            std::vector<int> posToSwap = pm.validateMove(moves, event.mouseButton.x, event.mouseButton.y, selectedPieceX, selectedPieceY);
                            if (!newMoves.empty() && posToSwap.at(0) == -1) {
                                selectedPieceX = event.mouseButton.x / 100;
                                selectedPieceY = event.mouseButton.y / 100;
                                moves = newMoves;
                                moveState = 1;
                            }
                            else {
                                if (posToSwap[0] != -1) {
                                    movePiece(posToSwap);
                                    loadPieces();
                                    moves.clear();
                                    moveState = 0;
                                }
                            }
                        }   
                    }
                default:
                    break;
            }

            
        }

        window.clear();

        window.draw(boardSprite);
        for (int i = 0; i < 32; i++)
        {
            window.draw(pieces[i]);
        }
        for (int i = 0; i < moves.size(); i++)
        {
            window.draw(moves[i]);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}