#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* array, int a, int b) {
	int tmp = 0;
	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
	return;
}

void InsertionSort(int* array, int start, int end) {
	int i = 0;
	int j = 0;
	int key = 0;

	for (i = start + 1; i < end + 1; i++) {
		key = array[i];
		for (j = i - 1; j >= 0 && array[j] > key; j--) {
			array[j + 1] = array[j];
		}
		array[j + 1] = key;
	}

}

int GetMedian(int* arr, int start, int end) {
	int mid = start + (end - start) / 2;
	int* tmp = (int*)calloc(3, sizeof(int));
	if (tmp == NULL) {
		return -1;
	}
	tmp[0] = arr[start]; 
	tmp[1] = arr[mid]; 
	tmp[2] = arr[end];

	InsertionSort(tmp, 0, 2);
	
	arr[start] = tmp[0];
	arr[mid] = tmp[1]; 
	arr[end] = tmp[2];


	return arr[mid];
}
int Partition(int* arr, int start, int end) {
	int mid = start + (end - start) / 2;
	int pivot = 0;
	int i = start + 1;
	int left = start - 1;
	int right = 0;
	
	pivot = GetMedian(arr, start, end);

	Swap(arr, mid, end - 1);

	while (i < end - 1) {
		if (arr[i] < pivot) {
			left++;
			Swap(arr, i, left + 1);
		}
		else {
			right++;
			Swap(arr, i, left + right+ 1);
		}
		i++;
	}

	Swap(arr, left + 2, end - 1);

	return left + 2;
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

	fopen_s(&fp, "input1-3.txt", "rt");

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
	hybridQuickSort(arr, 0, count - 1); // index 3개를 랜덤으로 뽑았을 때 ==> 200 ~ 1 내림차순 37초 300 ~ 1 내림차순 튕김
										// median of partitiong => 300 ~ 1 내림차순 0초 , 10000 ~ 1 내림차순 0.0070s 초
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