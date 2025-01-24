#include <iostream>
using namespace std;

struct score{
    string subName;
    float score;
};

class student{
    private:
        int studentCode;
        string fullName;
        int age;
        string hometown;
        float height;
        float weight;
        score subject[8];
    public:
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
            weight = tempHeight;
            string tempSub[] = {"Mathematics", "Physics", "Chemistry", "literature", "English", "History", "Biology", "Geography"};
            for(int i = 0; i < 8; i++){
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

int main() {
    student* Son = new student(1, "Tran Nguyen Xuan Son", 18, "Binh Dinh", 1.7, 47);
    Son->introduce();
    Son->subjectGrades();
    cout << Son->rank();
    return 0;
}