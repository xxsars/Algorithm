template<typename T>
istream & operator >> (istream &in, vector<T> &obj) {
    for (auto &it : obj) {
        in >> it;
    }
    return in;
}
