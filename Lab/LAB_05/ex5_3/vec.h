#ifndef VEC
#define VEC
class Vec{
private:
    int *nums;
    unsigned int capacity;
    unsigned int current;

public:
    Vec(); // default constructor
    Vec(int * const arr, const int dim); // self-defined constructor
    Vec(const Vec& old); //copy constructor
    ~Vec(); // destructor
    void assign(int * const arr, const int dim); // A const pointer
    void push_back(int num);
    void pop_back();
    int size() const; // Const member functions can be called by const object, wehreas non-const memeber functions can not.
    void sort();
    void printVec();
    bool isEqual(const Vec& vec2);
    void unionSet(const Vec& vec1, const Vec& vec2);
    int min();
    int max();
    bool find(const int target);
    Vec& inpendetSet(); // remove duplicates
};
#endif