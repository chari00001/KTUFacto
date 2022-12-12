#include <iostream>
#include <string>
#include <time.h>
// #include <conio.h> // for Windows
#include <curses.h> // For Linux
#include <regex>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;

class Konumlar
{
private:
    string varisYeri;
    int dakika;
};

class SinglyNode
{
public:
    string elem;
    SinglyNode *next;

    void printNode() { cout << elem << endl; }
};

class SinglyLinkedList
{
public:
    SinglyNode *head;

    SinglyLinkedList();

    bool empty() const;
    void addBack(const string &e);
    int print();
    string getElement(int);
    void removeOrdered(const string &e);
};

class Hatalar
{
public:
    void sifreUzunluguUyari() { cout << "Sifre 8 Karakterden Az 24 Karakterden Fazla Olamaz!!" << endl; }
    void buyukHarfUyari() { cout << "Kullanici Adi Buyuk Harf Iceremez!!!" << endl; }
    void gucluSifreUyari() { cout << "Lutfen Daha Guclu Bir Sifre Giriniz!!!" << endl; }
    void kullaniciTurkceKarakterUyari() { cout << "Kullanici Adi Turkce Karakter veya Bosluk Iceremez!!" << endl; }
    void sifreturkceKarakterUyari() { cout << "Sifre Turkce Karakter veya Bosluk Iceremez!!!" << endl; }
    void k_adiUzunluguUyari() { cout << "Kullanici Adi 8 Karakterden Az 24 Karakterden Fazla Olamaz" << endl; }
};

class Zaman
{
private:
    int saat;
    int dakika;

public:
    void setSaat(int Saat) { this->saat = Saat; }
    void setDakika(int Dakika) { this->dakika = Dakika; }
    int getDakika() { return dakika; }
    int getSaat() { return saat; }
    string getCurrentDate();
    string getCurrentTime();
    Zaman operator+(Zaman &obj);
    void printZaman();
    void printUniversal();
};

class Kisi
{
private:
    string adSoyad;
    string telNo;

public:
    void setAdSoyad(string adSoyad) { this->adSoyad = adSoyad; }
    void setTelNo(string telNo) { this->telNo = telNo; }
    string getAdSoyad() { return adSoyad; }
    string getTelNo() { return telNo; }
};

class Kullanici : public Kisi
{
private:
    string kullaniciAdi;
    string ePosta;
    string adres;
    string sifre; // sorun sifre nasil store edilir bakin!!!!!!! openssl kutuphanesine bakilsin
    string indirimKodu;
    string dTarihi;

public:
    Kullanici(string KullaniciAdi = "") { setKullaniciAdi(KullaniciAdi); }

    void setKullaniciAdi(string kullaniciAdi) { this->kullaniciAdi = kullaniciAdi; }
    void setEposta(string ePosta) { this->ePosta = ePosta; }
    void setAdres(string adres) { this->adres = adres; }
    void setSifre(string sifre) { this->sifre = sifre; }
    void setIndirimKodu(string indirimKodu) { this->indirimKodu = indirimKodu; }
    void setDTarihi(string dTarihi) { this->dTarihi = dTarihi; }

    string getKullaniciAdi() { return kullaniciAdi; }
    string getEposta() { return ePosta; }
    string getAdres() { return adres; }
    string getSifre() { return sifre; }
    string getIndirimKodu() { return indirimKodu; }
    string getDTarihi() { return dTarihi; }

    void SikayetYaz();
    void SifreDegistir();
    void kaydet();
    bool sifreKontrol(string sifre);
    bool kullaniciAdiKontrol(string kullanici_adi);
    bool ePostaKontrol(string ePosta);

    string sifrele(char *bilgi, bool gizle = true);
};

class Yonetici : public Kisi
{
private:
    string sifre;

public:
    Yonetici(string Sifre = "") { sifre = Sifre; } // Default kullanma
    void set_sifre(char *) { this->sifre = sifre; }

    void UrunEkle();
    void KuryeEkle();
    void SikayetOku();
    void IndirimKoduEkle();
    void FaturaOku();
};

class Kiyafet
{
private:
    double fiyat;
    string kategori;
    string kiyafet_adi;
    string boyut;
    string renk;

public:
    void set_fiyat(double fiyat) { this->fiyat = fiyat; }
    void set_kategori(string kategori) { this->kategori = kategori; }
    void set_kiyafet_adi(string kiyafet_adi) { this->kiyafet_adi = kiyafet_adi; }
    void set_boyut(string boyut) { this->boyut = boyut; }
    void set_renk(string renk) { this->renk = renk; }

