#ifndef CHESS_H
#define CHESS_H

using namespace std;
class Chess
{
public:
	static vector<vector<int>>chessBoard;
private:
	vector<vector<vector<int>>> chessRecord; //¾ú¥v¬ö¿ýtable
	static vector<string> chessStep; //´ÑÃÐ
	vector<vector<vector<int>>> recordStack; //®¬´Ñªº¦û¦s
	vector<string>stepStack;//®¬´Ñ´Ñ¨Bªº¦û¦s
	vector<vector<int>> legalMoveSpace;
	static int whoseTurn ;
	static int stepNumber ;
	static void recordChessStep(vector<int>ori, vector<int>des);
	static int end;//-1:Ä~Äò 0:¶Â³Ó 1:¬õ³Ó
public:
	friend class Draw;
	Chess(string filename);
	vector<int> selectedChess();
	vector<vector<int>> whereCanGO(vector<int> pos);
	vector<int> moveChess(vector<int> pos);
	void readBoard(string fileName);
	void saveBoard(string fileName);
	void nextPlayer();
	void renewHistory();
	void assignBoard();
	void Undo();
	static void endGame(vector<int>des);
	static int& getEnd();
	static int& getStepNumber();
	int getStackSize();
	int gonnaLost();
};


#endif // CHESS_H