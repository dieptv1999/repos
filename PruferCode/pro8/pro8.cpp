
#include<stdio.h>
int i, n, A[10000][3], B[10000][2], a, b, M;
int main() {
	/* printf("Nhap N:"); */scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d %d", &A[i][0], &A[i][1]);
		A[i][2] = A[i][0];
	}
	printf("\n");
	/*for(i=0;i<n;i++){printf("%d\t",A[i][2]);}printf("\n");
	 for(i=0;i<n;i++){printf("%d\t",A[i][3]);}*/
	for (int j = 0; j < n; j++) {
		for (int k = 1; k <= n; k++)
		{
			M = 0; a = 0; b = 0;
			for (int t = 0; t < n; t++) { if (A[t][0] == k) { M++; a = 0; b = t; } }
			for (int t = 0; t < n; t++) { if (A[t][1] == k) { M++; a = 1; b = t; } }
			if (M == 1) {
				B[j][0] = A[b][a]; B[j][1] = A[b][a + 1]; for (int l = 0; l < 3; l++) { A[b][l] = n + 1; }
				break;
			}
		}
	}
	if (B[n - 2][1] != 0)

	{ /*for(i=0;i<n;i++){printf("%d ",B[i][0]);}printf("\n");*/
		for (i = 0; i < n - 1; i++) { printf("%d ", B[i][1]); } return 0;
	}
	return 0;
}
/* 9 0 2 0 3 2 4 2 6 2 9 6 1 6 5 9 7 9 8 */
/*10 5 0 2 0 2 3 2 8 7 8 8 9 8 10 4 10 6 10 1 5
 */