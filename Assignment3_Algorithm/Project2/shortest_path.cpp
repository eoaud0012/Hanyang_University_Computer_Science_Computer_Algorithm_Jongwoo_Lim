#include <stdio.h>

#define MAX 10000
#define INF 100000

int arr[MAX + 1][MAX + 1];
int visited[MAX + 1];
int dist[MAX + 1];
int vertex, edge;


/*
    
5 8				vertex 갯수 edge 갯수
1 2 2			vertex(source) vertex(destination) weight
1 3 3			
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
   
 
*/


void input() {
	int i = 0, j = 0;
	int source = 0, dest = 0;
	int weight = 0;
	scanf_s("%d %d", &vertex, &edge);

	// 모든 vertex 간 가중치 초기화
	for (i = 1; i <= vertex; i++) {
		for (j = 1; j <= vertex; j++) {
			if (i != j) {
				arr[i][j] = INF;
			}
		}
	}
	// edge 가중치 입력
	for (i = 1; i <= edge; i++) {
		scanf_s("%d %d %d", &source, &dest, &weight);
		arr[source][dest] = weight;
	}

	// 해당 vertex 까지가는 최소 가중치(minimum cost)의 초기화
	for (i = 1; i <= vertex; i++) {
		dist[i] = INF;
	}

}

void dijkstra() {
	int i = 0, j = 0;
	int min = 0, v = 0;

	// 시작점의 초기화, 시작점은 항상 1
	dist[1] = 0;        

	for (i = 1; i <= vertex; i++) {
		min = INF;
		for (j = 1; j <= vertex; j++) {
			if (visited[j] == 0 && min > dist[j]) {    // 모든 vertex 중 최소 비용 vertex 선택, 현재 최소 비용보다 새로이 들어온 값이 적다면 초기화
				min = dist[j];
				v = j;
			}
		}

		visited[v] = 1;   // 해당 vertex 방문 mark

		for (j = 1; j <= vertex; j++) {
			if (dist[j] > dist[v] + arr[v][j]) {       // 현재 최소비용보다 더 작은 값이 나오면 그 값으로 대체
				dist[j] = dist[v] + arr[v][j];
			}
		}
	}
}


int main(void)
{
	input();
	dijkstra();
	printf("%d \n", dist[vertex]);
	return 0;
}
