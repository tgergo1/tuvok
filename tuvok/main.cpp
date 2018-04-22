/* 
 * File:   main.cpp
 * Author: tgergo1
 *
 * Created on April 22, 2018, 1:17 AM
 */

#include <vector>
#include <functional>
#include <thread>

void func1(void* param){
    
}
void func2(void* param){
    
}
void func3(void* param){
    
}

template<typename T=void*>
struct runnable{
    
    int params;
    void *paramp;
    void (*function)(T);
    runnable(void (*function)(T), void *paramp=nullptr, unsigned int params=0){
        this->params=params;
        this->paramp=paramp;
        this->function=function;
    }
    runnable operator()() const{
        (*function)(reinterpret_cast<void*>(params));
    }
    void* fun(){
        return function;             
    }
};

int main(int argc, char** argv) {
    std::vector<std::function<runnable<void*>()>> functions;
    std::vector<std::thread> workers;
    //do shit
    functions.push_back(*(new runnable<>(&func1)));
    functions.push_back(*(new runnable<>(&func2)));
    functions.push_back(*(new runnable<>(&func3)));
    
    runnable<>fun(&func1) ;
    for (auto f : functions){
        workers.push_back(*(new std::thread(fun.function)));
    }
    
    return 0;
}

