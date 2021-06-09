#include<stdio.h>
#include<stdlib.h>
typedef struct JOB{
int processid;
int at;
int bt;
int ct;
} job;
typedef struct QUE{
job jobs[10];
int f,r;
} que;
void insert(que*q,job
