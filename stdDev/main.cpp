#include <iostream>
#include <vector>
#include <fstream>
#include <string>

//Reads doubles from a txt file and outputs standard deviation and mean
int stdDev(std::vector<double> a) {
	double mean = 0, dev = 0;
	for (int i = 0; i < a.size(); i++) {
		mean += a[i];
	}
	mean /= a.size();
	for (int j = 0; j < a.size(); j++) {
		dev += std::pow(a[j] - mean, 2);
	}
	dev = sqrt(dev / (a.size() - 1));
	std::cout << "Mean: " << mean << "\n";
	return dev;
}
int main(int argc, char** argv) {
	std::ifstream readFile;
	std::string fileName = argv[1];
	std::vector<double> myVec;

	readFile.open(fileName, std::ios_base::in);
	if (readFile.is_open()) {
		while (readFile.good()) {
			double heyThere;
			readFile >> heyThere;
			myVec.push_back(heyThere);
		}
		readFile.close();
	}
	for (auto i : myVec) {
		std::cout << i << "\n";
	}
	std::cout << "Standard Deviation: " << stdDev(myVec) << "\n";
	return 0;
}