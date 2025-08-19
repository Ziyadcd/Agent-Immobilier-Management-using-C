#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED


void afficher_transaction_rec(transaction*head){
if(head==NULL)
    {
    printf("Rien d'afficher\n");
    return;
    }
    transaction*temp=head;
    while(temp!=NULL){
        printf("la proprieter d'id %d a effectuer une transaction de type %s et d'agent %s a date %d/%d/%d\n",temp->id_Pro,temp->type_tra,temp->Nom_agent,temp->date.jour,temp->date.mois,temp->date.annee);
        temp=temp->next;
    }

}



void afficher_Proprieter(Propriete*head){
if(head==NULL){
    printf("Rien a afficher!!\n");
    return;
}
Propriete *temp=head;
while(temp!=NULL){
    printf("Propriete d'id %d de type %s et Quartie %s a %d chambre et %d salle de baine avec une prix de %2.f\n",temp->id_Pro,temp->type,temp->Quartie,temp->chambres,temp->salles_de_bain,temp->prix);
temp=temp->next;
}
return;
}
#endif // AFFICHAGE_H_INCLUDED
