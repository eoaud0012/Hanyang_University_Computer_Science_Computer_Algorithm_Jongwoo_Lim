#include <stdio.h>
#include <stdlib.h>

int** CutRod(int* money_per_length_table, int rod_length) {
	int i = 0;
	int j = 1;
	int k = 1;
	int max_money = -1;
	
	// cut_point[0] 자를 지점, cut_point[1] 해당 길이를 잘랐을 경우 최대 금액
	int** cut_point = (int**)malloc(sizeof(int)* 2);
	if (cut_point == NULL) {
		printf("malloc error!\n");
		return -1;
	}
	for (i = 0; i < 2; i++) {
		cut_point[i] = calloc((rod_length + 1), sizeof(int));
		if (cut_point[i] == NULL) {
			printf("malloc error!\n");
			return -1;
		}
	}

	for (j = 1; j < rod_length + 1; j++) {
		for (k = 1; k <= j; k++) {
			if (max_money < money_per_length_table[k] + money_per_length_table[j - k]) {
				max_money = money_per_length_table[k] + money_per_length_table[j - k];
				cut_point[0][j] = k;
				cut_point[1][j] = max_money;
			}
		}
		max_money = -1;
	}

	return cut_point;
}

int main(void) {

	int rod_length = 0;
	int i = 1;
	int fileCheck = 0;
	int* money_per_length;
	int** result;
	FILE* fp;

	fopen_s(&fp, "input2-1.txt", "rt");
	if (fp == NULL) {
		printf("file open fail\n");
		return -1;
	}

	fscanf_s(fp, "%d", &rod_length);
	money_per_length = (int*)calloc((rod_length + 1), sizeof(int));
	if (money_per_length == NULL) {
		printf("malloc error!\n");
		return -1;
	}

	while (!feof(fp)) {
		fscanf_s(fp, "%d", &money_per_length[i++]);
	}

	result = CutRod(money_per_length, rod_length);

	printf("%d\n", result[1][rod_length]);

	// 삼항연산자(길이가 길어 분리하였습니다.)
	rod_length == result[0][rod_length] ? 
	printf("%d %d\n", rod_length - result[0][rod_length], result[0][rod_length]) :
	printf("%d %d\n", result[0][rod_length], rod_length - result[0][rod_length]);

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