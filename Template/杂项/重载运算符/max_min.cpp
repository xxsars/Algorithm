template<typename T1, typename T2>
typename std::common_type<T1, T2>::type max(T1 a, T2 b) {
    return a > b ? a : b;
}

template<typename T1, typename T2>
typename std::common_type<T1, T2>::type min(T1 a, T2 b) {
    return a < b ? a : b;
}
