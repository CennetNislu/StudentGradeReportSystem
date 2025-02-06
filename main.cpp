//425507 - Cennet NISLU
//434399 - Kübra DERELİ

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

class Kurs {
private:
    string kursAdi;
    string kursSayisi;
    int krediSaati;
    char harfNotu;
public:
    Kurs(string kursAdi_ = " ", string kursSayisi_ = " ", int krediSaati_ = 0, char harfNotu_ = '*');
    void setCourse(string kursAdi_, string kursSayisi_, int krediSaati_, char harfNotu_);
    int getkrediSaati();
    char getharfNotu();
    string getkursSayisi();
    void print(bool isharfNotu);
    void print(ofstream& output, bool isharfNotu);
};

Kurs::Kurs(string kursAdi_, string kursSayisi_, int krediSaati_, char harfNotu_)
    : kursAdi(kursAdi_), kursSayisi(kursSayisi_), krediSaati(krediSaati_), harfNotu(harfNotu_) {}

void Kurs::setCourse(string kursAdi_, string kursSayisi_, int krediSaati_, char harfNotu_) {
    kursAdi = kursAdi_;
    kursSayisi = kursSayisi_;
    harfNotu = harfNotu_;
    krediSaati = krediSaati_;
}

int Kurs::getkrediSaati() {
    return krediSaati;
}

char Kurs::getharfNotu() {
    return harfNotu;
}

string Kurs::getkursSayisi() {
    return kursSayisi;
}

void Kurs::print(bool isharfNotu) {
    cout << left;
    cout << setw(11) << kursSayisi << " ";
    cout << setw(16) << kursAdi;
    cout << setw(9) << krediSaati << " ";
    if (isharfNotu)
        cout << setw(4) << harfNotu << endl;
    else
        cout << setw(4) << "*" << endl;
}

void Kurs::print(ofstream& output, bool isharfNotu) {
    output << left;
    output << setw(11) << kursSayisi << " ";
    output << setw(16) << kursAdi;
    output << setw(9) << krediSaati << " ";
    if (isharfNotu)
        output << setw(4) << harfNotu << endl;
    else
        output << setw(4) << "*" << endl;
}

class Kisi {
protected:
    string ad;
    string soyad;
public:
    void setName(string ad_, string soyad_) {
        ad = ad_;
        soyad = soyad_;
    }

    string getName() const {
        return ad + " " + soyad;
    }
};

class Ogrenci : public Kisi {
private:
    void kursSirala();
    int ogrenciNo;
    bool harcOdendiMi;
    int kursunSirasi;
    Kurs kayitliKurs[10];
public:
    Ogrenci();
    void setOgrenci(string ad_, string soyad_,
                    int ogrenciNo_, int kursunSirasi_,
                    bool harcOdendiMi_, Kurs courses[],char harfNotus[]);
    void print(float harcOrani);
    void print(ofstream& output, float harcOrani);
    int getHoursEnrolled();
    float getGpa();
    float harcMiktari(float harcOrani);
};


void Ogrenci::setOgrenci(string ad_, string soyad_,
                              int ogrenciNo_, int kursunSirasi_,
                              bool harcOdendiMi_, Kurs courses[],char harfNotus[]) {
    Kisi::setName(ad_, soyad_);
    ogrenciNo = ogrenciNo_;
    kursunSirasi = kursunSirasi_;
    harcOdendiMi = harcOdendiMi_;
    for (int i = 0; i < kursunSirasi; i++) {
        kayitliKurs[i] = courses[i];

    }
    kursSirala();
}

Ogrenci::Ogrenci() {
    ogrenciNo = 0;
    kursunSirasi = 0;
    harcOdendiMi = false;
}

void Ogrenci::print(float harcOrani) {
    cout << "Öğrenci İsmi: " << getName() << endl;
    cout << "Öğrenci NO: " << ogrenciNo << endl;
    cout << "Kayıtlı kurs sayısı: " << kursunSirasi << endl<<endl;
    cout<<left;
    cout<<"Kurs Sırası "<<setw(15)<<"Kurs İsmi"
    <<setw(10)<<"Kredisi"
    <<setw(8) <<"Harf Notu"<<endl;

    cout.unsetf(ios::left);

    for(int i = 0; i < kursunSirasi; i++)
        kayitliKurs [i].print(harcOdendiMi);
    cout<<endl;

    cout<<"Toplam kredi saati:  "<<getHoursEnrolled()<<endl;

    cout<<fixed<<showpoint<<setprecision(2);

    if (harcOdendiMi)
        cout<<"Yarıyıl GPA: "<<getGpa()<<endl;
    else
    {
        cout<<"*** Harf Notunuz, siz harcınızı ödeyene kadar beklemeye alınmıştır. ***"<<endl;
        cout<<"Harç Miktarınız: "<<harcMiktari (harcOrani) <<endl;
    }
    cout<<"-------------------------"<<endl;
}

