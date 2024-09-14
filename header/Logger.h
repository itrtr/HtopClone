//
// Created by pnkjsng on 8/25/24.
//

#ifndef HTOPCLONE_LOG_H
#define HTOPCLONE_LOG_H
#include <iostream>
#include <set>
#include <string>
#include <type_traits>
#include <vector>

template <typename T, typename = void>
struct is_iterable : std::false_type {};

template <typename T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin()), decltype(std::declval<T>().end())>> : std::true_type {};

class Logger {
public:
    template <typename T>
    static std::enable_if_t<!is_iterable<T>::value> log(const T &value) {
        std::cout << "[" << value << "]\n";
    }

    template <typename T>
    static std::enable_if_t<is_iterable<T>::value> log(const T &iterable) {
        std::cout << "[";
        for (const auto &obj : iterable) {
            std::cout << obj << " ";
        }
        std::cout << "]\n";
    }
};

#endif // HTOPCLONE_LOG_H