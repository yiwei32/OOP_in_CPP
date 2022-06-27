#include <iostream>
#include <stdlib.h>
#include <random>
#include <iomanip>

using namespace std;

class Point2D{
private:
    int x;
    int y;
public:
    // add any member if necessary
    Point2D(int x_val = 0, int y_val = 0):x(x_val), y(y_val){}
    void assignPoint2D(int x_val, int y_val){x=x_val; y=y_val;}
    friend ostream& operator<<(ostream& ost, const Point2D& pt){
        cout << "(" << pt.x << "," << pt.y << ")";
        return ost;
    }
    Point2D& operator=(const int& k){
        x = k; 
        y = k;
        return *this;
    }
    Point2D& operator=(const Point2D& pt){
        x = pt.x; 
        y = pt.y;
        return *this;
    }
    bool operator<(const Point2D& pt2){
        if (x != pt2.x){
            return x < pt2.x ? true : false;
        }
        else{
            return y < pt2.y ? true : false;
        }
    }
};


template<class T>
T *new1D(int n, T k){
    T *vec = new T [n];
    for (int i = 0; i < n; i++)
        vec[i] = k;
    return vec;
}

template<>
char *new1D<char>(int n, char k){
    char *vec = new char [n];
    for (int i = 0; i < n; ++i){
        vec[i] = k % 26 + 97;
    }
    return vec;
}

template<class T>
void rand1D(T *vec, int n);

template<>
void rand1D(int *vec, int n){
    for (int i = 0; i < n; ++i){
        vec[i] = rand() % 10 + 1;
    }
}

template<>
void rand1D(double *vec, int n){
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(0, 10);
    for (int i = 0; i < n; ++i){
        vec[i] = distr(eng);
    }
}

template<>
void rand1D<char>(char *vec, int n){
    for (int i = 0; i < n; ++i){
        vec[i] = char(rand() % 26 + 97);
    }
}

template<>
void rand1D<Point2D>(Point2D *vec, int n){
    
    for (int i = 0; i < n; ++i){
        vec[i].assignPoint2D(rand()%10, rand()%10);
    }
}

template<class T>
void display1D(T *vec, int n){
    for (int i = 0;i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}

template<>
void display1D(double *vec, int n){
    for (int i = 0; i < n; ++i){
        cout << fixed << setprecision(2) << vec[i] << " ";
    }
    cout << endl;
}


template<class T>
void sort1D(T *vec, int n){
    
    for (int i = 1; i < n; ++i){
        int j = i - 1;
        T key = vec[i];
        while (j >= 0 && key < vec[j]){
            vec[j+1] = vec[j];
            --j;
        }
        vec[j+1] = key;
    }
}

template<class T>
void analysis(int n, int k = 0){
    T *vec = new1D<T> (n, k);
    rand1D<T>(vec,n);
    // for int 1~10, for double 0.00~10.00, for char a~z, // for Point2D x: 0~9 y:0~9
    display1D<T>(vec,n);
    sort1D<T>(vec,n);
    display1D<T>(vec,n);
}



int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    srand(1);
    analysis<int>(n);
    analysis<double>(n);
    analysis<char>(n);
    analysis<Point2D>(n);
    return 0; 
}