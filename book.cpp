#include <iostream>
#include <string>
using namespace std;

class book {
    private:
        string brand;
        int yearRelease;
        string name;
    public:
        book(string b, int y, string n){
            brand = b;
            yearRelease = y;
            name = n;
        }
};

class studyBook : public book {
    private:
        string discipline;
    public:
        studyBook(string b, int y, string n, string d) : book(b, y, n){
            discipline = d;
        }
        const string& getDiscipline() const {
            return discipline;
        }
        void setDiscipline(string d){
            discipline = d;
        }
};

class textBook : public studyBook {
    private:
        string school[10];
    public:
        textBook(string b, int y, string n, string d, string s[]) : studyBook(b, y, n, d){
            for(int i = 0; i < 10; i++) school[i] = s[i];
        }
};

class workBook : public studyBook {
    private:
        string rank;
    public:
        workBook(string b, int y, string n, string d, string r) : studyBook(b, y, n, d){
            rank = r;
        }
};

class fiction : public book{
    private:
        string author;
        int ageLimit;
};

class novel : public fiction {
    private:
        int numberChapter;
        string translator;  
};

class romanceNovel : public novel {
    private:
    public:
};

class detectiveNovel : public novel {
    private:
    public:
};

class manga : public fiction {
    private:
        string animatedAdaptation;
};

int main(){

    return 0;
}