#ifndef BANK_H
#define BANK_H
#include <iostream>

using namespace std;

class Bank
{
    public:
        Bank();
        Bank(int accountId,int balance);
        void setaccountId(int accountId);
        int getaccountId();
        void setbalance(int balance);
        int getbalance();
        virtual void withdraw(int amount);
        virtual void deposit(int amount);

    protected:
        int balance,accountId;
        static int counter;
};



class SavingsBankAccount : public Bank{
    public:
        SavingsBankAccount();
        void setminimumBalance(int minimumBalance);
        int getminimumBalance();
        void withdraw(int amount);
        void deposit(int amount);
    private:
        int minimumBalance;

};

class Client{
    public:
      Client();
      Client(string name,string address,int phoneNumber);
      void setName(string name);
      string getName();
      void setAddress(string address);
      string getAddress();
      void setPhoneNumber(int phoneNumber);
      int getPhoneNumber();
    private:
        string name,address;
        int phoneNumber;
        Bank* basic;
        SavingsBankAccount* saving;

};

class BankingApplication{
    public:
        BankingApplication();
        int menu();


};

#endif // BANK_H

