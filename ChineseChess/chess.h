#ifndef CHESS_H
#define CHESS_H

using namespace std;
class Chess
{
public:
	static vector<vector<int>>chessBoard;
private:
	vector<vector<vector<int>>> chessRecord; //���v����table
	static vector<string> chessStep; //����
	vector<vector<vector<int>>> recordStack; //���Ѫ����s
	vector<string>stepStack;//���ѴѨB�����s
	vector<vector<int>> legalMoveSpace;
	static int whoseTurn ;
	static int stepNumber ;
	static void recordChessStep(vector<int>ori, vector<int>des);
	static int end;//-1:�~�� 0:�³� 1:����
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