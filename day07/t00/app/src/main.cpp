#include <string>
#include "src/Vector.h"
#include "algorithmUtils.h"
#include <vector>
#include <cassert>
#include <string>

using namespace CBL;

template<typename T>
void Print(T &container) {
    for (const auto &item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

//static bool CheckConstructors() {
//    std::cout << "========CheckConstructors========" << std::endl;
//    std::cout << "\nEmpty vector" << std::endl;
//    {
//        Vector<std::string> vec;
//    }
//    std::cout << "-\nCreate Vector Size" << std::endl;
//    {
//        Vector<std::string> vec(12);
//        std::cout << "Size = " << vec.size() << std::endl;
//        std::vector<std::string> vec1(12);
//        std::cout << "Size = " << vec1.size() << std::endl;
//    }
//    std::cout << "-\nCreate Vector Size with Value" << std::endl;
//    {
//        Vector<std::string> v(12, "a");
//        std::vector<std::string> v1(12, "a");
//        Print(v);
//        std::cout << "Size = " << v.size() << std::endl;
//        Print(v1);
//        std::cout << "Size = " << v1.size() << std::endl;
//    }
//    std::cout << "-\nCreate Vector [first , last)" << std::endl;
//    {
//        Vector<std::string> newc(20, "pope");
//        Vector<std::string> newV(newc.begin(), newc.end());
//        Print(newc);
//        Print(newV);
//    }
//    std::cout << "-\nCreate Vector with list init" << std::endl;
//    {
//        Vector<std::string> ret = {"1", "2", "2", "3", "4"};
//        Print(ret);
//    }
//    std::cout << "-\nCreate Vector on base other" << std::endl;
//    {
//        Vector<std::string> ret = {"1", "2", "2", "3", "4"};
//        Print(ret);
//        Vector<std::string> ret1 = ret;
//        Print(ret1);
//    }
//
//    std::cout << "\n================================\n\n" << std::endl;
//    return true;
//}

//static bool CheckOperators() {
//    {
//        std::cout << "\n========Check Operators======\n\n" << std::endl;
//        {
//            std::cout << "\nCheck Operator [=] \n\n" << std::endl;
//            Vector<std::string> v(2, "alice");
//            Vector<std::string> v1(2);
//            std::cout << "OPERATION CHECK" << std::endl;
//            v1 = v;
//            Print(v);
//            Print(v1);
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//        {
//            std::cout << "\nCheck Operator [==] \n\n" << std::endl;
//            Vector<std::string> v13(2, "alice");
//            Vector<std::string> v12(2, "alice");
//            Vector<std::string> v14(2, "alice1");
//            Vector<std::string> v15(2, "alice");
//            std::cout << "OPERATION CHECK" << std::endl;
//            std::cout << (v13 == v12) << std::endl;
//            std::cout << (v14 == v15) << std::endl;
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//        {
//            std::cout << "\nCheck Operator [!=] \n\n" << std::endl;
//            Vector<std::string> v13(2, "alice");
//            Vector<std::string> v12(2, "alice");
//            Vector<std::string> v14(2, "alice1");
//            Vector<std::string> v15(2, "alice");
//            std::cout << "OPERATION CHECK" << std::endl;
//            std::cout << (v13 != v12) << std::endl;
//            std::cout << (v14 != v15) << std::endl;
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//        {
//            std::cout << "\nCheck Operator [<] \n\n" << std::endl;
//            Vector<std::string> v(2, "alice");
//            Vector<std::string> v1(2, "bob returns");
//            Vector<std::string> v14(2, "alice1");
//            Vector<std::string> v15(2, "alice");
//            std::cout << "OPERATION CHECK" << std::endl;
//            std::cout << (v < v1) << std::endl;
//            std::cout << (v14 < v15) << std::endl;
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//        {
//            std::cout << "\nCheck Operator [>] \n\n" << std::endl;
//            Vector<std::string> v(2, "alice");
//            Vector<std::string> v1(1, "bob returns");
//            Vector<std::string> v14(2, "alice1");
//            Vector<std::string> v15(2, "alice");
//            std::cout << "OPERATION CHECK" << std::endl;
//            std::cout << (v > v1) << std::endl;
//            std::cout << (v14 > v15) << std::endl;
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//        {
//            std::cout << "\nCheck Operator [<=] \n\n" << std::endl;
//            Vector<std::string> v(2, "alice");
//            Vector<std::string> v1(1, "bob returns");
//            Vector<std::string> v14(2, "alice1");
//            Vector<std::string> v15(2, "alice");
//            std::cout << "OPERATION CHECK" << std::endl;
//            std::cout << (v <= v1) << std::endl;
//            std::cout << (v14 <= v15) << std::endl;
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//        {
//            std::cout << "\nCheck Operator [>=] \n\n" << std::endl;
//            Vector<std::string> v(2, "alice");
//            Vector<std::string> v1(1, "bob returns");
//            Vector<std::string> v14(2, "alice1");
//            Vector<std::string> v15(2, "alice");
//            std::cout << "OPERATION CHECK" << std::endl;
//            std::cout << (v >= v1) << std::endl;
//            std::cout << (v14 >= v15) << std::endl;
//            std::cout << "OPERATION CHECK END\n\n" << std::endl;
//            std::cout << "\n-------------------------------\n\n" << std::endl;
//        }
//    }
//    return true;
//}

static bool EraseCheck() {
    {
        std::cout << "ERASE CHECK" << std::endl;
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        std::cout << *v.erase(v.begin() + 1) << std::endl;
        Print(v);
        std::cout << "=====================" << std::endl;
        std::cout << *s.erase(s.begin() + 1) << std::endl;
        Print(s);
        std::cout << "\n=========[]===========\n" << std::endl;
//        std::cout << *v.erase(v.begin(), v.end() - 1) << std::endl;
//        Print(v);
//        std::cout << "=====================" << std::endl;
//        std::cout << *s.erase(s.begin(), s.end() - 1) << std::endl;
//        Print(s);
        std::cout << "ERASE CHECK END" << std::endl;
    }
    return true;
}

//static bool ClearCheck() {
//    {
//        std::cout << "CLEAR CHECK" << std::endl;
//        Vector<int> v({1, 2, 3});
//        std::vector<int> s({1, 2, 3});
//        std::cout << v.size() << " " << v.capacity() << std::endl;
//        std::cout << "================================" << std::endl;
//        std::cout << s.size() << " " << s.capacity() << std::endl;
//        std::cout << "\n================================\n" << std::endl;
//        v.clear();
//        s.clear();
//        std::cout << v.size() << " " << v.capacity() << std::endl;
//        std::cout << "================================" << std::endl;
//        std::cout << s.size() << " " << s.capacity() << std::endl;
//        std::cout << "CLEAR CHECK END\n" << std::endl;
//    }
//    return true;
//}

//static bool PushCheck() {
//    {
//        std::cout << "PUSH CHECK" << std::endl;
//        {
//            Vector<int> v(10);
//            Vector<int> v1({1, 2, 3});
//            v = v1;
//            std::cout << "Size v = " << v.size() << " " << v.capacity()
//                      << std::endl;
//            Print(v);
//            v.push_back(4);
//            v.push_back(5);
//            v.push_back(6);
//            std::cout << "Size v = " << v.size() << " " << v.capacity()
//                      << std::endl;
//            Print(v);
//            std::cout << "---------------------------------------\n" << std::endl;
//        }
//        {
//            Vector<int> v({1, 2, 3});
//            std::vector<int> v1({1, 2, 3});
//            std::cout << "Size v = " << v.size() << " " << v.capacity() << std::endl;
//            Print(v);
//            v.push_back(4);
//            v.push_back(5);
//            v.push_back(6);
//            std::cout << "Size v = " << v.size() << " " << v.capacity() << std::endl;
//            Print(v);
//
//            std::cout << "Size v1 = " << v1.size() << " " << v1.capacity() << std::endl;
//            Print(v1);
//            v1.push_back(4);
//            v1.push_back(5);
//            v1.push_back(6);
//            std::cout << "Size v1 = " << v1.size() << " " << v1.capacity() << std::endl;
//            Print(v1);
//        }
//        std::cout << "PUSH CHECK END" << std::endl;
//    }
//    return true;
//}

//static bool PopCheck() {
//    {
//        std::cout << "POP CHECK" << std::endl;
//        Vector<int> v({1, 2, 3});
//        std::vector<int> s({1, 2, 3});
//        Print(v);
//        std::cout << "================================" << std::endl;
//        Print(s);
//        std::cout << "================================" << std::endl;
//        v.pop_back();
//        v.pop_back();
//        v.pop_back();
//        s.pop_back();
//        s.pop_back();
//        s.pop_back();
//        Print(v);
//        std::cout << "================================" << std::endl;
//        Print(s);
//        std::cout << "POP CHECK END" << std::endl;
//    }
//    return true;
//}
//
//static bool AccsessCheck() {
//    {
//        std::cout << "ACCSESS CHECK" << std::endl;
//        Vector<int> v({1, 2, 3});
//        std::vector<int> s({1, 2, 3});
////        std::cout << "1:" << v[0] << " 2:" << v.at(1) << std::endl;
////        v[0] = 11; v.at(1) = 22;
////        std::cout << "1:" << v[0] << " 2:" << v.at(1) << std::endl;
//        std::cout << "================================" << std::endl;
////        std::cout << "1:" << s[0] << " 2:" << s.at(1) << std::endl;
//        s[0] = 11; s.at(1) = 22;
//        std::cout << "1:" << s[0] << " 2:" << s.at(1) << std::endl;
//
//    }
//    {
//        std::cout << "CHECK AT EXCEPTION" << std::endl;
//        try {
//            Vector<int> v({1, 2, 3});
//            v.at(123);
//        }
//        catch (std::exception&e ) {
//            std::cout << e.what() << std::endl;
//        }
//    }
//    std::cout << "ACCSESS CHECK END" << std::endl;
//    return true;
//}

//static bool EmptyCheck() {
//    {
//        std::cout << "EMPTY CHECK" << std::endl;
//        Vector<int> v;
//        std::vector<int> s;
//        std::cout << v.isEmpty() << v.size() << v.capacity() << std::endl;
//        std::cout << "================================" << std::endl;
//        std::cout << s.empty() << s.size() << s.capacity() << std::endl;
//        std::cout << "EMPTY CHECK END" << std::endl;
//    }
//    return true;
//}

//bool ReserveCheck() {
//    {
//        std::cout << "RESERVE CHECK" << std::endl;
//        Vector<int> v;
//        std::vector<int> s;
//        v.reserve(10);
//        s.reserve(10);
//        Print(v);
//        std::cout << v.capacity() << " " << v.size() << std::endl;
//        std::cout << "================================" << std::endl;
//        Print(s);
//        std::cout << s.capacity() << " " << s.size() << std::endl;
//        std::cout << "RESERVE CHECK END" << std::endl;
//    }
//    return true;
//}

//bool ResizeCheck() {
//    {
//        std::cout << "RESIZE CHECK" << std::endl;
//        Vector<int> v;
//        std::vector<int> s;
//        v.resize(10);
//        s.resize(10);
//        std::cout << v.capacity() << " " << v.size() << std::endl;
//        Print(v);
//        std::cout << "================================" << std::endl;
//        std::cout << s.capacity() << " " << s.size() << std::endl;
//        Print(s);
//        v.resize(30);
//        s.resize(30);
//        std::cout << v.capacity() << " " << v.size() << std::endl;
//        Print(v);
//        std::cout << "================================" << std::endl;
//        std::cout << s.capacity() << " " << s.size() << std::endl;
//        Print(s);
//        std::cout << "RESIZE CHECK END" << std::endl;
//    }
//    return true;
//}

//static bool InsertCheck() {
//    {
//        std::cout << "INSERT CHECK" << std::endl;
//        Vector<int> v({1, 2, 3});
//        std::vector<int> s({1, 2, 3});
//        v.insert(v.begin(), 11);
//        v.insert(v.begin() + 2, 22);
//        v.insert(v.begin() + 4, 44);
//        s.insert(s.begin(), 11);
//        s.insert(s.begin() + 2, 22);
//        s.insert(s.begin() + 4, 44);
//        Print(v);
//        std::cout << "================================" << std::endl;
//        Print(s);
//        std::cout << "INSERT CHECK END" << std::endl;
//    }
//    return true;
//}

int main(int argc, char *argv[]) {
//    CheckConstructors();
//    CheckOperators();
//    AccsessCheck();
//    ReserveCheck();
//    ResizeCheck();
//    ClearCheck();
//    PushCheck();
//    PopCheck();
////проверил
    EraseCheck();
//    InsertCheck();

//    EmptyCheck();
    return 0;
}
