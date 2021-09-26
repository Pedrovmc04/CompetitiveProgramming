#include <vector>
#include <algorithm>
using namespace std;
 
long long N, Answer = 0;
long long A[1 << 19], B[1 << 19], C[1 << 19];
long long D[1 << 19];
 
int main() {
	// Step #1. 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
 
	// Step #2. 累積和を取る
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) B[i] = A[i];
		if (i % 2 == 0) B[i] = -A[i];
		C[i] = C[i - 1] + B[i];
	}
 
	// Step #3. 座標圧縮をする
	vector<long long> X;
	for (int i = 0; i <= N; i++) X.push_back(C[i]);
	sort(X.begin(), X.end());
	for (int i = 0; i <= N; i++) C[i] = lower_bound(X.begin(), X.end(), C[i]) - X.begin();
 
 
	// Step #4. 答えを計算する
	for (int i = 0; i <= N; i++) {
		Answer += D[C[i]];
		D[C[i]] += 1;
	}
	cout << Answer << endl;
	return 0;
}