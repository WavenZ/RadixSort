/*
	@brief:基数排序
	@author:WavenZ
	@time:2018/10/17
*/
#define _CRT_SECURE_NO_WARNINGS
#include "RadixSort.h"

void Distribute(SLCell *r, int i, ArrType *f, ArrType *e) {
	//静态链表L的r域中记录已按（key[0],...,key[i-1]）有序。
	//按第i个关键字keys[i]建立RADIX个子表，使同一个字表中记录的keys[i]相同
	//f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表第一个和最后一个记录
	int j;
	for (j = 0; j < RADIX; ++j) f[j] = 0;//各子表记录清空
	for (int p = r[0].next; p; p = r[p].next) {
		j = r[p].keys[i];//j为当前记录的第i个关键字映射到[0..RADIX-1],由于是数字，就是和key一一对应的
		if (!f[j]) f[j] = p;//如果第一个记录不为空，把当前记录作为第一个记录
		else r[e[j]].next = p;//否则，将当前记录添加到最后一个记录后面
		e[j] = p;//将当前记录标记为最后一个记录
	}
}

void Collect(SLCell *r, int i, ArrType* f, ArrType* e) {
	//按keys[i]自小到大地将f[0..RADIX-1]所指各子表一次链接为一个链表
	//e[0..RADIX-1]为各子表的尾指针
	int j;
	int t;
	for (j = 0; !f[j]; ++j);//找到第一个不为空的子表
	r[0].next = f[j];//第一个不为空的子表的第一个记录就是第一个记录
	t = e[j];//t保存当前子表最后一个记录
	while (j < RADIX) {//循环遍历后面的所有子表
		for (j += 1; j < RADIX - 1 && !f[j]; j++);//找到下一个不为空的子表
		if (f[j]>0) {//如果不为空
			r[t].next = f[j];//将之前保存的最后一个记录与当前子表的记录串起来
			t = e[j];//t保存当前子表的最后一个记录
		}
		r[t].next = 0;//将最后一个记录的next域清空
	}
}
void RadixSort(SLList *L) {
	//L是采用静态链表表示的顺序表
	//对L作基数排序，使得L成为按关键字从小到大排列的有序静态链表，L.r[0]为头结点
	ArrType f[RADIX];
	ArrType e[RADIX];
	for (int i = 0; i < L->recnum; ++i) {
		L->r[i].next = i + 1;//将已有的所有元素全部串起来
	}
	L->r[L->recnum].next = 0;//将最后一个元素的next域清空
	for (int i = 1; i <= L->keynum; ++i) {//将所有对所有的关键字进行一次分配和一次收集
		Distribute(L->r, i, f, e);
		Collect(L->r, i, f, e);
	}
}
void DealKey(SLList *L) {
	for (int i = 1; i <= L->recnum; ++i) {
		for (int j = 1; j <= L->keynum; ++j) {
			L->r[i].keys[j] = (L->r[i].data / (int)pow(10,j-1)) % 10;
		}
	}
}