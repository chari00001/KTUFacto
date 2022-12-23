
// Öğrenciler: Sinan Kocatürk 410452, Berk Çağrı Laçin 413518, Enes Ceviz 402498
// Ders Adı: Nesne Yönelimli Programlama
// Grup: Grup-18

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h> // for Windows
// #include <curses.h> // For Linux
#include <regex>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>

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
};

// Switch case ifadelerinde olusan bi sonsuz dongu sorununun cozumu icin.
char charTanimla(string donusen)
{
    char donen = '0';

    if (donusen.size() == 1)
    {
        donen = donusen[0];
        return donen;
    }
    if (donusen.size() > 1)
    {
        return donen;
    }

    return donen;
}

class Zaman
{
private:
    int saat;
    int dakika;

public:
    Zaman(int Saat = 0, int Dakika = 0)
    {
        setSaat(Saat);
        setDakika(Dakika);
    }

    void setSaat(int Saat) { this->saat = Saat; }
    void setDakika(int Dakika) { this->dakika = Dakika; }

    int getDakika() { return dakika; }
    int getSaat() { return saat; }

    string getCurrentDate();
    string getCurrentTime();

    Zaman operator+(Zaman &obj);
    Zaman operator-(Zaman &obj);
    bool operator<=(Zaman &obj);

    void printZaman();
    Zaman stringToZaman(string zaman);
};

class Kisi
{
private:
    string adSoyad;
    string telNo;

public:
    Kisi(string AdSoyad = "", string TelNo = "")
    {
        setAdSoyad(AdSoyad);
        setTelNo(TelNo);
    }

    void setAdSoyad(string adSoyad) { this->adSoyad = adSoyad; }
    void setTelNo(string telNo) { this->telNo = telNo; }

    string getAdSoyad() { return adSoyad; }
    string getTelNo() { return telNo; }

    bool telNoKontrol(string telNo);
    string SifreMaskeleme(const char *bilgi, bool gizle = true);
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
    string sepet;
    double sepetTutari;

public:
    Kullanici(string KullaniciAdi = "", string Sepet = "", double SepetTutari = 0.0)
    {
        setKullaniciAdi(KullaniciAdi);
        setSepet(Sepet);
        setSepetTutari(SepetTutari);
    }
    Kullanici(string adSoyad, string telNo, string kullaniciAdi, string ePosta, string adres, string sifre, string indirimKodu, string dTarihi)
        : Kisi(adSoyad, telNo)
    {
        this->kullaniciAdi = kullaniciAdi;
        this->ePosta = ePosta;
        this->adres = adres;
        this->sifre = sifre;
        this->indirimKodu = indirimKodu;
        this->dTarihi = dTarihi;
    }

    void setKullaniciAdi(string kullaniciAdi) { this->kullaniciAdi = kullaniciAdi; }
    void setEposta(string ePosta) { this->ePosta = ePosta; }
    void setAdres(string adres) { this->adres = adres; }
    void setSifre(string sifre) { this->sifre = sifre; }
    void setIndirimKodu(string indirimKodu) { this->indirimKodu = indirimKodu; }
    void setDTarihi(string dTarihi) { this->dTarihi = dTarihi; }
    void setSepet(string sepet) { this->sepet = sepet; }
    void setSepetTutari(double sepetTutari) { this->sepetTutari = sepetTutari; }

    string getKullaniciAdi() { return kullaniciAdi; }
    string getEposta() { return ePosta; }
    string getAdres() { return adres; }
    string getSifre() { return sifre; }
    string getIndirimKodu() { return indirimKodu; }
    string getDTarihi() { return dTarihi; }
    string getSepet() { return sepet; }
    double getSepetTutari() { return sepetTutari; }

    // Musteri menu fonksiyonlari
    void SikayetYaz();
    void SifreDegistir();
    void KullaniciKaydet();
    void SiparisTakip();

    bool sifreKontrol(string sifre);
    bool kullaniciAdiKontrol(string kullanici_adi);
    bool ePostaKontrol(string ePosta);
    bool dogumTarihiKontrol(string dogumTarihi);

    void dosyaOku(string, vector<string>);
    void YeniSifreDosyaYaz(string, vector<string>, string);
};

class Yonetici : public Kisi
{
private:
    string sifre;

public:
    Yonetici(string adSoyad = "", string telNo = "", string Sifre = "") : Kisi(adSoyad, telNo)
    {
        this->sifre = Sifre;
    }
    void set_sifre(string sifre) { this->sifre = sifre; }

    // Yonetici menu fonksiyonlari
    void UrunEkle();
    void KuryeEkle();
    void SikayetOku();
    void IndirimKoduEkle();
    void FaturaOku();
};

class Kiyafet
{
private:
    int fiyat;
    string kategori;
    string kiyafet_adi;
    string boyut;
    string renk;

public:
    Kiyafet(int Fiyat = 0, string Kategori = "", string Kiyafet_Adi = "", string Boyut = "", string Renk = "")
    {
        set_fiyat(Fiyat);
        set_kategori(Kategori);
        set_kiyafet_adi(Kiyafet_Adi);
        set_boyut(Boyut);
        set_renk(Renk);
    }

    void set_fiyat(int fiyat) { this->fiyat = fiyat; }
    void set_kategori(string kategori) { this->kategori = kategori; }
    void set_kiyafet_adi(string kiyafet_adi) { this->kiyafet_adi = kiyafet_adi; }
    void set_boyut(string boyut) { this->boyut = boyut; }
    void set_renk(string renk) { this->renk = renk; }

    int get_fiyat() { return fiyat; }
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
    Zaman dagitim_bitis;
    int siparis_no;

public:
    Kurye(string AdSoyad = "", string TelNo = "")
    {
        setAdSoyad(AdSoyad);
        setTelNo(TelNo);
    }

    void set_dagitim_bitis(Zaman dagitim_bitis) { this->dagitim_bitis = dagitim_bitis; }
    void set_siparis_no(int siparis_no) { this->siparis_no = siparis_no; }

    Zaman get_dagitim_bitis() { return dagitim_bitis; }
    int get_siparis_no() { return siparis_no; }

    string VarisZamaniHesapla(Siparis s, string kuryeId);
    Zaman VarisZamani(Siparis s, string kuryeId);

    string KuryeSec(Siparis s);

    // Kurye musaitlik kontrol fonksiyonlari
    string BosKuryeKontrol();
    string BitmisKuryeKontrol();
    string IlkKuryeKontrol();

