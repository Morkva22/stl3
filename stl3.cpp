#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    double engineVolume;
    double price;

    void print() const {
        cout << "Name: " << name << ", Year: " << year
             << ", Engine Volume: " << engineVolume
             << ", Price: " << price << endl;
    }
};

class CarManager {
    vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void removeCar(const string& name) {
        auto it = remove_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.name == name;
        });
        cars.erase(it, cars.end());
    }

    void displayAllCars() const {
        for (const auto& car : cars) {
            car.print();
        }
    }

    void sortByName() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.name < b.name;
        });
    }

    void sortByYear() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.year < b.year;
        });
    }

    void sortByEngineVolume() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.engineVolume < b.engineVolume;
        });
    }

    void sortByPrice() {
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.price < b.price;
        });
    }

    vector<Car> searchByName(const string& name) const {
        vector<Car> result;
        copy_if(cars.begin(), cars.end(), back_inserter(result), [&](const Car& car) {
            return car.name == name;
        });
        return result;
    }

    vector<Car> searchByYear(int year) const {
        vector<Car> result;
        copy_if(cars.begin(), cars.end(), back_inserter(result), [&](const Car& car) {
            return car.year == year;
        });
        return result;
    }

    vector<Car> searchByEngineVolume(double engineVolume) const {
        vector<Car> result;
        copy_if(cars.begin(), cars.end(), back_inserter(result), [&](const Car& car) {
            return car.engineVolume == engineVolume;
        });
        return result;
    }

    vector<Car> searchByPrice(double price) const {
        vector<Car> result;
        copy_if(cars.begin(), cars.end(), back_inserter(result), [&](const Car& car) {
            return car.price == price;
        });
        return result;
    }
};

void printSearchResults(const vector<Car>& results) {
    if (results.empty()) {
        cout << "No cars found." << endl;
    } else {
        for (const auto& car : results) {
            car.print();
        }
    }
}

int main() {
    CarManager manager;
    int choice;

    do {
        cout << "\n1. Add Car\n2. Remove Car\n3. Display All Cars\n4. Sort Cars\n5. Search Cars\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Car car;
                cout << "Enter car name: ";
                cin >> car.name;
                cout << "Enter car year: ";
                cin >> car.year;
                cout << "Enter engine volume: ";
                cin >> car.engineVolume;
                cout << "Enter price: ";
                cin >> car.price;
                manager.addCar(car);
                break;
            }
            case 2: {
                string name;
                cout << "Enter car name to remove: ";
                cin >> name;
                manager.removeCar(name);
                break;
            }
            case 3:
                manager.displayAllCars();
                break;
            case 4: {
                int sortChoice;
                cout << "1. Sort by Name\n2. Sort by Year\n3. Sort by Engine Volume\n4. Sort by Price\nEnter your choice: ";
                cin >> sortChoice;
                switch (sortChoice) {
                    case 1:
                        manager.sortByName();
                        break;
                    case 2:
                        manager.sortByYear();
                        break;
                    case 3:
                        manager.sortByEngineVolume();
                        break;
                    case 4:
                        manager.sortByPrice();
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;
            }
            case 5: {
                int searchChoice;
                cout << "1. Search by Name\n2. Search by Year\n3. Search by Engine Volume\n4. Search by Price\nEnter your choice: ";
                cin >> searchChoice;
                switch (searchChoice) {
                    case 1: {
                        string name;
                        cout << "Enter car name to search: ";
                        cin >> name;
                        auto results = manager.searchByName(name);
                        printSearchResults(results);
                        break;
                    }
                    case 2: {
                        int year;
                        cout << "Enter car year to search: ";
                        cin >> year;
                        auto results = manager.searchByYear(year);
                        printSearchResults(results);
                        break;
                    }
                    case 3: {
                        double engineVolume;
                        cout << "Enter engine volume to search: ";
                        cin >> engineVolume;
                        auto results = manager.searchByEngineVolume(engineVolume);
                        printSearchResults(results);
                        break;
                    }
                    case 4: {
                        double price;
                        cout << "Enter price to search: ";
                        cin >> price;
                        auto results = manager.searchByPrice(price);
                        printSearchResults(results);
                        break;
                    }
                    default:
                        cout << "Invalid choice!" << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}