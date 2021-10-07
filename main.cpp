/*
Имеется отсортированный массив целых чисел.
Необходимо разработать функцию insert_sorted,
которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
чтобы упорядоченность контейнера сохранялась.
Реализуйте шаблонную функцию insert_sorted,
которая сможет аналогично работать с любым контейнером,
содержащим любой тип значения.


Сгенерируйте вектор, состоящий из 100 вещественный чисел,
представляющий собой значения аналогового сигнала.
На основе этого массива чисел создайте другой вектор целых чисел,
представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
Выведите получившиеся массивы чисел.
Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым по формуле: .
Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

/*
1
*/

void insert_sorted(vector<int> & a, int b ){
    for_each(a.begin(), a.end(), [](int i) { cout << i << " "; });
    cout << endl;
    auto it = std::lower_bound(a.begin(), a.end(), b);
    a.insert(it, b);
    for_each(a.begin(), a.end(), [](int i) { cout << i << " "; });
    cout << endl;
}


template <typename T> // объявление параметра шаблона функции
void insert_sorted_1(vector<T> & a, T b){
    for_each(a.begin(), a.end(), [](int i) { cout << i << " "; });
    cout << endl;

    auto it = std::lower_bound(a.begin(), a.end(), b);
    a.insert(it, b);

    for_each(a.begin(), a.end(), [](int i) { cout << i << " "; });
    cout << endl;
}

/*
2
*/
void writeRandomValue(vector<double> &vec){
    std::srand(double(std::time(nullptr)));
    //    std::generate(vec.begin(), vec.end(), std:: );
    for(int i = 0; i<(vec.size()); ++i) {
        double high = 100.0, low = 0.0;
        vec[i]=((double) rand()/(static_cast<double>(RAND_MAX) + 1.0))*(high - low) + low;
    }
}

//не понятно как составить выражение для векторов с помощью алгоритмических функций
//не понятен механизм доступа к элементу вектора с помощью алгоритмических функций
//не понятно как написать лямбда функцию для accumulate
double calculate(vector<int> &vec_int, vector<double> &vec_doible){

    //
// return   accumulate(vec_doible.begin(),vec_doible.end(),0, [vec_doible,vec_int](){return vec_doible - vec_int;});
 double summ = 0;
    for(int i = 0; i <vec_doible.size(); i++ ){

     summ += pow((vec_doible[i] - vec_int[i]),2);
}
return summ;

}

/**/
int main()
{



    vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    sort(vec.begin(), vec.end());

    insert_sorted(vec,4);

    vector<double>ADC_analog(100);
    vector<int>ADC_digital;
    writeRandomValue(ADC_analog);
copy(ADC_analog.begin(), ADC_analog.end(), back_inserter(ADC_digital));

cout << "Analog" << endl;
for_each(ADC_analog.begin(), ADC_analog.end(), [](double i) { cout << i << " "; });
 cout << endl;

cout << "Digital" << endl;
for_each(ADC_digital.begin(), ADC_digital.end(), [](double i) { cout << i << " "; });
 cout << endl;

 cout << "Error " << calculate(ADC_digital,ADC_analog);
//

    cout << endl << "Hello World!" << endl;
    return 0;
}
