#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	cin >> N;
	if (N.find('0')==std::string::npos) {
		cout << -1 << '\n';
		return 0;
	}
	int sum = 0;
	for (char c : N) {
		sum += (c - '0');
	}
	if (sum % 3 != 0) {
		cout << -1 << '\n';
		return 0;
	}
	sort(N.begin(), N.end(), greater<int>());
	cout << N << '\n';
	return 0;
}