#include <exception>
#include <iostream>
#include <string>

// Створюємо клас для виключення
class InsufficientArgumentException : public std::exception {
private:
    int minArgs;
    std::string message;
public:
    InsufficientArgumentException(int m) : minArgs(m) {
        message = "Insufficient arguments. Minimum required arguments: " + std::to_string(minArgs);
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main(int argc, char *argv[]) {
    try {
        int minRequiredArgs = 3; // Задаємо мінімальну кількість аргументів
        // argc включає ім'я програми як перший аргумент, тому ми віднімаємо 1
        if(argc - 1 < minRequiredArgs) {
            throw InsufficientArgumentException(minRequiredArgs);
        }
        // Зробити щось з аргументами
        // ...
    }
    catch (InsufficientArgumentException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unknown error occurred" << std::endl;
    }

    return 0;
}