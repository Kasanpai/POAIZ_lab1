// Laba_1.cpp 
// part_1


#include <iostream>

int main()
{
	int min = INT_MAX, max = INT_MIN;
	int a[10] = { 0 };

	for (int i = 0; i < 10; i++) {
		a[i] = i;
		printf("%d ", a[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (a[i] < min) {
			min = a[i]; 
		};
	}

	for (int i = 0; i < 10; i++) {
		if (a[i] < min) {
			min = a[i]; 
		};
	}

	printf("\n%d", max - min);
	printf("\n%d", max);
	printf("\n%d", min);


	return 0;
}
