#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

class piecemovement
{
public:
	std::vector<Sprite> calculateValidMoves(int board[][8], int x, int y, Texture *validMoves);
	int validatePieceMovement(int x, int y, int activeX, int activeY, std::vector<Sprite> moves, int board[][8]);
private:
	void calculateRookValidMoves();
	void calculateBishopValidMoves();
	void calculateKnightValidMoves();
	void calculateQueenValidMoves();
	void calculateKingValidMoves();
	std::vector<Sprite> calculatePawnValidMoves(int board[][8], int x, int y, int pieceType);
};

