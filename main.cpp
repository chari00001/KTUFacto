#include <iostream>
#include <string>
#include <time.h>
// #include <conio.h> // for Windows
#include <curses.h> // For Linux
#include <regex>
#include <fstream>
#include <list>

using namespace std;

class SinglyNode
{
public:
    string elem;
    SinglyNode *next;
};

class SinglyLinkedList
{
public:
    SinglyNode *head;

    SinglyLinkedList();

    bool empty() const;
    void addBack(const string &e);
    void print();

    void removeOrdered(const string &e);
};

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
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

void SinglyLinkedList::print()
{
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    SinglyNode *first = head;
    while (first != NULL)
    {
        cout << first->elem << endl;
        first = first->next;
    }
}

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
    char *adSoyad;
    char *telNo;

public:
    void setAdSoyad(char *adSoyad) { this->adSoyad = adSoyad; }
    void setTelNo(char *telNo) { this->telNo = telNo; }

    string getAdSoyad() { return adSoyad; }
    string getTelNo() { return telNo; }
};

class Kullanici : public Kisi
{
private:
    string kullaniciAdi;
    string ePosta;
    string adres;
    string sifre;
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

    void SikayetYaz()
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

    void SifreDegistir()
    {
        // change the password of the user and add it to kullanicilar.txt in format of username:password:email 
        string yeniSifre;
        cout << "Yeni Sifrenizi Giriniz: " << endl;
        getline(cin >> ws, yeniSifre);

        ifstream KullanicilarFile("./kullanicilar.txt");
        ofstream KullanicilarFileTemp("./kullanicilartemp.txt");

        if (KullanicilarFile.is_open() && KullanicilarFileTemp.is_open())
        {
            string line;
            while (getline(KullanicilarFile, line))
            {
                if (line.find(getKullaniciAdi()) != string::npos)
                {
                    string newLine = getKullaniciAdi() + " " + yeniSifre + " " + getEposta();
                    KullanicilarFileTemp << newLine << endl;
                }
                else
                {
                    KullanicilarFileTemp << line << endl;
                }
            }
        }  
        KullanicilarFile.close();
        KullanicilarFileTemp.close();

        remove("./kullanicilar.txt");
        rename("./kullanicilartemp.txt", "./kullanicilar.txt");


        // string line;
        // string usernameFromFile;
        // string emailFromFile;

        // string newPassword;

        // cout << "Yeni sifrenizi giriniz: " << endl;
        // cin >> newPassword;

        // ifstream KullanicilarFile("./kullanicilar.txt");

        // if (KullanicilarFile.is_open())
        // {
        //     while (getline(KullanicilarFile, line))
        //     {
        //         usernameFromFile = line.substr(0, line.find(" "));

        //         if (usernameFromFile == kullaniciAdi)
        //         {
        //             line.erase(0, line.length());

        //             ofstream KullanicilarFileYaz("./kullanicilar.txt", ios::app);

        //             if (KullanicilarFileYaz.is_open())
        //             {
        //                 KullanicilarFileYaz << getKullaniciAdi() << " " << newPassword << " " << getEposta();
        //             }

        //             KullanicilarFileYaz.close();
        //             break;
        //         }
        //     }

        //     KullanicilarFile.close();
        // }
    }

    /*   string sifrele(const char *yazi, bool goster)
       {
           const char BACKSPACE = 8;
           const char RETURN = 13;

           string sifre;
           unsigned char harf = 0;

           cout << yazi;

           while (harf = _getch() != RETURN)
           {
               if (harf == BACKSPACE)
               {
                   if (sifre.length() != 0)
                   {
                       if (goster)
                           cout << "\b \b";
                       sifre.resize(sifre.length() - 1);
                   }
               }
               else if (harf == 0 || harf == 224) // handle escape sequences
               {
                   _getch(); // ignore non printable chars
                   continue;
               }
               else
               {
                   sifre += harf;
                   if (goster)
                       cout << '*';
               }
           }
           cout << endl;
           return sifre;
       }*/

    void kaydet()
    {
        fstream kullanicilar("./kullanicilar.txt", ios::app);

        string kullaniciAdi;
        string sifre;
        string ePosta;

    KONTROL:
        if (kullanicilar.is_open())
        {

            cout << "Kullanici Adi:	";
            getline(cin >> ws, kullaniciAdi);

            // sifre = sifrele("Sifre:	", true);
            cout << "\nŞifreniz: ";
            getline(cin >> ws, sifre);

            cout << "\nEpostanizi Giriniz: ";
            getline(cin >> ws, ePosta);

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

            kullanicilar << getKullaniciAdi() << " " << getSifre() << " " << getEposta() << endl;

            kullanicilar.close();

            cout << "Kayit Basarili" << endl;
        }
        else
        {
            cout << "Böyle Bir Dosya Yok..." << endl;
        }
    }

    bool sifreKontrol(string sifre)
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
    bool kullaniciAdiKontrol(string kullanici_adi)
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
            return true;
        }
    }
    bool ePostaKontrol(string ePosta)
    {
        regex eMailexp{"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"};

        return regex_search(ePosta, eMailexp);
    }
};

class Yonetici : public Kisi
{
private:
    string sifre;

public:
    Yonetici(string Sifre = "")
    {
        sifre = Sifre;
    }
    void set_sifre(char *) { this->sifre = sifre; }
    string get_sifre() { return sifre; }

    void UrunEkle()
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
    void KuryeEkle();
    void SikayetOku()
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
    void IndirimKoduEkle()
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
    void MenuBaslat()
    {
        int opsiyon1, opsiyon2;
        cout << "1 - Sisteme giris\n2 - Uye kaydi\n3 - Cikis"
             << endl;
        cin >> opsiyon1;
        system("clear"); // system("cls") - windows
    MENU:
        if (opsiyon1 == 1)
        {
            cout << "1 - Yönetici girişi\n2 - Müşteri girişi\n"
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

    void YoneticiGiris()
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

    void MusteriGiris()
    {
        Kullanici k;

    KULLANICI_GIRIS:
        string username, password, line;
        cout << "Kullanici adi: ";
        cin >> username;
        cout << "Sifre: ";
        cin >> password;

        ifstream file("./kullanicilar.txt");
        if (file.is_open())
        {
            while (getline(file, line))
            {
                string delimiter = " ";
                string usernameFromFile = line.substr(0, line.find(delimiter));
                line.erase(0, line.find(delimiter) + delimiter.length());
                string passwordFromFile = line.substr(0, line.find(delimiter));

                // check if the username and password match
                if (usernameFromFile == username && passwordFromFile == password)
                {
                    k.setKullaniciAdi(username);
                    cout << "Giris basarili" << endl;
                    goto MUSTERI_MENU;
                }
                else
                {
                    system("clear");
                    
                    // goto KULLANICI_GIRIS;
                }
            }
            // if we reach this point, it means that the username and password did not match
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
            KategorileriListele();
        }
        else if (ops == 2)
        {
            cout << "Siparis takip";
        }
        else if (ops == 3)
        {
            k.SikayetYaz();
        }
        else if (ops == 4)
        {
            k.SifreDegistir();
            cout << "Sifre Degistir";
        }
        else if (ops == 5)
        {
            system("clear");
            MenuBaslat();
        }
        else
        {
            cout << "Hatali giris" << endl;
            goto MUSTERI_MENU;
        }
    }

    void KategorileriListele()
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
            Kategoriler->print();
        }

        UrunlerFile.close();
    }
};

int main()
{
    Menu m;

    m.MenuBaslat();

    cout << "\n\n\n";
}
