#include<stdio.h>
#include <stdlib.h>
void init(int mat[6][7])
{
    int i,j;
    for (i=0;i<6;i++)
    {
        for(j=0;j<7;j++){
            mat[i][j]=0;
        }
    }
}
//REMPLISSAGE
int pleine(int mat[6][7],int x){
 int t;
 if( mat[0][x]!=0){
   return 0;
 }else{return 1;}
}
void remplissage(int mat[6][7],int x,int k,int*lig){
int test;
  test=pleine(&mat[0][0],x);
 // printf("%d",test);
  if(test==1){

    int i=5;
    int m=0;
    do{
        if(mat[i][x]==0 ){
            mat[i][x]=k;
            *lig=i;
            m=1;
        }else{
        i--;}
    }while(m!=1);
  }
  else{
    do{
        printf("donner une autre colonne : ");
        scanf("%d",&x);
       test=pleine(&mat[0][0],x) ;
    }while(test==0);
     int i=5;
    int m=0;
     do{
        if(mat[i][x]==0 ){
            mat[i][x]=k;
            *lig=i;
            m=1;
        }else{
        i--;}
    }while(m!=1);
    mat[*lig][x]=k;
  }

}





void jsuiv(int*k)
{
  if(*k==1){
    *k=2;
    } else{
       *k=1;}
}



void affichage(int mat[6][7]){
int i,j;

for(i=0;i<6;i++){
    printf("+-----+-----+-----+-----+-----+-----+-----+ \n");
    printf("|  ");
    for(j=0;j<7;j++){
            if(mat[i][j]==0){printf("  |   "," ");} else{
        printf("%d |   ",mat[i][j]);
    }
    }
    printf("\n");
}
 printf("+-----+-----+-----+-----+-----+-----+-----+ \n");
  printf(" 0      1     2     3     4     5    6  \n");

}



int vict(int mat[6][7],int x,int lig,int k){
/**1ere test verticale**/
int h=0;
int i;
if(lig<5){
    for(i=lig;i<lig+4;i++){
        if(mat[i][x]==k){
            h++;
        }
    }
}

int th=0;
if(h==4){
    th=1;
}
/** 2eme test horizontale**/
int v=0;
int tv=0;
int j=0;



do{
        for(i=j;i<j+4;i++){
            if(mat[lig][i]==k){
                v++;
            }
        }

j++;
if(v<4){
    v=0;
}

} while ((j<5 )&& (v<4));


if(v==4){

    tv=1;
}


/** 3eme test diagonale**/
int test=0;
int b=x;
j=x;
int d1=0;
int d2=0;
i=lig;
int i1=lig;

do{
    b++;
    i--;
    if(mat[i][b]==k){
        d1++;

    }
}while(mat[i][b]==k);
do{
    j--;
    i1++;
    if(mat[i1][j]==k){
        d2++;

    }
}while(mat[i1][j]==k);
d1=d1+d2+1;
if(d1==4){
    test=1;
}
if(test==0){
b=x;
j=x;

i=lig;
i1=lig;
        d1=0;
d2=0;
    do{
    b--;
    i--;
    if(mat[i][b]==k){
        d1++;
    }
}while(mat[i][b]==k);
do{
    j++;
    i1++;
    if(mat[i1][j]==k){
        d2++;
    }
}while(mat[i1][j]==k);

}
d1=d1+d2+1;
if(d1==4){
    test=1;
}



if((th==1)||(tv==1)||(test==1)){return 1;
}else{return 0;}



}











void main(){

int mat[6][7];
int i,j,lig;
init(&mat[0][0]);
int k=1;
int x;
lig=0;
int tour=0;
int victoire=0;
affichage(&mat[0][0]);
do{
        tour++;

printf("le  joueur num %d va commencer : ",k);
scanf("%d",&x);
remplissage(&mat[0][0],x,k,&lig);
affichage(&mat[0][0]);
 victoire = vict(&mat[0][0],x,lig,k);

lig=0;
jsuiv(&k);

}while((victoire==0) && (tour<41));
if(victoire==1){
    jsuiv(&k);
    printf("\n \n le joueur numero %d a gagne ! \n \n",k);
}else{
printf("egalité");}

}

