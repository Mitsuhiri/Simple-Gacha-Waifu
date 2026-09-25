/*
Game Gacha waifu dengan fitur :
1. Gacha waifu
2. Buka inventory waifu
3. Ceraikan waifu
4. Buka List waiuf
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
// Database Waifu 1.1
#pragma region Database_waifu
struct waifu{
    string name;
    string rarity;
};
// Ubah jumlah waifu sesuai dengan raritynya ketika ingin menambahkan waifu
const int jumlahCommon = 8;
const int jumlahUncommon = 8;
const int jumlahRare = 6;
const int jumlahLegendary = 6;
const int jumlahMythical = 7;

waifu common[jumlahCommon] = { // List waifu common
    {"Sakura Haruno", "Common"},
    {"Anzu Hoshino", "Common"},
    {"Tenten", "Common"},
    {"Mako Mankanshoku", "Common"},
    {"Tsuyu Asui", "Uncommon"},
    {"Sasha Blouse", "Common"},
    {"Miyuki Shirogane", "Common"},
    {"Anzu Hoshino", "Common"},
};
waifu uncommon[jumlahUncommon] = { // List waifu uncommon
    {"Uraraka Ochako", "Uncommon"},
    {"Nobara Kugisaki", "Uncommon"},
    {"Kanao Tsuyuri", "Uncommon"},
    {"Lucy Heartfilia", "Uncommon"},
    {"Mai Sakurajima", "Uncommon"},
    {"Miku Nakano", "Uncommon"},
    {"Momo Yaoyorozu", "Common"},
};
waifu rare[jumlahRare] = { // List waifu rare
    {"Asuka Langley Soryu", "Rare"},
    {"Rin Tohsaka", "Rare"},
    {"Yor Forger", "Rare"},
    {"Ram", "Rare"},
    {"Tsunade", "Rare"},
    {"Maki Zenin", "Uncommon"},
};
waifu legendary[jumlahLegendary] = { // List waifu legendary
    {"Power", "Legendary"},
    {"Kaguya Shinomiya", "Legendary"},
    {"Emilia", "Legendary"},
    {"Kurumi Tokisaki", "Legendary"},
    {"Nami", "Legendary"},
    {"Albedo", "Legendary"},
};
waifu mythical[jumlahMythical] = { // List waifu mythical
    {"Saber (Artoria Pendragon)", "Mythical"},
    {"Zero Two", "Rare"},
    {"Rem", "Mythical"},
    {"Asuna", "Mythical"},
    {"Makima", "Mythical"},
    {"Violet Evergarden", "Mythical"},
    {"Frieren", "Mythical"},
};
#pragma endregion
// Fungsi untuk cek waifu yang sudah punya
bool cekDuplikat(string name, waifu inventory[], int jumlahWaifu){
    for(int i = 0;i < jumlahWaifu; i++){ // Mengecek waifu 1 per 1 yang ada di inventory
        if(inventory[i].name == name){
            return true; // Ketika waifu yang didapat ada yang sama dengan yang di inventory, fungsi langsung menyatakan true
        }
    } 
    return false;
}
// Funsi untuk menambahkan waifu ke inventory
void tambahKeInventory(string name,string rarity, waifu inventory[], int &jumlahWaifu, int &gems){
    if(cekDuplikat(name, inventory, jumlahWaifu)){ // Dijalankan ketika fungsi cekDuplikat bersifat true
        int reward = 0;

        if(rarity == "Common"){
            reward = 50;

        } else if(rarity == "Uncommon"){
            reward = 75;

        } else if(rarity == "Rare"){
            reward = 125;

        } else if(rarity == "Legendary"){
            reward = 200;

        } else if(rarity == "Mythical"){
            reward = 300;

        }
        gems = gems + reward;

        cout << "\n";
        cout << "-----------------------------------------\n";
        cout << "  Duplikat!\n";
        cout << "  " << name << "-mu Terkonversi menjadi " << reward << " Gems!\n";
        cout << "-----------------------------------------\n\n";
    } else{ // Dijalankan ketika fungsi cekDuplikat bersifat false
        inventory[jumlahWaifu].name = name;
        inventory[jumlahWaifu].rarity = rarity;
        jumlahWaifu++;
        cout << "  Waifu Barumu Masuk Ke inventory!\n";
        cout << "----------------------------------------\n";
    }
}
// Fungsi utama untuk gacha waifu
void gacha(waifu inventory[], int &jumlahWaifu, int &gems,const int harga){
    if(gems < harga){ // Mengecek perbandingan antara gems dan harga gacha
        cout << "  Gems tidak Cukup\n";
        cout << "  Miskin lu\n";

    } else{ // Dijalankan ketika gems lebih besar dari harga atau false
        gems -= harga;
        int roll = rand() % 100 + 1; // Sistem gacha utama dari 1 sampai 100

        if(roll <= 60){
            int randomIndex = rand() % jumlahCommon; // Sistem gacha dengan ruang lingkup jumlahCommon
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << common[randomIndex].name << "\n";
            cout << "       [" << common[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(common[randomIndex].name, common[randomIndex].rarity, inventory, jumlahWaifu, gems);
        } else if(roll <= 85){
            int randomIndex = rand() % jumlahUncommon; // Sistem gacha dengan ruang lingkup jumlahUnommon
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << uncommon[randomIndex].name << "\n";
            cout << "       [" << uncommon[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(uncommon[randomIndex].name, uncommon[randomIndex].rarity, inventory, jumlahWaifu, gems);
        } else if(roll <= 95){
            int randomIndex = rand() % jumlahRare; // Sistem gacha dengan ruang lingkup jumlahRare
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << rare[randomIndex].name << "\n";
            cout << "       [" << rare[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(rare[randomIndex].name, rare[randomIndex].rarity, inventory, jumlahWaifu, gems);
        } else if(roll <= 99){
            int randomIndex = rand() % jumlahLegendary; // Sistem gacha dengan ruang lingkup jumlahLegendary
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << legendary[randomIndex].name << "\n";
            cout << "       [" << legendary[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(legendary[randomIndex].name,legendary[randomIndex].rarity, inventory, jumlahWaifu, gems);
        } else if(roll <=100){
            int randomIndex = rand() % jumlahMythical; // Sistem gacha dengan ruang lingkup jumlahMythical
            cout << "\n";
            cout << "========================================\n";
            cout << "            > SUMMONED! <\n";
            cout << "========================================\n";
            cout << "\n";
            cout << "       " << mythical[randomIndex].name << "\n";
            cout << "       [" << mythical[randomIndex].rarity << "]\n";
            cout << "\n";
            cout << "========================================\n";
            tambahKeInventory(mythical[randomIndex].name, mythical[randomIndex].rarity, inventory, jumlahWaifu, gems);
        }
    }
}
// Funsi untuk membuka waifu yang sudah punya
void fungsiInventory(waifu inventory[],int jumlahWaifu){
    cout << "\n";
    cout << "==============================\n";
    cout << "\tList Waifumu \n";
    cout << "==============================\n";

    if(jumlahWaifu == 0){ //Dijalankan ketika tidak punya waifu
        cout << "  Kamu Belum Punya Waifu 1 pun..\n\n";
    } else{ // Dijalankan ketika mempunyai waifu minimal 1
        for (int i = 0; i < jumlahWaifu; i++){
            cout << i + 1 << ". " << inventory[i].name << " [" << inventory[i].rarity << "]\n";
        }
    }
}
// Fungsi untuk membuka list waifu di Database Waifu
void listRarity(){
    cout << "\n";
    cout << "==============================\n";
    cout << "\tCommon(60%)\n";
    cout << "==============================\n";
    for(int i = 0; i < jumlahCommon; i++){ // Menampilkan semua list waifu Common
        cout << i + 1 << ". " << common[i].name << "\n";
    }
    cout << "\n";
    cout << "\n==============================\n";
    cout << "\tUncommon(25%)\n";
    cout << "==============================\n";
    for(int i = 0; i < jumlahUncommon; i++){ // Menampilkan semua list waifu Uncommon
        cout << i + 1 << ". " << uncommon[i].name << "\n";
    }
    cout << "\n";
    cout << "==============================\n";
    cout << "\tRare(10%)\n";
    cout << "==============================\n";
    for(int i = 0; i < jumlahRare; i++){ // Menampilkan semua list waifu Rare
        cout << i + 1 << ". " << rare[i].name << "\n";
    }
    cout << "\n";
    cout << "==============================\n";
    cout << "\tLegendary(4%)\n";
    cout << "==============================\n";
    for(int i = 0; i < jumlahLegendary; i++){ // Menampilkan semua list waifu Legendary
        cout << i + 1 << ". " << legendary[i].name << "\n";
    }
    cout << "\n";
    cout << "==============================\n";
    cout << "\tMythical(1%)\n";
    cout << "==============================\n";
    for(int i = 0; i < jumlahMythical; i++){ // Menampilkan semua list waifu Mythical
        cout << i + 1 << ". " << mythical[i].name << "\n";
    }
    cout << "\n";
}
// Fungsi untuk menghapus waifu dari inventory
void cerai(waifu inventory[], int &jumlahWaifu, int &gems){
    int reward = 0;
    int nomor;

    if(jumlahWaifu == 0){
        cout << "\n";
        cout << "========================================\n";
        cout << "             Ceraikan Waifu\n";
        cout << "========================================\n";
        cout << "  Kamu Belum Punya Waifu 1 pun...\n\n";

    } else{
        cout << "\n";
        cout << "========================================\n";
        cout << "             Ceraikan Waifu\n";
        cout << "========================================\n";

        for (int i = 0; i < jumlahWaifu; i++){
            cout << "  [" <<i + 1 << "]" << inventory[i].name << " [" << inventory[i].rarity << "] - ";
            if(inventory[i].rarity == "Common"){
                reward = 50;

            } else if(inventory[i].rarity == "Uncommon"){
                reward = 100;

            } else if(inventory[i].rarity == "Rare"){
                reward = 175;

            } else if(inventory[i].rarity == "Legendary"){
                reward = 300;

            } else if(inventory[i].rarity == "Mythical"){
                reward = 500;
            }
            cout << reward << "Gems\n";
        }
    
        cout << "----------------------------------------\n";
        cout << "  Pilih 0 untuk batal\n";
        cout << "  Pilih waifu yang ingin diceraikan: ";
        cin >> nomor;

        if(nomor < 0 || nomor > jumlahWaifu){
            cout << "  Pilihan Tidak Valid.\n";
            return;
        } else if(nomor == 0){
            cout << "  Perceraian Dibatalkan\n";
        } else{
            int list = nomor - 1;
            int hargaCerai = 0;

            if(inventory[list].rarity == "Common"){
                hargaCerai = 50;
            } else if(inventory[list].rarity == "Uncommon"){
                hargaCerai = 100;

            } else if(inventory[list].rarity == "Rare"){
                hargaCerai = 175;

            } else if(inventory[list].rarity == "Legendary"){
                hargaCerai = 300;

            } else if(inventory[list].rarity == "Mythical"){
                hargaCerai = 500;
            }

            cout << "\n";
            cout << "----------------------------------------\n";
            cout << "  " << inventory[list].name << " Berhasil Dicerakan!\n";
            cout << "  Kamu Mendapatkan " << hargaCerai << "Gems\n";
            cout << "----------------------------------------\n";

            gems += hargaCerai;

            for(int i = list; i < jumlahWaifu - 1; i++){
                inventory[i] = inventory[i + 1];
            }
            
            jumlahWaifu--;
        }
    }
}
// Fungsi utama untuk menjalankan fungsi-fungsi lainnya
int main (){

    srand(time(0));
    string name;
    string rarity;
    int pilihan;
    int gems = 1000;
    const int harga = 100;
    waifu inventory[1000];
    int jumlahWaifu = 0;

    do{

        cout << "\n";
        cout << "+=======================================+\n";
        cout << "        >----{ GACHA WAIFU }----<        \n";
        cout << "+=======================================+\n";
        cout << "  Gems kamu : " << gems << "\n";
        cout << "-----------------------------------------\n";
        cout << "  [1] Gacha Waifu\n";
        cout << "  [2] Inventory\n";
        cout << "  [3] Ceraikan Waifu\n";
        cout << "  [4] List Waifu\n";
        cout << "  [5] Keluar\n";
        cout << "-----------------------------------------\n";
        cout << "  Pilihanmu(1-5) : ";
        cin >> pilihan;

        if(pilihan == 1){
            gacha(inventory, jumlahWaifu, gems, harga);

        }else if(pilihan == 2){
            fungsiInventory(inventory, jumlahWaifu);

        }else if(pilihan == 3){
            cerai(inventory, jumlahWaifu, gems);

        }else if(pilihan == 4){
            listRarity();

        }else if(pilihan == 5){
            cout << "  Program Ditutup";
        } else {
            cout << "  Pilih yang bener tot";
        }
    } while (pilihan != 5);
    return 0;
}