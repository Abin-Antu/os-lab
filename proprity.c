#include<stdio.h>
int main()
{
    int n ,i,j,temp;
    int bt[20],wt[20],tat[20],p[20],priority[20];
    int total_wt =0 ,total_tat=0;
    printf("enter the number of process :");
    scanf("%d",&n);
    printf("enter the burst time and the priority\n ");
    for(i=0;i<n;i++)
    {
        printf("p%d hte burst time",i+1);
        scanf("%d",&bt[i]);
        printf("p%d the priority",i+1);
        scanf("%d",&priority[i]);
        p[i] = i+1;
    }
    //sort the burst time 
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(priority[i] > priority[j])
            {
                // swap the burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // swap the process id
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                // swap the priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp ;
            }
        }
    }
    // calculate the waiting time
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i] = wt[i-1]+bt[i-1];
    }
    // calculate the turn around time
    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] +bt[i];
    }
    printf("\n Process\t burst Time\t\tPriority\t Waiting Time \t Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\n",p[i],bt[i],priority[i],wt[i],tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("The total waiting time is %d\n",total_wt);
    printf("The total turn around time is %d\n",total_tat);
    printf("The average waiting time is%d \n",total_wt/n);
    printf("The average turnaround time is %d\n",total_tat/n);
        
    }
    