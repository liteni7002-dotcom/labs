#pragma once
#include <string>
#include <exception>

class AgeException : public std::exception
{
public:
    AgeException(const std::string& message) : message{ message }
    {
    }
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};