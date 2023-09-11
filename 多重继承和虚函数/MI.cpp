#include <iostream>
#include <string>

using namespace std;

//基类：用于派生各行各业的人
class Person{
private:
    string name_;
    string id_;
protected://保护方法常用于基类给派生类提供的内部接口，以简化函数编写，类外部不可访问。
    virtual void Data()const;
    virtual void Get();
public:
    Person():name_("None"),id_("None"){}
    Person(const string& name,const string id):name_(name),id_(id){}
    /*纯虚函数*/
    //纯虚函数的标志就是函数声明后面带有"=0"
    virtual ~Person()=0;//包含纯虚函数的类无法实现为对象，只能作为基类使用
    virtual void Set();
    virtual void Show()const;
    
    
};

//派生类：服务员Waiter
class Waiter:public virtual Person{
private:
    int panache_;
protected:
    virtual void Data()const;
    virtual void Get();
public:
    Waiter():Person(),panache_(0){}
    Waiter(const string & name,const string& id,int panache)
        :Person(name,id),panache_(panache){}
    Waiter(const Person& person,int panache=0):Person(person),panache_(panache){}
    virtual ~Waiter(){}
    virtual void Set();
    virtual void Show()const;

};

//派生类：歌手
class Singer:public virtual Person{
protected:
    //常量定义
    enum{other,alto,contralto,soprano,bass,baritone,tenor};//歌手类型
    enum{Vtypes = 7};//歌手类型数量
    //保护方法
    virtual void Data()const;
    virtual void Get();
private:
    static char*pv_[Vtypes];//?????????????为什么声明为常量
    int voice_;
public:
    Singer():Person(),voice_(other){}
    Singer(const string& name,const string& id,int voice=other)
        :Person(name,id),voice_(voice){}
    Singer(const Person& person,int voice = other)
        :Person(person),voice_(voice){}
    virtual ~Singer(){}
    void Set();
    void Show()const;
};

//多态派生类
/*从歌手和服务员派生出的唱歌服务员类存在致命问题
  那就是：
  1. 一个唱歌服务员有两个基类，也就是由两个人构成的，实际上他是一个人
  2. 对于基类同名的方法，调用时存在二义性*/

/*对于此问题的解决方法就是使用虚基类
  虚基类的虚与虚函数的虚毫无关系，C++只是不想引入新的关键字才这样设置的

  重点：虚基类使得从多个类（他们具有同一个虚函数基类）派生出的对象只继承一个基类对象
  */  
class SingingWaiter:public Singer,public Waiter{
protected:
    virtual void Data()const;
    virtual void Get();
public:
    SingingWaiter(){}
    SingingWaiter(const string& name,const string& id,
        int panache = 0,int voice = Singer::other)
        :Person(name,id),Waiter(name,id,panache),Singer(name,id,voice){}
    SingingWaiter(const Waiter& waiter,int voice = Singer::other)
        :Person(waiter),Waiter(waiter),Singer(waiter,voice){}
    SingingWaiter(const Singer& singer,int panache = 0)
        :Person(singer),Waiter(singer,panache),Singer(singer){}
    //唱歌服务员的基类的基类是虚基类，必须显式地调用虚基类的构造函数。
    SingingWaiter(const Person& person,int p=0,int v = Singer::other)
        :Person(person),Waiter(person,p),Singer(person,v){}
    virtual void Set();
    virtual void Show()const;
};

/*类成员函数实现*/
/************************************************/


/*基类方法*/

Person::~Person(){}//即使析构函数是纯虚函数，也要提供定义

void Person::Get(){
    getline(cin,name_);
    cout<<"请输入身份证号：";
    cin>>id_;
    while(cin.get()!='\n')
        continue;
}

void Person::Data()const{
    cout<<"名字："<<name_<<"\n"<<"身份证号："<<id_<<endl;
}
void Person::Set(){
    cout<<"请输入名字：";
    Get();
}
void Person::Show()const{
    Data();
}

/*服务员方法*/

void Waiter::Get(){
    cout<<"请输入服务员的人气值：";
    cin>>panache_;
    while(cin.get()!='\n')
        continue;    
}

void Waiter::Set(){
    cout<<"请输入服务员的名字：";
    Person::Get();
    Get();
}

void Waiter::Data()const{
    cout<<"人气值："<<panache_<<endl;
}

void Waiter::Show()const{
    cout<<"职业：服务员"<<endl;
    Person::Data();
    Data();
}

/*歌手方法*/
string pv[]={"ohter","alto","contralto",
    "soprano","bass","baritone","tenor"};

void Singer::Get(){
    cout<<"请输入歌手的声音类型："<<endl;
    int i;
    for(i=0;i<Vtypes;i++){
        cout<<i<<":"<<pv[i]<<"    ";
        if(i%4==3)//4个一行
            cout<<endl;

    }
    if(i%4!=0)//超过4个换行
        cout<<endl;

    while(cin>>voice_&&(voice_<0||voice_>=Vtypes))
        cout<<"请重新输入歌手声音类型（在0～7范围内选择）:";
    while(cin.get()!='\n')
        continue;
        
}
void Singer::Set(){
    cout<<"请输入歌手的名字：";
    Person::Get();
    Get();
        
}

void Singer::Data()const{
    cout<<"声音类型："<<voice_<<endl;
}

void Singer::Show()const{
    cout<<"职业：歌手"<<endl;
    Person::Data();
    Data();
}

void SingingWaiter::Get(){
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Data()const{
    Waiter::Data();
    Singer::Data();
}

void SingingWaiter::Set(){
    cout<<"请输入唱歌服务员的名字：";
    Person::Get();
    Get();
}

void SingingWaiter::Show()const{
    cout<<"职业：唱歌服务员";
    Person::Data();
    Data();
}

/*函数入口*/
/***************************************************/
#include<cstring>
const int LIM = 4;
int main(void){
    Person* lolas[LIM];
    int ct;
    for(ct=0;ct<LIM;ct++){
        char choice;
        cout<<"请输入职业：\n"<<"w:waiter  s:singer  t:singing waiter  q:quit\n";
        cin>>choice;
        while(strchr("wstq",choice)==NULL){
            cout<<"请输入 w s t q 中的任意一个:";
            cin>>choice;
        }
        if(choice == 'q')
            break;
        switch(choice){
            case 'w': lolas[ct]=new Waiter;
                      break;
            case 's': lolas[ct]=new Singer;
                      break;
            case 't': lolas[ct]=new SingingWaiter;
                      break;

        }
        cin.get();
        lolas[ct]->Set();
    }

    cout<<"以下是您的员工列表：\n";
    int i;
    for(i=0;i<ct;i++){
        cout<<endl;
        lolas[i]->Show();
    }
    for(i=0;i<ct;i++){
        delete lolas[i];
    }
    cout<<"以上！";


    return 0;
}