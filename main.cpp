//
//  main.cpp
//  C++ Coding Project
//
//  Created by Beatrice Totanes on 06/01/2021.
//  Copyright © 2021 Beatrice Totanes. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

// Student Class
class student {
    string snum; //Student Number
    string lastName; //Last Name
    string gName; //Given Name
    string mName; //Middle Name
    string course;
    string bday; //Birthday
    float gwa; //GWA
    int age; //Age
    string seniority;
    string cStand; //Current Stanfding
    
    //Private function declarations
    private:
        int findAge(int, int, int, int, int, int);
    
    //Public function declarations
    public:
        student *next; //For connecting nodes
        student();
        student(string, string, string, string, string, string, float);
        void setStudentNum(string);
        void setLastName(string);
        void setGivenName(string);
        void setMiddleName(string);
        void setCourse(string);
        void setBday(string);
        void setGwa(float);
        void setAge(string);
        void setSeniority(string);
        void setCurrStand(float);
        string getStudentNum();
        string getLastName();
        string getGivenName();
        string getMiddleName();
        string getCourse();
        string getBday();
        float getGwa();
        int getAge();
        string getSeniority();
        string getCurrStand();
        void updateData(string, string, string, string, string, string, float); //Update Method
        void printData(); //Prints Data
};

// Linked List Class
class linkedList {
    student *head; //Points to the head of the list
    int elements; //counts no. of elements
    
    //Private function declarations
    void defaultSort(); //sort by student number
    void sortLastName();
    void sortGwa();
    void swap(student**, student**);
    
    //Public function declarations
    public:
        linkedList();
        int getElementCount(int);
        void addStudent();
        void insert();
        void removeStudent(string);
        void update();
        void print();
        void sortMenu();
        ~linkedList();
};


int main() {
    linkedList list;
    int c = 0;
    int choice;
    string snum;
    
    while (c == 0) {
        //Menu
        cout << "\nStudent Information System\n";
        cout << "[1] Add Student\n";
        cout << "[2] Delete Student\n";
        cout << "[3] Update Student Information\n";
        cout << "[4] Sort List\n";
        cout << "[5] Display Students\n";
        cout << "[0] Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 0:
                c = 1;
                break;
            case 1:
                list.insert();
                c = 0;
                break;
            case 2:
                cout << "\nEnter student number: ";
                cin >> snum;
                list.removeStudent(snum);
                c = 0;
                break;
            case 3:
                list.update();
                c = 0;
                break;
            case 4:
                list.sortMenu();
                c = 0;
                break;
            case 5:
                cout << "\n[Defaultly Sorted by Student Number]\n";
                list.print();
                c = 0;
                break;
            default:
                c = 0;
                cout << "Invalid input.\n"; //Prints message if user inputs a value other than 0 to 4
        }
        
    }
    
    return 0;
}

                            /*
                                FOR STUDENT CLASS <-------------------------------->
                                */
//Constructor---------------
//If user doesn't supply input upon instantiation, this constructor will be used.
student:: student(){
    snum = "0";
    lastName = "0";
    gName = "0";
    mName = "0";
    course = "0";
    bday = "0";
    gwa = 0;
    age = 0;
    seniority = "0";
    cStand = "0";
    next = NULL;
}

//If user supplies input upon instantiation, this constructor will be used.
student:: student(string snum, string lname, string gname, string mname, string course, string bday, float gwa){
    setStudentNum(snum);
    setLastName(lname);
    setGivenName(gname);
    setMiddleName(mname);
    setCourse(course);
    setBday(bday);
    setGwa(gwa);
    setAge(bday);
    setSeniority(snum);
    setCurrStand(gwa);
    next = NULL;
}

// Function Definitions
// 1. Updates Data of Student
void student:: updateData(string snum, string lname, string gname, string mname, string course, string bday, float gwa){
    setStudentNum(snum);
    setLastName(lname);
    setGivenName(gname);
    setMiddleName(mname);
    setCourse(course);
    setBday(bday);
    setGwa(gwa);
    setAge(bday);
    setSeniority(snum);
    setCurrStand(gwa);
}

