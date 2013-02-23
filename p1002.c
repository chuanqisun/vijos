#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){

	int L, S, T, M;
    int stone_loc[102];
	int stone_mark[9000];
    int stone_count[9000];
	int m,i,j,step,t,shift,max_distance;
	int min_stone;
	
	//input
	scanf("%d", &L);
	scanf("%d %d %d", &S,&T,&M);


    //init 
    for (i=0; i<9000; i++){
        stone_mark[i]=0;
        stone_count[i]=101;
    }
    for (i=0; i<102; i++){
        stone_loc[i]=0;
    } 
    stone_count[0]=0;
    shift=0;



    //compression length
    max_distance=S * (S-1) + T;

    //read in stone location
	for (m=1; m<=M; m++){
		scanf("%d",&i);
        stone_loc[m]=i;
	}
    //treat ending point as a stone
    stone_loc[M+1]=L;
	
	//sort stones
	for (i=0; i<=M; i++){
		for (j=0; j<=M-i; j++){
			if (stone_loc[j]>stone_loc[j+1]){
				t=stone_loc[j];
				stone_loc[j]=stone_loc[j+1];
				stone_loc[j+1]=t;
			}
		}
	}	
    
    min_stone=0;
    //directly compute min stones
    if (S==T) {
        for (i=1; i<=M; i++) {
           if (stone_loc[i] % S == 0) {
               min_stone++;
           }
        }
        printf("%d", min_stone);
        return 0;
    }
    
    //compress distance to a maximum of max_distance
    for (i=1; i<=M+1; i++){
        shift=stone_loc[i]-stone_loc[i-1]-max_distance;
        if (shift > 0) {
            for (j=i; j<=M+1; j++){
                stone_loc[j]-=shift;
            }
        }
        stone_mark[stone_loc[i]]=1;
    }
    
    //get L according to last stone
    L = stone_loc[M+1];
    stone_mark[L] = 0; 
    

	int cur;
	
    //DP one time iteration through the array

	for (cur=0; cur<L; cur++){
	    for (step=S;step<=T;step++){
            if (stone_count[cur] + stone_mark[cur + step] < stone_count[cur + step]) {
                stone_count[cur + step] = stone_count[cur] + stone_mark[cur + step];
            }
        }
    }
    
    min_stone=101;
    for (i=L; i<L+T; i++) {
		if (stone_count[i] < min_stone){
            min_stone = stone_count[i];
        }
    }

    printf("%d", min_stone);

    return 0;
}

