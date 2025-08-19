#ifndef FONCTION_AVANCER_H_INCLUDED
#define FONCTION_AVANCER_H_INCLUDED

void modify_P(Propriete**head,int p,Propriete A){
Propriete *temp=*head;
int i=0;
while(i<p && temp!=NULL){
    temp=temp->next;
    i++;
}
if(temp==NULL){
    printf("Propriete exist Pas !!\n");
    return;
}
if(i==p){
    temp->chambres=A.chambres;
    temp->salles_de_bain=A.salles_de_bain;
}
}

void Recherche_Avancer(Propriete **head,float MinPrix,float MaxPrix,char Type[20],int minchambre){
Propriete *temp=*head;
            printf("Les Propriete de type %s et entre %2.f et %2.f avec des chambres grande ou egale a %d Sont : \n",Type,MinPrix,MaxPrix,minchambre);

while(temp!=NULL){
    if(temp->chambres>=minchambre && temp->prix>=MinPrix && temp->prix<=MaxPrix && strcmp(temp->type,Type)==0){
        printf("Propriete d'id %d avec Des chambres %d et Prix de %.f et de Type de %s : \n",temp->id_Pro,temp->chambres,temp->prix,temp->type);

    }
    temp=temp->next;
}

}



void Recherche_Type(Propriete **head,char type[20]){
Propriete*temp=*head;
        printf("les Propriete de type %s Sont :\n",type);

while(temp!=NULL){
    if(strcmp(temp->type,type)==0){
        printf("la Propriete avec Id %d est de type %s\n",temp->id_Pro,type);
    }
    temp=temp->next;
}
}


void Recherche_Add(Propriete **head,char ADD[20]){
Propriete*temp=*head;
        printf("les Proprieters d'adresse %s Sont :\n",ADD);

while(temp!=NULL){
    if(strcmp(temp->adresse,ADD)==0){
        printf("la Proprieters avec id %d a une adresse de %s\n",temp->id_Pro,ADD);
    }
        temp=temp->next;

}
}




void Trie_les_Agant(transaction*head){
    int N=0,i,j;
    transaction*temp=head;
    Used *T=(Used*)malloc(sizeof(Used)*200);
if(head==NULL){
    printf("Tu as Pas des Agants !!\n");
        return;
}
while(temp!=NULL){
    strcpy(T[N].agant,temp->Nom_agent);
    T[N].inc=0;
    N++;
    temp=temp->next;
}

for(i=0;i<N;i++)
for(j=0;j<N;j++){
    if(strcmp(T[i].agant,T[j].agant)==0)
        T[i].inc++;
}
int k;
for(i=0;i<N;i++)
for(j=i+1;j<N;){
    if(strcmp(T[i].agant,T[j].agant)==0)
    {
        for(k=j;k<N-1;k++)
            {
                T[k]=T[k+1];
            }
            N--;

    }else{
    j++;
    }
}
for(i=0 ;i<3 ;i++){
            printf("Agant %s : %d transaction\n\n",T[i].agant,T[i].inc);
    if(strcmp(T[i].agant,T[i+1].agant)==0 && T[i].inc==T[i+1].inc)
    break;
}

free(T);

}





char* Trie_les_Quartie(Propriete*head){
    int N=0,i,j;
    Propriete*temp=head;
    Used *T=(Used*)malloc(sizeof(Used)*200);
if(head==NULL){
    printf("Tu as Pas des Quartie !!\n");
        exit(1);
}
while(temp!=NULL){
    strcpy(T[N].agant,temp->Quartie);
    T[N].inc=0;
    N++;
    temp=temp->next;
}

for(i=0;i<N;i++)
for(j=0;j<N;j++){
    if(strcmp(T[i].agant,T[j].agant)==0)
        T[i].inc++;
}

int k;
for(i=0;i<N;i++)
for(j=i+1;j<N;){
    if(strcmp(T[i].agant,T[j].agant)==0)
    {
        for(k=j;k<N-1;k++)
            {
                T[k]=T[k+1];
            }
            N--;

    }else{
    j++;
    }
    }
    Used L;
    for(i=0;i<N;i++)
    for(j=i+1;j<N;j++){
        if(T[i].inc<T[j].inc){
          L=T[i];
          T[i]=T[j];
          T[j]=L;
        }
    }
    char *GG=malloc(strlen(T[0].agant)+1);
    strcpy(GG,T[0].agant);
    free(T);
return GG ;
}





