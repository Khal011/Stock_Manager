#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>


char str[40];
int day;
int month;
int year;


struct item
{
	char productname[40],productcomp[40],c;
	int productid;
	int price;
	int Qnt;
}st;

void bienvenue();
void title();
void login();
void menu();
void title();
void deleteproduct();
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void ajout_produit();
void affichage_des_produits();
void recherche_produit();
void modifier_produit();
void supprimer_tous();

void main()

{
bienvenue(); //call for welcome screen function
login(); //call for login function
}



void bienvenue()

{
	HANDLE wHnd;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("Projet C");
    COORD bufferSize = {120, 120};
    SetConsoleScreenBufferSize(wHnd, bufferSize);

	time_t t;
	time(&t);
	printf("                                                                                                         \n");
for (int i=0;i<120;i++){
	printf("-");
}
	printf("\t\t\t\t%s",ctime(&t));


	printf("\t\t\t   ====================================\t\t\t\t\t\n");
	printf("\t\t\t\t       BIENVENUE DANS \t \t\t\t\t\t\t\n");
	printf("\t\t\t        SYSTEME DE GESTION DES STOCKS \t \t\t\t\t\t\t\n");
	printf("\t\t\t   ====================================\t\t\t\t\t\t\n");
for (int i=0;i<120;i++){
	printf("-");
}
	printf("\n\tProjet realiser par:");
	printf("\n\t\t#Felfel Raed");
	printf("\n\t\t#Saad Mohamed Khalil");
	printf("\n\t\t#Bougares Majd\n");
for (int i=0;i<120;i++){
	printf("-");
}
	printf("\n\n\n\t Appuyez sur n%simporte quelle touche pour continuer.........","'");



getch();
system("cls");
}

void login()
{

int a=0,i=0;
    char uname[15],c=' ';
    char pword[15],code[15];
    char user[15]="admin";
    char pass[15]="admin";
    do
{

    printf("\n  ========================  SE CONNECTER   ========================  ");
    printf(" \n                        UTILISATEUR:-");
	gets(uname);
	printf(" \n                        MOT DE PASSE:-");
	while(i<15)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else if (c!=8) 
		{
		printf("*");
	    i++;
		}
		else if (i>0){
			
			i--;
           putch('\b');
           putch(' ');
           putch('\b');
		}
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"admin")==0 && strcmp(pword,"admin")==0)
	{
	printf("  \n\n\n\t BIENVENUE DANS LE SYSTEME DE GESTION DES STOCKS !!!! LA CONNEXION EST REUSSITE");
	printf("\n\n\n\tAppuyez sur n%simporte quelle touche pour continuer.........\n","'");
	getch();
	break;
	}
	else
	{
		printf("\n        DESOLE !!! LA CONNEXION A  ECHOUE ");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nDesole vous avez entre de fausses coorodonnees 4 fois !!!");

		getch();

		}
		system("cls");
		menu();
}



void menu(void)
{

	int choice;
	system("cls");

	main:
	
	printf("\n======================== LE SYSTEME DE GESTION DES STOCKS ========================");
	printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n\t\tPress <1> Ajouter un produit");
	printf("\n\t\tPress <2> Supprimer un produit");
	printf("\n\t\tPress <3> Recherche dun produit");
	printf("\n\t\tPress <4> Affichage de tous les produits");
	printf("\n\t\tPress <5> Modifier un produit");
	printf("\n\t\tPress <6> Supprimer tous les produits");
	printf("\n\t\tPress <7> Quitter!");

	printf("\n\n\t\tEntrer votre choix[1-7]");
	gets(str);
	choice=atoi(str);

	system("cls");

	switch(choice)
	{
		case 1:
			ajout_produit();
			break;
		case 2:
			deleteproduct();
			break;
		case 3:
		recherche_produit();
			break;
		case 4:
		affichage_des_produits();
			break;
		case 5:
			modifier_produit();
			break;
		case 6:
			supprimer_tous();
			break;
		case 7:
			printf("Sortie du systeme");
			exit(0);
			break;	


		default:
		printf("Choix invalide! Sortie du systeme\n");
			getch();
	}

}


