template <typename T> struct Discrete {
	vector<T> p;

	Discrete() {}
    
	void add(T t) { 
        p.push_back(t); 
    }
	void init() { 
        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin()); 
    }
	int size() {
        return p.size(); 
    }
	int id(T t) { 
        return lower_bound(p.begin(), p.end(), t) - p.begin(); 
    }
	T operator[](int id) {
        return p[id]; 
    }
    vector<T> &get() {
        return p; 
    }
};