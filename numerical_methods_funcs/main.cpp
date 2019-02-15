#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> AddVectors(std::vector<int> a, std::vector<int> b) {
	std::vector<int> c(a.size());
	for (int i = 0; i < a.size();i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}
int DotProduct(std::vector<int> a, std::vector<int> b) {
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += a[i] * b[i];
	}
	return ans;
}
std::vector<int> CrossProduct(std::vector<int> a, std::vector<int> b) {
	std::vector<int> crossProduct;
	for (int i = 0; i < a.size();i++) {
		crossProduct.push_back(a[(i + 1) % a.size()] * b[(i + 2) % b.size()] - a[(i + 2) % a.size()] * b[(i + 1) % b.size()]);
	}
	return crossProduct;
}
int stdDev(std::vector<int> a) {
	double mean = 0, dev = 0;
	for (int i = 0; i < a.size(); i++) {
		mean += a[i];
	}
	mean /= a.size();
	for (int j = 0; j < a.size(); j++) {
		dev += std::pow(a[j] - mean,2);
	}
	dev = sqrt(dev / (a.size() - 1));
	return dev;
}
int Factorial(int n) { 
	int fact=1;
	for (int i = 0; i < n; i++) {
		fact *= n - i;
	}
	return fact;
} 
int Combination(int n, int r) {
	return Factorial(n) / (Factorial(r) * Factorial(n - r));
}
void RiemannIntegral(int n, double a, double b) {
	double ans = 0.0,dx = (b - a)/n, x;

	for (int i = 0; i < n;i++) {
		x = a + i * dx;
		ans += dx * std::cos(x);
	}

	std::cout << "The integral is: " << ans << "\n";
}
void TrapezoidalIntegral(int n, double a, double b) {
	double ans = 0.0, dx = (b - a) / n, x;

	for (int i = 0; i < n; i++) {
		ans += std::cos(a + i * dx);
	}
	ans = dx / 2 * (std::cos(a) + 2 * ans + std::cos(b));
	std::cout << "The Integral is: " << ans << "\n";
}

int main() {
	std::vector<int> a{ 2,3,5 }, b{ 3,1,7 }, c{7,11,5,7,9,3,6,2,10,1,14},d;
	d = CrossProduct(a, b);
	std::cout << "a * b = " << DotProduct(a, b) << "\n";
	std::cout << "a x b = \n";
	for (auto i : d) {
		std::cout << i << "\n";
	}
	stdDev(c);
	std::cout << "C(7,5) = " <<  Combination(7, 5) << "\n";
	RiemannIntegral(10, 1.0,5.0);
	TrapezoidalIntegral(10, 1.0, 5.0);
	std::string y;
	getline(std::cin, y);
	return 0;
}