void Trie_les_Type_App(Propriete*head){
    int N=0,i,j;
    Propriete*temp=head;
    Used *T=(Used*)malloc(sizeof(Used)*200);
if(head==NULL){
    printf("Tu as Pas des Quartie !!\n");
        exit(1);
}
while(temp!=NULL){
    strcpy(T[N].agant,temp->type);
    T[N].inc=0;
    N++;
    temp=temp->next;
}

for(i=0;i<N;i++)
for(j=0;j<N;j++){
    if(strcmp(T[i].agant,T[j].agant)==0)
        T[i].inc++;
}

int k;
for(i=0;i<N;i++)
for(j=i+1;j<N;){
    if(strcmp(T[i].agant,T[j].agant)==0)
    {
        for(k=j;k<N-1;k++)
            {
                T[k]=T[k+1];
            }
            N--;

    }else{
    j++;
    }
    }
    Used L;
    for(i=0;i<N;i++)
    for(j=i+1;j<N;j++){
        if(T[i].inc<T[j].inc){
          L=T[i];
          T[i]=T[j];
          T[j]=L;
        }
    }
    char *GG=Trie_les_Quartie(head);
    printf("-La demande pour les %ss et les %ss reste elevee, en particulier dans les quartiers %s",T[0].agant,T[1].agant,GG);
}

void Trie_les_Quartie_aff(Propriete*head){
    int N=0,i,j;
    Propriete*temp=head;
    Used *T=(Used*)malloc(sizeof(Used)*200);
if(head==NULL){
    printf("Tu as Pas des Quartie !!\n");
        exit(1);
}
while(temp!=NULL){
    strcpy(T[N].agant,temp->Quartie);
    T[N].inc=0;
    N++;
    temp=temp->next;
}

for(i=0;i<N;i++)
for(j=0;j<N;j++){
    if(strcmp(T[i].agant,T[j].agant)==0)
        T[i].inc++;
}

int k;
for(i=0;i<N;i++)
for(j=i+1;j<N;){
    if(strcmp(T[i].agant,T[j].agant)==0)
    {
        for(k=j;k<N-1;k++)
            {
                T[k]=T[k+1];
            }
            N--;

    }else{
    j++;
    }
    }
    Used L;
    for(i=0;i<N;i++)
    for(j=i+1;j<N;j++){
        if(T[i].inc<T[j].inc){
          L=T[i];
          T[i]=T[j];
          T[j]=L;
        }
    }
 for(i=0;i<N;i++){
    printf("%s : %d\n\n",T[i].agant,T[i].inc);
    if(i==2)
        break;
 }
    free(T);

}







void Meilleur_adresse(Propriete*head,transaction*head2,int mois){
if(head==NULL)
{
    printf("Pas des Proprieter\n");
    return;
}
int N=0;
Used2 *T=(Used2*)malloc(sizeof(Used2)*200);
Propriete*temp=head;
transaction*temp2=head2;
for(int k=0 ;k<200;k++){
    T[k].Prix=0;
}
while(temp!=NULL){
    while(temp2!=NULL){
    if(temp->id_Pro==temp2->id_Pro && temp2->date.mois==mois){
    strcpy(T[N].adresse,temp->adresse);
    T[N].Prix=temp2->prix_vente;
                N++;
                }
        temp2=temp2->next;
    }
    temp2=head2;
    temp=temp->next;
}
int i,j,k;
 for (i=0;i<N;i++) {
        for (j=i+1;j<N;) {
            if (strcmp(T[i].adresse, T[j].adresse) == 0) {
                T[i].Prix += T[j].Prix;
                for (k = j; k < N - 1; k++) {
                    T[k] = T[k + 1];
                }
                N--;
            } else {
                j++;
            }
        }
    }
Used2 L;
  for(i=0;i<N;i++)
    for(j=i+1;j<N;j++){
        if(T[i].Prix<T[j].Prix){
          L=T[i];
          T[i]=T[j];
          T[j]=L;
        }
    }

    printf("- La propriete situee a l'adresse %s a genere le plus de revenus avec un total de $%.0f pour la vente ce mois-ci\n\n",T[0].adresse,T[0].Prix);
    free(T);
}





#endif
