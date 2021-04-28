#include <stdio.h>
#include <stdlib.h>

char* LCS(char* first_string, char* second_string) {

	int i = 0;
	int j = 1;
	int k = 1;
	int x = 0;
	int y = 0;
	int z = 0;
	int first_char_count = (int)first_string[0];
	int second_char_count = (int)second_string[0];
	int lcs_count = 0;

	// LCS의 최대 길이는 두 번째 문자열의 문자 갯수
	char* tmp = (char*)calloc(second_char_count + 1, sizeof(char));

	// LCS table 의 열의 갯수는 첫 번째 문자열의 문자 갯수
	int** lcs_table = (int**)malloc(sizeof(int*) * (first_char_count + 1));
	if (lcs_table == NULL) {
		printf("malloc error\n");
		return -1;
	}
	// LCS table 의 행의 갯수는 두 번째 문자열의 문자 갯수
	for (i = 0; i < first_char_count + 1; i++) {
		lcs_table[i] = calloc(second_char_count + 1, sizeof(int));
		if (lcs_table[i] == NULL) {
			printf("malloc error\n");
			return -1;
		}
	}

	for (j = 1; j < first_char_count + 1; j++) {
		for (k = 1; k < second_char_count + 1; k++) {
			if (first_string[j] != second_string[k]) {
				lcs_table[j][k] = lcs_table[j - 1][k] >= lcs_table[j][k - 1] ? lcs_table[j - 1][k] : lcs_table[j][k - 1];
			}
			else {
				lcs_table[j][k] = lcs_table[j - 1][k - 1] + 1;
			}
		}
	}

	x = first_char_count;
	y = second_char_count;
	lcs_count = lcs_table[x][y];
	z = lcs_count;
	
	while (x > 0 && y > 0) {
		int center = lcs_table[x][y];
		int up = lcs_table[x - 1][y];
		int left = lcs_table[x][y - 1];
		if (up >= left && up == center) {
			x--;
			continue;
		}
		else if(up < left) {
			y--;
			continue;
		}
		else {
			tmp[z--] = first_string[x--];
			y--;
		}
	
		
	}


	return tmp;
}

int main(void) {

	char tmp;
	int i = 1;
	int j = 1;
	int k = 1;
	int count = 0;
	int fileCheck = 0;
	char* first;
	char* second;
	char* result;
	FILE* fp;

	first = (char*)malloc(sizeof(char) * 501);
	second = (char*)malloc(sizeof(char) * 501);

	fopen_s(&fp, "input2-2.txt", "rt");
	if (fp == NULL) {
		printf("file open fail\n");
		return -1;
	}

	while ((tmp = fgetc(fp)) != '\n') {
		first[i++] = tmp;
		count++;
	}

	first[0] = (char)count;

	count = 0;

	while ((tmp = fgetc(fp)) != EOF) {
		second[j++] = tmp;
		count++;
	}

	second[0] = (char)count;
	
	result = LCS(first, second);

	while ((tmp = result[k++]) != NULL) {
		printf("%c", tmp);
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