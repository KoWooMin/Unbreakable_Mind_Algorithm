#include <bits/stdc++.h>
#define fastio cin.tie(0)->ios::sync_with_stdio(0); cout.tie(0); setvbuf(stdout, nullptr, _IOFBF, BUFSIZ);
#define INF INT64_MAX
// INT32_MIN, INT64_MIN, INT32_MAX, INT64_MAX
using namespace std;
using int64 = int64_t;

int main() {
	fastio;

	while (1) {
		int64 N, M;
		cin >> N >> M;
		if (!(N || M)) break;

		int64 S, D;
		int64 dist[3][500];
		bool needCheck[500] = { false, };
		vector<pair<int64, int64>> vio[1000];
		priority_queue<pair<int64, int64>> pq;

		cin >> S >> D;

		//����ġ �ʱ�ȭ
		for (int64 i = 0; i < 3; ++i) {
			for (int64 j = 0; j < N; ++j) {
				dist[i][j] = INF;
			}
		}

		dist[0][S] = 0;
		dist[1][D] = 0;
		dist[2][D] = 0;
		needCheck[D] = true;

		//����ġ ����
		for (int64 i = 0; i < M; ++i) {
			int64 a, b, c;
			cin >> a >> b >> c;

			vio[a].push_back({ c, b }); // ������ ����ġ
			vio[b + 500].push_back({ c, a }); // ������ ����ġ
		}
		
		//���ͽ�Ʈ�� 3�� ���
		//ù��°: ������������ �ɸ��� �ּڰ� ã��
		//�ι�°: ������������ �ɸ��� �ּڰ� ��Ʈ�� ã��
		//����°: �ּڰ� ��Ʈ �����ϰ� �״��� ����å ��Ʈ ã��
		for (int64 i = 0; i < 3; ++i) {
			dist[0][0]; needCheck[0];
			if (i == 0) pq.push({ 0, S });
			else if (i == 1) pq.push({ 0, D });
			else pq.push({ 0, D });

			while (!pq.empty()) {
				int64 cur = pq.top().second;
				int64 dis = -pq.top().first;
				int64 dir;

				pq.pop();

				if (dist[i][cur] < dis) continue;
				if (i != 0) dir = cur + 500;
				else dir = cur;

				for (auto& iter : vio[dir]) {
					int64 next_c = iter.second;
					int64 next_d = iter.first + dist[i][cur];

					if (i == 1 && dist[0][cur] == dist[0][next_c] + iter.first && needCheck[cur]) needCheck[next_c] = true;
					else if (i == 2 && dist[0][cur] == dist[0][next_c] + iter.first && needCheck[cur]) continue;

					if (dist[i][next_c] > next_d) {
						dist[i][next_c] = next_d;
						pq.push({ -next_d, next_c });
					}
				}
			}
		}

		if (dist[2][S] == INF) cout << -1 << "\n";
		else cout << dist[2][S] << "\n";
	}

	return EXIT_SUCCESS;
}