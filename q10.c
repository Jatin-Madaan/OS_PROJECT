#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
struct p{
  int arrival_time;
  int burst_time;
  int process_id;
  int type;
  int completion_time;
  int turnaround_time;
  int waiting_time;
};
int st,N;
void pro_exe(struct p P[],struct p Q1[],struct p Q2[],int Q1_C, int Q2_C){

  	printf("\n Enter the time where to start  :  \n");

  	scanf("%d",&st);
    fflush(stdin);

  	int t_Q=2,INT_MAXIMUM;
  	int B_z=0;
  	int rem_t[N];
  	int flag ;
  	int k=0;
  	int x,i;
  	int z;
  	struct p temp;
  	int comp= 0, t = 0, min_m=Q1[0].burst_time;
  	int least = 0, fin_time;
  	int flag1 = 0;
  	while(1){

  		for (i = 0; i < Q1_C;i++){
  			rem_t[i] = Q1[i].burst_time;
  		}

         	while(comp != Q1_C){
  	       		for (x = 0; x < Q1_C; x++) {
  	            	if ((Q1[x].arrival_time <= st) && (rem_t[x] <= min_m) && rem_t[x] > 0) {
  	                	min_m = rem_t[x];
  	                	least = x;
  	                	flag1=1;
  					}
  	       		}
  	       		
  	       			if(flag1==0) {
  	            st++;
  	            continue;
  	        }


  	        rem_t[least]--;

  	        min_m = rem_t[least];
  	        if(min_m == 0)
  	             min_m = INT_MAXIMUM;

  			if (rem_t[least] == 0) {
  	 			     comp++;
  	            Q1[least].completion_time = st;
  	            fin_time = st + 1;
  	 			Q1[least].completion_time = st+1;
  			}


  	        st ++ ;
  	       }
  	   }
  }
void pro_div(struct p P[],struct p Q1[],struct p Q2[]){
  int Q1_C=0;
  int Q2_C=0;

  for(int i=0;i<N;i++){
    if(P[i].type == 0){
        Q1[Q1_C]=P[i];
        printf("\nprocess p %d is in Q0\n",i);
        Q1_C++;
        sleep(1);
      }
    if(P[i].type == 1){
        Q2[Q2_C]=P[i];
        printf("\nprocess p %d is in Q1\n",i);
        Q2_C++;
        sleep(1);
      }
}

}






void pro_cre(){
  printf("No of processes: \n");
  scanf("%d",&N);
  struct p P[N];
  struct p Q1[N];
  struct p Q2[N];

  for(int c = 0;c<N;c++){

  printf("Arrival time of  process   %d     : ",c);
  scanf("%d",&P[c].turnaround_time);
  fflush(stdin);

  printf("Burst  time of  process   %d     : ",c);
  scanf("%d",&P[c].burst_time);
  fflush(stdin);

  printf("Process class (system_level/user-level-0/1)       : ");
  scanf("%d",&P[c].type);
  fflush(stdin);
  P[c].process_id=c;
  }

  pro_div(P,Q1,Q2);
}



int main(){
  pro_cre();
}
