#pragma once
#include <iostream>
#include <thread>
#include <vector>

class Worker {
    public:
    Worker() = default;
//    Worker(Worker&) = delete;
//    Worker(Worker&&) = delete;
//    Worker& operator=(const Worker&) = delete;
    ~Worker() {
        joinAllThreads();
    }
    template <typename Function, class... Args>
    void startNewThread(Function&& func, Args&&... args) {
        m_workerThreads.push_back(std::thread(func, std::forward<Args>(args)...));
    }
    void joinAllThreads() {
        for (auto& t : m_workerThreads) {
            if (t.joinable()) {
                t.join();
            }
        }
    }
    private:
    std::vector<std::thread> m_workerThreads;
};
