#include <iostream>
#include <iomanip>
using namespace std;

struct dateTime{
    int day;
    int month;
    int year;
};

class patient{
    private:
        string patientCode;
        string fullName;
        dateTime dateOfAdmission;
        string deseaseCode;
        double hopitalFees;
        static int numberOfPatient;
    public:
        patient(string pCode, string name, int day, int month, int year, string dCode, double fees){
            patientCode = pCode;
            fullName = name;
            dateOfAdmission.day = day;
            dateOfAdmission.month = month;
            dateOfAdmission.year = year;
            deseaseCode = dCode;
            hopitalFees = fees;
            numberOfPatient++; 
        }

        void infomationOfPatient(){
            cout << "=======> " << "Patient code : " << getPatientCode() << endl;
            cout << "=======> " << "Full name of the patient : " << getFullName() << endl;
            cout << "=======> " << "Date of admission : " << getDOA().day << "/" << getDOA().month << "/" << getDOA().year << endl;
            cout << "=======> " << "Desease code : " << getDeseaseCode() << endl;
            cout << "=======> " << "Hopital fees of " << fixed << setprecision(0) << getFullName() << " : " << getHopitalFees() << endl;
            cout << endl;
        }

        void setPatientCode(string pCode){
            patientCode = pCode;
        }
        void setFullName(string name){
            fullName = name;
        }
        void setDOA(int day, int month, int year){
            dateOfAdmission.day = day;
            dateOfAdmission.month = month;
            dateOfAdmission.year = year;
        }
        void setDeseaseCode(string dCode){
            deseaseCode = dCode;
        }
        void setHopitalFees(double fees){
            hopitalFees = fees;
        }

        string getPatientCode(){
            return patientCode;
        }
        string getFullName(){
            return fullName;
        }
        dateTime getDOA(){
            return dateOfAdmission;
        }
        string getDeseaseCode(){
            return deseaseCode;
        }
        double getHopitalFees(){
            return hopitalFees;
        }
        static int getNumberOfPatient(){
            return numberOfPatient;
        }
};

int patient::numberOfPatient = 0;


int main(){
    patient* NVAn = new patient("1001", "Nguyen Van An", 15, 1, 2025, "B001", 1500000.0);
    patient* TTHoa = new patient("1002", "Tran Thi Hoa", 18, 1, 2025, "B002", 2300000.0);
    patient* LMQuan = new patient("1003", "Le Minh Quan", 20, 1, 2025, "B003", 1750000.0);
    patient* PNAnh = new patient("1004", "Pham Ngoc Anh", 22, 1, 2025, "B004", 2000000.0);
    patient* DTBinh = new patient("1005", "Do Thanh Binh", 25, 1, 2025, "B005", 1200000.0);

    // The first patient

    cout << "Patient infomation of " << NVAn->getFullName() << " before them was edited: " << endl;
    NVAn->infomationOfPatient();
    NVAn->setHopitalFees(10000000.0);
    cout << "Patient infomation of " << NVAn->getFullName() << " after them was edited: " << endl;
    NVAn->infomationOfPatient();
    cout << endl;

    // The second patient

    cout << "Patient infomation of " << TTHoa->getFullName() << " before them was edited: " << endl;
    TTHoa->infomationOfPatient();
    TTHoa->setDeseaseCode("B007");
    TTHoa->setHopitalFees(2000000.0);
    cout << "Patient infomation of " << TTHoa->getFullName() << " after them was edited: " << endl;
    TTHoa->infomationOfPatient();
    cout << endl;

    // The third patient

    cout << "Patient infomation of " << LMQuan->getFullName() << " before them was edited: " << endl;
    LMQuan->infomationOfPatient();
    LMQuan->setDOA(12, 1, 2025);
    cout << "Patient infomation of " << LMQuan->getFullName() << " after them was edited: " << endl;
    LMQuan->infomationOfPatient();
    cout << endl;

    // The fourth patient

    cout << "Patient infomation of " << PNAnh->getFullName() << " before them was edited: " << endl;
    PNAnh->infomationOfPatient();
    PNAnh->setPatientCode("1000");
    cout << "Patient infomation of " << PNAnh->getFullName() << " after them was edited: " << endl;
    PNAnh->infomationOfPatient();
    cout << endl;

    // The fifth patient

    cout << "Patient infomation of " << DTBinh->getFullName() << " before them was edited: " << endl;
    DTBinh->infomationOfPatient();
    DTBinh->setFullName("Dang Thanh Binh");
    cout << "Patient infomation of " << DTBinh->getFullName() << " after them was edited: " << endl;
    DTBinh->infomationOfPatient();
    cout << endl;

    cout << endl;
    cout << "========================================================" << endl;
    cout << "Number of patient is " << patient::getNumberOfPatient()  << " people, curently" << endl;
    cout << endl;
    cout << "============ END ============";

    delete NVAn;
    delete TTHoa;
    delete LMQuan;
    delete PNAnh;
    delete DTBinh;

    return 0;
}