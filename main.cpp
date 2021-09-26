#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <optional>
#include <algorithm>

using namespace std;

struct Person{
    string lastName;
    string firstName;
    std::string patronymic;
};

//переопределяем оператор ввода для структуры Person
std::istream& operator>> (std::istream &in, Person &person)
{
    in >> person.firstName;
    in >> person.lastName;
    in >> person.patronymic;
    return in;
}

//переопределяем оператор вывода для структуры Person
std::ostream& operator<< (std::ostream &out, const Person &person)
{
    out << "Person:" << endl;
    out << "    firstName " << person.firstName << endl;
    out << "    firstName " << person.lastName << endl;
    out << "    firstName " << person.patronymic << endl;
    return out;
}


//Для этой структуры перегрузите оператор вывода. Необходимо, чтобы номер телефона
//выводился в формате: +7(911)1234567 12, где 7 – это номер страны, 911 – номер города,
//1234567 – номер, 12 – добавочный номер. Если добавочного номера нет, то его выводить не
//надо.

struct PhoneNumber{
    int countryCode;
    int cityCode;
    string number;
    int extensionNumber;

};
//переопределяем оператор ввода для структуры PhoneNumber
std::istream& operator>> (std::istream &in, PhoneNumber &phoneNumber)
{
    in >> phoneNumber.countryCode;
    in >> phoneNumber.cityCode;
    in >> phoneNumber.number;
    in >> phoneNumber.extensionNumber;
    return in;
}

//переопределяем оператор вывода для структуры PhoneNumber
std::ostream& operator<< (std::ostream &out, const PhoneNumber &phoneNumber)
{
    out << "+" << phoneNumber.countryCode <<"("<<phoneNumber.cityCode<<")"  << phoneNumber.number<<" "<< phoneNumber.extensionNumber<<endl;
    return out;
}


/**/
bool cmp(const std::pair<Person, PhoneNumber> &lhs, const std::pair<Person, PhoneNumber> &rhs)
{
    return lhs.second.number < rhs.second.number;
}


Person person;
PhoneNumber phone;
class PhoneBook{
public:
//private:
    //Это называется вектор пар, здесь хранятся пары
    std::vector<std::pair<Person, PhoneNumber>> phonebook;


public:
    PhoneBook(istream& is) {
        while (!is.eof()) {
            Person person;
            PhoneNumber phone;
            is >> person;
            is >> phone;
            phonebook.push_back(std::make_pair(person, phone));
        }


    }
    ~PhoneBook() {}



    /*
     * Лямбда
     * [внешние переменные доступ ккоторым нужен из тела функции](аргументы функции){тело функции}
     *
     */
    void SortByName(){
        std::sort(phonebook.begin(), phonebook.end(), [](const std::pair<Person, PhoneNumber> &lhs, const std::pair<Person, PhoneNumber> &rhs)
        {
            return lhs.first.lastName < rhs.first.lastName;
        });

    }


    void SortByPhone(){
        std::sort(phonebook.begin(), phonebook.end(), [](const std::pair<Person, PhoneNumber> &lhs, const std::pair<Person, PhoneNumber> &rhs)
        {
            return lhs.second.number < rhs.second.number;
        });
    }

    void GetPhoneNumber(){}
    void ChangePhoneNumber(){}

    void AddData(){//ну надо как-то забить даные


    }
    friend std::istream& operator>> (std::istream &in, PhoneBook &phoneBook);
    friend std::ostream& operator<< (std::ostream &out, const PhoneBook &phoneBook);

};

std::istream& operator>>(std::istream &in, PhoneBook &phoneBook)
{
    in >> person;
    in >> phone;
    auto p = std::make_pair(person, phone);
    phoneBook.phonebook.push_back(p);

    return in;
}

//не переопределяется оператор вывода
//проблема: внутри не видится phoneBook.phonebook.pop_back(); нет такого метода
std::ostream& operator<< (std::ostream &out, const PhoneBook &phoneBook)
{
//    phoneBook.phonebook.?;//что тут должно быть?
    return out;
}






//формат хранения данных в файле?
//как прочитанные данные из файла поместить в вектор пар?
//как при добавлении данных в вектор пар обрабатывать опциональный тип?
//как применить опциональный тип конкретно в этом случае?

int main()
{

    std::string path = "D:\\PhoneBook.txt";
    fstream file(path);//прочитали файл PhoneBook.txt

    if (!file.is_open()){ // если файл не открыт
            cout << "Can not open file!\n"; // сообщить об этом
            return 0;
    }

    PhoneBook book(file);
    cout << book;
    PhoneNumber phone;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
//    cout << book;
//    cout << "------SortByName--------" << endl;
//    book.SortByName();
//    cout << book;
//    cout << "-----GetPhoneNumber-----" << endl;
//    // лямбда функция, которая принимает фамилию и выводит номер телефона
//    //этого человека, либо строку с ошибкой
//            auto print_phone_number = [&book](const string& surname) {
//        cout << surname << "\t";
//        auto answer = book.GetPhoneNumber(surname);
//        if (get<0>(answer).empty())
//            cout << get<1>(answer);
//        else
//            cout << get<0>(answer);
//        cout << endl;
//    };
//    // вызовы лямбды
//    print_phone_number("Ivanov");
//    print_phone_number("Petrov");
//    cout << "----ChangePhoneNumber----" << endl;
//    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
//                           PhoneNumber{7, 123, "15344458", nullopt});
//    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
//                           PhoneNumber{ 16, 465, "9155448", 13 });
//    cout << book;
    cout << "Hello World!" << endl;
    system("pause");
    return 0;
}
