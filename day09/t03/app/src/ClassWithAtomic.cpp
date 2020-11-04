#include "ClassWithAtomic.h"

//int MultithreadedClass::getInt() const {
//    return m_int;
//}
//
//void MultithreadedClass::add(int addValue) {
//    m_mutex.lock();
//    for (int i = 0; i < abs(addValue); ++i) {
//        ++m_int;
//    }
//    m_mutex.unlock();
//}
//
//void MultithreadedClass::subtract(int subtractValue) {
//    std::lock_guard log (m_mutex);
//    for (int i = 0; i < abs(subtractValue); ++i) {
//        --m_int;
//    }
//}

void ClassWithAtomic::addToInt(int addValue) {
    for (int i = 0; i < abs(addValue); ++i)  {
        ++m_int;
    }
}

void ClassWithAtomic::subtractFromInt(int subtractValue) {
    for (int i = 0; i < abs(subtractValue); ++i)  {
        --m_int;
    }
}

void ClassWithAtomic::pushToVector(int value) {
    std::lock_guard lock(m_vecMutex);
    m_vector.push_back(value);
}

void ClassWithAtomic::eraseFromVector(int value) {
    std::lock_guard lock(m_vecMutex);
    auto iterator = std::remove_if(m_vector.begin(), m_vector.end(), [value](int& i) {
       return i == value;
    });
    m_vector.erase(iterator, m_vector.end());
}

int ClassWithAtomic::getInt() const {
    return m_int;
}

std::vector<int> ClassWithAtomic::getVector() const {
    return m_vector;
}