// 2. Prints Student Data
void student:: printData(){
    cout << "Student Number: " << getStudentNum() << endl;
    cout << "Name: " << getLastName() << ", " << getGivenName() << " " << getMiddleName() << endl;
    cout << "Course: " << getCourse() << endl;
    cout << "Bday: " << getBday() << endl;
    cout << "GWA: " << getGwa() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Seniority: " << getSeniority() << endl;
    cout << "Current Standing: " << getCurrStand() << endl;
}

//Mutators----------------
// Assigns the data to the variables
void student:: setStudentNum(string snum){
    this->snum = snum;
}

void student:: setLastName(string lname){
    lastName = lname;
}

void student:: setGivenName(string givenName){
    gName = givenName;
}

void student:: setMiddleName(string middleName){
    mName = middleName;
}

void student:: setCourse(string course){
    this->course = course;
}

void student:: setBday(string bday){
    this->bday = bday;
}

void student:: setGwa(float gwa){
    this->gwa = gwa;
}

// For age, it will be calculated using the birthday of the student.
void student:: setAge(string bday){
    string tmpBYear;
    string tmpBMonth;
    string tmpBDayNum;
    stringstream tmp;
    int bYear;
    int bMonth;
    int bDate;
    int pYear; //present
    int pMonth; //present
    int pDay; //present
    string tmpBirthday = bday;
    
    tmpBirthday.erase(remove(tmpBirthday.begin(), tmpBirthday.end(), '-'), tmpBirthday.end()); //Removes dashes
    
    // Computes the current date
    time_t now = time(0);
    tm *locTime = localtime(&now);
    
    pYear = 1900 + locTime->tm_year;
    pMonth = 1 + locTime->tm_mon;
    pDay = locTime->tm_mday;
    
    // Gets year, month, and day
    tmpBYear = tmpBirthday.substr(0,4);
    tmpBMonth = tmpBirthday.substr(4,2);
    tmpBDayNum = tmpBirthday.substr(6,2);
    
    // Converts strings to numbers
    istringstream(tmpBYear) >> bYear;
    istringstream(tmpBMonth) >> bMonth;
    istringstream(tmpBDayNum) >> bDate;
    
    // Finds age through the findAge function
    age = findAge(pDay, pMonth, pYear, bDate, bMonth, bYear);
}

// Function to compute the age based on the birthday
int student:: findAge(int currDay, int currMonth, int currYr, int bDate, int bMonth, int bYear){
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (bDate > currDay) {
        currDay = currDay + month[bMonth - 1];
        currMonth = currMonth - 1;
    }
    
    if (bMonth > currMonth) {
        currYr = currYr - 1;
        currMonth = currMonth + 12;
    }

    int calcYear = currYr - bYear;
    
    return calcYear;
}

// For seniority, it will be computed based on the student number.
void student:: setSeniority(string sNum){
    string tmpNum;
    string tmpSNum = sNum;
    int yr;
    
    // Gets the first four digits of the student number which is equivalent to the year that the student entered university
    tmpNum = tmpSNum.substr(0,4);
    
    // Converts string to integer
    istringstream(tmpNum) >> yr;
    
    // If-else statements to determine the seniority of the student.
    if (yr >= 2014 && yr <= 2017) {
        seniority = "4th Year";
    }else if (yr == 2018) seniority = "3rd Year";
    else if (yr == 2019) seniority = "2nd Year";
    else if (yr == 2020) seniority = "1st Year";
    else seniority = "Invalid";
}

