//
// Created by Th on 30/05/2023.
//


#pragma once
#include <string>
#include <exception>
#include <utility>

class Exceptions : public std::exception
{
protected:
    std::string message;

public:
    explicit Exceptions(std::string MessageException);

    [[nodiscard]] const char* what() const noexcept override;

};

class ExceptionsValidator: public Exceptions
{
public:
    explicit ExceptionsValidator(std::string MessageException);
};

class ExceptionsRepository: public Exceptions
{
public:
    explicit ExceptionsRepository(std::string MessageException);
};