    double get_fiyat() { return fiyat; }
    string get_kategori() { return kategori; }
    string get_kiyafet_adi() { return kiyafet_adi; }
    string get_boyut() { return boyut; }
    string get_renk() { return renk; }
};

class Siparis : public Kiyafet
{
public:
    Siparis(string kullaniciAdi = " ",
            string siparisAdresi = " ",
            string urunBilgisi = " ",
            string siparisNo = "0000000",
            double siparis_fiyat = 0,
            string siparis_baslangic = "00:00",
            string siparis_ulasim = "00:00")
    {
        this->kullanici_adi = kullaniciAdi;
        this->siparis_adresi = siparisAdresi;
        this->urun_bilgisi = urunBilgisi;
        this->siparis_no = siparisNo;
        this->siparis_fiyat = siparis_fiyat;
        this->siparis_baslangic = siparis_baslangic;
        this->siparis_ulasim = siparis_ulasim;
    }

    void set_kullanici_adi(string kullanici_adi) { this->kullanici_adi = kullanici_adi; }
    void set_siparis_adresi(string siparis_adresi) { this->siparis_adresi = siparis_adresi; }
    void set_urun_bilgisi(string urun_bilgisi) { this->urun_bilgisi = urun_bilgisi; }
    void set_siparis_no(string siparis_no) { this->siparis_no = siparis_no; }
    void set_siparis_fiyat(double siparis_fiyat) { this->siparis_fiyat = siparis_fiyat; }
    void set_siparis_baslangic(string siparis_baslangic) { this->siparis_baslangic = siparis_baslangic; }
    void set_siparis_ulasim(string siparis_ulasim) { this->siparis_ulasim = siparis_ulasim; }

    string get_kullanici_adi() { return kullanici_adi; }
    string get_siparis_adresi() { return siparis_adresi; }
    string get_urun_bilgisi() { return urun_bilgisi; }
    string get_siparis_no() { return siparis_no; }
    double get_siparis_fiyat() { return siparis_fiyat; }
    string get_siparis_baslangic() { return siparis_baslangic; }
    string get_siparis_ulasim() { return siparis_ulasim; }

private:
    string kullanici_adi;
    string siparis_adresi;
    string urun_bilgisi;
    string siparis_no;
    double siparis_fiyat;
    string siparis_baslangic;
    string siparis_ulasim;
};

class Kurye : public Kisi
{
private:
    Zaman dagitim_bitis; // TIME
    int siparis_no;

public:
    void set_dagitim_bitis(Zaman dagitim_bitis) { this->dagitim_bitis = dagitim_bitis; }
    void set_siparis_no(int siparis_no) { this->siparis_no = siparis_no; }

    Zaman get_dagitim_bitis() { return dagitim_bitis; }
    int get_siparis_no() { return siparis_no; }

    string VarisZamaniHesapla(Siparis s);
    Zaman VarisZamani(Siparis s);
    void KuryeAta(string varisZamani);
};

class Menu
{
public:
    void MenuBaslat();
    void YoneticiGiris();
    void MusteriGiris();
    SinglyLinkedList KategorileriListele();
    void UrunleriListele(string Selection, Kullanici k);
    void UrunSec(SinglyLinkedList &urunler, int urunIndex, Kullanici k);
};

// FUNCTION DEFINITIONS

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
}

string SinglyLinkedList::getElement(int chosenIndex)
{
    SinglyNode *current = head;
    if (empty())
    {
        cout << "List is empty !" << endl;
        return "";
    }
    int count = 1;
    while (current != NULL)
    {
        if (count == chosenIndex)
        {
            return current->elem;
        }
        count++;
        current = current->next;
    }
}

bool SinglyLinkedList::empty() const
{
    return head == NULL;
}

void SinglyLinkedList::addBack(const string &e)
{
    SinglyNode *v = new SinglyNode;
    for (SinglyNode *i = head; i != NULL; i = i->next)
    {
        if (i->elem == e)
        {
            return;
        }
        v->elem = e;
        v->next = NULL;
    }

    // if (head == NULL) // ilk elemani alirken sikinti olur gibi?
    //     head = v;
    //     v->next = NULL;
    // else // buralara bakin
    // {
    //     SinglyNode *first = head;
    //     while (first->next != NULL)
    //         first = first->next;
    //     first->next = v;
    // }

    v->elem = e;
    v->next = NULL;

    if (head == NULL)
        head = v;
    else
    {
        SinglyNode *first = head;
        while (first->next != NULL)
            first = first->next;
        first->next = v;
    }
}

