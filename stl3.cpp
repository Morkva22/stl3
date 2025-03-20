#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class FindMin {
public:
    T operator()(const vector<T>& vec) const {
        if (vec.empty()) throw runtime_error("Vector is empty!");
        return *min_element(vec.begin(), vec.end());
    }
};

template<typename T>
class FindMax {
public:
    T operator()(const vector<T>& vec) const {
        if (vec.empty()) throw runtime_error("Vector is empty!");
        return *max_element(vec.begin(), vec.end());
    }
};

template<typename T>
class SortDescending {
public:
    void operator()(vector<T>& vec) const {
        sort(vec.begin(), vec.end(), greater<T>());
    }
};

template<typename T>
class SortAscending {
public:
    void operator()(vector<T>& vec) const {
        sort(vec.begin(), vec.end());
    }
};

template<typename T>
class IncreaseBy {
    T value;
public:
    IncreaseBy(T val) : value(val) {}
    void operator()(vector<T>& vec) const {
        for (T& num : vec) {
            num += value;
        }
    }
};

template<typename T>
class DecreaseBy {
    T value;
public:
    DecreaseBy(T val) : value(val) {}
    void operator()(vector<T>& vec) const {
        for (T& num : vec) {
            num -= value;
        }
    }
};

template<typename T>
class RemoveEqual {
    T value;
public:
    RemoveEqual(T val) : value(val) {}
    void operator()(vector<T>& vec) const {
        vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
    }
};

template<typename T>
void printVector(const vector<T>& vec) {
    for (const T& num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> intNumbers = {5, 3, 9, 1, 7, 2, 8, 4, 6};
    vector<double> doubleNumbers = {5.5, 3.3, 9.9, 1.1, 7.7, 2.2, 8.8, 4.4, 6.6};

    FindMin<int> findMinInt;
    cout << "Min value (int): " << findMinInt(intNumbers) << endl;

    FindMax<int> findMaxInt;
    cout << "Max value (int): " << findMaxInt(intNumbers) << endl;

    SortDescending<int> sortDescInt;
    sortDescInt(intNumbers);
    cout << "Sorted descending (int): ";
    printVector(intNumbers);

    SortAscending<int> sortAscInt;
    sortAscInt(intNumbers);
    cout << "Sorted ascending (int): ";
    printVector(intNumbers);

    IncreaseBy<int> increaseBy5(5);
    increaseBy5(intNumbers);
    cout << "Increased by 5 (int): ";
    printVector(intNumbers);

    DecreaseBy<int> decreaseBy3(3);
    decreaseBy3(intNumbers);
    cout << "Decreased by 3 (int): ";
    printVector(intNumbers);

    RemoveEqual<int> removeEqual6(6);
    removeEqual6(intNumbers);
    cout << "Removed all 6s (int): ";
    printVector(intNumbers);

    FindMin<double> findMinDouble;
    cout << "Min value (double): " << findMinDouble(doubleNumbers) << endl;

    FindMax<double> findMaxDouble;
    cout << "Max value (double): " << findMaxDouble(doubleNumbers) << endl;

    SortDescending<double> sortDescDouble;
    sortDescDouble(doubleNumbers);
    cout << "Sorted descending (double): ";
    printVector(doubleNumbers);

    SortAscending<double> sortAscDouble;
    sortAscDouble(doubleNumbers);
    cout << "Sorted ascending (double): ";
    printVector(doubleNumbers);

    IncreaseBy<double> increaseBy2_5(2.5);
    increaseBy2_5(doubleNumbers);
    cout << "Increased by 2.5 (double): ";
    printVector(doubleNumbers);

    DecreaseBy<double> decreaseBy1_1(1.1);
    decreaseBy1_1(doubleNumbers);
    cout << "Decreased by 1.1 (double): ";
    printVector(doubleNumbers);

    RemoveEqual<double> removeEqual6_6(6.6);
    removeEqual6_6(doubleNumbers);
    cout << "Removed all 6.6s (double): ";
    printVector(doubleNumbers);

    return 0;
}