#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
	int N, G, K, x = 1;
	vector <tuple<int, int, int>> food;
	vector <tuple<int, int, int>> food_temp;
	//vector <int> G_total_min;
	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		int S, L, O;
		cin >> S >> L >> O;
		food.push_back(make_tuple(S, L, O));
		food_temp.push_back(make_tuple(S, L, O));
	}
	int K_temp = K;
	while (1) {
		int total = 0;
		int j = 0;
		vector <int> index_max(K);
		while (K > 0) { //select to dump
			int calc_max = 0;
			for (int i = 0; i < N; i++) {
				if (calc_max < get<0>(food[i]) * max(1, x - get<1>(food[i])) && get<2>(food[i]) == 1) {
					calc_max = get<0>(food[i]) * max(1, x - get<1>(food[i]));
					index_max[j] = i; // select max G
				}
			}
			get<2>(food[index_max[j]]) = 0;
			K--;
			j++;
		}
		for (int i = 0; i < N; i++) {
			get<2>(food[i]) = 0;
		}
		for (int i = 0; i < j; i++) {
			get<2>(food[index_max[i]]) = 1; //select dump
		}

		for (int i = 0; i < N; i++) { //find total G min for each day
			if (get<2>(food[i]) == 0) { //add which is not able to dump
				total += get<0>(food[i]) * max(1, x - get<1>(food[i])); //calc total min G on day x
			}
		}
		if (total > G)
			break;
		//G_total_min.push_back(total);
		x++;
		K = K_temp;
		food = food_temp;
	}

	cout << x - 1 << endl;

	return 0;
}