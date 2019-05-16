#include "pch.h"
#include "chess.h"
#include "Draw.h"
// 利用巨集先定義 上,下,左,右,ESC,ENTER,SPACE,左右角括號
#define ESC	27
#define DIRECTION_KEYBOARD	224
#define UP     72
#define DOWN   80
#define LEFT   75
#define RIGHT  77
#define ENTER  13
#define SPACE  32
#define L_ANGLEBRACKET 44
#define R_ANGLEBRACKET 46


using namespace std;
vector<string> Chess::chessStep = {};
int Chess::whoseTurn = 0;
int Chess::stepNumber = 0;
int Chess::end = -1;
//class Chess
Chess::Chess(string filename)
{
	ifstream fin(filename);
	for (int i = 0; i < 10; i++)
	{
		vector<int> temp = {};
		for (int j = 0; j < 9; j++)
		{
			int chess;
			fin >> chess;
			temp.push_back(chess);
		}
		chessBoard.push_back(temp);
	}
	fin >> whoseTurn;
	fin.close();
}

vector<int> Chess::selectedChess()
{
	// 以下程式碼是移動游標
	unsigned short int ch1, ch2;
	unsigned short int X = 0, Y = 0;

	// 200 是變成橫向游標  (你可以試試看	SetCursorVisible(TRUE, 100);)
	SetCursorVisible(TRUE, 200);
	gotoxy(30, 2);
	X = 30;
	Y = 2;
	COORD coordInData;
	coordInData = { 0, 0 };
	int func;
	beforeSelect:
	while (true)
	{
		ch1 = _getch();
		if (ch1 == ESC)
		{
			func = ESC;
			break;
		}
		else if (ch1 == DIRECTION_KEYBOARD)
		{
			ch2 = _getch();
			switch (ch2)
			{
			case UP:
				if (Y == 2)
					break;
				Y = Y - 2;
				gotoxy(X, Y);
				coordInData.X -= 1;
				break;
			case DOWN:
				if (Y == 20)
					break;
				Y = Y + 2;
				gotoxy(X, Y);
				coordInData.X += 1;
				break;
			case LEFT:
				if (X == 30)
					break;
				X = X - 4;
				gotoxy(X, Y);
				coordInData.Y -= 1;
				break;
			case RIGHT:
				if (X == 62)
					break;
				X = X + 4;
				gotoxy(X, Y);
				coordInData.Y += 1;
				break;
			case ENTER:
				func = ENTER;
				goto afterselect;
				break;
			}

		}
		else if (ch1 == ENTER)
		{
			func = ENTER;
			//TODO:選單
			goto afterselect;
			break;
		}
		else if (ch1 == SPACE)
		{
			func = SPACE;
			goto afterselect;
			break;
		}
		else if (ch1 == L_ANGLEBRACKET)
		{
			func = L_ANGLEBRACKET;
			goto afterselect;
			break;
		}
		else if (ch1 == R_ANGLEBRACKET)
		{
			func = R_ANGLEBRACKET;
			goto afterselect;
			break;
		}
	}
	
afterselect:
	vector<int> position = { -1,-1 };
	switch (func)
	{
	case ESC:
		return {-4,-4};
		break;
	case ENTER:
		if (whoseTurn == 0)
		{
			if (chessBoard[coordInData.X][coordInData.Y] >= 1 && chessBoard[coordInData.X][coordInData.Y] <= 7)
			{
				position[0] = coordInData.X;
				position[1] = coordInData.Y;
			}
			else
			{
				goto beforeSelect;
			}
		}
		else if (whoseTurn == 1)
		{
			if(chessBoard[coordInData.X][coordInData.Y] >= 8 && chessBoard[coordInData.X][coordInData.Y] <= 14)
			{
				position[0] = coordInData.X;
				position[1] = coordInData.Y;
			}
			else goto beforeSelect;
		}
		else selectedChess();

		return position;
		break;
	case SPACE:
		return position;
		break;
	case L_ANGLEBRACKET:
		return {-2,-2};
		break;
	case R_ANGLEBRACKET:
		//TODO:取消悔棋
		return {-3,-3};
		break;
	default:
		goto beforeSelect;
		break;
	}
	
}

