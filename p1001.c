#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	int n, max_amount, total_amount, person_amount;
	char max_name[21];
	char tmp_name[21];
	scanf("%d", &n);
	int t_avg, c_avg, p_count;
	char leader, west;

	max_amount=0;
	total_amount=0;

	int i;
	for (i=0; i<n; i++){
		person_amount=0;

		scanf("%s %d %d %c %c %d", tmp_name, &t_avg, &c_avg, &leader, &west, &p_count);

		if(t_avg>80 && p_count>=1){
			person_amount+=8000;
		}

		if(t_avg>85 && c_avg>80){
			person_amount+=4000;
		}

		if(t_avg>90) {
			person_amount+=2000;
		}

		if(t_avg>85 && west=='Y') {
			person_amount+=1000;
		}

		if(c_avg>80 && leader=='Y') {
			person_amount+=850;
		}

		if (person_amount>max_amount) {
			max_amount=person_amount;
			strcpy(max_name,tmp_name);
		}

		total_amount+=person_amount;
	}

	printf("%s\n%d\n%d", max_name, max_amount, total_amount);

	return 0;
}