void SinglyLinkedList::removeOrdered(const string &e)
{
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    if ((e.compare(head->elem) == 0))
    {
        SinglyNode *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    SinglyNode *previous = head;
    while (previous->next != NULL)
    {
        if ((e.compare(previous->next->elem) == 0))
        {
            SinglyNode *temp = previous->next;
            previous->next = previous->next->next;
            delete temp;
            return;
        }

        previous = previous->next;
    }

    if (previous->next == NULL)
        cout << "\n"
             << e << " is not found" << endl;
}

int SinglyLinkedList::print()
{
    int count = 0;
    if (empty())
    {
        cout << "List is empty !" << endl;
        return 0;
    }

    SinglyNode *first = head;
    while (first != NULL)
    {
        cout << first->elem << endl;
        first = first->next;
        count++;
    }

    return count - 1;
}

// string Kullanici::sifrele(char *bilgi, bool gizle = true)
// {
//     const char BACKSPACE = 8;
//     const char RETURN = 13;

//     string sifre;
//     char harf = 0;

//     cout << bilgi << " ";

//     while ((harf = _getch()) != RETURN)
//     {
//         if (harf == BACKSPACE)
//         {
//             if (sifre.length() != 0)
//             {
//                 if (gizle)
//                     cout << "\b \b";
//                 sifre.resize(sifre.length() - 1);
//             }
//         }
//         else if (harf == 0 || harf == 224) // handle escape sequences
//         {
//             _getch(); // ignore non printable chars
//             continue;
//         }
//         else
//         {
//             sifre += harf;
//             if (gizle)
//                 cout << '*';
//         }
//     }
//     cout << endl;
//     return sifre;
// }

void Kullanici::SikayetYaz()
{
    string sikayet;

    cout << "Sikayet veya Onerinizi yaziniz: " << endl;
    getline(cin >> ws, sikayet);

    ofstream SikayetFile("./sikayetler.txt", ios::app);

    if (SikayetFile.is_open())
    {
        SikayetFile << getKullaniciAdi() << " - " << sikayet << endl;
    }
}

void Kullanici::SifreDegistir()
{
    vector<string> list;

    string yeniSifre;
    // yeniSifre = sifrele("Yeni Sifrenizi Giriniz:", true);

    cout << "Yeni Sifrenizi Giriniz: ";
    cin >> yeniSifre;

    ifstream KullaniciFile("./kullanicilar.txt");

    if (KullaniciFile.is_open())
    {
        string line;
        while (getline(KullaniciFile, line))
        {
            string usernameFromFile = line.substr(0, line.find("-"));
            if (usernameFromFile.compare(getKullaniciAdi()) == 0)
            {
                string temp = getKullaniciAdi() + "-" + yeniSifre + "-" + getEposta() + "-" + getAdres() + "-" + getDTarihi() + "-" + getIndirimKodu() + "-" + getAdSoyad() + "-" + getTelNo();

                list.push_back(temp);
            }
            else
            {
                list.push_back(line);
            }
        }
    }
    KullaniciFile.close();

    fstream s("./kullanicilar.txt", ofstream::out | ofstream::trunc);

    for (int i = 0; i < list.size(); i++)
    {
        s << list[i] << endl;
    }

    s.close();

    cout << "Sifreniz Basariyla Degistirildi" << endl;
    setSifre(yeniSifre);
}

void Kullanici::kaydet()
{
    fstream kullanicilar("./kullanicilar.txt", ios::app);

    string adSoyad;
    string telNo;
    string kullaniciAdi;
    string sifre;
    string ePosta;
    string adres;
    string indirimKodu;
    string dTarihi;

KONTROL:
    if (kullanicilar.is_open())
    {
        cout << "Ad Soyad: ";
        getline(cin >> ws, adSoyad);

        cout << "Telefon No: ";
        getline(cin >> ws, telNo);

        cout << "Kullanici Adi: ";
        getline(cin >> ws, kullaniciAdi);

        // sifre = sifrele("Sifrenizi Giriniz", true);
        cout << "Sifre giriniz: " << endl;
        cin >> sifre;

        cout << "\nEpostanizi Giriniz: ";
        getline(cin >> ws, ePosta);

        cout << "\nIlcenizi giriniz: ";
        getline(cin >> ws, adres);

        cout << "\nIndirim kodu: ";
        getline(cin >> ws, indirimKodu);

        cout << "\nDogum tarihini giriniz: ";
        getline(cin >> ws, dTarihi);

        if (kullaniciAdiKontrol(kullaniciAdi))
        {
            setKullaniciAdi(kullaniciAdi);
        }
        else
        {
            cout << "Kullanıcı adı geçersiz.\n";
            goto KONTROL;
        }

        if (sifreKontrol(sifre))
        {
            setSifre(sifre);
        }
        else
        {
            cout << "Şifre geçersiz.\n";
            goto KONTROL;
        }

        if (ePostaKontrol(ePosta))
        {
            setEposta(ePosta);
        }
        else
        {
            cout << "Eposta geçersiz.\n";
            goto KONTROL;
        }

        setAdSoyad(adSoyad);
        setTelNo(telNo);
        setDTarihi(dTarihi);
        setAdres(adres);
        setIndirimKodu(indirimKodu);

        kullanicilar << getKullaniciAdi() << "-"
                     << getSifre() << "-"
                     << getEposta() << "-"
                     << getAdres() << "-"
                     << getDTarihi() << "-"
                     << getIndirimKodu() << "-"
                     << getAdSoyad() << "-"
                     << getTelNo() << endl;

        kullanicilar.close();

        cout << "Kayit Basarili" << endl;
    }
    else
    {
        cout << "Böyle Bir Dosya Yok..." << endl;
    }
}

bool Kullanici::sifreKontrol(string sifre)
{
    Hatalar hata;
    bool buyuk_harf = false;
    bool kucuk_harf = false;
    bool sayi = false;
    bool ozel_karakter = false;
    int sayac = 0;

    regex buyuk_harf_exp{"[A-Z]+"};
    regex kucuk_harf_exp{"[a-z]+"};
    regex sayi_exp{"[0-9]+"};
    regex ozel_karakter_exp{"[@!?]+"};

    bool kontrol = false;

    /*for (int i = 0; i < sifre.length(); i++) {
        if (sifre[i] == 32 || (sifre[i] >= 128 && sifre[i] <= 255)) {
            hata.sifreturkceKarakterUyari();
            return false;
        }
    }*/

    do
    {
        if (sifre.length() < 8)
        {

            return false;
        }
        else
        {
            buyuk_harf = regex_search(sifre, buyuk_harf_exp);
            kucuk_harf = regex_search(sifre, kucuk_harf_exp);
            sayi = regex_search(sifre, sayi_exp);
            ozel_karakter = regex_search(sifre, ozel_karakter_exp);

            sayac = buyuk_harf + kucuk_harf + sayi + ozel_karakter;

            if (sayac < 4)
            {

                return false;
            }

            else
            {

                kontrol = true;

                return true;
            }
        }
    } while (!kontrol);
}

bool Kullanici::kullaniciAdiKontrol(string kullanici_adi)
{ //!!!!!!!!!!!!!!!  DUZELTILECEK KISIM  !!!!!!!!!!!!!!!//
    Hatalar hata;
    regex kullanici_ad_exp{"^[a-z_0-9]+$"};

    if (kullanici_adi.length() < 8)
    {

        return false;
    }

    if (regex_search(kullanici_adi, kullanici_ad_exp))
    {
        return true;
    }
    else
    {

        return false;
    }

    for (int i = 0; i < kullanici_adi.length(); i++)
    {
        if (kullanici_adi[i] > 'A' && kullanici_adi[i] < 'Z')
        {

            return false;
        }
    }
    return true;
}

bool Kullanici::ePostaKontrol(string ePosta)
{
    regex eMailexp{"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"};

    return regex_search(ePosta, eMailexp);
}

void Yonetici::UrunEkle()
{
    ofstream UrunlerFile("./urunler.txt", ios::app);

    string cat, name, price, size, color;
    cout << "Urunun Kategorisini giriniz: " << endl;
    cin >> cat;
    cout << "Urunun Ismini giriniz: " << endl;
    cin >> name;
    cout << "Urunun Fiyatini giriniz: " << endl;
    cin >> price;
    cout << "Urunun Boyutunu giriniz: " << endl;
    cin >> size;
    cout << "Urunun Rengini giriniz: " << endl;
    cin >> color;

    if (UrunlerFile.is_open())
    {
        UrunlerFile << cat << "-" << name << "-" << price << "-" << size << "-" << color << endl;
    }
    else
    {
        cout << "Boyle bir dosya yok." << endl;
    }
    UrunlerFile.close();
}

void Yonetici::KuryeEkle()
{
    ofstream KuryelerFile("./kuryeler.txt", ios::app);

    string adSoyad;
    string telNo;

    cout << "Kurye'nin adi soyadi: " << endl;
    getline(cin >> ws, adSoyad);

    cout << "Kurye'nin telefon numarasi: " << endl;
    cin >> telNo;

    KuryelerFile << adSoyad << "-" << telNo << endl;

    KuryelerFile.close();
}

void Yonetici::SikayetOku()
{
    ifstream sikayetFile("./sikayetler.txt");
    string line;
    if (sikayetFile.is_open())
    {
        while (getline(sikayetFile, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Boyle bir dosya yok." << endl;
    }
    sikayetFile.close();
}
void Yonetici::IndirimKoduEkle()
{
    ofstream IndirimlerFile("./indirimler.txt", ios::app);
    string kod;
    int indirim;

    cout << "Indirim kodunu giriniz: " << endl;
    cin >> kod;

    cout << "Indirim miktarini giriniz: " << endl;
    cin >> indirim;

    if (IndirimlerFile.is_open())
    {
        IndirimlerFile << kod << " " << indirim << endl;
    }
    else
    {
        cout << "Boyle bir dosya bulunamadi." << endl;
    }
    IndirimlerFile.close();
}
void Yonetici::FaturaOku()
{
    ifstream FaturalarFile("./faturalar.txt");
    string line;
    string delimiter = "-";

    int index = 1;
    while (getline(FaturalarFile, line))
    {
        string AdSoyadFromFile = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + 1);
        string UrunFromFile = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + 1);
        string SiparisFiyatFromFile = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + 1);
        string AdetFromFile = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + 1);
        string SiparisZamaniFromFile = line.substr(0, line.find(delimiter));

        cout << "\nFatura - " << index << endl;
        cout << "\nAd Soyad: " << AdSoyadFromFile
             << "\nUrun: " << UrunFromFile
             << "\nSiparis Fiyati: " << SiparisFiyatFromFile
             << "\nAdet: " << AdetFromFile
             << "\nSiparis Saati: " << SiparisZamaniFromFile << endl;
        index++;
    }
}

