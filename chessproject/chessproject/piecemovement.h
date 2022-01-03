#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

class piecemovement
{
public:
	std::vector<Sprite> calculateValidMoves(int board[][8], int x, int y, Texture *validMoves);
	std::vector<int> validateMove(std::vector<Sprite> moves, int x, int y, int sx, int sy);
private:
	std::vector<Sprite> calculateRookValidMoves(int board[][8], int x, int y, int pieceType);
	std::vector<Sprite> calculateKnightValidMoves(int board[][8], int x, int y, int pieceType);
	std::vector<Sprite> calculateBishopValidMoves(int board[][8], int x, int y, int pieceType);
	std::vector<Sprite> calculateQueenValidMoves(int board[][8], int x, int y, int pieceType);
	std::vector<Sprite> calculateKingValidMoves(int board[][8], int x, int y, int pieceType);
	std::vector<Sprite> calculatePawnValidMoves(int board[][8], int x, int y, int pieceType);
};

