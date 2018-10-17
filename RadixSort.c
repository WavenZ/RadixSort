/*
	@brief:��������
	@author:WavenZ
	@time:2018/10/17
*/
#define _CRT_SECURE_NO_WARNINGS
#include "RadixSort.h"

void Distribute(SLCell *r, int i, ArrType *f, ArrType *e) {
	//��̬����L��r���м�¼�Ѱ���key[0],...,key[i-1]������
	//����i���ؼ���keys[i]����RADIX���ӱ�ʹͬһ���ֱ��м�¼��keys[i]��ͬ
	//f[0..RADIX-1]��e[0..RADIX-1]�ֱ�ָ����ӱ��һ�������һ����¼
	int j;
	for (j = 0; j < RADIX; ++j) f[j] = 0;//���ӱ��¼���
	for (int p = r[0].next; p; p = r[p].next) {
		j = r[p].keys[i];//jΪ��ǰ��¼�ĵ�i���ؼ���ӳ�䵽[0..RADIX-1],���������֣����Ǻ�keyһһ��Ӧ��
		if (!f[j]) f[j] = p;//�����һ����¼��Ϊ�գ��ѵ�ǰ��¼��Ϊ��һ����¼
		else r[e[j]].next = p;//���򣬽���ǰ��¼��ӵ����һ����¼����
		e[j] = p;//����ǰ��¼���Ϊ���һ����¼
	}
}

void Collect(SLCell *r, int i, ArrType* f, ArrType* e) {
	//��keys[i]��С����ؽ�f[0..RADIX-1]��ָ���ӱ�һ������Ϊһ������
	//e[0..RADIX-1]Ϊ���ӱ��βָ��
	int j;
	int t;
	for (j = 0; !f[j]; ++j);//�ҵ���һ����Ϊ�յ��ӱ�
	r[0].next = f[j];//��һ����Ϊ�յ��ӱ�ĵ�һ����¼���ǵ�һ����¼
	t = e[j];//t���浱ǰ�ӱ����һ����¼
	while (j < RADIX) {//ѭ����������������ӱ�
		for (j += 1; j < RADIX - 1 && !f[j]; j++);//�ҵ���һ����Ϊ�յ��ӱ�
		if (f[j]>0) {//�����Ϊ��
			r[t].next = f[j];//��֮ǰ��������һ����¼�뵱ǰ�ӱ�ļ�¼������
			t = e[j];//t���浱ǰ�ӱ�����һ����¼
		}
		r[t].next = 0;//�����һ����¼��next�����
	}
}
void RadixSort(SLList *L) {
	//L�ǲ��þ�̬�����ʾ��˳���
	//��L����������ʹ��L��Ϊ���ؼ��ִ�С�������е�����̬����L.r[0]Ϊͷ���
	ArrType f[RADIX];
	ArrType e[RADIX];
	for (int i = 0; i < L->recnum; ++i) {
		L->r[i].next = i + 1;//�����е�����Ԫ��ȫ��������
	}
	L->r[L->recnum].next = 0;//�����һ��Ԫ�ص�next�����
	for (int i = 1; i <= L->keynum; ++i) {//�����ж����еĹؼ��ֽ���һ�η����һ���ռ�
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