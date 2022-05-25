#include "main.h"

void inizializza_targhe(char targa_1[][D], char *free){
    for (int i=0; i<N; i++){
        memcpy(&targa_1[i][9], free, sizeof targa_1[N][D]);
        printf("%s  \n", &targa_1[i][D]);
    }
}

void creaparcheggio_vuoto(char *vuoto){
    for (int i=0; i<=X; i++){
        for (int j=0; j<=Y; j++){
            printf("|%s| ", vuoto);
        }
        printf(" \n");
    }
}

void inseriscitarga(char new[][D], int pos[25], int *i){
    printf("Inserire il numero di targa: ");
    *i=0;
    if (pos[*i]==0){
        scanf("%s", &new[*i][D]);
        i++;
    }
}

void inizializzaposizione(int pos[25]){
    for (int i=0; i<25; i++){
        pos[i]=0;
    }
}

void stampaparcheggio(char new[][D], char *empty, int *i){
    if (*i<=4){
        for (int p=0; p<X; p++){
            for (int l=0; l<=0; l++){
                if (p==*i){
                    printf("|%s| ", new[p]);
                }
                printf("|%s| ", empty);
            }
        }
        printf(" \n");
        for (int h=1; h<=X; h++){
            for (int y=0; y<=Y; y++){
                printf("|%s| ", empty);
            }
            printf(" \n");
        }
    }
}

void inseriscitarga_nelparcheggio(char targa[][D], char *vuoto, int pos[25], int *i){
    inseriscitarga(targa, pos, i);
    for (int j=0; j<=24; j++){
        if (pos[j]==0){
            stampaparcheggio(targa, vuoto, &j);
            pos[j]=1;
        }
        break;
    }
}

void inseriscitarganuova_nelparcheggio(char targa[][D], char *vuoto, int pos[25], int *i){
    inseriscitarga(targa, pos, i);
    int h=*i+1;
    stampaparcheggio(targa, vuoto, &h);
}

void liberoposto(int pos[25], char *vuoto){
    int t=0;
    printf("Quale posto liberiamo?");
    scanf("%d", &t);
    pos[t]=0;
    
    // da finire
}

void working(int pos[25], char targa[][D], char *free){
    for (int i=0; i<=24; i++){
        if (pos[i+1]==0){
            printf("Il parcheggio non è ancora pieno; inserire nuova targa?   (Digitare 1 per Si o 0 per No) ");
            int x=0;
            scanf("%d", &x);
            if (x==0){
                printf("Chiudo Programma..... \n");
                return;
            }else{
                inseriscitarganuova_nelparcheggio(targa, free, pos, &i);
            }
        }else{
            printf("Il parcheggio è pieno! \n");
            printf("Liberare un posto auto o inizializzare parcheggio?   (Digitare 1 o 0 rispettivamente) ");
            int y=0;
            scanf("%d", &y);
            if (y==0){
                creaparcheggio_vuoto(free);
                inizializzaposizione(pos);
                inseriscitarga_nelparcheggio(targa, free, pos, &i);
            }else{
                creaparcheggio_vuoto(free);
                
            }
        }
    }
}

int main(){
    
    int pos[25];
    char free[]={'0','0','0','0','0','0','0','\0'};
    char targa_1[N][D]={""};
    int i=0;
    
    creaparcheggio_vuoto(free);
    inizializza_targhe(targa_1, free);
    inizializzaposizione(pos);
    inseriscitarga_nelparcheggio(targa_1, free, pos, &i);
    working(pos, targa_1, free);

    return 0;
}