void Ogrenci::print(ofstream& output, float harcOrani) {

    output << "Öğrenci İsmi: " << getName() << endl;
    output << "Öğrenci NO:" << ogrenciNo << endl;
    output << "Kayıtlı kurs sayısı: " << kursunSirasi<< endl;
    output << endl;

    output <<left;
    output<<"Kurs Sırası "<<setw(15)<<"Kurs İsmi"
    <<setw(8)<<"Kredisi"
    <<setw(6) <<"Harf Notu"<<endl<<endl;

    output.unsetf(ios::left);

    for (int i = 0; i < kursunSirasi; i++) {
        kayitliKurs[i].print(output, harcOdendiMi);
    }
    output<<endl;

    output << "Toplam kredi saati: "<<getHoursEnrolled()<<endl;
    output << fixed<<showpoint<<setprecision (2);


    if(harcOdendiMi)
    output<<"Yarıyıl GPA: "<<getGpa()<<endl;
    else
    {
        output<<"***  Harf Notunuz, siz harcınızı ödeyene kadar beklemeye alınmıştır.  ***"<<endl;
        output<<"Harç Miktarınız: "<<harcMiktari(harcOrani)<<endl;
    }
    output<<"-------------------------"<<endl<<endl;
}

int Ogrenci::getHoursEnrolled() {
    int totalCredits = 0;
    for (int i = 0; i < kursunSirasi; i++) {
        totalCredits += kayitliKurs[i].getkrediSaati();
    }
    return totalCredits;
}

float Ogrenci::getGpa() {
    float sum = 0.0;
    for(int i = 0; i < kursunSirasi; i++){
        switch(kayitliKurs[i].getharfNotu()){
            case 'A': sum += kayitliKurs[i].getkrediSaati() * 4; break;
            case 'B': sum += kayitliKurs[i].getkrediSaati() * 3; break;
            case 'C': sum += kayitliKurs[i].getkrediSaati() * 2; break;
            case 'D': sum += kayitliKurs[i].getkrediSaati() * 1; break;
            case 'F': sum += kayitliKurs[i].getkrediSaati() * 0; break;
            default: sum += kayitliKurs[i].getkrediSaati() * 0;
        }
    }
    return sum / getHoursEnrolled();
}

float Ogrenci::harcMiktari(float harcOrani) {
    return harcOrani*getHoursEnrolled();
}



void Ogrenci::kursSirala() {
    for (int i = 0; i < kursunSirasi - 1; i++) {
        for (int j = i + 1; j < kursunSirasi; j++) {
            if (kayitliKurs[i].getkursSayisi() > kayitliKurs[j].getkursSayisi()) {
                Kurs temp = kayitliKurs[i];
                kayitliKurs[i] = kayitliKurs[j];
                kayitliKurs[j] = temp;
            }
        }
    }
}

void getOgrenciData(ifstream& input, Ogrenci studentList[],int kayitliOgrenci) {
    string fName;
    string lName;
    int ID;
    int noOfCourses;
    char isPaid;
    bool harcOdendiMi;
    string cName;
    string cNo;
    int credits;
    Kurs courses[6];
    char cHarfNotu[6];
    for (int sayac = 0; sayac < kayitliOgrenci; sayac++) {
        input >> fName >> lName >> ID >> isPaid;
        if (isPaid == 'Y')
            harcOdendiMi = true;
        else
            harcOdendiMi = false;
        input>> noOfCourses;
        for(int i=0;i<noOfCourses;i++){
            input>>cName>>cNo>>credits>>cHarfNotu[i];
            courses[i].setCourse(cName,cNo,credits,cHarfNotu[i]);
        }

        studentList[sayac].setOgrenci(fName,lName,ID,noOfCourses,harcOdendiMi,courses,cHarfNotu);
    }
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    Ogrenci studentList[10];
    int kayitliOgrenci;
    float harcOrani;
    ifstream input;
    ofstream output;
    input.open("input.txt");
    if (!input){
        cout << "İnput.txt dosyası bulunamadı. Program kapatılıyor." << endl;
        return 1;
    }
    output.open("output.txt");
    input >> kayitliOgrenci;
    input >> harcOrani;

    getOgrenciData(input, studentList, kayitliOgrenci);

    for (int sayac = 0; sayac < kayitliOgrenci; sayac++) {
        studentList[sayac].print(harcOrani);
        studentList[sayac].print(output, harcOrani);
    }

    return 0;
}
