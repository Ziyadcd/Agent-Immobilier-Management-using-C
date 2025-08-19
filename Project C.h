#ifndef PROJECT_C_H_INCLUDED
#define PROJECT_C_H_INCLUDED
typedef struct Date{
int jour;
int mois;
int annee;
}Date;
typedef struct Propriete{
int id_Pro;
char adresse[100];
char type[30];
int chambres;
char Quartie[40];
int salles_de_bain;
float prix;
struct Propriete*next;
struct Propriete*prec;
}Propriete;

typedef struct transaction{
int id_transaction;
int id_Pro;
char type_tra[20];
float prix_vente;
Date date;
char Nom_agent[20];
struct transaction*next;
}transaction;

typedef struct Used{
int inc;
char agant[20];
}Used;
typedef struct Used2{
float Prix;
char adresse[60];
}Used2;
#endif
