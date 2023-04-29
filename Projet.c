#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
typedef struct
{
    int jour,mois,annee;
} date;
typedef struct
{
    float EMD,CC,TP;
} notes;
typedef struct
{
    char nom[30];
    float moyenne,moyenneCoeff;
    int coeff,S,TP,nbr;
    notes note;
} modules;
typedef struct
{
    long long int matricule;
    char nom[50],prenom[50],adresse[100], email[50];
    date date;
    float MoyenneS1,MoyenneS2,MoyenneG;
    int groupe,section,nbrmodules;
    modules  Modules[100];
} etudiant;
void trquit(char *rep)
{
    Start:
        fflush(stdin);
        *rep=getchar();
        if(*rep!='n' && *rep!='N' && *rep!='o' && *rep!='O')
        {
            printf("                       Vous Avez Entr%c Un Caractere Different De O Et N. Veuillez R%cessayer: ",130,130);
            goto Start;
        }
}

void quit(char *rep)
{
    printf("                                Voulez-vous Effectuer Une Nouvelle Operation? (O/N): ");
    trquit(rep);
}
int Verif (float *x)
{
       int stop = 0;
do
       {
       scanf("%f", &*x);
       if (*x < 0 || *x > 20)
       {
         printf("                           Erreur ! Vous Devez Entrer Une Note Entre 0 Et 20 !\n\n");
         printf("                           NOTE : ");

       }
       else stop = 1;
       } while (!(stop));
}
int Annee (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1900 || *x > 2020)
       {
         printf("                           Erreur ! Vous Devez Entrer Une Ann%ce Entre 1900 Et 2020 !\n\n",130);
         printf("                           ANNEE : ");

       }
       else stop = 1;
       } while (!(stop));
}
int Mois (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1 || *x > 12)
       {
         printf("                           Vous Devez Entrer Un Mois Entre 1 Et 12 !\n\n");
         printf("                           MOIS : ");

       }
       else stop = 1;
       } while (!(stop));
}
int Jour1 (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1 || *x > 31)
       {
         printf("                           Erreur ! Vous Devez Entrer Un Jour Entre 1 Et 31 !\n\n");
         printf("                           JOUR : ");

       }
       else stop = 1;
       } while (!(stop));
}
int Jour2 (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1 || *x > 30)
       {
         printf("                           Erreur ! Vous Devez Entrer Un Jour Entre 1 Et 30 !\n\n");
         printf("                           JOUR : ");

       }
       else stop = 1;
       } while (!(stop));
}
int Jour3 (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1 || *x > 28)
       {
         printf("                           Erreur ! Vous Devez Entrer Un Jour Entre 1 Et 28 !\n\n");
         printf("                           JOUR : ");

       }
       else stop = 1;
       } while (!(stop));
}
int Jour4 (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1 || *x > 29)
       {
         printf("                           Erreur ! Vous Devez Entrer Un Jour Entre 1 Et 29 !\n\n");
         printf("                           JOUR : ");

       }
       else stop = 1;
       } while (!(stop));
}
void vider_stdin(void)
{
    scanf("%*[^\n]");
    getchar();
}
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

