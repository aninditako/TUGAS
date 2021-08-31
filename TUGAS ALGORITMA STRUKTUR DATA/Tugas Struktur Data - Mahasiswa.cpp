#include <iostream>
#include <stdlib.h> 
#include <string.h>
using namespace std;

	struct mhs
	{
		int nilai;
		char nmk[20];
	};
	struct data
	{
		char nama[30];
		int nim , jm;
		mhs matkul[10];
	}dt[20];
	
	string kembali;
	int pl,pilih;
	string nm;
	
	bool found;
	int  no, bm;
	
	int i,j;

	
void menu()
{
	cout<<endl;  
	cout<<"|-----------------------|"<<endl;
	cout<<"| Silahkan Pilih Menu : |"<<endl;
	cout<<"| 1. Input Data \t|"<<endl;
	cout<<"| 2. Cari Data \t\t|"<<endl;
	cout<<"| 3. Lihat \t\t|" <<endl;
	cout<<"| 4. Selesai \t\t|"<<endl;
	cout<<"|-----------------------|"<<endl<<endl;
	
	cout<<" Pilih : ";
	cin>>pl;
}

int main()
{
	
	do
	{
		menu();
		cout<<endl;
		
		switch (pl)
		{
			
			case 1 :
			
			cout<<" Masukan Banyak Mahasiswa : ";
			cin>>bm;
			
			cout<<endl;
			
			for(i=0; i<bm; i++)
			{
				cout<<" Mahasiswa ke-"<<i+1<<endl;
				cout<<" NIM \t\t:";
				cin>>dt[i].nim;
				cout<<" Nama \t\t:" ;
				cin>>dt[i].nama;
				cout<<" Banyak MKA \t: ";
				cin>>dt[i].jm;
				
				for(j=1; j<=dt[i].jm; j++)
				{
					cout<<endl;
					cout<<" \t 1. Nama Mata Kuliah    : ";
					cin>>dt[i].matkul[j].nmk;
					cout<<" \t 2. Nilai  \t\t: ";
					cin>>dt[i].matkul [j].nilai;
					
					
				}
				cout<<endl;
	cout<<" ----------------------------------------------------"<<endl;
				cout<<endl;
			}
			break;
			

			case 2 :
				cout<<" Cari data berdasarkan"<<endl;
				cout<<" 1. NIM"<<endl;		
				cout<<" 2. Nama"<<endl;	
				cout<<" Pilih : ";	
				cin>>pilih;
				cout<<endl;
				
				switch(pilih)
				{
					
					case 1:
					
						cout<<" NIM yang dicari : ";
						cin>>no;
						
						found = false;
						i=0;

						while((i<10) && (!found))
						{
							if(dt[i].nim==no)
							{
								found=true;
							}
							else
							{
								i=i+1;
							}
						}
						
						if(found)
						{
							cout<<" Mahasiswa ke-"<<i+1<<endl;
							cout<<" NIM \t\t:"<<dt[i].nim<<endl;
							cout<<" Nama \t\t:" <<dt[i].nama<<endl;
							
							for(j=1; j<=dt[i].jm; j++)
							{
								cout<<endl;
								cout<<" \t 1. Nama Mata Kuliah    : "<<dt[i].matkul[j].nmk<<endl;
								cout<<" \t 2. Nilai  \t\t: "<<dt[i].matkul [j].nilai<<endl;
								
								
							}
							cout<<endl;
						}
						else
						{
							cout<<" NIM "<<no<<" Tidak Ditemukan"<<endl;
						}
						
					break;
					
					case 2:
						cout<<" Nama  yang dicari: ";
						cin>>nm;
						
						found = false;
						i=0;

						while((i<10) && (!found))
						{
							if(dt[i].nama==nm)
							{
								found=true;
							}
							else
							{
								i=i+1;
							}
						}
						
						if(found)
						{
							cout<<" Mahasiswa ke-"<<i+1<<endl;
							cout<<" NIM \t\t:"<<dt[i].nim<<endl;
							cout<<" Nama \t\t:" <<dt[i].nama<<endl;
							
							for(j=1; j<=dt[i].jm; j++)
							{
								cout<<endl;
								cout<<" \t 1. Nama Mata Kuliah    : "<<dt[i].matkul[j].nmk<<endl;
								cout<<" \t 2. Nilai  \t\t: "<<dt[i].matkul [j].nilai<<endl;
								
								
							}
							cout<<endl;
						}
						else
						{
							cout<<" Nama "<<nm<<" Tidak Ditemukan"<<endl;
						}
		
					
						cout<<" ----------------------------------------------------"<<endl;
					
				}
				
				
			break;
			
			case 3 :
				for(i=0; i<bm; i++)
				{
					cout<<" Mahasiswa ke-"<<i+1<<endl;
					cout<<" NIM \t\t:"<<dt[i].nim<<endl;
					cout<<" Nama \t\t:" <<dt[i].nama<<endl;
					
					for(j=1; j<=dt[i].jm; j++)
					{
						cout<<endl;
						cout<<" \t 1. Nama Mata Kuliah    : "<<dt[i].matkul[j].nmk<<endl;
						cout<<" \t 2. Nilai  \t\t: "<<dt[i].matkul [j].nilai<<endl;
						
						cout<<endl;
					}
					
					cout<<endl;
	cout<<" ----------------------------------------------------"<<endl;
				cout<<endl;
			}
				
	
			break;
			
			case 4 :
				cout<<" Terimakasih";
				exit(0);
			break;
			
		}
			
	}
	while (pl>=1 && pl<=3);
	
	
}
