#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, cnt = 0;
	int start=0, end=0,sum=0;
	vector <int> A;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		A.push_back(input);
	}
	while (true) {
		if (sum >= M) {
			sum -= A[start];
			start++;
		}
		else if (sum < M) {
			if (end == N)
				break;
			sum += A[end];
			end++;
		}
		if (sum == M) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}