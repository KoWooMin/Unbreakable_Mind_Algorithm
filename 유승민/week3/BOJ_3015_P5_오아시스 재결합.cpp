#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT32_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int64 N, A;
int64 Ans = 0;
vector<pair<int64, int64>> vp;

int main() {
	fastio;

	//��� ����ΰ�
	cin >> N;

	//�ʱⰪ ����
	cin >> A;
	vp.push_back({ A, 1 });

	for (int i = 1; i < N; ++i) {
		cin >> A; //�̹��� ������ ����� Ű

		int idx = -1; // Ű�� ������� �Ǻ��� ����

		for (int j = vp.size() - 1; j >= 0; --j) {

			//�ջ���� �� ��������̸� pop
			if (vp[j].first < A) {
				Ans += vp[j].second;
				vp.pop_back();
			}

			//Ű�� ��������̸� idx �� ��ġ �����س���
			else if (vp[j].first == A) {
				Ans += vp[j].second;
				idx = j;
			}

			//Ű�� ū����̸� �Ѹ�ۿ� ����
			else {
				Ans++;
				break;
			}
		}

		// �̹��� ���Դ� ��� ��ġ ����
		if (idx == -1) vp.push_back({ A, 1 });
		else vp[idx].second++;
	}

	cout << Ans;

	return EXIT_SUCCESS;
}