vector<vector<int>> Chess::whereCanGO(vector<int>pos)
{
	vector<vector<int>>legalList;
	if (whoseTurn == 0)
	{
		vector<int>temp(2);
		switch (chessBoard[pos[0]][pos[1]])
		{
		case 1:  //將
		{
			for (int i = max(pos[0] - 1, 0); i <= min(pos[0] + 1, 2); i++)
			{
				for (int j = max(pos[1] - 1, 3); j <= min(pos[1] + 1, 5); j++)
				{
					if (chessBoard[i][j] == 0 || chessBoard[i][j] >= 8)
					{
						if (i == pos[0] - 1 && j == pos[1] - 1)
						{
							continue;
						}
						else if (i == pos[0] - 1 && j == pos[1] + 1)
						{
							continue;
						}
						else if (i == pos[0] + 1 && j == pos[1] - 1)
						{
							continue;
						}
						else if (i == pos[0] + 1 && j == pos[1] + 1)
						{
							continue;
						}
						else
						{
							legalList.push_back({ i,j });
						}
					}
				}
			}
			//王見王規則
			int m = pos[0]+1;
			do
			{
				if (chessBoard[m][pos[1]] == 0)
				{
					m += 1;
				}
				else if (chessBoard[m][pos[1]] == 8)
				{
					legalList.push_back({ m,pos[1] });
					break;
				}
				else break;
			} while (m <= 9);
			break;
		}
		case 2:  //士
		{
			if (pos[0] == 0)
			{
				if (chessBoard[1][4] == 0 ||
					(chessBoard[1][4] >= 8 && chessBoard[1][4] <= 14))
				{
					legalList.push_back({ 1, 4 });
				}
			}
			else if (pos[0] == 1)
			{
				if (chessBoard[0][3] == 0 ||
					(chessBoard[0][3] >= 8 && chessBoard[0][3] <= 14))
				{
					legalList.push_back({ 0, 3 });
				}
				if (chessBoard[0][5] == 0 ||
					(chessBoard[0][5] >= 8 && chessBoard[0][5] <= 14))
				{
					legalList.push_back({ 0, 5 });
				}
				if (chessBoard[2][3] == 0 ||
					(chessBoard[2][3] >= 8 && chessBoard[2][3] <= 14))
				{
					legalList.push_back({ 2, 3 });
				}
				if (chessBoard[2][5] == 0 ||
					(chessBoard[2][5] >= 8 && chessBoard[2][5] <= 14))
				{
					legalList.push_back({ 2, 5 });
				}
			}
			else if (pos[0] == 2)
			{
				if (chessBoard[1][4] == 0 ||
					(chessBoard[1][4] >= 8 && chessBoard[1][4] <= 14))
				{
					legalList.push_back({ 1, 4 });
				}
			}
			break;
		}
		case 3:  //象
		{
			for (int i = max(pos[0] - 2, 0); i <= min(pos[0] + 2, 4); i += 2)
			{
				for (int j = max(pos[1] - 2, 0); j <= min(pos[1] + 2, 8); j += 2)
				{
					if ((chessBoard[i][j] == 0 ||
						(chessBoard[i][j] >= 8 && chessBoard[i][j] <= 14)))
					{
						if (i < pos[0] && j < pos[1])
						{
							if (chessBoard[i + 1][j + 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
						else if (i < pos[0] && j > pos[1])
						{
							if (chessBoard[i + 1][j - 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
						else if (i > pos[0] && j < pos[1])
						{
							if (chessBoard[i - 1][j + 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
						else if (i > pos[0] && j > pos[1])
						{
							if (chessBoard[i - 1][j - 1] == 0)
							{
								legalList.push_back({ i,j });
							}
						}
					}
				}
			}
			break;
		}
		case 4:	 //車
		{
			// 向左走
			int x = pos[0];
			int y = pos[1];
			y -= 1;
			while (y >= 0)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0 && chessBoard[x][y] > 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (y == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走，並加入到legalList。
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y--;
				}
			}
			// 向右走
			x = pos[0];
			y = pos[1];
			y += 1;
			while (y <= 8)
			{
				if (chessBoard[x][y] != 0 && chessBoard[x][y] > 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (y == 8)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y++;
				}
			}
			// 向上走
			x = pos[0];
			y = pos[1];
			x -= 1;
			while (x >= 0)
			{
				if (chessBoard[x][y] != 0 && chessBoard[x][y] > 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (x == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x--;
				}
			}
			// 向下走
			x = pos[0];
			y = pos[1];
			x += 1;
			while (x <= 9)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0 && chessBoard[x][y] > 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (x == 9)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x++;
				}
			}
			break;
		}
		case 5:  //馬
		{
			if (pos[0] - 1 >= 1 && chessBoard[pos[0] - 1][pos[1]] == 0)
			{
				if (pos[1] - 1 >= 0 && chessBoard[pos[0] - 2][max(pos[1] - 1,0)] == 0 ||
					(chessBoard[pos[0] - 2][max(pos[1] - 1, 0)] >= 8 && chessBoard[pos[0] - 2][max(pos[1] - 1, 0)] <= 14))
				{
					legalList.push_back({ pos[0] - 2,pos[1] - 1 });
				}
				if (pos[1] + 1 <= 8 && chessBoard[pos[0] - 2][min(pos[1] + 1,8)] == 0 ||
					(chessBoard[pos[0] - 2][min(pos[1] + 1,8)] >= 8 && chessBoard[pos[0] - 2][min(pos[1] + 1,8)] <= 14))
				{
					legalList.push_back({ pos[0] - 2,pos[1] + 1 });
				}
			}
			if (pos[0] + 1 <= 8 && chessBoard[pos[0]+ 1][pos[1]] == 0)
			{
				if (pos[1] - 1 >= 0 && chessBoard[pos[0] + 2][max(pos[1] - 1,0)] == 0 ||
					(chessBoard[pos[0] + 2][max(pos[1] - 1, 0)] >= 8 && chessBoard[pos[0] + 2][max(pos[1] - 1,0)] <= 14))
				{
					legalList.push_back({ pos[0] + 2,pos[1] - 1 });
				}
				if (pos[1] + 1 <= 8 && chessBoard[pos[0] + 2][min(pos[1] + 1,8)] == 0 ||
					(chessBoard[pos[0] + 2][min(pos[1] + 1, 8)] >= 8 && chessBoard[pos[0] + 2][min(pos[1] + 1, 8)] <= 14))
				{
					legalList.push_back({ pos[0] + 2,pos[1] + 1 });
				}
			}
			if (pos[1] - 1 >= 1 && chessBoard[pos[0]][pos[1] - 1] == 0)
			{
				if (pos[0] - 1 >= 0 && chessBoard[max(pos[0] - 1,0)][pos[1] - 2] == 0 ||
					(chessBoard[max(pos[0] - 1, 0)][pos[1] - 2] >= 8 && chessBoard[max(pos[0] - 1, 0)][pos[1] - 2] <= 14))
				{
					legalList.push_back({ pos[0] - 1,pos[1] - 2 });
				}
				if (pos[0] + 1 <= 9 && chessBoard[min(pos[0] + 1,9)][pos[1] - 2] == 0 ||
					(chessBoard[min(pos[0] + 1, 9)][pos[1] - 2] >= 8 && chessBoard[min(pos[0] + 1, 9)][pos[1] - 2] <= 14))
				{
					legalList.push_back({ pos[0] + 1,pos[1] - 2 });
				}
			}
			if (pos[1] + 1 <= 7 && chessBoard[pos[0]][pos[1] + 1] == 0)
			{
				if (pos[0] - 1 >= 0 && chessBoard[max(pos[0] - 1, 0)][pos[1] + 2] == 0 ||
					(chessBoard[max(pos[0] - 1, 0)][pos[1] + 2] >= 8 && chessBoard[max(pos[0] - 1, 0)][pos[1] + 2] <= 14))
				{
					legalList.push_back({ pos[0] - 1,pos[1] + 2 });
				}
				if (pos[0] + 1 <= 9 && chessBoard[min(pos[0] + 1, 9)][pos[1] + 2] == 0 ||
					(chessBoard[min(pos[0] + 1, 9)][pos[1] + 2] >= 8 && chessBoard[min(pos[0] + 1, 9)][pos[1] + 2] <= 14))
				{
					legalList.push_back({ pos[0] + 1,pos[1] + 2 });
				}
			}
			break;
		}
		case 6:  //包
		{
			// 向左走
			int x = pos[0];
			int y = pos[1];
			y -= 1;
			while (y >= 0)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (y == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走，並加入到legalList。
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y--;
				}
			}
			// 如果不是邊界則繼續找可以吃的棋子。
			if (y > 0)
			{
				while (true)
				{
					y--;
					// 如果是紅色方則可以吃，停止
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					// 如果遇到邊界都沒有，停止
					else if (y == 0)
					{
						break;
					}
				}
			}

			// 向右走
			x = pos[0];
			y = pos[1];
			y += 1;
			while (y <= 8)
			{
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (y == 8)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y++;
				}
			}
			if (y < 8)
			{
				while (true)
				{
					y++;
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					else if (y == 8)
					{
						break;
					}
				}
			}

			// 向上走
			x = pos[0];
			y = pos[1];
			x -= 1;
			while (x >= 0)
			{
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (x == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x--;
				}
			}
			if (x > 0)
			{
				while (true)
				{
					x--;
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					else if (x == 0)
					{
						break;
					}
				}
			}

			// 向下走
			x = pos[0];
			y = pos[1];
			x += 1;
			while (x <= 9)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (x == 9)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x++;
				}
			}
			// 如果不是邊界則繼續找可以吃的棋子。
			if (x < 9)
			{
				while (true)
				{
					x++;
					// 如果是紅色方則可以吃，停止
					if (chessBoard[x][y] >= 8 && chessBoard[x][y] <= 14)
					{
						temp = { x, y };
						legalList.push_back(temp);
						break;
					}
					// 如果遇到邊界都沒有，停止
					else if (x == 9)
					{
						break;
					}
				}
			}
			break;
		}
		case 7:  //卒
		{
			// 有過河
			if (pos[0] >= 5)
			{
				if (pos[0] + 1 <= 9)
				{
					temp = { pos[0] + 1,pos[1] };
					legalList.push_back(temp);
				}
				if (pos[1] - 1 >= 0)
				{
					temp = { pos[0],pos[1] - 1 };
					legalList.push_back(temp);
				}
				if (pos[1] + 1 <= 8)
				{
					temp = { pos[0],pos[1] + 1 };
					legalList.push_back(temp);
				}
				break;
			}
			else if (pos[0] <= 4)
			{
				temp = { pos[0] + 1,pos[1] };
				legalList.push_back(temp);
				break;
			}
		}
		default:
			break;
		}
	}
	else if (whoseTurn == 1)
	{
		vector<int>temp(2);
		switch (chessBoard[pos[0]][pos[1]]-7)
		{

		case 1:  //帥
		{
		for (int i = max(pos[0] - 1, 7); i <= min(pos[0] + 1, 9); i++)
		{
			for (int j = max(pos[1] - 1, 3); j <= min(pos[1] + 1, 5); j++)
			{
				if (chessBoard[i][j] == 0 || (chessBoard[i][j] >= 1 && chessBoard[i][j] <= 7))
				{
					if (i == pos[0] - 1 && j == pos[1] - 1)
					{
						continue;
					}
					else if (i == pos[0] - 1 && j == pos[1] + 1)
					{
						continue;
					}
					else if (i == pos[0] + 1 && j == pos[1] - 1)
					{
						continue;
					}
					else if (i == pos[0] + 1 && j == pos[1] + 1)
					{
						continue;
					}
					else
					{
						legalList.push_back({ i,j });
					}
				}
			}
		}
		//王見王規則
		int m = pos[0] - 1;
		while (m >= 0)
		{
			if (chessBoard[m][pos[1]] == 0)
			{
				m -= 1;
			}
			else if (chessBoard[m][pos[1]] == 1)
			{
				legalList.push_back({ m,pos[1] });
				break;
			}
			else break;
		}
		break;
	}
		case 2:  //仕
		{
		if (pos[0] == 9)
		{
			if (chessBoard[8][4] == 0 ||
				(chessBoard[8][4] >= 1 && chessBoard[8][4] <= 7))
			{
				legalList.push_back({ 8, 4 });
			}
		}
		else if (pos[0] == 8)
		{
			if (chessBoard[9][3] == 0 ||
				(chessBoard[9][3] >= 1 && chessBoard[9][3] <= 7))
			{
				legalList.push_back({ 9, 3 });
			}
			if (chessBoard[9][5] == 0 ||
				(chessBoard[9][5] >= 1 && chessBoard[9][5] <= 7))
			{
				legalList.push_back({ 9, 5 });
			}
			if (chessBoard[7][3] == 0 ||
				(chessBoard[7][3] >= 1 && chessBoard[7][3] <= 7))
			{
				legalList.push_back({ 7, 3 });
			}
			if (chessBoard[7][5] == 0 ||
				(chessBoard[7][5] >= 1 && chessBoard[7][5] <= 7))
			{
				legalList.push_back({ 7, 5 });
			}
		}
		else if (pos[0] == 7)
		{
			if (chessBoard[8][4] == 0 ||
				(chessBoard[8][4] >= 1 && chessBoard[8][4] <= 7))
			{
				legalList.push_back({ 8, 4 });
			}
		}
		break;
	}
		case 3:  //相
		{
		for (int i = max(pos[0] - 2, 5); i <= min(pos[0] + 2, 9); i += 2)
		{
			for (int j = max(pos[1] - 2, 0); j <= min(pos[1] + 2, 8); j += 2)
			{
				if ((chessBoard[i][j] == 0 ||
					(chessBoard[i][j] >= 1 && chessBoard[i][j] <= 7)))
				{
					if (i < pos[0] && j < pos[1])
					{
						if (chessBoard[i + 1][j + 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
					else if (i < pos[0] && j > pos[1])
					{
						if (chessBoard[i + 1][j - 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
					else if (i > pos[0] && j < pos[1])
					{
						if (chessBoard[i - 1][j + 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
					else if (i > pos[0] && j > pos[1])
					{
						if (chessBoard[i - 1][j - 1] == 0)
						{
							legalList.push_back({ i,j });
						}
					}
				}
			}
		}
		break;
	}
		case 4:	 // 紅車 
		{

			// 向左走
			int x = pos[0];
			int y = pos[1];
			y -= 1;
			while (y >=0)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (y == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走，並加入到legalList。
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y--;
				}
			}
			// 向右走
			x = pos[0];
			y = pos[1];
			y += 1;
			while (y <= 8)
			{
				if (chessBoard[x][y] != 0 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (y == 8)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					y++;
				}
			}
			// 向上走
			x = pos[0];
			y = pos[1];
			x -= 1;
			while (x >= 0)
			{
				if (chessBoard[x][y] != 0 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				else if (x == 0)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x--;
				}
			}
			// 向下走
			x = pos[0];
			y = pos[1];
			x += 1;
			while (x <= 9)
			{
				// 當第一次遇到 != 0，停止。
				if (chessBoard[x][y] != 0 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (chessBoard[x][y] != 0)
				{
					break;
				}
				// 當第一次遇到邊界，停止。
				else if (x == 9)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 繼續走
				else
				{
					temp = { x, y };
					legalList.push_back(temp);
					x++;
				}
			}
			break;
		}
		case 5:  //傌
		{

			if (pos[0] - 1 >= 1 && chessBoard[pos[0] - 1][pos[1]] == 0)
			{
				if (pos[1] - 1 >= 0 && chessBoard[pos[0] - 2][max(pos[1] - 1, 0)] == 0 ||
					(chessBoard[pos[0] - 2][max(pos[1] - 1, 0)] >= 1 && chessBoard[pos[0] - 2][max(pos[1] - 1, 0)] <= 7))
				{
					legalList.push_back({ pos[0] - 2,pos[1] - 1 });
				}
				if (pos[1] + 1 <= 8 && chessBoard[pos[0] - 2][min(pos[1] + 1, 8)] == 0 ||
					(chessBoard[pos[0] - 2][min(pos[1] + 1, 8)] >= 1 && chessBoard[pos[0] - 2][min(pos[1] + 1, 8)] <= 7))
				{
					legalList.push_back({ pos[0] - 2,pos[1] + 1 });
				}
			}
			if (pos[0] + 1 <= 8 && chessBoard[pos[0] + 1][pos[1]] == 0)
			{
				if (pos[1] - 1 >= 0 && chessBoard[pos[0] + 2][max(pos[1] - 1, 0)] == 0 ||
					(chessBoard[pos[0] + 2][max(pos[1] - 1, 0)] >= 1 && chessBoard[pos[0] + 2][max(pos[1] - 1, 0)] <= 7))
				{
					legalList.push_back({ pos[0] + 2,pos[1] - 1 });
				}
				if (pos[1] + 1 <= 8 && chessBoard[pos[0] + 2][min(pos[1] + 1, 8)] == 0 ||
					(chessBoard[pos[0] + 2][min(pos[1] + 1, 8)] >= 1 && chessBoard[pos[0] + 2][min(pos[1] + 1, 8)] <= 7))
				{
					legalList.push_back({ pos[0] + 2,pos[1] + 1 });
				}
			}
			if (pos[1] - 1 >= 1 && chessBoard[pos[0]][pos[1] - 1] == 0)
			{
				if (pos[0] - 1 >= 0 && chessBoard[max(pos[0] - 1, 0)][pos[1] - 2] == 0 ||
					(chessBoard[max(pos[0] - 1, 0)][pos[1] - 2] >= 1 && chessBoard[max(pos[0] - 1, 0)][pos[1] - 2] <= 7))
				{
					legalList.push_back({ pos[0] - 1,pos[1] - 2 });
				}
				if (pos[0] + 1 <= 9 && chessBoard[min(pos[0] + 1, 9)][pos[1] - 2] == 0 ||
					(chessBoard[min(pos[0] + 1, 9)][pos[1] - 2] >= 1 && chessBoard[min(pos[0] + 1, 9)][pos[1] - 2] <= 7))
				{
					legalList.push_back({ pos[0] + 1,pos[1] - 2 });
				}
			}
			if (pos[1] + 1 <= 7 && chessBoard[pos[0]][pos[1] + 1] == 0)
			{
				if (pos[0] - 1 >= 0 && chessBoard[max(pos[0] - 1, 0)][pos[1] + 2] == 0 ||
					(chessBoard[max(pos[0] - 1, 0)][pos[1] + 2] >= 1 && chessBoard[max(pos[0] - 1, 0)][pos[1] + 2] <= 7))
				{
					legalList.push_back({ pos[0] - 1,pos[1] + 2 });
				}
				if (pos[0] + 1 <= 9 && chessBoard[min(pos[0] + 1, 9)][pos[1] + 2] == 0 ||
					(chessBoard[min(pos[0] + 1, 9)][pos[1] + 2] >= 1 && chessBoard[min(pos[0] + 1, 9)][pos[1] + 2] <= 7))
				{
					legalList.push_back({ pos[0] + 1,pos[1] + 2 });
				}
			}
			break;
		}
		
	
		case 6:  //炮
		{
		// 向左走
		int x = pos[0];
		int y = pos[1];
		y -= 1;
		while (y >= 0)
		{
			// 當第一次遇到 != 0，停止。
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			// 當第一次遇到邊界，停止。
			else if (y == 0)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			// 繼續走，並加入到legalList。
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				y--;
			}
		}
		// 如果不是邊界則繼續找可以吃的棋子。
		if (y > 0)
		{
			while (y >= 0)
			{
				y--;
				// 如果是黑色方則可以吃，停止
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 如果遇到邊界都沒有，停止
				else if (y == 0)
				{
					break;
				}
			}
		}

		// 向右走
		x = pos[0];
		y = pos[1];
		y += 1;
		while (y <= 8)
		{
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			else if (y == 8)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				y++;
			}
		}
		if (y < 8)
		{
			while (true)
			{
				y++;
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (y == 8)
				{
					break;
				}
			}
		}

		// 向上走
		x = pos[0];
		y = pos[1];
		x -= 1;
		while (x >= 0)
		{
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			else if (x == 0)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				x--;
			}
		}
		if (x > 0)
		{
			while (true)
			{
				x--;
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				else if (x == 0)
				{
					break;
				}
			}
		}

		// 向下走
		x = pos[0];
		y = pos[1];
		x += 1;
		while (x <= 9)
		{
			// 當第一次遇到 != 0，停止。
			if (chessBoard[x][y] != 0)
			{
				break;
			}
			// 當第一次遇到邊界，停止。
			else if (x == 9)
			{
				temp = { x, y };
				legalList.push_back(temp);
				break;
			}
			// 繼續走
			else
			{
				temp = { x, y };
				legalList.push_back(temp);
				x++;
			}
		}
		// 如果不是邊界則繼續找可以吃的棋子。
		if (x < 9)
		{
			while (true)
			{
				x++;
				// 如果是黑色方則可以吃，停止
				if (chessBoard[x][y] >= 1 && chessBoard[x][y] <= 7)
				{
					temp = { x, y };
					legalList.push_back(temp);
					break;
				}
				// 如果遇到邊界都沒有，停止
				else if (x == 9)
				{
					break;
				}
			}
		}
		break;
	}
		case 7:  //兵
		{
		// 有過河
		if (pos[0] <= 4)
		{
			if (pos[0] - 1 >= 0)
			{
				temp = { pos[0] - 1,pos[1] };
				legalList.push_back(temp);
			}
			if (pos[1] - 1 >= 0)
			{
				temp = { pos[0],pos[1] - 1 };
				legalList.push_back(temp);
			}
			if (pos[1] + 1 <= 8)
			{
				temp = { pos[0],pos[1] + 1 };
				legalList.push_back(temp);
			}
			break;
		}
		else if (pos[0] >= 5)
		{
			temp = { pos[0] - 1,pos[1] };
			legalList.push_back(temp);
			break;
		}
	}
		default:
			break;
		}
	}
	else
	{
		cout << "Can't find player" << endl;
	}
	legalMoveSpace = legalList;
	return legalList;
}

vector<int> Chess::moveChess(vector<int>pos)
{
	// 以下程式碼是移動游標
	unsigned short int ch1, ch2;
	unsigned short int X = 0, Y = 0;

	// 200 是變成橫向游標  (你可以試試看	SetCursorVisible(TRUE, 100);)
	SetCursorVisible(TRUE, 200);
	gotoxy(30 + 4 * pos[1], 2 + 2 * pos[0]);
	X = 30+4*pos[1];
	Y = 2+2*pos[0];
	vector<int>coordInData;
	coordInData = { pos[0], pos[1] };
	int func;
before:
	while (true)
	{
		ch1 = _getch();
		if (ch1 == ESC)
		{
			func = ESC;
			break;
		}
		else if (ch1 == DIRECTION_KEYBOARD)
		{
			ch2 = _getch();
			switch (ch2)
			{
			case UP:
				if (Y == 2)
					break;
				Y = Y - 2;
				gotoxy(X, Y);
				coordInData[0] -= 1;
				break;
			case DOWN:
				if (Y == 20)
					break;
				Y = Y + 2;
				gotoxy(X, Y);
				coordInData[0] += 1;
				break;
			case LEFT:
				if (X == 30)
					break;
				X = X - 4;
				gotoxy(X, Y);
				coordInData[1] -= 1;
				break;
			case RIGHT:
				if (X == 62)
					break;
				X = X + 4;
				gotoxy(X, Y);
				coordInData[1] += 1;
				break;
			case ENTER:
				func = ENTER;
				goto after;
				break;
			}

		}
		else if (ch1 == ENTER)
		{
			func = ENTER;
			goto after;
			break;
		}
		else if (ch1 == SPACE)
		{
			func = SPACE;
			goto after;
			break;
		}
	}

after:
	vector<int> moveTo = { coordInData[0],coordInData[1] };
	vector<int> position = { -1,-1 };
	switch (func)
	{
	case ESC:
		return position;
		break;
	case ENTER:
		if (find(legalMoveSpace.begin(), legalMoveSpace.end(), moveTo) != legalMoveSpace.end())
		{
			recordChessStep(pos, moveTo);
			position = moveTo;
			endGame(position);
			chessBoard[moveTo[0]][moveTo[1]] = chessBoard[pos[0]][pos[1]];
			chessBoard[pos[0]][pos[1]] = 0;
			
			//確認是否和局(雙方皆剩下不可過河的棋子)
			bool tie = false;
			/*
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (chessBoard[i][j] == 0 ||
						chessBoard[i][j] == 1 || chessBoard[i][j] == 2 || chessBoard[i][j] == 3 ||
						chessBoard[i][j] == 8 || chessBoard[i][j] == 9 || chessBoard[i][j] == 10)
					{
						tie = true;
					}
					else tie = tie && false;
				}
			}*/
			if (tie)
				end = 2;
			return position;
			break;
		}
		else goto before;
	case SPACE:
		return position;
		break;
	case L_ANGLEBRACKET:
		//TODO:悔棋
		return position;
		break;
	case R_ANGLEBRACKET:
		//TODO:取消悔棋
		return position;
		break;
	default:
		goto before;
		break;
	}
}

void Chess::readBoard(string filename)
{
	chessBoard.clear();
	chessRecord.clear();
	chessStep.clear();
	stepNumber = 0;
	ifstream fin(filename);
	for (int i = 0; i < 10; i++)
	{
		vector<int> temp = {};
		for (int j = 0; j < 9; j++)
		{
			int chess;
			fin >> chess;
			temp.push_back(chess);
		}
		chessBoard.push_back(temp);
	}
	fin >> whoseTurn;
	fin.close();
	renewHistory();
}

void Chess::saveBoard(string filename)
{
	ofstream fout(filename);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fout << chessBoard[i][j] << " ";
		}
		fout << "\n";
	}
	fout << whoseTurn;
	fout.flush();
	fout.close();
}

void Chess::nextPlayer()
{
	recordStack.clear();
	stepStack.clear();
	if (whoseTurn == 0)
	{
		whoseTurn = 1;
	}
	else if (whoseTurn == 1)
	{
		whoseTurn = 0;
	}
	else
	{
		system("cls");
		cout << "Error: Can't find next player" << endl;
	}
}

void Chess::recordChessStep(vector<int>ori, vector<int>des)
{
	vector<string>fullA;
	vector<string>fullC;
	string halfFront,halfBack,res;
	fullA = { "０","１","２","３","４","５","６","７","８","９" };
	fullC = { "零","九","八","七","六","五","四","三","二","一" };
	stringstream step("");
	vector<int>num;
	halfFront = "║ ";
	stepNumber += 1;
	step << "　";
	int temp = stepNumber;
	while (temp > 0)
	{	
		num.push_back(temp % 10);
		temp /= 10;
	}
	for (int i = 0; i < num.size()-1;i++)
		step << "\b\b";
	for (int i = num.size() - 1; i >= 0; i--)
	{
		step << fullA[num[i]];
	}
	if (whoseTurn == 0)
	{
		
		step << "黑：";
		switch (chessBoard[ori[0]][ori[1]])
		{
		case 1:
			step << "將" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[0] - ori[0]];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[ori[0] - des[0]];
			}
			else
			{
				step << "平" << fullA[des[1] + 1];
			}
			break;
		case 2:
			step << "士" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[1] + 1];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[des[1] + 1];
			}
			break;
		case 3:
			step << "象" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[1] + 1];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[des[1] + 1];
			}
			break;
		case 4:
			step << "車" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[0] - ori[0]];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[ori[0] - des[0]];
			}
			else
			{
				step << "平" << fullA[des[1] + 1];
			}
			break;
		case 5:
			step << "馬" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[1] + 1];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[des[1] + 1];
			}
			else break;
			break;
		case 6:
			step << "包" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[0] - ori[0]];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[ori[0] - des[0]];
			}
			else
			{
				step << "平" << fullA[des[1] + 1];
			}
			break;
		case 7:
			step << "卒" << fullA[ori[1] + 1];
			if (des[0] > ori[0])
			{
				step << "進" << fullA[des[0] - ori[0]];
			}
			else if (des[0] < ori[0])
			{
				step << "退" << fullA[ori[0] - des[0]];
			}
			else
			{
				step << "平" << fullA[des[1] + 1];
			}
			break;
		default:
			break;

		}
	}
	else if (whoseTurn == 1)
	{
		
		
		step << "紅：";
		switch (chessBoard[ori[0]][ori[1]] - 7)
		{
		case 1:
			step << "帥" << fullC[ori[1]+1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[10+(des[0]-ori[0])];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[10 + (ori[0] - des[0])];
			}
			else
			{
				step << "平" << fullC[des[1]+1];
			}
			break;
		case 2:
			step << "仕" << fullC[ori[1] + 1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[des[1]+1];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[des[1]+1];
			}
			break;
		case 3:
			step<< "相" << fullC[ori[1] + 1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[des[1] + 1];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[des[1] + 1];
			}
			break;
		case 4:
			step<< "車" << fullC[ori[1] + 1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[10 + (des[0] - ori[0])];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[10 + (ori[0] - des[0])];
			}
			else
			{
				step << "平" << fullC[des[1] + 1];
			}
			break;
		case 5:
			step<< "傌" << fullC[ori[1] + 1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[des[1] + 1];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[des[1] + 1];
			}
			break;
		case 6:
			step<< "炮" << fullC[ori[1] + 1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[10 + (des[0] - ori[0])];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[10 + (ori[0] - des[0])];
			}
			else
			{
				step << "平" << fullC[des[1] + 1];
			}
			break;
		case 7:
			step<< "兵" << fullC[ori[1] + 1];
			if (des[0] < ori[0])
			{
				step << "進" << fullC[10 + (des[0] - ori[0])];
			}
			else if (des[0] > ori[0])
			{
				step << "退" << fullC[10 - (ori[0] - des[0])];
			}
			else
			{
				step << "平" << fullC[des[1] + 1];
			}
			break;
		default:
			break;
		}
	}
	step << "　　　║";
	halfBack = " ";
	step >> res;
	chessStep.push_back(halfFront+res+halfBack);
}

