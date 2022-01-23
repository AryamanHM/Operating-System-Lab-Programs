#include<stdio.h> 
void print_gantt_chart(int n,int processes[],int bt[],int tat[])
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i] - 1; j++) printf(" ");
        printf("P%d", processes[i]);
        for(j=0; j<bt[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<bt[i]; j++) printf("  ");
        if(tat[i] > 9) printf("\b"); // backspace : remove 1 space
        printf("%d",tat[i]);

    }
    printf("\n");

}  
void findWaitingTime(int processes[], int n, 
						int bt[], int wt[]) 
{ 
	wt[0] = 0; 
	int i; 
	for(i=1;i<n;i++) 
		wt[i]=bt[i-1]+wt[i-1] ; 
} 
void findTurnAroundTime( int processes[], int n, 
				int bt[], int wt[], int tat[]) 
{  
	int i;
	for (i = 0; i < n ; i++) {
	
		tat[i] = bt[i] + wt[i]; }
	print_gantt_chart(n,processes,bt,tat);	
}  
void findavgTime( int processes[], int n, int bt[]) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0,i; 
	findWaitingTime(processes, n, bt, wt); 
	findTurnAroundTime(processes, n, bt, wt, tat); 
	printf("Processes Burst time Waiting time Turn around time\n");
	for (i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		printf(" %d ",processes[i]); 
		printf("	 %d ", bt[i] ); 
		printf("	 %d",wt[i] ); 
		printf("	 %d\n",tat[i] ); 
	} 
	float s=(float)total_wt / (float)n; 
	float t=(float)total_tat / (float)n; 
	printf("Average waiting time = %f",s); 
	printf("\n"); 
	printf("Average turn around time = %f ",t); 
} 

int main() 
{ 
	int n,i;
	printf("Enter number of process:");
    scanf("%d",&n);
    int processes[n],burst_time[n];
    printf("Enter process ID and burst time.\n");
	for(i=0;i<n;i++)
    {
    	printf("process ID:");
        scanf("%d",&processes[i]);
        printf("Burst time:");
        scanf("%d",&burst_time[i]);         
    } 
	findavgTime(processes, n, burst_time); 
	return 0; 
} 
 

