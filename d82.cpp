#include <iostream>
#include <fstream>
using namespace std;

class Logger {
public:
    virtual void write(string message) = 0;

    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string message) override {
        cout << "Console Log: " << message << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string message) override {
        ofstream file("log.txt", ios::app);
        file << message << endl;
        file.close();
        cout << "Message written to file." << endl;
    }
};

int main() {
    ConsoleLogger c;
    FileLogger f;
    Logger* logger;
    int choice;
    cout << "1. Console Logger\n";
    cout << "2. File Logger\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        logger = &c;
    }
    else if (choice == 2) {
        logger = &f;
    }
    else {
        cout << "Invalid choice";
        return 0;
    }
    logger->write("Hello! This is a log message.");
    return 0;
}