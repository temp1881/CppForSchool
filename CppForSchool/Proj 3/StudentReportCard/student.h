#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <fstream>

class Student {
public:
    void create();
    void show();
    void report();
    void modify();

    int get_num() const { return num;}

private:
    int num;
    char name[50];

    int p_mark, c_mark, m_mark, e_mark, cs_mark;

    double perc;
    char grade;
};

//-----------------------------------------------------------------------------------
// Defining class functions


void Student::create() {
    std::cout << "\nEnter the roll number of student : ";
    std::cin >> num;
    std::cout << "\nEnter name of student : ";
    std::cin.ignore();
    std::cin.getline(name,50);

    std::cout << "\nEnter the marks in physics : ";
    std::cin >> p_mark ;
    std::cout << "\nEnter the marks in chemistry : ";
    std::cin >> c_mark;
    std::cout << "\nEnter the marks in math : ";
    std::cin >> m_mark;
    std::cout << "\nEnter the marks in english : ";
    std::cin >> e_mark;
    std::cout << "\nEnter the marks in computer science : ";
    std::cin >> cs_mark;

    perc = (p_mark + c_mark + m_mark + e_mark + cs_mark) / 5;
    grade = (perc >= 90) ? 'A' : (perc >= 80) ? 'B' : (perc >= 70) ? 'C'
                               : (perc >= 60) ? 'D' : (perc >= 50 ? 'E' : 'F');

    std::cout << "\nStudent report has been created\n\n";
    system("pause");
}

void Student::show() {
    std::cout << "\nStudent roll number : " << num;
    std::cout << "\nStudent name : " << name;
    std::cout << "\nMarks in physics : " << p_mark;
    std::cout << "\nMarks in chemistry : " << c_mark;
    std::cout << "\nMarks in math : " << m_mark;
    std::cout << "\nMarks in english : " << e_mark;
    std::cout << "\nMarks in computer science : " << cs_mark;
    std::cout << "\nPercentage of student is : " << perc;
    std::cout << "\nGrade of student is : " << grade;

    std::cout << "\n\n------------------------------\n\n";
}

void Student::report() {
    std::cout << num << std::setw(19) << name << std::setw(12) << p_mark
              << std::setw(12) << c_mark << std::setw(12) << m_mark
              << std::setw(12) << e_mark << std::setw(12) << cs_mark
              << std::setw(12) << perc << std::setw(12) << grade << "\n";
}

void Student::modify() {
    std::cout << "\nStudent roll number : " << num << "\n";
    std::cout << "Enter the marks in physics : ";
    std::cin >> p_mark;
    std::cout << "Enter the marks in chemistry : ";
    std::cin >> c_mark;
    std::cout << "Enter the marks in math : ";
    std::cin >> m_mark;
    std::cout << "Enter the marks in english : ";
    std::cin >> e_mark;
    std::cout << "Enter the marks in computer science : ";
    std::cin >> cs_mark;

    perc = (p_mark + c_mark + m_mark + e_mark + cs_mark) / 5;
    grade = (perc >= 90) ? 'A' : (perc >= 80) ? 'B' : (perc >= 70) ? 'C'
                               : (perc >= 60) ? 'D' : (perc >= 50 ? 'E' : 'F');

    std::cout << "\nStudent report has been modified\n\n";

}

// Class functions definitions ends here
//-----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
// Defining general functions

void intro();
void create_student_record();
void entry_menu();
void display_all();
void display_single();
void modify_student();
void delete_student();


void intro() {
    std::cout << "\n\n\t   STUDENT";
    std::cout << "\n\n\t REPORT CARD";
    std::cout << "\n\n\t   SYSTEM\n\n\n";

    system("pause");
}

