#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
typedef struct typetamu *typeptrtamu;
struct typetamu{
    string nama;
    int jumlah_orang;
    string warna;
    typeptrtamu next;
};

typedef struct typeantrian *typeptrantrian;
struct typeantrian{
    string nama;
    int jumlah_orang;
    string warna;
    typeptrantrian next;
};
typedef struct typesouvenirdimeja *typeptrsouvenir;
struct typesouvenirdimeja{
    string warna;
    typeptrsouvenir next;
};

struct typesouvenir{
    string warna;
    int next;
};

typedef struct typekardus *typeptrkardus;
struct typekardus{
    typesouvenir souvenir[13];
    int isi = 12;
    typeptrkardus next;
};

int menu();

void buat_stack_kardus();
bool kardus_kosong();
void push();
void cetak_kardus();

void buat_souvenir();
bool souvenir_habis();
void push_souvenir_meja(typeptrkardus kardus);
void pop_souvenir_meja();

void buat_stack_souvenir(typeptrkardus kardus);
void cetak_souvenir();
void pop_souvenir(typeptrkardus kardus);
void souvenir();

void buat_antrian();
bool antrian_kosong();
void enqueue(typeptrtamu input);
void cetak_antrian();
void masuk();

void buat_tamu();
bool tamu_kosong();
void input_tamu(typeptrtamu input);
void cetak_tamu();
void tamu_keluar();

typeptrkardus kardus_bawah,kardus_atas;
typeptrantrian antrian_depan,antrian_belakang;
typeptrtamu tamu_awal, tamu_akhir;
typeptrsouvenir souvenir_meja_atas, souvenir_meja_bawah;
int souvenir_atas, souvenir_bawah;
int kosongawal, kosongakhir;

int slot = 5;
int souvenir_meja = 0;

//===========================================================================================================
main()
{
    buat_antrian();
    buat_tamu();
    buat_stack_kardus();
    buat_souvenir();

    while(true){
        switch(menu()){
            case 1 : 
            masuk();
            break;
            case 2 : 
            cetak_tamu();
            break;
            case 3 : 
            cetak_antrian();
            break;
            case 4 : 
            tamu_keluar();
            break;
            case 5 : 
            souvenir();
            break;
            case 0 : 
            exit(0);
            break;
        }
    }
}

int menu(){
    int pilih;
    cout << "==========================================" << endl;
    cout << "Sisa Orang yang boleh masuk = " << slot << endl;
    cout << "Tumpukan souvenir = " << souvenir_meja << endl;
    cout << "==========================================" << endl;
    cout << "Menu :" << endl;
    cout << "1. Masuk" << endl;
    cout << "2. Tamu yang Masuk" << endl;
    cout << "3. Antrian" << endl;
    cout << "4. Tamu Keluar" << endl;
    cout << "5. Souvenir" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih : ";
    cin >> pilih;
    system("cls");
    return pilih;
}
void masuk(){
   if(souvenir_meja > 0){
        typeptrtamu input = new typetamu;
        cout << "Nama yang diundang : ";
        cin.ignore(); getline(cin, input->nama);
        do{
            cout << "Jumlah orang yang datang : ";
            cin >> input->jumlah_orang;
            if(input->jumlah_orang < 1 || input->jumlah_orang > 2) cout << "Masukkan minimal 1 orang dan maksimal 2 orang!" << endl;
        } while(input->jumlah_orang < 1 || input->jumlah_orang > 2);
        input->warna = souvenir_meja_atas->warna;
        pop_souvenir_meja();
        
        if(slot >= input->jumlah_orang){
            input_tamu(input);
        } else {
            cout << "Silahkan Mengantri terlebih dahulu!!" << endl;
            enqueue(input);
        }
   } else {
       cout << "Souvenir Habis! Silahkan Push terlebih dahulu!" << endl;
   }
}

