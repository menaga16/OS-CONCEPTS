#include<stdio.h>
#include<stdlib.h>

int pending[15];


int main(){
	int flag; 
	int num_res, num_process;
	printf("enter the number of resources:");
	scanf("%d",&num_res);
	printf("enter the number of process:");
	scanf("%d",&num_process);
	int i,j,k,w;
	int alloc_tbl[num_process][num_res];  
	int max[num_process][num_res];	
	int need[num_process][num_res]; 
	int available[num_res]; 
	int finish[num_process]; 
	int safe_seq[num_process]; 
	for(i =0;i<num_process;i++){
		finish[i] = 0; 
		safe_seq[i] = 9999;
	}
	printf("-----------ALLOCATION TABLE----------------\n");
	for(i=0;i<num_process;i++){
		for(j=0;j<num_res;j++){
			printf("enter allocation for process%d resource %c:",i+1,j+65);
			scanf("%d",&alloc_tbl[i][j]);
		}
	}

	printf("-----------MAX TABLE----------------\n");
	for(i=0;i<num_process;i++){
		for(j=0;j<num_res;j++){
			printf("enter max for process%d resource %c:",i+1,j+65);
			scanf("%d",&max[i][j]);
		}
	}
	printf("----------AVAILABLE-------\n");
	for(i=0;i<num_res;i++){
		printf("enter the available resource %c:",i+65);
		scanf("%d",&available[i]);
	}
	
	
	for(i=0;i<num_process;i++){
		for(j=0;j<num_res;j++){
			need[i][j]=max[i][j] - alloc_tbl[i][j];
		}
	}	
	int found = 0;

	k=0;     
	while(1){
		found = 0;  
		for(i=0;i<num_process;i++){
			if(finish[i] == 0){
				int flag = 0;
				for(j=0;j<num_res;j++){
					if( need[i][j] > available[j]){
						flag = 1; 
						break;
					}
				}
			
				if (flag == 0){ 
					safe_seq[k] = i;
					k++;
					found = 1;
					for(w = 0; w<num_res; w++){
						available[w]+=alloc_tbl[i][w];
					}
					finish[i] = 1;	
				}
			}
		}
	
		int flag_sum = 0;
	
		for(w=0;w<num_process;w++){
			flag_sum+=finish[w];
		}
		if(flag_sum == num_process){ 
			break;
		}
	
		if(found == 0){
			printf("unsafe state!!!\n");
			break;
		}
	}
	
	printf("safe sequence...........\n");
	for(i=0;i<num_process;i++){
		if(safe_seq[i] == 9999){
			break;
		}
		printf("P%d ",safe_seq[i]+1);
	}
	return 0;
}