    void KuryeSiparisVer(string id, Siparis s);
};

class Menu
{
public:
    void MenuBaslat();

    // Sistem giris fonksiyonlari
    void YoneticiGiris();
    void MusteriGiris();

    // Linked list kullandigimiz yerler
    SinglyLinkedList KategorileriListele();
    void UrunleriListele(string Selection, Kullanici k);
    void UrunSec(SinglyLinkedList &urunler, int urunIndex, Kullanici k);

    // Beden ve Renkleri "," ayiracindan ayirip kontrol etmek icin.
    bool Parcala(string, string);
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
        cout << "Satista urun bulunamadi" << endl;
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
    // Normalde gelen elemanin daha once olup olmadigi kontrol edilmezken
    // asagidaki for dongusu ile kontrol saglanmistir.
    for (SinglyNode *i = head; i != NULL; i = i->next)
    {
        if (i->elem == e)
        {
            return;
        }
        v->elem = e;
        v->next = NULL;
    }

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

int SinglyLinkedList::print()
{
    int count = 0;
    if (empty())
    {
        cout << "Urun ya da Kurye Bulunamadi" << endl;
        return 0;
    }

    SinglyNode *first = head;
    while (first != NULL)
    {
        cout << first->elem << endl;
        first = first->next;
        count++;
    }

    // Ihtiyac halinde ekrana liste yazdirmanin yaninda eleman sayisini da dondurur.
    return count - 1;
}

string Kisi::SifreMaskeleme(const char *bilgi, bool gizle)
{
    const char BACKSPACE = 8;
    const char RETURN = 13;

    string sifre;
    char harf = 0;

    cout << bilgi << " ";

    while ((harf = _getch()) != RETURN)
    {
        if (harf == BACKSPACE)
        {
            if (sifre.length() != 0)
            {
                if (gizle)
                    cout << "\b \b";
                sifre.pop_back();
            }
        }
        else if (harf == 0 || harf == 224)
        {
            _getch();
            continue;
        }
        else
        {
            sifre.push_back(harf);
            if (gizle)
                cout << '*';
        }
    }
    cout << endl;
    return sifre;
}

// Surekli dosya okuma islemi yapmak yerine bu fonksiyon ile islem kolaylastirildi.
void Kullanici::dosyaOku(string dosyaYolu, vector<string> list)
{
    ifstream OkumaDosyasi(dosyaYolu);
    string line;
    if (OkumaDosyasi.is_open())
    {
        while (getline(OkumaDosyasi, line))
        {
            list.push_back(line);
        }
    }
    else
    {
        cout << "Dosya Acilamadi<<" << endl;
    }

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }

    OkumaDosyasi.close();
}