void ajout_produit()
{
	int index, valid;
	char c;
	int a=0;

	FILE *fp;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	do
	{
		system("cls");
		printf("============ ENTRER LE STOCK ID ============");
		int ID;
		
		
		fp = fopen("BDD.txt","a+");
		if(fp!=NULL)
		{
			I:
			printf("\nStock Code :");
			gets(str);
			valid=1;
			for (index=0; index<strlen(str); ++index)
			{
				
				if(!isdigit(str[index]))
				{	
					valid = 0;
					break;
				}

				
			}
			if (!valid) {
				printf("\nCode Invalide\n");
				goto I;
				break;	
				}

			ID=atoi(str);
			// "%d/%02d/%02d", tm.tm_mday, tm.tm_mon + 1,  tm.tm_year + 1900
			while(fscanf(fp,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt,&day, &month,  &year)!=EOF)
			{

				if(ID == st.productid)
				{
					printf("\n\tLe Stock code est deja existant.\n");
					rewind(fp);
					goto I;
				}
			}
			st.productid = ID;
		}
		else
		{
			
			
			printf("\nCode du Produit\t :");			
			gets(str);
			st.productid=atoi(str);
		}
		fclose(fp);

		do
		{

			
			
			printf("\nNom du Produit\t :");
			gets(st.productname);
			st.productname[0]=toupper(st.productname[0]);

			for (index=0; index<strlen(st.productname); ++index)
			{
				if(isalpha(st.productname[index]))
					valid = 1;
				else

				{	
					if ((st.productname)[index] ==' ') st.productname[index] ='_'; 
					if ((st.productname)[index] !='_'){
					valid = 0;
					break;}
					
				}
			}
			if (!valid)
			{
				printf("\n Le nom contient des caracteres Incompatibles. Reessayer une autre fois!");
				


			}
		}while(!valid);



			do
		{
			char productcomp[40];
			
			printf("\nLa Societe productrice\t :");
			gets(st.productcomp);
			st.productcomp[0]=toupper(st.productcomp[0]);

			for (index=0; index<strlen(st.productcomp); ++index)
			{
				if(isalpha(st.productcomp[index]))
					valid = 1;
				else
				{	if ((st.productcomp)[index] !='_'){
					valid = 0;
					break;}
					
				}
			}
			if (!valid)
			{
				printf("\n Le nom contient des caracteres Incompatibles. Reessayer une autre fois!");

			}
		}while(!valid);


		do
			{
				
				printf("\nPrix [10-5000]$:");
				gets(str);
				st.price=atoi(str);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tVous avez depasser les limites du prix $.Reessayer.");
				}
			}while(st.price<10 || st.price>5000);

				do
			{
				fflush(stdin);
				printf("\nQuantite [1-500]\t:");
				gets(str);
				st.Qnt=atoi(str);
				if(st.Qnt<1 || st.Qnt>500)
				{
					printf("\n\tEntrer une Quantite dans[1-500] .Reessayer.");
				}
			}while(st.Qnt<1 || st.Qnt>500);
		fp=fopen("BDD.txt","a");
		day=tm.tm_mday;
		month =tm.tm_mon + 1;
		year= tm.tm_year + 1900;

		fprintf(fp,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp,st.price, st.productid,st.Qnt,day, month,  year);
		fclose(fp);
		printf("\nAppuyez 'Enter' pour ajouter des stocks et n'importe quel autre bouton pour retourner au menu principal");

	}
	while((c = getch()) =='\r');
	menu();
}


void recherche_produit()
{
	char target[40];
	int found=0;
	FILE *sfile;
	sfile=fopen("BDD.txt","r");
	printf("\nEntrer un nom pour rechercher:");
	gets(target);
	target[0]=toupper(target[0]);
	while (!feof(sfile) && found==0)
	{
		fscanf(sfile,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt,&day, &month,  &year);
		if(strcmp(target, st.productname)==0)
		{
			found=1;
		}
	}

	if(found)
	{
		printf("\n Element trouve");
		printf("\nNom du stock\t\t:%s  \nsociete productrice\t\t:%s \nprix du stock\t\t:%i \nStock ID\t\t:%i \nLa quantite du Stock\t:%i", st.productname, st.productcomp, st.price, st.productid, st.Qnt);

	}
	else
		printf("Aucun element trouve");
		fclose(sfile);
		printf("\nAppuyer sur n'importe quel autre bouton pour retourner au menu principal");
		while((st.c = getch()) =='\r');
		menu();

}

void deleteproduct(void)
{
	char target[40];
	int found=0;
	FILE *sfile, *tfile;
	sfile=fopen("BDD.txt","r");
	tfile=fopen("Temp.txt","a+");
	printf("\n Entrer le nom a supprimer ");
	fflush(stdin);
	gets(target);
	target[0]=toupper(target[0]);
	while (fscanf(sfile,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt,&day, &month,  &year)!=EOF)
	{
		if(strcmp(target,st.productname)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tfile,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp,st.price, st.productid,st.Qnt,day, month,  year);
		}
	}
			if(!found)
			{
				printf("\n Aucun element trouve");
				getch();
				menu();
			}
			else
			{
				printf("\n Element supprime");
			}
			fclose(sfile);
			fclose(tfile);
			remove("BDD.txt");
			rename("Temp.txt","BDD.txt");

			printf("\nAppuyer sur n'importe quel autre bouton pour retourner au menu principal!");
		while((st.c = getch()) =='\r');
		menu();
}

