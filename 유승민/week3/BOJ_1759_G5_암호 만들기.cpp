#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

vector<char> v, v1;

//����
inline void Solve(int64 S, int64 rm, int64 am, int64 pos) {
	if (rm < 0)rm = 0; // ����� ������ ���ڰ� �ּ������� ������ 0���� ����
	if (am < 0) am = 0; // ����� ������ ���ڰ� �ּ������� ������ 0���� ����
	if (S - rm - am < 0)return; // ��Ʈ��ŷ (�߿�)
	else if (S == 0) { // ���δ� ������� ���
		for (auto _iter : v1) {
			cout << _iter;
		}
		cout << "\n";
		return;
	}

	//��͸� ���� ���� ����
	for (int64 i = pos; i < v.size(); ++i) {

		// ������ ���
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			v1.push_back(v[i]);
			Solve(S - 1, rm - 1, am, i + 1);
			v1.pop_back();
		}

		//������ ���
		else {
			v1.push_back(v[i]);
			Solve(S - 1, rm, am - 1, i + 1);
			v1.pop_back();
		}
	}
}

int main() {
	fastio;

	int64 L, C;

	cin >> L >> C;
	for (int64 i = 0; i < C; ++i) {
		char a;
		cin >> a;
		v.push_back(a);
	}

	//���Ľ� a c i s t w ������ ��
	sort(v.begin(), v.end());

	// L = �� ���� �ϴ� ����
	// 1 = �ּ� ���� �ϴ� ������ ���� (a, e, i, o u)
	// 2 = �ּ� ���� �ϴ� ������ ���� (������)
	// 0 = ���° index ���� Ž���ؾ� �ϴ°�
	Solve(L, 1, 2, 0);

	return EXIT_SUCCESS;
}