#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

main() {
	setlocale (LC_ALL, "Rus");
	
	srand(time(NULL));
	
	int a[100][100];
	int m, n;
	int h[10000];
	
	printf("Введите количество строк массива:");
	scanf("%d", &n);
	
	printf("\n");
	
	printf("Введите количество столбцов массива:");
	scanf("%d", &m);
	
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100 - 50;
		}
	}
	
	printf("Изначальный массив:\n");
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	
	int k = 0;
	while (k < n * m) {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				h[k]=a[i][j];
				k++;
			}
		}
	}
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k-1; j++){
			if (h[j]>h[j+1]) {
				int q = h[j];
				h[j] = h[j+1];
				h[j+1] = q;	
			}
		}
	}
	
	int t = 0, r = m - 1, b = n - 1, l = 0;
	
	int count = 0;
	while (t < b || l < r || count < k) {
		for (int i = l; i <= r; i++) {
			a[t][i] = h[count];
			count++;
		}
		t++;
		if (t > b) break;
		
		for (int i = t; i <= b; i++) {
			a[i][r] = h[count];
			count++;
		}
		r--;
		if (l > r) break;
		
		for (int i = r; i >= l; i--) {
			a[b][i] = h[count];
			count++;
		}
		b--;
		if(t > b) break;
		
		for (int i = b; i >= t; i--) {
			a[i][l] = h[count];
			count++;
		}
		l++;
		if(l > r) break;
	}
	
	printf("Отсортированный массив:\n");
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	
}
