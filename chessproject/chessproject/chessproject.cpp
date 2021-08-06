
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1200, 800), "Chess");

    Texture chessBoard;
    if (!chessBoard.loadFromFile("chessboard.png"))
    {
        return EXIT_FAILURE;
    }

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

        window.display();
    }
}