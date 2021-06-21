#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
using namespace std;

class FizzBuzz{
private:
    int n;
    int cur = 1;

    mutex mtx;
    condition_variable fizzcv;
    condition_variable buzzcv;
    condition_variable fizzbuzzcv;
    condition_variable numcv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }
    
    void notify(){
        if (cur < n){
            if (cur % 15 == 0){
                fizzbuzzcv.notify_one();
            }else if (cur % 5 == 0){
                buzzcv.notify_one();
            }else if (cur % 3 == 0){
                fizzcv.notify_one();
            }else
                numcv.notify_one();
        }else{
            fizzbuzzcv.notify_one();
            buzzcv.notify_one();
            fizzcv.notify_one();
            numcv.notify_one();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(cur <= n){
            unique_lock<mutex>  lk(mtx);
            while(cur%3!=0 || cur%15==0)
                fizzcv.wait(lk);
            if (cur <= n){
                printFizz();
                cur++;  
                notify();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(cur <= n){
            unique_lock<mutex>  lk(mtx);
            while(cur%5!=0 || cur%15==0)
                buzzcv.wait(lk);
            if (cur <= n){
                printBuzz();
                cur++;
                notify();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(cur <= n){
            unique_lock<mutex>  lk(mtx);
            while(cur%15!=0)
                fizzbuzzcv.wait(lk);
            if (cur <= n){
                printFizzBuzz();
                cur++;
                notify();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(cur <= n){
            unique_lock<mutex>  lk(mtx);//RAII
            while (cur%3==0 || cur%5==0)
                numcv.wait(lk);
            if (cur <= n){
                printNumber(cur);
                cur++;
                notify();
            } 
        }
    }
};

void printFizz(){
    std::cout << "fizz" << std::endl;
}

void printBuzz(){
    std::cout << "buzz" << std::endl;
}

void  printFizzBuzz(){
    std::cout << "fizzbuzz" << std::endl;
}

void number(int x){
    std::cout << x << std::endl;
}
int main(){
    FizzBuzz fizzbuzz(1);
    
    std::thread t1(&FizzBuzz::fizz, &fizzbuzz, std::move(printFizz)); // t5 在对象 fizzbuzz 上运行 FizzBuzz::fizz()
    std::thread t2(&FizzBuzz::buzz, &fizzbuzz, std::move(printBuzz));
    std::thread t3(&FizzBuzz::fizzbuzz, &fizzbuzz, std::move(printFizzBuzz));
    std::thread t4(&FizzBuzz::number, &fizzbuzz, std::move(number));
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;

}