void Menu::MenuBaslat()
{
    int opsiyon1, opsiyon2;
    cout << "1 - Sisteme giris\n2 - Uye kaydi\n3 - Cikis"
         << endl;
    cin >> opsiyon1;
    system("clear"); // system("cls") - windows

    switch (opsiyon1)
    {
    case 1:
    {
        cout << "1 - Yonetici Girisi\n2 - Musteri Girisi\n"
             << endl;
        cin >> opsiyon2;
        system("clear");

        switch (opsiyon2)
        {
        case 1:
        {
            YoneticiGiris();
            break;
        }
        case 2:
        {
            MusteriGiris();
            break;
        }
        default:
            cout << "Yanlis Secim." << endl;
            break;
        }
        break;
    }
    case 2:
    {
        Kullanici user;
        user.kaydet();
        system("clear");
        return MenuBaslat();
        break;
    }
    case 3:
    {
        cout << "İyi günler dileriz...";
        exit;
    }
    default:
        break;
    }
}

void Menu::YoneticiGiris()
{
    Yonetici y;

    string sifre, girilenSifre;
    ifstream AdminFile("./yonetici.txt", ios::out);
    AdminFile >> sifre;
    AdminFile.close();

YONETICI_MENU:
    cout << "Admin sifrenizi giriniz:" << endl;
    cin >> girilenSifre;
    system("clear");
    if (sifre == girilenSifre)
    {
        cout << "1 - Urun ekle\n2 - Kurye ekle\n3 - Sikayet ve Oneriler\n4 - Indirim kodu tanimla\n5 - Siparis Faturalari" << endl;
        int AdminOpsiyon;
        cin >> AdminOpsiyon;

        switch (AdminOpsiyon)
        {
        case 1:
        {
            system("clear");
            y.UrunEkle();
            break;
        }
        case 2:
        {
            system("clear");
            y.KuryeEkle();
            break;
        }
        case 3:
        {
            system("clear");
            y.SikayetOku();
            break;
        }
        case 4:
        {
            system("clear");
            y.IndirimKoduEkle();
            break;
        }
        case 5:
        {
            system("clear");
            y.FaturaOku();
            break;
        }
        default:
        {
            system("clear");
            cout << "Hatali giris" << endl;
            goto YONETICI_MENU;
            break;
        }
        }
    }
    else
    {
        cout << "Yanlış şifre.";
    }
}