void buat_souvenir(){
    souvenir_meja_bawah = new typesouvenirdimeja;
    souvenir_meja_bawah = NULL;
    souvenir_meja_atas = souvenir_meja_bawah;
}
bool souvenir_habis(){
    if(souvenir_meja_bawah == NULL) return true;
    else return false;
}
void push_souvenir_meja(typeptrkardus kardus){
    if(souvenir_meja >= 3){
        cout << "Tumpukan Souvenir sudah penuh!!" << endl;
    }else {
        typeptrsouvenir NS;
        NS = new typesouvenirdimeja;
        NS->warna = kardus->souvenir[souvenir_atas].warna;
        pop_souvenir(kardus);

        if(souvenir_habis()){
            souvenir_meja_bawah = NS;
        } else {
            souvenir_meja_atas->next = NS;
        }
        souvenir_meja_atas = NS;
        souvenir_meja_atas->next = NULL;
        souvenir_meja++;  
        
        cout << "Berhasil Melakukan Push!" << endl;
    }
}
void pop_souvenir_meja(){
    typeptrsouvenir hapus,bantu;
    hapus = souvenir_meja_atas;
    if(souvenir_meja_bawah != souvenir_meja_atas){
        bantu = souvenir_meja_bawah;
        while(bantu->next != hapus) bantu = bantu->next;
        souvenir_meja_atas = bantu;
        souvenir_meja_atas->next = NULL;
    } else {
        souvenir_meja_atas = NULL;
        souvenir_meja_bawah = souvenir_meja_atas;
    }
    free(hapus);
    souvenir_meja--;
}
void souvenir(){
    char confirm;
    cetak_souvenir();
    cout << endl;
    cout << "Ingin melakukan Push?" << endl;
    cin >> confirm;
    if(tolower(confirm) == 'y') {
        if(kardus_kosong()){
            push();
        }
        push_souvenir_meja(kardus_atas);
    }
}

void buat_stack_kardus(){
    typeptrkardus list;
    list = new typekardus;
    list = NULL;
    kardus_bawah = list;
    kardus_atas = list;
}
bool kardus_kosong(){
    if(kardus_bawah == NULL) return true;
    else return false;
}
void push(){
        typeptrkardus NS,bantu;

        NS = new typekardus;

        buat_stack_souvenir(NS);

        if(kardus_kosong()) kardus_bawah=NS;
        else kardus_atas->next=NS;

        kardus_atas=NS;
        kardus_atas->next=NULL;
}
void cetak_souvenir(){
    typeptrsouvenir bantu,cetak;
    if(souvenir_habis()){
        cout << "Souvenir Habis!! Silahkan Push terlebih Dahulu!!" << endl;
    } else {
        cetak = souvenir_meja_atas;
        if(souvenir_meja_atas != souvenir_meja_bawah){    
            do{
                bantu = souvenir_meja_bawah;
                while(bantu->next != cetak) bantu = bantu->next;
                cout << "- " << cetak->warna << endl;
                cetak = bantu;
            }while(bantu != souvenir_meja_bawah);
        }
        cout << "- " << souvenir_meja_bawah->warna << endl;
    }
}
void pop(){
    typeptrkardus hapus,bantu;
    hapus = kardus_atas;
    if(kardus_bawah != kardus_atas){
        bantu = kardus_bawah;
        while(bantu->next != hapus) bantu = bantu->next;
        kardus_atas = bantu;
        kardus_atas->next = NULL;
    } else {
        kardus_atas = NULL;
        kardus_bawah = kardus_atas;
    }
    free(hapus);
}

void buat_stack_souvenir(typeptrkardus kardus){
    kosongawal = 0;
    kosongakhir = 0;
    souvenir_atas = 12;
    souvenir_bawah = 1;
    kardus->souvenir[1].warna = "Merah"; kardus->souvenir[1].next = 2;
    kardus->souvenir[2].warna = "Kuning"; kardus->souvenir[2].next = 3;
    kardus->souvenir[3].warna = "Hijau"; kardus->souvenir[3].next = 4;
    kardus->souvenir[4].warna = "Merah"; kardus->souvenir[4].next = 5;
    kardus->souvenir[5].warna = "Kuning"; kardus->souvenir[5].next = 6;
    kardus->souvenir[6].warna = "Hijau"; kardus->souvenir[6].next = 7;
    kardus->souvenir[7].warna = "Merah"; kardus->souvenir[7].next = 8;
    kardus->souvenir[8].warna = "Kuning"; kardus->souvenir[8].next = 9;
    kardus->souvenir[9].warna = "Hijau"; kardus->souvenir[9].next = 10;
    kardus->souvenir[10].warna = "Merah"; kardus->souvenir[10].next = 11;
    kardus->souvenir[11].warna = "Kuning"; kardus->souvenir[11].next = 12;
    kardus->souvenir[12].warna = "Hijau"; kardus->souvenir[12].next = 0;
}
void pop_souvenir(typeptrkardus kardus){
    int hapus = souvenir_atas;
    int bantu = souvenir_bawah;
    if(souvenir_atas != souvenir_bawah){
        while(kardus->souvenir[bantu].next != hapus) {
            bantu = kardus->souvenir[bantu].next;
        }
        souvenir_atas = bantu;
    } else {
        souvenir_atas = 0;
        souvenir_bawah = 0;
        pop();
    }
    kardus->souvenir[hapus].warna = "";
    kardus->souvenir[souvenir_atas].next = 0; 
}

