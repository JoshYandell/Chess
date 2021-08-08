
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int squareSize = 100;

Sprite pieces[32];

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

int main()
{

    RenderWindow window(VideoMode(1200, 800), "Chess");

    Texture chessBoard;
    Texture chessPieces;

    if (!chessBoard.loadFromFile("chessboard.png"))
    {
        return EXIT_FAILURE;
    }
    if (!chessPieces.loadFromFile("chessPieces.png"))
    {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 32; i++) pieces[i].setTexture(chessPieces);

    loadPieces();

    Sprite boardSprite(chessBoard);

    Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
            }

            
        }

        window.clear();

        window.draw(boardSprite);
        for (int i = 0; i < 32; i++)
        {
            window.draw(pieces[i]);
        }

        window.display();
    }

    return EXIT_SUCCESS;
}