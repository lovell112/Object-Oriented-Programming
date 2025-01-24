#include <iostream>
using namespace std;

struct score{
    string subName;
    float score;
};

class student{
    private:
        string fullName;
        int age;
        string hometown;
        float height;
        float weight;
        score subject[8];
    public:
        int studentCode;
        student(){
            studentCode = 0;
            fullName = "Default";
            age = 0;
            hometown = "None";
            height = 0;
            weight = 0;
            string tempSub[] = {"Mathematics", "Physics", "Chemistry", "literature", "English", "History", "Biology", "Geography"};
            for(int i = 0; i < 8; i++){
                subject[i].subName = tempSub[i];
                subject[i].score = 0;
            }
        }
        student(int tempCode, string tempName, int tempAge, string tempHometown, float tempHeight, float tempWeight){
            studentCode = tempCode;
            fullName = tempName;
            age = tempAge;
            hometown = tempHometown;
            height = tempHeight;
            weight = tempWeight;
            string tempSub[] = {"Mathematics", "Physics", "Chemistry", "literature", "English", "History", "Biology", "Geography"};
            for(int i = 0; i < 8; i++){
                cout << "Scan subject " << tempSub[i] << " : ";
                cin >> subject[i].score;
                subject[i].subName = tempSub[i];
            }
        }
        void introduce(){
            cout << "Hello everyone\n";
            cout << "My name is " << fullName << endl;
            cout << "I'm " << age << " years old" << endl;
            cout << "I was born and raised in " << hometown << endl;
        }
        void subjectGrades(){
            for(int i = 0; i < 8; i++) cout << "Subject " << i+1 << ": " << subject[i].subName << " = " << subject[i].score << endl;
        }
        float GPA(){
            float total = 0;
            for(int i = 0; i < 8; i++) total += subject[i].score;
            total /= 8.0;
            return total;
        }
        string rank(){
            string ranks;
            if(GPA() >= 8) ranks = "GIOI";
            else if (GPA() < 8 && GPA() >= 6.5) ranks = "KHA";
            else if(GPA() < 6.5 && GPA() >= 5) ranks = "TRUNG BINH";
            else ranks = "YEU";
            return "Hoc luc : " + ranks;
        }
};

class grades{
    private:
        string classCode;
        student* members = new student[40];
        student* leader;
    public:
        static int numberOfClass;
        grades(string code){
            classCode = code;
            numberOfClass++;
        }
        ~grades(){
            delete[] members;
            numberOfClass--;
            leader = nullptr;
        }
        int numberOfStudent = 0;
        void addStudent(int code, string name, int age, string home, int height, int weight){
            cout << "==> Add student " << numberOfStudent + 1 << " in class " << classCode << " : " << endl;
            members[numberOfStudent++] = student(code, name, age, home, height, weight);
            cout << "============ ADD A NEW STUDENT FINISH =============" << endl;
        }
        void deleteStudent(int stuCode){
            bool flag = 1;
            for(int i = 0; i < numberOfStudent; i++){
                if(members[i].studentCode == stuCode){
                    flag = 0;
                    for(int j = i+1; j < numberOfStudent; j++){
                        members[j-1] = members[j];
                    }
                    numberOfStudent--;
                    cout << "============ DELETE FINISH ============" << endl;
                    return;
                }
            }
            if(flag) cout << "!### DELETE FAILD ###!" << endl;
        }
        void editInfo(int stuCode){
            bool flag = 1;
            for(int i = 0; i < numberOfStudent; i++){
                if(members[i].studentCode == stuCode){
                    flag = 0;
                    cout << "Will you edit student infomation ?" << endl;
                    cin.ignore();
                    string editName; cout << "Fullname => "; getline(cin, editName);
                    int editAge; cout << "Age => "; cin >> editAge;
                    cin.ignore();
                    string editHome; cout << "Hometown => "; getline(cin, editHome);
                    float editHeight; cout << "Height => "; cin >> editHeight;
                    float editWeight; cout << "Weight => "; cin >> editWeight;
                    members[i] = student(stuCode, editName, editAge, editHome, editHeight, editWeight);
                    cout << "============ EDIT FINISH ============" << endl;
                    return;
                }
            }
            if(flag) cout << "!### EDIT FAILD ###!" << endl;
        }
        void setupLeader(int stuCode){
            bool flag = 1;
            for(int i = 0; i < numberOfStudent; i++){
                if(members[i].studentCode == stuCode){
                    flag = 0;
                    leader = &members[i];
                    cout << "============ SETUP FINISH ============" << endl;
                    return;
                }
            }
            if(flag) cout << "!### SETUP FAILD ###!" << endl;
        }
};

int grades::numberOfClass = 0;

int main() {
    grades* first = new grades("12a3");
    first->addStudent(1, "Tran Nguyen Xuan Son", 18, "Binh Dinh", 1.7, 47);
    first->addStudent(2, "Tran Tan Sang", 16, "Binh Dinh", 1.6, 37);
    first->addStudent(3, "Nguyen Thi Minh Khai", 17, "Binh Dinh", 1.5, 27);
    first->deleteStudent(2);
    first->editInfo(3);
    first->setupLeader(1);
    grades* second = new grades("12a2");
    grades* third = new grades("12a1");
    grades* fourth = new grades("12a4");

    cout <<"THERE ARE " << grades::numberOfClass << " CLASS IN THIS SCHOOL";

    delete first;
    delete second;
    delete third;
    delete fourth;

    return 0;
}