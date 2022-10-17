#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string p_id;
    string p_name;
    string p_sex;
    int p_age;

public:
    Person(const string &id, const string &name, const string &sex, int age)
        : p_id(id), p_name(name), p_sex(sex), p_age(age)
    {
    }
    void print() const
    {
        cout << "id:" << p_id << endl;
        cout << "name:" << p_name << endl;
        cout << "sex:" << p_sex << endl;
        cout << "p_age:" << p_age << endl;
    }
};

class Student : public Person
{
private:
    string s_id;

public:
    Student(const string &id, const string &name, const string &sex, int age, string &d)
        : Person(id, name, "man", age), s_id(d)
    {
    }
};
class Staff : public Person
{
private:
    string s_id;

public:
    Staff(const string &id, const string &name, const string &sex, int age, const string &d)
        : Person(id, name, "woman", age), s_id(d)
    {
    }
};

class Stud_Staff : public Student, public Staff
{
private:
    int num = 10;

public:
    Stud_Staff(const string &id, const string &name, int age, const string &dd, string ss)
        : Student(id, name, "nan", age, ss), Staff(id, name, "woman", age, dd)
    {
    }
};

int main()
{
    Stud_Staff ss("123456789", "zyq", 20, "2020", "3030");
    ss.Student::print();
    ss.Staff::print();

    Student s1 = ss;
    Staff s2 = ss;
    // Person p = ss;
}
