//
// Created by Th on 30/05/2023.
//

#include "Exceptions.h"
#include <utility>

Exceptions::Exceptions(std::string MessageException) {
    this->message = std::move(MessageException);
}

const char *Exceptions::what() const noexcept {
    return this->message.c_str();
}

ExceptionsValidator::ExceptionsValidator(std::string MessageException) :
Exceptions(move(MessageException)) {

}

ExceptionsRepository::ExceptionsRepository(std::string MessageException) :
Exceptions(move(MessageException)) {

}