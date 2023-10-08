#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int global_Id = 1;

class Person {
protected:
    string name, address;
    int Id;
public:
    Person(string name, string address, int Id): name(name), address(address), Id(Id) {global_Id++;}
    string getName() {return name;}
    string getAddress() {return address;}
    void setAddress(string address) {this->address = address;}
    int getId() {return Id;}
    void setId(int Id) {this->Id = Id;}
    string toString() {return "Person[name=" + name + ",address=" + address + ",Id=" + to_string(Id) + "]";}
};

class Student : public Person {
    string program;
    int year;
    double fee;
public:
    Student(string name, string address, int Id, string program, int year, double fee): Person(name, address, Id), program(program), year(year), fee(fee) {}
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
    Staff(string name, string address, int Id, string school, double pay): Person(name, address, Id), school(school), pay(pay) {}
    string getSchool() {return school;}
    void setSchool(string school) {this->school = school;}
    double getPay() {return pay;}
    void setPay(double pay) {this->pay = pay;}
    string toString() {return "Staff[" + Person::toString() + ",school=" + school + ",pay=" + to_string(pay) + "]";}
};

class Course {
    string courseID, courseName, courseDescription;
    int noCredit;
    vector<Student> studentList;
    vector<Staff> staffList;
public:
    Course(string courseID, string courseName, string courseDescription, int noCredit): courseID(courseID), courseName(courseName), courseDescription(courseDescription), noCredit(noCredit) {}
    void addStudent(Student student_id) {studentList.push_back(student_id);}
    void removeStudent(Student student_id) {
        for(int i = 0; i < studentList.size(); i++)
            if(studentList[i].getId() == student_id.getId())
                for(; i < studentList.size()-1; i++)
                    studentList[i] = studentList[i+1];
    }
    void addStaff(Staff staff_id) {staffList.push_back(staff_id);}
    void removeStaff(Staff staff_id) {
        for(int i = 0; i < studentList.size(); i++)
            if(staffList[i].getId() == staff_id.getId())
                for(; i < staffList.size()-1; i++)
                    staffList[i] = staffList[i+1];
    }
    string studentList_toString() {
        int i;
        string s = "studentList=[";
        for(i = 0; i < studentList.size()-1; i++)
            s += studentList[i].toString() + ",";
        s += studentList[i].toString() + "]";
        return s;
    }
    string staffList_toString() {
        int i;
        string s = "staffList=[";
        for(i = 0; i < staffList.size()-1; i++)
            s += staffList[i].toString() + ",";
        s += staffList[i].toString() + "]";
        return s;
    }
    string toString() {return "Course[courseID=" + courseID + ",courseName=" + courseName + ",courseDescription=" + courseDescription + ",noCredit=" + to_string(noCredit) + "," + studentList_toString() + "," + staffList_toString() + "]";}
};

class SchoolBusinessTest {
public:
    void main() {
        Student* stu_arr[5];
        for(int i = 0; i < 5; i++) {
            stu_arr[i] = new Student("stu_" + to_string(i+1), "addr_" + to_string(i+1), global_Id, "CSE", 2023, 10.5);
            stu_arr[i]->setYear(2023);
        }
        for(int i = 0; i < 5; i++) {
            cout << stu_arr[i]->toString() << '\n';
        }

        Staff* newStaff = new Staff("abc","def", global_Id,"BKAV",10.4);
        newStaff->setAddress("new_addr");
        cout << newStaff->toString() << '\n';
    }
};

int main() {
    SchoolBusinessTest* newSchool = new SchoolBusinessTest();
    newSchool->main();

    return 0;
}