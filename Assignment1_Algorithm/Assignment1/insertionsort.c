#include <stdio.h>

int main(void) {
	int arr[8] = { 3, 5, 8, 5, 39, 31, 2, 87 };
	int count = 7;

	for (int i = 1; i < count + 1; i++) {
		int key = arr[i];
		int j = i - 1;
		for (j; j >= 0 && arr[j] > key; j--) {
			
			arr[j + 1] = arr[j];
			
		}
		arr[j + 1] = key;
	}

	for (int i = 0; i < count + 1; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}