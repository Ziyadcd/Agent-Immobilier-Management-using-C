#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED


void Ajouter_transaction(transaction**head,Propriete*head2,transaction V){
    int Valide=0;
    Propriete*temp=head2;
    while(temp!=NULL){
        if(temp->id_Pro==V.id_Pro)
        {
            Valide=1;
            break;
        }
       temp=temp->next;
    }
    if(Valide==1){
    transaction *nv=malloc(sizeof(transaction));
    nv->next=NULL;
    nv->date=V.date;
    nv->id_Pro=V.id_Pro;
        strcpy(nv->type_tra,V.type_tra);
    nv->id_transaction=V.id_transaction;
    strcpy(nv->Nom_agent,V.Nom_agent);
    nv->prix_vente=V.prix_vente;
transaction *temp2=*head;
if(temp2==NULL){
    *head=nv;
    printf("Bien Cree\n");
    return;
}
while(temp2->next!=NULL)
    temp2=temp2->next;
temp2->next=nv;
}else{
printf("Problem Id de proprieter pas correcte\n");
return;
}
}
#endif
