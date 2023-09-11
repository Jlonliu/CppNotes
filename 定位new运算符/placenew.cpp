#include<iostream>
#include<string>
#include<new>

using namespace std;

const int BUF = 512;

class JustTesting{
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Jstr Testing",int n=0){
        words = s;
        number = n;
        cout<<words<<"被构建了"<<endl;
    }
    ~JustTesting(){cout<<words<<"被销毁了"<<endl;}
    void Show()const{cout<<words<<", "<<number<<endl;}
};

int main(void){
    char * buffer = new char[BUF];//申请512位空间

    JustTesting *pc1,*pc2;

    pc1 = new(buffer) JustTesting;//将对象防止在buffer地址处
    pc2 = new JustTesting("Heap1",20);//将对象放在堆中

    cout<<"内存地址：\n"<<"buffer: "<<(void*)buffer<<"    heap: "<<pc2<<endl;
    cout<<"内存数据：\n"<<pc1<<": ";
    pc1->Show();
    cout<<pc2<<": ";
    pc2->Show();

    JustTesting *pc3,*pc4;
    pc3 = new (buffer+sizeof(JustTesting))JustTesting("Bad Idea",6);
    pc4 = new JustTesting("Heap2",10);

    cout<<"内存数据：\n"<<pc1<<": ";
    pc3->Show();
    cout<<pc2<<": ";
    pc4->Show();

    delete pc2;
    delete pc4;
    //如下释放对象内存是错误的
    //delete只能与常规new运算符使用，不能与定位new运算符配合使用
    //此时要释放对象 内存只能显式调用对象的析构函数
    /* 
       delete pc1;
       delete pc3;
    */
    pc1->~JustTesting();
    pc3->~JustTesting();
    //缓冲区内对象都销毁了之后，才能销毁缓冲区buffer
    delete [] buffer;
    cout<<"Done"<<endl;
    
    return 0;
}