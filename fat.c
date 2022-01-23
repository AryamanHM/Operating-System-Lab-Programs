#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int processes[] = {0,1,2,3,4,5,6};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {7,12,40,13,6,44,8};
    int arrival[]={0,0,0,0,0,0,0};
    int quantum = 3,x,y,q1i[20],q1[20],q2i[20],q2[20],q3i[20],q3[20],i,e1[20],e2[20],e3[20],p1=0,p2=0,p3=0,j,temp,pos;
    int wt1[20],total1=0,tat1[20],wt2[20],total2=0,tat2[20],wt3[20],total3=0,tat3[20];
    float avg_wt1,avg_tat1,avg_wt2,avg_tat2,avg_wt3,avg_tat3;
    for(i=0;i<=7;i++)
    {
    	x=processes[i];
    	y=burst_time[i];
    	if(x<=10)
    	{
    	q1i[i]=x;
    	q1[i]=y;
    	e1[i]=0;
    	p1++;
}
else if(x>10 && x<=30)
{
	q2i[i]=x;
	q2[i]=y;
	e2[i]=0;
	p2++;
}
else
{
	q3i[i]=x;
	q3[i]=y;
	e3[i]=0;
	p3++;
}
 for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(q1[j]<q1[pos])
                pos=j;
        }
  
        temp=q1[i];
        q1[i]=q1[pos];
        q1[pos]=temp;
  
        temp=q1i[i];
        q1i[i]=q1i[pos];
        q1i[pos]=temp;
    }
     wt1[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt1[i]=0;
        for(j=0;j<i;j++)
            wt1[i]+=q1[j];
  
        total1+=wt1[i];
    }
  
    avg_wt1=(float)total1/n;      
    total1=0;
  
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat1[i]=q1[i]+wt1[i];   
        total1+=tat1[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",q1i[i],q1[i],wt1[i],tat1[i]);
    }
  
    avg_tat1=(float)total1/n;    
    printf("\n\nAverage Waiting Time=%f",avg_wt1);
    printf("\nAverage Turnaround Time=%f\n",avg_tat1);
     for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(q2[j]<q2[pos])
                pos=j;
        }
  
        temp=q2[i];
        q2[i]=q2[pos];
        q2[pos]=temp;
  
        temp=q2i[i];
        q2i[i]=q2i[pos];
        q2i[pos]=temp;
    }
    wt2[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt2[i]=0;
        for(j=0;j<i;j++)
            wt2[i]+=q2[j];
  
        total2+=wt2[i];
    }
  
    avg_wt2=(float)total2/n;      
    total2=0;
  
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat2[i]=q2[i]+wt2[i];   
        total2+=tat2[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",q2i[i],q2[i],wt2[i],tat2[i]);
    }
  
    avg_tat1=(float)total2/n;    
    printf("\n\nAverage Waiting Time=%f",avg_wt2);
    printf("\nAverage Turnaround Time=%f\n",avg_tat2);
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(q3[j]<q3[pos])
                pos=j;
        }
  
        temp=q3[i];
        q3[i]=q3[pos];
        q3[pos]=temp;
  
        temp=q3i[i];
        q3i[i]=q3i[pos];
        q3i[pos]=temp;
    }
    wt3[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt3[i]=0;
        for(j=0;j<i;j++)
            wt3[i]+=q3[j];
  
        total3+=wt3[i];
    }
  
    avg_wt3=(float)total3/n;      
    total3=0;
  
    printf("\nProcesst    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat3[i]=q3[i]+wt3[i];   
        total3+=tat3[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",q3i[i],q3[i],wt3[i],tat3[i]);
    }
  
    avg_tat3=(float)total3/n;    
    printf("\n\nAverage Waiting Time=%f",avg_wt3);
    printf("\nAverage Turnaround Time=%f\n",avg_tat3);
    return 0;
}
}
