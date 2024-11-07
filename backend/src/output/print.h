#ifndef PRINT_H
#define PRINT_H

#include <string>

class Print {
public:
    virtual ~Print() = default;
    virtual void cprint(const std::string& message) = 0;

protected:
    Print() = default;
};

#endif // PRINT_H