// Laba_1.cpp 
// part_2


#include <iostream>

int main()
{
	int min = 0, max = 100, m = 0;
	int a[10] = { 0 };

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		m = min + rand() % (max - min + 1);
		a[i] = m;
		printf("%d ", a[i]);
	}

	return 0;
}
