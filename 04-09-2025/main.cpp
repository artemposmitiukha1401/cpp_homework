#include <iostream>

class Car {
    char* model = nullptr;
    char* country = nullptr;
    char* color = nullptr;
    int year = 0;
    double price = 0.0;

public:
    char* getModel() const { return model; }
    char* getCountry() const { return country; }
    char* getColor() const { return color; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    void SetModel(const char* model) {
        delete[] this->model;
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }
    void SetCountry(const char* country) {
        delete[] this->country;
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
    }
    void SetColor(const char* color) {
        delete[] this->color;
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
    }
    void SetYear(const int year) {
        if (year <= 0) {
            std::cout << "Invalid year\n";
            return;
        }
        this->year = year;
    }
    void SetPrice(const double price) {
        if (price <= 0 ) {
            std::cout << "Invalid price\n";
            return;
        }
        this->price = price;
    }
    Car() {
        SetModel("No model");
        SetCountry("No country");
        SetColor("No color");
        this->year = 0;
        this->price = 0;
    }
    Car(const char* model, const char* country, const char* color, int year, double price) {
        if (model == nullptr || country == nullptr || color == nullptr) {
            std::cerr << "Error, null input (parameters set to default)\n";
            SetModel("No model");
            SetCountry("No country");
            SetColor("No color");
            return;
        }
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        this->country = new char[strlen(country) + 1];
        strcpy(this->country, country);
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
        this->year = year;
        this->price = price;
    }
    void Print() {
        std::cout << "| Model: " << model << " | " << country << " | " << color << " | " << year << " | " << price << "$ |\n";
    }
    void ChangeProperties() {
        const int BUFFER_SIZE = 256;
        char new_model[BUFFER_SIZE];
        char new_country[BUFFER_SIZE];
        char new_color[BUFFER_SIZE];
        int new_year = 0;
        double new_price = 0;

        std::cout << "\nEnter new model > ";
        std::cin.getline(new_model, BUFFER_SIZE);

        std::cout << "Enter new country > ";
        std::cin.getline(new_country, BUFFER_SIZE);

        std::cout << "Enter new color > ";
        std::cin.getline(new_color, BUFFER_SIZE);

        std::cout << "Enter new year > "; std::cin >> new_year;
        std::cin.ignore();
        SetYear(new_year);

        std::cout << "Enter new price > "; std::cin >> new_price;
        std::cin.ignore();
        SetPrice(new_price);

        SetModel(new_model);
        SetCountry(new_country);
        SetColor(new_color);
    }
    ~Car() {
        delete[] model;
        delete[] country;
        delete[] color;
        model = nullptr;
        country = nullptr;
        color = nullptr;
    }
};
int main() {
    Car car_1{"Porsche 911", "Germany", "White", 2025, 100000};
    car_1.Print();
    car_1.ChangeProperties();
    car_1.Print();

    return 0;
}