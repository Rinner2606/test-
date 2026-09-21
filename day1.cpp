#include <iostream>
#include <fstream>
using namespace std;

struct MON {
    char mamon[15];
    char tenmon[50];
    int sotc;
    float diem;
};

struct SV {
    char mssv[15];
    char hoten[50];
    int tuoi;
    int somon;
    MON dsmon[20];
    int tongtc;
    float dtb;
};
void docfile(const char filename[], SV &s) {
    ifstream f(filename);
    if (!f) {
        cout << "Khong mo duoc file\n";
        return;
    }

    f.getline(s.mssv, 15);
    f.getline(s.hoten, 50);
    f >> s.tuoi;
    f >> s.somon;
    f.ignore(1000, '\n');   

    if (s.somon <= 0 || s.somon > 20) {
        cout << "So mon khong hop le\n";
        return;
    }

    s.tongtc = 0;
    float tongdiem = 0;
    char dongSao[100];

    for (int i = 0; i < s.somon; i++) {
        f.getline(dongSao, 100);  

        f.getline(s.dsmon[i].mamon, 15);
        f.getline(s.dsmon[i].tenmon, 50);
        f >> s.dsmon[i].sotc;
        f >> s.dsmon[i].diem;
        f.ignore(1000, '\n');    

        s.tongtc += s.dsmon[i].sotc;
        tongdiem += s.dsmon[i].diem * s.dsmon[i].sotc;
    }

    if (s.tongtc > 0)
        s.dtb = tongdiem / s.tongtc;
    else
        s.dtb = 0;

    f.close();
}
void insv(SV s) {
    cout << "Ma SV: " << s.mssv << endl;
    cout << "Ho ten: " << s.hoten << endl;
    cout << "Tuoi: " << s.tuoi << endl;
    cout << "So mon: " << s.somon << endl;

    cout << "\nDanh sach mon hoc\n";
    for (int i = 0; i < s.somon; i++) {
        cout << s.dsmon[i].mamon << " | "
             << s.dsmon[i].tenmon << " | "
             << s.dsmon[i].sotc << " TC | "
             << s.dsmon[i].diem << endl;
    }

    cout << "Tong TC: " << s.tongtc << endl;
    cout << "DTB: " << s.dtb << endl;
}
int main() {
    SV s;
    docfile("SV.TXT", s);
    insv(s);
    system("pause");
    return 0;
}
