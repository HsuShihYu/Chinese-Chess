#include"pch.h"
#include"chess.h"
#include"Draw.h"

vector<vector<int>> Chess::chessBoard = {};

// 利用巨集先定義 上,下,左,右,ESC
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

vector<string>Draw::leftPart = {};
vector<string>Draw::rightPart = {};
vector<string>Draw::chessPart = {};
void Draw::renewChessPart()
{
	// 一行一行去重做一個 String.
	// Ex: 第一行的第一列為 0，則 append "╔*═*"  (*代表 空白)
	vector<string>rowString(10);
	chessPart = intialBoard(chessPart);
	string temp;
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		temp = "";
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			// 討論各行狀況 (p.s. 這裡用很多重複的code，如果這個 function 之後還會用的到，再來修改，來減少行數)
			if (i == 0)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╗ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╔ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("═ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
			}
			else if (i == 4)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("┴ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
			}
			else if (i == 5)
			{
				if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("┬ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
			}
			else if (i == 9)
			{
				if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╚ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("╝ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("═ ═ ");
						break;
					case 1:
						temp.append("將═ ");
						break;
					case 2:
						temp.append("士═ ");
						break;
					case 3:
						temp.append("象═ ");
						break;
					case 4:
						temp.append("車═ ");
						break;
					case 5:
						temp.append("馬═ ");
						break;
					case 6:
						temp.append("包═ ");
						break;
					case 7:
						temp.append("卒═ ");
						break;
					case 8:
						temp.append("帥═ ");
						break;
					case 9:
						temp.append("仕═ ");
						break;
					case 10:
						temp.append("相═ ");
						break;
					case 11:
						temp.append("車═ ");
						break;
					case 12:
						temp.append("傌═ ");
						break;
					case 13:
						temp.append("炮═ ");
						break;
					case 14:
						temp.append("兵═ ");
						break;
					}
				}
			}
			else if (1 <= i <= 3 || 6 <= i <= 8)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ");
						break;
					case 1:
						temp.append("將");
						break;
					case 2:
						temp.append("士");
						break;
					case 3:
						temp.append("象");
						break;
					case 4:
						temp.append("車");
						break;
					case 5:
						temp.append("馬");
						break;
					case 6:
						temp.append("包");
						break;
					case 7:
						temp.append("卒");
						break;
					case 8:
						temp.append("帥");
						break;
					case 9:
						temp.append("仕");
						break;
					case 10:
						temp.append("相");
						break;
					case 11:
						temp.append("車");
						break;
					case 12:
						temp.append("傌");
						break;
					case 13:
						temp.append("炮");
						break;
					case 14:
						temp.append("兵");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("║ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("┼ ─ ");
						break;
					case 1:
						temp.append("將─ ");
						break;
					case 2:
						temp.append("士─ ");
						break;
					case 3:
						temp.append("象─ ");
						break;
					case 4:
						temp.append("車─ ");
						break;
					case 5:
						temp.append("馬─ ");
						break;
					case 6:
						temp.append("包─ ");
						break;
					case 7:
						temp.append("卒─ ");
						break;
					case 8:
						temp.append("帥─ ");
						break;
					case 9:
						temp.append("仕─ ");
						break;
					case 10:
						temp.append("相─ ");
						break;
					case 11:
						temp.append("車─ ");
						break;
					case 12:
						temp.append("傌─ ");
						break;
					case 13:
						temp.append("炮─ ");
						break;
					case 14:
						temp.append("兵─ ");
						break;
					}
				}
			}
		}
		// 把每行讀進暫存的 vector <string>
		rowString[i] = temp;
	}
	// 把 rowString 讀進基數行的 chessBoard
	for (int i = 0; i < 10; i++)
	{
		Draw::chessPart[2 * i + 1] = rowString[i];
	}
	renewCarOrder();
}

void Draw::renewLeft()
{
	leftPart = initialSituation(leftPart);
	
	if (Chess::chessStep.size() > 0)
	{
		int n;
		if (Chess::stepNumber < 20)
		{
			n = Chess::stepNumber;
		}
		else
		{
			n = Chess::stepNumber % 19;
			if (n == 0)
				n = 19;
		}
			leftPart[n] = Chess::chessStep[Chess::stepNumber - 1];
	}
}

void Draw::renewRight()
{
	rightPart = initialRight(rightPart);
	vector<int> bKingPos(2),rKingPos(2);
	//確認對面王位置
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Chess::chessBoard[i][j] == 1)
			{
				bKingPos = { i,j };
			}
			if (Chess::chessBoard[i][j] == 8)
			{
				rKingPos = { i,j };
			}
		}
	}
	if (Chess::getEnd() == -1)
	{
		if (Chess::whoseTurn == 0)
		{
			rightPart[3] = "║ 　　現在輪到　黑色方　下棋　　║ ";

		}
		else if (Chess::whoseTurn == 1)
		{
			rightPart[3] = "║ 　　現在輪到　紅色方　下棋　　║ ";
		}
	}
	else if(Chess::getEnd() ==  0)
	{
		rightPart[3] = "║ 　　　　黑色方　勝利！　　　　║ "; 
	}
	else if (Chess::getEnd() == 1)
	{
		rightPart[3] = "║ 　　　　紅色方　勝利！　　　　║ ";
	}
	else if (Chess::getEnd() == 2)
	{
		rightPart[3] = "║ 　　　　　　和局！　　　　　　║ ";			   
	}
	// 後面再持續更新
}

