#include "pch.h"
#include <iostream>

char board[3][3];

void ResetBoard();
void PrintBoard();
void PlayerMove(char letter);
char CheckWinner();

int main()
{
	ResetBoard();
	PrintBoard();

	while (true)
	{
		PlayerMove('X');
		char winner = CheckWinner();
		if (winner != ' ')
		{
			printf("Winner is : %c", winner);
			break;
		}

		PlayerMove('O');
		winner = CheckWinner();
		if (winner != ' ')
		{
			printf("Winner is : %c", winner);
			break;
		}
	}

	return 0;
}

void ResetBoard()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = ' ';
		}
	}
}

void PrintBoard()
{
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void PlayerMove(char letter)
{
	int row = 0, col = 0;
	while (row < 1 || row > 3)
	{
		printf("Enter a number of row(1 to 3): ");
		scanf_s("%d", &row);
	}

	while (col < 1 || col > 3)
	{
		printf("Enter a number of col(1 to 3): ");
		scanf_s("%d", &col);
	}

	row--;
	col--;

	if (board[row][col] == ' ')
	{
		board[row][col] = letter;
		PrintBoard();
	}
	else
	{
		printf("Not a valid cordinates.\n");
	}
}

char CheckWinner()
{
	//rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return board[i][0];
		}
	}

	//cols
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return board[0][i];
		}
	}

	//Main diagonal
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return board[0][0];
	}

	//Other diagonal
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return board[0][2];
	}

	return ' ';
}