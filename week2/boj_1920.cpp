#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[100000];
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		arr[i] = input;
	}
	sort(arr, arr+N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int input = 0;
		cin >> input;
		int lo = 0, hi = N - 1;
		bool find = false;
		while (lo<=hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] == input) {
				cout << "1" << '\n';
				find = true;
				break;
			}
			else if (arr[mid] < input) {
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		if (!find) {
			cout << "0" << '\n';
		}
	}
	return 0;
}