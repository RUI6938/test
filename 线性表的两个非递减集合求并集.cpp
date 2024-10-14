#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

#include <iostream>
using namespace std;
struct List 
{
    int _length;
    int _capacity;
    int* _data;

    List(int capacity) 
    {
        _capacity = capacity;
        _length = 0;
        _data = new int[_capacity];
    }

    ~List()
    {
        delete[] _data;
    }
};

bool Insert(List& list, int value) 
{
    //����--�޷�����
    if (list._length == list._capacity)
    {
        return false;
    }
    //����ֵ��ǰһ��ֵС ��������
    if (list._length > 0 && value < list._data[list._length - 1]) 
    {
        return false;
    }
    //��������
    list._data[list._length] = value;
    list._length++;

    return true;
}


List Merge(const List& listA, const List& listB)
{
    List listC(listA._capacity + listB._capacity);
    int i = 0, j = 0;
    while (i < listA._length && j < listB._length) 
    {
        if (listA._data[i] < listB._data[j]) 
        {
            Insert(listC, listA._data[i]);
            i++;
        }
        else 
        {
            Insert(listC, listB._data[j]);
            j++;
        }
    }
    while (i < listA._length) 
    {
        Insert(listC, listA._data[i]);
        i++;
    }
    while (j < listB._length)
    {
        Insert(listC, listB._data[j]);
        j++;
    }

    return listC;
}

void Printf(const List& list) 
{
    for (int i = 0; i < list._length; i++) 
    {
        cout << list._data[i] << " ";
    }
    cout << endl;
}

int main()
{
    int ALen;
    cin >> ALen;

    List listA(ALen);
    for (int i = 0; i < listA._capacity; i++) 
    {
        int value;
        cin >> value;
        if (!Insert(listA, value)) 
        {
            cout << "������������������ֵ��";
            i--;
        }
    }

    int BLen;
    cin >> BLen;

    List listB(BLen);
    for (int i = 0; i < listB._capacity; i++) 
    {
        int value;
        cin >> value;
        if (!Insert(listB, value)) 
        {
            cout << "������������������ֵ��";
            i--;
        }
    }

    Printf(listA);
    Printf(listB);

    List listC = Merge(listA, listB);
    Printf(listC);

    return 0;
}



