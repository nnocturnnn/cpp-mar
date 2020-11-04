#pragma once
#include <iostream>
#include <thread>

class Worker {
    public:
    Worker() = default;
    Worker(Worker&) = delete;
    Worker(Worker&&) = delete;
    Worker& operator=(const Worker&) = delete;
    ~Worker() {
        joinThread();
    }
    template <typename Function, class... Args>
    void startWorker(Function&& func, Args&&... args) {
        m_thread = new std::thread(func, std::forward<Args>(args)...);
    }
    void joinThread() {
        if (m_thread) {
            m_thread->join();
            delete m_thread;
            m_thread = nullptr;
        }
    }
    private:
    std::thread* m_thread{nullptr};
};

class TestClass {
    public:
    TestClass() = default;
    ~TestClass() = default;
    void testMember1() {
        std::cout << "testMember1" << std::endl;
    }
    void testMember2(int i) {
        std::cout << "testMember2 " << i << std::endl;
    }
};
