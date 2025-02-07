/*
    Author: xxsars
    Use: debug(...);
    Define the main function as follows：
        #define LOCAL
        #if defined LOCAL and !defined ONLINE_JUDGE
        #include "algo/debug.h"
        #else
        #define debug(...) ;
        #endif
*/

#ifndef ALGO_DEBUG_H
#define ALGO_DEBUG_H

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <type_traits>

// std::pair
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// std::vector
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[ ";
    for (const auto &x : v) os << x << " ";
    os << "]";
    return os;
}

// std::vector<vector>
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) {
    os << "[\n";
    for (const auto &row : v) {
        // os << "  [ ";
        // for (const auto &x : row) os << x << " ";
        // os << "]\n";
        os << "    ";
        for (const auto &x : row) os << x << " ";
        os << "\n";
    }
    os << "]";
    return os;
}

// std::set
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
    os << "{ ";
    for (const auto &x : s) os << x << " ";
    os << "}";
    return os;
}

// std::unordered_set
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &s) {
    os << "{ ";
    for (const auto &x : s) os << x << " ";
    os << "}";
    return os;
}

// std::map
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::map<T, U> &m) {
    os << "{ ";
    for (const auto &[key, value] : m) os << key << ": " << value << ", ";
    os << "}";
    return os;
}

// std::unordered_map
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<T, U> &m) {
    os << "{ ";
    for (const auto &[key, value] : m) os << key << ": " << value << ", ";
    os << "}";
    return os;
}

// Recursive function to print std::tuple
template <std::size_t I = 0, typename... Args>
typename std::enable_if<I == sizeof...(Args), void>::type
print_tuple(std::ostream &, const std::tuple<Args...> &) {}

template <std::size_t I = 0, typename... Args>
typename std::enable_if<I < sizeof...(Args), void>::type
print_tuple(std::ostream &os, const std::tuple<Args...> &t) {
    if (I > 0) os << ", ";
    os << std::get<I>(t);
    print_tuple<I + 1>(os, t);
}

// std::tuple
template <typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t) {
    os << "(";
    print_tuple(os, t);
    os << ")";
    return os;
}

// Debug output function
void debug_out() { std::cerr << std::endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << H << " ";
    debug_out(T...);
}

// Macro for debugging
#define debug(...) std::cerr << "(" << #__VA_ARGS__ << "): ", debug_out(__VA_ARGS__)

#endif // ALGO_DEBUG_H