void Chess::endGame(vector<int>des)
{
	if (chessBoard[des[0]][des[1]] == 1)
	{
		end = 1;
	}
	else if(chessBoard[des[0]][des[1]] == 8)
	{
		end = 0;
	}
	else end = -1;
}

int& Chess::getEnd()
{
	return end;
}

void Chess::renewHistory()
{
	chessRecord.push_back(chessBoard);
}

int& Chess::getStepNumber()
{
	return stepNumber;
}

void Chess::assignBoard()
{
	recordStack.push_back(chessRecord[chessRecord.size() - 1]);
	stepStack.push_back(chessStep[chessStep.size() - 1]);
	chessRecord.pop_back();
	chessStep.pop_back();
	recordStack.push_back(chessRecord[chessRecord.size() - 1]);
	stepStack.push_back(chessStep[chessStep.size() - 1]);
	chessRecord.pop_back();
	chessStep.pop_back();


	chessBoard = chessRecord[chessRecord.size() - 1];
	Draw::leftPart[stepNumber] = "║ 　　　　　　　　　　　║ ";
	stepNumber -= 1;
	Draw::leftPart[stepNumber] = "║ 　　　　　　　　　　　║ ";
	stepNumber -= 1;
	
}

void Chess::Undo()
{
	chessRecord.push_back(recordStack[recordStack.size() - 1]);
	chessStep.push_back(stepStack[stepStack.size() - 1]);
	recordStack.pop_back();
	stepStack.pop_back();
	stepNumber += 1;
	Draw::leftPart[stepNumber] = chessStep[stepNumber-1];

	chessRecord.push_back(recordStack[recordStack.size() - 1]);
	chessStep.push_back(stepStack[stepStack.size() - 1]);
	recordStack.pop_back();
	stepStack.pop_back();
	stepNumber += 1;
	Draw::leftPart[stepNumber] = chessStep[stepNumber - 1];
	chessBoard = chessRecord[chessRecord.size() - 1];
}

int Chess::getStackSize()
{
	return stepStack.size();
}

int Chess::gonnaLost()
{
	int x;
	int y;
	int end;
	vector<int>temp(2);
	vector<vector<int>>validList;

	for (int i = 0; i < chessBoard.size(); i++)
	{
		for (int j = 0; j < chessBoard[i].size(); j++)
		{
			temp[0] = i;
			temp[1] = j;
			validList = whereCanGO(temp);
			for (int i = 0; i < validList.size(); i++)
			{
				x = validList[i][0];
				y = validList[i][1];
				if (chessBoard[x][y] == 1)
				{
					end = 1;
					return end;
				}
				else if (chessBoard[x][y] == 8)
				{
					end = 2;
					return end;
				}
			}
		}
	}
	end = 3;
	return end;
}