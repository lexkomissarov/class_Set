#include <iostream>
using namespace std;

int SetSize = 10; // ������
int* universum = new int[SetSize] { 0, -1, 2, 100, 4000, 5, 6, 7, 8, 9 }; // ��������

class TSet 
{
private:
    bool* _set;
    int getIndex(int n); //�������� ������

public:
    TSet(); // �������
    void add(int n); // ��������
    bool includes(int n); // �����������?
    void remove(int n); // ���������
    bool isEmpty(); // �����?
    void merge(TSet& set); // �����������
    void intercept(TSet& set); // �����������
    void except(TSet& set); // ��������
    TSet getAddition(); // ����������
    void print(); // ������
};

TSet::TSet() // �������
{
    _set = new bool[SetSize];
    for (int i = 0; i < SetSize; ++i) 
    {
        _set[i] = false;
    }
}

void TSet::add(int n) // ��������
{
    int index = getIndex(n);

    if (index != -1) 
    {
        _set[index] = true;
    }
}

bool TSet::includes(int n) // �����������?
{
    int index = getIndex(n);

    return _set[index];
}

void TSet::remove(int n) // ���������
{
    int index = getIndex(n);

    if (index != -1) 
    {
        _set[index] = false;
    }
}

bool TSet::isEmpty() // �����?
{

    for (int i = 0; i < SetSize; ++i) 
    {
        if (_set[i]) 
        {
            return false;
        }
    }

    return true;
}

void TSet::merge(TSet& set) // �����������
{
    for (int i = 0; i < SetSize; i++) 
    {
        if (set._set[i]) 
        {
            _set[i] = true;
        }
    }
}

void TSet::intercept(TSet& set) // �����������
{
    for (int i = 0; i < SetSize; i++)
    {
        if (!set._set[i]) 
        {
            _set[i] = false;
        }
    }
}

void TSet::except(TSet& set) // ��������
{
    for (int i = 0; i < SetSize; i++) 
    {
        if (set._set[i]) 
        {
            _set[i] = false;
        }
    }
}

TSet TSet::getAddition() // ����������
{
    TSet res;

    for (int i = 0; i < SetSize; i++) 
    {
        if (!_set[i]) 
        {
            res._set[i] = true;
        }
    }

    return res;
}

int TSet::getIndex(int n) //�������� ������
{
    for (int i = 0; i < SetSize; i++) 
    {
        if (universum[i] == n) 
        {
            return i;
        }
    }

    return -1;
}

void TSet::print() // ������
{
    for (int i = 0; i < SetSize; i++) 
    {
        if (_set[i]) 
        {
            cout << universum[i] << " ";
        }
    }

    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "");

    TSet set1;
    TSet set2;
    TSet set3;

    set1.add(1);
    set1.add(3);
    set1.add(4);
    set1.add(5);
    set1.add(9);

    set2.add(1);
    set2.add(2);
    set2.add(5);
    set2.add(6);

    set3.add(7);
    set3.add(8);
    set3.add(9);
    set3.add(0);

    cout << "Set 1 = "; set1.print();
    cout << "Set 2 = "; set2.print();
    cout << "Set 3 = "; set3.print();

    cout << "����������� 1 � 2:" << endl;
    set1.merge(set2);
    set1.print();

    cout << endl << "Set 1 = "; set1.print();
    cout << "Set 3 = "; set3.print();

    cout << "�������� 1 - 3:" << endl;
    set1.except(set3);
    set1.print();

    cout << endl << "Set 3 = "; set3.print();

    cout << "���������� 3:" << endl;
    set3.getAddition().print();

    cout << endl << "Set 1 = "; set1.print();

    cout << "1 �������� 5?: " << set1.includes(5) << endl;
    set1.remove(5);
    cout << "�������� 5 �� 1" << endl;
    cout << "1 �������� 5?: " << set1.includes(5) << endl;

    cout << endl << "Set 1 = "; set1.print();
    cout << "Set 2 = "; set2.print();
    set1.intercept(set2);
    cout << "����������� 1 � 2" << endl;
    set1.print();
    set1.add(4000);
    set1.add(8);
    set1.print();

    TSet set4;

    cout << endl << "1 ������?: " << set1.isEmpty() << endl;
    cout << "4 ������?: " << set4.isEmpty() << endl;

    return 0;
}