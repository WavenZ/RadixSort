#pragma once
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_OF_KEY 8
#define RADIX 10
#define MAX_SPACE 10
typedef int KeysType;
typedef int infoType;
typedef struct {
	int data;
	KeysType keys[MAX_NUM_OF_KEY];//关键字列表
	infoType otheritems;//其他
	int next;
}SLCell;
typedef struct {
	SLCell r[MAX_SPACE];//静态链表的可利用空间，r[0]为头结点
	int keynum;//记录的当前关键字个数
	int recnum;//静态链表的当前长度
}SLList;
typedef int ArrType;


void DealKey(SLList *L);
void RadixSort(SLList *L);