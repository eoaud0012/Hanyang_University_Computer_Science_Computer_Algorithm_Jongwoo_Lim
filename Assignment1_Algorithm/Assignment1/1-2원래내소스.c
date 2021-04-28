#include <stdio.h>
#include <stdlib.h>

int result_arr_element_count = 0;


void Heapify(int** arr, int* result_arr, int arr_count, int total_element_count, int index) {
	int i = 0;
	int tmp = 0;

	for (i = index; i > 1; i /= 2) {
		if (arr[arr_count][i / 2] > arr[arr_count][i]) {
			tmp = arr[arr_count][i / 2];
			arr[arr_count][i / 2] = arr[arr_count][i];
			arr[arr_count][i] = tmp;
		}
	}
	return;
}


void Build_Heapify(int** arr, int* result_arr, int arr_count, int total_element_count) {
	int i = 0;
	int j = 0;


	for (i = result_arr_element_count; i > 0; i--) {
		Heapify(arr, result_arr, arr_count, total_element_count, i);
	}



	return;
}

int DeleteMin(int** arr, int* result_arr, int arr_count, int total_element_count) {
	int i = 0;
	int min = 0;
	int max = 0;
	min = arr[arr_count][1];
	max = arr[arr_count][result_arr_element_count];
	arr[arr_count][1] = max;
	arr[arr_count][result_arr_element_count] = 99999;
	result_arr_element_count--;

	for (i = result_arr_element_count; i > 0; i -= 1) {
		Heapify(arr, result_arr, arr_count, total_element_count, i);
	}

	return min;
}



void DeleteMin_All(int** arr, int* result_arr, int arr_count, int total_element_count) {
	int i = 0;
	int j = 0;

	for (i = 0; i < arr_count; i++) {
		int cur_element = arr[i][-1 * (arr[i][-1 * arr[i][0] + 1])];

		if ((arr[i][0]) == arr[i][-1 * (arr[i][-1 * arr[i][0] + 1])]) {
			continue;
		}
		else {
			arr[arr_count][result_arr_element_count + 1] = cur_element;
			(arr[i][(-1 * (arr[i][0]) + 1)])--;
			result_arr_element_count++;
		}
	}

	Build_Heapify(arr, result_arr, arr_count, total_element_count);

	return;
}


int** HeapSort(int** arr, int arr_count, int total_element_count) {
	int i = 0;
	int j = 0;
	int* result_arr = malloc(sizeof(int) * total_element_count);
	if (result_arr == NULL) {
		printf("error!\n");
		return;
	}
	while (result_arr_element_count != total_element_count) {
		DeleteMin_All(arr, result_arr, arr_count, total_element_count);
		result_arr[i++] = DeleteMin(arr, result_arr, arr_count, total_element_count);
	}

	return result_arr;

}

int main(void) {

	char ch = 0;
	int fileCheck;
	int arr_count = 0;
	int i = 0;
	int j = 0;
	int k = 1;
	int each_arr_element_count = 0;
	int total_element_count = 0;
	int** arr;
	int** result_arr;
	FILE* fp;

	fopen_s(&fp, "input1-2.txt", "r");

	if (fp == NULL) {
		printf("file open fail\n");
		return -1;
	}

	fscanf_s(fp, "%d", &arr_count);
	arr = (int**)malloc(sizeof(int*) * arr_count + 1);
	for (i = 0; i < arr_count + 1; i++) {
		arr[i] = malloc(sizeof(int) * 101);
		if (arr[i] == NULL) {
			printf("error!\n");
			return -1;
		}
	}

	while (1) {
		ch = fgetc(fp);
		if (ch == '\n') {
			arr[j][0] = (-1) * each_arr_element_count;
			arr[j][k] = -1;
			each_arr_element_count = 0;
			j++;
			k = 1;
		}
		if (ch == EOF) {
			arr[j][0] = (-1) * each_arr_element_count;
			arr[j][k] = -1;
			break;
		}

		fscanf_s(fp, "%d", &arr[j][k]);
		k++;
		total_element_count++;
		each_arr_element_count++;
	}

	result_arr = HeapSort(arr, arr_count, total_element_count);






	fileCheck = fclose(fp);
	if (fileCheck != EOF) {
		printf("file close success\n");
	}
	else {
		printf("file close faile\n");
	}
	return 0;
}