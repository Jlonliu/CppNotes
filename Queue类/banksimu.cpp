//利用queue类进行atm模拟

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "myqueue.h"

const int MIN_PER_HR=60;
bool newcustomer(double x);

using namespace std;

int main(void){
    srand(time(0));
    cout<<"Case Study:Bank of Heather Automatic Teller\n";
    cout<<"请输入队列最大值: ";
    int qs;
    cin>>qs;
    Queue line(qs);

    cout<<"输入模拟时间(小时)：\n";
    int hours;
    cin>>hours;

    //每分钟一个循环
    long cyclelimit = MIN_PER_HR * hours;

    cout<<"输入平均每小时的客流量：\n";
    double perhour;
    cin>>perhour;
    double min_per_cust;//每位客户平均用时
    min_per_cust = MIN_PER_HR/perhour;

    Item temp;//新客户数据
    long turnaways = 0;//队列满了之后离去的人
    long customers = 0;//进入队列的人
    long served = 0;//模拟中接受服务的人
    long sum_line = 0;//累计队列长度
    int wait_time = 0;//客户所需的处理时间
    long line_wait = 0;//队列总计等待时间

    //每分钟一个循环
    for(int cycle = 0;cycle < cyclelimit;cycle++){
        if(newcustomer(min_per_cust)){
            if(line.isfull()){//队列已满
                turnaways++;//新客户离去
            }
            else{
                customers++;//客户进入队列
                temp.set(cycle);
                line.enqueue(temp);

            }
        }
        if(wait_time <= 0 && !line.isempty()){//如果客户处理时间结束，且队列非空
            line.dequeue();//队首客户离去
            wait_time = temp.ptime();//新客户处理时间
            line_wait += cycle-temp.when();//累加客户服务时间
            served++;//服务完成的客户增加
        }
        if(wait_time > 0){
            wait_time--;

        }
        sum_line += line.queuecount();//每分钟的队列长度的累加和
    }

    if(customers>0){
        cout<<"接收客户："<<customers<<endl;
        cout<<"服务客户："<<served<<endl;
        cout<<"离开客户："<<turnaways<<endl;
        cout<<"平均队列长度：";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<(double)sum_line/cyclelimit<<endl;
        cout<<"平均等待时间："<<(double)line_wait/served<<" minutes\n";

    }
    else{
        cout<<"没有客户\n";
    }


    return 0;
}

bool newcustomer(double x){
    return (rand()*x/RAND_MAX<1);
}