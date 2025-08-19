#ifndef LES_FONCTION_H_INCLUDED
#define LES_FONCTION_H_INCLUDED

void ajouter_debut(Propriete**head,Propriete value){
    Propriete *nv = malloc(sizeof(Propriete));
    strcpy(nv->adresse,value.adresse);
    strcpy(nv->type,value.type);
    strcpy(nv->Quartie,value.Quartie);
    nv->chambres=value.chambres;
    nv->id_Pro=value.id_Pro;
    nv->prix=value.prix;
    nv->salles_de_bain=value.salles_de_bain;
    nv->next=NULL;
    nv->prec=NULL;
if(*head==NULL){
        *head=nv;
        return;
}
nv->next=*head;
(*head)->prec=nv;
*head=nv;
}


void ajouter_fin(Propriete **fin,Propriete value){
    Propriete *nv = malloc(sizeof(Propriete));
        strcpy(nv->adresse,value.adresse);
    strcpy(nv->type,value.type);
    nv->chambres=value.chambres;
    nv->id_Pro=value.id_Pro;
    nv->prix=value.prix;
     strcpy(nv->type,value.type);
    strcpy(nv->Quartie,value.Quartie);
    nv->salles_de_bain=value.salles_de_bain;
    nv->next=NULL;
    nv->prec=NULL;
    nv->next=NULL;
    nv->prec=NULL;
    if(*fin==NULL){
        *fin=nv;
    }
    (*fin)->next=nv;
    nv->prec=*fin;
    *fin=nv;
}

void Ajouter_apres_P(Propriete **fin,int id,Propriete value){
Propriete *nv = malloc(sizeof(Propriete));
        strcpy(nv->adresse,value.adresse);
    strcpy(nv->type,value.type);
    nv->chambres=value.chambres;
     strcpy(nv->type,value.type);
    strcpy(nv->Quartie,value.Quartie);
    nv->id_Pro=value.id_Pro;
    nv->prix=value.prix;
    nv->salles_de_bain=value.salles_de_bain;
    nv->next=NULL;
    nv->prec=NULL;
    nv->next=NULL;
    nv->prec=NULL;
    Propriete *temp=*fin;
    if(*fin==NULL)
    {*fin=nv;
    return;
    }
    while(temp->prec!=NULL){
            if(temp->id_Pro==id){
                nv->next=temp->next;
                temp->next->prec=nv;
                temp->next=nv;
                nv->prec=temp;
                return;
            }
        temp=temp->prec;
    }
    ajouter_fin(fin,value);
}

void Suppression_debut(Propriete**head,transaction **head2){
if(*head==NULL){
printf("Tu as deja pas de Propriete !!\n");
return;
}
Propriete *temp=*head;
transaction*temp2=NULL;
transaction*temp3=*head2;

  if(head2!=NULL){
        while(temp3!=NULL){

            if(temp3->id_Pro==temp->id_Pro){
    transaction*deleted=temp3;
        transaction *next=temp3->next;

if(temp2==NULL){
    *head2=temp3->next;
}else{
                temp2->next=temp3->next;
            }
            free(deleted);
            temp3=next;
            }else{
            temp2=temp3;
            temp3=temp3->next;
            }
        }
    }
    if(temp->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
*head=(*head)->next;
free(temp);
(*head)->prec=NULL;
}

void Suppression_fin(Propriete **fin,transaction**head2){


if(*fin==NULL){
printf("Tu as deja pas de Propriete !!\n");
return;
}
Propriete *temp=*fin;
transaction*temp2=NULL;
transaction*temp3=*head2;
    if(head2!=NULL){
        while(temp3!=NULL){

            if(temp3->id_Pro==temp->id_Pro){
    transaction*deleted=temp3;
        transaction *next=temp3->next;

if(temp2==NULL){
    *head2=temp3->next;
}else{
                temp2->next=temp3->next;
            }
            free(deleted);
            temp3=next;
            }else{
            temp2=temp3;
            temp3=temp3->next;
            }
        }
    }
     if(temp->prec==NULL){
        free(*fin);
        *fin=NULL;
        return;
    }
*fin=(*fin)->prec;
free(temp);
(*fin)->next=NULL;
}

void Suppression_apres_P(Propriete **fin,Propriete **head,int id,transaction**head2){
if(*head==NULL){
printf("Tu as deja pas de Propriete !!\n");
return;
}
Propriete *temp=*head;
Propriete *temp2,*temp3;
transaction*temp4=NULL;
transaction*temp5=*head2;
while(temp!=NULL && temp->id_Pro!=id){
    temp=temp->next;
}
if(temp==NULL){
    printf("Id exist Pas!!\n");
    return;
}
        temp2=temp->next;
        while(temp2!=NULL){
                if(head2!=NULL){
        while(temp5!=NULL){
            if(temp5->id_Pro==temp2->id_Pro){
                    transaction *deleted=temp5;
            transaction *next=temp5->next;

if(temp4==NULL){
    *head2=temp5->next;
    free(deleted);
}else{
                temp4->next=temp5->next;
                free(deleted);
            }
            temp5=next;
            }else{
            temp4=temp5;
            temp5=temp5->next;
            }
        }
temp4=NULL;
temp5=*head2;
    }
temp3=temp2;
temp2=temp2->next;
free(temp3);
        }

        temp->next=NULL;
        *fin=temp;
        return;

}
void free_all(Propriete**head){
if(*head==NULL)return;
Propriete*temp=*head;
while(temp!=NULL){
    (*head)=(*head)->next;
    free(temp);
    temp=*head;
}

}

#endif
