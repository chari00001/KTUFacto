#include <iostream>
#include <string>
#include <time.h>
// #include <conio.h> // for Windows
#include <curses.h> // For Linux
#include <regex>
#include <fstream>
#include <list>
#include <sstream>

using namespace std;

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
    Kullanici(string KullaniciAdi = "")
    {
        kullaniciAdi = KullaniciAdi;
    }

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

    string sifrele(char *bilgi, bool gizle = true);

    void SikayetYaz();

    void SifreDegistir();

    void kaydet();

    bool sifreKontrol(string sifre);

    bool kullaniciAdiKontrol(string kullanici_adi);

    bool ePostaKontrol(string ePosta);
};

class Yonetici : public Kisi
{
private:
    string sifre;

public:
    Yonetici(string Sifre = "") // sikinti
    {
        sifre = Sifre;
    }
    void set_sifre(char *) { this->sifre = sifre; }

    void UrunEkle();
    void KuryeEkle();
    void SikayetOku();
    void IndirimKoduEkle();
    void FaturaOku();
};

class Kurye : public Kisi
{
    int dagitim_bitis; // TIME
    int siparis_no;
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
    double get_fiyat() { return fiyat; }

    void set_kategori(string kategori) { this->kategori = kategori; }
    string get_kategori() { return kategori; }

    void set_kiyafet_adi(string kiyafet_adi) { this->kiyafet_adi = kiyafet_adi; }
    string get_kiyafet_adi() { return kiyafet_adi; }

    void set_boyut(string boyut) { this->boyut = boyut; }
    string get_boyut() { return boyut; }

    void set_renk(string renk) { this->renk = renk; }
    string get_renk() { return renk; }
};

class Siparis : public Kiyafet
{
public:
    Siparis(int siparis_no,
            double siparis_fiyat,
            int siparis_baslangic,
            int siparis_ulasim);

private:
    int siparis_no;
    double siparis_fiyat;
    int siparis_baslangic; // TIME
    int siparis_ulasim;    // TIME
};

class Zaman
{
private:
    int saat;
    int dakika;
};

class Menu
{
public:
    void MenuBaslat();

    void YoneticiGiris();

    void MusteriGiris();

    SinglyLinkedList KategorileriListele();

    void UrunleriListele(string Selection);

    void UrunSec(SinglyLinkedList &urunler, int urunIndex);
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

    if (head == NULL) // ilk elemani alirken sikinti olur gibi?
        head = v;
    else // buralara bakin
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
    string yeniSifre;
    // yeniSifre = sifrele("Yeni Sifrenizi Giriniz:", true);

    cout << "Yeni sifrenizi giriniz: " << endl;
    cin >> yeniSifre;

    ifstream KullaniciFile("./kullanicilar.txt");
    ofstream KullaniciFileTemp("./kullanicilarTemp.txt");

    if (KullaniciFile.is_open() && KullaniciFileTemp.is_open())
    {
        string line;
        while (getline(KullaniciFile, line))
        {
            if (line.find(getKullaniciAdi()) != string::npos)
            {
                KullaniciFileTemp << getKullaniciAdi() << "-"
                                  << yeniSifre << "-"
                                  << getEposta() << "-"
                                  << getAdres() << "-"
                                  << getDTarihi() << "-"
                                  << getIndirimKodu() << "-"
                                  << getAdSoyad() << "-"
                                  << getTelNo() << endl;
            }
            else
            {
                KullaniciFileTemp << line << endl;
            }
        }
    }

    KullaniciFile.close();
    KullaniciFileTemp.close();

    remove("./kullanicilar.txt");
    rename("./kullanicilarTemp.txt", "./kullanicilar.txt");

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
        UrunlerFile << cat << " " << name << " " << price << " " << size << " " << color << endl;
    }
    else
    {
        cout << "Boyle bir dosya yok." << endl;
    }
    UrunlerFile.close();
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
void Yonetici::FaturaOku() {}

void Menu::MenuBaslat()
{
    int opsiyon1, opsiyon2;
    cout << "1 - Sisteme giris\n2 - Uye kaydi\n3 - Cikis"
         << endl;
    cin >> opsiyon1;
    system("clear"); // system("cls") - windows
MENU:                // switch case
    if (opsiyon1 == 1)
    {
        cout << "1 - Yonetici Girisi\n2 - Musteri Girisi\n"
             << endl;
        cin >> opsiyon2;
        system("clear");
        if (opsiyon2 == 1)
        {
            YoneticiGiris();
        }
        else if (opsiyon2 == 2)
        {
            MusteriGiris();
        }
        else
        {
            cout << "Yanlış Seçim." << endl;
            goto MENU;
        }
    }
    else if (opsiyon1 == 2)
    {
        Kullanici user;
        user.kaydet();
        system("clear");
        return MenuBaslat();
    }
}

