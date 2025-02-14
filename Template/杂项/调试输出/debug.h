/*
    Author: xxsars
    Use: debug(...);
    Define the main function as follows：
        #if defined LOCAL and !defined ONLINE_JUDGE
        #include "algo/debug.h"
        #else
        #define debug(...) ;
        #endif
    Prework:
        #define LOCAL: should be added in your "bits/stdc++.h"
*/

#ifndef ALGO_DEBUG_H
#define ALGO_DEBUG_H

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <type_traits>

// std::pair
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    return os << "(" << p.first << "," << p.second << ")";
}

// std::array
template <typename T, std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &arr) {
    os << "[";
    for (std::size_t i = 0; i < N; ++i) {
        os << (i != 0 ? " " : "") << arr[i];
    }
    os << "]";
    return os;
}

// std::vector
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        os << (it != v.begin() ? " " : "") << *it;
    }
    os << "]";
    return os;
}

// std::vector<vector>
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v) {
    os << "[\n";
    for (const auto &row : v) {
        os << "  [";
        for (auto it = row.begin(); it != row.end(); ++it) {
            os << (it != row.begin() ? " " : "") << *it;
        }
        os << "]\n";
    }
    os << "]";
    return os;
}

// std::set
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
    os << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        os << (it != s.begin() ? " " : "") << *it;
    }
    os << "}";
    return os;
}

// std::unordered_set
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &s) {
    os << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        os << (it != s.begin() ? " " : "") << *it;
    }
    os << "}";
    return os;
}

// std::map
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::map<T, U> &m) {
    os << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        os << (it != m.begin() ? " " : "") << it->first << ":" << it->second;
    }
    os << "}";
    return os;
}

// std::unordered_map
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<T, U> &m) {
    os << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        os << (it != m.begin() ? " " : "") << it->first << ":" << it->second;
    }
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
    os << (I > 0 ? " " : "") << std::get<I>(t);
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
void debug_out() {
    std::cerr << std::endl;
}

template <typename Head>
void debug_out(Head H) {
    std::cerr << H << std::endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << H << ", ";
    debug_out(T...);
}

// Macro for debugging
#define debug(...) \
    if (sizeof(#__VA_ARGS__) == 1) { \
        std::cerr << std::endl; \
    } else { \
        std::cerr << __LINE__ << ": (" << #__VA_ARGS__ << ") = "; \
        debug_out(__VA_ARGS__); \
    }

#endif // ALGO_DEBUG_H
