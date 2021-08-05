#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LinkNode
{
	int data;
	struct LinkNode *next;
}LinkNode, *LinkList;

void InitLInkList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void Insert(LinkList &L, int x)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LinkNode));
	p->data = x;
	p->next = L->next;
	L->next = p;
}

void Print(LinkList L)
{
	while (L->next != NULL)
	{
		printf("%d ", L->next->data);
		L = L->next;
	}
}

void Search(LinkList L)
{
	int flag = 1;
	LinkList p = L;
	LinkList mid = L;
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			flag = 0;
			break;
		}
		p = p->next->next;
		mid = mid->next;
	}
	if (flag == 1)
	{
		printf("λ�����м�Ԫ���ǣ�%d\n", mid->data);
	}
	else
	{
		printf("λ�����м��Ԫ�ز����ڣ�\n");
	}
}

int main(){
	int n;
	int e;
	LinkList L;
	InitLInkList(L);
	printf("������Ҫ��ŵ����ݸ�����\n");
	scanf("%d", &n);
	printf("������Ҫ��ŵ����ݣ�\n");
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &e);
		Insert(L, e);
	}
	Print(L);
	Search(L);
	return 0;
}