#include<stdio.h>
#define BOYUT 8
#include<time.h>
#include<stdlib.h>

int labirent[BOYUT][BOYUT];  // Random matris icin
/*int labirent[BOYUT][BOYUT]={ {1,1,1,1,1,1,1,1},
					         {1,0,0,0,0,0,1,0},
					         {1,0,1,0,1,1,1,1},
				      	     {1,0,1,0,1,0,0,0},
					         {1,0,1,0,1,1,1,1},
				 	         {1,0,1,0,1,0,0,1},
							 {1,0,1,0,1,0,0,0},
							 {0,1,1,1,1,1,1,1}};
*/	// Manuel martis icin 	       

int yol[BOYUT][BOYUT] = {0};

void yazdir(){
	
	int i,j;
	for(i=0; i<BOYUT; i++){
		for(j=0; j<BOYUT; j++){
			printf("%d\t",yol[i][j]);
		}
		printf("\n\n");
	}
}

int kisayol(int x, int y){
	
	if(x==BOYUT-1 && y==BOYUT-1){
		yol[x][y] = 1;
		return 1;
	}
	
	if(x>=0 && y>=0 && x<BOYUT && y<BOYUT && yol[x][y]==0 && labirent[x][y]==1){
		
		yol[x][y] = 1;
		
		if(kisayol(x+1,y)){
			return 1;
		}
		
		if(kisayol(x,y+1)){
			return 1;
		}
		
		if(kisayol(x-1,y)){
			return 1;
		}
		
		if(kisayol(x,y-1)){
			return 1;
		}
		
		yol[x][y] = 0;
	}
	return 0;
}

void random(){
	int a,b;
	srand(time(NULL));
			
			
	for(a=0; a<BOYUT; a++){
		for(b=0; b<BOYUT; b++){
			labirent[a][b]=rand()%2+0;
			
	}
	
}
	labirent[0][0] = 1;
	labirent[BOYUT-1][BOYUT-1] = 1;
	int i=0,j=0;
	while(i<BOYUT){
		while(j<BOYUT){
			printf("%d\t",labirent[i][j]);
        	j++;
		}
	j=0;
	printf("\n\n");
	i++;
	}
	    printf("***************************************\n");
	if (kisayol(0,0)){
	
    	printf("\t     Kisayol Bulundu\n");
    	printf("***************************************\n");
        yazdir();
    }
    else{
	    printf("\t\    Yol Bulunamadi\n");
        printf("***************************************\n");
    }
}

void manuel(){
	int i=0,j=0;
	while(i<BOYUT){
		while(j<BOYUT){
			printf("%d\t",labirent[i][j]);
        	j++;
		}
	j=0;
	printf("\n\n");
	i++;
	}
	    printf("**********************************************************\n");
	if (kisayol(0,0)){
	
    	printf("\t\t      Kisayol Bulundu\n");
    	printf("**********************************************************\n");
        yazdir();
    }
    else{
	    printf("\t\t      Yol Bulunamadi\n");
        printf("***************************************************************\n");
    }
}
int main(){
	
	random();
	//manuel();
	
    return 0;
}

