#include<thread>
#include<iostream>
#include<mutex>
using namespace std;
mutex mu;
void share_ptr(string s,int id){
        mu.lock();
        cout<<id<<endl;
        mu.unlock();
}
void func1(void){
        for(int i=0;i<6;i++)
            share_ptr("func1 thread",i);
}

int main(){
    thread t1(func1);
    thread t2(func1);
    for(int i=0;i<10;i++)
        share_ptr("main thread",i);

    system("pause");
    return 0;
}