#pragma once
#include <iostream>
#include <string>

namespace CBL {
template<class T>
class BasicString {
    public:
    using iterator = T *;
    static const size_t npos = -1ul;

    BasicString() {
        m_buffer = new T[1];
        m_buffer[0] = '\0';
    }
    BasicString(const BasicString<T> &str) {
        m_size = str.m_size;
        m_buffer = new T[m_size + 1];
        std::copy(str.begin(), str.end(), m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(const BasicString<T> &str, size_t pos, size_t len = npos) {
        m_size = len != npos ? std::min(str.m_size - pos, len) : str.m_size - pos;
        m_buffer = new T[m_size + 1];
        std::copy(str.m_buffer + pos, str.m_buffer + m_size + pos, m_buffer);
        m_buffer[m_size] = '\0';
    }
    explicit BasicString(const T *str) {
        m_size = std::char_traits<T>::length(str);
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(const T *str, size_t n) {
        m_size = std::min(std::char_traits<T>::length(str), n);
        m_buffer = new T[m_size + 1];
        std::copy(str, str + m_size, m_buffer);
        m_buffer[m_size] = '\0';
    }
    BasicString(size_t n, T c) {
        m_size = n;
        m_buffer = new T[m_size + 1];
        std::fill_n(m_buffer, m_size, c);
        m_buffer[m_size] = '\0';
    }
    BasicString(iterator first, iterator last) {
        m_size = std::distance(first, last);
        m_buffer = new T[m_size + 1];
        std::copy(first, last, m_buffer);
        m_buffer[m_size] = '\0';
    }
    virtual ~BasicString() {
        delete[] m_buffer;
    }

// iterators
    iterator begin() const {
        return m_buffer;
    }

    iterator end() const {
        return m_buffer + m_size;
    }

// capacity
    size_t length() const {
        return m_size;
    }
    // element access
    T& operator[](size_t index) const {
        return *(m_buffer + index);
    }

    T& at(size_t index) const {
        if (index < m_size) {
            return *(m_buffer + index);
        } else {
            throw(std::out_of_range("BasicString: out of range"));
        }
    }

    T& back() const {
        return *(m_buffer + m_size - 1);
    }

    T& front() const {
        return *m_buffer;
    }

// modifiers

    BasicString<T>& operator=(const BasicString<T>& str) {
        if (this != &str) {
            BasicString<T> new_string(str);
            std::swap(this->m_size, new_string.m_size);
            std::swap(this->m_buffer, new_string.m_buffer);
            m_buffer[m_size] = '\0';
        }
        return *this;
    }

    BasicString<T>& operator=(const T* str) {
        return operator=(BasicString<T>(str));
    }

    BasicString<T>& operator=(const T c) {
        return operator=(BasicString<T>(1, c));
    }

    BasicString<T>& operator+=(const BasicString<T>& str) {
        append(str);
        return *this;
    }

    BasicString<T>& operator+=(const T* str) {
        append(str);
        return *this;
    }

    BasicString<T>& operator+=(const T c) {
        append(1, c);
        return *this;
    }

    void append(const BasicString<T>& str) {
        T* new_string = new T[m_size + str.length() + 1];
        new_string[m_size + str.m_size] = '\0';
        std::copy(begin(), end(), new_string);
        std::copy(str.begin(), str.end(), new_string + m_size);
        m_size += str.length();
        delete[] m_buffer;
        m_buffer = new_string;
    }

    void append(const T* str) {
        append(BasicString<T>{str});
    }

    void append(const T* str, size_t n) {
        append(BasicString<T>{str, n});
    }

    void append(size_t n, T c) {
        append(BasicString<T>{n, c});
    }

    void append(iterator first, iterator last) {
        append(BasicString<T>{first, last});
    }

    void swap(BasicString<T>& str) {
        std::swap(this->m_size, str.m_size);
        std::swap(this->m_buffer, str.m_buffer);
    }

    // string operations
    const T* c_str() const {
        return m_buffer;
    }

    virtual int compare(const BasicString<T>& str) const {
        size_t lhs = m_size;
        size_t rhs = str.m_size;
        int result = std::char_traits<T>::compare(m_buffer, str.m_buffer, std::min(lhs, rhs));
        if (result != 0) {
            return result;
        }
        if (lhs < rhs) {
            return -1;
        }
        if (lhs > rhs) {
            return 1;
        }
        return 0;
    }
    virtual int compare(const T* str) const {
        return compare(BasicString<T>{str});
    }
    protected:
    size_t m_size{0};
    T* m_buffer{nullptr};
};
} // end namespace CBL
template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> new_string(lhs);
    new_string += rhs;
    return new_string;
}

template <class T>
CBL::BasicString<T> operator+(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator+(CBL::BasicString<T>{lhs}, rhs);
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator+(lhs, CBL::BasicString<T>{rhs});
}

template <class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T>& rhs) {
    return operator+(CBL::BasicString<T>{1, lhs}, rhs);
}
template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T rhs) {
    return operator+(lhs, CBL::BasicString<T>{1, rhs});
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    if (lhs.length() != rhs.length()) {
        return false;
    }
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator==(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator==(CBL::BasicString<T>{lhs}, rhs);
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator==(lhs, CBL::BasicString<T>{rhs});
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator!=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator<(const T* lhs, const CBL::BasicString<T>& rhs) {
    return CBL::BasicString<T>{lhs} < rhs;
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const T* rhs) {
    return CBL::BasicString<T>{lhs} < rhs;
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return (lhs < rhs) && (lhs == rhs);
}

template <class T>
bool operator<=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return (lhs < rhs) && (lhs == rhs);
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return (lhs < rhs) && (lhs == rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs <= rhs);
}

template <class T>
bool operator>(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs <= rhs);
}
template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs <= rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}
template <class T>
bool operator>=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const T* rhs){
    return !(lhs < rhs);
}

