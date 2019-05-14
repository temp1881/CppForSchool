#include "account.h"

void Account::create_account() {
    std::cout << "\nEnter the account No. : ";
    std::cin >> acno;
    std::cout << "\nEnter the name of the account holder : ";
    std::cin.ignore();
    std::cin.getline(name,50);
    std::cout << "\nEnter type of account (C/S) : ";
    std::cin >> type;
    type = char(toupper(type));
    std::cout << "\nEnter the initial ammount (>= 500 for saving, >= 1000 for current : ";
    std::cin >> deposit;
    std::cout << "\n\n\nAccount created..\n";
}

void Account::show_account() const {
    std::cout << "\nAccount No. : " << acno;
    std::cout << "\nAccount holder name : " << name;
    std::cout << "\nType of account : " << type;
    std::cout << "\nBalance of account : " << deposit;
}

void Account::modify() {
    std::cout << "\nAccount number : " << acno;
    std::cout << "\nModify account holder name : ";
    std::cin.ignore();
    std::cin.getline(name,50);
    std::cout << "\nModify type of account : ";
    std::cin >> type;
    type = char(toupper(type));
    std::cout << "\nModify balance amount : ";
    std::cin >> deposit;
}

void Account::dep(int x) {
    deposit += x;
}

void Account::draw(int x) {
    deposit -= x;
}

void Account::report() const {
    std::cout << acno << std::setw(10) << " " << name << std::setw(8) << " "
              << type << std::setw(4) << " " << deposit << "\n";
}

void write_account()
{
    Account ac;
    std::ofstream outFile;
    outFile.open("account.dat",std::ios::binary|std::ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
    outFile.close();
}

void display_sp(int n) {
    Account ac;
    bool flag = false;
    std::ifstream inFile;
    inFile.open("account.dat",std::ios::binary);
    if(!inFile) {
        std::cout << "File could not be open !! press any key ...\n";
        return;
    }

    std::cout << "\nBALANCE DETAILS\n";

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        if(ac.ret_acno() == n) {
            ac.show_account();
            flag = true;
        }
    }

    inFile.close();
    if(flag == false) {
        std::cout << "\n\nAccount number does not exist\n";
    }

}

void modify_account(int n) {
    bool found = false;
    Account ac;
    std::fstream file;
    file.open("account.dat",std::ios::binary|std::ios::in|std::ios::out);
    if(!file) {
        std::cout << "\nFile could not be open !! press any key to continue..\n";
        return;
    }

    while(!file.eof() && found == false) {
        file.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.ret_acno() == n) {
            ac.show_account();
            std::cout << "\n\nEnter the new details of account\n";
            ac.modify();
            int pos = (-1)*static_cast<int> (sizeof(Account));
            file.seekp(pos,std::ios::cur);
                    file.write(reinterpret_cast<char *>(&ac), sizeof(Account));
            std::cout << "\n\n\t Record Updated\n";
            found = true;
        }
    }

    file.close();
    if(found == false) {
        std::cout << "\n\n Record not found \n";
    }
}

void delete_account(int n) {
    Account ac;
    std::ifstream inFile;
    std::ofstream outFile;

    inFile.open("account,dat",std::iostream::binary);
    if(!inFile) {
        std::cout << "\nCould not open File !! press any key to continue...\n";
        return;
    }

    outFile.open("temp.dat",std::ios::binary);
    inFile.seekg(0,std::ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        if(ac.ret_acno() != n) {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
        }
    }

    inFile.close();
    outFile.close();

    remove("account.dat");
    rename("Temp.dat","account.dat");
    std::cout << "\n\n\t Record Deleted..\n";
}

void display_all() {
    Account ac;
    std::ifstream inFile;
    inFile.open("account.dat",std::ios::binary);
    if(!inFile) {
        std::cout << "\nFile could not be open !! press any key to continue..\n";
        return;
    }

    std::cout << "\n\n\t ACCOUNT HOLDER LIST \n\n";
    std::cout << "====================================================\n";
    std::cout << "A/c no.      NAME           Type  Balance\n";
    std::cout << "====================================================\n";

    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        ac.report();
    }
    inFile.close();
}

void deposit_withdraw(int n, int option) {
    int amt;
    bool found = false;
    Account ac;
    std::fstream file;
    file.open("account.dat",std::ios::binary|std::ios::in|std::ios::out);
    if(!file) {
        std::cout << "\nFile could not be open !! Press any key to continue..\n";
        return;
    }

    while(!file.eof() && found == false) {
        file.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        if(ac.ret_acno() == n) {
            ac.show_account();
            if(option == 1) {
                std::cout << "\n\n\tTO DEPOSIT AMOUNT ";
                std::cout << "\n\nEnter the amount to be deposited : ";
                std::cin >> amt;
                ac.dep(amt);
            }
            if(option == 2) {
                std::cout << "\n\n\tTO WITHDRAW AMOUNT ";
                std::cout << "\n\nEnter the amount to be withdraw : ";
                std::cin >> amt;
                int bal = ac.ret_deposit() - amt;
                if((bal < 500 && ac.ret_type() == 'S') || (bal < 1000 && ac.ret_type() == 'C')) {
                    std::cout << "Insufficient balance\n";
                }
                else {
                    ac.draw(amt);
                }
            }
            int pos = (-1)*static_cast<int> (sizeof(ac));
            file.seekp(pos,std::ios::cur);
            file.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            std::cout << "\n\n\t Record updated\n";
            found = true;
        }
    }
    if(found == false) {
        std::cout << "\n\n Record not found \n";
    }
}

void intro() {
    std::cout << "\n\n\n\t   BANK"
              << "\n\n\tMANAGEMENT"
              << "\n\n\t  SYSTEM\n";
    std::cin.get();

}





























