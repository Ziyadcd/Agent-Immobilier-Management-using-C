#ifndef RAPPORT_H_INCLUDED
#define RAPPORT_H_INCLUDED

void Rapport_G(transaction *headT,Propriete*headP,int mois){

 float moyder=0,moyacc=0;
int incre=0;

int j=0;
int totale_tran=0,maison=0,appart=0,terr=0,autre=0,moin_200=0,plus_500=0,between200k500=0,quarteA=0,quarteB=0,quarteC=0,Totale_mois_dernier=0,Sud=0,Nord=0,Est=0,Central=0,quarteD=0;

float vente=0,location=0,PrixADM=0,PrixADDM=0;
if(headT==NULL || headP==NULL){
    printf("Tu as pas Des Proprieter\n");
    return;
}

Propriete *tempP=headP;
transaction *tempT=headT;

while(tempT!=NULL){
       if(tempT->date.mois==mois){
    totale_tran++;
    if(tempT->prix_vente<200000)
        moin_200++;
     if(tempT->prix_vente>=200000 && tempT->prix_vente<500000)
        between200k500++;
        if(tempT->prix_vente>500000)
            plus_500++;
    if(strcmp(tempT->type_tra,"vente")==0)
        vente+=tempT->prix_vente;
    if(strcmp(tempT->type_tra,"location")==0)
        location+=tempT->prix_vente;


       }else if(tempT->date.mois==mois-1){
       Totale_mois_dernier++;
       PrixADDM+=tempT->prix_vente;
       }
    tempT=tempT->next;
}
tempT=headT;
printf("1.Total des Transactions : %d\n\n",totale_tran);
printf("2. Revenus Totaux :\n\n");
printf("- Ventes : $%2.f\n\n",vente);
printf("- Locations : $%2.f\n\n",location);
printf("- Totale :$%2.f\n\n",location+vente);
while(tempP!=NULL){
    while(tempT!=NULL){
        if(tempP->id_Pro==tempT->id_Pro && tempT->date.mois==mois && strcmp(tempP->type,"Appartement")==0)
        {appart++;}
        if(tempP->id_Pro==tempT->id_Pro && tempT->date.mois==mois && strcmp(tempP->type,"Maison")==0)
         {maison++;}
        if(tempP->id_Pro==tempT->id_Pro && tempT->date.mois==mois && strcmp(tempP->type,"Terrain")==0)
           {terr++;}
        if(tempP->id_Pro==tempT->id_Pro && tempT->date.mois==mois && strcmp(tempP->type,"Appartement")!=0 &&  strcmp(tempP->type,"Maison")!=0 && strcmp(tempP->type,"Terrain")!=0 )
            {autre++;}
        tempT=tempT->next;
    }
    tempT=headT;
    tempP=tempP->next;
}
printf("3. Repartition des Transactions par Type de Propriete :\n\n");
printf("- Appartement : %d Transactions\n\n",appart);
printf("- Maison : %d Transactions\n\n",maison);
printf("- Terrain : %d Transactions\n\n",terr);
printf("- Autre : %d\n\n",autre);
printf("4. Repartition des Transactions par Prix :\n\n");
printf("- Moins de $200,000 : %d transactions\n\n",moin_200);
printf("- $200,000 - $500,000 : %d transactions\n\n",between200k500);
printf("- Plus de $500,000 : %d transactions\n\n",plus_500);
printf("5. Top 3 des Agents Immobiliers Performants :\n\n");
Trie_les_Agant(headT);
printf("6. Tendances du Marche Immobilier : \n\n");
if(Totale_mois_dernier!=0){
PrixADM=((totale_tran-Totale_mois_dernier)/(float)(Totale_mois_dernier+totale_tran))*100;
PrixADM<0 ? printf("- Le nombre de transactions a Diminuer de %.0f%% par rapport au mois dernier\n\n",-PrixADM) :(PrixADM==0 ? printf("- Le nombre de transactions reste stable par rapport au mois dernier\n\n")
                                                                                                                 : printf("- Le nombre de transactions a Augmenter de %.0f%% par rapport au mois dernier\n\n",PrixADM));
}else{
printf("Il y a aucun Transactions Dernier Mois\n\n");
}
PrixADM=(((location+vente)-PrixADDM)/(float)((location+vente)+PrixADDM))*100;
PrixADM<0 ? printf("- Les prix moyens des proprietes ont diminuer de %.0f%% par rapport au mois dernier\n\n",-PrixADM) :(PrixADM==0 ? printf("- Les prix moyens des proprietes reste stable par rapport au mois dernier\n\n")

                                                                                             : printf("- Le nombre de transactions a Augmenter de %.0f%% par rapport au mois dernier\n\n",PrixADM));

Propriete*minihead=NULL;
tempP=headP;
tempT=headT;
Propriete RR;
              while(tempP!=NULL){
                while(tempT!=NULL){
                    if(tempP->id_Pro==tempT->id_Pro && tempT->date.mois==mois){
                            RR.id_Pro=tempP->id_Pro;
                    RR.prix=tempP->prix;
                    RR.salles_de_bain=tempP->salles_de_bain;
                    RR.chambres=tempP->chambres;
                    strcpy(RR.adresse,tempP->adresse);
                    strcpy(RR.Quartie,tempP->Quartie);
                    strcpy(RR.type,tempP->type);
                        ajouter_debut(&minihead,RR);
                    }
                    tempT=tempT->next;
                }
                tempP=tempP->next;
              }
Trie_les_Type_App(minihead);
printf("\n\n7.Principales Zones geographiques :\n\n");
Trie_les_Quartie_aff(minihead);
Meilleur_adresse(headP,headT,mois);
printf("\n\nCe rapport fournit un aperçu complet des activites immobilieres du mois, y compris les revenus generes la repartition des transactions par type de propriete et par prix, les performances des agents immobiliers, les tendances du marche, les zones geographiques les plus actives, et des analyses specifiques sur certaines proprietes et quartiers. \n");
free(minihead);

}


#endif
