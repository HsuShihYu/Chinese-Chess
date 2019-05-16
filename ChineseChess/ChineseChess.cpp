// ChineseChess.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"//內建標頭檔都在這
#include "chess.h"
#include "Draw.h"
int main()
{
	// 讀取檔案
	// 畫初始化棋盤
	// 讀取誰先下
	Chess mainChess("Initial.txt");
	//Chess mainChess("check.txt"); //和局情況
	Draw GUI;

	GUI.renewChess();
	GUI.showOutput();
	mainChess.renewHistory();
	int lose;
	do
	{

		const vector<int>selectError = { -1,-1 };
		const vector<int>regret = { -2,-2 };
		const vector<int>regretUndo = { -3,-3 };
		const vector<int>mainMenu = { -4,-4 };
		//int lose;


	reSelect:
		lose = 3;		// 3 = 正常, 2 = 紅方被將軍, 1 = 黑方被將軍
		vector<int>currentPosition = {};
		vector<int>nextPosition = {};
		vector<vector<int>>legal = {};
		vector<vector<int>>nextLegal = {};

		currentPosition = mainChess.selectedChess();
		if (currentPosition == selectError)
			goto reSelect;
		//悔棋
		else if (currentPosition == regret)
		{
			int change;
			GUI.showRegretMenu();
			change = GUI.selectRegret();
			// 不悔棋

			if (change == 1)
			{
				GUI.showOutput();
				goto reSelect;
			}
			// 悔棋
			else if (change == 0)
			{
				if (Chess::getStepNumber() >= 2)
				{
					mainChess.assignBoard();
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
				else if (Chess::getStepNumber() <= 1)
				{
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
			}
		}
		//還原
		else if (currentPosition == regretUndo)
		{
			int change;
			GUI.showUndoMenu();
			change = GUI.selectRegret();
			//不還原
			if (change == 1)
			{
				GUI.showOutput();
				goto reSelect;
			}
			// 還原
			else if (change == 0)
			{
				if (mainChess.getStackSize() >= 2)
				{
					mainChess.Undo();
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
				else if (mainChess.getStackSize() <= 1)
				{
					GUI.renewChess();
					GUI.showOutput();
					goto reSelect;
				}
			}
		}
		//選單
		else if (currentPosition == mainMenu)
		{
			int change;
			string temp;
			GUI.showMainMenu();
			change = GUI.selectMainMenu();

			switch (change)
			{
			case 0:		// 繼續遊戲
				GUI.showOutput();
				goto reSelect;
				break;
			case 1:		// 重新遊戲
				mainChess.readBoard("Initial.txt");
				Chess::getStepNumber() = 0;
				GUI.clearLeft();
				GUI.clearRight();
				Chess::getEnd() = -1;
				GUI.renewChess();
				GUI.showOutput();
				goto reSelect;
				break;
			case 2:		// 存檔
				system("cls");
				cout << "請 輸 入 檔 名 + .副檔名" << endl;
				cin >> temp;
				mainChess.saveBoard(temp);

				GUI.renewChess();
				GUI.showOutput();
				goto reSelect;
				break;
			case 3:		// 讀檔
				system("cls");
				cout << "請 輸 入 檔 名 + .副檔名" << endl;
				cin >> temp;
				mainChess.readBoard(temp);
				mainChess.renewHistory();
				GUI.clearLeft();
				GUI.renewChess();
				GUI.showOutput();
				goto reSelect;
				break;
			case 4:		// 離開
				system("cls");
				goto end;
				break;
			default:
				break;
			}
		}
		legal = mainChess.whereCanGO(currentPosition);
		if (legal.size() == 0)
			goto reSelect;

		// 提示可下的位置
		GUI.showHint(legal);
		// 移動棋子、改棋盤，畫出棋盤
		nextPosition = mainChess.moveChess(currentPosition);
		if (nextPosition == selectError)
		{
			GUI.renewChess();
			GUI.showOutput();
			goto reSelect;
		}
		// 判斷遊戲結束
		if (Chess::getEnd() >= 0)
		{
			GUI.renewChess();
			GUI.showOutput();
			GUI.showRestartMenu();
			int change;
			change = GUI.selectRegret();
			if (change == 0)//結束遊戲後重新開始
			{
				mainChess.readBoard("Initial.txt");
				Chess::getStepNumber() = 0;
				GUI.clearLeft();
				GUI.clearRight();
				Chess::getEnd() = -1;
				GUI.renewChess();
				GUI.showOutput();
				goto reSelect;
				break;
			}
			else if (change == 1)//結束遊戲後離開程式
			{
				system("cls");
				goto end;
			}
			
		}
		lose = mainChess.gonnaLost();
		if (lose == 1 || lose == 2)
		{
			mainChess.nextPlayer();
			GUI.renewChess();

			GUI.loseRight(lose);
			GUI.showOutput();
			goto reSelect;
		}

		mainChess.nextPlayer();
		mainChess.renewHistory();
		GUI.renewChess();
		GUI.showOutput();
	} while (Chess::getEnd() == -1);
end:
	SetColor(207);
	cout << endl << endl << endl << endl;
	cout << " 已離開象棋遊戲 !! " << endl;
	cout << endl << endl << endl << endl;
	SetColor(15);
	return 0;
}

