#include "piecemovement.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

using namespace sf;

std::vector<Sprite> piecemovement::calculateValidMoves(int board[][8], int x, int y, Texture *validMoves) {
	int squareX = x / 100;
	int squareY = y / 100;
	int pieceType = board[squareY][squareX];
	std::vector<Sprite> moves;

	switch (abs(pieceType))
	{

		case 1:
			moves = calculateRookValidMoves(board, squareX, squareY, pieceType);
			break;

		case 2:
			moves = calculateKnightValidMoves(board, squareX, squareY, pieceType);
			break;

		case 3:
			moves = calculateBishopValidMoves(board, squareX, squareY, pieceType);
			break;

		case 4:
			moves = calculateQueenValidMoves(board, squareX, squareY, pieceType);
			break;

		case 5:
			moves = calculateKingValidMoves(board, squareX, squareY, pieceType);
			break;

		case 6:
			moves = calculatePawnValidMoves(board, squareX, squareY, pieceType);
			break;

		default:
			break;
	}
	for (int i = 0; i < moves.size(); i++) moves[i].setTexture(*validMoves);

	return moves;
}

std::vector<Sprite> piecemovement::calculateRookValidMoves(int board[][8], int x, int y, int pieceType) {
	
	std::vector<Sprite> moves;
	for (int i = x + 1; i <= 7; i++) {
		if (board[y][i] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * i, 100 * y);
		if (board[y][i] * pieceType < 0) break;
	}
	for (int i = x - 1; i >= 0 ; i--) {
		if (board[y][i] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * i, 100 * y);
		if (board[y][i] * pieceType < 0) break;
	}
	for (int i = y + 1; i <= 7; i++) {
		if (board[i][x] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * x, 100 * i);
		if (board[i][x] * pieceType < 0) break;
	}
	for (int i = y - 1; i >= 0; i--) {
		if (board[i][x] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * x, 100 * i);
		if (board[i][x] * pieceType < 0) break;
	}

	return moves;
}

std::vector<Sprite> piecemovement::calculateKnightValidMoves(int board[][8], int x, int y, int pieceType) {
	
	std::vector<Sprite> moves;
	if (y > 1 && x > 0 && board[y - 2][x - 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 1), 100 * (y - 2));
	}
	if (y > 1 && x < 7 && board[y - 2][x + 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 1), 100 * (y - 2));
	}
	if (y > 0 && x > 1 && board[y - 1][x - 2] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 2), 100 * (y - 1));
	}
	if (y > 0 && x < 6 && board[y - 1][x + 2] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 2), 100 * (y - 1));
	}
	if (y < 7 && x > 1 && board[y + 1][x - 2] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 2), 100 * (y + 1));
	}
	if (y < 7  && x < 6 && board[y + 1][x + 2] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 2), 100 * (y + 1));
	}
	if (y < 6 && x > 0 && board[y + 2][x - 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 1), 100 * (y + 2));
	}
	if (y < 6 && x < 7 && board[y + 2][x + 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 1), 100 * (y + 2));
	}

	return moves;
}

std::vector<Sprite> piecemovement::calculateBishopValidMoves(int board[][8], int x, int y, int pieceType) {

	std::vector<Sprite> moves;

	for (int i = x + 1; i <= 7; i++) {
		if (board[y + (i - x)][i] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * i, 100 * (y + (i - x)));
		if (board[y + (i - x)][i] * pieceType < 0) break;
	}
	for (int i = x + 1; i <= 7; i++) {
		if (board[y - (i - x)][i] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * i, 100 * (y - (i - x)));
		if (board[y - (i - x)][i] * pieceType < 0) break;
	}
	for (int i = x - 1; i >= 0; i--) {
		if (board[y - (x - i)][i] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * i, 100 * (y - (x - i)));
		if (board[y - (x - i)][i] * pieceType < 0) break;
	}
	for (int i = x - 1; i >= 0; i--) {
		if (board[y + (x - i)][i] * pieceType > 0) break;
		moves.push_back(Sprite());
		moves.back().setPosition(100 * i, 100 * (y + (x - i)));
		if (board[y + (x - i)][i] * pieceType < 0) break;
	}
	

	return moves;
}

