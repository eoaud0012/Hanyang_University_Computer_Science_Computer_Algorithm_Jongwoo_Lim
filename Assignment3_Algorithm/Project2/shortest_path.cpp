#include <stdio.h>

#define MAX 10000
#define INF 100000

int arr[MAX + 1][MAX + 1];
int visited[MAX + 1];
int dist[MAX + 1];
int vertex, edge;


/*
    
5 8				vertex ���� edge ����
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

	// ��� vertex �� ����ġ �ʱ�ȭ
	for (i = 1; i <= vertex; i++) {
		for (j = 1; j <= vertex; j++) {
			if (i != j) {
				arr[i][j] = INF;
			}
		}
	}
	// edge ����ġ �Է�
	for (i = 1; i <= edge; i++) {
		scanf_s("%d %d %d", &source, &dest, &weight);
		arr[source][dest] = weight;
	}

	// �ش� vertex �������� �ּ� ����ġ(minimum cost)�� �ʱ�ȭ
	for (i = 1; i <= vertex; i++) {
		dist[i] = INF;
	}

}

void dijkstra() {
	int i = 0, j = 0;
	int min = 0, v = 0;

	// �������� �ʱ�ȭ, �������� �׻� 1
	dist[1] = 0;        

	for (i = 1; i <= vertex; i++) {
		min = INF;
		for (j = 1; j <= vertex; j++) {
			if (visited[j] == 0 && min > dist[j]) {    // ��� vertex �� �ּ� ��� vertex ����, ���� �ּ� ��뺸�� ������ ���� ���� ���ٸ� �ʱ�ȭ
				min = dist[j];
				v = j;
			}
		}

		visited[v] = 1;   // �ش� vertex �湮 mark

		for (j = 1; j <= vertex; j++) {
			if (dist[j] > dist[v] + arr[v][j]) {       // ���� �ּҺ�뺸�� �� ���� ���� ������ �� ������ ��ü
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
