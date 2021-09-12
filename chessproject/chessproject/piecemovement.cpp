#include "piecemovement.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

using namespace sf;

std::vector<Sprite> piecemovement::calculateValidMoves(int board[][8], int x, int y, Texture *validMoves) {
	int pieceType = board[y][x];
	std::vector<Sprite> moves;

	switch (abs(pieceType))
	{

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			moves = calculatePawnValidMoves(board, x, y, pieceType);
			break;

		default:
			break;
	}
	for (int i = 0; i < moves.size(); i++) moves[i].setTexture(*validMoves);

	return moves;
}


std::vector<Sprite> piecemovement::calculatePawnValidMoves(int board[][8], int x, int y, int pieceType) {
	
	std::vector<Sprite> moves;

	if (pieceType < 0) {
		moves.push_back(Sprite());
		moves[0].setPosition(100 * x, 100 * (y + 1));
		if (y == 1) {
			moves.push_back(Sprite());
			moves[1].setPosition(100 * x, 100 * (y + 2));
		}
	}
	else {
		moves.push_back(Sprite());
		moves[0].setPosition(100 * x, 100 * (y - 1));
		if (y == 6) {
			moves.push_back(Sprite());
			moves[1].setPosition(100 * x, 100 * (y - 2));
		}
	}

	return moves;
}

int piecemovement::validatePieceMovement(int x, int y, int activeX, int activeY, std::vector<Sprite> moves, int board[][8]) {
	for (int i = 0; i < moves.size(); i++) {
		int moveX = moves[i].getPosition().x;
		int moveY = moves[i].getPosition().y;
		std::cout << "x=" << x << " y=" << y << " activeX=" << activeX << " activeY=" << activeY << std::endl;
		if (x > moveX && x < moveX + 100 && y > moveY && y < moveY + 100)
		{
			std::swap(board[y / 100][x / 100], board[activeY][activeX]);
			return 1;
		}
	}
	return 0;
}