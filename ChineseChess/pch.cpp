// pch.cpp: 對應到先行編譯過之標頭的來源檔案; 編譯需要此才可成功
#include "pch.h"
void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void SetCursorVisible(BOOL _bVisible, DWORD _dwSize)
{
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = _bVisible;
	CCI.dwSize = _dwSize;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}
// 顏色編碼 請參考 https://blog.wildsky.cc/posts/c-code-note/
void SetColor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
vector<string> intialBoard(vector<string>chessBoard)
{
	chessBoard.push_back("１　２　３　４　５　６　７　８　９");
	chessBoard.push_back("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗ ");
	chessBoard.push_back("║ 　｜　｜　｜＼｜／｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜／｜＼｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜　｜　｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜　｜　｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ┴ ─ ║ ");
	chessBoard.push_back("║ 　　楚河　　　　　　漢界　　　║ ");
	chessBoard.push_back("║ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ┬ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜　｜　｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜　｜　｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜＼｜／｜　｜　｜　║ ");
	chessBoard.push_back("║ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ┼ ─ ║ ");
	chessBoard.push_back("║ 　｜　｜　｜／｜＼｜　｜　｜　║ ");
	chessBoard.push_back("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝ ");
	chessBoard.push_back("九　八　七　六　五　四　三　二　一");
	return chessBoard;
}

// 初始化戰況
vector<string>initialSituation(vector<string>leftPart)
{
	leftPart.push_back("╔ ═ 　戰　況　顯　示　═ ╗ ");//0
	leftPart.push_back("║ 　　　　　　　　　　　║ ");//1
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("║ 　　　　　　　　　　　║ ");
	leftPart.push_back("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝ ");
	return leftPart;
}

// 初始化右側顯示
vector<string>initialRight(vector<string>rightPart)
{
	rightPart.clear();
	rightPart.push_back("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　現在輪到　　色方　下棋　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ║ ");
	rightPart.push_back("║ 　Ｅｓｃ選單　＜悔棋　＞還原　║ ");
	rightPart.push_back("║ 　　　　　　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　Ｅｎｔｅｒ　選取棋子　　　║ ");
	rightPart.push_back("║ 　　Ｓｐａｃｅ　取消選取　　　║ ");
	rightPart.push_back("║ 　　　　↑　　　　　　　　　　║ ");
	rightPart.push_back("║ 　　　←　→　方向鍵控制游標　║ ");
	rightPart.push_back("║ 　　　　↓　　　　　　　　　　║ ");
	rightPart.push_back("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝ ");
	return rightPart;
}

vector<string>initialRegret(vector<string>regretMenu)
{
	regretMenu.clear();
	regretMenu.push_back("╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗ ");
	regretMenu.push_back("║ 　　　　　　　　　　　║ ");
	regretMenu.push_back("║ 　　　　　　　　　　　║ ");
	regretMenu.push_back("║ 　　　確定悔棋？　　　║ ");
	regretMenu.push_back("║ 　　　　　　　　　　　║ ");
	regretMenu.push_back("║ 　　是　　　　否　　　║ ");
	regretMenu.push_back("║ 　　　　　　　　　　　║ ");
	regretMenu.push_back("║ 　　　　　　　　　　　║ ");
	regretMenu.push_back("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝ ");
	return regretMenu;
}
vector<string>initialMainMenu(vector<string>mainMenu)
{
	mainMenu.clear();
	mainMenu.push_back("╔═════════════════╗");
	mainMenu.push_back("║     繼續遊戲    ║");
	mainMenu.push_back("║═════════════════║");
	mainMenu.push_back("║     重新開始    ║");
	mainMenu.push_back("║═════════════════║");
	mainMenu.push_back("║     存檔        ║");
	mainMenu.push_back("║═════════════════║");
	mainMenu.push_back("║     讀檔        ║");
	mainMenu.push_back("║═════════════════║");
	mainMenu.push_back("║     離開遊戲    ║");
	mainMenu.push_back("╚═════════════════╝");
	return mainMenu;
}
// 一般會略過此檔案，但若您目前正使用先行編譯過的標頭，則會先保留該檔案。