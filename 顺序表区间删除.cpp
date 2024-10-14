#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct ListNode {
    ElemType data[MAXSIZE];//�������ͣ���ʵ����һ�����飬ֻ������һ���ṹ���װ�ˣ�
    int length;//���㲢ʵʱ��������ĳ���
}*SqList;//��struct ListNode��װ��һ��ָ������ṹ���ָ������
SqList InitList() {//����
    SqList L;//����һ��L���������������һ��ָ�����ͣ�ָ�������Ǹ��ṹ��
    L = (SqList)malloc(sizeof(ListNode));//��L���䶯̬�ռ�
    L->length = 0;//��ʼ����Ϊ0
    return L;
}
Status ListInsert(SqList L, int i, ElemType e) {//�������
   
    if (L->length == MAXSIZE) {//������Ѿ����ˣ��򲻿��ڲ�������Ԫ��
        return ERROR;
    }
    if (i<1 || i>L->length + 1) {//��������λ�ò��ڱ��ڣ����ɲ���,�����i��Ҫ�ڱ��в����λ�ã����������±꣬����Ҫ i>L->length + 1
        return ERROR;
    }
    if (i <= L->length) {//���i�ڱ�ķ�Χ�ڣ�����Խ��в���
        for (int k = L->length - 1; k >= i - 1; k--) {//kָ�������һ��λ�ã�һֱ�ҵ�����Ϊi-1��λ�ã�Ҳ����λ��Ϊi��λ��
            L->data[k + 1] = L->data[k];//��������Ԫ��λ�ö����ƽ��һ����λ
        }
    }
    L->data[i - 1] = e;//����������
    L->length++;//���³���
    return OK;
}
Status ListDelete(SqList L, int i) {//ɾ������
    int k;
    if (L->length == 0) {//�������û��Ԫ�أ��򲻿���ɾ��
        return ERROR;
    }
    if (i<1 || i>L->length) {//���ڷ�Χ�ڲ���ɾ��������Ӧ����i<0||i>L->length-1,���������i��i+1
        return ERROR;
    }
    if (i < L->length) {//�ڷ�Χ��
        for (k = i; k < L->length; k++) {//����ɾ�����������������ǰ�ƶ�
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;//���³���
    return OK;
}
void Ans(SqList L, int x, int y) {//ɾ��ָ������
    
    for (int i = 0; i < L->length; i++) {//��ͷѰ���������������
        if (L->data[i] >= x && L->data[i] <= y) {//�������
            ListDelete(L, i + 1);//��ɾ�������ﴫ����i+1��Ҳ������һ��Ԫ�ص��±�����λ��
            i--;//����ǰһ������λ�ã��������µ���һ�����ݽ��в���
        }
    }
}
Status Output(SqList L) {//��ӡ
    int i;
    for (i = 0; i < L->length - 1; i++) {
        printf("%d ", L->data[i]);//�������
    }
    printf("%d\n", L->data[L->length - 1]);//�������
    return OK;
}
int main() {
    SqList L;
    L = InitList();
    int m, x, y, n;
    scanf("%d", &m);//��ĳ���
    for (int i = 1; i <= m; i++) {
        scanf("%d", &n);//��������
        ListInsert(L, i, n);//��������
    }
    scanf("%d%d", &x, &y);//����ɾ������
    Ans(L, x, y);//����
    Output(L);//��ӡ
    return 0;
}
