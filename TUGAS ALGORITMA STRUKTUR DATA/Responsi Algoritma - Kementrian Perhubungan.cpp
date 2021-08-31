#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
struct mudik
{
	string nama,jk,almt,trans,waktu;
	int nik;

}mdk[100];
mudik temp;

int i,banyak, pilih,pil,pl;
char namasort[100];

void judul();
void menu_data();
void input();
void dtout();
void output();
void rekursif(int a);
void cari();
void nmpmdk();
void nikpmdk();
void bubbles();
void bubbles2();

main()
{
	cout<<"                        ANINDITA K. O. / 124190019                 "<<endl;
	judul();
	menu_data();
	cout<<"\t\t PILIH : ";
	cin>>pilih;
	cout<<endl;
	system("CLS");
	switch(pilih)
		{
			case 1:
				//input
				input();
			break;
			case 2:
				//output//output();
				dtout();
				cout<<"\t\t Output Berdasar : ";
				cin>>pl;
				cout<<endl;
				system("pause");
				system("CLS");
					switch(pl)
					{
						case 1:		
							//nama 
							
							bubbles();
						break;
						case 2:
							//nik
							bubbles2();
						break;
						case 3:
							main();
						break;
					}

				
			break;
			case 3:
				//cari
				cari();
				cout<<"\t\t Cari Berdasar : ";
				cin>>pil;
				cout<<endl;
				system("pause");
				system("CLS");
					
					switch(pil)
					{
						case 1:
						//nama
							nmpmdk();
						break;
						case 2:
						//nik
							nikpmdk();
						break;
						case 3:
							main();
						break;
					}
					
			break;
			case 4:
				//exit
				exit(0);
			break;
			default:
			cout<<"Salah Input ";
		}

}
void judul()
{
	system("cls");
	cout<<"============================================================================="<<endl;
    cout<<"                        KEMENTRIAN PERHUBUNGAN REPUBLIK INDONESIA            "<<endl;
    cout<<"============================================================================="<<endl;
}
void menu_data()
{
	cout<<"\t------------------------------------------------------------------"<<endl;
	cout<<"\t 1. INPUT DATA                            \n";
    cout<<"\t 2. OUTPUT DATA                           \n";
    cout<<"\t 3. CARI DATA                             \n";
	cout<<"\t 4. Exit \t\t"<<endl;
	cout<<"\t------------------------------------------------------------------"<<endl;
	cout<<endl;
}
void dtout()
{
	system("cls");
	cout<<"\n\t|-------------------------------------------------=-----|";
	cout<<"\n\t|                       OUTPUT DATA                     |";
	cout<<"\n\t|-------------------------------------------------------|"<<endl<<endl;
	cout<<"\t|  1. Berdasarkan Nama \t   |"<<endl;
	cout<<"\t|  2. Berdasarkan NIK  \t   |"<<endl;
	cout<<"\t|  3. Kembali \t\t   |"<<endl;
	cout<<"\t+--------------------------+"<<endl;
}
void cari()
{
	system("cls");
	cout<<"\n\t|----------------------------------------------------=-----|";
	cout<<"\n\t|                       SEARCHING DATA                     |";
	cout<<"\n\t|----------------------------------------------------------|"<<endl<<endl;
	cout<<"\t|  1. Berdasar Nama \t   |"<<endl;
	cout<<"\t|  2. Berdasar NIK  \t   |"<<endl;
	cout<<"\t|  3. Kembali \t\t   |"<<endl;
	cout<<"\t+--------------------------+"<<endl;
}
void input()
{
	
	cin.ignore();
		cout<<"\n\t|------------------------------------------------=-----|";
		cout<<"\n\t|                       INPUT DATA                     |";
		cout<<"\n\t|------------------------------------------------------|"<<endl<<endl;
	
	ofstream jumlah;
	
	jumlah.open("banyak data.txt");
	
	cout<<endl;
	cout<<"\tBanyak Data : "; 
	cin>>banyak; 
	cout<<endl;
	
	jumlah<<banyak;
	jumlah.close();
	
	ofstream save;
	save.open("responsi.txt");
	
	for(i=0; i<banyak; i++)
    {
		cin.ignore();
		cout<< "\t Pemudik  ke- " << i+1 << endl;
		cout<< "\t Nama Lengkap                : "; 
		getline(cin,mdk[i].nama);
		cout<< "\t NIK                         : "; 
		cin>> mdk[i].nik;
		cin.ignore(); 
		cout<< "\t Jenis Kelamin               : "; 
		cin>> mdk[i].jk;
		cout<< "\t Alamat                      : "; 
		cin>> mdk[i].almt;   
		cout<< "\t Transportasi                : "; 
		cin>> mdk[i].trans;
		cout<< "\t Waktu                       : "; 
		cin>> mdk[i].waktu;
		cout<<endl;
		
			save<<mdk[i].nama<<endl;
			save<<mdk[i].nik<<endl;
			save<<mdk[i].jk<<endl;
			save<<mdk[i].almt<<endl;
			save<<mdk[i].trans<<endl;
			save<<mdk[i].waktu<<endl;
		
	}
	
	save.close();
	system("pause");
	system("CLS");
	main();
	
}

