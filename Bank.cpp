#include "Bank.h"
#include <iostream>
#include <fstream>

using namespace std;


int Bank::counter=1;
Bank::Bank()
{
    balance=0;
    accountId=counter;
    counter++;
}

Bank::Bank(int accountId,int balance)
{
    this->accountId=accountId;
    this->balance=balance;

}

void Bank::setaccountId(int accountId){
   this->accountId=accountId;
}

int Bank::getaccountId()
{

    return accountId;

}

void Bank::setbalance(int balance)
{
    this->balance=balance;
}

int Bank::getbalance()
{
    return balance;
}

void Bank::withdraw(int amount)
{
    if (amount<=balance)
    {
        balance=balance-amount;
        cout<<"thank you"<<endl;
        cout<<"new balance : "<<getbalance()<<endl;
    }
    else
        cout<<"sorry, this is more than you can withdraw"<<endl;

}

void Bank::deposit(int amount)
{
    balance+=amount;
    cout<<"thank you"<<endl;
    cout<<"new balance : "<<getbalance()<<endl;

}

SavingsBankAccount::SavingsBankAccount()
{
    minimumBalance=1000;
    balance=1000;
}

void SavingsBankAccount::setminimumBalance(int minimumBalance)
{
    this->minimumBalance=minimumBalance;
}

int SavingsBankAccount::getminimumBalance()
{
    return minimumBalance;
}

void SavingsBankAccount::withdraw(int amount)
{
    if (amount<=balance && amount>minimumBalance)
    {
        balance=balance-amount;
        cout<<"thank you"<<endl;
        cout<<"new balance : "<<getbalance()<<endl;
    }
    else
        cout<<"sorry, this is more than you can withdraw"<<endl;

}

void SavingsBankAccount::deposit(int amount)
{
    if(amount>=100)
    {
        balance+=amount;
        cout<<"thank you"<<endl;
        cout<<"new balance : "<<getbalance()<<endl;
    }
    else
        cout<<"you must add at least 100 pound"<<endl;
}
Client::Client() {};
Client::Client(string name,string address,int phoneNumber)
{
    this->name=name;
    this->address=address;
    this->phoneNumber=phoneNumber;

}
void Client::setName(string name)
{
    this->name=name;
}
string Client::getName()
{
    return name;
}
void Client::setAddress(string address)
{
    this->address=address;
}
string Client::getAddress()
{
    return address;
}
void Client::setPhoneNumber(int phoneNumber)
{
    this->phoneNumber=phoneNumber;
}
int Client::getPhoneNumber()
{
    return phoneNumber;
}

BankingApplication::BankingApplication() {}

int BankingApplication::menu()
{
    while(int x = 1)
    {
        int choice;
        cout<<"Welcome to FCI Banking Application and Information \n"
            <<"1. Create a New Account \n"
            <<"2. List Clients and Accounts \n"
            <<"3. Withdraw Money \n"
            <<"4. Deposit Money \n"
            <<"Please Enter Choice =========> ";
        cin>>choice;
        if(choice==1)
        {
            string name,address;
            int phoneNumber;
            Client person;
            cout<<"Enter client name =========> ";
            cin>>name;
            person.setName(name);
            cout<<"Enter client address =========> ";
            cin>>address;
            person.setAddress(address);
            cout<<"Enter client phone number =========> ";
            cin>>phoneNumber;
            person.setPhoneNumber(phoneNumber);

            int choice2 ;
            cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 Please Enter Choice =========> ";
            cin>>choice2;
            if (choice2==1)
            {
                Bank account;
                int balance;
                cout<<"Please Enter the Starting Balance =========> ";
                cin>>balance;
                account.setbalance(balance);

                cout<<"An account was created with ID : "<<account.getaccountId()<<" and starting balance "<<account.getbalance()<<"L.E."<<endl;
                ofstream information("information.txt", ios::app);
                information<<person.getName()<<" "<<person.getAddress()<<" "<<person.getPhoneNumber()<<" "<<account.getaccountId()<<" "<<account.getbalance()<<" "<<choice2;
                information.close();
            }
            else
            {
                SavingsBankAccount account;
                int balance;
                cout<<"The account is open by a default value of 1000 L.E if you want add another balance,please enter this balance if no enter 0 "<<endl;
                cin>>balance;
                account.setbalance(1000+balance);
                cout<<"an account was created with ID : "<<account.getaccountId()<<" and starting balance "<<account.getbalance()<<"L.E."<<endl;

                ofstream information("information.txt" , ios::app);
                information<<person.getName()<<" "<<person.getAddress()<<" "<<person.getPhoneNumber()<<" "<<account.getaccountId()<<" "<<account.getbalance()<<" "<<choice2;
                information.close();

            }
        }
        else if(choice==2)
        {
            ifstream read("information.txt");
            string name,address;
            int balance,id,choice2,phoneNumber;
            while(read>>name>>address>>phoneNumber>>id>>balance>>choice2)
            {
                cout<<"Name: "<<name<<endl<<"Address: "<<address<<endl<<"Id: "<<id<<endl<<"Balance: "<<balance<<endl
                <<"-------------------------------------------------------------------"<<endl;
            }
        }
        else if(choice==3)
        {
            string name,address;
            int balance,id,idFile,choice2, phoneNumber;
            cout<<"Enter Account ID : ";
            cin>>id;
            ifstream read("information.txt");

            while(read>>name>>address>>phoneNumber>>idFile>>balance>>choice2)
            {
                if(id==idFile)
                {
                    cout<<"Account ID : "<<id<<endl<<"balance : "<<balance<<endl;
                    if (choice2==1)
                    {
                        Bank user;
                        user.setbalance(balance);
                        int withdraws;
                        cout<<"Please Enter The Amount to Withdraw ";
                        cin>>withdraws;
                        user.withdraw(withdraws);

                    }
                    else if (choice2==2)
                    {
                        SavingsBankAccount user;
                        user.setbalance(balance);
                        int withdraws;
                        cout<<"Please Enter The Amount to Withdraw ";
                        cin>>withdraws;
                        user.withdraw(withdraws);

                    }

                }
            }
        }
        else if(choice==4)
        {
            string name,address;
            int balance,id,idFile,choice2, phoneNumber;
            cout<<"Enter Account ID : ";
            cin>>id;
            ifstream read("information.txt");

            while(read>>name>>address>>phoneNumber>>idFile>>balance>>choice2)
            {
                if(id==idFile)
                {
                    cout<<"Account ID : "<<id<<endl<<"balance : "<<balance<<endl;
                    if (choice2==1)
                    {
                        Bank user;
                        user.setbalance(balance);
                        int Deposits;
                        cout<<"Please Enter The Amount to Deposit ";
                        cin>>Deposits;
                        user.deposit(Deposits);


                    }
                    else if (choice2==2)
                    {
                        SavingsBankAccount user;
                        user.setbalance(balance);
                        int Deposits;
                        cout<<"Please Enter The Amount to Deposit ";
                        cin>>Deposits;
                        user.deposit(Deposits);
                    }
                }
            }
        }
    }
}



