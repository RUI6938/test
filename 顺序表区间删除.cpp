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
    ElemType data[MAXSIZE];//定义类型（其实就是一个数组，只不过用一个结构体包装了）
    int length;//计算并实时更新数组的长度
}*SqList;//将struct ListNode包装成一个指向这个结构体的指针类型
SqList InitList() {//创建
    SqList L;//创建一个L变量，这个变量是一个指针类型，指向上面那个结构体
    L = (SqList)malloc(sizeof(ListNode));//给L分配动态空间
    L->length = 0;//初始长度为0
    return L;
}
Status ListInsert(SqList L, int i, ElemType e) {//插入操作
   
    if (L->length == MAXSIZE) {//如果表已经满了，则不可在插入其他元素
        return ERROR;
    }
    if (i<1 || i>L->length + 1) {//如果插入的位置不在表内，不可插入,这里的i是要在表中插入的位置，不是索引下标，所以要 i>L->length + 1
        return ERROR;
    }
    if (i <= L->length) {//如果i在表的范围内，则可以进行插入
        for (int k = L->length - 1; k >= i - 1; k--) {//k指向表的最后一个位置，一直找到索引为i-1的位置，也就是位置为i的位置
            L->data[k + 1] = L->data[k];//让其后面的元素位置都向后平移一个单位
        }
    }
    L->data[i - 1] = e;//插入新数据
    L->length++;//更新长度
    return OK;
}
Status ListDelete(SqList L, int i) {//删除数据
    int k;
    if (L->length == 0) {//如果表中没有元素，则不可在删除
        return ERROR;
    }
    if (i<1 || i>L->length) {//不在范围内不可删除，正常应该是i<0||i>L->length-1,但是这里的i是i+1
        return ERROR;
    }
    if (i < L->length) {//在范围内
        for (k = i; k < L->length; k++) {//进行删除，将后面的数据往前移动
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;//更新长度
    return OK;
}
void Ans(SqList L, int x, int y) {//删除指定区间
    
    for (int i = 0; i < L->length; i++) {//从头寻找满足区间的数据
        if (L->data[i] >= x && L->data[i] <= y) {//如果满足
            ListDelete(L, i + 1);//则删除，这里传的是i+1，也就是下一个元素的下标索引位置
            i--;//返回前一个索引位置，即将对新的下一个数据进行查找
        }
    }
}
Status Output(SqList L) {//打印
    int i;
    for (i = 0; i < L->length - 1; i++) {
        printf("%d ", L->data[i]);//输出数据
    }
    printf("%d\n", L->data[L->length - 1]);//输出长度
    return OK;
}
int main() {
    SqList L;
    L = InitList();
    int m, x, y, n;
    scanf("%d", &m);//表的长度
    for (int i = 1; i <= m; i++) {
        scanf("%d", &n);//输入数据
        ListInsert(L, i, n);//插入数据
    }
    scanf("%d%d", &x, &y);//输入删除区间
    Ans(L, x, y);//运算
    Output(L);//打印
    return 0;
}
