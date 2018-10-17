/*
	@brief:基数排序
	@author:WavenZ
	@time:2018/10/17
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "RadixSort.h"

int main(int argc, char* argv[]) {
	int data;
	SLList S;
	S.recnum = 0;
	S.keynum = 3;
	//产生随机数
	freopen("data.txt", "w", stdout);
	for (int i = 1; i < 10; ++i) {
		printf("%d ", rand() % 1000);
	}
	fclose(stdout);

	//读入测试数据
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 1; (scanf("%d", &data) != -1) && i < 10; ++i) {
		S.r[i].data = data;
		S.recnum += 1;
	}
	//打印测试数据
	printf("Before sort:\n    ");
	for (int i = 1; i <= S.recnum; ++i) {
		printf("%d ", S.r[i].data);
	}
	printf("\n");
	printf("After sort:\n    ");
	//调用算法
	DealKey(&S);
	RadixSort(&S);
	//打印运算结果
	for (int i=S.r[0].next; i; i=S.r[i].next) {
		printf("%d ", S.r[i].data);
	}
	printf("\n");
	//后续处理
	fclose(stdin);
	fclose(stdout);
	system("pause");
	return 1;
}