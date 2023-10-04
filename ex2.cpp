#include <iostream>
#include <iomanip>
using namespace std;

class Person {
protected:
    string name, address;
public:
    Person(string name, string address): name(name), address(address) {}
    string getName() {return name;}
    string getAddress() {return address;}
    void setAddress(string address) {this->address = address;}
    string toString() {return "Person[name=" + name + ",address=" + address + "]";}
};

class Student : public Person {
    string program;
    int year;
    double fee;
public:
    Student(string name, string address, string program, int year, double fee): Person(name, address), program(program), year(year), fee(fee) {}
    string getProgram() {return program;}
    void setProgram(string program) {this->program = program;}
    int getYear() {return year;}
    void setYear(int year) {this->year = year;}
    double getFee() {return fee;}
    void setFee(double fee) {this->fee = fee;}
    string toString() {return "Student[" + Person::toString() + ",program=" + program + ",year=" + to_string(year) + ",fee=" + to_string(fee) + "]";}
};

class Staff : public Person {
    string school;
    double pay;
public:
    Staff(string name, string address, string school, double pay): Person(name, address), school(school), pay(pay) {}
    string getSchool() {return school;}
    void setSchool(string school) {this->school = school;}
    double getPay() {return pay;}
    void setPay(double pay) {this->pay = pay;}
    string toString() {return "Staff[" + Person::toString() + ",school=" + school + ",pay=" + to_string(pay) + "]";}
};

class SchoolBusinessTest {
public:
    void main() {
        Student* stu_arr[5];
        for(int i = 0; i < 5; i++) {
            stu_arr[i] = new Student("stu_" + to_string(i+1), "addr_" + to_string(i+1), "CSE", 2023, 10.5);
            stu_arr[i]->setYear(2023);
        }
        for(int i = 0; i < 5; i++) {
            cout << stu_arr[i]->toString() << '\n';
        }

        Staff* newStaff = new Staff("abc","def","BKAV",10.4);
        newStaff->setAddress("new_addr");
        cout << newStaff->toString() << '\n';
    }
};

int main() {
    SchoolBusinessTest* newSchool = new SchoolBusinessTest();
    newSchool->main();

    return 0;
}
