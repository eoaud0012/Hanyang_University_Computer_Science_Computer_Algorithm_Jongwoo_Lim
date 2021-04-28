#include <stdio.h>
#include <stdlib.h>

void Swap(int* arr, int a, int b) {
	int tmp = 0;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	return;
}

void Heapify(int* arr, int count, int non_leaf_node_index) {
	int internal_node = non_leaf_node_index;
	int l_node = internal_node * 2;
	int r_node = internal_node * 2 + 1;
	int smallest_node = internal_node;

	if (l_node <= count && arr[l_node] < arr[smallest_node]) {
		smallest_node = l_node;
	}

	if (r_node <= count && arr[r_node] < arr[smallest_node]) {
		smallest_node = r_node;
	}

	if (smallest_node != internal_node) {
		Swap(arr, smallest_node, internal_node);
		Heapify(arr, count, smallest_node);
	}
	return;
}

void BuildHeap(int* arr, int count) {
	int i = 0;
	int non_leaf_node_index = 0;

	non_leaf_node_index = count / 2;

	for (i = non_leaf_node_index; i > 0; i -= 1) {
		Heapify(arr, count, i);
	}
	return;
}

void HeapSort(int* arr, int count) {
	
	BuildHeap(arr, count);

	while (count > 1) {
		Swap(arr, 1, count);
		count -= 1;
		Heapify(arr, count, 1);
	}
	return;
}

int main(void) {
	int i = 1;
	int j = 0;
	int num = 0;
	int count = 0;
	int* arr;

	arr = (int*)malloc(sizeof(int) * 100);
	if (arr == NULL) {
		printf("error");
		return -1;
	}

	while (count < 99) {
		scanf_s("%d", &num);
		if (num == -1) {
			break;
		}
		arr[i] = num;
		count++; i++;
	}

	HeapSort(arr, count);

	printf("\n");

	for (j = 1; j <= count; j++) {
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}