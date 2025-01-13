template<typename T>
ostream & operator << (ostream &out, const set<T> &obj) {
    out << "set(";
    for (auto it = obj.begin(); it != obj.end(); it++)
        out << (it == obj.begin() ? "" : ", ") << *it;
    out << ")";
    return out;
}
template<typename T1,typename T2>
ostream & operator << (ostream &out, const map<T1,T2> &obj) {
    out << "map(";
    for (auto it = obj.begin(); it != obj.end(); it++)
        out << (it == obj.begin() ? "" : ", ") << it->first << ": " << it->second;
    out << ")";
    return out;
}
template<typename T1,typename T2>
ostream & operator << (ostream &out, const pair<T1,T2> &obj) {
    out << "<" << obj.first << ", " << obj.second << ">";
    return out;
}
template<typename T>
ostream & operator << (ostream &out, const vector<T> &obj) {
    out << "vector(";
    for (auto it = obj.begin(); it != obj.end(); it++)
        out << (it == obj.begin() ? "" : ", ") << *it;
    out << ")";
    return out;
}
