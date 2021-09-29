/*
   1 Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения, на которые указывают эти указатели.
   2 Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и сортирует указатели по значениям, на которые они указывают.
   3 Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 способа:
        ○ count_if и find
        ○ count_if и цикл for
        ○ цикл for и find
        ○ 2 цикла for

Замерьте время каждого способа подсчета и сделайте выводы.
Справка:
count_if - это алгоритмическая функция из STL, которая принимает 3 параметра: итератор на начало, итератор на конец и унарный предикат (функцию, принимающую один параметр и возвращающую тип bool).
find - это метод класса string, который возвращает позицию символа (строки), переданного в качестве параметра, в исходной строке. Если символ не найден, то метод возвращает string::npos.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <clocale>

#include "Timer.h"

using namespace std;

/*
Шаблонная фуикция Swap
*/
template <typename T>
void Swap( T *a , T *b){
    T tmp = *b;
    *b = *a;
    *a = tmp;
}

/*
Шаблонная фуикция SortPointers
*/
template <typename T>
void SortPointers(vector<T> *a){
    sort(a->begin(),a->end());
}

//Русские буквы не воспинимает, поэтому используем латинские
char vowelLtter[6]={'a','e', 'i', 'o', 'u','y'};
//Это попытка написать функцию для работы с count_if
bool isVowelLtter(int i, int num)
{
    if (i < num)
        return true;
    else
        return false;
}



/*
Считаем буквы 2 цикла for
*/
int usingFor(string *data, int size){
    Timer timer("for & for");
    int cnt = 0;
    string str = "asdfsadf";
    for(int i = 0; i < size; i++){
        for(int j = 0; j < sizeof(vowelLtter); j++){
           std::string:find
            if((*data) == vowelLtter[j]){//vowelLtter[j]
                cnt++;
                break;
            }
        }
    }
    timer.print();
    return cnt;
}

/**/
int main()
{



    return 0;
}
