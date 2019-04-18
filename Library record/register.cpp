#include <iostream>
#include <cstring>


using namespace std;

struct Biblio
{
    char nazwisko[30];
    char imie[30];
    char tytul[30];
    int rok;

    struct Biblio *nast;
    struct Biblio *poprz;

};

struct List
{
    struct Biblio *pocz;
    struct Biblio *kon;
};

void dodaj(struct List *lista, const char *nazwisko, const char *imie, const char *tytul, int rok)
{
    Biblio *curr=new Biblio;


    for(int i=0; i<30; i++)
    {
        curr->nazwisko[i]=0;
        curr->imie[i]=0;
        curr->tytul[i]=0;
    }

    curr->rok=rok;
    strcpy(curr->nazwisko,nazwisko);
    strcpy(curr->imie,imie);
    strcpy(curr->tytul,tytul);

    curr->nast=NULL;
    curr->poprz=NULL;

    if(lista->pocz==NULL)
    {
        lista->pocz=curr;
        lista->kon=curr;
    }
    else
    {
        curr->poprz=lista->kon;
        lista->kon->nast=curr;
        lista->kon=curr;
    }
}

void wypisz(struct List *lista)
{
    Biblio*tmp=lista->pocz;

    if(lista->pocz==NULL) cout<<"Brak elementow "<<endl<<endl;

    while(tmp != NULL)
    {
        cout<<tmp->nazwisko<<" "<<tmp->imie<<" "<<tmp->tytul<<" "<<tmp->rok<<endl;
        tmp=tmp->nast;
    }

}

void sortuj( List *lista){
     Biblio *tmp = NULL;
     Biblio *tmp1 = NULL;
    char nazwisko[30];
    char imie[30];
    char tytul[30];
    int rok;

    for(tmp = lista->pocz; tmp != NULL; tmp = tmp->nast){
        for(tmp1 = lista->pocz; tmp1 != NULL; tmp1 = tmp1->nast){
            if(strcmp(tmp->tytul,tmp1->tytul)<0){


                strcpy(nazwisko,tmp->nazwisko);
                strcpy(imie,tmp->imie);
                strcpy(tytul,tmp->tytul);
                rok=tmp->rok;

                strcpy(tmp->nazwisko,tmp1->nazwisko);
                strcpy(tmp->imie,tmp1->imie);
                strcpy(tmp->tytul,tmp1->tytul);
                tmp->rok=tmp1->rok;

                strcpy(tmp1->nazwisko,nazwisko);
                strcpy(tmp1->imie,imie);
                strcpy(tmp1->tytul,tytul);
                tmp1->rok=rok;
            }
        }
    }
}

void usun(struct List *lista, char *tytul)
{
    Biblio *tmp=lista->pocz;
    Biblio *prev=lista->pocz;

    while(tmp!=NULL)
    {

        if(strcmp(tmp->tytul,tytul)==0)
        {
            break;
        }

        prev=tmp;
        tmp=tmp->nast;
    }
    if(strcmp(tmp->tytul,tytul)==0)
    {

        if(tmp->nast==NULL)
        {
            prev->nast=NULL;
            lista->kon=prev;
        }
        else if(tmp==lista->pocz)
        {
            lista->pocz=tmp->nast;
        }
        else
        {
            prev->nast=tmp->nast;
            tmp->nast->poprz=prev;
        }
    }

}


void szukaj(List *lista, char*tytul)
{
    Biblio *tmp=lista->pocz;

    while(tmp != NULL)
    {
        if(strcmp(tmp->tytul,tytul) == 0)
        {
            cout<<"Znaleziono: "<<tmp->nazwisko<<" "<<tmp->imie<<" "<<tmp->tytul<<" "<<tmp->rok<<endl;
        }
    tmp=tmp->nast;
    }
}


int main()
{
    int wyb;
    List list;
    list.kon=NULL;
    list.pocz=NULL;

//    dodaj(&list,"Drzew","Ksawie","Strzelec",947);
//    dodaj(&list,"sdasd","Kamil","Akcja",1788);
//    dodaj(&list,"aaaa","Glen","Zemsta",2018);
//    dodaj(&list,"uuuu","Walt","Czas honoru",1410);
//    dodaj(&list,"rrrrqw","Ted","Ogien",1000);
//    wypisz(&list);
//    sortuj(&list);
//    cout<<endl;
//    wypisz(&list);
//
//
//
//
//    usun(&list,"Zemsta");
//    cout<<endl;
//    wypisz(&list);
//    usun(&list,"Ogien");
//    cout<<endl;
//    wypisz(&list);
//    usun(&list,"Akcja");
//    cout<<endl;
//    wypisz(&list);
//    cout<<endl;
//    szukaj(&list,"Strzelec");

    char nazwisko[30];
    char imie[30];
    char tytul[30];
    int rok;



    while(true)
    {
        cout << "1. Dodanie do listy" << endl;
        cout << "2. Usuwanie z listy" << endl;
        cout << "3. Wypisanie wszystkich"<<endl;
        cout << "4. Posortowanie po tytule"<<endl;
        cout << "5. Wyszukanie po tytule"<<endl<<endl;
        cin>>wyb;
        switch(wyb)
          {
            case 1:

            cout<<"Podaj nazwisko: ";
            cin>>nazwisko;
            cout<<"Podaj imie: ";
            cin>>imie;
            cout<<"Podaj tytul: ";
            cin>>tytul;
            cout<<"Podaj rocznik: ";
            cin>>rok;
            dodaj(&list, nazwisko, imie, tytul, rok);
            cout<<endl;
            break;

            case 2:

            cout<<"Podaj tytul: ";
            cin>>tytul;
            usun(&list, tytul);
            cout<<endl;
            break;

            case 3:

            wypisz(&list);
            cout<<endl;
            break;

            case 4:
                sortuj(&list);
                cout<<"Posortowane: ";
                wypisz(&list);
                cout<<endl;
                break;

            case 5:
                cout<<"Podaj tytul: ";
                cin>>tytul;
                szukaj(&list, tytul);
                cout<<endl;
                break;




          }
    }




    return 0;







}
