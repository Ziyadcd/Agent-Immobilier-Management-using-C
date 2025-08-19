#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"Project C.h"
#include"les Fonction.h"
#include"transaction.h"
#include"Fonction_avancer.h"
#include "Rapport.h"
#include"Affichage.h"

int main()
{
            int so;
    int choix,minchambre,Rech,i;
    float prixmin,prixmax,montant;
    Date D;
 Propriete *head=NULL;
 Propriete *Fin=NULL;
 char add[40],type[20];
 Propriete Nv;
 Propriete Nv1;
 transaction*head2=NULL;
 int pos,pos2;
do{
            printf("----------------Choisier votre Choix----------------\n\n");
    printf("1.Ajout une propriete\n");
    printf("2.Modification une propriete\n");
    printf("3.Suppression une propriete\n");
    printf("4.Recherche une propriete\n");
    printf("5.Afficher les transactions recentes\n");
    printf("6.Generer des rapports et des analyses\n");
    printf("7.Ajouter une Transaction \n");
    printf("8.Afficher Proprieter\n");
    printf("9.Quitter\n");
    scanf("%d",&choix);
    system("cls");
    switch (choix){
case 1:
    do{     printf("1.Ajouter Debut une propriete\n");
    printf("2.Ajouter apres une propriete specifique\n");
    printf("3.Ajouter Fin une propriete\n");
    printf("0.Return\n");
    scanf("%d",&i);
    system("cls");
    switch (i){
  case 1:
  printf("Donner le Id de Proprieter: \n");
  scanf("%d",&Nv1.id_Pro);
  printf("Donner le nombre des chambres : \n");
  scanf("%d",&Nv1.chambres);
  printf("Donner le nombre des salles de bain : \n");
  scanf("%d",&Nv1.salles_de_bain);
  printf("Donner l'addresse : \n");
  scanf("%s",Nv1.adresse);
  printf("Donner le Quartie : \n");
  scanf("%s",Nv1.Quartie);
  printf("Donner le Type de Propriete : \n");
  scanf("%s",Nv1.type);
  printf("Donner le Prix\n");
  scanf("%f",&Nv1.prix);
  ajouter_debut(&head,Nv1);
  if(head->next==NULL)
    {Fin=head;}
          system("cls");
    break;
  case 2:
    printf("Apres quel Id\n");
    scanf("%d",&pos);
    printf("Donner le Id de Proprieter: \n");
  scanf("%d",&Nv1.id_Pro);
  printf("Donner le nombre des chambres : \n");
  scanf("%d",&Nv1.chambres);
  printf("Donner le nombre des salles de bain : \n");
  scanf("%d",&Nv1.salles_de_bain);
  printf("Donner l'addresse : \n");
  scanf("%s",Nv1.adresse);
  printf("Donner le Quartie : \n");
  scanf("%s",Nv1.Quartie);
  printf("Donner le Type de Propriete : \n");
  scanf("%s",Nv1.type);
  Ajouter_apres_P(&Fin,pos,Nv1);
  if(Fin->prec==NULL){
        head=Fin;
  }
      system("cls");
  break;
  case 3:
       printf("Donner le Id de Proprieter: \n");
  scanf("%d",&Nv1.id_Pro);
  printf("Donner le nombre des chambres : \n");
  scanf("%d",&Nv1.chambres);
  printf("Donner le nombre des salles de bain : \n");
  scanf("%d",&Nv1.salles_de_bain);
  printf("Donner l'addresse : \n");
  scanf("%s",Nv1.adresse);
  printf("Donner le Quartie : \n");
  scanf("%s",Nv1.Quartie);
  printf("Donner le Type de Propriete : \n");
  scanf("%s",Nv1.type);
  printf("Donner le Prix\n");
  scanf("%f",&Nv1.prix);
ajouter_fin(&Fin,Nv1);
  if(Fin->prec==NULL)
    {head=Fin;}
          system("cls");
    break;
    case 0:
        break;
 default :
    printf("Invalide Choix!!\n");
    exit(1);
    break;
    }}while(i!=0);
break;
 case 2:
        printf("Quel Propriete tu veux Modifier ?\n");
        scanf("%d",&pos);
        printf("Donner les Nouveux Propriete:\n");
        printf("Nouveux Nombre des chambres:\n");
        scanf("%d",&Nv.chambres);
         printf("Nouveux Nombre des Salles de baine:\n");
        scanf("%d",&Nv.salles_de_bain);
                system("cls");
        modify_P(&head,pos,Nv);
             break;

case 3:
    do{
    printf("1.Suppression au debut\n");
    printf("2.Suppression au fin\n");
    printf("3.suppression apres un propriete specifique\n");
        printf("0.Return\n");
scanf("%d",&i);
    switch (i){
  case 1:
    Suppression_debut(&head,&head2);
 system("cls");
    printf("Tu as fais une suppression au debut !!\n");
    break;
  case 2:
    Suppression_fin(&Fin,&head2);
     system("cls");
    printf("Tu as fais une suppression au fin !!\n");
    break;
  case 3:
    printf("Tu veux Supprimer apres quel Id-Proprieter ? :\n");
    scanf("%d",&pos);
    Suppression_apres_P(&Fin,&head,pos,&head2);
     system("cls");
     printf("Tu as fais une suppression des proprieters qui ont suive la proprieter d'id %d\n",pos);
    break;
    case 0:
        break;
  default:
    printf("Invalide Choix !!\n");
    break;
    }
    }while(i!=0);
    break;
case 4:
    do{
        printf("tu veux Recherche par adresse ou Type ou Recherche specifique\n");
        printf("1.adresse\n");
        printf("2.Type\n");
        printf("3.Recherche specifique\n");
        printf("0.return\n");
        scanf("%d",&Rech);
        switch (Rech){
    case 1:
            printf("Donner l'adresse :\n");
            scanf("%s",add);
            system("cls");
            Recherche_Add(&head,add);
            break;
    case 2 :
            printf("Donner Type :\n");
            scanf("%s",type);
            system("cls");
            Recherche_Add(&head,type);
            break;
    case 3:
            printf("Donner le min de prix :\n");
            scanf("%f",&prixmin);
            printf("Donner le max de prix :\n");
            scanf("%f",&prixmax);
             printf("Donner le min de nombre des chambres :\n");
            scanf("%d",&minchambre);
            printf("Donner de type :\n");
            scanf("%s",type);
            system("cls");
            Recherche_Avancer(&head,prixmin,prixmax,type,minchambre);
            break;
    case 0:
        break;

        default:
            printf("Invalide Coix !!\n");
            break;
        }}while(Rech!=0);
break;
case 5:
        system("cls");
        do{
        afficher_transaction_rec(head2);
        printf("0.Return\n");
        scanf("%d",&so);
        switch(so){
    case 0:
        break;
    default:
        printf("Invalide Choix !!\n");
        }
    }while(so!=0);
    system("cls");
    break;

    case 6:
        system("cls");
        int rapp;
        do{
        Rapport_G(head2,head,2);
        printf("\n0.Return\n");
        scanf("%d",&rapp);
        }while(rapp!=0);
            system("cls");
        break;
case 7:
    transaction nv2;
    int j;
    system("cls");
    printf("Donner le id de transaction\n");
    scanf("%d",&nv2.id_transaction);
    printf("Donner le nom d'agent\n");
    scanf("%s",nv2.Nom_agent);
    printf("Donner le id de proprieter\n");
    scanf("%d",&nv2.id_Pro);
    printf("Donner annee\n");
    scanf("%d",&nv2.date.annee);
     printf("Donner mois\n");
    scanf("%d",&nv2.date.mois);
     printf("Donner Jour\n");
    scanf("%d",&nv2.date.jour);
    printf("Donner le Prix\n");
  scanf("%f",&nv2.prix_vente);

do{
    printf("Donner le type de transaction\n");
    printf("1.vente\n");
    printf("2.location\n");
scanf("%d",&j);
        if(j==1)
    strcpy(nv2.type_tra,"vente");
if(j==2)
    strcpy(nv2.type_tra,"location");
}while(j!=1 && j!=2);
            Ajouter_transaction(&head2,head,nv2);
            system("cls");
        break;

case 0:
        break;
case 8:
    system("cls");
        do{
        afficher_Proprieter(head);
        printf("0.Return\n");
        scanf("%d",&so);
        switch(so){
    case 0:
        break;
    default:
        printf("Invalide Choix !!\n");
        break;
        }
    }while(so!=0);
    system("cls");
    break;
case 9:
            exit(1);
            break;
default:
            printf("\n Invalide choix !!\n");
            break;}
}while(choix!=9);
free_all(&head);
free(Fin);
    return 0;
}
