#include<stdio.h>
void print_gantt_chart(int n,int processes[],int bt[],int tat[],int wt[])
{
    int i, j;
    int last = bt[n-1] + ( n== 1 ? 0 : wt[n-1]);
    // printing top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    // middle position
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]-1; j++) printf(" ");
        printf("p%d", processes[i]);
        for(j=0; j<bt[i]-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing waiting time
    int minus = 0;
    for(i=0; i<n; i++) {
        if(wt[i]>9) printf(" ");
        printf("%d", wt[i]);
        if(wt[i+1]>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<bt[i]-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    printf("%d\n", last);
}
 int main()
{
	int n;
    printf("Enter number of process:");
    scanf("%d",&n);
    int bt[n],p[n],wt[n],tat[n],i,j,total=0,pos,temp;
    float avg_wt,avg_tat;
	printf("\nEnter Process ID and Burst Time:\n");
    for(i=0;i<n;i++)
    {
    	printf("\nprocess ID:");
        scanf("%d",&p[i]);
        printf("\nBurst time:");
        scanf("%d",&bt[i]);         
    } 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
   
    wt[0]=0;            
   for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
   avg_wt=(float)total/n;      
    total=0;
  printf("\nProcesst    Burst Time    tWaiting TimetTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
   avg_tat=(float)total/n;    
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    print_gantt_chart(n,p,bt,tat,wt);
    
}
