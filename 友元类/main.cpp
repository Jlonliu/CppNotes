#include <iostream>
#include "tv.h"
using namespace std;
int main()
{
    Tv s42;
    cout << "Init\"TV:\n";
    s42.settings();
    cout << "ABC";
    s42.onoff();
    s42.chanup();
    cout << "change\"TV:\n";
    s42.settings();

    Remote grey;
    grey.setchan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "Remote\"TV:\n";
    s42.settings();
    return 0;
}