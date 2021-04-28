#include <stdio.h>
#include <stdlib.h>

void Heapify(int* arr, int count, int index) {
	int i = 0;
	int tmp = 0;

	for (i = index; i > 1; i /= 2) {
		if (arr[i / 2] < arr[i]) {
			tmp = arr[i / 2];
			arr[i / 2] = arr[i];
			arr[i] = tmp;
		}
	}
}
void Build_Heapify(int* arr, int count) {
	int i = 0;
	int tmp = 0;

	for (i = count; i > 0; i -= 1) {
		Heapify(arr, count, i);
	}
	return;
}

int DeleteMax(int* arr, int count) {
	int i = 0;
	int min = 0;
	int max = 0;
	max = arr[1];
	min = arr[count];
	arr[1] = min;
	arr[count] = -99999;
	count--;

	for (i = count; i > 0; i -= 1) {
		Heapify(arr, count, i);
	}

	return max;
}

int* HeapSort(int* arr, int count) {
	int i = 0;
	int* target_arr = arr;
	int* result_arr = malloc(sizeof(int) * (count));
	if (result_arr == NULL) {
		printf("error");
		return;
	}

	Build_Heapify(arr, count);

	for (i = 0; i < count; i++) {
		result_arr[i] = DeleteMax(arr, count);
	}

	return result_arr;
}

int main(void) {
	int i = 1;
	int j = 0;
	int num = 0;
	int count = 0;
	int* arr;
	int* result;

	arr = malloc(sizeof(int) * 100);
	if (arr == NULL) {
		printf("error");
		return -1;
	}

	while (count != 100) {
		scanf_s("%d", &num);
		if (num == -1) {
			break;
		}
		arr[i] = num;
		count++; i++;
	}

	result = HeapSort(arr, count);

	for (j = 0; j < count; j++) {
		printf("%d ", result[j]);
	}
	printf("\n");
	return 0;
}