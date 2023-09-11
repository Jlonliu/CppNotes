/*队列类
    特征：
    1. 存储有序的项目序列
    2. 容量有上限
    3. 可以创建空队列
    4. 可以检查队列是否为空
    5. 可以检查队列是否满
    6. 队尾能够添加项目
    7. 队首能够删除项目
    8. 能够确认队列元素的总数

*/
#include<cstdlib>


class Customer{
private:
    long arrive;
    int processtime;
public:
    Customer(){arrive = processtime = 0;}
    void set(long when);
    long when()const{return arrive;}
    int ptime()const{return processtime;}
};

void Customer::set(long when){
    processtime = std::rand()%3+1;
    arrive = when;
}


typedef Customer Item;

class Queue{
    
private:
    enum {Q_SIZE = 10};//常量,Queue的默认存储极限

    /*在类声明中声明的结构、类、枚举是嵌套在类中的，其作用域是整个类*/
    struct Node{
        Item item;
        struct Node* next;
    };

    Node* front;//队列头
    Node* rear;//队列尾

    int items;//队列中的项目数量

    //常量成员变量需要提供初始值
    //1. 定义时直接赋值：const int qsize = 10;
    //2. 构造函数中进行初始化（使用初始化列表）
    const int qsize;//存储元素个数极限


/*
    在这个例子中，如果复制队列时，将会调用默认复制构造函数
    默认复制构造函数会让新对象依然只想原来队列的头尾，并没有另外生成一份新的数据
    此时需要单独编写深度复制构造函数。如果不需要复制队列，又怕意外复制了产生了不可追踪的错误，
    可以使用伪私有方法来使程序报错：
*/
    Queue(const Queue& q):qsize(0){}
    Queue& operator=(const Queue & q){return *this;}
/*
    将复制构造函数和赋值函数定义为私有函数，这样在程序默认调用这两个函数时，
    就会因为使用了类的私有数据而报错
*/

public:
    Queue(int qs = Q_SIZE);//创建一个能够存放qs个元素的队列
    ~Queue();
    bool isempty()const{return items == 0;}
    bool isfull()const{return items == qsize;}
    int queuecount()const{return items;}
    bool enqueue(const Item &item);//添加元素到队尾
    bool dequeue(void);//删除队首元素

};

/* 对于const和&成员必须使用初始化列表：
   初始化工作是在对象创建时完成的，此时尚未执行括号中的任何代码。
   初始化列表只适用于构造函数。*/
//其他成员可以使用初始化列表有可以不使用
Queue::Queue(int qs):qsize(qs){
    front = rear = nullptr;
    items = 0;
}

bool Queue::enqueue(const Item& item){
    if (isfull()){
        return false;
    }
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items ++;
    if(front == nullptr){
        //队列为空的话，让队列头指向新元素
        front = add;
    }
    else{
        //队列不空的话，让队尾元素的后一个指针指向新元素，乖乖排队
        rear->next = add;
    }
    rear = add;//尾部指针移动到新元素上
    return true;

}

bool Queue::dequeue(void){
    if(isempty()){
        return false;
    }
    items--;
    Node * temp = front;//临时存储队列头部元素
    front = front->next;//将头部指针后移
    delete temp;//删除先前存储的头部元素
    if(items == 0){//如果队列空了
        //如果删除一个元素队列就空了，那么队列中就只有一个元素
        //头指针和尾指针都指向这唯一的一个元素
        //头部指针处理了但是尾部指针尚未处理
        rear = nullptr;//尾部指针设置为空
    }//如果队列内不止一个元素，尾部指针指向的和头部指针不同，那么删除队首元素与队尾毫无关系
    return true;
}

Queue::~Queue(){
    Node * temp;
    while(items--){
        temp = front;
        front = front->next;
        delete temp;
    }
}
