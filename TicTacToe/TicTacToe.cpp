#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

char board[3][3];

void ResetBoard();
void PrintBoard();
void PlayerMove(char letter);
void CompuerMove();
char CheckWinner();
void GoodPlaceForMove(char symbol, int *row, int *col);
int CheckFreeSpaces();

int main()
{
	int isComputer = 1;
	int playAgain = 2;

	do
	{
		ResetBoard();
		PrintBoard();
		printf("Choose an option: \n");
		printf("1. Play against the computer.\n");
		printf("2. Play against other person.\n");
		scanf_s("%d", &isComputer);

		while (1)
		{
			PlayerMove('X');
			char winner = CheckWinner();
			if (winner != ' ')
			{
				printf("Winner is : %c\n", winner);
				break;
			}
			if (CheckFreeSpaces() == 0)
			{
				printf("There is no winner!\n");
				break;
			}

			if (isComputer == 2)
			{
				PlayerMove('O');
			}
			else
			{
				CompuerMove();
			}

			winner = CheckWinner();
			if (winner != ' ')
			{
				printf("Winner is : %c\n", winner);
				break;
			}
			if (CheckFreeSpaces() == 0)
			{
				printf("There is no winner!\n");
				break;
			}
		}

		printf("Do you want to play again?\n");
		printf("1. Yes\n");
		scanf_s("%d", &playAgain);

	} while (playAgain == 1);

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

	do
	{
		row = 0;
		col = 0;
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
	} while (board[row][col] != ' ');

	board[row][col] = letter;
	PrintBoard();
}

int CheckFreeSpaces()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return 1;
			}
		}
	}

	return 0;
}

void CompuerMove()
{
	srand(time(0));
	int row, col;

	do
	{
		row = -1, col = -1;
		GoodPlaceForMove('O', &row, &col);

		if (row == - 1)
		{
			GoodPlaceForMove('X', &row, &col);
		}

		if (row == -1)
		{
			row = rand() % 3;
			col = rand() % 3;
		}
	} while (board[row][col] != ' ');

	board[row][col] = 'O';
	PrintBoard();
}

void GoodPlaceForMove(char symbol, int *row, int *col)
{
	int currentRow = -1, currentCol = -1;
	*row = currentRow;
	*col = currentCol;

	//rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == symbol && board[i][1] == symbol)
		{
			currentCol = 2;
			if (board[i][currentCol] == ' ')
			{
				*row = i;
				*col = currentCol;
				return;
			}
		}
		if (board[i][0] == symbol && board[i][2] == symbol)
		{
			currentCol = 1;
			if (board[i][currentCol] == ' ')
			{
				*row = i;
				*col = currentCol;
				return;
			}
		}

		if (board[i][1] == symbol && board[i][2] == symbol)
		{
			currentCol = 0;
			if (board[i][currentCol] == ' ')
			{
				*row = i;
				*col = currentCol;
				return;
			}
		}
	}

	//cols
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == symbol && board[1][i] == symbol)
		{
			currentRow = 2;
			if (board[currentRow][i] == ' ')
			{
				*row = currentRow;
				*col = i;
				return;
			}
		}
		if (board[0][i] == symbol && board[2][i] == symbol)
		{
			currentRow = 1;
			if (board[currentRow][i] == ' ')
			{
				*row = currentRow;
				*col = i;
				return;
			}
		}
		if (board[1][i] == symbol && board[2][i] == symbol)
		{
			currentRow = 0;
			if (board[currentRow][i] == ' ')
			{
				*row = currentRow;
				*col = i;
				return;
			}
		}
	}

	//Main diagonal
	if (board[0][0] == symbol && board[1][1] == symbol)
	{
		currentRow = 2;
		if (board[currentRow][currentRow] == ' ')
		{
			*row = currentRow;
			*col = currentRow;
			return;
		}
	}
	if (board[0][0] == symbol && board[2][2] == symbol)
	{
		currentRow = 1;
		if (board[currentRow][currentRow] == ' ')
		{
			*row = currentRow;
			*col = currentRow;
			return;
		}
	}
	if (board[1][1] == symbol && board[2][2] == symbol)
	{
		currentRow = 0;
		if (board[currentRow][currentRow] == ' ')
		{
			*row = currentRow;
			*col = currentRow;
			return;
		}
	}

	//Other diagonal
	if (board[0][2] == symbol && board[1][1] == symbol)
	{
		currentRow = 2;
		currentCol = 0;
		if (board[currentRow][currentCol] == ' ')
		{
			*row = currentRow;
			*col = currentCol;
			return;
		}
	}
	if (board[0][2] == symbol && board[2][0] == symbol)
	{
		currentRow = 1;
		currentCol = 1;
		if (board[currentRow][currentCol] == ' ')
		{
			*row = currentRow;
			*col = currentCol;
			return;
		}
	}
	if (board[1][1] == symbol && board[2][0] == symbol)
	{
		currentRow = 0;
		currentCol = 2;
		if (board[currentRow][currentCol] == ' ')
		{
			*row = currentRow;
			*col = currentCol;
			return;
		}
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