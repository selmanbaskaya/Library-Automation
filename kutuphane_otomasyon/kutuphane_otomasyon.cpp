#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Kitap
{
	public:

		string KitapAdi;
		string KitapYazariAdi;
		string KitapYazariSoyadi;
		string KitapYayýmevi;
		int	   KitapBasimYili;
		int    KitapAdeti;

		void KitapBilgi();
		void KitapYazdir();
		void KitapListele();
};

void Kitap::KitapBilgi()
{
	setlocale(LC_ALL, "Turkish");
	cout.setf(ios::right);

	cout<<""<<endl;

	cout<<setw(15)<<" ""Kitap Adýný Giriniz: ";
	cin>>KitapAdi;

	cout<<setw(15)<<" ""Kitabýn Yazarýnýn Adýný Giriniz: ";
	cin>>KitapYazariAdi;

	cout<<setw(15)<<" ""Kitabýn Yazarýnýn Soyadýný Giriniz: ";
	cin>>KitapYazariSoyadi;

	cout<<setw(15)<<" ""Kitabýn Yayýmevini Giriniz: ";
	cin>>KitapYayýmevi;

	cout<<setw(15)<<" ""Kitabýn Basým Yýlýný Giriniz: ";
	cin>>KitapBasimYili;

	cout<<setw(15)<<" ""Kitabýn Adetini Giriniz: ";
	cin>>KitapAdeti;
}

void Kitap::KitapYazdir()
{
	setlocale(LC_ALL, "Turkish");
	cout.setf(ios::right);

	cout<<setw(15)<<"Kitabýn Adý: "<<KitapAdi<<endl;

	cout<<setw(15)<<"Kitabýn Yazarýnýn Adý: "<<KitapYazariAdi<<endl;

	cout<<setw(15)<<"Kitabýn Yazarýnýn Soyadý: "<<KitapYazariSoyadi<<endl;

	cout<<setw(15)<<"Kitabýn Yayýmevi: "<<KitapYayýmevi<<endl;

	cout<<setw(15)<<"Kitabýn Basým Yýlý: "<<KitapBasimYili<<endl;

	cout<<setw(15)<<"Kitabýn Adeti: "<<KitapAdeti<<endl;
}

class Kutuphane
{
	public:
		Kitap Kitaplar[200];

		int KitapSayisi;

		fstream dosya;

		Kutuphane()
		{
			KitapSayisi=0;

			dosya.open("Du_Kutuphane.txt", ios::out|ios::in|ios::app);

			dosya.setf(ios::left);
		}

		void KitapEkle()
		{
			Kitaplar[KitapSayisi].KitapBilgi();

			//Kullanýmý kýsaltmak için "Kitaplar[KitapSayisi]"'ný bir baþka deðiþkene yollayacaðým.

			Kitap x =Kitaplar[KitapSayisi];

			dosya<<setw(15)<<x.KitapAdi
				<<setw(15)<<x.KitapYazariAdi
				<<setw(15)<<x.KitapYazariSoyadi
				<<setw(15)<<x.KitapYayýmevi
				<<setw(15)<<x.KitapBasimYili
				<<setw(15)<<x.KitapAdeti<<endl;
		}

		void KitapBul(string KitapAdi)
		{
			fstream dosya;

			dosya.open("Du_Kutuphane.txt", ios::out|ios::in|ios::app);

			Kitap x;

			while (dosya.eof()!=true)
			{
				cout<<""<<endl;

				dosya>>x.KitapAdi;

				dosya>>x.KitapYazariAdi;

				dosya>>x.KitapYazariSoyadi;

				dosya>>x.KitapYayýmevi;

				dosya>>x.KitapBasimYili;

				dosya>>x.KitapAdeti;

				if (x.KitapAdi==KitapAdi)
				{
					x.KitapYazdir();
				}
			}

			dosya.close();

		}