// For current standing, it is based on the GWA.
void student:: setCurrStand(float gwa){
    if (gwa > 3.0) {
        cStand = "Fail";
    } else if (gwa > 1.45 && gwa <= 1.75) {
        cStand = "Cum Laude";
    }else if (gwa > 1.20 && gwa <= 1.45) {
        cStand = "Magna Cum Laude";
    }else if (gwa >= 1.0 && gwa <= 1.20) {
        cStand = "Summa Cum Laude";
    }else cStand = "Pass";
}

//Accessors--------------
// Functions to access the private attributes
string student:: getStudentNum(){
    return snum;
}

string student::getLastName(){
    return lastName;
}

string student::getMiddleName(){
    return mName;
}

string student::getGivenName(){
    return gName;
}

string student:: getCourse(){
    return course;
}

string student::getBday(){
    return bday;
}

float student::getGwa(){
    return gwa;
}

int student::getAge(){
    return age;
}

string student::getSeniority(){
    return seniority;
}

string student::getCurrStand(){
    return cStand;
}

                /*
                    FOR LINKED LIST CLASS <-------------------------------->
                */

//Constructor
linkedList:: linkedList(){
    head = NULL; // Ensures head is pointing to NULL when object is first created
    elements = 0;
}

//Destructor to deallocate memory
linkedList:: ~linkedList(){
    student *tmp = head;
    student *next;
    
    while (tmp != NULL) {
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

// Function Definitions
// 1. Gets the number of elements in the list
int linkedList:: getElementCount(int count){
    return count;
}

// 2. Function to insert a new student
void linkedList:: insert(){
    student *tmp = new student();
    string snum;
    string lastName;
    string gName;
    string mName;
    string course;
    string bday;
    float gwa;
    
    cout << "\nStudent Number (Format: 20XX-XXXXX): ";
    cin >> snum;
    cout << "Last Name: ";
    cin.ignore();
    getline(cin, lastName);
    cout << "First Name: ";
    getline(cin, gName);
    cout << "Middle Name: ";
    getline(cin, mName);
    cout << "Course: ";
    getline(cin, course);
    cout << "Birthday (Format: YYYY-MM-DD): ";
    cin >> bday;
    cout << "GWA: ";
    cin >> gwa;
    
    tmp->updateData(snum, lastName, gName, mName, course, bday, gwa); //Updates data
    
    // Inserts the node in the linked list
    if (head == NULL) {
        head = tmp;
    }else{
        tmp->next = head;
        head = tmp;
        
        defaultSort(); // Linked list is defaultly sorted by student number
    }
    elements++;
    cout << "Student Added! \n";
}

// 3. Function to Sort by Student Number
void linkedList:: defaultSort(){
    string minStringNum;
    int minIntNum;
    string nextStringNum;
    int nextIntNum;
    student *tmp = head; //Traveller from node to node
    student *min;
    student *r;
    
    //Sorting through Selection Sort
    //Swaps data between nodes if the student numbers are not in ascending order
    while (tmp != NULL) {
        min = tmp; //Sets the minimum value
        r = tmp->next; //Gets the next node
        
        //This loop finds the minimum value from all of the nodes
        while (r != NULL) {
            //Converts the student number in the minimum value from string to integer
            minStringNum = min->getStudentNum();
            minStringNum.erase(remove(minStringNum.begin(), minStringNum.end(), '-'), minStringNum.end());
            istringstream(minStringNum) >> minIntNum;
            
            //Converts the student number in 'r' from string to integer
            nextStringNum = r->getStudentNum();
            nextStringNum.erase(remove(nextStringNum.begin(), nextStringNum.end(), '-'), nextStringNum.end());
            istringstream(nextStringNum) >> nextIntNum;
            
            //If the student number in 'r' is greater than the student number in 'min', 'r' will become 'min' since it is currently the minimum/smallest value.
            if (minIntNum > nextIntNum) {
                min = r;
            }
            
            //Proceeds to the next node to compare and find the minimum value
            r = r->next;
        }
        
        //Swaps the data between the node w/ the current minimum/smallest student number to the node 'tmp'
        swap(&tmp, &min);
        tmp = tmp->next;
    }
    
}

// 4. Function to Sort by Last Name
void linkedList:: sortLastName(){
    student *tmp = head; //Traveller from node to node
    student *r;
    student *min;
    int compare;
    string minString;
    string nextString;
    string minFirst;
    string nextFirst;
    
    //Sorting through Selection Sort
    //Swaps data between nodes if the last names are not in ascending order
    while (tmp != NULL) {
        min = tmp; //Sets the minimum value/last name
        r = tmp->next; //Gets the next node
        
        //This loop finds the minimum value from all of the nodes
        while (r != NULL) {
            minString = min->getLastName(); //Gets the last name of the current minimum node
            nextString = r->getLastName(); //Gets the last name of 'r' node
            
            compare = minString.compare(nextString);
            //If minString is smaller than nextString, then 'min' will be equal to 'r' since the last name in 'r' comes first currently than the last name in 'min'
            if (compare > 0) {
                min = r;
            }
            //Proceeds to the next node to compare and find the minimum value/last name
            r = r->next;
        }
        
        //Swaps the data between the node w/ the current minimum/smallest student number to the node 'tmp'
        swap(&tmp, &min);
        tmp = tmp->next;
    }
    
    tmp = head;
    
    // After sorting by last name, if there are same last names, sort by first name to break the tie.
    while (tmp != NULL) {
        min = tmp; //Sets the minimum value/last name
        r = tmp->next; //Gets the next node
        
        //This loop finds the minimum value from all of the nodes
        while (r != NULL) {
            minString = min->getLastName(); //Gets the last name of the current minimum node
            nextString = r->getLastName(); //Gets the last name of 'r' node
            
            compare = minString.compare(nextString);
            //If minString is smaller than nextString, then 'min' will be equal to 'r' since the last name in 'r' comes first currently than the last name in 'min'
            if (compare == 0) {
                minString = min->getGivenName(); //Gets the last name of the current minimum node
                nextString = r->getGivenName(); //Gets the last name of 'r' node
                
                compare = minString.compare(nextString);
                if (compare > 0) {
                    min = r;
                }
            }
            //Proceeds to the next node to compare and find the minimum value/last name
            r = r->next;
        }
        
        //Swaps the data between the node w/ the current minimum/smallest student number to the node 'tmp'
        swap(&tmp, &min);
        tmp = tmp->next;
    }
}

// 5. Function to Sort by GWA
void linkedList:: sortGwa(){
    float minGwa;
    float rGwa;
    student *tmp = head; //Traveller from node to node
    student *min;
    student *r;
    string minLName;
    string nextLName;
    string minFName;
    string nextFName;
    int compareLName;
    
    //Sorting through Selection Sort
    //Swaps data between nodes if the student numbers are not in ascending order
    while (tmp != NULL) {
        min = tmp; //Sets the minimum value
        r = tmp->next; //Gets the next node
        
        //This loop finds the minimum value from all of the nodes
        while (r != NULL) {
            minGwa = min->getGwa(); //Gets the gwa from the 'min' node
            rGwa = r->getGwa(); //Gets the gwa from the current 'r' node
            
            //If the GWA in 'r' is greater than the student number in 'min', 'r' will become 'min' since it is currently the minimum/smallest value.
            if (minGwa > rGwa) {
                min = r;
            }else if (minGwa == rGwa){
                //Breaking the tie
                minLName = min->getLastName();
                nextLName = r->getLastName();
                
                compareLName = minLName.compare(nextLName);
                if (compareLName > 0) {
                    swap(&r, &min);
                }else if (compareLName == 0){
                    minFName = min->getGivenName();
                    nextFName = r->getGivenName();
                }
            }
            
            //Proceeds to the next node to compare and find the minimum value
            r = r->next;
        }
        
        //Swaps the data between the node w/ the current minimum/smallest student number to the node 'tmp'
        swap(&tmp, &min);
        tmp = tmp->next;
    }

}

// 6. Function to Swap Student Information if it is Unsorted
void linkedList:: swap(student **tmp, student **min){
    string tmpSnum;
    string tmpLName;
    string tmpMName;
    string tmpGName;
    string tmpCourse;
    string tmpBday;
    float tmpGwa;
    
    //Student Number swap
    tmpSnum = (*tmp)->getStudentNum();
    (*tmp)->setStudentNum((*min)->getStudentNum());
    (*min)->setStudentNum(tmpSnum);
    
    //Last Name Swap
    tmpLName = (*tmp)->getLastName();
    (*tmp)->setLastName((*min)->getLastName());
    (*min)->setLastName(tmpLName);
    
    //Middle Name Swap
    tmpMName = (*tmp)->getMiddleName();
    (*tmp)->setMiddleName((*min)->getMiddleName());
    (*min)->setMiddleName(tmpMName);
    
    //Given Name Swap
    tmpGName = (*tmp)->getGivenName();
    (*tmp)->setGivenName((*min)->getGivenName());
    (*min)->setGivenName(tmpGName);
    
    //Course Swap
    tmpCourse = (*tmp)->getCourse();
    (*tmp)->setCourse((*min)->getCourse());
    (*min)->setCourse(tmpCourse);
    
    //Bday Swap
    tmpBday = (*tmp)->getBday();
    (*tmp)->setBday((*min)->getBday());
    (*min)->setBday(tmpBday);
    
    //Gwa Swap
    tmpGwa = (*tmp)->getGwa();
    (*tmp)->setGwa((*min)->getGwa());
    (*min)->setGwa(tmpGwa);
    
    //Age, Seniority, Curr Standing Swap
    (*tmp)->setAge((*tmp)->getBday());
    (*tmp)->setSeniority((*tmp)->getStudentNum());
    (*tmp)->setCurrStand((*tmp)->getGwa());
    
    (*min)->setAge((*min)->getBday());
    (*min)->setSeniority((*min)->getStudentNum());
    (*min)->setCurrStand((*min)->getGwa());
}

// 7. Function for the Menu for Sorting
void linkedList:: sortMenu(){
    int choice;
    
    cout << "\n\nSort According to:\n";
    cout << "[1] Student Number\n";
    cout << "[2] Last Name\n";
    cout << "[3] GWA\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            defaultSort();
            cout << "\n[Defaultly Sorted by Student Number]\n";
            print();
            break;
        case 2:
            sortLastName();
            cout << "\n[Temporarily Sorted by Last Name]\n";
            print();
            defaultSort(); // Will sort again by student number to restore to default sort
            break;
        case 3:
            sortGwa();
            cout << "\n[Temporarily Sorted by GWA]\n";
            print();
            defaultSort(); // Will sort again by student number to restore to default sort
            break;
        default:
            cout << "Invalid input.\n"; //Prints message if user inputs a value other than 0 to 4
            break;
    }
}

// 8. Function to remove/delete a student from the list based on student number
void linkedList:: removeStudent(string snum){
    student *current = head;
    int compare;
    student *before;
    student *tmp;
    bool exists = false;
    
    //If list is not empty, proceed to finding the student that will be deleted via student number.
    if (current != NULL) {
        compare = snum.compare(current->getStudentNum()); //If compare == 0, then the student number matches the student number to be deleted
        if (compare == 0) {
            head = head->next;
            delete current;
            exists = true;
            elements--; //Decrements no. of elements in the list
        }
        
        //If the node at the beginning isn't the one to be deleted, then proceed to finding the the matching student number in the succeeding nodes.
        if (exists == false) {
            before = current;
            current = current->next;
            while (current != NULL) {
                compare = snum.compare(current->getStudentNum());
                if (compare == 0) {
                    tmp = current;
                    //Connects the node before the node to be deleted to the next node after the node to be deleted
                    before->next = tmp->next;
                    delete tmp;
                    elements--; //Decrements no. of elements in the list
                    exists = true;
                    break;
                }
                before = current;
                current = current->next;
            }
        }
        
        //If the student number exists in the database, then it will print the message that the student has been removed. Else, the student does not exist.
        if(exists == true){
            cout << "\nStudent w/ student number [" << snum << "] has been removed from the database.\n";
        }else cout << "\nStudent does not exist.\n";
    }else cout << "\nList is currently empty.\n";
}

// 9. Function to update the attribute(s) of the student in the linked list
void linkedList:: update(){
    int compare;
    int c = 0;
    int choice;
    string text;
    float num;
    student *tmp = head;
    string snum;
    bool exists = false;
    
    // If list is not empty, then it will proceed to asking for the student number.
    if (head != NULL) {
        cout << "\nEnter student number: ";
        cin >> snum;
        
        while (tmp != NULL) {
            compare = snum.compare(tmp->getStudentNum()); // Checks if the student exists in the database
            
            // If compare == 0, it means that the student exists and proceeds to asking the user what attribute to edit.
            if (compare == 0) {
                exists = true;
                while (c == 0) {
                    //Menu
                    cout << "\nStudent Number: " << tmp->getStudentNum() << endl;
                    cout << "[1] First Name: " << tmp->getGivenName() << endl;
                    cout << "[2] Middle Name: " << tmp->getMiddleName() << endl;
                    cout << "[3] Last Name: " << tmp->getLastName() << endl;
                    cout << "[4] Birthday: " << tmp->getBday() << endl;
                    cout << "[5] Course: " << tmp->getCourse() << endl;
                    cout << "[6] GWA: " << tmp->getGwa() << endl;
                    printf("[0] Back to Main Menu\n");
                    printf("Enter data to edit [1-6] or 0 to go back to Main Menu: ");
                    cin >> choice;
                    
                    switch (choice) {
                        case 0:
                            c = 1;
                            break;
                        case 1:
                            cout << "Enter first name: ";
                            cin.ignore();
                            getline(cin, text);
                            tmp->setGivenName(text);
                            c = 0;
                            break;
                        case 2:
                            cout << "Enter middle name: ";
                            cin.ignore();
                            getline(cin, text);
                            tmp->setMiddleName(text);
                            c = 0;
                            break;
                        case 3:
                            cout << "Enter last name: ";
                            cin.ignore();
                            getline(cin, text);
                            tmp->setLastName(text);
                            c = 0;
                            break;
                        case 4:
                            cout << "Enter birthday (Format: YYYY-MM-DD): ";
                            cin.ignore();
                            getline(cin, text);
                            tmp->setBday(text);
                            tmp->setAge(text);
                            c = 0;
                            break;
                        case 5:
                            cout << "Enter course: ";
                            cin.ignore();
                            getline(cin, text);
                            tmp->setCourse(text);
                            c = 0;
                            break;
                        case 6:
                            cout << "Enter GWA: ";
                            cin >> num;
                            tmp->setGwa(num);
                            tmp->setCurrStand(num);
                            c = 0;
                            break;
                        default:
                            c = 0;
                            cout << "Invalid input.\n"; //Prints message if user inputs a value other than 0 to 4
                    }
                }
               
                break;
            }
            tmp = tmp->next;
        }
        
        if (exists == false) {
            cout << "\nStudent does not exist.\n";
        }
        
    }else cout << "\nList is empty.";
}

//Utility Method for Printing
void linkedList:: print(){
    student *tmp = head;
    cout << endl << "The no. of elements on the list are: [" << elements << "].\n" << endl;
    
    if (elements == 0) {
        cout << "\nList is empty.\n";
    }
    
    while (tmp != NULL) {
        tmp->printData();
        cout << endl;
        tmp = tmp->next;
    }
}

