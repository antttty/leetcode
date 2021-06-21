#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int n;
} FizzBuzz;

typedef struct{
    int cur = 1; //对cur进行上锁 即可实现对FizzBuzz的上锁
    pthread_mutex_t  mtxcur = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t   condcur3 = PTHREAD_COND_INITIALIZER;
    pthread_cond_t   condcur5 = PTHREAD_COND_INITIALIZER;
    pthread_cond_t   condcur35 = PTHREAD_COND_INITIALIZER;
    pthread_cond_t   condcur = PTHREAD_COND_INITIALIZER;
}buf;
    
buf   mybuf;
FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    return obj;
}

void fizzBuzzFree(FizzBuzz* obj) {
    pthread_cond_signal(&mybuf.condcur35);
    pthread_cond_signal(&mybuf.condcur3);
    pthread_cond_signal(&mybuf.condcur5);
    pthread_cond_signal(&mybuf.condcur);
}

void mysignal(FizzBuzz* obj){//根据cur不同的值 来signal不同的条件变量
    if (mybuf.cur > obj->n){
        fizzBuzzFree(obj);
        return ;
    }

    if (mybuf.cur % 3 == 0 && mybuf.cur % 5 == 0){
        pthread_cond_signal(&mybuf.condcur35);
    }else if (mybuf.cur % 3 == 0){
        pthread_cond_signal(&mybuf.condcur3);
    }else if (mybuf.cur % 5 == 0){
        pthread_cond_signal(&mybuf.condcur5);
    }else{
        pthread_cond_signal(&mybuf.condcur);
    }

}
// printFizz() outputs "fizz".
void* fizz(void* obj) {
    pthread_mutex_lock(&(mybuf.mtxcur));
    while(mybuf.cur <= ((FizzBuzz*)obj)->n){
        if (mybuf.cur % 3 == 0 && mybuf.cur%5 != 0){
            printf("%s, \n", "fizz");
            mybuf.cur++;
            mysignal((FizzBuzz *)obj);//
        }

        while(!(mybuf.cur <= ((FizzBuzz*)obj)->n &&
             mybuf.cur % 3 == 0 && mybuf.cur%5 != 0 ))
            pthread_cond_wait(&mybuf.condcur3, &mybuf.mtxcur);//等待
    }
    pthread_mutex_unlock(&(mybuf.mtxcur));
}

// printBuzz() outputs "buzz".
void* buzz(void* obj) {
    pthread_mutex_lock(&(mybuf.mtxcur));
    while(mybuf.cur <= ((FizzBuzz*)obj)->n){
        if (mybuf.cur%5 == 0 && mybuf.cur%3 != 0){
            printf("%s, \n", "buzz");
            mybuf.cur++;
            mysignal((FizzBuzz *)obj);
        }

        while( !( mybuf.cur <= ((FizzBuzz*)obj)->n && 
            mybuf.cur%5 == 0 && mybuf.cur%3 != 0))
            pthread_cond_wait(&mybuf.condcur5, &mybuf.mtxcur);//等待
    }
    pthread_mutex_unlock(&(mybuf.mtxcur));
}

// printFizzBuzz() outputs "fizzbuzz".
void* fizzbuzz(void* obj) {
    pthread_mutex_lock(&(mybuf.mtxcur));
    while(mybuf.cur <= ((FizzBuzz*)obj)->n){
        if (mybuf.cur % 3 == 0 && mybuf.cur%5 == 0 ){
            printf("%s, \n", "fizzbuzz");
            mybuf.cur++;
            mysignal((FizzBuzz *)obj);//
        }

        while(!(mybuf.cur < ((FizzBuzz*)obj)->n && mybuf.cur % 3 == 0 && mybuf.cur%5 == 0 ))
            pthread_cond_wait(&mybuf.condcur35, &mybuf.mtxcur);//等待
    }
    pthread_mutex_unlock(&(mybuf.mtxcur));
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void* number(void* obj) {
    pthread_mutex_lock(&(mybuf.mtxcur));
    while(mybuf.cur <= ((FizzBuzz*)obj)->n){
        if (mybuf.cur %3 !=0 &&  mybuf.cur %3 !=0){
            printf("%d, \n", mybuf.cur);
            mybuf.cur++;
            mysignal((FizzBuzz *)obj);//
        }
        while(!( mybuf.cur <= ((FizzBuzz*)obj)->n && mybuf.cur % 3 != 0 && mybuf.cur%5 != 0 ))
            pthread_cond_wait(&mybuf.condcur, &mybuf.mtxcur);//等待
    }
    pthread_mutex_unlock(&(mybuf.mtxcur));
}

int main(){
    FizzBuzz* myfizzbuzz = fizzBuzzCreate(2);
    pthread_t th[4];
    pthread_create(&th[0], NULL, number, (void *)myfizzbuzz);
    pthread_create(&th[1], NULL, fizz, (void *)myfizzbuzz);
    pthread_create(&th[2], NULL, buzz, (void *)myfizzbuzz);
    pthread_create(&th[3], NULL, fizzbuzz, (void *)myfizzbuzz);
    fizzBuzzFree(myfizzbuzz);
    int i = 0;
    for(i = 0; i < 4; i++){
        pthread_join(th[i], NULL);
    }

    return 0;
}