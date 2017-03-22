//
//  stacklist.c
//  Prak10
//
//  Created by Richard Matthew on 11/2/16.
//  Copyright (c) 2016 MatthewRichard20. All rights reserved.
//
/* File : stacklist.h */

#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>
#include "stacklist.h"

/* Prototype manajemen memori */

void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
 Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    
    *P = (address) malloc((1)*sizeof(infotype));
    if ((*P)!=Nil)
    {
        Info(*P)=X;
        Next(*P)=Nil;
        
    }
}

void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    free(P);
}
/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
    return (Top(S) == Nil);
}
void CreateEmpty (Stack * S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
{
    Top(*S) = Nil;
}
void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{ address p;
    
    Alokasi(&p, X);
    if (p!=Nil)
    {
        if (!(IsEmpty(*S)))
            {
                Next(p) = Top(*S);
            }
        
        Top(*S) = p;
        InfoTop(*S)= Info(p);
    }
}
void Pop (Stack * S, infotype * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
    address p;
    
    p = Top(*S);
    *X = Info(p);
    if(Next(p) == Nil)
    {
        Top(*S) = Nil;
    }
    else
    {
        
    Top(*S) = Next(p);
    InfoTop(*S) = Info(Next(p));
    }
    
    Dealokasi(p);
    
}