namespace CBL {
class String : public CBL::BasicString<char> {
    public:
    using BasicString<char>::BasicString;
    using BasicString<char>::operator=;
    using BasicString<char>::operator+=;
    using BasicString<char>::operator[];

    size_t find(const String& str, size_t pos = 0) const {
        if (pos >= m_size || pos + str.m_size > m_size)
            return CBL::BasicString<char>::npos;
        auto iter = std::search(begin() + pos, end(), str.m_buffer, str.m_buffer + str.m_size);
        if (iter == end()) {
            return CBL::BasicString<char>::npos;
        }
        return iter - begin();
    }

    size_t find(const char* str, size_t pos = 0) const {
        String new_string(str);
        return find(new_string, pos);
    }

    size_t find(char c, size_t pos = 0) const {
        String new_str(1, c);
        return find(new_str, pos);
    }

    size_t rfind(const String& str, size_t pos = 0) const {
        auto it = pos > m_size ? end() - str.m_size : begin() + pos;
        for (auto temp = begin() - 1; it != temp; --it) {
            if (std::char_traits<char>::compare(str.c_str(), it, str.length()) == 0) {
                return std::distance(begin(), it);
            }
        }
        return CBL::BasicString<char>::npos;
    }

    size_t rfind(const char* str, size_t pos = 0) const {
        String new_string(str);
        return rfind(new_string, pos);
    }

    size_t rfind(char c, size_t pos = 0) const {
        String new_str(1, c);
        return rfind(new_str, pos);
    }
};
}

namespace CBL {
class WString : public CBL::BasicString<wchar_t> {
    public:
    using BasicString<wchar_t>::BasicString;
    using BasicString<wchar_t>::operator=;
    using BasicString<wchar_t>::operator+=;
    using BasicString<wchar_t>::operator[];

    size_t find(const WString& str, size_t pos = 0) const {
        if (pos >= m_size || pos + str.m_size > m_size)
            return CBL::BasicString<wchar_t>::npos;
        auto iter = std::search(begin() + pos, end(), str.m_buffer, str.m_buffer + str.m_size);
        if (iter == end()) {
            return CBL::BasicString<wchar_t>::npos;
        }
        return iter - begin();
    }

    size_t find(const wchar_t* str, size_t pos = 0) const {
        return find(WString(str), pos);
    }

    size_t find(wchar_t c, size_t pos = 0) const {
        return find(WString (1, c), pos);
    }

    size_t rfind(const WString& str, size_t pos = 0) const {
        auto it = pos > m_size ? end() - str.m_size : begin() + pos;
        for (auto temp = begin() - 1; it != temp; --it) {
            if (std::char_traits<wchar_t>::compare(str.c_str(), it, str.length()) == 0) {
                return std::distance(begin(), it);
            }
        }
        return CBL::BasicString<wchar_t>::npos;
    }

    size_t rfind(const wchar_t* str, size_t pos = 0) const {
        WString new_string(str);
        return rfind(new_string, pos);
    }

    size_t rfind(wchar_t c, size_t pos = 0) const {
        WString new_str(1, c);
        return rfind(new_str, pos);
    }
};

}