int VerifGroup (int *x)
{
       int stop = 0;
do
       {
       scanf("%d", &*x);
       if (*x < 1 || *x > 4)
       {
         printf("                           Erreur ! Vous Devez Entrer Un Numero Entre 1 et 4 !\n\n");
         printf("                           GROUPE : ");
       }
       else stop = 1;
       } while (!(stop));
}
int menu()
{
    system("mode 650");
    FILE *fptr;
    char c;
    char *filename = "image.txt";
    fptr = fopen(filename, "r");
       if (fptr == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c = fgetc(fptr);
       while (c != EOF)
       {
        printf ("%c", c);
        c = fgetc(fptr);
       }
       fclose(fptr);

  int choix = 0;
while (choix < 1 || choix > 12)
{
    printf("                                                                              Les Choix:\n\n");
    printf("                                                                     1. Creation Liste De Modules\n\n");
    printf("                                                                          2. Ajout D'un Module\n\n");
    printf("                                                                       3. Suppression D'un Module\n\n");
    printf("                                                                      4. Creation Liste D'Etudiants\n\n");
    printf("                                                                         5. Ajout D'un Etudiant\n\n");
    printf("                                                                      6. Modification D'un Etudiant\n\n");
    printf("                                                                      7. Suppression D'un Etudiant\n\n");
    printf("                                                                          8. Afichage Etudiants \n\n");
    printf("                                                                       9. Affichage Moyenne Groupe\n\n");
    printf("                                                                      10. Affichage Moyenne Section\n\n");
    printf("                                                                      11. Affichage Major De Promo\n\n");
    printf("                                                                         12. Quitter Le Programme\n\n");
    printf("                                                                            Votre Choix ?\n\n");
    printf("                                Mon Choix : ");
    scanf("%d", &choix);
    printf("\n\n");
    system("cls");
}
return choix;
}
int main(int argc, char *argv[])
{
    FILE *Etudiant;
    FILE *module;
    FILE *Indice;
    FILE *Ftemp;
    etudiant Etud;
    modules Module;
    float E[100];
    long long int mat,c;
    char rep,nomEt[50], prenomEt[50],Nom[30];
    long pos;
    float NotesGroup1,NotesGroup2,NotesGroup3,NotesGroup4,SommeNotesSection,NotesS1=0,NotesS2=0,max;
    int NombresEtudiantsGroup1,NombresEtudiantsGroup2,NombresEtudiantsGroup3,NombresEtudiantsGroup4,nbrS1=0,nbrS2=0,G,i=1,imax,a,j,N,I,Menu = 1,choice,operation,trouve=0;
    FILE *fptr1;
    char c1;
    char *filename1 ="image1.txt";
    FILE *fptr2;
    char c2;
    char *filename2 ="image2.txt";
    FILE *fptr3;
    char c3;
    char *filename3 ="image3.txt";
    FILE *fptr4;
    char c4;
    char *filename4 ="image4.txt";
    system("mode 650");
    printf("\n");
    printf("\n");
    printf("\n");
    Color(0,15);
    do
    {
       switch (operation = menu())
       {
       case 1:
       printf("\n");
       printf("\n");
       printf("\n");
       printf("                                      Vous Avez Choisis Creation Liste De Modules\n\n");
       printf("                             Veuillez Entrer Les Modules Du S1 : \n\n");
       module=fopen("Module.dat","wb");
       if (module!=NULL)
       {
       printf("                             Est-Ce-Que Le Module Comporte Une Note De TP ? (0/1) : ");
       scanf("%d",&choice);
       printf("\n");
       if(choice==1)
        {
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=1;
       Module.TP=1;
       printf("\n");
       }
       if (choice==0)
       {
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=1;
       Module.TP=0;
       printf("\n");
       }
       }
       fwrite(&Module,sizeof(Module),1,module);
       fclose(module);
       printf("                             Voulez-vous Ajouter Un Nouveau Module S1 ? (O/N): ");
       trquit(&rep);
       printf("\n");
       if (rep=='o' || rep=='O')
       {
        do
        {
            module=fopen("Module.dat","ab");
       if (module!=NULL)
       {
       printf("                             Est-Ce-Que Le Module Comporte Une Note De TP ? (0/1) : ");
       scanf("%d",&choice);
       printf("\n");
       if(choice==1){
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=1;
       Module.TP=1;
       printf("\n");
       }
       if (choice==0)
       {
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=1;
       Module.TP=0;
       printf("\n");
       }
       }
       fwrite(&Module,sizeof(Module),1,module);
       fclose(module);
       printf("                             Voulez-vous Ajouter Un Nouveau Module S1 ? (O/N): ");
       trquit(&rep);
       printf("\n");
        }while(rep=='o' || rep=='O');
       }
       system("cls");
       printf("\n");
       printf("\n");
        printf("                             Veuillez Entrer Les Modules Du S2 : \n\n");
       do
        {
            module=fopen("Module.dat","ab");
       if (module!=NULL)
       {
       printf("                             Est-Ce-Que Le Module Comporte Une Note De TP ? (0/1) : ");
       scanf("%d",&choice);
       printf("\n");
       if(choice==1){
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=2;
       Module.TP=1;
       printf("\n");
       }
       if (choice==0)
       {
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=2;
       Module.TP=0;
       printf("\n");
       }
       }
       fwrite(&Module,sizeof(Module),1,module);
       fclose(module);
       printf("                             Voulez-vous Ajouter Un Nouveau Module S2 ? (O/N): ");
       trquit(&rep);
       printf("\n");
        }while(rep=='o' || rep=='O');
       system("cls");
       break;
       case 2:
       printf("\n");
       printf("\n");
       printf("\n");
       printf("                                      Vous Avez Choisis Ajout D'un Module");
       do
        {
       printf("\n");
       printf("\n");
       printf("                             Semestre : ");
       scanf("%d",&choice);
       printf("\n");
       if(choice==1){
       printf("                             Veuillez Entrer Les Modules Du S1 : \n\n");
        do
        {
            module=fopen("Module.dat","ab");
       if (module!=NULL)
       {
       printf("\n");
       printf("                             Est-Ce-Que Le Module Comporte Une Note De TP ? (0/1) : ");
       scanf("%d",&choice);
       printf("\n");
       if(choice==1){
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=1;
       Module.TP=1;
       printf("\n");
       }
       if (choice==0)
       {
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=1;
       Module.TP=0;
       printf("\n");
       }
       }
       fwrite(&Module,sizeof(Module),1,module);
       fclose(module);
       printf("                             Voulez-vous Ajouter Un Nouveau Module S1 ? (O/N): ");
       trquit(&rep);
       printf("\n");
        }while(rep=='o' || rep=='O');
        system("cls");
       }
       if(choice == 2)
       {
        printf("                             Veuillez Entrer Les Modules Du S2 : \n\n");
       do
        {
            module=fopen("Module.dat","ab");
       if (module!=NULL)
       {
           printf("\n");
       printf("                             Est-Ce-Que Le Module Comporte Une Note De TP ? (0/1) : ");
       scanf("%d",&choice);
       printf("\n");
       if(choice==1){
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=2;
       Module.TP=1;
       printf("\n");
       }
       if (choice==0)
       {
       printf("                         Nom Module : ");
       fflush(stdout);
       scanf(" %[^\n]", Module.nom);
       vider_stdin();
       printf("\n");
       printf("                         Coefficion Module : ");
       scanf("%d",&Module.coeff);
       Module.S=2;
       Module.TP=0;
       printf("\n");
       }
       }
       fwrite(&Module,sizeof(Module),1,module);
       fclose(module);
       printf("                             Voulez-vous Ajouter Un Nouveau Module S2 ? (O/N): ");
       trquit(&rep);
       printf("\n");
        }while(rep=='o' || rep=='O');
        system("cls");
       }
       printf("\n");
       printf("\n");
       printf("                             Voulez-vous Ajouter Un Nouveau Module ? (O/N): ");
       trquit(&rep);
       printf("\n");
       system("cls");
        }while(rep=='o' || rep=='O');
       break;
       case 3:
       printf("\n");
       printf("\n");
       printf("\n");
       printf("                                      Vous Avez Choisis Suppression D'un Module\n\n");
       do
       {
        N=0;
        module=fopen("Module.dat","rb");
        if(module!=NULL)
        {
          while(fread(&Module,sizeof(Module),1,module))
         {
             N++;
         }
        }
        fclose(module);
        module=fopen("Module.dat","rb");
        Ftemp=fopen("temp.dat","wb+");
        if(module!=NULL && Ftemp!=NULL)
       {
        printf("\n");
        printf("\n");
        printf("                              Veuillez Entrer Le Nom Du Module A Supprimer\n\n");
        printf("                         Nom Module : ");;
        fflush(stdin);
        gets(Nom);
        while(fread(&Module,sizeof(Module),1,module))
        {
         if(strcmp(Module.nom,Nom))  fwrite(&Module,sizeof(Module),1,Ftemp);
        }
       }
        fclose(module);
        fclose(Ftemp);
        remove("Module.dat");
        rename("temp.dat","Module.dat");
        printf("\n");
        G=0;
        module=fopen("Module.dat","rb");
        if(module!=NULL)
        {
          while(fread(&Module,sizeof(Module),1,module))
         {
             G++;
         }
        }
        fclose(module);
        if(G<N) printf("                              Le Module %s Est Supprim%c\n\n",Nom,130);
         else   printf("                              Module Non Trouv%c.\n",130);

       printf("\n");
       printf("\n");
       printf("                               Voulez-vous Supprimer Un Autre Module ? (O/N): ");
       trquit(&rep);
       printf("\n");
       system("cls");
        }while(rep=='o' || rep=='O');
       break;
       case 4:
       printf("\n");
       printf("\n");
       printf("\n");
       printf("                                      Vous Avez Choisis Creation Liste D'Etudiants\n\n");
       Etudiant=fopen("Etudiant.dat","wb");
       if (Etudiant!=NULL)
       {
       i=1;
       printf("                             Veuillez Entrer Les informations de l'Etudiant Numero %d  : \n\n",i);
       printf("                          NOM : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.nom);
       vider_stdin();
       printf("                          PRENOM : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.prenom);
       vider_stdin();
       printf("                          SECTION : ");
       scanf("%d",&Etud.section);
       printf("                          GROUPE : ");
       VerifGroup(&Etud.groupe);
       printf("                          MATRICULE : ");
       scanf("%lld",&Etud.matricule);
       printf("                          ADRESSE : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.adresse);
       vider_stdin();
       printf("                          EMAIL : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.email);
       vider_stdin();
       printf("                          DATE DE NAISSANCE : \n");
       printf("                          ANNEE : ");
       Annee(&Etud.date.annee);
       if (Etud.date.annee%400 == 0 || (Etud.date.annee%4 == 0 && Etud.date.annee%100 != 0))
       {
       printf("                          MOIS : ");
       Mois(&Etud.date.mois);
       if(Etud.date.mois == 4 || Etud.date.mois == 6 || Etud.date.mois == 9 || Etud.date.mois == 11)
       {
       printf("                          JOUR : ");
       Jour2(&Etud.date.jour);
       }
       else if (Etud.date.mois == 2)
       {
       printf("                          JOUR : ");
       Jour4(&Etud.date.jour);
       }
       else
       {
        printf("                          JOUR : ");
       Jour1(&Etud.date.jour);
       }
       }
       else
       {
        printf("                          MOIS : ");
       Mois(&Etud.date.mois);
       if(Etud.date.mois == 4 || Etud.date.mois == 6 || Etud.date.mois == 9 || Etud.date.mois == 11)
       {
       printf("                          JOUR : ");
       Jour2(&Etud.date.jour);
       }
       else if (Etud.date.mois == 2)
       {
       printf("                          JOUR : ");
       Jour3(&Etud.date.jour);
       }
       else
       {
        printf("                          JOUR : ");
       Jour1(&Etud.date.jour);
       }
       }
       system("cls");
       printf("\n");
       printf("\n");
       a=0;
       module=fopen("Module.dat","rb");
       if (module!=NULL)
       {
           while(!feof(module))
           {
               fread(&Module,sizeof(Module),1,module);
               a++;
           }
       }
       fclose(module);
       Etud.nbrmodules=a-1;
       printf("                             Module S1 : \n\n");
       printf("                             Module TP : \n\n");
       module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       j=0;
                NotesS1=0;nbrS1=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 1 && Module.TP == 1)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           printf("                           TP : ");
           Verif(&Module.note.TP);
           Etud.Modules[j].note.TP=Module.note.TP;
           Module.moyenne=0.6*Module.note.EMD+0.4*((Module.note.TP+Module.note.CC)/2);
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS1=NotesS1+Module.moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
           j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
         printf("                             Module Sans TP : \n\n");
         module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 1 && Module.TP == 0)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           Module.moyenne=0.6*Module.note.EMD+0.4*Module.note.CC;
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS1=NotesS1+Module.moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
          j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
          printf("                             Module S2 : \n\n");
          printf("                             Module Avec TP : \n\n");
          module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                NotesS2=0;nbrS2=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 2 && Module.TP == 1)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           printf("                           TP : ");
           Verif(&Module.note.TP);
           Etud.Modules[j].note.TP=Module.note.TP;
           Module.moyenne=0.6*Module.note.EMD+0.4*((Module.note.TP+Module.note.CC)/2);
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS2=NotesS2+Module.moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
         printf("                             Module Sans TP : \n\n");
         module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 2 && Module.TP == 0)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           Module.moyenne=0.6*Module.note.EMD+0.4*Module.note.CC;
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS2=NotesS2+Module.moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
       Etud.MoyenneS1=NotesS1/nbrS1;
       Etud.MoyenneS2=NotesS2/nbrS2;
       Etud.MoyenneG=(Etud.MoyenneS1+Etud.MoyenneS2)/2;
       i++;
       Indice=fopen("Indice.txt","w");
       if (Indice!=NULL)
       {
           fprintf(Indice,"%d\n",i);
       }
       fclose(Indice);
        }
        fwrite(&Etud,sizeof(Etud),1,Etudiant);
        fclose(Etudiant);
        break;
        case 5:
        printf("\n");
        printf("\n");
        printf("\n");
            printf("                                      Vous Avez Choisis Ajout D'un Etudiant\n\n");
        do
        {
        nbrS1=0;nbrS2=0;NotesS1=0;NotesS2=0;
       Etudiant=fopen("Etudiant.dat","ab");
       if (Etudiant!=NULL)
       {
        Indice=fopen("Indice.txt","r");
       if (Indice!=NULL)
       {
       fscanf(Indice,"%d\n",&i);
       }
       fclose(Indice);

       printf("                             Veuillez Entrer Les informations de l'Etudiant Numero %d  : \n\n",i);
       printf("                          NOM : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.nom);
       vider_stdin();
       printf("                          PRENOM : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.prenom);
       vider_stdin();
       printf("                          SECTION : ");
       scanf("%d",&Etud.section);
       printf("                          GROUPE : ");
       VerifGroup(&Etud.groupe);
       printf("                          MATRICULE : ");
       scanf("%lld",&Etud.matricule);
       printf("                          ADRESSE : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.adresse);
       vider_stdin();
       printf("                          EMAIL : ");
       fflush(stdout);
       scanf(" %[^\n]", Etud.email);
       vider_stdin();
       printf("                          DATE DE NAISSANCE : \n");
       printf("                          ANNEE : ");
       Annee(&Etud.date.annee);
       if (Etud.date.annee%400 == 0 || (Etud.date.annee%4 == 0 && Etud.date.annee%100 != 0))
       {
       printf("                          MOIS : ");
       Mois(&Etud.date.mois);
       if(Etud.date.mois == 4 || Etud.date.mois == 6 || Etud.date.mois == 9 || Etud.date.mois == 11)
       {
       printf("                          JOUR : ");
       Jour2(&Etud.date.jour);
       }
       else if (Etud.date.mois == 2)
       {
       printf("                          JOUR : ");
       Jour4(&Etud.date.jour);
       }
       else
       {
        printf("                          JOUR : ");
       Jour1(&Etud.date.jour);
       }
       }
       else
       {
        printf("                          MOIS : ");
       Mois(&Etud.date.mois);
       if(Etud.date.mois == 4 || Etud.date.mois == 6 || Etud.date.mois == 9 || Etud.date.mois == 11)
       {
       printf("                          JOUR : ");
       Jour2(&Etud.date.jour);
       }
       else if (Etud.date.mois == 2)
       {
       printf("                          JOUR : ");
       Jour3(&Etud.date.jour);
       }
       else
       {
        printf("                          JOUR : ");
       Jour1(&Etud.date.jour);
       }
       }
       printf("\n");
       printf("\n");
       system("cls");
        a=0;
       module=fopen("Module.dat","rb");
       if (module!=NULL)
       {
           while(!feof(module))
           {
               fread(&Module,sizeof(Module),1,module);
               a++;
           }
       }
       fclose(module);
       Etud.nbrmodules=a-1;
       printf("                             Module S1 : \n\n");
       printf("                             Module TP : \n\n");
       module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       j=0;
                NotesS1=0;nbrS1=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 1 && Module.TP == 1)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           printf("                           TP : ");
           Verif(&Module.note.TP);
           Etud.Modules[j].note.TP=Module.note.TP;
           Module.moyenne=0.6*Module.note.EMD+0.4*((Module.note.TP+Module.note.CC)/2);
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS1=NotesS1+Module.moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
           j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
         printf("                             Module Sans TP : \n\n");
         module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 1 && Module.TP == 0)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           Module.moyenne=0.6*Module.note.EMD+0.4*Module.note.CC;
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS1=NotesS1+Module.moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
          j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
          printf("                             Module S2 : \n\n");
          printf("                             Module Avec TP : \n\n");
          module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                NotesS2=0;nbrS2=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 2 && Module.TP == 1)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           printf("                           TP : ");
           Verif(&Module.note.TP);
           Etud.Modules[j].note.TP=Module.note.TP;
           Module.moyenne=0.6*Module.note.EMD+0.4*((Module.note.TP+Module.note.CC)/2);
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS2=NotesS2+Module.moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
         printf("                             Module Sans TP : \n\n");
         module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 2 && Module.TP == 0)
           {
           printf("                             Veuillez Entrer Les Notes Du Module %s \n\n",Module.nom);
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
           Module.moyenne=0.6*Module.note.EMD+0.4*Module.note.CC;
           Etud.Modules[j].moyenne=Module.moyenne;
           NotesS2=NotesS2+Module.moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           else j++;
            }
        }
         fclose(module);
         system("cls");
       Etud.MoyenneS1=NotesS1/nbrS1;
       Etud.MoyenneS2=NotesS2/nbrS2;
       Etud.MoyenneG=(Etud.MoyenneS1+Etud.MoyenneS2)/2;
       i++;
       Indice=fopen("Indice.txt","w");
       if (Indice!=NULL)
       {
           fprintf(Indice,"%d\n",i);
       }
       fclose(Indice);
        }
        fwrite(&Etud,sizeof(Etud),1,Etudiant);
        fclose(Etudiant);
        printf("                             Voulez-vous Ajouter Un Nouveau Etudiant ? (O/N): ");
       trquit(&rep);
       printf("\n");
       }while(rep=='o' || rep=='O');
        system("cls");
        system("cls");
        break;
        case 6:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                      Vous Avez Choisis Modification D'un Etudiant\n\n");
        printf("                                 Veuillez Entrer La Matricule De L'Etudiant Recherch%c: \n\n",130);
        printf("                           MATRICULE  : ");
        scanf("%lld",&c);
        system("cls");
        Etudiant=fopen("Etudiant.dat","rb+");
     if(Etudiant!=NULL)
     {
         while(!trouve && !feof(Etudiant))
         {
             pos=ftell(Etudiant);
             fread(&Etud,sizeof(Etud),1,Etudiant);
             if(Etud.matricule==c) trouve=1;
         }
         printf("\n");
         printf("\n");
         if(trouve==0) printf("                 Etudiant Non Trouv%c.",130);
         else
         {
             printf("\n");
             printf("\n");
             printf("                           L'Etudiant A Modifier Est : %s %s",Etud.nom,Etud.prenom);
             printf("\n");
             printf("\n");
             printf("                                 Modifier La Matricule? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                 printf("                          MATRICULE : ");
                 scanf("%lld",&Etud.matricule);
             }
             printf("\n");
             printf("                                 Modifier Le Nom ? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                  printf("                          NOM : ");
                  fflush(stdout);
                  scanf(" %[^\n]", Etud.nom);
                  vider_stdin();
             }
             printf("\n");
             printf("                                 Modifier Le Prenom ? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                  printf("                          PRENOM : ");
                  fflush(stdout);
                  scanf(" %[^\n]", Etud.prenom);
                  vider_stdin();
             }
             printf("\n");
             printf("                                 Modifier La Section ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                  printf("                          SECTION : ");
                  scanf("%d",&Etud.section);
             }
             printf("\n");
             printf("                                 Modifier Le Groupe ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
               printf("\n");
               printf("                          GROUPE : ");
               VerifGroup(&Etud.groupe);
             }
             printf("\n");
             printf("                                 Modifier L'Adresse ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                  printf("                          ADRESSE : ");
                  fflush(stdout);
                  scanf(" %[^\n]", Etud.adresse);
                  vider_stdin();
             }
             printf("\n");
             printf("                                 Modifier L'Email ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                  printf("                          EMAIL : ");
                  fflush(stdout);
                  scanf(" %[^\n]", Etud.email);
                  vider_stdin();
             }
             printf("\n");
             printf("                                 Modifier La Date De Naissance ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\n");
                  printf("                          DATE DE NAISSANCE : \n");
       printf("                          ANNEE : ");
       Annee(&Etud.date.annee);
       if (Etud.date.annee%400 == 0 || (Etud.date.annee%4 == 0 && Etud.date.annee%100 != 0))
       {
       printf("                          MOIS : ");
       Mois(&Etud.date.mois);
       if(Etud.date.mois == 4 || Etud.date.mois == 6 || Etud.date.mois == 9 || Etud.date.mois == 11)
       {
       printf("                          JOUR : ");
       Jour2(&Etud.date.jour);
       }
       else if (Etud.date.mois == 2)
       {
       printf("                          JOUR : ");
       Jour4(&Etud.date.jour);
       }
       else
       {
        printf("                          JOUR : ");
       Jour1(&Etud.date.jour);
       }
       }
       else
       {
        printf("                          MOIS : ");
       Mois(&Etud.date.mois);
       if(Etud.date.mois == 4 || Etud.date.mois == 6 || Etud.date.mois == 9 || Etud.date.mois == 11)
       {
       printf("                          JOUR : ");
       Jour2(&Etud.date.jour);
       }
       else if (Etud.date.mois == 2)
       {
       printf("                          JOUR : ");
       Jour3(&Etud.date.jour);
       }
       else
       {
        printf("                          JOUR : ");
       Jour1(&Etud.date.jour);
       }
       }
             }
             printf("\n");
             printf("                                 Modifier les Notes ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                system("cls");
                do
                {
                printf("\n");
                printf("                             Semestre : ");
                scanf("%d",&choice);
                printf("\n");
                if(choice==1){
                printf("                             Module TP : \n\n");
                 module=fopen("Module.dat","rb");
                if (module!=NULL)
                {
                j=0;
                NotesS1=0;nbrS1=0;
                while(j<Etud.nbrmodules)
             {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 1 && Module.TP == 1)
           {
                printf("                                 Modifier Les Notes Du Module %s ? (O/N) : ",Module.nom);
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
             printf("                                 Modifier La Note Du EMD ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
             }
             printf("\n");
             printf("                                 Modifier La Note Du CC ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
             }
             printf("\n");
             printf("                                 Modifier La Note Du TP ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           TP : ");
           Verif(&Module.note.TP);
           printf("\n");
           Etud.Modules[j].note.TP=Module.note.TP;
             }
            Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*((Etud.Modules[j].note.TP+Etud.Modules[j].note.CC)/2);
           NotesS1=NotesS1+ Etud.Modules[j].moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
           j++;
           }
           else
           {
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*((Etud.Modules[j].note.TP+Etud.Modules[j].note.CC)/2);
           NotesS1=NotesS1+ Etud.Modules[j].moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
           j++;
           }
           }
           else j++;
           }
           }
         fclose(module);
         system("cls");
         printf("                             Module Sans TP : \n\n");
         module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                while(j<Etud.nbrmodules)
          {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 1 && Module.TP == 0)
           {
           printf("                                 Modifier Les Notes Du Module %s ? (O/N) : ",Module.nom);
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                                 Modifier La Note Du EMD ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
             }
             printf("\n");
             printf("                                 Modifier La Note Du CC ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           CC : ");
           Verif(&Module.note.CC);
           printf("\n");
           Etud.Modules[j].note.CC=Module.note.CC;
             }
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*Etud.Modules[j].note.CC;
           NotesS1=NotesS1+Etud.Modules[j].moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
           j++;
           }
           else
           {
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*Etud.Modules[j].note.CC;
           NotesS1=NotesS1+Etud.Modules[j].moyenne*Module.coeff;
           nbrS1=nbrS1+Module.coeff;
           j++;
            }
           }
           else j++;
           }
           }
         fclose(module);
         Etud.MoyenneS1=NotesS1/nbrS1;
                }
         if(choice==2){
          printf("                             Module S2 : \n\n");
          printf("                             Module Avec TP : \n\n");
          module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                NotesS2=0;nbrS2=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 2 && Module.TP == 1)
           {
           printf("                                 Modifier Les Notes Du Module %s ? (O/N) : ",Module.nom);
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                                 Modifier La Note Du EMD ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
             }
             printf("\n");
             printf("                                 Modifier La Note Du CC ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           CC : ");
           Verif(&Module.note.CC);
           Etud.Modules[j].note.CC=Module.note.CC;
             }
             printf("\n");
             printf("                                 Modifier La Note Du TP ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           TP : ");
           Verif(&Module.note.TP);
           printf("\n");
           Etud.Modules[j].note.TP=Module.note.TP;
             }
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*((Etud.Modules[j].note.TP+Etud.Modules[j].note.CC)/2);
           NotesS2=NotesS2+Etud.Modules[j].moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           else
           {
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*((Etud.Modules[j].note.TP+Etud.Modules[j].note.CC)/2);
           NotesS2=NotesS2+Etud.Modules[j].moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
            }
           }
           else j++;
           }
           }
         fclose(module);
         system("cls");
         printf("                             Module Sans TP : \n\n");
         module=fopen("Module.dat","rb");
         if (module!=NULL)
        {       j=0;
                while(j<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.S == 2 && Module.TP == 0)
           {
             printf("                                 Modifier Les Notes Du Module %s ? (O/N) : ",Module.nom);
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
             printf("                                 Modifier La Note Du EMD ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           EMD : ");
           Verif(&Module.note.EMD);
           Etud.Modules[j].note.EMD=Module.note.EMD;
             }
             printf("\n");
             printf("                                 Modifier La Note Du CC ? (O/N) : ");
             fflush(stdin);
             rep=getchar();
             printf("\n");
             if(rep=='o' || rep=='O')
             {
           printf("                           CC : ");
           Verif(&Module.note.CC);
           printf("\n");
           Etud.Modules[j].note.CC=Module.note.CC;
             }
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*Etud.Modules[j].note.CC;
           NotesS2=NotesS2+Etud.Modules[j].moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           else
           {
           Etud.Modules[j].moyenne=0.6*Etud.Modules[j].note.EMD+0.4*Etud.Modules[j].note.CC;
           NotesS2=NotesS2+Etud.Modules[j].moyenne*Module.coeff;
           nbrS2=nbrS2+Module.coeff;
           j++;
           }
           }
           else j++;
           }
           }
        Etud.MoyenneS2=NotesS2/nbrS2;
         }
         fclose(module);
         printf("\n");
         printf("                             Voulez-vous Refaire L'Operation ? (O/N) : ");
                trquit(&rep);
                printf("\n");
                system("cls");
                }while(rep=='o' || rep=='O');
         system("cls");
       Etud.MoyenneG=(Etud.MoyenneS1+Etud.MoyenneS2)/2;
     }
         }
                fseek(Etudiant,pos,SEEK_SET);
                fwrite(&Etud,sizeof(Etud),1,Etudiant);
                fclose(Etudiant);
     }

        break;
        case 7:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                      Vous Avez Choisis Supression D'un Etudiant\n\n");
        do
        {
        printf("                      Nom De L'Etudiant : ");
        fflush(stdin);
        gets(nomEt);
        printf("\n");
        printf("                      Prenom De L'Etudiant : ");
        fflush(stdin);
        gets(prenomEt);
        printf("\n");
        N=0;
        Etudiant=fopen("Etudiant.dat","rb");
        if(Etudiant!=NULL)
        {
          while(fread(&Etud,sizeof(Etud),1,Etudiant))
         {
             N++;
         }
        }
        fclose(Etudiant);
        Etudiant=fopen("Etudiant.dat","rb");
        Ftemp=fopen("temp.dat","wb+");
    if(Etudiant!=NULL && Ftemp!=NULL)
    {
        while(fread(&Etud,sizeof(Etud),1,Etudiant))  if(strcmp(Etud.nom,nomEt) && strcmp(Etud.prenom,prenomEt))   fwrite(&Etud,sizeof(Etud),1,Ftemp);
        fclose(Etudiant);
        fclose(Ftemp);
        remove("Etudiant.dat");
        rename("temp.dat","Etudiant.dat");
    }
        G=0;
        Etudiant=fopen("Etudiant.dat","rb");
        if(Etudiant!=NULL)
        {
          while(fread(&Etud,sizeof(Etud),1,Etudiant))
         {
             G++;
         }
        }
        fclose(Etudiant);
        if(G<N)
        {
                printf("                      L'Etudiant %s %s Est Supprim%c\n",nomEt,prenomEt,130);
                Indice=fopen("Indice.txt","r+");
                Ftemp=fopen("temp.txt","w+");
                if (Indice!=NULL && Ftemp!=NULL)
                {
                fscanf(Indice,"%d\n",&i);
                i=i-(N-G);
                fprintf(Ftemp,"%d\n",i);
                }
                fclose(Indice);
                fclose(Ftemp);
                remove("Indice.txt");
                rename("temp.txt","Indice.txt");
        }

        else    printf("                      Etudiant Non Trouv%c.\n",130);
    printf("\n");
    printf("\n");
    printf("                               Voulez-vous Supprimer Un Autre Etudiant ? (O/N): ");
       trquit(&rep);
       printf("\n");
        }while(rep=='o' || rep=='O');
        break;
        case 8:
       do
       {
       printf("\n");
        printf("\n");
        printf("\n");
        fptr3 = fopen(filename3, "r");
        if (fptr3 == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c3 = fgetc(fptr3);
       while (c3 != EOF)
       {
        printf ("%c", c3);
        c3 = fgetc(fptr3);
       }
       fclose(fptr3);

       printf("\n");
       printf("\n");
       printf("\n");
       printf("                                                                                Les Choix:\n\n");
    printf("                                                                      1. Afficher Tous Les Etudiants\n\n");
    printf("                                                                          2. Afficher Un Etudiant\n\n");
    printf("                                Mon Choix : ");
    scanf("%d",&choice);
    system("cls");
    if(choice == 1)
    {
       printf("\n");
        printf("\n");
        printf("\n");
        fptr3 = fopen(filename3, "r");
        if (fptr3 == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c3 = fgetc(fptr3);
       while (c3 != EOF)
       {
        printf ("%c", c3);
        c3 = fgetc(fptr3);
       }
       fclose(fptr3);

       printf("\n");
       printf("\n");
       printf("\n");
       Etudiant=fopen("Etudiant.dat","rb");
       if (Etudiant!=NULL)
       {
       while(fread(&Etud,sizeof(Etud),1,Etudiant))
       {
       printf("                          NOM  :   %s \n\n",Etud.nom);
       printf("                          PRENOM  :   %s \n\n",Etud.prenom);
       printf("                          SECTION  :   %d \n\n",Etud.section);
       printf("                          GROUPE  :   %d \n\n",Etud.groupe);
       printf("                          MATRICULE  :   %lld \n\n",Etud.matricule);
       printf("                          ADRESSE  :   %s \n\n",Etud.adresse);
       printf("                          EMAIL  :   %s \n\n",Etud.email);
       if (Etud.date.mois == 1) printf("                          DATE DE NAISSANCE  :   %d Janvier %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 2) printf("                          DATE DE NAISSANCE  :   %d Fevrier %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 3) printf("                          DATE DE NAISSANCE  :   %d Mars %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 4) printf("                          DATE DE NAISSANCE  :   %d Avril %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 5) printf("                          DATE DE NAISSANCE  :   %d Mai %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 6) printf("                          DATE DE NAISSANCE  :   %d Juin %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 7) printf("                          DATE DE NAISSANCE  :   %d Juillet %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 8) printf("                          DATE DE NAISSANCE  :   %d Aout %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 9) printf("                          DATE DE NAISSANCE  :   %d Septembre %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 10) printf("                          DATE DE NAISSANCE  :   %d Octobre %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 11) printf("                          DATE DE NAISSANCE  :   %d Novembre %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 12) printf("                          DATE DE NAISSANCE  :   %d Decembre %d\n\n",Etud.date.jour,Etud.date.annee);
       printf("                             La Moyenne Du S1 Est  :   %.2f\n\n",Etud.MoyenneS1);
       printf("                             La Moyenne Du S2 Est  :   %.2f\n\n",Etud.MoyenneS2);
       printf("                             La Moyenne Generale Est  :   %.2f\n\n",Etud.MoyenneG);
       printf("\n");
       printf("                             Notes Modules  :   \n\n");
       printf("                             Semestre 1  :   \n\n");
         module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 1 && Module.S == 1)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("                           TP : %.2f\n",Etud.Modules[i].note.TP);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
                  module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 0 && Module.S == 1)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
         printf("                             Semestre 2  :   \n\n");
                  module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 1 && Module.S == 2)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("                           TP : %.2f\n",Etud.Modules[i].note.TP);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
                  module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 0 && Module.S == 2)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
       printf("                 -----------------------------------------------------------------------------\n");
       }
       }
       fclose(Etudiant);
    }
    if(choice == 2)
    {
        printf("\n");
        printf("\n");
        printf("\n");
        fptr3 = fopen(filename3, "r");
        if (fptr3 == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c3 = fgetc(fptr3);
       while (c3 != EOF)
       {
        printf ("%c", c3);
        c3 = fgetc(fptr3);
       }
       fclose(fptr3);

       printf("\n");
       printf("\n");
       printf("\n");
       do
       {
       printf("                             Veuillez Entrer La Matricule De L'Etudiant Recherch%c: \n\n",130);
       printf("                        MATRICULE  : ");
       scanf("%lld",&c);
       printf("\n");
       system("cls");
       Etudiant=fopen("Etudiant.dat","rb");
     if(Etudiant!=NULL)
     {
         while(!trouve && !feof(Etudiant))
         {
             fread(&Etud,sizeof(Etud),1,Etudiant);
             if(Etud.matricule==c) trouve=1;
         }
         printf("\n");
         printf("\n");
         if(trouve==0) printf("              Etudiant Non Trouv%c.",130);
         else
         {
       printf("\n");
       printf("\n");
       printf("\n");
       printf("                          NOM  :   %s \n\n",Etud.nom);
       printf("                          PRENOM  :   %s \n\n",Etud.prenom);
       printf("                          SECTION  :   %d \n\n",Etud.section);
       printf("                          GROUPE  :   %d \n\n",Etud.groupe);
       printf("                          MATRICULE  :   %lld \n\n",Etud.matricule);
       printf("                          ADRESSE  :   %s \n\n",Etud.adresse);
       printf("                          EMAIL  :   %s \n\n",Etud.email);
       if (Etud.date.mois == 1) printf("                          DATE DE NAISSANCE  :   %d Janvier %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 2) printf("                          DATE DE NAISSANCE  :   %d Fevrier %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 3) printf("                          DATE DE NAISSANCE  :   %d Mars %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 4) printf("                          DATE DE NAISSANCE  :   %d Avril %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 5) printf("                          DATE DE NAISSANCE  :   %d Mai %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 6) printf("                          DATE DE NAISSANCE  :   %d Juin %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 7) printf("                          DATE DE NAISSANCE  :   %d Juillet %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 8) printf("                          DATE DE NAISSANCE  :   %d Aout %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 9) printf("                          DATE DE NAISSANCE  :   %d Septembre %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 10) printf("                          DATE DE NAISSANCE  :   %d Octobre %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 11) printf("                          DATE DE NAISSANCE  :   %d Novembre %d\n\n",Etud.date.jour,Etud.date.annee);
       if (Etud.date.mois == 12) printf("                          DATE DE NAISSANCE  :   %d Decembre %d\n\n",Etud.date.jour,Etud.date.annee);
       printf("                             La Moyenne Du S1 Est  :   %.2f\n\n",Etud.MoyenneS1);
       printf("                             La Moyenne Du S2 Est  :   %.2f\n\n",Etud.MoyenneS2);
       printf("                             La Moyenne Generale Est  :   %.2f\n\n",Etud.MoyenneG);
       printf("\n");
       printf("                             Notes Modules  :   \n\n");
       printf("                             Semestre 1  :   \n\n");
         module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 1 && Module.S == 1)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("                           TP : %.2f\n",Etud.Modules[i].note.TP);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
                  module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 0 && Module.S == 1)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
         printf("                             Semestre 2  :   \n\n");
                  module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 1 && Module.S == 2)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("                           TP : %.2f\n",Etud.Modules[i].note.TP);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
                  module=fopen("Module.dat","rb");
       if (module!=NULL)
        {       i=0;
                while(i<Etud.nbrmodules)
       {
           fread(&Module,sizeof(Module),1,module);
           if(Module.TP == 0 && Module.S == 2)
           {
           printf("                                Module : %s\n\n",Module.nom);
           printf("                           EMD : %.2f\n",Etud.Modules[i].note.EMD);
           printf("                           CC : %.2f\n",Etud.Modules[i].note.CC);
           printf("\n");
           printf("                           Moyenne : %.2f\n",Etud.Modules[i].moyenne);
           printf("\n");
           i++;
           }
           else i++;
            }
        }
         fclose(module);
         }
         fclose(Etudiant);
     }
     printf("\n");
     printf("\n");
       printf("                             Voulez-vous Afficher Un Autre Etudiant ? (O/N) ");
       trquit(&rep);
       printf("\n");
       system("cls");
        }while(rep=='o' || rep=='O');

    }
    printf("\n");
    printf("\n");
       printf("                             Voulez-vous Refaire L'Operation ? (O/N) ");
       trquit(&rep);
       printf("\n");
       system("cls");
        }while(rep=='o' || rep=='O');

       break;
       case 9:
            printf("\n");
        printf("\n");
        printf("\n");
        fptr1 = fopen(filename1, "r");
        if (fptr1 == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c1 = fgetc(fptr1);
       while (c1 != EOF)
       {
        printf ("%c", c1);
        c1 = fgetc(fptr1);
       }
       fclose(fptr1);
       printf("\n");
       printf("\n");
       printf("\n");
       NombresEtudiantsGroup1=0;NotesGroup1=0;
       NombresEtudiantsGroup2=0;NotesGroup2=0;
       NombresEtudiantsGroup3=0;NotesGroup3=0;
       NombresEtudiantsGroup4=0;NotesGroup4=0;
       Etudiant=fopen("Etudiant.dat","rb");
       if (Etudiant!=NULL)
       {
       while(fread(&Etud,sizeof(Etud),1,Etudiant))
       {
       if (Etud.groupe==1) {NombresEtudiantsGroup1++;NotesGroup1=NotesGroup1+Etud.MoyenneG;};
       if (Etud.groupe==2) {NombresEtudiantsGroup2++;NotesGroup2=NotesGroup2+Etud.MoyenneG;};
       if (Etud.groupe==3) {NombresEtudiantsGroup3++;NotesGroup3=NotesGroup3+Etud.MoyenneG;};
       if (Etud.groupe==4) {NombresEtudiantsGroup4++;NotesGroup4=NotesGroup4+Etud.MoyenneG;};
       }
       }
       fclose(Etudiant);
       if(NombresEtudiantsGroup1==0) printf("                         La Moyenne Du Groupe 1 Est  :   0.00\n\n");
       else printf("                         La Moyenne Du Groupe 1 Est  :   %.2f\n\n",NotesGroup1/NombresEtudiantsGroup1);
       if(NombresEtudiantsGroup2==0) printf("                         La Moyenne Du Groupe 2 Est  :   0.00\n\n");
       else printf("                         La Moyenne Du Groupe 2 Est  :   %.2f\n\n",NotesGroup2/NombresEtudiantsGroup2);;
       if(NombresEtudiantsGroup3==0) printf("                         La Moyenne Du Groupe 3 Est  :   0.00\n\n");
       else printf("                         La Moyenne Du Groupe 3 Est  :   %.2f\n\n",NotesGroup3/NombresEtudiantsGroup3);
       if(NombresEtudiantsGroup4==0) printf("                         La Moyenne Du Groupe 4 Est  :   0.00\n\n");
       else printf("                         La Moyenne Du Groupe 4 Est  :   %.2f\n\n",NotesGroup4/NombresEtudiantsGroup4);
       break;
       case 10:
        printf("\n");
        printf("\n");
        printf("\n");
        fptr2 = fopen(filename2, "r");
        if (fptr2 == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c2 = fgetc(fptr2);
       while (c2 != EOF)
       {
        printf ("%c", c2);
        c2 = fgetc(fptr2);
       }
       fclose(fptr2);
       printf("\n");
       printf("\n");
       printf("\n");
       SommeNotesSection=0;N=0;
       Etudiant=fopen("Etudiant.dat","rb");
       if (Etudiant!=NULL)
       {
       while(fread(&Etud,sizeof(Etud),1,Etudiant))
       {
           SommeNotesSection=SommeNotesSection+Etud.MoyenneG;
           N++;
       }
       }
       fclose(Etudiant);
       if(N == 0 || SommeNotesSection == 0) printf("                    La Moyenne De La Section 7 Est  :   0.00\n\n");
       else printf("                             La Moyenne De La Section 7 Est  :   %.2f\n\n",SommeNotesSection/N);
       break;
       case 11:
            printf("\n");
        printf("\n");
        printf("\n");
        fptr4 = fopen(filename4, "r");
        if (fptr4 == NULL)
       {
        printf("Cannot open file \n");
        exit(0);
       }
       c4 = fgetc(fptr4);
       while (c4 != EOF)
       {
        printf ("%c", c4);
        c4 = fgetc(fptr4);
       }
       fclose(fptr4);
       printf("\n");
       printf("\n");
       printf("\n");
       N=0;
       Etudiant=fopen("Etudiant.dat","rb");
       if (Etudiant!=NULL)
       {
       while(fread(&Etud,sizeof(Etud),1,Etudiant))
       {
         N++;
       }
       }
       fclose(Etudiant);
       if (N == 0) printf("                 Aucun Etudiant Existant");
       else
       {
       i=1;
       Etudiant=fopen("Etudiant.dat","rb");
       if (Etudiant!=NULL)
       {
       while(fread(&Etud,sizeof(Etud),1,Etudiant))
       {
         E[i]=Etud.MoyenneG;
         i++;
       }
       }
       fclose(Etudiant);
       I=i-1;
       max=E[1];
       imax=1;
       for(i=2;i<=I;i++)
       {
           if(E[i]>=max) {
            max=E[i];imax=i;
           }
       }
       i=1;
       Etudiant=fopen("Etudiant.dat","rb");
       if (Etudiant!=NULL)
       {
           do
         {
         fread(&Etud,sizeof(Etud),1,Etudiant);
         if(i == imax)
         {
       printf("                             Le Major De Promo Est : \n\n");
       printf("                         NOM  : %s \n\n",Etud.nom);
       printf("                         PRENOM  : %s \n\n",Etud.prenom);
       printf("                         MOYENNE  : %.2f \n\n",max);
       i++;
         }
         else i++;
        }while(i<=N);
       }
       fclose(Etudiant);
       }
       printf("\n");
       printf("\n");
       printf("\n");
       break;
       case 12:
       return 0;
       system("cls");
       default:
       printf("\n");
       printf("\n");
       printf("                             Vous N'avez Pas Rentr%c Un Nombre Correct.\n\n",130);
       break;
       }
       printf("\n\n");
       printf("                                                                        Revenir Au Menu?\n\n");
       printf("                                                                              1-Oui\n\n");
       printf("                                                                              2-Non\n\n");
       printf("                             Mon Choix : ");
       scanf("%d",&Menu);
       system("cls");
       }
       while(Menu != 2 );
       return 0;
       }







