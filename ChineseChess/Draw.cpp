#include"pch.h"
#include"chess.h"
#include"Draw.h"

vector<vector<int>> Chess::chessBoard = {};

// �Q�Υ������w�q �W,�U,��,�k,ESC
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
	// �@��@��h�����@�� String.
	// Ex: �Ĥ@�檺�Ĥ@�C�� 0�A�h append "��*��*"  (*�N�� �ť�)
	vector<string>rowString(10);
	chessPart = intialBoard(chessPart);
	string temp;
	for (int i = 0; i < Chess::chessBoard.size(); i++)
	{
		temp = "";
		for (int j = 0; j < Chess::chessBoard[i].size(); j++)
		{
			// �Q�צU�檬�p (p.s. �o�̥Ϋܦh���ƪ�code�A�p�G�o�� function �����ٷ|�Ϊ���A�A�ӭק�A�Ӵ�֦��)
			if (i == 0)
			{
				if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
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
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�r �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
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
						temp.append("�� �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�s �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
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
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
						break;
					}
				}
				else if (j == 8)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �� ");
						break;
					case 1:
						temp.append("�N�� ");
						break;
					case 2:
						temp.append("�h�� ");
						break;
					case 3:
						temp.append("�H�� ");
						break;
					case 4:
						temp.append("���� ");
						break;
					case 5:
						temp.append("���� ");
						break;
					case 6:
						temp.append("�]�� ");
						break;
					case 7:
						temp.append("���� ");
						break;
					case 8:
						temp.append("���� ");
						break;
					case 9:
						temp.append("�K�� ");
						break;
					case 10:
						temp.append("���� ");
						break;
					case 11:
						temp.append("���� ");
						break;
					case 12:
						temp.append("�X�� ");
						break;
					case 13:
						temp.append("���� ");
						break;
					case 14:
						temp.append("�L�� ");
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
						temp.append("�� ");
						break;
					case 1:
						temp.append("�N");
						break;
					case 2:
						temp.append("�h");
						break;
					case 3:
						temp.append("�H");
						break;
					case 4:
						temp.append("��");
						break;
					case 5:
						temp.append("��");
						break;
					case 6:
						temp.append("�]");
						break;
					case 7:
						temp.append("��");
						break;
					case 8:
						temp.append("��");
						break;
					case 9:
						temp.append("�K");
						break;
					case 10:
						temp.append("��");
						break;
					case 11:
						temp.append("��");
						break;
					case 12:
						temp.append("�X");
						break;
					case 13:
						temp.append("��");
						break;
					case 14:
						temp.append("�L");
						break;
					}
				}
				else if (j == 0)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�� �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
				else if (1 <= j <= 7)
				{
					switch (Chess::chessBoard[i][j])
					{
					case 0:
						temp.append("�q �w ");
						break;
					case 1:
						temp.append("�N�w ");
						break;
					case 2:
						temp.append("�h�w ");
						break;
					case 3:
						temp.append("�H�w ");
						break;
					case 4:
						temp.append("���w ");
						break;
					case 5:
						temp.append("���w ");
						break;
					case 6:
						temp.append("�]�w ");
						break;
					case 7:
						temp.append("��w ");
						break;
					case 8:
						temp.append("�Ӣw ");
						break;
					case 9:
						temp.append("�K�w ");
						break;
					case 10:
						temp.append("�ۢw ");
						break;
					case 11:
						temp.append("���w ");
						break;
					case 12:
						temp.append("�X�w ");
						break;
					case 13:
						temp.append("���w ");
						break;
					case 14:
						temp.append("�L�w ");
						break;
					}
				}
			}
		}
		// ��C��Ū�i�Ȧs�� vector <string>
		rowString[i] = temp;
	}
	// �� rowString Ū�i��Ʀ檺 chessBoard
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
	//�T�{�ﭱ����m
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
			rightPart[3] = "�� �@�@�{�b����@�¦��@�U�ѡ@�@�� ";

		}
		else if (Chess::whoseTurn == 1)
		{
			rightPart[3] = "�� �@�@�{�b����@�����@�U�ѡ@�@�� ";
		}
	}
	else if(Chess::getEnd() ==  0)
	{
		rightPart[3] = "�� �@�@�@�@�¦��@�ӧQ�I�@�@�@�@�� "; 
	}
	else if (Chess::getEnd() == 1)
	{
		rightPart[3] = "�� �@�@�@�@�����@�ӧQ�I�@�@�@�@�� ";
	}
	else if (Chess::getEnd() == 2)
	{
		rightPart[3] = "�� �@�@�@�@�@�@�M���I�@�@�@�@�@�@�� ";			   
	}
	// �᭱�A�����s
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
	string wordBlack = "�N�h�H���]��";
	string wordRed = "�ӥK���X���L";
	string car = "��";
	string red = "��";
	string black = "��";
	string bug1 = "��";
	string bug2 = "��";
	string bug3 = "���";
	int count = 0;

	system("color 0f");
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� " << endl;
	for (int i = 0; i < 21; i++)
	{
		SetColor(15);
		cout << "�� ";
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
		cout << "�@";
		// �ѽL����
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
		cout << "�@";
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
		cout << "�@�� " << endl;
	}
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� " << endl;
}

