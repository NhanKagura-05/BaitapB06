#include <iostream>
#include <string>
using namespace std;
class Student {
private:
 string name;
 int age;
 float gpa;
public:
 // Constructor
 Student(string n, int a, float g) : name(n), age(a), gpa(g) {}
 // Getter methods
 string getName() const { return name; }
 int getAge() const { return age; }
 float getGPA() const { return gpa; }
 // Setter methods
 void setName(string n) { name = n; }
 void setAge(int a) { age = a; }
 void setGPA(float g) { gpa = g; }
 // Method to display student information
 void displayInfo() const {
 cout << "Tên: " << name << endl;
 cout << "Tuổi: " << age << endl;
 cout << "GPA: " << gpa << endl;
 }
};
int main() {
 // Tạo một đối tượng Student
 Student s1("Nguyen Van A", 20, 3.5);
 // Hiển thị thông tin sinh viên
 cout << "Thông tin sinh viên:" << endl;
 s1.displayInfo();
 // Thay đổi GPA của sinh viên
 s1.setGPA(3.8);
 // Hiển thị thông tin sau khi cập nhật
 cout << "\nThông tin sau khi cập nhật GPA:" << endl;
 s1.displayInfo();
 return 0;
}