void Draw::renewCarOrder()
{
	carList.clear();
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			if (Chess::chessBoard[i][j] == 4)
			{
				carList.push_back(0);
			}
			else if (Chess::chessBoard[i][j] == 11)
			{
				carList.push_back(1);
			}
		}
	}
}

void Draw::showOutput()
{
	system("cls");
	string wordBlack = "將士象馬包卒";
	string wordRed = "帥仕相傌炮兵";
	string car = "車";
	string red = "紅";
	string black = "黑";
	string bug1 = "７";
	string bug2 = "炮";
	string bug3 = "色方";
	int count = 0;

	system("color 0f");
	cout << "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗ " << endl;
	for (int i = 0; i < 21; i++)
	{
		SetColor(15);
		cout << "║ ";
		for (int j = 0; j < leftPart[i].size(); j++)
		{
			SetColor(15);
			if (find(bug1.begin(), bug1.end(), leftPart[i][j]) != bug1.end())
			{
				SetColor(15);
				cout << leftPart[i][j];
			}
			else if (find(bug2.begin(), bug2.end(), leftPart[i][j]) != bug2.end())
			{
				SetColor(15);
				cout << leftPart[i][j];
			}
			else if (find(black.begin(), black.end(), leftPart[i][j]) != black.end())
			{
				SetColor(8);
				cout << leftPart[i][j];
			}
			else if (find(red.begin(), red.end(), leftPart[i][j]) != red.end())
			{
				SetColor(12);
				cout << leftPart[i][j];
			}
			else
			{
				SetColor(15);
				cout << leftPart[i][j];
			}
		}
		cout << "　";
		// 棋盤部分
		SetColor(240);
		for (int j = 0; j < chessPart[i].size(); j++)
		{
			if (i == 0 || i == 20)
			{
				SetColor(253);
				cout << chessPart[i][j];
			}
			else
			{
				if (find(wordRed.begin(), wordRed.end(), chessPart[i][j]) != wordRed.end())
				{
					SetColor(124);
					cout << chessPart[i][j];
				}
				else if (find(wordBlack.begin(), wordBlack.end(), chessPart[i][j]) != wordBlack.end())
				{
					SetColor(112);
					cout << chessPart[i][j];
				}
				else if (find(car.begin(), car.end(), chessPart[i][j]) != car.end())
				{
					if (carList[count] == 0)
					{
						SetColor(112);
						cout << chessPart[i][j];
						count++;
					}
					else if (carList[count] == 1)
					{
						SetColor(124);
						cout << chessPart[i][j];
						count++;
					}
				}
				else
				{
					SetColor(240);
					cout << chessPart[i][j];
				}
			}
		}
		SetColor(15);
		cout << "　";
		int status = Chess::whoseTurn;
		if(i <= 10)
		{ 
			for (int j = 0; j < rightPart[i].size(); j++)
			{
				if (find(red.begin(), red.end(), rightPart[i][j]) != red.end())
				{
					status = 1;
					SetColor(207);
					cout << rightPart[i][j];
				}
				else if (find(black.begin(), black.end(), rightPart[i][j]) != black.end())
				{
					status = 0;
					SetColor(240);
					cout << rightPart[i][j];
				}
				else if (find(bug3.begin(), bug3.end(), rightPart[i][j]) != bug3.end())
				{
					if (status == 0)
					{
						SetColor(240);
						cout << rightPart[i][j];
					}
					else if (status == 1)
					{
						SetColor(207);
						cout << rightPart[i][j];
					}
				}
				else
				{
					SetColor(15);
					cout << rightPart[i][j];
				}
			}
		}
		else
		{
			SetColor(15);
			cout << rightPart[i];
		}
		cout << "　║ " << endl;
	}
	cout << "╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝ " << endl;
}

