#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <iostream>

using namespace std;

class Account
{

public:
    Account()
    {
        yourName = "Dawgs";
        yourBalance = 0;
        
    }

    Account(string newName)
    {
        if (newName.length() < 5)
        {
            yourName = "Dawgs";
        }
        else if (newName.length() > 20)
        {
            yourName = newName.substr(0, 20);
        }
        else
        {
            yourName = newName;
        }

        yourBalance = 0;
      
    }

    void setName(std::string newName)
    {
        yourName = newName;
    }

    std::string getName() const
    {
        // add  code  here
        return yourName;
    }

    void setBalance(double balance)
    {
        yourBalance = balance;
    }

    double getBalance()
    {
        // add  code  here  -- a basic  getter , return  the  balance  of the  account
        return yourBalance; /*  replace  this */
    }

    double deposit(double depositAmount)
    {
        if (depositAmount < 0)
        {
            std::cout << "You cannot deposit anything less than 0.";
        }
        else
        {
            yourBalance += depositAmount;
        }
        return yourBalance;
    }

    double withdraw(double withdrawalAmount)
    {
        if (withdrawalAmount < 0)
        {
            std::cout << "You cannot withdraw anything less than 0.";
        }
        else
        {
            yourBalance -= withdrawalAmount;
        }
        return yourBalance;
    }

    double interest(double percent)
    {

        yourBalance += (yourBalance * percent);

        return yourBalance;
    }

    bool transferTo(double amount, Account &otherAccount)
    {

        if ((yourBalance - amount) < 0)
        {
            return false;
        }

        withdraw(amount);
        otherAccount.deposit(amount);
        return true;
    }

private:
    string yourName;
    double yourBalance;
};
#endif