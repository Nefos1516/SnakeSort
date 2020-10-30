#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale (LC_ALL, "Rus");//setting russian
	
	srand(time(NULL));//random for autocomplete array
	
	int **a;//pointer to pointer to line of elements in two-dimensional array
	int m, n;
	
	printf("Введите количество строк массива:");
	scanf("%d", &n);//input number of lines here
	
	printf("\n");
	
	printf("Введите количество столбцов массива:");
	scanf("%d", &m);//input number of columns here
	
	a = (int**)malloc(n*sizeof(int*));//assignment of memory for pointers to lines
	
	for (int i = 0; i < n ; i++) {
		a[i] = (int*)malloc(m*sizeof(int));//assingment of memory for lines themself
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 100 - 50;//autocompleting array with random numbers from -50 to 50
		}
	}
	
	//output of unsorted array
	printf("Изначальный массив:\n");
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	
	//creating one-dimensional array and filling it with elements of array(a) for easier sorting
	int *h;
	h = (int*)malloc(n*m*sizeof(int));
	
	int k = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			h[k]=a[i][j];
			k++;
		}
	}
	
	//bubble-sort
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k-1; j++){
			if (h[j]>h[j+1]) {
				int q = h[j];
				h[j] = h[j+1];
				h[j+1] = q;	
			}
		}
	}
	
	/*this is borders of array(a), which will help us to put numbers in the right way
	t - top, r - right, b - bottom, l - left*/
	int t = 0, r = m - 1, b = n - 1, l = 0;
	
	int count = 0;//just counter of iterations
	//starting while cycle until our elements will end, or top and bottom or right and left borders will meet
	while (t < b || l < r || count < k) {
		
		//putting sorted elements from array(h) to array(a) from left border to right border
		for (int i = l; i <= r; i++) {
			a[t][i] = h[count];
			count++;
		}
		t++;//our top border is moving down by 1
		if (t > b) break;//breaking out of cycle while if top border is lower than bottom border
		
		//putting sorted elements from array(h) to array(a) from top border to bottom border
		for (int i = t; i <= b; i++) {
			a[i][r] = h[count];
			count++;
		}
		r--;//our right border is moving left by 1
		if (l > r) break;//breaking out of cycle while if right border is more left than left border
		
		//putting sorted elements from array(h) to array(a) from right border to left border
		for (int i = r; i >= l; i--) {
			a[b][i] = h[count];
			count++;
		}
		b--;//our bottom border is moving up by 1
		if(t > b) break;
		
		//putting sorted elements from array(h) to array(a) from bottom border to top border
		for (int i = b; i >= t; i--) {
			a[i][l] = h[count];
			count++;
		}
		l++;//our left border is moving right by 1
		if(l > r) break;
	}
	
	//output of sorted array
	printf("Отсортированный массив:\n");
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
