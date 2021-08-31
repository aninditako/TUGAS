#include <iostream> 
#include <conio.h> //getch untuk berhenti saat mengulangi input dan sebelum pembayaran
#include <windows.h> //system cls
#include <fstream> //untuk file
#include <string.h> 
#include <string> 
#include <iomanip> 

using namespace std; 

int j, k, banyak , jum;
int byr, kembalian;
int totPem = 0;
string user, pass, user1, pass1;
char log, log2, lagi;

struct dataPesan
{
  string nama [100], alamat [100]; 
  string notelp;
}dp;

struct dataPen 
{
    string nama[30], umur[30];
    string panggil[15];
}dt; 

struct pesawat
{
    int tiket;
    float diskon;
    string tujuan, kelas, kPenerbangan;
    char pes, pil, pil2;
}p;


void yia()
{
	cout<<"==================================================================="<<endl;
    cout<<"                  YOGYAKARTA INTERNATIONAL AIRPORT                 "<<endl;
    cout<<"==================================================================="<<endl;
}

void login()
{
		yia();
		cout<<endl<<" Klik 'enter' untuk melakukan pendaftaran akun"<<endl;
		cout<<endl<<endl;
		for (k=1; k<=1; k++) 
        {
			cin.ignore();
			cout<<"  Nama Lengkap Pemesan    : "; getline(cin, dp.nama[k]);
			cout<<"  Alamat Pemesan          : "; getline(cin, dp.alamat[k]);
			cout<<"  No telp                 : "; cin>>dp.notelp;
			cout<<"  Username                : "; cin>>user;
			cout<<"  Password                : "; cin>>pass;
			cout<<endl<<endl;
        }
		Sleep(500);
		system ("cls");
			do
			{
				cout<<endl<<endl<<"||------------------------------LOGIN-----------------------------||"<<endl<<endl;
				cout<<"Username\t: "; cin>>user1;
				cout<<"Password\t: "; cin>>pass1;
				if (user1==user && pass1==pass)
				{
					cout<<"\nSelamat, Login Berhasil\n";
				}
				else
				{
					cout<<endl<<"LOGIN GAGAL " <<endl;
					cout<<"Ingin Login Kembali? (y/n) : "; cin>>log2;
					if (log2=='n' || log2=='N')
					{
						exit(0);
					}
				}
			}
			while (log2=='Y' || log2=='y');
}

void tujuan()
{
	cout<<"\t|---------------------------------------------------|"<<endl;
    cout<<"\t|              TUJUAN KEBERANGKATAN YIA             |\n";
    cout<<"\t|---------------------------------------------------|"<<endl;
    cout<<"\t|  1. YOGYAKARTA-JAKARTA                            |\n";
    cout<<"\t|  2. YOGYAKARTA-SURABAYA                           |\n";
    cout<<"\t|  3. YOGYAKARTA-BALI                               |\n";
    cout<<"\t|  4. YOGYAKARTA-MAKASSAR                           |\n";
    cout<<"\t|  5. YOGYAKARTA-BATAM                              |\n";
    cout<<"\t|---------------------------------------------------|"<<endl;
}

string tujuan2() //untuk output hasil dari pemilihan tujuan
{
    if (p.pil=='1')
    {
        p.tujuan="YOGYAKARTA-JAKARTA";
    }
    else if (p.pil=='2')
    {
        p.tujuan="YOGYAKARTA-SURABAYA";
    }
    else if (p.pil=='3')
    {
        p.tujuan="YOGYAKARTA-BALI";
    }
    else if (p.pil=='4')
    {
        p.tujuan="YOGYAKARTA-MAKASSAR";
    }
    else if (p.pil=='5')
    {
        p.tujuan="YOGYAKARTA-BATAM";
    }
    return p.tujuan;
}

