#include <iostream>
#include <vector>
using namespace std;
class base
{
public:
    friend ostream &operator<<(ostream &o, const base &b);

private:
    virtual ostream &print(ostream &o) const
    {
        return o << "Hello, Base";
    }
};

class derived : public base
{
public:
private:
    virtual ostream &print(ostream &o) const override
    {
        return o << "Hello, Derived";
    }
};

ostream &operator<<(ostream &o, const base &b)
{
    return b.print(o);
}

int main()
{
    base base_obj;
    derived derived_obj;
    vector<base *> v = {&base_obj, &derived_obj};
    for (auto i : v)
    {
        cout << *i << endl;
    }
}