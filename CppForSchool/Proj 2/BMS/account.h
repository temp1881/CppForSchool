#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <istream>
#include <fstream>
#include <cctype>
#include <iomanip>

class Account {
public:
    void create_account();       //function that gets data from user
    void show_account() const;   //show data on screen
    void modify();               //add new data
    void dep(int x);               //accept amount and add to balance
    void draw(int x);              //accept amount and subtract to balance
    void report() const;         //shows data in tabular format


    int ret_acno() const {return acno;}     // return account number
    int ret_deposit() const {return deposit;}     // return balance amount
    char ret_type() const {return type;}     // return type of account

private:
    int acno;
    char name[50];
    int deposit;
    char type;
};

void write_account();	//function to write record in binary file

void display_sp(int n);	//function to display account details given by user

void modify_account(int n);	//function to modify record of file

void delete_account(int n);	//function to delete record of file

void display_all();		//function to display all account details

void deposit_withdraw(int n, int option); // function to desposit/withdraw amount for given account

void intro();	//introductory screen function

#endif // ACCOUNT_H
