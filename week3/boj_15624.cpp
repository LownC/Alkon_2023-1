#include <iostream>
using namespace std;

int dp[1000000];

int fibo(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		if (dp[n] > 0)
			return dp[n]; //if memo exist
		return dp[n]= fibo(n-2) + fibo(n - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; 
	cin >> n;
	cout << fibo(n) % 1000000007;
	return 0;
}