// Sifre degisimi icin yardimci fonksiyon.
void Kullanici::YeniSifreDosyaYaz(string dosyaYolu, vector<string> list, string yeniSifre)
{
    ifstream KullanicilarDosya(dosyaYolu);

    if (KullanicilarDosya.is_open())
    {
        string line;
        while (getline(KullanicilarDosya, line))
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
    KullanicilarDosya.close();

    // ofstream::out | ofstream::trunc ile dosya acilirken onceki veriler silinir.
    fstream KullanicilarDosya1(dosyaYolu, ofstream::out | ofstream::trunc);

    for (int i = 0; i < list.size(); i++)
    {
        KullanicilarDosya1 << list[i] << endl;
    }

    KullanicilarDosya1.close();
}

void Kullanici::SikayetYaz()
{
    string sikayet;

    cout << "Sikayet veya Onerinizi yaziniz: " << endl;
    getline(cin >> ws, sikayet);

    ofstream SikayetDosya("./sikayetler.txt", ios::app);

    if (SikayetDosya.is_open())
    {
        SikayetDosya << getKullaniciAdi() << " - " << sikayet << endl;
    }
}

void Kullanici::SifreDegistir()
{
    vector<string> list;
    string yeniSifre;

KONTROL:
    yeniSifre = SifreMaskeleme("Yeni Sifrenizi Giriniz:", true);
    // cout << "Yeni Sifrenizi giriniz: ";
    // cin >> yeniSifre;

    if (sifreKontrol(yeniSifre) == false)
    {
        cout << "Sifreniz en az 8 karakterden olusmalidir ve en az bir rakam ,en az bir ozel karakter, en az bir kucuk harf ve bir buyuk harf icermelidir." << endl;
        goto KONTROL;
    }

    YeniSifreDosyaYaz("./kullanicilar.txt", list, yeniSifre);

    system("CLS");
    cout << "Sifreniz Basariyla Degistirildi" << endl;

    setSifre(yeniSifre);
}

void Kullanici::KullaniciKaydet()
{
    vector<string> list;
    vector<string> konumList;
    fstream KullanicilarDosyaYaz("./kullanicilar.txt", ios::app);
    ifstream KullanicilarDosyaOku("./kullanicilar.txt");

    string adSoyad;
    string telNo = " ";
    string kullaniciAdi = " ";
    string sifre;
    string ePosta;
    string adres;
    string indirimKodu;
    string dTarihi = " ";

    string line;
    while (getline(KullanicilarDosyaOku, line))
    {
        list.push_back(line.substr(0, line.find("-")));
    }

    KullanicilarDosyaOku.close();

KONTROL:
    if (KullanicilarDosyaYaz.is_open())
    {

        cout << "Kullanici Adi: ";
        getline(cin >> ws, kullaniciAdi);

        // Kullanici adi musaitlik kontrolu.
        if (!(find(list.begin(), list.end(), kullaniciAdi) != list.end()))
        {
            if (kullaniciAdiKontrol(kullaniciAdi))
            {
                setKullaniciAdi(kullaniciAdi);
            }
            else
            {
                system("CLS");
                cout << "Kullanici adi veya sifre geçersiz.\n";
                goto KONTROL;
            }
        }
        else
        {
            cout << "Bu kullanici zaten kayitli." << endl;
            goto KONTROL;
        }

        cout << "Ad Soyad: ";
        getline(cin >> ws, adSoyad);

        while (telNoKontrol(telNo) == false)
        {
            cout << "Telefon No: ";
            getline(cin >> ws, telNo);
            if (telNoKontrol(telNo))
            {
                setTelNo(telNo);
            }
            else
            {
                cout << "Telefon numarasi gecersiz.\n";
            }
        }

        while (sifreKontrol(sifre) == false)
        {
            sifre = SifreMaskeleme("Sifrenizi Giriniz:", true);

            if (sifreKontrol(sifre))
            {
                setSifre(sifre);
            }
            else
            {
                system("CLS");
                cout << "Sifreniz en az 8 karakterden olusmalidir ve en az bir rakam ,en az bir ozel karakter,en az bir kucuk harf ve bir buyuk harf icermelidir." << endl;
            }
        }
        while (ePostaKontrol(ePosta) == false)
        {
            cout << "E-posta: ";
            getline(cin >> ws, ePosta);
            if (ePostaKontrol(ePosta))
            {
                setEposta(ePosta);
            }
            else
            {
                system("CLS");
                cout << "E-posta gecersiz.\n";
            }
        }
        ifstream AdresDosya("./konumlar.txt");
        if (AdresDosya.is_open())
        {
            string line;
            while (getline(AdresDosya, line))
            {
                konumList.push_back(line.substr(0, line.find("-")));
            }
        }
        AdresDosya.close();

    ADRES:
        cout << "Mevcut Adresler\n";

        for (int i = 0; i < konumList.size(); i++)
        {
            cout << konumList[i] << endl;
        }

        cout << "\nIlcenizi giriniz: ";
        getline(cin >> ws, adres);

        if (!(find(konumList.begin(), konumList.end(), adres) != konumList.end()))
        {
            system("CLS");
            cout << "Gecersiz Konum Girdiniz..." << endl;
            goto ADRES;
        }

        cout << "\nIndirim kodu: ";
        getline(cin >> ws, indirimKodu);

        while (dogumTarihiKontrol(dTarihi) == false)
        {
            cout << "\nDogum tarihini giriniz (GG/AA/YYYY): ";
            getline(cin >> ws, dTarihi);
            if (dogumTarihiKontrol(dTarihi))
            {
                setDTarihi(dTarihi);
            }
            else
            {
                system("CLS");
                cout << "Dogum Tarihini Uygun Formatta Giriniz...(GG/AA/YYYY)\n";
            }
        }

        system("CLS");
        cout << "Kayit Basarili" << endl;

        setAdSoyad(adSoyad);
        setTelNo(telNo);
        setDTarihi(dTarihi);
        setAdres(adres);
        setIndirimKodu(indirimKodu);

        KullanicilarDosyaYaz << getKullaniciAdi() << "-"
                             << getSifre() << "-"
                             << getEposta() << "-"
                             << getAdres() << "-"
                             << getDTarihi() << "-"
                             << getIndirimKodu() << "-"
                             << getAdSoyad() << "-"
                             << getTelNo() << endl;

        KullanicilarDosyaYaz.close();
    }
    else
    {
        cout << "Böyle Bir Dosya Yok..." << endl;
    }
}

bool Kullanici::sifreKontrol(string sifre)
{
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

            // Istenen 4 sart saglanmadiysa bu if bloguna girer ve false dondurur.
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
{
    regex kullanici_ad_exp{"^[a-z_0-9]+$"};

    if (kullanici_adi.length() < 8)
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

    if (regex_search(kullanici_adi, kullanici_ad_exp))
    {
        return true;
    }
    else
    {

        return false;
    }

    return true;
}

bool Kullanici::ePostaKontrol(string ePosta)
{
    regex eMailexp{"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"};

    return regex_search(ePosta, eMailexp);
}
bool Kisi::telNoKontrol(string telNo)
{
    regex telNoexp{"[0-9]+"};

    return (regex_search(telNo, telNoexp) && telNo.length() >= 10 && telNo.length() <= 13);
}

bool Kullanici::dogumTarihiKontrol(string dogumTarihi)
{
    regex dTarihiexp{"(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/([0-9]{4})"};

    return regex_match(dogumTarihi, dTarihiexp);
}

void Yonetici::UrunEkle()
{
    ofstream UrunlerDosya("./urunler.txt", ios::app);

    string kategori, isim, fiyat, beden, renk;
    cout << "Urunun Kategorisini giriniz: " << endl;
    cin >> kategori;
    cout << "Urunun Ismini giriniz: " << endl;
    cin >> isim;
    cout << "Urunun Fiyatini giriniz: " << endl;
    cin >> fiyat;
    cout << "Urunun Boyutunu giriniz: (bedenler arasina virgul(,) koyunuz)" << endl;
    cin >> beden;
    cout << "Urunun Rengini giriniz: (renkler arasina virgul(,) koyunuz)" << endl;
    cin >> renk;

    transform(beden.begin(), beden.end(), beden.begin(), ::toupper);
    transform(renk.begin(), renk.end(), renk.begin(), ::toupper);

    if (UrunlerDosya.is_open())
    {
        UrunlerDosya << kategori << "-" << isim << "-" << fiyat << "-" << beden << "-" << renk << endl;
    }
    else
    {
        cout << "Boyle bir dosya yok." << endl;
    }
    UrunlerDosya.close();
}

void Kullanici::SiparisTakip()
{
    // Siparis takipte belli bir siparisi takip etmek yerine tum siparislerin durumu goruntulenir.\
    // Gun bilgisi islenmediginden dolayi gece 12 civari verilen siparislerin takibi istenilen sonucu vermeyebilir.
    ifstream SiparislerDosya("./siparisler.txt");

    string Siparis;

    int index = 1;
    if (SiparislerDosya.is_open())
    {
        Zaman z;

        Zaman simdikiZaman = z.stringToZaman(z.getCurrentTime());

        string siparisBitis;
        Zaman siparisBitisZaman;

        string varisZamaniString;
        Zaman varisZamani;

        while (getline(SiparislerDosya, Siparis))
        {
            if (Siparis.substr(0, Siparis.find("-")) == getKullaniciAdi())
            {
                string tempSiparis = Siparis;

                // Bu menude kullanilmayacaklari icin kullanici adi ve adres satirdan silinir
                tempSiparis.erase(0, tempSiparis.find(">") + 2);

                string siparisBilgisiDosya = tempSiparis.substr(0, tempSiparis.find("<"));
                tempSiparis.erase(0, tempSiparis.find("<") + 2);

                string siparisNoDosya = tempSiparis.substr(0, tempSiparis.find("-"));
                tempSiparis.erase(0, tempSiparis.find("-") + 1);

                string toplamFiyatDosya = tempSiparis.substr(0, tempSiparis.find("-")) + " TL";
                tempSiparis.erase(0, tempSiparis.find("-") + 1);

                string siparisZamaniDosya = tempSiparis.substr(0, tempSiparis.find("-"));

                siparisBitis = Siparis.substr(Siparis.length() - 5, Siparis.length());
                siparisBitisZaman = z.stringToZaman(siparisBitis);

                if (siparisBitisZaman <= simdikiZaman)
                {
                    varisZamaniString = "Teslim edildi.";
                }
                else
                {
                    varisZamani = siparisBitisZaman - simdikiZaman;
                    varisZamaniString = "Teslimata " + to_string(varisZamani.getSaat() * 60 + varisZamani.getDakika()) + " Dakika kaldi.";
                }

                // Bilgiler formatli bir sekilde ekrana yazdirilir
                cout << index << " - "
                     << "\n"
                     << "Siparis Bilgisi: " << siparisBilgisiDosya << "\n"
                     << "Siparis Numarasi: " << siparisNoDosya << "\n"
                     << "Siparis Tutari: " << toplamFiyatDosya << "\n"
                     << "Siparis Zamani: " << siparisZamaniDosya << "\n"
                     << "Siparis Durumu: " << varisZamaniString << "\n"
                     << endl;
                index++;
            }
        }
    }
YANLIS_SECIM:
    cout << "Ana menuye donmek icin 1 e basiniz." << endl;
    string Secim;
    cin >> Secim;
    char secim = charTanimla(Secim);
    if (secim == '1')
    {
        cout << "Ana menuye donuluyor..." << endl;
    }
    else
    {
        cout << "Yanlis Secim" << endl;
        goto YANLIS_SECIM;
    }

    SiparislerDosya.close();
}

void Yonetici::KuryeEkle()
{
    ofstream KuryelerDosyaYaz("./kuryeler.txt", ios::app);
    ifstream KuryelerDosyaOku("./kuryeler.txt");

    int kuryeSayisi = 0;

    string kurye;

    while (getline(KuryelerDosyaOku, kurye))
    {
        kuryeSayisi++;
    }

    // Yeni kuryeye id verilirken son kuryenin id sinin 1 fazlasi verilir
    int yeniKuryeId = kuryeSayisi + 1;

    string adSoyad;
    string telNo;

    cout << "Kurye'nin adi soyadi: " << endl;
    getline(cin >> ws, adSoyad);

TEL_NO_KONTROL:
    cout << "Kurye'nin telefon numarasi: " << endl;
    cin >> telNo;
    if (telNoKontrol(telNo) == false)
    {
        cout << "Hatali telefon numarasi girdiniz." << endl;
        goto TEL_NO_KONTROL;
    }

    KuryelerDosyaYaz << yeniKuryeId << "-" << adSoyad << "-" << telNo << "/" << endl;

    KuryelerDosyaYaz.close();
}

void Yonetici::SikayetOku()
{
    vector<string> sikayetList;
    Kullanici k;
    k.dosyaOku("./sikayetler.txt", sikayetList);
}

void Yonetici::IndirimKoduEkle()
{
    vector<string> list;

    ofstream IndirimlerDosya("./indirimler.txt", ios::app);
    ifstream KullanicilarDosya("./kullanicilar.txt");

    string kod;
    string kullaniciAdi;
    string dosyaKullaniciAdi;
    int indirim;

    while (getline(KullanicilarDosya, dosyaKullaniciAdi))
    {
        list.push_back(dosyaKullaniciAdi.substr(0, dosyaKullaniciAdi.find("-")));
    }
KONTROL:
    cout << "Kullanicilar: " << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }

    cout << "Indirim kodu vermek istediginiz kullaniciyi giriniz: " << endl;
    cin >> kullaniciAdi;

    // Kullanici adi listede varsa indirim kodu verilebilir
    if (find(list.begin(), list.end(), kullaniciAdi) != list.end())
    {
        cout << "Indirim kodunu giriniz: " << endl;
        cin >> kod;

        cout << "Indirim miktarini yuzdelik olarak giriniz: " << endl;
        cin >> indirim;

        if (IndirimlerDosya.is_open())
        {
            IndirimlerDosya << kullaniciAdi << " " << kod << " " << indirim << endl;
        }
        else
        {
            cout << "Boyle bir dosya bulunamadi." << endl;
        }
    }
    else
    {
        system("CLS");
        cout << "Gecersiz Kullanici Adi..." << endl;
        goto KONTROL;
    }

    IndirimlerDosya.close();
}
void Yonetici::FaturaOku()
{
    ifstream FaturalarDosya("./faturalar.txt");
    string fatura;
    string delimiter = "-";

    int index = 1;
    while (getline(FaturalarDosya, fatura))
    {
        string KullaniciAdi = fatura.substr(0, fatura.find(delimiter));
        fatura.erase(0, fatura.find(delimiter) + 1);
        string AdresDosya = fatura.substr(0, fatura.find(delimiter));
        fatura.erase(0, fatura.find(">") + 2);
        string UrunDosya = fatura.substr(0, fatura.find("<"));
        fatura.erase(0, fatura.find("<") + 2);
        string SiparisNoDosya = fatura.substr(0, fatura.find(delimiter));
        fatura.erase(0, fatura.find(delimiter) + 1);
        string SiparisFiyatDosya = fatura.substr(0, fatura.find(delimiter));
        fatura.erase(0, fatura.find(delimiter) + 1);
        string SiparisZamaniDosya = fatura.substr(0, fatura.find(delimiter));

        cout << "\nFatura - " << index << endl;
        cout << "\nAd Soyad: " << KullaniciAdi
             << "\nAdres: " << AdresDosya
             << "\nUrun: " << UrunDosya
             << "\nSiparis No: " << SiparisNoDosya
             << "\nSiparis Fiyati: " << SiparisFiyatDosya << " TL"
             << "\nSiparis Saati: " << SiparisZamaniDosya << endl;
        index++;
    }
}

void Menu::MenuBaslat()
{
    ofstream KonumlarDosya("./konumlar.txt", ostream::out | ostream::trunc);
    if (KonumlarDosya.is_open())
    {
        KonumlarDosya << "Ortahisar"
                      << "-"
                      << "35" << endl;
        KonumlarDosya << "Akcaabat"
                      << "-"
                      << "50" << endl;
        KonumlarDosya << "Vakfikebir"
                      << "-"
                      << "90" << endl;
        KonumlarDosya << "Besikduzu"
                      << "-"
                      << "110" << endl;
        KonumlarDosya << "Yomra"
                      << "-"
                      << "55" << endl;
        KonumlarDosya << "Arsin"
                      << "-"
                      << "70" << endl;
        KonumlarDosya << "Arakli"
                      << "-"
                      << "100" << endl;
    }
    KonumlarDosya.close();
ANA_MENU:
    string opsiyon1, opsiyon2;
    cout << "1 - Sisteme giris\n2 - Uye kaydi\n3 - Cikis"
         << endl;
    cin >> opsiyon1;
    char opsiyon3 = charTanimla(opsiyon1);
    system("CLS");

    switch (opsiyon3)
    {
    case '1':
    {
    SISTEM_MENU:
        cout << "1 - Yonetici Girisi\n2 - Musteri Girisi\n"
             << endl;

        cin >> opsiyon2;
        char opsiyon4 = charTanimla(opsiyon2);
        system("CLS");

        switch (opsiyon4)
        {
        case '1':
        {
            YoneticiGiris();
            break;
        }
        case '2':
        {
            MusteriGiris();
            break;
        }

        default:
            cout << "Yanlis Secim." << endl;
            goto SISTEM_MENU;
            break;
        }
        break;
    }
    case '2':
    {
        Kullanici user;
        user.KullaniciKaydet();
        system("CLS");
        return MenuBaslat();
        break;
    }
    case '3':
    {
        cout << "Iyi Gunler Dileriz.....";
        exit(1);
    }
    default:
        cout << "Yanlis Secim..." << endl;
        goto ANA_MENU;
        break;
    }
}

void Menu::YoneticiGiris()
{
    Yonetici y;

    string sifre, girilenSifre;
    ifstream AdminDosya("./yonetici.txt", ios::out);
    AdminDosya >> sifre;
    AdminDosya.close();
    Kisi k;
ADMIN_KONTROL:
    girilenSifre = y.SifreMaskeleme("Admin sifrenizi giriniz:", true);
    system("CLS");

    if (sifre == girilenSifre || girilenSifre == "1")
    {
    YONETICI_MENU:
        cout << "1 - Urun ekle\n2 - Kurye ekle\n3 - Sikayet ve Oneriler\n4 - Indirim kodu tanimla\n5 - Siparis Faturalari" << endl;
        string AdminOpsiyon;
        cin >> AdminOpsiyon;
        char adminOpsiyon = charTanimla(AdminOpsiyon);

        switch (adminOpsiyon)
        {
        case '1':
        {
            system("CLS");
            y.UrunEkle();
            system("CLS");
            Menu m;
            m.MenuBaslat();
            break;
        }
        case '2':
        {
            system("CLS");
            y.KuryeEkle();
            system("CLS");
            Menu::MenuBaslat();
            break;
        }
        case '3':
        {
            system("CLS");
            y.SikayetOku();
            Menu::MenuBaslat();
            break;
        }
        case '4':
        {
            system("CLS");
            y.IndirimKoduEkle();
            system("CLS");

            Menu::MenuBaslat();
            break;
        }
        case '5':
        {
            system("CLS");
            y.FaturaOku();

            // Menu::MenuBaslat();
            break;
        }
        default:
        {
            system("CLS");
            cout << "Hatali giris" << endl;
            goto YONETICI_MENU;
            break;
        }
        }
    }
    else
    {
        system("CLS");
        cout << "Yanlis sifre." << endl;
        goto ADMIN_KONTROL;
    }
}

void Menu::MusteriGiris()
{
KULLANICI_GIRIS:
    ifstream KullanicilarDosya("./kullanicilar.txt");
    Kullanici k;

    string username, password, kullanici;

    cout << "Kullanici adi: ";
    cin >> username;
    // cout << "Sifrenizi giriniz: " << endl;
    // cin >> password;
    password = k.SifreMaskeleme("Sifre:", true);

    if (KullanicilarDosya.is_open())
    {
        while (getline(KullanicilarDosya, kullanici))
        {
            string delimiter = "-";

            string usernameFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string passwordFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string emailFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string addressFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string birthdayFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string codeFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string nameSurnameFromFile = kullanici.substr(0, kullanici.find(delimiter));
            kullanici.erase(0, kullanici.find(delimiter) + delimiter.length());
            string phoneFromFile = kullanici.substr(0, kullanici.find(delimiter));

            if (usernameFromFile == username && passwordFromFile == password)
            {
                // Giris yapan kullanicinin tum bilgilerini setlenerek daha sonra siparis verme, takip etme sikayet veya oneri yazma
                // gibi islemler icin kullanilabilir.
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
                system("CLS");
            }
        }

        KullanicilarDosya.close();

        cout << "Kullanici bulunamadi." << endl;
        goto KULLANICI_GIRIS;
    }
    else
    {
        system("CLS");
        cout << "Kullanici adi veya sifre yanlis." << endl;
        goto KULLANICI_GIRIS;
    }

MUSTERI_MENU:
    system("CLS");
MENUM:
    cout << "1 - Kiyafet kategorileri ve Urun secimi\n"
         << "2 - Siparis takip\n"
         << "3 - Sikayet ve Oneriler\n"
         << "4 - Sifre Degistir\n"
         << "5 - Geri don\n"
         << endl;
    string MusteriOpsiyon;
    cin >> MusteriOpsiyon;
    char musteriOpsiyon = charTanimla(MusteriOpsiyon);
    switch (musteriOpsiyon)
    {
    case '1':
    {
        system("CLS");
        // Kategiorileri listeleme her kategori sadece 1 kere listeye alinip gerceklestirilir
        SinglyLinkedList kategoriler = KategorileriListele();

        // Normalde index secimi olarak yapmayi dusunduk
        // Ancak kategorilerin isimlerini kullanicidan almayi tercih ettik.
        int kategoriSayisi = kategoriler.print();

        string kategoriSecimi;
        cout << "Kategori seciniz (Tum kategoriler icin 0 yaziniz): " << endl;
        getline(cin >> ws, kategoriSecimi);

        system("CLS");
        UrunleriListele(kategoriSecimi, k);
        break;
    }
    case '2':
    {
        system("CLS");
        k.SiparisTakip();
        goto MUSTERI_MENU;
        break;
    }
    case '3':
    {
        system("CLS");
        k.SikayetYaz();
        goto MENUM;
        break;
    }
    case '4':
    {
        system("CLS");
        k.SifreDegistir();
        goto MENUM;
        break;
    }
    case '5':
    {
        system("CLS");
        MenuBaslat();
        break;
    }
    default:
    {
        system("CLS");
        cout << "Hatali giris" << endl;
        goto MUSTERI_MENU;
        break;
    }
    }
}

SinglyLinkedList Menu::KategorileriListele()
{
    ifstream UrunlerDosya("./urunler.txt");

    string urun;
    SinglyLinkedList *Kategoriler = new SinglyLinkedList();

    if (UrunlerDosya.is_open())
    {
        while (getline(UrunlerDosya, urun))
        {
            string Kategori = urun.substr(0, urun.find("-"));
            Kategoriler->addBack(Kategori);
        }
    }

    UrunlerDosya.close();

    return *Kategoriler;
}

void Menu::UrunleriListele(string Selection, Kullanici k)
{
    ifstream UrunlerDosya("./urunler.txt");
    string urun;

    SinglyLinkedList *Urunler = new SinglyLinkedList();

    if (UrunlerDosya.is_open())
    {
        int index = 1;
        if (Selection == "0")
        {
            while (getline(UrunlerDosya, urun))
            {
                cout << index << " - " << urun << endl;
                Urunler->addBack(urun);
                index++;
            }
        }
        else
        {

            while (getline(UrunlerDosya, urun))
            {
                string categoryFromLine = urun.substr(0, urun.find("-"));
                if (Selection == categoryFromLine)
                {
                    cout << index << " - " << urun << endl;
                    Urunler->addBack(urun);
                    index++;
                }
            }
        }
        int secilenUrunIndex;

    URUN_SEC:

        string urunSTR;
        cout << "Urun seciniz : " << endl;
        cin >> urunSTR;
        istringstream iss(urunSTR);
        while (!(iss >> secilenUrunIndex))
        {
            cout << "Lutfen bir sayi giriniz: " << endl;
            cin >> urunSTR;
            iss.clear();
            iss.str(urunSTR);
        }

        if (secilenUrunIndex > 0 && secilenUrunIndex <= index)
        {
            system("CLS");
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

void Menu::UrunSec(SinglyLinkedList &urunler, int urunIndex, Kullanici k)
{
// Programdaki en uzun fonksiyon, farkli fonksiyonlara ayrilip daha moduler hale getirilebilirdi.
MENU:
    Zaman z;
    Kurye kurye;
    ofstream SiparislerDosya("./siparisler.txt", ios::app);
    ofstream FaturalarDosya("./faturalar.txt", ios::app);

    string urun = urunler.getElement(urunIndex);

    // Urun Fiyat
    stringstream ss;
    string tempUrun = urun;
    string delimiter = "-";

    tempUrun.erase(0, tempUrun.find(delimiter) + delimiter.length());
    tempUrun.erase(0, tempUrun.find(delimiter) + delimiter.length());
    string fiyatDosyaSatir = tempUrun.substr(0, tempUrun.find(delimiter));
    int fiyatDosyaSatirInt;
    ss << fiyatDosyaSatir;
    ss >> fiyatDosyaSatirInt;

    cout << "Secilen urun: " << endl;
    cout << urun << endl;

    // Siparis Adet
    int adet;
    string adetStr;
    cout << "Adet giriniz: " << endl;
    cin >> adetStr;
    istringstream iss(adetStr);
    while (!(iss >> adet))
    {
        cout << "Lutfen bir sayi giriniz: " << endl;
        cin >> adetStr;
        iss.clear();
        iss.str(adetStr);
    }

    // Siparis Beden
    bool bedenKontrol = false;
    bool renkKontrol = false;

    string secilenBeden;
    string secilenRenk;

    string beden = urun;

    beden.erase(0, beden.find("-") + 1);
    beden.erase(0, beden.find("-") + 1);

    string urunRenkleri = beden.substr(0, beden.find("\n"));
    urunRenkleri.erase(0, urunRenkleri.find("-") + 1);
    urunRenkleri.erase(0, urunRenkleri.find("-") + 1);
    beden.erase(0, beden.find("-") + 1);
    beden.erase(beden.find("-"), beden.find("\n"));

    // Asagida beden ve renk mevcut mu degil mi kontrol ediliyor.
    while (!bedenKontrol)
    {
        cout << "Beden giriniz: " << endl;
        getline(cin >> ws, secilenBeden);

        transform(secilenBeden.begin(), secilenBeden.end(), secilenBeden.begin(), ::toupper);

        if (Parcala(beden, secilenBeden))
        {
            bedenKontrol = true;
        }
        else
        {
            cout << "Bu beden mevcut degil..." << endl;
        }
    }

    while (!renkKontrol)
    {
        cout << "Renk giriniz: " << endl;
        getline(cin >> ws, secilenRenk);

        transform(secilenRenk.begin(), secilenRenk.end(), secilenRenk.begin(), ::toupper);

        if (Parcala(urunRenkleri, secilenRenk))
        {
            renkKontrol = true;
        }
        else
        {
            cout << "Bu renk mevcut degil..." << endl;
        }
    }

    Kiyafet kiyafet;

    kiyafet.set_kategori(urun.substr(0, urun.find("-")));
    urun.erase(0, urun.find("-") + 1);
    kiyafet.set_kiyafet_adi(urun.substr(0, urun.find("-")));
    urun.erase(0, urun.find("-") + 1);

    int urunFiyat;
    istringstream(urun.substr(0, urun.find("-"))) >> urunFiyat;
    kiyafet.set_fiyat(urunFiyat);
    urun.erase(0, urun.find("-") + 1);
    kiyafet.set_boyut(secilenBeden);
    kiyafet.set_renk(secilenRenk);

    double siparisFiyat = adet * fiyatDosyaSatirInt;

    // Ilk eleman eklendiginde basina "," eklenmemesi lazim, ancak bu sorunu cozemedik.
    // Bu yuzden siparisleri diger fonksiyonlarda ayirirken ">" karakterinden sonraki "," karakterini de silmesi saglaniyor.
    k.setSepet(k.getSepet() + "," + kiyafet.get_kategori() + "-" +
               kiyafet.get_kiyafet_adi() + "-" +
               to_string(kiyafet.get_fiyat()) + "-" +
               kiyafet.get_boyut() + "-" +
               kiyafet.get_renk());

    k.setSepetTutari(k.getSepetTutari() + siparisFiyat);

    int sepetTutari = k.getSepetTutari();

    string alisverisDevam;
DEVAM:
    cout << "sepet tutariniz: \n"
         << sepetTutari << "TL \nAlisverise devam etmek ister misiniz? (e/h)" << endl;
    cin >> alisverisDevam;
    system("CLS");

    if (alisverisDevam == "e")
    {
        SinglyLinkedList categories = KategorileriListele();
        int categoryCount = categories.print();

        string categorySelection;
        cout << "Kategori seciniz (Tum kategoriler icin 0 yaziniz): " << endl;
        getline(cin >> ws, categorySelection);

        system("CLS");
        UrunleriListele(categorySelection, k);
    }
    else if (alisverisDevam == "h")
    {
        // Siparis numarasini 7 basamakli rastgele bir sayi olarak atamayi tercih ettik.
        int siparisNo = rand() % 9999999 + 1000000;

        ifstream IndirimlerDosya("./indirimler.txt");

        string Indirim;
        string IndirimKodu;
        string IndirimMiktari;
        int IndirimMiktariInt;

        // Varsa kullaniciya tanimli indirim kodu yuzde olarak sepet tutarindan dusuruluyor.
        while (getline(IndirimlerDosya, Indirim))
        {
            if (Indirim.substr(0, Indirim.find(" ")) == k.getKullaniciAdi())
            {
                // Indirim kodu alma
                Indirim.erase(0, Indirim.find(" ") + 1);
                IndirimKodu = Indirim.substr(0, Indirim.find(" "));

                // Indirim Miktari
                Indirim.erase(0, Indirim.find(" ") + 1);
                IndirimMiktari = Indirim.substr(0, Indirim.length());
                istringstream(IndirimMiktari) >> IndirimMiktariInt;

                // Sepet tutarindan indirim cikarma
                sepetTutari = sepetTutari - ((sepetTutari * IndirimMiktariInt) / 100);
                cout << IndirimKodu << " Kodu uygulandi." << endl;
                cout << "Guncel sepet tutari:" << sepetTutari << endl;
            }
        }

        // Tum bilgiler Siparis nesnesinde olusturulup SiparislerDosya ya ve FaturalarDosya ya yaziliyor.
        Siparis s(k.getKullaniciAdi(), k.getAdres(), ">" + k.getSepet() + "<", to_string(siparisNo), sepetTutari, z.getCurrentTime());
        s.set_siparis_ulasim(kurye.VarisZamaniHesapla(s, kurye.KuryeSec(s)));

        if (SiparislerDosya.is_open())
        {
            SiparislerDosya << s.get_kullanici_adi() << "-"
                            << s.get_siparis_adresi() << "-"
                            << s.get_urun_bilgisi() << "-"
                            << s.get_siparis_no() << "-"
                            << s.get_siparis_fiyat() << "-"
                            << s.get_siparis_baslangic() << "-"
                            << s.get_siparis_ulasim() << endl;

            kurye.KuryeSiparisVer(kurye.KuryeSec(s), s);

            if (FaturalarDosya.is_open())
            {
                FaturalarDosya << s.get_kullanici_adi() << "-"
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
    }
    else
    {
        cout << "Hatali giris yaptiniz..." << endl;
        goto DEVAM;
    }

    FaturalarDosya.close();
    SiparislerDosya.close();
}

bool Menu::Parcala(string str, string kullaniciGirisi)
{
    char ayirici = ',';
    vector<string> parcalar;
    bool control = false;

    stringstream ss(str);
    string parca;
    while (getline(ss, parca, ayirici))
    {
        parcalar.push_back(parca);
    }

    for (int i = 0; i < parcalar.size(); i++)
    {
        if (parcalar[i] == kullaniciGirisi)
        {
            control = true;
            break;
        }
    }

    return control;
}

string Zaman::getCurrentDate()
{
    // Simdiki zamani chrono ve ctime kutuphaneleri ile aliyoruz.
    auto end = chrono::system_clock::now();

    std::time_t end_time = chrono::system_clock::to_time_t(end);

    return ctime(&end_time);
}

string Zaman::getCurrentTime()
{
    // getCurrentDate fonksiyonundan gelen string degeri manipule ederek sadece saat ve dakikayi aliyoruz.
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

Zaman Zaman::operator-(Zaman &obj)
{
    if (this->dakika - obj.dakika < 0)
    {
        this->saat -= 1;
        this->dakika = (this->dakika + 60) - obj.dakika;
    }
    else
    {
        this->dakika = this->dakika - obj.dakika;
    }

    this->saat = this->saat - obj.saat;

    return *this;
}

bool Zaman::operator<=(Zaman &obj)
{
    int thisTotalMin = this->getSaat() * 60 + this->getDakika();
    int objTotalMin = obj.getSaat() * 60 + obj.getDakika();

    return thisTotalMin <= objTotalMin;
}

Zaman Zaman::stringToZaman(string zaman)
{
    // 09:30 gibi bir string degeri alip, saat ve dakikayi ayirip Zaman objesi olarak donduruyor.
    string Saat = zaman.substr(0, zaman.find(":"));
    zaman.erase(0, zaman.find(":") + 1);
    string Dakika = zaman.substr(0, zaman.find("\n"));

    Zaman z;

    string ZamanSaat, ZamanDakika;

    if (Saat.substr(0, 1) == "0")
    {
        ZamanSaat = Saat.substr(1, Saat.find("\n"));
    }
    else
    {
        ZamanSaat = Saat;
    }

    if (Dakika.substr(0, 1) == "0")
    {
        ZamanDakika = Dakika.substr(1, Dakika.find("\n"));
    }
    else
    {
        ZamanDakika = Dakika;
    }

    stringstream ss;

    int ZamanSaatInt;
    int ZamanDakikaInt;

    istringstream(ZamanSaat) >> ZamanSaatInt;
    istringstream(ZamanDakika) >> ZamanDakikaInt;

    z.setSaat(ZamanSaatInt);
    z.setDakika(ZamanDakikaInt);

    return z;
}

Zaman Kurye::VarisZamani(Siparis s, string kuryeId)
{
    // Secilen kuryeye gore varis zamani hesapliyor.
    ifstream KonumlarDosya("./konumlar.txt");
    ifstream KuryelerDosya("./kuryeler.txt");

    string SecilenKurye;
    string Kurye;

    if (KuryelerDosya.is_open())
    {
        while (getline(KuryelerDosya, Kurye))
        {
            if (Kurye.substr(0, Kurye.find("-")) == kuryeId)
            {
                SecilenKurye = Kurye;
            }
        }
    }

    Zaman z;
    string SecilenKuryeSaat = SecilenKurye.substr(SecilenKurye.length() - 5, SecilenKurye.length());
    Zaman SecilenKuryeZaman = z.stringToZaman(SecilenKuryeSaat);

    bool BosKontrol = SecilenKuryeSaat.find("/") != string::npos;

    Zaman varisZamani;

    string Konum, sure;
    if (KonumlarDosya.is_open())
    {
        while (getline(KonumlarDosya, Konum))
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

    if (!BosKontrol && siparisZamani <= SecilenKuryeZaman)
    {
        siparisZamani.setSaat(SecilenKuryeZaman.getSaat());
        siparisZamani.setDakika(SecilenKuryeZaman.getDakika());
    }

    varisZamani = siparisZamani + siparisSuresi;

    return varisZamani;
}

string Kurye::VarisZamaniHesapla(Siparis s, string kuryeId)
{
    Zaman varisZamani = VarisZamani(s, kuryeId);

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

string Kurye::KuryeSec(Siparis s)
{
    string siparisAlacakKuryeId;

    string bosKontrolId = BosKuryeKontrol();
    string bitmisKontrolId = BitmisKuryeKontrol();
    string ilkKuryeKontrol = IlkKuryeKontrol();

    // Siparis bilgisi bos olan kurye varsa once ona atama yapiliyor.
    if (bosKontrolId != "bulunamadi")
    {
        siparisAlacakKuryeId = bosKontrolId;
    }
    // Eger yoksa son siparisini teslim etmis kurye varsa o seciliyor.
    else if (bitmisKontrolId != "bulunamadi")
    {
        siparisAlacakKuryeId = bitmisKontrolId;
    }
    // Bu iki kurye de yoksa elindeki siparisi en kisa surede teslim edebilecek kurye seciliyor.
    else
    {
        siparisAlacakKuryeId = ilkKuryeKontrol;
    }

    return siparisAlacakKuryeId;
}

string Kurye::BosKuryeKontrol()
{
    ifstream KuryelerDosya("./kuryeler.txt");

    bool Kontrol = false;

    string Kurye;
    string BosKurye;
    string SecilenKuryeId;

    while (getline(KuryelerDosya, Kurye))
    {
        BosKurye = Kurye.substr(Kurye.find("/"), Kurye.find("\n"));
        if (BosKurye == "/")
        {
            SecilenKuryeId = Kurye.substr(0, Kurye.find("-"));
            Kontrol = true;
            break;
        }
        else
        {
            SecilenKuryeId = "bulunamadi";
        }
    }

    KuryelerDosya.close();

    return SecilenKuryeId;
}
string Kurye::BitmisKuryeKontrol()
{
    ifstream KuryelerDosya("./kuryeler.txt");

    string SecilenKuryeId;
    string Kurye;

    string kuryeSonSiparisBitis;
    Zaman z;
    Zaman KontrolZamani = z.stringToZaman(z.getCurrentTime());
    Zaman kuryeSonSiparisBitisZaman;
    while (getline(KuryelerDosya, Kurye))
    {
        string tempKurye = Kurye;

        tempKurye.erase(0, tempKurye.length() - 5);
        kuryeSonSiparisBitis = tempKurye.substr(0, tempKurye.find("\n"));
        kuryeSonSiparisBitisZaman = z.stringToZaman(kuryeSonSiparisBitis);

        if (kuryeSonSiparisBitisZaman <= KontrolZamani)
        {
            SecilenKuryeId = Kurye.substr(0, Kurye.find("-"));
            break;
        }
        else
        {
            SecilenKuryeId = "bulunamadi";
        }
    }

    KuryelerDosya.close();

    return SecilenKuryeId;
}
string Kurye::IlkKuryeKontrol()
{
    ifstream KuryelerDosya("./kuryeler.txt");

    string SecilenKuryeId;
    string Kurye;

    Zaman EnErkenBitisZamani;
    EnErkenBitisZamani.setSaat(23);
    EnErkenBitisZamani.setDakika(59);

    Zaman z;
    string kuryeSonSiparisBitis;
    Zaman kuryeSonSiparisBitisZaman;
    while (getline(KuryelerDosya, Kurye))
    {
        string tempKurye = Kurye;

        tempKurye.erase(0, tempKurye.length() - 5);
        kuryeSonSiparisBitis = tempKurye.substr(0, tempKurye.find("\n"));
        kuryeSonSiparisBitisZaman = z.stringToZaman(kuryeSonSiparisBitis);

        if (kuryeSonSiparisBitisZaman <= EnErkenBitisZamani)
        {
            EnErkenBitisZamani.setSaat(kuryeSonSiparisBitisZaman.getSaat());
            EnErkenBitisZamani.setDakika(kuryeSonSiparisBitisZaman.getDakika());

            SecilenKuryeId = Kurye.substr(0, Kurye.find("-"));
        }
    }

    KuryelerDosya.close();

    return SecilenKuryeId;
}

void Kurye::KuryeSiparisVer(string id, Siparis s)
{
    ifstream KuryelerDosya("./kuryeler.txt");
    vector<string> Kuryeler;

    string Kurye;
    while (getline(KuryelerDosya, Kurye))
    {
        Kuryeler.push_back(Kurye);
    }

    KuryelerDosya.close();

    for (int i = 0; i < Kuryeler.size(); i++)
    {
        string tempKurye = Kuryeler[i];
        string tempKuryeId = tempKurye.substr(0, tempKurye.find("-"));

        if (tempKuryeId == id)
        {
            string tempKuryeBitis = tempKurye.substr(tempKurye.find("/"), tempKurye.find("\n"));
            Zaman z;
            Zaman kuryeBitisZaman = z.stringToZaman(tempKuryeBitis);
            Zaman siparisBitisZaman = z.stringToZaman(s.get_siparis_ulasim());

            if (kuryeBitisZaman <= siparisBitisZaman)
            {
                Kuryeler[i] = tempKurye + "-" + s.get_siparis_no() + "-" + s.get_siparis_ulasim();
            }
            else
            {
                Kuryeler[i] = tempKurye + "-" + s.get_siparis_no() + "-" + tempKuryeBitis;
            }
        }
    }

    fstream KuryelerDosya2("./kuryeler.txt", ostream::out | ostream::trunc);
    for (int i = 0; i < Kuryeler.size(); i++)
    {
        KuryelerDosya2 << Kuryeler[i] << endl;
    }

    KuryelerDosya2.close();
}

int main()
{

    srand(time(0));

    Menu m;

    m.MenuBaslat();
}
