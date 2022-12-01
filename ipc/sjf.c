#include<stdio.h>

int main() {

  int n;
  printf("Enter number of process:");
  scanf("%d",&n);

  int burst_time[n],p[n];
  int waiting_time[n];
  int turn_around_time[n];
  int i, j, position, temp; 
  int total=0;
  float avg_waiting_time;
  float avg_turn_around_time;
 
  // printf("Enter burst time for process: ");
  // for (int i = 0; i < n; i++) {
  //   scanf(" %d", &burst_time[n]);
  // }

    printf("Enter Burst Time: ");
    for(i=0;i<n;i++) {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;         
    }
  
   //sorting of burst times
    for(i=0;i<n;i++) {
      
      position=i;
        
      for(j=i+1;j<n;j++) {
        if(burst_time[j]<burst_time[position]) {
          position=j;
        }
      }
  
      temp=burst_time[i];
      burst_time[i]=burst_time[position];
      burst_time[position]=temp;
  
      temp=p[i];
      p[i]=p[position];
      p[position]=temp;
    }
   
    waiting_time[0]=0;            
  
   
    for(i=1;i<n;i++) {
      waiting_time[i]=0;
    
      for(j=0;j<i;j++) {
            waiting_time[i]+=burst_time[j];
      }
      total+=waiting_time[i];
    }
  
    avg_waiting_time=(float)total/n;      
    total=0;
  
    printf("\nProcess ID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++) {
      turn_around_time[i]=burst_time[i]+waiting_time[i];   
      total+=turn_around_time[i];
      printf("%d\t\t%d\t%d\t%d\n",i+1,burst_time[i],waiting_time[i],turn_around_time[i]);
    }
  
    avg_turn_around_time=(float)total/n;    
    printf("Average Waiting Time=%.2f\n",avg_waiting_time);
    printf("Average Turnaround Time=%.2f\n",avg_turn_around_time);
}