void entry_menu() {
    system("cls");

    std::cout << "\n\n  ENTRY MENU";
    std::cout << "\n\n  1. CREATE STUDENT RECORD";
    std::cout << "\n\n  2. DISPLAY ALL STUDENTS RECORD";
    std::cout << "\n\n  3. SEARCH STUDENT RECORD";
    std::cout << "\n\n  4. MODIFY STUDENT RECORD";
    std::cout << "\n\n  5. DELETE STUDENT RECORD";
    std::cout << "\n\n  6. BACK TO MAIN MENU";
    std::cout << "\n\n  Please enter your choice <1-6>\n\n";

    int choice = 0;
    std::cin >> choice;


    switch(choice) {
    case 1:
        create_student_record();
        break;
    case 2:
        display_all();
        break;
    case 3:
        display_single();
        break;
    case 4:
        modify_student();
        break;
    case 5:
        delete_student();
        break;
    case 6:
        break;
    default:
        std::cout << "\n\nError: option non existe\n\n";
        return;
    }
}

void create_student_record() {
    system("cls");

    Student s;
    s.create();

    std::ofstream ofs;
    ofs.open("students.txt",std::ios::binary|std::ios::app);

    ofs.write(reinterpret_cast<char* > (&s), sizeof(Student));
    ofs.close();
}

void display_all() {
    system("cls");

    Student s;

    std::ifstream ifs;
    ifs.open("students.txt",std::ios::binary);
    if(!ifs) {
        std::cout << "\nCould not open file\n";
        return;
    }

    std::cout << "Roll num.         Name       Physics    Chemistry      Math      English       C.S        %age        Grade\n";
    std::cout << "\n-----------------------------------------------------------------------------------------------------------\n";

    while(ifs.read(reinterpret_cast<char *> (&s), sizeof(Student))) {
        s.report();
    }

    ifs.close();
    system("pause");
}

void display_single() {
    system("cls");

    std::cout << "\nEnter student roll number : ";
    int n = 0;
    std::cin >> n;

    std::cout << "\n------------------------------\n";

    Student s;
    bool flag = false;

    std::ifstream ifs;
    ifs.open("students.txt",std::ios::binary);
    if(!ifs) {
        std::cout << "\nCould not open file\n";
        return;
    }

    while(ifs.read(reinterpret_cast<char *> (&s),sizeof(Student))) {
        if(s.get_num() == n) {
            s.show();
            flag = true;
        }
    }

    ifs.close();
    if(flag == false) {
        std::cout << "\n\nStudent record not found\n\n";
    }
    system("pause");
}

void modify_student() {
    system("cls");

    std::cout << "\nEnter student roll number : ";
    int n = 0;
    std::cin >> n;

    std::fstream fs;
    fs.open("students.txt",std::ios::binary|std::ios::in|std::ios::out);
    if(!fs) {
        std::cout << "Caould not open file!\n";
        return;
    }

    Student s;
    bool found = false;

    while(!fs.eof() && found == false) {
        fs.read(reinterpret_cast<char *>(&s),sizeof(Student));
        if(s.get_num() == n) {
            s.show();

            std::cout << "\nEnter the new details to modify : ";
            s.modify();

            int pos = (-1)*static_cast<int>((sizeof(Student)));
            fs.seekp(pos,std::ios::cur);

            fs.write(reinterpret_cast<char *>(&s),(sizeof(Student)));

            found = true;
        }
    }

    fs.close();
    if(found == false) {
        std::cout << "\nStudent record not found\n\n";
    }
    system("pause");
}

void delete_student() {
    system("cls");

    std::cout << "\nEnter student roll number : ";
    int n = 0;
    std::cin >> n;

    Student s;

    std::ifstream ifs;
    ifs.open("students.txt",std::ios::binary);
    if(!ifs) {
        std::cout << "\nCould not open file\n";
        return;
    }

    std::ofstream ofs;
    ofs.open("temp.txt",std::ios::binary);
    ifs.seekg(0,std::ios::beg);
    while(ifs.read(reinterpret_cast<char *> (&s), sizeof (Student))) {
        if(s.get_num() != n) {
            ofs.write(reinterpret_cast<char *> (&s), sizeof (Student));
        }
    }

    ifs.close();
    ofs.close();

    remove("students.txt");
    rename("temp.txt","students.txt");
    std::cout << "\nStudent report deleted\n\n";
    system("pause");
}


//-----------------------------------------------------------------------------------

#endif // STUDENT_H