void Menu::MusteriGiris()
{
KULLANICI_GIRIS:
    ifstream KullanicilarFile("./kullanicilar.txt");
    Kullanici k;

    string username, password, line;

    cout << "Kullanici adi: ";
    cin >> username;
    cout << "Sifrenizi giriniz: " << endl;
    cin >> password;
    // password = k.sifrele("Sifre:", true);

    if (KullanicilarFile.is_open())
    {
        while (getline(KullanicilarFile, line))
        {
            string delimiter = "-";

            string usernameFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string passwordFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string emailFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string addressFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string birthdayFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string codeFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string nameSurnameFromFile = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            string phoneFromFile = line.substr(0, line.find(delimiter));

            if (usernameFromFile == username && passwordFromFile == password)
            {
                k.setKullaniciAdi(username);
                k.setSifre(password);
                k.setEposta(emailFromFile);
                k.setAdres(addressFromFile);
                k.setDTarihi(birthdayFromFile);
                k.setIndirimKodu(codeFromFile);
                k.setAdSoyad(nameSurnameFromFile);
                k.setTelNo(phoneFromFile);

                cout << "Giris basarili" << endl;
                goto MUSTERI_MENU;
            }
            else
            {
                system("clear");
            }
        }

        KullanicilarFile.close();

        cout << "Kullanici bulunamadi." << endl;
        goto KULLANICI_GIRIS;
    }
    else
    {
        // cout << "Dosya acilamadi" << endl;
    }

MUSTERI_MENU:
    system("clear");
    cout << "1 - Kiyafet kategorileri ve Urun secimi\n"
         << "2 - Siparis takip\n"
         << "3 - Sikayet ve Oneriler\n"
         << "4 - Sifre Degistir\n"
         << "5 - Geri don\n"
         << endl;
    int MusteriOpsiyon;
    cin >> MusteriOpsiyon;

    switch (MusteriOpsiyon)
    {
    case 1:
    {
        system("clear");
        SinglyLinkedList categories = KategorileriListele();
        int categoryCount = categories.print();

        string categorySelection;
        cout << "Kategori seciniz (Tum kategoriler icin 0 yaziniz): " << endl;
        getline(cin >> ws, categorySelection);

        system("clear");
        UrunleriListele(categorySelection, k);
        break;
    }
    case 2:
    {
        system("clear");
        cout << "Siparis takip";
        break;
    }
    case 3:
    {
        system("clear");
        k.SikayetYaz();
        break;
    }
    case 4:
    {
        system("clear");
        k.SifreDegistir();
        break;
    }
    case 5:
    {
        system("clear");
        // Geri don
        MenuBaslat();
        break;
    }
    default:
    {
        system("clear");
        cout << "Hatali giris" << endl;
        goto MUSTERI_MENU;
        break;
    }
    }
}