void buat_antrian(){
    antrian_depan = new typeantrian;
    antrian_depan = NULL;
    antrian_belakang = antrian_depan;
}
bool antrian_kosong(){
    if(antrian_depan == NULL) return true;
    else return false;
}
void enqueue(typeptrtamu input){
    typeptrantrian NQ;
    NQ = new typeantrian;

    NQ->nama = input->nama;
    NQ->jumlah_orang = input->jumlah_orang;
    NQ->warna = input->warna;

    if(antrian_kosong()){
        antrian_depan = NQ;
    } else {
        antrian_belakang->next = NQ;
    }
    antrian_belakang = NQ;
    antrian_belakang->next = NULL;
    
}
void cetak_antrian(){
    if(!antrian_kosong()){
        typeptrantrian bantu;
        bantu = antrian_depan;
        do{
            cout << "Nama yang diundang : " << bantu->nama << endl;
            cout << "Jumlah orang yang datang : " << bantu->jumlah_orang << endl;
            cout << "Warna Souvenir : " << bantu->warna << endl;
            bantu = bantu->next;
        } while(bantu != NULL);
    } else {
        cout << "Tidak ada Antrian!!" << endl;
    }
}
void dequeue(){
    typeptrantrian hapus;
    hapus = antrian_depan;
    if(antrian_depan == antrian_belakang){
        antrian_depan = NULL;
        antrian_belakang = antrian_depan;
    } else {
        antrian_depan = antrian_depan->next;
    }
    free(hapus);
}

void buat_tamu(){
    tamu_awal = new typetamu;
    tamu_awal = NULL;
    tamu_akhir = tamu_awal;
}
bool tamu_kosong(){
    if(tamu_awal == NULL){
        return true;
    } else return false;
}
void input_tamu(typeptrtamu input){
    typeptrtamu NT = input;
    if(tamu_kosong()){
        tamu_awal = NT;
    } else {
        tamu_akhir->next = NT;
    }
    tamu_akhir = NT;
    tamu_akhir->next = NULL;
    slot -= NT->jumlah_orang;
}
void tamu_keluar(){
    if(!tamu_kosong()){
        typeptrtamu hapus;
        hapus = tamu_awal;
        if(tamu_awal != tamu_akhir){
            tamu_awal = tamu_awal->next;
        } else {
            tamu_awal = NULL;
            tamu_akhir = tamu_awal;
        }
        slot += hapus->jumlah_orang;
        free(hapus);
        if(!antrian_kosong() && slot >= antrian_depan->jumlah_orang){
            cout << "Tamu atas nama " << antrian_depan->nama << " dipersilahkan masuk !!" << endl;
            typeptrtamu input = new typetamu;
            input->nama = antrian_depan->nama;
            input->jumlah_orang = antrian_depan->jumlah_orang;
            input->warna = antrian_depan->warna;
            input_tamu(input);
            dequeue();
        }
    } else {
        cout << "Tidak ada Tamu di dalam ruangan!" << endl;
    }
}
void cetak_tamu(){
    if(!tamu_kosong()){
        typeptrtamu bantu;
        bantu = tamu_awal;
        do{
            cout << "------------------------------------------------" << endl;
            cout << "Nama yang diundang       : " << bantu->nama << endl;
            cout << "Jumlah orang yang datang : " << bantu->jumlah_orang << endl;
            cout << "Warna Souvenir           : " << bantu->warna << endl;
            bantu = bantu->next;
        } while(bantu != NULL);
    }else{
        cout << "Tidak ada tamu di dalam ruangan!!" << endl;
    }
}
