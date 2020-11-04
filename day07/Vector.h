#pragma once
#include <iostream>
#include <memory>

namespace CBL {
template <class T>
class Vector {
    public:
    using iterator = T*;

    Vector() : Vector(0) {
    }
    explicit Vector(size_t size) : m_size(size), m_capacity(size) {
        m_buffer = new T[size];
    }

    Vector(size_t size, const T& value) : Vector(size) {
        for(size_t i = 0; i < size; ++i) {
            m_buffer[i] = value;
        }
    }

    Vector(iterator first, iterator last)
        : Vector(std::distance(first, last)){
        std::copy(first, last, this->m_buffer);
    }

    Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
        for(size_t i = 0; i < this->m_size; ++i) {
            m_buffer[i] = *(lst.begin() + i);
        }
    }

    Vector(const Vector<T>& other) : Vector(std::distance(other.begin(), other.end())){
        std::copy(other.begin(), other.end(), this->m_buffer);
    }

    ~Vector() {
        delete[] m_buffer;
    }
    
    //проверил
    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            this->m_buffer = new T[other.size()];
            this->m_size = other.m_size;
            std::copy(other.begin(), other.end(), this->m_buffer);
            if (this->m_capacity < other.m_capacity) {
                this->m_capacity = other.m_capacity;
            }
        }
        return *this;
    }

    bool operator==(const Vector<T>& other) const {
        if ((this->m_size) != other.m_size) {
            return false;
        }
        for (size_t it = 0; it != other.size(); ++it) {
             if ((this->m_buffer)[it] != other[it]) {
                 return false;
             }
        }
        return true;
    }

    bool operator!=(const Vector<T>& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector<T>& other) const {
        return std::lexicographical_compare(m_buffer, m_buffer + m_size, other.m_buffer, other.m_buffer + other.m_size);
    }

    bool operator>(const Vector<T>& other) const {
        return !(*this < other) && (*this != other);
    }

    bool operator<=(const Vector<T>& other) const {
        return *this < other || *this == other;
    }

    bool operator>=(const Vector<T>& other) const {
        return *this > other || *this == other;
    }
    //проверил
    //iterators
    iterator begin() const {
        return m_buffer;
    }

    iterator end() const {
        return m_buffer + m_size;
    }

    //capacity
    size_t size() const {
        return this->m_size;
    }
    size_t capacity() const {
        return this->m_capacity;
    }
    bool isEmpty() const {
        return this->m_size == 0;
    }
    //проверил
    void resize(size_t size, const T& value = T()) {
        T* new_vector = NULL;
        if (size >= this->m_capacity) {
            new_vector = new T[size];
            size_t it = 0;
            for (; it < this->m_size; ++it) {
                new_vector[it] = this->m_buffer[it];
            }
            for (; it < size - this->m_size; ++it) {
                new_vector[it] = value;
            }
        } else if (size < this->m_capacity) {
            new_vector = new T[size];
            for (size_t it = 0; it < size; ++it) {
                new_vector[it] = this->m_buffer[it];
            }
        }
        delete[] this->m_buffer;
        this->m_capacity = size;
        this->m_size = size;
        this->m_buffer = new_vector;
    }

    void reserve(size_t size) {
        T* new_vector;
        if (size > this->m_capacity) {
            this->m_capacity = size;
            new_vector = new T[size];
            size_t it = 0;
            for (; it < this->m_size; ++it) {
                new_vector[it] = this->m_buffer[it];
            }
            for (; it < size; ++it) {
                new_vector[it] = T();
            }
            delete[] this->m_buffer;
            this->m_buffer = new_vector;
        }
    }

    //element access
    T& operator[](size_t index) const {
        return *(this->m_buffer + index);
    }

    T& at(size_t index) const {
        if (index < this->m_size) {
            return *(this->m_buffer + index);
        } else {
            throw(std::out_of_range("Vector: out_of_range"));
        }
    }

    T* data() const {
        return this->m_buffer;
    }

    // modifiers
    void push_back(const T& value) {
        if (this->m_size == this->m_capacity) {
            if (m_capacity == 0) {
                m_capacity = 1;
            }
            this->m_capacity *= 2;
            T* new_vector = new T[this->m_capacity];
            std::copy(this->m_buffer, this->m_buffer + this->m_size, new_vector);
            delete[] this->m_buffer;
            this->m_buffer = new_vector;
            *(m_buffer + m_size) = value;
            this->m_size++;
        }
        else {
            *(m_buffer + m_size) = value;
            this->m_size++;
        }
    }
    void pop_back() {
        (this->m_size)--;
    }

    iterator insert(iterator pos, const T& value) {
        iterator iter;
        size_t distance = std::distance(this->begin(), pos);
        if (distance == m_size && this->m_size == this->m_capacity) {
            this->push_back(value);
            iter = m_buffer + m_size - 1;
        } else {
            iter = pos;
            for(; iter != this->end() - 1; ++iter) {
                *(iter + 1) = *(iter);
            }
            m_buffer[distance] = value;
            iter = pos;
        }
        return iter;
    }

    iterator erase(iterator pos) {
        auto returned = (this->m_buffer + this->m_size);
        if (pos == (this->m_buffer + this->m_size)) {
            returned = (this->m_buffer + this->m_size);
        } else {
            returned = pos;
            for (auto it = pos; it != (this->m_buffer + this->m_size) - 1; ++it) {
                *it = *(it + 1);
            }
        }
        (this->m_size)--;
        return returned;
    }

    iterator erase(iterator first, iterator last) {
        size_t distance = std::distance(first, last);
        if (distance == this->m_size) {
            m_size = 0;
            return nullptr;
        } else {
            auto it = first;
            for (; it != last; ++it) {
                *it = *(it + distance);
            }
            this->m_size -= distance;
            return it;
        }
    }

    void clear() {
        m_size = 0;
    }
    private:
    size_t m_size{0};
    size_t m_capacity{0};
    T* m_buffer{nullptr};
};
}
