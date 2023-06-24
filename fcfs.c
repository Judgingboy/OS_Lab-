#include <stdio.h>

int P[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0;

float awt,avg_tat,avg_wt;

void main()
{
 int i;
 printf("\n Enter no : of processes: ");
 scanf("%d",&n);
 printf("Enter burst time for each process : ");
 
 for (int i=0;i<n;i++)
 {
  scanf("%d",&bt[i]);
  P[i]=i;
 }
 
 int WT_TAT(int *a,int *b)
 {
  int i;
  for(int i=0;i<n;i++)
  {
  if(i==0)
    tat[i]=bt[i];
  else
    tat[i]=tat[i-1]+bt[i];
  tot_tat=tot_tat+tat[i];
  }

  *a=tot_tat;
  wt[0]=0;
 
  for(i=1;i<n;i++)
  {
   wt[i]=wt[i-1]+bt[i-1];
   tot_wt=tot_wt+wt[i];
  }

  *b=tot_wt;
  printf("\n Process \t\t Burst Time \t Turnaround time \t Waiting Time");

  for(i=0;i<n;i++)
    printf("\n Process [%d] \t\t %d \t\t %d \t\t\t %d",P[i],bt[i],tat[i],wt[i]);
 return 0;
 }

 printf("\n FCFS Algorithm : \n");
 WT_TAT(&FCFS_tat,&FCFS_wt);
 printf("\n Total turnaround time %d",FCFS_tat);
 printf("\n Average turnaround time %d",(FCFS_tat)/n);
 printf("\n Total waiting time %d",FCFS_wt);
 printf("\n Average waiting time %d",(FCFS_wt)/n);

 
 
}












