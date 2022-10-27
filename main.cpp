#include <iostream>
#include <string>
#include <time.h>
#include <curses.h>
#include <regex>
#include <fstream>

using namespace std;

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
    IF:
        if (opsiyon1 == 1)
        {
            cout << "1 - Yönetici girişi\n2 - Müşteri giris\n"
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
                cout << "Yanlis Secim." << endl;
                goto IF;
            }
        }
        else if (opsiyon1 == 2)
        {
            cout << "patates";
        }
    }

    void YoneticiGiris()
    {
    YONETICI_MENU:
        cout << "1 - Urun ekle\n2 - Kurye ekle\n3 - Sikayet ve Oneriler\n4 - Indirim kodu tanimla\n5 - Siparis Faturalari" << endl;
        int ops;

        cin >> ops;

        if (ops == 1)
        {
            cout << "Urun ekle";
        }
        else if (ops == 2)
        {
            cout << "Kurye ekle";
        }
        else if (ops == 3)
        {
            cout << "Sikayet ve Oneriler";
        }
        else if (ops == 4)
        {
            cout << "Indirim kodu tanimla";
        }
        else if (ops == 5)
        {
            cout << "Faturalar";
        }
        else
        {
            cout << "Hatali giris" << endl;
            goto YONETICI_MENU;
        }
    }

    void MusteriGiris()
    {
        cout << "1 - Kategoriler\n2 - Siparis Takip\n3 - Sikayet ve Oneriler\n4 - Sifre Degistir\n5 - Geri dön" << endl;
    }
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

    string sifrele(const char *yazi, bool goster)
    {
        const char BACKSPACE = 8;
        const char RETURN = 13;

        string sifre;
        unsigned char harf = 0;

        cout << yazi;

        while (harf = getch() != RETURN)
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
                getch(); // ignore non printable chars
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
    }

    void kaydet()
    {
        ofstream kullanicilar("./kullanicilar.txt", ios::app);

        string kullaniciAdi;
        string sifre;
        string ePosta;

    KONTROL:
        if (kullanicilar.is_open())
        {

            cout << "Kullanici Adi:	";
            getline(cin >> ws, kullaniciAdi);

            sifre = sifrele("Sifre:	", true);

            cout << "Epostanizi Giriniz: ";
            getline(cin >> ws, ePosta);

            if (kullaniciAdiKontrol(kullaniciAdi))
            {
                setKullaniciAdi(kullaniciAdi);
            }

            if (sifreKontrol(sifre))
            {
                setSifre(sifre);
            }

            if (ePostaKontrol(ePosta))
            {
                setEposta(ePosta);
            }

            kullanicilar << getKullaniciAdi() << " " << getSifre() << " " << getEposta() << endl;

            kullanicilar.close();
        }
        else
        {
            cout << "Boyle Bir Dosya Yok....." << endl;
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
    { //!!!!!!!!!!!!!!!  DUZELT�LECEK KISIM  !!!!!!!!!!!!!!!//
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
    char *sifre;

public:
    void set_sifre(char *) { this->sifre = sifre; }
    string get_sifre() { return sifre; }
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
    char *kategori;
    char *kiyafet_adi;
    char *boyut;
    char *renk;
};

class Siparis : public Kiyafet
{
private:
    int siparis_no;
    double siparis_fiyat;
    int siparis_baslangic; // TIME
    int siparis_ulasim;    // TIME
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
};

int main()
{
    Menu m;

    m.MenuBaslat();

    cout << "\n\n\n";
}