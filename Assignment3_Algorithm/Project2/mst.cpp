#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent(int set[], int x) {
	if (set[x] == x) {
		return x;
	}
	return set[x] = parent(set, set[x]);
}

void Union(int set[], int a, int b) {
	a = parent(set, a);
	b = parent(set, b);

	if (a < b) {
		set[b] = a;
	}
	else {
		set[a] = b;
	}
}

int find(int set[], int a, int b) {
	a = parent(set, a);
	b = parent(set, b);
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

void kruskal(void) {
	int n = 7;
	int m = 11;
	int city_num = 0;
	int city_pair = 0;
	int tmp = 0;
	vector<Edge> v;

	scanf_s("%d %d\n", &city_num, &city_pair);

	while (tmp != city_pair) {
		int node1, node2, weight;
		scanf_s("%d %d %d", &node1, &node2, &weight);
		v.push_back(Edge(node1, node2, weight));
		tmp++;
	}

	sort(v.begin(), v.end());

	int* set = new int[n];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			Union(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
	return;
}
int main(int argc, char* argv[]) {


	kruskal();
}