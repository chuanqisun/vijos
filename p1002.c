#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){

	int L, S, T, M;
	int stone[101];
	int m,i,j, step;
	
	//input
	scanf("%d", &L);
	scanf("%d %d %d", &S,&T,&M);
	for (m=0; m<M; m++){
		scanf("%d",&i);
		stone[m]=i;
	}

	
	int cur;

	int window[11];
	int window_stone[11];
	
	for (i=0; i<=T; i++){
		window_stone[i]=0;
		for (j=0; j<M; j++){
			if (stone[j]==i){
				window_stone[i]=1;
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