SinglyLinkedList Menu::KategorileriListele()
{
    ifstream UrunlerFile("./urunler.txt");

    string line;
    SinglyLinkedList *Kategoriler = new SinglyLinkedList();

    if (UrunlerFile.is_open())
    {
        while (getline(UrunlerFile, line))
        {
            string Kategori = line.substr(0, line.find("-"));
            Kategoriler->addBack(Kategori);
        }
    }

    UrunlerFile.close();

    return *Kategoriler;
}

void Menu::UrunleriListele(string Selection, Kullanici k)
{
    ifstream UrunlerFile("./urunler.txt");
    string line;

    SinglyLinkedList *Urunler = new SinglyLinkedList();

    if (UrunlerFile.is_open())
    {
        int index = 1;
        if (Selection == "0")
        {
            while (getline(UrunlerFile, line))
            {
                cout << index << " - " << line << endl;
                Urunler->addBack(line);
                index++;
            }
        }
        else
        {

            while (getline(UrunlerFile, line))
            {
                string categoryFromLine = line.substr(0, line.find("-"));
                if (Selection == categoryFromLine)
                {
                    cout << index << " - " << line << endl;
                    Urunler->addBack(line);
                    index++;
                }
            }
        }
        int secilenUrunIndex;

    URUN_SEC:
        cout << "Urun seciniz :" << endl;
        cin >> secilenUrunIndex;

        if (secilenUrunIndex > 0 && secilenUrunIndex <= index)
        {
            system("clear");
            UrunSec(*Urunler, secilenUrunIndex, k);
        }
        else
        {
            cout << "Gecersiz urun secimi...";
            goto URUN_SEC;
        }
    }
    else
    {
        cout << "Boyle bir dosya bulunamadi..." << endl;
    }
}

