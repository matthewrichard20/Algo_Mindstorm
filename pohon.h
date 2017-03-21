#ifndef pohon_h
#define pohon_h
//#include "Stats_infotype.h"
#include "boolean.h"

#define Nil_Tree NULL

/*** Definisi Type Pohon Biner ***/
typedef struct tNode *paddress;
typedef struct tNode {
	float Info;
	boolean Visited;
	paddress Prev;
	paddress Next1;
	paddress Next2;
	paddress Next3;
} node;
typedef paddress TriTree;

/*** Selektor ***/
#define Info(P) (P)->Info
//Mengirimkan nilai Akar pohon biner P
#define Visited(P) (P)->Visited
//Mengirimkan nilai true jika node sudah dikunjungi
#define Prev(P) (P)->Prev
//Mengirimkan parent dari node P
#define Next1(P) (P)->Next1
//Mengirimkan Anak Kiri pohon biner P
#define Next2(P) (P)->Next2
//Mengirimkan Anak Kanan pohon biner P
#define Next3(P) (P)->Next3
//Menginrimkan Anak tengah

/*** Konstruktor ***/
paddress Allocate (float X);
/* I.S. sembarang */
/* F.S. mengalokasi P, menghasilkan Nil jika gagal */
TriTree Tree (float X, TriTree L, TriTree R, TriTree M);
//Menghasilkan sebuah pohon  dari A, L, R, dan M, jika alokasi berhasil
//Menghasilkan pohon kosong (Nil) jika alokasi gagal

//void MakeTree (char* Akar, boolean B, int lvl, TriTree L, TriTree R, TriTree M, TriTree *P);
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon  P dari A, L, dan R, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal 

//void BuildTree (TriTree *P);
//Membentuk sebuah pohon  P dari pita karakter yang dibaca }
//I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
//Memori pasti cukup, alokasi pasti berhasil. }
//F.S. P dibentuk dari ekspresi dalam pita }

/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (TriTree P);
//Mengirimkan true jika P adalah pohon biner kosong

boolean IsOneElmt (TriTree P);
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen

void PrintTrace (TriTree P);
/* Menuliskan jejak P dimulai dari akar */

//paddress BackTrack(paddress CurP);
/* Mengembalikan parent CurP yang masih memiliki anak yang belum dikunjungi */

void InsertAfter(paddress P, float X, paddress *Pt);
/* Meletakkan node dengan info X jika P masih punya slot */

float* PrintTraceToArray (TriTree P);
/* Menuliskan trace sebuah node pada array */

int Level(TriTree T1);
/* Mengembalikan kedalaman T1 pada pohon */
/* Level parent utama = 0 */

#endif