void affichage_des_produits()
{


	FILE *f;
	int i, q;
	f=fopen("BDD.txt","r");
	if(f==NULL)
	{

		gotoxy(10,3);
		printf("PAS D'ELEMENTS ENREGISTRE");
		printf("\n\t\tAppuyer sur n'importe quel touche pour retourner au menu principal.");
		getch();
		menu();


	}
	else
	{

		gotoxy(0,5);
			for(i=0;i<120;i++)
		{
			printf("-");
		}
		gotoxy(5,6);
		printf("Nom");
		gotoxy(25,6);
		printf("PRIX");
		gotoxy(40,6);
		printf("Societe productrice");
		gotoxy(70,6);
		printf("Code");
		gotoxy(85,6);
		printf("Quantite\n");
		gotoxy(105,6);
		printf("Date\n");

		for(i=0;i<120;i++)
		{
			printf("-");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt,&day, &month,  &year)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.productname);
			gotoxy(25,q);
			printf("%i",st.price);
			gotoxy(40,q);
			printf("%s",st.productcomp);
			gotoxy(70,q);
			printf("%i",st.productid);
			gotoxy(85,q);
			printf("%i",st.Qnt);
			gotoxy(105,q);
			printf("%d/%02d/%02d",day, month,  year);
			q++;

			// "%d/%02d/%02d"
		}
		printf("\n");
		for(i=0;i<120;i++)
			printf("-");
	}
	fclose(f);

	printf("\nAppuyer sur n'importe quel touche pour retourner au menu principal!");

		getch();
		menu();
}


void supprimer_tous()
{
	char target[4];

	printf("\nVoulez vous supprimer tous les produits ? oui/non : ");
	fflush(stdin);
	gets(target);
	if (toupper(target[0])=='O') {
		remove("BDD.txt");
		printf("Tous les produits sont supprimer.\n");
		}
	printf("\n\n\t\t\tAppuyez sur n%simporte quelle touche pour retourner au Menu.........\n","'");
	while((st.c = getch()) =='\r');
	menu();
	

}



void modifier_produit()
{
	int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a=0;
	int id;
	char edit;
	long int size=sizeof(st);
	fp=fopen("BDD.txt","r+");
	if(fp==NULL)
	{
		printf("Pas d'element ajoute.");
		menu();
	}
	else
	{
		rp = fopen("Temp.txt","a");
		system("cls");
		printf("Entrer le code du produit à changer:");
		gets(str);
		id=atoi(str);
		while(fscanf(fp,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt,&day, &month,  &year)!=EOF)
		{
			if(id==st.productid)
			{

				a=1;
				printf("\n\t*****  ELEMENT TROUVE *****");
				printf("\nNom du Stock\t\t: %s",st.productname);
				printf("\nSociete Productrice\t\t: %s",st.productcomp);
				printf("\nPrix\t\t\t: %i",st.price);
				printf("\nCode du Stock\t\t: %i",st.productid);
				printf("\nQuantite du Stock\t:%i",st.Qnt);

				printf("\n\n\t*** NOUVEL ELEMENT ***");
			do
				{

					fflush(stdin);
					printf("\nNouveau Nom du Stock\t\t: ");
					gets(st.productname); // get input string
					st.productname[0]=toupper(st.productname[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.productname); ++index)
					{	//check if character is valid or not
						if(isalpha(st.productname[index]))
							valid = 1;
						else
						{	if ((st.productname)[index]!='_'){
							valid = 0;
							break;}
						}
					}
					if (!valid)
					{
						printf("\n  Le nom contient des caracteres Incompatibles. REessayer une autre fois!");
						getch();


					}
				}while(!valid);



				do
				{
					char productcomp[40];
					fflush(stdin);
					printf("\nNouvelle Societe\t\t:");
					gets(st.productcomp);
					st.productcomp[0]=toupper(st.productcomp[0]);

					for (index=0; index<strlen(st.productcomp); ++index)
					{
						if(isalpha(st.productcomp[index]))
							valid = 1;
						else
						{	if (st.productcomp[index]!='_'){
							valid = 0;
							break;}
						}
					}
					if (!valid)
					{
						printf("\n  Le nom contient des caracteres Incompatibles. Reessayer une autre fois!");
						getch();


					}
				}while(!valid);

					do
					{
						printf("\nNouveau prix [10-5000]$:");
						gets(str);
						st.price=atoi(str);
						if(st.price<10 || st.price>5000)
						{
							printf("\n\tVous avez depassee les limites du prix . Reessayer.");
						}
					}while(st.price<10 || st.price>5000);


				do
				{
					printf("\nNouvelle Quantite [1-500]\t:");
					gets(str);
					st.Qnt=atoi(str);
					if(st.Qnt<1 || st.Qnt>500)
					{
						printf("\n\tEntrer la nouvelle quantite dans [1-500] .Reessayez.");
					}
				}while(st.Qnt<1 || st.Qnt>500);


				printf("Appuyez sur 'y' pour valider les changements ou sur n%simporte quelle touche pour retourner au Menu Principal\n","'");
				edit=getch();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp,st.price, st.productid,st.Qnt,day, month,  year);
					fflush(stdin);
					printf("\n\n\t\t VOS CHANGEMENETS ONT ETE EFFECTUE");
				}
			}
			else
			{
				fprintf(rp,"%s %s %i %i %i %i/%i/%i\n", st.productname, st.productcomp,st.price, st.productid,st.Qnt,day, month,  year);
				fflush(stdin);
			}

		}
		if(!a)
		{
			printf("\n\nElement n'existe pas");
		}
		fclose(rp);
		fclose(fp);
		remove("BDD.txt");
		rename("Temp.txt","BDD.txt");
		getch();
	}
	menu();
}






