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

using namespace std;

class student {
    string snum;
    string lastName;
    string gName;
    string mName;
    string course;
    string bday;
    float gwa;
    int age;
    string seniority;
    string cStand;
    
    private:
        int findAge(int, int, int, int, int, int);
    
    public:
        student *next;
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

class linkedList {
    student *head;
    student *tail;
    int elements; //counts no. of elements
    
    void defaultSort(); //sort by student number
    void sortLastName();
    void sortGwa();
    void swap(student**, student**);
    
    public:
        linkedList();
        int getElementCount(int);
        void addStudent();
        void insert();
        void removeStudent();
        void print();
        void sortMenu();
        ~linkedList();
};


int main() {
    linkedList list;
    int c = 0;
    int choice;
    
    while (c == 0) {
        //Menu
        cout << "\n\nStudent Information System\n";
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
                c = 0;
                break;
            case 3:
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
                list.~linkedList();
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

void student:: setAge(string bday){
    string tmpBYear;
    string tmpBMonth;
    string tmpBDayNum;
    int bYear;
    int bMonth;
    int bDate;
    int pYear;
    int pMonth;
    int pDay;
    int i, j, k;
    string tmpBirthday = bday;
    
    tmpBirthday.erase(remove(tmpBirthday.begin(), tmpBirthday.end(), '-'), tmpBirthday.end()); //Removes dashes
    
    time_t now = time(0);
    tm *locTime = localtime(&now);
    
    pYear = 1900 + locTime->tm_year;
    pMonth = 1 + locTime->tm_mon;
    pDay = locTime->tm_mday;
    
    for (i = 0; i < 4; i++) {
        tmpBYear[i] = tmpBirthday[i];
    }
    
    j = 0;
    for (i = 4; i < 6; i++) {
        tmpBMonth[j] = tmpBirthday[i];
        j++;
    }
    
    k = 0;
    for (i = 6; i < 8; i++) {
        tmpBDayNum[k] = tmpBirthday[i];
        k++;
    }
    
    bYear = stoi(tmpBYear);
    bMonth = stoi(tmpBMonth);
    bDate = stoi(tmpBDayNum);
    
    age = findAge(pDay, pMonth, pYear, bDate, bMonth, bYear);
}

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

void student:: setSeniority(string sNum){
    char tmpNum[4];
    int yr;
    int i;
    
    for (i = 0; i < 4; i++) {
        tmpNum[i] = sNum[i];
    }
    
    yr = atoi(tmpNum);
    if (yr >= 2014 && yr <= 2017) {
        seniority = "4th Year";
    }else if (yr == 2018) seniority = "3rd Year";
    else if (yr == 2019) seniority = "2nd Year";
    else if (yr == 2020) seniority = "1st Year";
    else seniority = "Invalid";
}

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
    head = NULL;
    tail = NULL;
    elements = 0;
}

//Destructor
linkedList:: ~linkedList(){
    student *tmp = head;
    student *next;
    
    while (tmp != NULL) {
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    cout << "\nDeleted\n";
}

//Mutator


//Accessor
int linkedList:: getElementCount(int count){
    return count;
}

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
    
    tmp->updateData(snum, lastName, gName, mName, course, bday, gwa);
    
    if (head == NULL) {
        head = tail = tmp;
    }else{
        tmp->next = head;
        head = tmp;
        
        defaultSort();
    }
    elements++;
    cout << "Student Added! \n";
}

//Sort by student number
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
            minIntNum = stoi(minStringNum);
            
            //Converts the student number in 'r' from string to integer
            nextStringNum = r->getStudentNum();
            nextStringNum.erase(remove(nextStringNum.begin(), nextStringNum.end(), '-'), nextStringNum.end());
            nextIntNum = stoi(nextStringNum);
            
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

//Sort by Last Name
void linkedList:: sortLastName(){
    student *tmp = head; //Traveller from node to node
    student *r;
    student *min;
    int compare;
    string minString;
    string nextString;
    
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
}

void linkedList:: sortGwa(){
    float minGwa;
    float rGwa;
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
            minGwa = min->getGwa(); //Gets the gwa from the 'min' node
            rGwa = r->getGwa(); //Gets the gwa from the current 'r' node
            
            //If the GWA in 'r' is greater than the student number in 'min', 'r' will become 'min' since it is currently the minimum/smallest value.
            if (minGwa > rGwa) {
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

//Sort Menu
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
            break;
        case 3:
            sortGwa();
            cout << "\n[Temporarily Sorted by GWA]\n";
            print();
            break;
        default:
            cout << "Invalid input.\n"; //Prints message if user inputs a value other than 0 to 4
            break;
    }
}

//Utility Method for Printing
void linkedList:: print(){
    student *tmp = head;
    cout << endl << "The no. of elements on the list are: [" << elements << "].\n" << endl;
    
    while (tmp != NULL) {
        tmp->printData();
        cout << endl;
        tmp = tmp->next;
    }
}

