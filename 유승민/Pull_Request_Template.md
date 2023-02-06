## BOJ_5719_P5_거의 최단 경로
- 그래프, 다익스트라
- https://www.acmicpc.net/problem/5719


## 풀이

도착지점까지 걸리는 최솟값을 찾기위해 다익스트라 한번,
도착지점까지 지나는 경로를 찾기위해 다익스트라 또 한번,
최적의 경로를 제외하고 차선의 경로를 찾기위해 다익스트라 또 한번
총 다익스트라 세번을 사용하여 문제를 해결하였습니다.

<br>


여기서 나가는 가중치는 최선의 경로를 찾고, 
차선의 경로를 찾는데 활용됩니다.

<br>

```cpp
//가중치 설정
		for (int64 i = 0; i < M; ++i) {
			int64 a, b, c;
			cin >> a >> b >> c;

			vio[a].push_back({ c, b }); // 들어오는 가중치
			vio[b + 500].push_back({ c, a }); // 나가는 가중치
		}
```

<br>

다익스트라 3번 사용
첫번째: 도착지점까지 걸리는 최솟값 찾기
두번째: 도착지점까지 걸리는 최솟값 루트들 찾기
세번째: 최솟값 루트 제외하고 그다음 차선책 루트 찾기

<br>

```cpp
		for (int64 i = 0; i < 3; ++i) {
			//총 3번 실행

			//다익스트라 
			while (!pq.empty()) {
				...
				...

				if(){
					//특수한 조건부 존재
				}
			}
		}
```

<br>

## 소스코드
```cpp
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

		//가중치 초기화
		for (int64 i = 0; i < 3; ++i) {
			for (int64 j = 0; j < N; ++j) {
				dist[i][j] = INF;
			}
		}

		dist[0][S] = 0;
		dist[1][D] = 0;
		dist[2][D] = 0;
		needCheck[D] = true;

		//가중치 설정
		for (int64 i = 0; i < M; ++i) {
			int64 a, b, c;
			cin >> a >> b >> c;

			vio[a].push_back({ c, b }); // 들어오는 가중치
			vio[b + 500].push_back({ c, a }); // 나가는 가중치
		}
		
		//다익스트라 3번 사용
		//첫번째: 도착지점까지 걸리는 최솟값 찾기
		//두번째: 도착지점까지 걸리는 최솟값 루트들 찾기
		//세번째: 최솟값 루트 제외하고 그다음 차선책 루트 찾기
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
```


<br/>


## 결과 

| 메모리 | 시간 |
| ------ | ---- |
| 2684KB | 104ms |


