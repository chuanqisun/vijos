#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

	int L, S, T, M;
	int stone[101];
	int m,i,j, step,t;
	int min_stone;
	
	//input
	scanf("%d", &L);
	scanf("%d %d %d", &S,&T,&M);
	for (m=0; m<M; m++){
		scanf("%d",&i);
		stone[m]=i;
	}

	
	//sort stones for better performance
	for (i=0; i<M-1; i++){
		for (j=i; j<M-1; j++){
			if (stone[j]>stone[j+1]){
				t=stone[j];
				stone[j]=stone[j+1];
				stone[j+1]=t;
			}
		}
	}	


	int cur;

	int window[11];
	int window_stone[11];

	min_stone=0;
	
	for (i=0; i<=T; i++){
		window_stone[i]=0;
		for (j=0; j<M; j++){
			if (stone[j]==i){
				window_stone[i]=1;
				min_stone=j;
			}
		}
		window[i]=101;
	}
	
	window[0]=0;	


	for (cur=0; cur<L; cur++){
		if (window[0]<=100){
			for (step=S;step<=T;step++){
				if (window[0]+ (window_stone[step]) < window[step]) {
					window[step]=window[0]+window_stone[step];
				}
			}
		}
		for (i=0; i<T; i++){
			window[i]=window[i+1];
			window_stone[i]=window_stone[i+1];
		}


		window_stone[T]=0;
		for (j=0; j<M; j++){
			if (stone[j]==cur+T+1){
				window_stone[T]=1;
				min_stone=j+1;
				break;
			}else if(stone[j]>cur+T+1){
				min_stone=j;
				break;
			}
		}
		window[T]=101;
	}
		
	int min_step=101;
	for (i=0; i<T; i++){
		if (window[i]<min_step) {
			min_step=window[i];
		}
	}
	printf("%d", min_step);
	return 0;
}

