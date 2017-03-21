#include <stdio.h>
#include <stdlib.h>
#include "pohon.h"
//#include "stringMandiri.h"

/*** Konstruktor ***/
paddress Allocate (float X) {	
	//kamus lokal
	paddress P;
	//algoritma lokal
	P = (paddress) malloc (sizeof(node));
	if (P != Nil_Tree)
	{
		Info(P) = X;
		Visited(P) = false;
		Prev(P) = Nil_Tree;
		Next1(P) = Nil_Tree;
		Next2(P) = Nil_Tree;
		Next3(P) = Nil_Tree;
	}
  return P;
}
/* I.S. sembarang */
/* F.S. mengalokasi P, menghasilkan Nil_Tree jika gagal */

TriTree Tree (float X, TriTree N1, TriTree N2, TriTree N3) {
//I.S. Sembarang
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon  P dari A, N1, dan N2, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil_Tree) jika alokasi gagal 
	//kamus lokal
	paddress P;
	//algoritma lokal
	P = Allocate(X);
	if (P != Nil_Tree) {
		if ((Prev(N1) == Nil_Tree) && (Prev(N2) == Nil_Tree) && (Prev(N3) == Nil_Tree)) {
			Next1(P) = N1;
			if (N1 != Nil_Tree) {
				Prev(N1) = P;
			}
			Next2(P) = N2;
			if (N2 != Nil_Tree) {
				Prev(N2) = P;
			}
			Next3(P) = N3;
			if (N3 != Nil_Tree) {
				Prev(N3) = P;
			}
		} else {
			printf("Tidak valid\n");
		}
	}
	return P;
}
/*
void MakeTree (int X, TriTree N1, TriTree N2, TriTree N3, TriTree *P) {
//I.S. Sembarang 
//F.S. Menghasilkan sebuah pohon P 
//Menghasilkan sebuah pohon  P dari A, N1, dan N2, jika alokasi berhasil 
//Menghasilkan pohon P yang kosong (Nil_Tree) jika alokasi gagal 
	*P = Allocate(X);
	if (*P != Nil_Tree) {
		Next1(P) = N1;
		if (N1 != Nil_Tree) {
			Prev(N1) = P;
		}
		Next2(P) = N2;
		if (N2 != Nil_Tree) {
			Prev(N2) = P;
		}
		Next3(P) = N3;
		if (N3 != Nil_Tree) {
			Prev(N3) = P;
		}
	}
}
*/
/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (TriTree P) {
	return (P==NULL);
}
//Mengirimkan true jika P adalah pohon biner kosong

boolean IsOneElmt (TriTree P) {
	return (!IsTreeEmpty(P) && (IsTreeEmpty(Next1(P)) && IsTreeEmpty(Next2(P)) && IsTreeEmpty(Next3(P))));
}
//Mengirimkan true jika P adalah pohon biner tidak kosong dan
//hanya memiliki 1 elemen

void PrintTrace (TriTree P) {
	//Kamus Lokal
	
	//Algoritma
	if (Prev(P) == Nil_Tree) {
		printf("%.2f", Info(P));
	} else {
		PrintTrace(Prev(P));
		printf("->%.2f", Info(P));
	}
}

float* PrintTraceToArray (TriTree P) {
	//Kamus Lokal
	paddress PTemp;
	float *a;
	int i;
	//Algoritma
	a = (float*) malloc (Level(P) + 1);
	PTemp = P;
	i = Level(P);
	while (PTemp != Nil_Tree) {
		a[i] = Info(PTemp);
		PTemp = Prev(PTemp);
		i--;
	}
	return a;
}
/*
paddress BackTrack(paddress CurP) {
	//kamus lokal
	paddress P;
	boolean stop;
	//algoritma lokal
	if (Prev(P) == Nil_Tree) {
		if (Visited(Next1(P)) && Visited(Next2(P)) && (Visited(Next3(P)))) {
			return Nil_Tree;
		} else {
			return P;
		}
	} else {
		BackTrack(Prev(P));
	}
}
*/
void InsertAfter(paddress P, float X, paddress *Pt) {
	//kamus lokal
	//algoritma lokal
	if (Next1(P) == Nil_Tree) {
		*Pt = Allocate(X);
		Next1(P) = *Pt;
		Prev(*Pt) = P;
	} else if (Next2(P) == Nil_Tree) {
		*Pt = Allocate(X);
		Next2(P) = *Pt;
		Prev(*Pt) = P;
	} else if (Next3(P) == Nil_Tree) {
		*Pt = Allocate(X);
		Next3(P) = *Pt;
		Prev(*Pt) = P;
	} else {
		printf("Dah penuh sayang\n");
	}
}

int Level(TriTree T1) {
	//kamus lokal
	int l;
	paddress P;
	//algoritma lokal
	l=0;
	P = T1;
	while (Prev(P) != Nil_Tree) {
		P = Prev(P);
		l++;
	}
	return l;
}