Zaman Kurye::VarisZamani(Siparis s)
{
    ifstream KonumlarFile("./konumlar.txt");

    Zaman varisZamani;

    cout << "Siparis zamani: " << s.get_siparis_baslangic() << endl;
    cout << "Siparis adresi: " << s.get_siparis_adresi() << endl;

    string Konum, sure;
    if (KonumlarFile.is_open())
    {
        while (getline(KonumlarFile, Konum))
        {
            if (Konum.substr(0, Konum.find("-")) == s.get_siparis_adresi())
            {
                Konum.erase(0, Konum.find("-") + 1);
                sure = Konum.substr(0, Konum.find("-"));
            }
        }
    }

    int sureInt;
    istringstream(sure) >> sureInt;

    string siparisBaslangic = s.get_siparis_baslangic();

    string siparisSaati = siparisBaslangic.substr(0, siparisBaslangic.find(":"));
    siparisBaslangic.erase(0, siparisBaslangic.find(":") + 1);
    string siparisDakikasi = siparisBaslangic.substr(0, siparisBaslangic.find("-"));

    int siparisSaatiInt, siparisDakikasiInt;
    istringstream(siparisSaati) >> siparisSaatiInt;
    istringstream(siparisDakikasi) >> siparisDakikasiInt;

    Zaman siparisZamani;
    siparisZamani.setSaat(siparisSaatiInt);
    siparisZamani.setDakika(siparisDakikasiInt);

    Zaman siparisSuresi;
    siparisSuresi.setSaat(sureInt / 60);
    siparisSuresi.setDakika(sureInt % 60);

    cout << "Siparis zamani: " << siparisZamani.getSaat() << ":" << siparisZamani.getDakika() << endl;
    cout << "Siparis sure: " << siparisSuresi.getSaat() << ":" << siparisSuresi.getDakika() << endl;

    varisZamani = siparisZamani + siparisSuresi;

    return varisZamani;
}

string Kurye::VarisZamaniHesapla(Siparis s)
{
    Zaman varisZamani = VarisZamani(s);

    string varisZamaniString;
    stringstream ss;

    string varisZamaniSaat = to_string(varisZamani.getSaat());
    string varisZamaniDakika = to_string(varisZamani.getDakika());

    if (varisZamaniSaat.length() == 1)
    {
        varisZamaniSaat = "0" + varisZamaniSaat;
    }
    if (varisZamaniDakika.length() == 1)
    {
        varisZamaniDakika = "0" + varisZamaniDakika;
    }

    return varisZamaniSaat + ":" + varisZamaniDakika;
}

