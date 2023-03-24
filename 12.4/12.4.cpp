using namespace std;
#include <iostream>
#include <cstdlib>
typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    if (L != NULL)
    {
        Elem* T = L;
        while (T->link != L)
            T = T->link; // 3
        T->link = tmp; // 4
    }
    else
    {
        L = tmp; // 5
    }
    tmp->link = L; // 6
}

Info remove(Elem*& L)
{
    Elem* T = L;
    while (T->link != L)
        T = T->link; // 1
    Info value = L->info; // 2
    if (T != L)
    {
        Elem* tmp = L->link; // 3
        delete L; // 4
        L = tmp; // 5
        T->link = L; // 6
    }
    else
    {
        delete L; // 4
        L = NULL; // 7
    }
    return value; // 8
}
bool hasAdjacentDuplicates(Elem* L) {
    if (L == NULL) {
        return false;
    }
    Elem* current = L;
    do {
        if (current->info == current->link->info) {
            return true;
        }
        current = current->link;
    } while (current != L);
    return false;
}
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void display(Elem* L)
{
    if (L == NULL) // перевірка на наявність елементів у списку
    {
        std::cout << "Список порожній" << std::endl;
        return;
    }

    Elem* tmp = L;
    do // обхід списку
    {
        std::cout << tmp->info << " ";
        tmp = tmp->link;
    } while (tmp != L);
    std::cout << std::endl;
}

int main()
{
   
    Elem* L = NULL;
   // Info value = L->info;
  

    for (int i = 1; i <= 10; i++) {
        insert(L, getRandomNumber(1, 6));
    }
    display(L);
        cout << hasAdjacentDuplicates(L);   
    remove(L);
    return 0;
}