std::vector<Sprite> piecemovement::calculateQueenValidMoves(int board[][8], int x, int y, int pieceType) {

	std::vector<Sprite> moves;

	std::vector<Sprite> diagMoves = calculateBishopValidMoves(board, x, y, pieceType);
	std::vector<Sprite> straightMoves = calculateRookValidMoves(board, x, y, pieceType);

	moves.reserve(diagMoves.size() + straightMoves.size());
	moves.insert(moves.end(), diagMoves.begin(), diagMoves.end());
	moves.insert(moves.end(), straightMoves.begin(), straightMoves.end());

	return moves;
}

std::vector<Sprite> piecemovement::calculateKingValidMoves(int board[][8], int x, int y, int pieceType) {
	
	std::vector<Sprite> moves;

	if (y > 0 && board[y - 1][x] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * x, 100 * (y - 1));
	}
	if (y > 0 && x > 0 && board[y - 1][x - 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 1), 100 * (y - 1));
	}
	if (y > 0 && x < 7 && board[y - 1][x + 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 1), 100 * (y - 1));
	}
	if (x > 0 && board[y][x - 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 1), 100 * y);
	}
	if (x < 7 && board[y][x + 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 1), 100 * y);
	}
	if (y < 7 && board[y + 1][x] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * x, 100 * (y + 1));
	}
	if (y < 7 && x > 0 && board[y + 1][x - 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x - 1), 100 * (y + 1));
	}
	if (y < 7 && x < 7 && board[y + 1][x + 1] * pieceType <= 0) {
		moves.push_back(Sprite());
		moves.back().setPosition(100 * (x + 1), 100 * (y + 1));
	}

	return moves;
}

std::vector<Sprite> piecemovement::calculatePawnValidMoves(int board[][8], int x, int y, int pieceType) {
	
	std::vector<Sprite> moves;

	if (pieceType < 0) {
		if (y < 7 && board[y + 1][x] == 0) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * x, 100 * (y + 1));
		}
		if (y < 7 && x < 7 && board[y + 1][x + 1] > 0) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * (x + 1), 100 * (y + 1));
		}
		if (y < 7 && x > 0 && board[y + 1][x - 1] > 0) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * (x - 1), 100 * (y + 1));
		}
		if (y == 1) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * x, 100 * (y + 2));
		}
	}
	else {
		if (y > 0 && board[y - 1][x] == 0) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * x, 100 * (y - 1));
		}
		if (y > 0 && x < 7 && board[y - 1][x + 1] < 0) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * (x + 1), 100 * (y - 1));
		}
		if (y > 0 && x > 0 && board[y - 1][x - 1] < 0) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * (x - 1), 100 * (y - 1));
		}
		if (y == 6) {
			moves.push_back(Sprite());
			moves.back().setPosition(100 * x, 100 * (y - 2));
		}
	}

	return moves;
}

std::vector<int> piecemovement::validateMove(std::vector<Sprite> moves, int x, int y, int sx, int sy) {
	std::vector<int> posToSwap(4, -1);
	for (Sprite& move : moves) {
		int moveX = move.getPosition().x;
		int moveY = move.getPosition().y;
		if (x > moveX && x < moveX + 100 && y > moveY && y < moveY + 100) {
			posToSwap.clear();
			posToSwap.push_back(x/100);
			posToSwap.push_back(y/100);
			posToSwap.push_back(sx);
			posToSwap.push_back(sy);
			std::cout << posToSwap.at(0) << " " << posToSwap.at(1) << " " << posToSwap.at(2) << " " << posToSwap.at(3) << std::endl;
			break;
		}
	}

	return posToSwap;
}