void output()
{
	int o=137;
	string kosong;
	
	ifstream a;
	a.open("banyak data.txt");
	a>>banyak;
	a.close();
	cin.ignore();
	
	ifstream b;
	b.open("responsi.txt");
	b.close();
	cin.ignore();
	
	cout<<endl;
	
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                                      DATA USER                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"| No |"<<"\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	
	rekursif(o);
	cout<<endl;
	ifstream lihat;
	lihat.open("responsi.txt");
	
	for(i=0; i<banyak; i++)
	{
		getline(lihat,mdk[i].nama);
		lihat>>mdk[i].nik;
		lihat>>mdk[i].jk;
		lihat>>mdk[i].almt;
		lihat>>mdk[i].trans;
		lihat>>mdk[i].waktu;
	
			getline(lihat,kosong);
			
			cout<<"| "<<i+1;
			cout<<"  |\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
		rekursif(o);
			cout<<endl;
		
	}
	
	
		main();
	
}
void rekursif(int a)
{
	if(a>1)
	{
		cout<<"-";
		rekursif(a-1);
	}
	else
		cout<<"-";
}
void nmpmdk()
{	
	judul();
	
	cout<<"\t\t\t\t\t NAMA "<<endl;
	string namac; bool found=false;	
	int o=137,c=0;
	string kosong;
	ifstream a;
	
	a.open("banyak data.txt");
	a>>banyak;
	a.close();
	
	cout<<endl;
	
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                                      DATA USER                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"| No |"<<"\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	
	rekursif(o);
	cout<<endl;
	ifstream buka;
	buka.open("responsi.txt");
	
	for(i=0; i<banyak; i++)
	{
		getline(buka,mdk[i].nama);
		buka>>mdk[i].nik;
		buka>>mdk[i].jk;
		buka>>mdk[i].almt;
		buka>>mdk[i].trans;
		buka>>mdk[i].waktu;
	
			getline(buka,kosong);
			
			cout<<"| "<<i+1;
			cout<<"  |\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
		rekursif(o);
			cout<<endl;
		
	}
	
	cout<<"\tNama Pemudik yang dicari: ";
	cin.ignore();
	getline(cin,namac);
	cout<<endl;
	
	while((!found) && c<banyak)
	{
		if(namac==mdk[c].nama)
		{
			found=true;
		}
		else
		{
			c++;
		}
	}
	
	if(found)
	{
		cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                                      DATA USER                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
		rekursif(o);
		cout<<endl;
	
		getline(buka,kosong);
	
			cout<<"|\t"<<mdk[c].nama;
			cout<<"\t|\t"<<mdk[c].nik;
			cout<<"\t|\t"<<mdk[c].jk;
			cout<<"\t|\t"<<mdk[c].almt;
			cout<<"\t|\t"<<mdk[c].trans;
			cout<<"\t\t|\t\t"<<mdk[c].waktu<<"\t\t|"<<endl;
		
		rekursif(o);
		cout<<endl;
	  
	}
	else 
	{
		cout<<"\t\t     DATA TIDAK DITEMUKAN"<<endl;
	}
	buka.close();
	
	system("pause");
	system("CLS");	

	main();
}
void nikpmdk()
{	
	judul();
	
	cout<<"\t\t\t\t\t NIK "<<endl;
	int cnik; bool found=false;	
	int o=137,c=0;
	string kosong;
	ifstream a;
	
	a.open("banyak data.txt");
	a>>banyak;
	a.close();
	
	cout<<endl;
	
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                                      DATA USER                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"| No |"<<"\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	
	rekursif(o);
	cout<<endl;
	ifstream buka;
	buka.open("responsi.txt");
	
	for(i=0; i<banyak; i++)
	{
		getline(buka,mdk[i].nama);
		buka>>mdk[i].nik;
		buka>>mdk[i].jk;
		buka>>mdk[i].almt;
		buka>>mdk[i].trans;
		buka>>mdk[i].waktu;
	
			getline(buka,kosong);
			
			cout<<"| "<<i+1;
			cout<<"  |\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
		rekursif(o);
			cout<<endl;
		
	}
	
	cout<<"\tNIK Pemudik yang dicari: ";
	cin.ignore();
	cin>>cnik;
	//getline(cin,cnik);
	cout<<endl;
	
	while((!found) && c<banyak)
	{
		if(cnik == mdk[c].nik)
		{
			found=true;
		}
		else
		{
			c++;
		}
	}
	
	if(found)
	{
		cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                                      DATA USER                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
		rekursif(o);
		cout<<endl;
	
		getline(buka,kosong);
	
			cout<<"|\t"<<mdk[c].nama;
			cout<<"\t|\t"<<mdk[c].nik;
			cout<<"\t|\t"<<mdk[c].jk;
			cout<<"\t|\t"<<mdk[c].almt;
			cout<<"\t|\t"<<mdk[c].trans;
			cout<<"\t\t|\t\t"<<mdk[c].waktu<<"\t\t|"<<endl;
		
		rekursif(o);
		cout<<endl;
	  
	}
	else 
	{
		cout<<"\t\t       DATA TIDAK DITEMUKAN"<<endl;
	}
	buka.close();
	
	system("pause");
	system("CLS");	

	main();
}
void bubbles()
{ 	
	int o=137,j;
	string kosong;
	ifstream a;
	a.open("banyak data.txt");
	a>>banyak;
	a.close();
	cin.ignore();
	
	ifstream b;
	b.open("responsi.txt");
	b.close();
	cin.ignore();
	
	
	cout<<"\tNama File (hasil sorting) : "; 
	cin.getline(namasort,100);

	
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                                      DATA USER                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"| No |"<<"\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	rekursif(o);
	cout<<endl;
	
	
	
	ifstream buka;
	buka.open("responsi.txt");
	ofstream baru;
	baru.open(namasort);
	
	for(i=0; i<banyak; i++)
	{
		getline(buka,mdk[i].nama);
		buka>>mdk[i].nik;
		buka>>mdk[i].jk;
		buka>>mdk[i].almt;
		buka>>mdk[i].trans;
		buka>>mdk[i].waktu;
	
			getline(buka,kosong);
			
			cout<<"| "<<i+1;
			cout<<"  |\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
		rekursif(o);
			cout<<endl;
		
	}
	
	//PROSES SORTING
	for(i=0; i<banyak-1; i++)
	{
		for(j=0; j<banyak-1-i; j++)
		{
			if(mdk[j].nama > mdk[j+1].nama)
			{
				temp.nama = mdk[j].nama;
				temp.nik = mdk[j].nik;
				temp.jk= mdk[j].jk;
				temp.almt=mdk[j].almt;
				temp.trans=mdk[j].trans;
				temp.waktu=mdk[j].waktu;
				
				mdk[j].nama=mdk[j+1].nama;
				mdk[j].nik=mdk[j+1].nik;
				mdk[j].jk= mdk[j+1].jk;
				mdk[j].almt=mdk[j+1].almt;
				mdk[j].trans=mdk[j+1].trans;
				mdk[j].waktu=mdk[j+1].waktu;
				
				mdk[j+1].nama=temp.nama;
				mdk[j+1].nik=temp.nik;
				mdk[j+1].jk=temp.jk;
				mdk[j+1].almt=temp.almt;
				mdk[j+1].trans=temp.trans;
				mdk[j+1].waktu=temp.waktu;

			}
		}
	}
	for(i=0; i<banyak; i++)
	{
		baru<<mdk[i].nama<<endl;
		baru<<mdk[i].nik<<endl;
		baru<<mdk[i].jk<<endl;
		baru<<mdk[i].almt<<endl;
		baru<<mdk[i].trans<<endl;
		baru<<mdk[i].waktu<<endl;

	}
	buka.close();
	baru.close();
	
	cout<<endl<<"\t\t\t\t                SORTING BERHASIL "<<endl<<endl;
	
	//setelah sorting
		
	cout<<"\tNama file (hasil sorting) : ";
	cin>>namasort;
	cout<<endl;
	
	string namac; 	
	//bool found;
	//found=false;
	
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                  DATA SETELAH DISORTING (NAMA)                                                              |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	rekursif(o);
	cout<<endl;
	
	ifstream lihat;
	lihat.open(namasort);
	
	for(i=0; i<banyak; i++)
	{
		getline(lihat,mdk[i].nama);
		lihat>>mdk[i].nik;
		lihat>>mdk[i].jk;
		lihat>>mdk[i].almt;
		lihat>>mdk[i].trans;
		lihat>>mdk[i].waktu;

		getline(lihat,kosong);
		
			cout<<"|\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
			
		rekursif(o);
		cout<<endl;
	}
	lihat.close();	
	system("pause");
	system("CLS");
	main();
}
void bubbles2()
{ 	
	int o=137,j;
	string kosong;
	ifstream a;
	a.open("banyak data.txt");
	a>>banyak;
	a.close();
	cin.ignore();
	
	ifstream b;
	b.open("responsi.txt");
	b.close();
	cin.ignore();
	
	
	cout<<"\tNama File (hasil sorting) : "; 
	cin.getline(namasort,100);

	
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                        DATA SEBELUM DISORTING                                                               |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"| No |"<<"\t Nama \t|"<<"\t Nik \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	rekursif(o);
	cout<<endl;
	
	
	
	ifstream buka;
	buka.open("responsi.txt");
	ofstream baru;
	baru.open(namasort);
	
	for(i=0; i<banyak; i++)
	{
		getline(buka,mdk[i].nama);
		buka>>mdk[i].nik;
		buka>>mdk[i].jk;
		buka>>mdk[i].almt;
		buka>>mdk[i].trans;
		buka>>mdk[i].waktu;
	
			getline(buka,kosong);
			
			cout<<"| "<<i+1;
			cout<<"  |\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
		rekursif(o);
			cout<<endl;
		
	}
	//PROSES SORTING NIK
	for(i=0; i<banyak-1; i++)
	{
		for(j=0; j<banyak-1-i; j++)
		{
			if(mdk[j].nik > mdk[j+1].nik)
			{
				temp.nama = mdk[j].nama;
				temp.nik = mdk[j].nik;
				temp.jk= mdk[j].jk;
				temp.almt=mdk[j].almt;
				temp.trans=mdk[j].trans;
				temp.waktu=mdk[j].waktu;
				
				mdk[j].nama=mdk[j+1].nama;
				mdk[j].nik=mdk[j+1].nik;
				mdk[j].jk= mdk[j+1].jk;
				mdk[j].almt=mdk[j+1].almt;
				mdk[j].trans=mdk[j+1].trans;
				mdk[j].waktu=mdk[j+1].waktu;
				
				mdk[j+1].nama=temp.nama;
				mdk[j+1].nik=temp.nik;
				mdk[j+1].jk=temp.jk;
				mdk[j+1].almt=temp.almt;
				mdk[j+1].trans=temp.trans;
				mdk[j+1].waktu=temp.waktu;

			}
		}
	}
	for(i=0; i<banyak; i++)
	{
		baru<<mdk[i].nama<<endl;
		baru<<mdk[i].nik<<endl;
		baru<<mdk[i].jk<<endl;
		baru<<mdk[i].almt<<endl;
		baru<<mdk[i].trans<<endl;
		baru<<mdk[i].waktu<<endl;

	}
	buka.close();
	baru.close();
	
	cout<<endl<<"\t\t\t\t       SORTING BERHASIL "<<endl<<endl;
	
	
	
		//setelah sortingnik
		
	cout<<"\tNama file (hasil sorting) : ";
	cin>>namasort;cin.ignore(); 
	cout<<endl;
	
	string cnik; 	

	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|                                                  DATA SETELAH DISORTING (NIK)                                                               |"<<endl;
	cout<<"|=============================================================================================================================================|"<<endl;
	cout<<"|\t Nik \t|"<<"\t Nama \t|"<<"\t Jenis Kelamin \t|"<<"\t Alamat \t|"<<"\t Transportasi \t|"<<"\t Waktu Berangkat \t|"<<endl;
	rekursif(o);
	cout<<endl;
	
	ifstream lihat2;
	lihat2.open(namasort);
	
	for(i=0; i<banyak; i++)
	{
		getline(lihat2,mdk[i].nama);
		lihat2>>mdk[i].nik;
		lihat2>>mdk[i].jk;
		lihat2>>mdk[i].almt;
		lihat2>>mdk[i].trans;
		lihat2>>mdk[i].waktu;

		getline(lihat2,kosong);
		
			cout<<"|\t"<<mdk[i].nik;
			cout<<"\t|\t"<<mdk[i].nama;
			cout<<"\t|\t"<<mdk[i].jk;
			cout<<"\t|\t"<<mdk[i].almt;
			cout<<"\t|\t"<<mdk[i].trans;
			cout<<"\t\t|\t\t"<<mdk[i].waktu<<"\t\t|"<<endl;
			
		rekursif(o);
		cout<<endl;
	}
	lihat2.close();	
	
	system("pause");
	system("CLS");
	main();
}

