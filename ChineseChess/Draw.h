#ifndef DRAW_H
#define DRAW_H

//#include"pch.h"
//#include"chess.h"

using namespace std;
class Draw
{
private:
	vector<int>carList;
	static vector<string>chessPart;
	static vector<string>leftPart;
	static vector<string>rightPart;
	vector<string>regretMenu;
	vector<string>mainMenu;
public:
	friend class Chess;
	void showOutput();			// show 邊框 + 戰況 + 棋盤 + 提醒黑紅方下棋 + 操作提示。
	void showHint(vector<vector<int>>legalList);
	void renewChess();
	void showRegretMenu();
	void showUndoMenu();
	void showMainMenu();
	int selectRegret();
	int selectMainMenu();
	void renewRight();
	void renewLeft();
	void renewChessPart();
	void renewCarOrder();
	void clearLeft();
	void clearRight();
	void showRestartMenu();
	void loseRight(int end);
};

#endif // DRAW_H

