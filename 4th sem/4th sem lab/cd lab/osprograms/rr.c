// Program to implement SRTF Scheduling algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int remaining_time;
	int finished_index;
} process_t;
struct queue{
int a[100];
int l;
int r;
};
typedef struct queue que; 
void insert(que*q,int i){
if(q->r==99){printf("que is full");return;}
q->a[++q->r]=i;
}

int delete(que*q){
if(q->l>q->r){printf("que is empty");return -1;}
int z=q->a[q->l++];
if(q->l>q->r){q->r=-1;q->l=0;}
return z;
}
que QUE;


process_t processes[10];
int n;

int arrival_comparator(const void* a,const void* b) {
return ((process_t*)a)->arrival_time > ((process_t*)b)->arrival_time;
}
int finished_comparator(const void * a, const void * b) {
return ((process_t*)a)->finished_index > ((process_t*)b)->finished_index;
}

void schedule_rr(int tq) {
	int i, finished_jobs = 0;
	float twt = 0, ttt = 0;
	qsort(processes, n, sizeof(process_t), arrival_comparator);
	int cur_time = 0;
         i=0;int in=0,j=i+1;
	
		while(i!=-1){
			if (processes[i].remaining_time != 0) {
			
				if (processes[i].remaining_time <= tq) {
					printf("Scheduling process %d and finishing\n", processes[i].id);
					cur_time += processes[i].remaining_time;
					processes[i].remaining_time = 0;
					processes[i].turn_around_time = cur_time - processes[i].arrival_time;
					processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
					processes[i].finished_index = finished_jobs++;

					twt += processes[i].waiting_time;
					ttt += processes[i].turn_around_time;
					if(in==0){
					for(;j<n&&(processes[j].arrival_time<=cur_time);j++){insert(&QUE,j);if(j==n-1){in=1;}}
					}
					
				} else {
				        
					printf("Scheduling process %d...\n", processes[i].id);
					processes[i].remaining_time -= tq;
					cur_time += tq;
					if(in==0){
					for(;j<n&&(processes[j].arrival_time<=cur_time);j++){insert(&QUE,j);if(j==n-1){in=1;}}
					}
					insert(&QUE,i);
				}
			}
			i=delete(&QUE);
			}
		        
	
	
	
	qsort(processes, n, sizeof(process_t), finished_comparator);

	// Print table
	printf("\nId\tAT\tBT\tWT\tTT\n");
	for (i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival_time,
									   processes[i].burst_time, processes[i].waiting_time,
									   processes[i].turn_around_time);
	
	printf("Average waiting time: %f\n", twt/((float)n));
	printf("Average turnaround time: %f\n", ttt/((float)n));
}

int main() {
	int i,tq;
	QUE.r=-1;
        QUE.l=0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
        printf("time quantum\n");
        scanf("%d",&tq);
	printf("Enter process details\nArrival time\tBurst time\n");
	for (i = 0; i < n; i++) {
		processes[i].id = i+1;
		scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
		processes[i].remaining_time = processes[i].burst_time;
	}

	schedule_rr(tq);
}
