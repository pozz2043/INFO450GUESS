#include <iostream>
#include <iomanip>
#include<stdlib.h>
using namespace std;

void boardInitialbase(char altboard[][10])
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			altboard[i][j] = ' ';
		}
	}
	for (i = 2; i < 10; i++) //first row = numbering
	{
		altboard[i][0] = '0' + i - 1;
		altboard[0][i] = '0' + i - 1;
	}
	for (i = 2; i < 10; i++) //second row = bar ing
	{
		altboard[i][1] = '_';
		altboard[1][i] = '|';
	}
}
void boardInitial(char altboard[][10])
{
	int i, a, b;
	for (i = 2; i < 10; i++)
	{
		for (b = 2; b < 10; b++)
		{
			altboard[i][b] = '?';
		}
	}
	for (i = 0; i < 6; i++)
	{
		static int nCalls = 0;
		if (nCalls == 0)
		{
			srand(time(NULL));
		}
		nCalls++;
		a = rand() % 9;
		b = rand() % 9;
		if (altboard[a][b] == '?')
		{
			if (i == 5)
			{
				altboard[a][b] = 'B';
			}
			else
			{
				altboard[a][b] = 'G';

			}
		}
		else
		{
			i -= 1;
		}

	}
}
void displayInstruction()
{
	cout << "** *********************** **" << endl;
	cout << "**       Find Gold!        **" << endl;
	cout << "**   You have 5 guesses,   **" << endl;
	cout << "**    5 pieces of gold     **" << endl;
	cout << "**       And 1 bomb        **" << endl;
	cout << "**       Good Luck!        **" << endl;
	cout << "** *********************** **" << endl;
}
int getValueX()
{
	int x;
	cout << "Enter x coordinate: ";
	cin >> x;
	return x;
}
int getValueY()
{
	int x;
	cout << "Enter y coordinate: ";
	cin >> x;
	return x;
}
void displayInitialboard(char altboard[][10])
{
	int x, y;
	for (y = 2; y < 10; y++)
	{
		for (x = 2; x < 10; x++)
		{
			altboard[x][y] = '?';
		}
	}
	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			cout << setw(4) << altboard[x][y];
		}
		cout << endl;
	}
}

void displayboard(char altboard[][10])
{
	int x, y;
	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			if (altboard[x][y] == '?')
			{
				altboard[x][y] = ' ';
			}
			cout << setw(4) << altboard[x][y];
		}
		cout << endl;
	}
}

int main()
{
	char board[10][10], answer;
	char retry;
	boardInitialbase(board);//보드판의 베이스
	do
	{

		system("cls");
		int i, x, y, point = 0;
		displayInitialboard(board);
		boardInitial(board);//보드판 초기화 (random g coordinate)
		displayInstruction();//instruction 출력
		
		for (i = 4; i >= 0; i--)
		{
			x = getValueX();//get input x coordinate 

			y = getValueY();//get input y coordinate

			answer = board[x + 1][y + 1];
			if (answer == 'G')
			{
				board[x + 1][y + 1] = 'F';
				i += 1;
				cout << "You Found GOLD!! Extra Guess!" << endl;
				cout << "Only " << i << " guesses to go!" << endl;
				point += 1;
			}
			else if (answer == 'B')
			{

				cout << "BOMB! Game over!" << endl;
				cout << endl;
				break;
			}
			else
			{
				cout << "Too Bad… you have " << i << " guesses to go!" << endl;
			}
			cout << endl;
		}
		cout << "You earned " << point << " points!" << endl;
		cout << "Better Luck Next Time" << endl;

		cout << "Here's your board:" << endl;

		displayboard(board);//clear "?" to " ",  board display
		
		cout << "Play again? enter 'Y'" << endl;
		cin >> retry;
	} while ((retry == 'Y') || (retry == 'y'));
	return 0;
}