#include <bits/stdc++.h>
// #include "mystack.h"
#include "practice.h"

using namespace std;

int globalId = 100;
class person
{
    string name;
    int id;
    float salary;

public:
    person()
    {
        name = "";
        id = -1;
        salary = 1.0;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalId;
        globalId += 1;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }
    void printPerson()
    {
        cout << "name:" << this->name << " id: " << this->id << " salary: " << this->salary << endl;
    }
};

int main()
{
    // Stack<pair<int, char>> st;

    // st.push(make_pair(1, 'a'));
    // st.push(make_pair(2, 'b'));
    // st.push(make_pair(3, 'c'));

    // while (!st.empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.pop();
    //     cout << chk.first << " " << chk.second << endl;
    // }

    // pair<int, char> s;
    // s = st.Top();
    // cout << s.first << " " << s.second;

    ///////////////

    // stack by class

    // Stack<person> st;

    // person p1("rony das", 545.22);
    // person p2("akib das", 54.23);
    // person p3("ruble dev", 23.00);
    // st.push(p1);
    // st.push(p2);
    // st.push(p3);

    // person sav = st.mid();

    // cout << sav.getName();

    // while (!st.empty())
    // {
    //     person printObj;
    //     printObj = st.pop();
    //     printObj.printPerson();
    // }

    // cout << st.size();

    Stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.midDelete() << endl;
    cout << st.size() << endl;
    cout << st.Top() << endl;
    return 0;
}