void jenis()
{
	cout<<endl;
    cout<<"\t================================================================="<<endl;
    cout<<"\t| No.|       Pesawat                     Harga Tiket             |"<<endl;
    cout<<"\t=================================================================|"<<endl;
    cout<<"\t| 1. |   Garuda Indonesia               Rp. 1.800.000,-          |"<<endl;
    cout<<"\t| 2. |   Citilink Airlines              Rp. 1.700.000,-          |"<<endl;
    cout<<"\t| 3. |   Air Asia                       Rp. 1.600.000,-          |"<<endl;
    cout<<"\t| 4. |   Lion Air                       Rp. 1.500.000,-          |"<<endl;
    cout<<"\t================================================================="<<endl;
}

string kode() //kode penerbangan saat diprint out di retail
{
    if (p.pes=='1')
    {
        if (p.pil=='1')
        {
            p.kPenerbangan="SI-J";
        }
        else if (p.pil=='2')
        {
            p.kPenerbangan="SI-S";
        }
        else if (p.pil=='3')
        {
            p.kPenerbangan="SI-BL";
        }
        else if (p.pil=='4')
        {
            p.kPenerbangan="SI-M";
        }
        else if (p.pil=='5')
        {
            p.kPenerbangan="SI-BT";
        }
    }
    else if (p.pes== '2')
    {
        if (p.pil=='1')
        {
            p.kPenerbangan = "YA-J";
        }
        else if (p.pil=='2')
        {
            p.kPenerbangan = "YA-S";
        }
        else if (p.pil=='3')
        {
            p.kPenerbangan = "YA-BL";
        }
        else if (p.pil=='4')
        {
            p.kPenerbangan = "YA-M";
        }
        else if (p.pil=='5')
        {
            p.kPenerbangan = "YA-BT";
        }
    }
    else if (p.pes== '3')
    {
        if (p.pil=='1')
        {
            p.kPenerbangan = "SA-J";
        }
        else if (p.pil=='2')
        {
            p.kPenerbangan = "SA-S";
        }
        else if (p.pil=='3')
        {
            p.kPenerbangan = "SA-BL";
        }
        else if (p.pil=='4')
        {
            p.kPenerbangan = "SA-M";
        }
        else if (p.pil=='5')
        {
            p.kPenerbangan = "SA-BT";
        }
    }
    else if (p.pes == '4')
    {
        if (p.pil=='1')
        {
            p.kPenerbangan = "LA-J";
        }
        else if (p.pil=='2')
        {
            p.kPenerbangan = "LA-S";
        }
        else if (p.pil=='3')
        {
            p.kPenerbangan = "LA-BL";
        }
        else if (p.pil=='4')
        {
            p.kPenerbangan = "LA-M";
        }
        else if (p.pil=='5')
        {
            p.kPenerbangan = "LA-BT";
        }
    }
    return p.kPenerbangan;
}

string kelas2() //untuk output di ringkasan
{
    if (p.pil2=='1')
    {
        p.kelas="Ekonomi";
    }
    else if (p.pil2=='2')
    {
        p.kelas="Bisnis";
    }
    return p.kelas;
}

void kelas()
{
	cout<<"\n\t|----------------------------|";
	cout<<"\n\t|        Kelas Pesawat       |";
	cout<<"\n\t|----------------------------|";
	cout<<"\n\t|  1. Ekonomi                |";
	cout<<"\n\t|  2. Bisnis                 |";
	cout<<"\n\t|----------------------------|"<<endl;
}


void kettiket () // output keterangan saat pemilihan kelas pesawat
{
    ulang:
    cout<<"  Silakan Pilih Kelas Pesawat : "; cin>>p.pil2 ;
    if (p.pil2 =='1')
        {
            cout<<"   (Tiket Regular, tidak ada tambahan biaya)" << endl;
        }
    else if (p.pil2 =='2')
        {
            cout<<"   (Tambahan biaya Rp. 500.000,-)" << endl;
        }
    else
        {
        	cout<<"\tInput yang anda masukan salah\n";
            cout<<"Tekan ENTER untuk kembali\n";
            getch();
            goto ulang;
        }
}

