/*
1 Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.
2 Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
3 Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for-range-based.

*/

#include <iostream>
#include <list>
#include <iterator>
#include <array>
#include "Timer.h"
using namespace std;

void addList(int listSize){
    int sum = 0;
    list<double>myList;
    myList.resize(listSize);
    for(int i = 0; i < listSize; i++){
        sum += i;//сумма элементов
        myList.push_back((sum/(i+1)));
    }
}

/**/
class Matrix{
private:
static const int matrixSize = 3;
int result = 0;
 //   int matrix[matrixSize][matrixSize];
list<int>line_1 = {1,2,3};
list<int>line_2 = {4,5,6};
list<int>line_3 = {7,8,9};
list<list <int>>matrix = {line_1, line_2, line_3};


public :
    Matrix(){

    }


    int calcMatrix(){
//   return  matrix[0][0]*matrix[1][1]*matrix[2][2] +
//            matrix[1][0]*matrix[2][1]*matrix[0][2] +
//            matrix[2][0]*matrix[1][1]*matrix[0][2] -
//            matrix[0][0]*matrix[2][1]*matrix[1][2] -
//            matrix[1][0]*matrix[0][1]*matrix[2][2];

//cout << matrix.pop_front();

std::cout << line_1.front() << endl;
std::cout << line_1.front() << endl;
std::cout << line_1.front() << endl;

list<int> tmp = matrix.front();
int a = tmp.front();
int b =
for(auto i: line_1)cout << i;
    }
};


/*

*/
int main()
{
Matrix m;
m.calcMatrix();

    cout << "Hello World!" << endl;
    return 0;
}
