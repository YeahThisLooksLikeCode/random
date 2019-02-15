#include <iostream>
#include <string>
#include <vector>

void PrintBoard(std::vector<std::vector<std::string>> strBoard) {
	for (int i = strBoard[0].size()-1; i >= 0; i--) {
		int iBlank1 =12 - strBoard[0][i].length(), iBlank2 = 12 - strBoard[1][i].length();

		std::cout << strBoard[0][i];
		for (int j = 0; j < iBlank1;j++) {
			std::cout << " ";
		}
		std::cout << strBoard[1][i];
		for (int k = 0; k < iBlank2;k++) {
			std::cout << " ";
		}
		std::cout << strBoard[2][i] << "\n";
	}
}
std::vector<int> GetMove() {
	std::vector<int> moves(2);
	std::cout << "\nPick piece to move(1-3): ";
	std::cin >> moves[0];
	std::cout << "\nMake move(1-3): ";
	std::cin >> moves[1];
	moves[0] -= 1;
	moves[1] -= 1;
	return moves;
}
bool CheckMove(std::vector<int> moves, std::vector<std::vector<std::string>> strBoard) {
	std::string piece;
	if (moves[0] == moves[1]) { return false; }
	for (int i = strBoard[moves[0]].size() - 1; i >= 0; i--) {
		if (strBoard[moves[0]][i] != "|") {
			piece = strBoard[moves[0]][i];
			break;
		}
		else if (strBoard[moves[0]][i] == "|" and i == 0) { return false; break; }
	}
	for (int j = strBoard[moves[1]].size() - 1;j >= 0;j--) {
		if(strBoard[moves[1]][j] != "|"){
			if (j == 0 and strBoard[moves[1]][j] == "|") { 
				return true; break;
			}
			else if (strBoard[moves[1]][j].length()>= piece.length()) {
				return true;
				break;
			}
			else {
				return false;
				break;
			}
		}
	}
}
void UpdateBoard(std::vector<int> moves, std::vector<std::vector<std::string>>& strBoard) {
	int n = 0;
	for (int j = 0; j < strBoard.size();j++) {
		if (strBoard[moves[1]][j] == "|") {
			n = j;
			break;
		}
	};
	for (int i=strBoard.size() - 1;i >=0 ;i--) {
		if (strBoard[moves[0]][i] != "|") {
			strBoard[moves[1]][n] = strBoard[moves[0]][i];
			strBoard[moves[0]][i] = "|";
			break;
		}
	}
}
int main() {
	std::vector<std::vector<std::string>> strBoard{ {"######","####","##"},{"|","|","|"},{"|","|","|"} };
	std::vector<std::string> strWin{ "######","####","##" };
	bool gameOver = false;
	std::vector<int>move;
	while (gameOver == false) {
		bool check = false;
		while(check == false){
			PrintBoard(strBoard);
			move = GetMove();
			check = CheckMove(move, strBoard);
			std::cout << "check is: " << check << "\n";
		}
		UpdateBoard(move, strBoard);
		if (strBoard[2] == strWin) {
			gameOver = true;
			std::cout << "You win!\n";
		}
		
	}

	return 0;
}