int hargaTiket2()
{
	if (p.pes=='1')
    {
        if (p.pil2=='1')
        {
            p.tiket=1800000*jum;
        }
        else if (p.pil2=='2')
        {
            p.tiket=(1800000+500000)*jum;
        }
    }
    if (p.pes=='2')
    {
        if (p.pil2=='1')
        {
            p.tiket=1700000*jum;
        }
        else if (p.pil2=='2')
        {
            p.tiket=(1700000+500000)*jum;
        }
    }
    if (p.pes=='3')
    {
        if (p.pil2=='1')
        {
            p.tiket=1600000*jum;
        }
        else if (p.pil2=='2')
        {
            p.tiket=(1600000+500000)*jum;
        }
    }
    if (p.pes=='4')
    {
        if (p.pil2=='1')
        {
            p.tiket=1500000*jum;
        }
        else if (p.pil2=='2')
        {
            p.tiket=(1500000+500000)*jum;
        }
    }
    return p.tiket;
}

float diskon2()
{
	if (hargaTiket2()>15000000)
    {
        p.diskon=hargaTiket2()*0.4;
    }
    else if (hargaTiket2()>7500000 && hargaTiket2()<=15000000)
    {
        p.diskon=hargaTiket2()*0.25;
    }
    else if (hargaTiket2()>5000000 && hargaTiket2()<=7500000)
    {
        p.diskon=hargaTiket2()*0.15;
    }
    else
    {
        p.diskon=0;
    }
    return p.diskon;
}

int hargaTiket()
{
	ulang3:
	cout<<"  Silakan pilih Pesawat : "; cin>>p.pes;
    if (p.pes =='1')
    {
        if (p.pil2 =='1')
        {
            cout<<"Harga Tiket Garuda Indonesia dengan kelas Ekonomi Rp "<<1800000;
        }
        else if (p.pil2 =='2')
        {
            cout<<"Harga Tiket Garuda Indonesia dengan kelas Bisnis Rp "<<1800000+500000;
        }
        
        
    }
    else if (p.pes =='2')
    {
        if (p.pil2 =='1')
        {
            cout<<"Harga Tiket Citilink Airlines dengan kelas Ekonomi Rp "<<1700000+500000;
        }
        else if (p.pil2 =='2')
        {
            cout<<"Harga Tiket Citilink Airlines dengan kelas Bisnis Rp "<<1700000+500000;
        }
    }
    else if (p.pes =='3')
    {
        if (p.pil2 =='1')
        {
            cout<<"Harga Tiket Air Asia dengan kelas Ekonomi Rp "<<1600000+500000;
        }
        else if (p.pil2 =='2')
        {
            cout<<"Harga Tiket Air Asia dengan kelas Bisnis Rp "<<1600000+500000;
        }
    }
    else if (p.pes =='4')
    {
        if (p.pil2 =='1')
        {
            cout<<"Harga Tiket Lion Air dengan kelas Ekonomi Rp "<<1500000+500000;
        }
        else if (p.pil2 =='2')
        {
            cout<<"Harga Tiket Lion Air dengan kelas Bisnis Rp "<<1500000+500000;
        }
    }
    else if (p.pes != '1' ||p.pes != '2' || p.pes != '3' || p.pes != '4'  )
    {
    	cout<<"\tInput yang anda masukan salah\n";
        cout<<"Tekan ENTER untuk kembali\n";
        getch();
        goto ulang3;
	}
}

