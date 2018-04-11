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

  		printf("\n\nQueue1 has been  executed !!\n\n");
  		int a;
  		for(a=0; a< Q1_C ; a++)
  		{
  			printf("\nCompletion time of proc. %d = %d ",Q1[a].process_id,Q1[a].completion_time);
  		}
  		        for(x=0;B_z != Q2_C;){
  					if(Q2[x].burst_time <= t_Q && Q2[x].burst_time >0 ){
  						st+=Q2[x].burst_time;
        					Q2[x].burst_time=0;
       					flag=1;
  					}
  					else if(Q2[x].burst_time>0)
      				{
       					Q2[x].burst_time-=t_Q;
        					st+=t_Q;
     					}

  					if(Q2[x].burst_time==0 && flag==1)
  				    {
  				    	B_z++;
  					  	Q2[x].completion_time = st+1;
  				      	flag=0;
  				    }
  					if(x==Q2_C -1)
        					x=0;
  					else if(Q2[x+1].arrival_time<=st)
        					x++;
  					else
        					x=0;

  			}
  	        printf("\n\nQueue2 executed !!");
  			for(a=0; a< Q2_C ; a++)
  				{
  					printf("\nCompletion time of proc. %d = %d ",Q2[a].process_id,Q2[a].completion_time);
  				}

  			break;
  	}

  	int avg_tat1=0;
  	int avg_tat2=0;
  	int avg_wt1=0;
  	int avg_wt2=0;


  	for(i=0;i<Q1_C;i++){
  		Q1[i].turnaround_time=Q1[i].completion_time - Q1[i].arrival_time;

  	}

  	for(i=0;i<Q2_C;i++){
  		Q2[i].turnaround_time=Q2[i].completion_time - Q2[i].arrival_time;

  	}

  	for(i=0;i<Q2_C;i++){
  		Q2[i].waiting_time=Q2[i].turnaround_time - Q2[i].burst_time;

  	}

  	for(i=0;i<Q1_C;i++){
  		Q1[i].waiting_time=Q1[i].turnaround_time - Q1[i].burst_time;

  	}

  	printf("\n\nPROCESS NAME |\t TURN AROUND TIME |\t WAITING TIME \n");
  	for(i=0;i<Q1_C;i++){
  	printf(" %d             |\t\t%d         |\t\t%d \n",Q1[i].process_id,Q1[i].turnaround_time,Q1[i].waiting_time);
  	}
  	for(x=0;x<Q2_C;x++){
  	printf(" %d             |\t\t%d         |\t\t%d \n ",Q2[x].process_id,Q2[x].turnaround_time,Q2[x].waiting_time);
  	}


  	for(i=0;i<Q1_C;i++){

  		avg_tat1=avg_tat1+Q1[i].turnaround_time;
  	}
  	avg_tat1= (avg_tat1 / Q1_C);
  	for(i=0;i<Q2_C;i++){

  		avg_tat2=avg_tat2+Q2[i].turnaround_time;
  	}
  	avg_tat2= (avg_tat2 / Q2_C);
  	for(i=0;i<Q2_C;i++){

  		avg_wt2=avg_wt2+Q2[i].waiting_time;
  	}
  	avg_wt2= (avg_wt2 / Q2_C);
  	for(i=0;i<Q1_C;i++){

  		avg_wt1=avg_wt1+Q1[i].waiting_time;
  	}
  	avg_wt1= (avg_wt1 / Q1_C);

  	printf("\n\nPROCESS process_id |\t AVERAGE TURN AROUND TIME |\t AVERAGE WAITING TIME \n");
  	printf(" %d            |\t\t%d         |\t\t%d \n",Q1[i].process_id,avg_tat1,avg_wt1);
  	printf(" %d            |\t\t%d         |\t\t%d \n",Q1[i].process_id,avg_tat2,avg_wt2);


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
pro_exe(P,Q1,Q2,Q1_C,Q2_C);
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
