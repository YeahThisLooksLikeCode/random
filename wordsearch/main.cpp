#include <iostream>
#include <string>
#include <regex>
#include <fstream>

int GetMatches(std::string str, std::regex reg) {
	std::sregex_iterator itr(str.begin(), str.end(), reg);
	std::sregex_iterator itr2;
	int i = 0;
	while (itr != itr2) {
		std::smatch match = *itr;
		std::cout << match.str() << "\n";
		itr++;
		i++;
	}
	return i;
}

int main(int argc, char** argv) {
	int i;
	std::string str;
	std::string fileName = argv[1];
	std::ifstream file;
	std::regex reg{ argv[2] };
	file.open(fileName, std::ios_base::in);
	if (file.is_open()) {
		while (file.good()) {
			std::string mid;
			file >> mid;
			str += mid + "\n";
			
		}
		std::cout << str << "\n";
		i = GetMatches(str, reg);
		file.close();
		std::cout << "Matches found: " << i << "\n";
	}

	return 0;
}