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
	KeysType keys[MAX_NUM_OF_KEY];//�ؼ����б�
	infoType otheritems;//����
	int next;
}SLCell;
typedef struct {
	SLCell r[MAX_SPACE];//��̬����Ŀ����ÿռ䣬r[0]Ϊͷ���
	int keynum;//��¼�ĵ�ǰ�ؼ��ָ���
	int recnum;//��̬����ĵ�ǰ����
}SLList;
typedef int ArrType;


void DealKey(SLList *L);
void RadixSort(SLList *L);