float diskon()
{
    if (hargaTiket2()>15000000)
    {
        p.diskon =hargaTiket2()*0.4;
        cout<<" Selamat anda mendapatkan diskon 40% sebesar : Rp "<<p.diskon;
    }
    else if (hargaTiket2()>7500000 && hargaTiket2()<=15000000)
    {
        p.diskon =hargaTiket2()*0.25;
        cout<<" Selamat anda mendapatkan diskon 25% sebesar : Rp "<<p.diskon;
    }
    else if (hargaTiket2()>5000000 && hargaTiket2()<=7500000)
    {
        p.diskon =hargaTiket2()*0.15;
        cout<<" Selamat anda mendapatkan diskon 40% sebesar : Rp "<<p.diskon;
    }
    else
    {
        p.diskon =0;
    }
    return p.diskon ;
}

int total() //rumus total harga tiket
{
    totPem=hargaTiket2()-diskon2();
    return totPem;
}

void akhir() //ringkasan pesanan
{
    for (k=1; k<=1; k++) 
    {        
		cout<<"   Pemesan atas nama "<<dp.nama[k]<<" membeli "<<jum<<" tiket dengan tujuan "<<tujuan2();
        cout<<"\n   menggunakan pesawat kode "<<kode()<<" kelas "<<kelas2();
		cout<<"\n\t\t\t\t\tTotal harga Rp. "<<total()<<",-"<<endl;
	}
}

void cetakTabel () //print retail
{
    ofstream file ("Retail.txt");
    cout<<endl;
    if (!file.is_open()){
        cout<<"Tidak bisa membuka file";
    }
    else {
            cout<<endl;
            cout<<"==========================================================================================================================="<<endl;
            file<<"==========================================================================================================================="<<endl;
            cout<<" No. |           Nama Pemesan        |           Tujuan            |    Pesawat   |      Kelas     |        Harga         |"<<endl;
            file<<" No. |           Nama Pemesan        |           Tujuan            |    Pesawat   |      Kelas     |        Harga         |"<<endl;
            cout<<"==========================================================================================================================="<<endl;
            file<<"==========================================================================================================================="<<endl;
           

            for (k=1; k<=1; k++)
            {
                cout<<setiosflags(ios::right)<<setw(3)<<k<<setiosflags(ios::right)<<setw(30)<<dp.nama[k];
                file<<setiosflags(ios::right)<<setw(3)<<k<<setiosflags(ios::right)<<setw(30)<<dp.nama[k];
                for (j=1; j<=1; j++)
                {
                    totPem=totPem + total();
                    cout<<setiosflags(ios::left)<<setw(26)<<tujuan2()<<setiosflags(ios::left)<<setw(16)<<kode();
                    file<<setiosflags(ios::left)<<setw(26)<<tujuan2()<<setiosflags(ios::left)<<setw(16)<<kode();
                    cout<<setiosflags(ios::left)<<setw(17)<<kelas2()<<setiosflags(ios::left)<<setw(14)<<"Rp. "<<total()<<",-"<<setiosflags(ios::left)<<setw(8)<<"|"<<endl;
                    file<<setiosflags(ios::left)<<setw(17)<<kelas2()<<setiosflags(ios::left)<<setw(14)<<"Rp. "<<total()<<",-"<<setiosflags(ios::left)<<setw(8)<<"|"<<endl;
                }
                cout<<"==========================================================================================================================="<<endl;
                file<<"==========================================================================================================================="<<endl;
                cout<<setiosflags(ios::right)<<setw(80)<<"Total"<<setiosflags(ios::left)<<setw(6)<<"Rp. "<<totPem<<",-"<<endl;
                file<<setiosflags(ios::right)<<setw(80)<<"Total"<<setiosflags(ios::left)<<setw(6)<<"Rp. "<<totPem<<",-"<<endl;
                cout<<setiosflags(ios::right)<<setw(80)<<"Bayar"<<setiosflags(ios::left)<<setw(6)<<"Rp. "; cin>>byr;
                file<<setiosflags(ios::right)<<setw(80)<<"Bayar"<<setiosflags(ios::left)<<setw(6)<<"Rp. "<<byr<<",-"<<endl;
                kembalian=byr-totPem;
                cout<<setiosflags(ios::right)<<setw(80)<<"Kembalian"<<setiosflags(ios::left)<<setw(6)<<"Rp. "<<kembalian<<",-"<<endl;
                file<<setiosflags(ios::right)<<setw(80)<<"Kembalian"<<setiosflags(ios::left)<<setw(6)<<"Rp. "<<kembalian<<",-"<<endl;
            }
            file.close();
            cout<<endl<<"         Rekap data sudah disimpan   \n    Terima kasih telah memakai jasa kami "<<endl;
    }
}