void Menu::UrunSec(SinglyLinkedList &urunler, int urunIndex, Kullanici k)
{
    Zaman z;
    Kurye kurye;
    ofstream SiparislerFile("./siparisler.txt", ios::app);
    ofstream FaturalarFile("./faturalar.txt", ios::app);
    string urun = urunler.getElement(urunIndex);

    // Urun Fiyat
    stringstream ss;
    string tempUrun = urun;
    string delimiter = "-";
    tempUrun.erase(0, tempUrun.find(delimiter) + delimiter.length());
    tempUrun.erase(0, tempUrun.find(delimiter) + delimiter.length());
    string priceFromLine = tempUrun.substr(0, tempUrun.find(delimiter));
    int priceFromLineInt;
    ss << priceFromLine;
    ss >> priceFromLineInt;

    cout << priceFromLine;

    cout << "Secilen urun: " << endl;
    cout << urun << endl;

    // Siparis Adet
    int adet;
    cout << "Adet giriniz: " << endl;
    cin >> adet;

    // Siparis SiparisNo
    int siparisNo = rand() % 9999999 + 1000000;

    // Siparis Fiyat
    int siparisFiyat = adet * priceFromLineInt;

    Siparis s(k.getKullaniciAdi(), k.getAdres(), urun, to_string(siparisNo), siparisFiyat, z.getCurrentTime());
    s.set_siparis_ulasim(kurye.VarisZamaniHesapla(s));

    if (SiparislerFile.is_open())
    {
        SiparislerFile << s.get_kullanici_adi() << "-"
                       << s.get_siparis_adresi() << "-"
                       << s.get_urun_bilgisi() << "-"
                       << s.get_siparis_no() << "-"
                       << s.get_siparis_fiyat() << "-"
                       << s.get_siparis_baslangic() << "-"
                       << s.get_siparis_ulasim() << endl;

        if (FaturalarFile.is_open())
        {
            FaturalarFile << s.get_kullanici_adi() << "-"
                          << s.get_siparis_adresi() << "-"
                          << s.get_urun_bilgisi() << "-"
                          << s.get_siparis_no() << "-"
                          << s.get_siparis_fiyat() << "-"
                          << s.get_siparis_baslangic() << endl;
        }
        else
        {
            cout << "Boyle bir dosya bulunamadi..." << endl;
        }
    }
    else
    {
        cout << "Boyle bir dosya bulunamadi..." << endl;
    }

    FaturalarFile.close();
    SiparislerFile.close();
}

string Zaman::getCurrentDate()
{
    auto end = std::chrono::system_clock::now();

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    return std::ctime(&end_time);
}

string Zaman::getCurrentTime()
{
    string time;
    string timeUnManipulated = getCurrentDate();
    timeUnManipulated.erase(0, timeUnManipulated.find(" ") + 1);
    timeUnManipulated.erase(0, timeUnManipulated.find(" ") + 1);
    timeUnManipulated.erase(0, 3);
    timeUnManipulated.erase(timeUnManipulated.find(" "), '\n');

    time = timeUnManipulated;

    string hour;
    string min;

    hour = time.substr(0, time.find(":"));
    time.erase(0, time.find(":") + 1);
    min = time.substr(0, time.find(":"));

    stringstream ss;

    int hourInt;
    int minInt;

    ss << hour;
    ss >> hourInt;

    ss << min;
    ss >> minInt;

    setSaat(hourInt);
    setDakika(minInt);

    return hour + ":" + min;
}

void Zaman::printZaman()
{
    cout << getSaat() << ":" << getDakika() << endl;
}

Zaman Zaman::operator+(Zaman &obj)
{

    if (this->dakika + obj.dakika >= 60)
    {
        this->saat += 1;
        this->dakika = this->dakika + obj.dakika - 60;
    }
    else
    {
        this->dakika = obj.dakika + this->dakika;
    }

    if (this->saat + obj.saat >= 24)
    {
        this->saat = (this->saat + obj.saat) % 24;
    }
    else
    {
        this->saat = this->saat + obj.saat;
    }

    return *this;
}

void Kurye::KuryeAta(string varisZamani)
{
    ifstream KuryelerFile("./kuryeler.txt");

    string varisZamaniSaat = varisZamani.substr(0, varisZamani.find(":"));
    varisZamani.erase(0, varisZamani.find(":") + 1);
    string varisZamaniDakika = varisZamani.substr(0, varisZamani.find("\n"));

    string line;
    string ZamanFromFile; 
    string SaatFromFile;
    string DakikaFromFile;
    string secilenKurye;
    if (KuryelerFile.is_open())
    {
        while (getline(KuryelerFile, line))
        {
            line.erase(0, line.find("-") + 1);
            line.erase(0, line.find("-") + 1);
            ZamanFromFile = line.substr(0, line.find("\n"));
            
            SaatFromFile = ZamanFromFile.substr(0, ZamanFromFile.find(":"));
            ZamanFromFile.erase(0, ZamanFromFile.find(":") + 1);
            DakikaFromFile = ZamanFromFile.substr(0, ZamanFromFile.find("\n"));

            if (SaatFromFile <= varisZamaniSaat)
            {
                secilenKurye = line;
            }   
        }
    }
}

int main()
{
    srand(time(NULL));

    Menu m;
    m.MenuBaslat();

    cout << "\n\n\n";
}
