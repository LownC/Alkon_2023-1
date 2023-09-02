#include <iostream>
using namespace std;
int DP[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= n; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2])%10007;
	}

	cout << DP[n];

	return 0;
}