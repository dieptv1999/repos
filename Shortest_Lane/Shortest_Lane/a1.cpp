#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
typedef struct Hoso
{
	char hoten[40];
	float diem;
	char loai[11];
} danhsach;
int main()
{
	int n = 0;
	printf("Nhap so hoc sinh:");
	scanf("%d", &n);
	danhsach *d;
	d = (danhsach *)malloc(n * sizeof(danhsach));
	for (int i = 0; i < n; ++i)
	{
		printf("Nhap ho va ten sinh vien %d :", i + 1);
		fflush(stdin);
		gets(d[i].hoten);
		printf("Nhap diem cua hoc sinh :");
		scanf("%f",&d[i].diem);
		switch (int(d[i].diem))
		{
		case 9:case 10:{char c[] = {'G','i','o','i'}; memcpy(d[i].loai,c,5); break;}
		case 7:case 8:{char c1[] = {'K','h','a'}; memcpy(d[i].loai, c1,3); break;}
		case 5:case 6:{char c2[] = {'T','r','u','n','g',' ','b','i','n','h'}; strcpy(d[i].loai, c2); break;}
		default:char c3[] = {'K','o',' ','d','a','t'}; strcpy(d[i].loai, c3); break;
		}
	}
	printf("           XEP LOAI VAN HOA\n");
	printf(" HO VA TEN          DIEM      XEP LOAI\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%-20s%-10.2f%-10s\n", d[i].hoten, d[i].diem, d[i].loai);
	}
	return 0;
}
