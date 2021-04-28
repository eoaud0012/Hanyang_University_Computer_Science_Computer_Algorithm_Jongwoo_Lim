#include <stdio.h>
#include <stdlib.h>

int result_arr_element_count = 0;

void Swap(int** arr, int arr_count, int a, int b) {
	int tmp = 0;
	tmp = arr[arr_count + 1][a];
	arr[arr_count + 1][a] = arr[arr_count + 1][b];
	arr[arr_count + 1][b] = tmp;

	return;
}

void Heapify(int** arr, int arr_count, int non_leaf_node_index) {
 	int non_leaf_node = non_leaf_node_index;
	int l_node = non_leaf_node * 2;
	int r_node = non_leaf_node * 2 + 1;
	int smallest_node = non_leaf_node;

	if (l_node <= result_arr_element_count && arr[arr_count + 1][l_node] < arr[arr_count + 1][smallest_node]) {
		smallest_node = l_node;
	}

	if (r_node <= result_arr_element_count && arr[arr_count + 1][r_node] < arr[arr_count + 1][smallest_node]) {
		smallest_node = r_node;
	}

	if (smallest_node != non_leaf_node) {
		Swap(arr, arr_count, smallest_node, non_leaf_node);
		Heapify(arr, arr_count, smallest_node);
	}
	return;
}

void BuildHeap(int** arr, int arr_count) {
	int i = 0;
	int non_leaf_node_index = 0;

	non_leaf_node_index = result_arr_element_count / 2;

	for (i = non_leaf_node_index; i > 0; i -= 1) {
		Heapify(arr, arr_count, i);
	}
	return;
}

void DeleteMin(int** arr, int arr_count) {
	int i = 0;
	int min = 0;

	min = arr[arr_count + 1][1];
	arr[arr_count + 2][(arr[0][arr_count + 2]) + 1] = min;

	(arr[0][arr_count + 2])++;
	(arr[0][arr_count + 1])--;

	return;
}

void ExtractElement(int** arr, int arr_count) {

	int i = 0;

	for (i = 1; i < arr_count + 1; i++) {
		if ( arr[0][i] >= -1 * (arr[i][0]) ) {

			int cur_element = arr[i][-1 * (arr[i][0])];

			arr[arr_count + 1][result_arr_element_count + 1] = cur_element;
			(arr[0][arr_count + 1])++;
			(arr[i][0])--;
			result_arr_element_count++;
		}
	}
	return;
}

void HeapSort(int** arr, int arr_count, int total_element_count) {

	while (arr[0][arr_count + 2] < total_element_count) {

		ExtractElement(arr, arr_count);
		BuildHeap(arr, arr_count);
		DeleteMin(arr, arr_count);
		Swap(arr, arr_count, 1, result_arr_element_count);
		result_arr_element_count -= 1;
		Heapify(arr, arr_count, 1);
	}
	return;
}

int main(void) {

	char ch = 0;
	int fileCheck;
	int arr_count = 0;
	int i = 0;
	int j = 1;
	int k = 1;
	int x = 1;
	int each_arr_element_count = 0;
	int total_element_count = 0;
	int** arr;
	FILE* fp;

	fopen_s(&fp, "input1-2.txt", "rt");

	if (fp == NULL) {
		printf("file open fail\n");
		return -1;
	}

	fscanf_s(fp, "%d", &arr_count);
	arr = (int**)calloc((arr_count + 4), sizeof(int*)); // C6385 WARNING 으로 인해 arr_count + 3 만큼이 아닌, arr_count + 4로 변경. 121 번째 for문에서 마지막으로 i 가 7이 되고 종료되므로, 할당되지 않은 영역인 arr[7]에 접근하여 오류 발생하는 것을 확인.
	if (arr == NULL) {
		printf("error!\n");
		return -1;
	}
	for (i = 0; i < (arr_count + 3); i++) {
		arr[i] = (int*)calloc(100, sizeof(int));
		if (arr[i] == NULL) {
			printf("error!\n");
			return -1;
		}
	}
	

	while (1) {

		fscanf_s(fp, "%d", &arr[j][k]);
		k++;
		total_element_count++;
		each_arr_element_count++;

		ch = fgetc(fp);

		if (ch == '\n') {
			arr[0][j] = each_arr_element_count;
			arr[j][0] = -1;
			each_arr_element_count = 0;
			j++;
			k = 1;
		}
		if (ch == EOF) {
			arr[0][j] = each_arr_element_count;
			arr[j][0] = -1;
			break;
		}


	}


	HeapSort(arr, arr_count, total_element_count);


	for (x; x <= total_element_count; x++) {
		printf("%d ", arr[arr_count + 2][x]);
	}
	printf("\n");



	fileCheck = fclose(fp);
	if (fileCheck != EOF) {
		//printf("file close success\n");
		return 0;
	}
	else {
		printf("file close fail\n");
		return -1;
	}


	return 0;
}