void Draw::showHint(vector<vector<int>>legalList)
{
	SetColor(208);
	for (int i = 0; i < legalList.size(); i++)
	{
		string word = "將士象馬包卒帥仕相傌炮兵車";

		int x = legalList[i][0];
		int y = legalList[i][1];

		int X = (y * 4) + 30;
		int Y = (x * 2) + 2;

		gotoxy(X, Y);
		if (Chess::chessBoard[x][y] == 0 && y == 0)
		{
			if (x == 0)
			{
				cout << "╔ " << endl;
			}
			else if (x == 9)
			{
				cout << "╚ " << endl;
			}
			else
			{
				cout << "║ " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0 && y == 8)
		{
			if (x == 0)
			{
				cout << "╗ " << endl;
			}
			else if (x == 9)
			{
				cout << "╝ " << endl;
			}
			else
			{
				cout << "║ " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0)
		{
			if (x == 4)
			{
				cout << "┴ " << endl;
			}
			else if (x == 5)
			{
				cout << "┬ " << endl;
			}
			else if (x == 0 || x == 9)
			{
				cout << "═ " << endl;
			}
			else
			{
				cout << "┼ " << endl;
			}
		}
		else
		{
			SetColor(176);
			switch (Chess::chessBoard[x][y])
			{
			case 1:
				cout << "將" << endl;
				break;
			case 2:
				cout << "士" << endl;
				break;
			case 3:
				cout << "象" << endl;
				break;
			case 4:
				cout << "車" << endl;
				break;
			case 5:
				cout << "馬" << endl;
				break;
			case 6:
				cout << "包" << endl;
				break;
			case 7:
				cout << "卒" << endl;
				break;
			case 8:
				cout << "帥" << endl;
				break;
			case 9:
				cout << "仕" << endl;
				break;
			case 10:
				cout << "相" << endl;
				break;
			case 11:
				cout << "車" << endl;
				break;
			case 12:
				cout << "傌" << endl;
				break;
			case 13:
				cout << "炮" << endl;
				break;
			case 14:
				cout << "兵" << endl;
				break;
			}
			SetColor(208);
		}
	}
	SetColor(15);
}

void Draw::renewChess()
{
	renewChessPart();
	renewLeft();
	renewRight();
}

void Draw::showRegretMenu()
{
	int X = 35;
	int Y = 8;
	regretMenu = initialRegret(regretMenu);
	for (int i = 0; i < regretMenu.size(); i++)
	{
		gotoxy(X, Y);
		cout << regretMenu[i] << endl;
		Y++;
	}
}

void Draw::showMainMenu()
{
	int X = 50;
	int Y = 6;
	mainMenu = initialMainMenu(mainMenu);
	for (int i = 0; i < mainMenu.size(); i++)
	{
		gotoxy(X, Y);
		cout << mainMenu[i] << endl;
		Y++;
	}
}

int Draw::selectRegret()
{
	// 以下程式碼是移動游標
	unsigned short int ch1, ch2;
	unsigned short int X, Y;
	int func;

	// 200 是變成橫向游標  (你可以試試看	SetCursorVisible(TRUE, 100);)

	SetCursorVisible(TRUE, 200);
	gotoxy(41, 13);
	X = 41;
	Y = 13;
	func = 0;
	while (true)
	{
		ch1 = _getch();
		if (ch1 == ENTER)
		{
			return func;
			break;
		}
		else if (ch1 == DIRECTION_KEYBOARD)
		{
			ch2 = _getch();
			switch (ch2)
			{
			case LEFT:
				if (X == 41)
					break;
				X = X - 10;
				gotoxy(X, Y);
				func--;
				break;
			case RIGHT:
				if (X == 51)
					break;
				X = X + 10;
				gotoxy(X, Y);
				func++;
				break;
			case ENTER:
				return func;
				break;
			}
		}
	}
}

int Draw::selectMainMenu()
{
	// 以下程式碼是移動游標
	unsigned short int ch1, ch2;
	unsigned short int X, Y;
	int func;

	SetCursorVisible(TRUE,200);
	gotoxy(56, 7);
	X = 56;
	Y = 7;
	func = 0;
	while (true)
	{
		ch1 = _getch();
		if (ch1 == ENTER)
		{
			return func;
			break;
		}
		else if (ch1 == DIRECTION_KEYBOARD)
		{
			ch2 = _getch();
			switch (ch2)
			{
			case UP:
				if (Y == 7)
					break;
				Y = Y - 2;
				gotoxy(X, Y);
				func--;
				break;
			case DOWN:
				if (Y == 15)
					break;
				Y = Y + 2;
				gotoxy(X, Y);
				func++;
				break;
			case ENTER:
				return func;
				break;
			}
		}
	}
}

void Draw::showUndoMenu()
{
	int X = 35;
	int Y = 8;
	regretMenu = initialRegret(regretMenu);
	regretMenu[3] = "║ 　　　確定還原？　　　║ ";
	for (int i = 0; i < regretMenu.size(); i++)
	{
		gotoxy(X, Y);
		cout << regretMenu[i] << endl;
		Y++;
	}
}

void Draw::clearLeft()
{
	leftPart.clear();
	leftPart = initialSituation(leftPart);
}

void Draw::clearRight()
{
	rightPart = {};
	rightPart = initialRight(rightPart);
}

void Draw::showRestartMenu()
{
	int X = 35;
	int Y = 8;
	regretMenu = initialRegret(regretMenu);
	regretMenu[2] = "║ 　　　遊戲結束　　　　║ ";
	regretMenu[3] = "║ 　　是否重新開始？　　║ ";
	for (int i = 0; i < regretMenu.size(); i++)
	{
		gotoxy(X, Y);
		cout << regretMenu[i] << endl;
		Y++;
	}
}

void Draw::loseRight(int end)
{
	if (end == 1)
	{
		rightPart[6] = "║ 　　　　黑方已被將軍　　　　　║ ";
	}
	else if (end == 2)
	{
		rightPart[6] = "║ 　　　　紅方已被將軍　　　　　║ ";
	}
}