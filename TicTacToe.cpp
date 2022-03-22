#include <iostream>
#include <string>
#include <vector>

using namespace std;

//константы
char EMPTY = ' ';
char X = 'X';
char O = 'O';
const int NUM_SQUARES = 9;
const char NO_ONE = 'n';
const char TIE='T';
char GotWinner = '0';

void Intro(const vector<char>& board);
void DisplayBoard(vector<char>& board);
char AskYN(string question);
char X_or_O();

void Intro(vector<char>&board) {
	cout << "Hi There, Welcome to TicTacToe";
	DisplayBoard(board);
}
char AskYN(string question)
{
	char response;
	do
	{
		cout << question<<"(y/n)";
		cin >> response;
	} while (response != 'y'&& response != 'n');
	return response;
}
char X_or_O() {
	char WhoFirst = AskYN("Do you want to be first?");
	if (WhoFirst == 'y')
	{
		cout << "You are First";
		return X;
	}
	else
	{
		cout << "I will be first";
		return O;
	}
}
void DisplayBoard(vector<char>& board) {
	for (vector<char>::iterator iter=board.begin();iter!=board.end();++iter)
	{
		
	}
	
	cout <<"\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t---------";
	cout <<"\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t---------";
	cout <<"\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
	
}

char Turn() {//не хватает элемента
	if (X_or_O() == 'X')
		return O;
	else
		return X;
	
}
char AskNum() {
	int NumInTheBoard;
	cout << "Enter num";
	cin>>NumInTheBoard;
	return NumInTheBoard;
}

char Winner(const vector<char>& board)
{
	
	if((board[0]==board[1]&& board[1] == board[2]&&board[0]!= EMPTY) ||
	(board[3] == board[4] && board[5] == board[3]&&board[0]!= EMPTY) ||
	(board[6] == board[7] && board[7] == board[8]&&board[0]!= EMPTY))

	{
		return X;
	}
	else if (count(board.begin(), board.end(), EMPTY) == 0)
	{
		return TIE;
	}
	else {
		return NO_ONE;
	}
}


int main()
{
	vector<char>board(NUM_SQUARES, EMPTY);
	

	Intro(board);

	char HumanPawn = X_or_O();
	cout <<" 'Human Pawn :' " << HumanPawn<<"  ";
	
	cout<<" Winner : " << Winner(board);

	if (Winner(board)!=X)
	{
		DisplayBoard(board);

	}
	
	
	
	
	
	
}