void penumpang()
{
		cout<<"\n   Banyak tiket yang akan anda beli : "; cin>>jum;
    	cout<<endl;
        for (k=1; k<=jum; k++)
        {
            cout<<"   Penumpang ke-"<<k<<endl;
            cout<<"\tNama singkat            : "; cin>>dt.panggil[k];
            cin.ignore();
			cout<<"\tNama Lengkap Penumpang  : "; getline(cin, dt.nama[k]);
            cout<<"\tUmur                    : "; getline(cin, dt.umur[k]);
			cout<<endl;
        }
}

void cetakTiket() //print boarding pass
{
    ofstream file ("Tiket.txt");
    cout<<endl;
    if (!file.is_open()) {
            cout<<"Tidak bisa membuka file";
    }
    else {
        for (k=1; k<=jum; k++)
        {
            for (j=1; j<=1; j++)
            {
                file<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  "<<endl<<endl;
                file<<"   Kelas "<<kelas2()<<endl<<endl;
                file<<"   Nama"<<endl;
                file<<"   "<<dt.panggil[k]<<endl<<endl;
                file<<"   Penerbangan          Kelas"<<endl;
                file<<"      "<<kode()<<setiosflags(ios::right)<<setw(19)<<kelas2()<<endl<<endl;
                file<<"            Dari  -   Ke"<<endl;
                file<<"          "<<tujuan2()<<endl;
                file<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  "<<endl;
            }
            cout<<endl;
        }
    }
}

void menu()
{
	
	tujuan();
	ulang2:
	cout<<"  Silakan Pilih Tujuan anda : "; cin>>p.pil;
	switch (p.pil)
                    {
                        case '1':
                        {
                            cout<<"\n\tTujuan : "<<tujuan2()<<endl;
                            kelas(); 
                            kettiket();
                            break;
                        }
                        case '2':
                        {
                            cout<<"\n\tTujuan : "<<tujuan2()<<endl;
                            kelas();
                            kettiket();
                            break;
                        }
                        case '3':
                        {
                            cout<<"\n\tTujuan : "<<tujuan2()<<endl;
                            kelas();
                            kettiket();
                            break;
                        }
                        case '4':
                        {
                           cout<<"\n\tTujuan : "<<tujuan2()<<endl;
                            kelas(); 
                            kettiket();
                            break;
                        }
                        case '5':
                        {
                           cout<<"\n\tTujuan : "<<tujuan2()<<endl;
                            kelas(); 
                            kettiket();
                            break;
                        }
                        default:
                        {
                            cout<<"\tInput yang anda masukan salah\n";
                            cout<<"Tekan ENTER untuk kembali\n";
                            getch();
                            goto ulang2;
                            break;
                        }
                    } 
	jenis();
	hargaTiket();
	diskon();
}


main ()
{
	do
	{
		system("cls");
	    login();
	    cout<<endl;
	    Sleep(1200);
	    system("cls");
	    yia();
	    menu();
	    Sleep(1300);
	    system("cls");
		penumpang();
	    akhir(); 
	    cout<<"\n\n\n klik 'enter' untuk melanjutkan ke pembayaran";
	    getch();
	    system("cls"); 
	    cetakTabel(); 
	    cetakTiket(); 
	    cout<<endl;
	    cout<<endl<<"Akan memesan lagi? (y/n) : "; cin>>lagi;
	}
	while (lagi=='y' || lagi=='Y');
	return 0;
}
