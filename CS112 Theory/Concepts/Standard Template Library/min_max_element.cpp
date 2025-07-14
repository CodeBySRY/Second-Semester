#include <iostream>
#include <algorithm> // to use the minmax_element function();
#include <vector>
#include <iomanip>  // For setw()

/* The minmax_element() function: Return smallest and largest elements in range
Returns a pair with an iterator pointing to the element with the smallest value in the range [first,last) as first element, and the largest as second.
*/


using namespace std;

class Student {
    string name;
    int marks;

    public:
        string getName() const { return name; }
        int getMarks() const { return marks; }
        void AddStudent(vector <Student>& s);
        void SearchStudent(const vector<Student>&s);
        Student(string s, int m);
};

Student::Student(string s, int m) : name(s), marks(m) {}

void Student::AddStudent(vector<Student>& s1) {
    int myNum;
    cout << "Enter the number of students in the class: ";
    cin >> myNum;
    cin.ignore();
    for (int i = 0; i < myNum; i++) {
        string name;
        int marks;
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter the marks: ";
        cin >> marks;
        cin.ignore();
        Student newStu(name, marks);
        s1.push_back(newStu);
    }
}

void Student::SearchStudent(const vector<Student>&s1) {
    string search;
    cout << "Enter the name of the student to search: ";
    getline(cin, search);
    bool found = false;
    for (const Student& stu : s1) {
         if (stu.getName() == search) {
            cout << left << setw(15) << "Name Found:" << stu.getName() << endl
             << left << setw(15) << "Marks:" << stu.getMarks() << endl;
            found = true;
            break;
    }
}
if (found == false) {
    cout << "Student Not Found!" << endl;
}
}

void MinMaxMarks(vector<Student>&s1) {
    vector<int> stuMarks;
   for (const Student& s : s1) {
        int marks = s.getMarks();
        stuMarks.push_back(marks);

   } 
   
   auto output = minmax_element(stuMarks.begin(), stuMarks.end());
   cout << "The Maximum Marks = " << *output.second << endl;
   cout << "The Minimum Marks = " << *output.first << endl;

}

int main() {
    Student s(" ", 0);
    vector<Student> s1;
    s.AddStudent(s1);
    s.SearchStudent(s1);

    cout << endl;

    MinMaxMarks(s1);

    return 0;
}