void Menu::YoneticiGiris()
{
    Yonetici y;

    string sifre, girilenSifre;
    ifstream AdminFile("./yonetici.txt", ios::out);
    AdminFile >> sifre;

    cout << "Admin sifrenizi giriniz:" << endl;
    cin >> girilenSifre;
    system("clear");
    if (sifre == girilenSifre)
    {
    YONETICI_MENU:
        cout << "1 - Urun ekle\n2 - Kurye ekle\n3 - Sikayet ve Oneriler\n4 - Indirim kodu tanimla\n5 - Siparis Faturalari" << endl;
        int ops;

        cin >> ops;

        if (ops == 1)
        {
            system("clear");
            y.UrunEkle();
        }
        else if (ops == 2)
        {
            system("clear");
            cout << "Kurye ekle";
        }
        else if (ops == 3)
        {
            system("clear");
            y.SikayetOku();
        }
        else if (ops == 4)
        {
            system("clear");
            y.IndirimKoduEkle();
        }
        else if (ops == 5)
        {
            system("clear");
            cout << "Faturalar";
        }
        else
        {
            system("clear");
            cout << "Hatali giris" << endl;
            goto YONETICI_MENU;
        }
    }
    else
    {
        cout << "Yanlış şifre.";
    }
    AdminFile.close();
}

void Menu::MusteriGiris()
{
    Kullanici k;

KULLANICI_GIRIS:
    string username, password, line;
    cout << "Kullanici adi: ";
    cin >> username;
    // password = k.sifrele("Sifre:", true);
    cout << "Sifrenizi giriniz: " << endl;
    cin >> password;

    ifstream file("./kullanicilar.txt");
    if (file.is_open())
    {
        while (getline(file, line))
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
        cout << "Boyle bir kullanici yoktur." << endl;
        goto KULLANICI_GIRIS;
    }
    else
    {
        cout << "Dosya acilamadi" << endl;
    }
    file.close();

MUSTERI_MENU:
    cout << "1 - Kiyafet kategorileri ve Urun secimi\n2 - Siparis takip\n3 - Sikayet ve Oneriler\n4 - Sifre Degistir\n5 - Geri don\n"
         << endl;
    int ops;
    cin >> ops;

    if (ops == 1)
    {
        system("clear");
        SinglyLinkedList categories = KategorileriListele();
        int categoryCount = categories.print();

        string categorySelection;
        cout << "Kategori seciniz (Tum kategoriler icin 0 yaziniz): " << endl;
        getline(cin >> ws, categorySelection);

        system("clear");
        UrunleriListele(categorySelection);
    }
    else if (ops == 2)
    {
        system("clear");
        cout << "Siparis takip";
    }
    else if (ops == 3)
    {
        system("clear");
        k.SikayetYaz();
    }
    else if (ops == 4)
    {
        system("clear");
        k.SifreDegistir();
    }
    else if (ops == 5)
    {
        system("clear");
        // Geri don
        MenuBaslat();
    }
    else
    {
        system("clear");
        cout << "Hatali giris" << endl;
        goto MUSTERI_MENU;
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
            string Kategori = line.substr(0, line.find(" "));
            Kategoriler->addBack(Kategori);
        }
    }

    UrunlerFile.close();

    return *Kategoriler;
}

void Menu::UrunleriListele(string Selection)
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
                string categoryFromLine = line.substr(0, line.find(" "));
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
            UrunSec(*Urunler, secilenUrunIndex);
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

void Menu::UrunSec(SinglyLinkedList &urunler, int urunIndex)
{
    ofstream SiparislerFile("./siparisler.txt", ios::app);
    string urun = urunler.getElement(urunIndex);

    cout << urunler.print() << endl;

    // Urun Fiyat
    stringstream ss;
    string tempUrun = urun;
    tempUrun.erase(0, tempUrun.find(" ") + 1);
    tempUrun.erase(0, tempUrun.find(" ") + 1);
    string priceFromLine = tempUrun.substr(0, tempUrun.find(" "));
    int priceFromLineInt;
    ss << priceFromLine;
    ss >> priceFromLineInt;

    // Siparis Adet
    int adet;
    cout << "Adet giriniz: " << endl;
    cin >> adet;

    // Siparis SiparisNo
    int siparisNo = rand() % 9999999 + 1000000;

    // Siparis Fiyat
    int siparisFiyat = adet * priceFromLineInt;

    if (SiparislerFile.is_open())
    {
        SiparislerFile << urun << " "
                       << siparisNo << " "
                       << siparisFiyat << " "
                       << "12.00"
                       << " "
                       << "13.00" << endl;
    }
    else
    {
        cout << "Boyle bir dosya bulunamadi..." << endl;
    }

    SiparislerFile.close();
}

int main()
{
    srand(time(NULL));

    Menu m;

    m.MenuBaslat();

    cout << "\n\n\n";
}