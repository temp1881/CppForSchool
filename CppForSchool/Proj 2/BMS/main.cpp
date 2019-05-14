#include "account.h"
#include <iostream>

int main() {
    char ch;
    int num;

    intro();

    do {
        system("cls");

        std::cout<<"\n\n\n\tMAIN MENU";
        std::cout<<"\n\n\t01. NEW ACCOUNT";
        std::cout<<"\n\n\t02. DEPOSIT AMOUNT";
        std::cout<<"\n\n\t03. WITHDRAW AMOUNT";
        std::cout<<"\n\n\t04. BALANCE ENQUIRY";
        std::cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
        std::cout<<"\n\n\t06. CLOSE AN ACCOUNT";
        std::cout<<"\n\n\t07. MODIFY AN ACCOUNT";
        std::cout<<"\n\n\t08. EXIT";

        std::cout<<"\n\n\tSelect Your Option (1-8)\n";

        std::cin >> ch;

        system("cls");

        switch(ch) {
        case '1':
            write_account();
            break;
        case '2':
            std::cout << "\n\n\tEnter the account No. : ";
            std::cin >> num;
            deposit_withdraw(num,1);
            break;
        case '3':
            std::cout << "\n\n\tEnter the account No. : ";
            std::cin >> num;
            deposit_withdraw(num,2);
            break;
        case '4':
            std::cout << "\n\n\tEnter the account No. : ";
            std::cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            std::cout << "\n\n\tEnter the account No. : ";
            std::cin >> num;
            delete_account(num);
            break;
        case '7':
            std::cout << "\n\n\tEnter the account No. : ";
            std::cin >> num;
            modify_account(num);
            break;
        case '8':
            std::cout << "\nThank you for using bank management system\n";
            break;
        default:
            std::cout << "\a";
        }
        std::cin.ignore();
        std::cin.get();
    } while ( ch != '8');
    return 0;
}
