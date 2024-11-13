#include <iostream>
#ifndef TRANSACTION_H
#define TRANSACTION_H
class Transaction{
public:
    virtual bool doTransaction() = 0;
    virtual void display() = 0;
protected:
    char actionType;
};
#endif // TRANSACTION_H