void Draw::showHint(vector<vector<int>>legalList)
{
	SetColor(208);
	for (int i = 0; i < legalList.size(); i++)
	{
		string word = "�N�h�H���]��ӥK���X���L��";

		int x = legalList[i][0];
		int y = legalList[i][1];

		int X = (y * 4) + 30;
		int Y = (x * 2) + 2;

		gotoxy(X, Y);
		if (Chess::chessBoard[x][y] == 0 && y == 0)
		{
			if (x == 0)
			{
				cout << "�� " << endl;
			}
			else if (x == 9)
			{
				cout << "�� " << endl;
			}
			else
			{
				cout << "�� " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0 && y == 8)
		{
			if (x == 0)
			{
				cout << "�� " << endl;
			}
			else if (x == 9)
			{
				cout << "�� " << endl;
			}
			else
			{
				cout << "�� " << endl;
			}
		}
		else if (Chess::chessBoard[x][y] == 0)
		{
			if (x == 4)
			{
				cout << "�r " << endl;
			}
			else if (x == 5)
			{
				cout << "�s " << endl;
			}
			else if (x == 0 || x == 9)
			{
				cout << "�� " << endl;
			}
			else
			{
				cout << "�q " << endl;
			}
		}
		else
		{
			SetColor(176);
			switch (Chess::chessBoard[x][y])
			{
			case 1:
				cout << "�N" << endl;
				break;
			case 2:
				cout << "�h" << endl;
				break;
			case 3:
				cout << "�H" << endl;
				break;
			case 4:
				cout << "��" << endl;
				break;
			case 5:
				cout << "��" << endl;
				break;
			case 6:
				cout << "�]" << endl;
				break;
			case 7:
				cout << "��" << endl;
				break;
			case 8:
				cout << "��" << endl;
				break;
			case 9:
				cout << "�K" << endl;
				break;
			case 10:
				cout << "��" << endl;
				break;
			case 11:
				cout << "��" << endl;
				break;
			case 12:
				cout << "�X" << endl;
				break;
			case 13:
				cout << "��" << endl;
				break;
			case 14:
				cout << "�L" << endl;
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
	// �H�U�{���X�O���ʴ��
	unsigned short int ch1, ch2;
	unsigned short int X, Y;
	int func;

	// 200 �O�ܦ���V���  (�A�i�H�ոլ�	SetCursorVisible(TRUE, 100);)

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
	// �H�U�{���X�O���ʴ��
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
	regretMenu[3] = "�� �@�@�@�T�w�٭�H�@�@�@�� ";
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
	regretMenu[2] = "�� �@�@�@�C�������@�@�@�@�� ";
	regretMenu[3] = "�� �@�@�O�_���s�}�l�H�@�@�� ";
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
		rightPart[6] = "�� �@�@�@�@�¤�w�Q�N�x�@�@�@�@�@�� ";
	}
	else if (end == 2)
	{
		rightPart[6] = "�� �@�@�@�@����w�Q�N�x�@�@�@�@�@�� ";
	}
}