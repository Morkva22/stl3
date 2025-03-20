#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FindMin {
public:
    int operator()(const vector<int>& vec) const {
        if (vec.empty()) throw runtime_error("Vector is empty!");
        return *min_element(vec.begin(), vec.end());
    }
};

class FindMax {
public:
    int operator()(const vector<int>& vec) const {
        if (vec.empty()) throw runtime_error("Vector is empty!");
        return *max_element(vec.begin(), vec.end());
    }
};

class SortDescending {
public:
    void operator()(vector<int>& vec) const {
        sort(vec.begin(), vec.end(), greater<int>());
    }
};

class SortAscending {
public:
    void operator()(vector<int>& vec) const {
        sort(vec.begin(), vec.end());
    }
};

class IncreaseBy {
    int value;
public:
    IncreaseBy(int val) : value(val) {}
    void operator()(vector<int>& vec) const {
        for (int& num : vec) {
            num += value;
        }
    }
};

class DecreaseBy {
    int value;
public:
    DecreaseBy(int val) : value(val) {}
    void operator()(vector<int>& vec) const {
        for (int& num : vec) {
            num -= value;
        }
    }
};

class RemoveEqual {
    int value;
public:
    RemoveEqual(int val) : value(val) {}
    void operator()(vector<int>& vec) const {
        vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {5, 3, 9, 1, 7, 2, 8, 4, 6};

    FindMin findMin;
    cout << "Min value: " << findMin(numbers) << endl;

    FindMax findMax;
    cout << "Max value: " << findMax(numbers) << endl;

    SortDescending sortDesc;
    sortDesc(numbers);
    cout << "Sorted descending: ";
    printVector(numbers);

    SortAscending sortAsc;
    sortAsc(numbers);
    cout << "Sorted ascending: ";
    printVector(numbers);

    IncreaseBy increaseBy5(5);
    increaseBy5(numbers);
    cout << "Increased by 5: ";
    printVector(numbers);

    DecreaseBy decreaseBy3(3);
    decreaseBy3(numbers);
    cout << "Decreased by 3: ";
    printVector(numbers);

    RemoveEqual removeEqual6(6);
    removeEqual6(numbers);
    cout << "Removed all 6s: ";
    printVector(numbers);

    return 0;
}