#pragma once
#include <iostream>
#include <thread>
#include <vector>

//class MultithreadedClass {
//    public:
//    MultithreadedClass() = default;
//    ~MultithreadedClass() = default;
//    int getInt() const;
//    void add(int addValue);
//    void subtract(int subtractValue);
//    private:
//    int m_int{0};
//    std::mutex m_mutex;
//};

class ClassWithAtomic {
    public:
    ClassWithAtomic() = default;
    ~ClassWithAtomic() = default;
    void addToInt(int addValue);
    void subtractFromInt(int subtractValue);
    void pushToVector(int value);
    void eraseFromVector(int value);
    int getInt() const;
    std::vector<int> getVector() const;
    private:
    std::mutex m_vecMutex;
    std::atomic<int> m_int;
    std::vector<int> m_vector;
};
