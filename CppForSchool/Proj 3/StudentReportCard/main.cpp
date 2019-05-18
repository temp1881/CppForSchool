#include "student.h"

int main() {

    intro();

    while(true) {

        system("cls");
        std::cout << "\n\n  MAIN MENU";
        std::cout << "\n\n  01. ENTRY/EDIT MENU";
        std::cout << "\n\n  02. EXIT";
        std::cout << "\n\n  Please select your option <1-2>\n\n";

        int option = 0;
        std::cin >> option;

        switch(option) {
        case 1:
            entry_menu();
            break;
        case 2:
            system("cls");
            std::cout << "\n\nThanks for using the student report card!\n";
            std::cout << "\n\nClosing...\n\n";
            return 0;
        default:
            std::cout << "Error: option non existe (MAIN MENU)\n";
            return 1;
        }
    }

}