		void KitapListele()
			{
				ifstream dosya;
				dosya.open("DU_Kutuphane.txt");
				char veri;
				while(!dosya.eof())
				{
					dosya.get(veri);
					cout<<veri;
				}
					dosya.close();
			}


		void KitapSil(string KitapAd)
                {
                        Kitap kitap;
                        char veri;
                        fstream dosya;
                        dosya.open("Du_Kutuphane.txt", ios::in | ios::app);
                        fstream dosya0;
                        dosya.open("Du_Kutuphane0.txt", ios::in | ios::out | ios::app);

                        while (dosya>>kitap.KitapAdi>>kitap.KitapYazariAdi
                                   >>kitap.KitapYazariSoyadi
                                   >>kitap.KitapYayýmevi
                                   >>kitap.KitapBasimYili
                                   >>kitap.KitapAdeti)
                        {
                                if (KitapAd != kitap.KitapAdi)
                                {
                                        Kitap x =Kitaplar[KitapSayisi];

                                        dosya0<<setw(15)<<x.KitapAdi
                                        <<setw(15)<<x.KitapYazariAdi
                                        <<setw(15)<<x.KitapYazariSoyadi
                                        <<setw(15)<<x.KitapYayýmevi
                                        <<setw(15)<<x.KitapBasimYili
                                        <<setw(15)<<x.KitapAdeti<<endl;
                                }
                        }

                        dosya.close();

                        remove("Du_Kutuphane.txt");

                        dosya0.close();

                        rename("Du_Kutuphane0.txt","Du_Kutuphane.txt");
                }
};



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Turkish");

	int secim;
	char karar;
	string ara;

	Kutuphane DU;

	do
	{   cout<<endl<<"	   			      ""Düzce Üniversitesi Kütüphane Bilgi Sistemi"<<endl<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"               ""MENÜ"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<" * ""Rafa Kitap Eklemek Ýçin     -> 1"<<endl;
		cout<<" * ""Raftaki Kitabý Bulmak Ýçin  -> 2"<<endl;
		cout<<" * ""Raftan Kitap Silmek Ýçin    -> 3"<<endl;
		cout<<" * ""Sistemden Çýkmak Ýçin       -> 4"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<" ""Hangi Ýþlemi Yapmak Ýstiyorsunuz? : ";
		cin>>secim;

		if (secim==1)
		{
			DU.KitapEkle();

			cout<<endl<<"Kitabýnýz Rafa Baþarýyla Eklenmiþtir.";
		}
	
		else if (secim==2)
		{
			cout<<""<<endl;

			cout<<"         ""Raftaki Kitaplarýmýz"<<endl;;
			cout<<"---------------------------------------"<<endl;
			
			DU.KitapListele();

			cout<<endl<<" ""Aramak Ýstediðiniz Kitabýn Adýný Giriniz: ";
			cin>>ara;		

			DU.KitapBul(ara);

		}

		else if (secim==3)
		{
			cout<<endl<<"   ""Sistemimiz Size Daha Ýyi Hizmet Verebilmek Ýçin Yenileniliyor."
				<<endl<<"   ""Anlayýþýnýz Ýçin Teþekkür Ederiz."<<endl;
		}

		else if (secim==4)
		{
			exit (1);
		}

		else
		{
			cout<<endl<<"   ""Yanlýþ Bir Seçim Yaptýnýz."<<endl; 

			cout<<endl<<"   ""Tekrar Seçim Yapmak Ýster Misiniz? (E / e) : ";
  			cin >> karar; 

  			if (karar == 'E' || karar=='e') 
			{
				continue; 
			}
  			
  			else 
			{
				break; 
			}	
		}

  		cout<<endl<<"   ""Baþka iþlem Yapmak Ýster Misiniz? (E / e) : ";
  		cin >> karar; 

  		if (karar == 'E' || karar=='e') 
		{
			continue; 
		}
  			
  		else 
		{
			break; 
		}	

	} while (1);


	system("pause");
	return 0;
}