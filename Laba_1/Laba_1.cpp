// Laba_1.cpp 
// part_3


#include <iostream>

int main()
{
	int* a;
	int n, z = 0;
	printf("Input massive size: ");
	scanf_s("%d", &n);

	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		printf("Input element num %d : ", i + 1);
		scanf_s("%d", &z);
		a[i] = z;
	}

	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}
