#ifndef TV_H_
#define TV_H_
#include <iostream>
class Tv
{
private:
    int state;      // 开关
    int volume;     // 音量
    int maxchannel; // 频道最大值
    int channel;    // 频道
    int media;      // 媒体来源
    int mode;       // 模式broadcast或cable
public:
    /*---------HERE---------*/
    /*将另一个类设置为此类的友元*/
    friend class Remote; // Remote可以访问Tv类的私有变量
    /*----------------------*/
    enum
    {
        Off,
        On
    }; // 开关
    enum
    {
        MinVal,
        MaxVal = 20
    }; // 音量大小
    enum
    {
        Antenna,
        Cable
    }; // 频道
    enum
    {
        TV,
        DVD
    }; // 媒体来源

    Tv(int s = Off, int mc = 125) : state(s), maxchannel(mc), volume(5), channel(2), mode(Cable), media(TV) {}
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void setmode() { mode = (mode == Cable) ? Antenna : Cable; }
    void setmedia() { media = (media == TV) ? DVD : TV; }
    void settings() const; // 显示所以设置
};

class Remote
{
private:
    int mode; // 控制TV或者DVD
public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv &t) { return t.volup(); }
    bool voldown(Tv &t) { return t.voldown(); }
    void onoff(Tv &t) { t.onoff(); }
    void chanup(Tv &t) { t.chanup(); }
    void chandown(Tv &t) { t.chandown(); }
    void setchan(Tv &t, int c) { t.channel = c; }
    void setmode(Tv &t) { t.setmode(); }
    void setmedia(Tv &t) { t.setmedia(); }
};
bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}
void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}
void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "off" : "on") << endl;
    if (state == On)
    {
        cout << "Valume = " << volume << endl;
        cout << "Channel = " << channel << endl;
        cout << "Mode = " << mode << endl;
        cout << "Media = " << media << endl;
    }
}

#endif