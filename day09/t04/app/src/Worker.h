#pragma once
#include <iostream>
#include <thread>
#include <future>
#include <vector>

class Worker {
    public:
    Worker() = default;
    ~Worker() = default;
    template <typename Function, class... Args>
    auto startAsync(Function&& func, Args&&... args) {
        return std::async(std::launch::async, func, std::forward<Args>(args)...);
    }
};
