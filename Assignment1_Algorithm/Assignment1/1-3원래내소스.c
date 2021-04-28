#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* arr, int a, int b) {
	int tmp = 0;
	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	return;
}

int GetMedian(int* index) {
	int i = 0;
	int j = 0;

	if (index[0] < index[1] < index[2]) {
		return index[1];
	}

	for (i = 0; i < 2; i++) {
		for (j = i + 1; j < 3; j++) {
			if (index[i] > index[j]) {
				Swap(index, i, j);
			}
		}
	}

	return index[1];
}

void InsertionSort(int* arr, int start, int end) {
	int i = 0;
	int j = 0;
	int key = 0;

	for (i = start + 1; i < end + 1; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}

}

void GetRandom(int* index, int count) {
	int i = 0;
	int j = 0;
	int key = 0;
	for (i = 0; i < 3; i++) {
		index[i] = rand() % count;
		if (i > 0) {
			for (j = 0; j < i; j++) {
				key = index[j];
				if (key == index[j + 1]) {
					i--;
					break;
				}
			}
		}
	}

	return;
}

int Partition(int* arr, int start, int end) {
	int mid = 0;
	int pivot = 0;
	int i = 0;
	int left = -1;
	int right = 0;
	int* index = (int*)calloc(3, sizeof(int));

	GetRandom(index, end + 1);
	mid = GetMedian(index);
	pivot = arr[mid];

	Swap(arr, mid, end);

	while (i != end) {
		if (arr[i] < pivot) {
			left++;
			Swap(arr, i, left);
		}
		else {
			Swap(arr, i, left + right + 1);
			right++;
		}
		i++;
	}

	Swap(arr, left + 1, end);

	return left + 1;
}

void hybridQuickSort(int* arr, int start, int end) {
	int mid = 0;

	if (end - start + 1 < 11) { // 초기 원소의 값이 10개 이하면 바로 insertion sort 실행
		InsertionSort(arr, start, end);

	}
	else {
		mid = Partition(arr, start, end);
		hybridQuickSort(arr, start, mid);
		hybridQuickSort(arr, mid + 1, end);
	}
	return;
}

int main(void) {

	char ch = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	int fileCheck = 0;
	int* arr;
	clock_t start;
	clock_t end;
	float delay;
	FILE* fp; FILE* fp2;

	srand((unsigned int)time(NULL));

	arr = (int*)calloc(10000, sizeof(int));
	if (arr == NULL) {
		printf("error!\n");
		return -1;
	}

	fopen_s(&fp, "input1-3_2.txt", "rt");

	if (fp == NULL) {
		printf("file open fail\n");
		return -1;
	}

	while (feof(fp) != 1) {

		fscanf_s(fp, "%d", &arr[i]);
		i++;
		count++;
	}

	start = clock();
	hybridQuickSort(arr, 0, count - 1); // 200 ~ 1 내림차순 37초 300 ~ 1 내림차순 튕김
	end = clock();
	delay = (float)(end - start) / CLOCKS_PER_SEC;

	fileCheck = fclose(fp);
	if (fileCheck != EOF) {
		//printf("file close success\n");
	}
	else {
		printf("file close fail\n");
		return -1;
	}

	for (k = 0; k < count; k++) {
		printf("%d ", arr[k]);
	}
	printf("\n");
	printf("%.4fs\n", delay);

	fopen_s(&fp2, "ouput1-3.txt", "w");
	if (fp2 == NULL) {
		printf("file open fail\n");
		return -1;
	}

	for (j = 0; j < count; j++) {
		fprintf(fp2, "%d ", arr[j]);
	}
	fprintf(fp2, "\n");
	fprintf(fp2, "%.4fs\n", delay);

	fileCheck = fclose(fp2);
	if (fileCheck != EOF) {
		//printf("file close success\n");
	}
	else {
		printf("file close fail\n");
		return -1;
	}

	return 0;
}