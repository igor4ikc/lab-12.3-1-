#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spysok
{
    Spysok* link1,
        * link2;
    inform inf;
};

void Create(Spysok*& first, Spysok*& last, inform inf);
void Cout(Spysok*& T);
void Process(Spysok*& T, inform L1, Spysok*& last);

int main(void)
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Spysok* first = NULL;
    Spysok* last = NULL;

    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        x = rand() % 6;
        Create(first, last, x);
    }

    Spysok* T = first;
    Cout(T);


    int L1;

    cout << "¬вед≥ть L1: ";  cin >> L1;
    cout << endl;


    T = first;
    Process(T, L1, last);
    T = first;
    Cout(T);

    return 0;
}

void Create(Spysok*& first, Spysok*& last, inform inf)
{
    Spysok* tmp = new Spysok;

    tmp->inf = inf;
    tmp->link1 = NULL;
    tmp->link2 = NULL;
    if (first == NULL)
        first = tmp;
    else
    {
        last->link1 = tmp;
        tmp->link2 = last;
    }
    last = tmp;
}

void Cout(Spysok*& T)
{

    inform inf;
    cout << "L2: " << endl;
    while (T != NULL)
    {
        inf = T->inf;
        cout << inf << "   ";
        T = T->link1;
    }
    cout << endl;
}

void Process(Spysok*& T, inform L1, Spysok*& last)
{
    while (T != NULL)
    {
        if (T->inf == L1)
        {
            Spysok* tmp = new Spysok;
            tmp->inf = L1;
            tmp->link1 = T->link1;
            if (T->link1 != NULL)
                T->link1->link2 = tmp;
            else
                last = tmp;
            T->link1 = tmp;
            tmp->link2 = T;
            T = T->link1->link1;
        }
        else
            T = T->link1;
    }
}