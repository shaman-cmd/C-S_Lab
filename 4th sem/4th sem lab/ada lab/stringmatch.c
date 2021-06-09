#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int cnt;
int stringmatch(char a[],char b[],int n,int m){
int i,j;

for(i=0;i<=n-m;i++){
for(j=0;j<m-1&&a[i+j]==b[j];j++,cnt++);
if(j==m-1) return i;
cnt++;
}
return -1;
}
int main(){
system("rm 'stringmatch_b.txt'");
system("rm 'stringmatch_b_cnt.txt'");
system("rm 'stringmatch_w.txt'");
system("rm 'stringmatch_w_cnt.txt'");
system("rm 'stringmatch_avg.txt'");
system("rm 'stringmatch_avg_cnt.txt'");
const char charset[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int i,n,key,pos;
char *a,b[4];
FILE *f1,*f2;
srand(time(NULL));
for(n=11;n<=101;n+=10){
cnt=0;
a=(char*)malloc(sizeof(char)*n);
for(i=0;i<n-1;i++){
key=rand()%(int)(strlen(charset));
a[i]=charset[key];
}
a[n-1]='\0';
for(i=0;i<3;i++){
b[i]=a[i];
}
b[3]='\0';
f1=fopen("stringmatch_b.txt","a");
f2=fopen("stringmatch_b_cnt.txt","a");
fprintf(f1,"the main string is %s and matching string is %s\n",a,b);
pos=stringmatch(a,b,n,4);
fprintf(f1,"pos=%d\n\n",pos);
fprintf(f2,"%d\t%d\n",n-1,cnt);
fclose(f1);
fclose(f2);

cnt=0;
for(i=0;i<3;i++){
b[i]=a[(n-3+2*i)/2];
}
b[3]='\0';
f1=fopen("stringmatch_avg.txt","a");
f2=fopen("stringmatch_avg_cnt.txt","a");
fprintf(f1,"the main string is %s and matching string is %s\n",a,b);
pos=stringmatch(a,b,n,4);
fprintf(f1,"pos=%d\n\n",pos);
fprintf(f2,"%d\t%d\n",n-1,cnt);
fclose(f1);
fclose(f2);





for(i=0;i<n-1;i++){
a[i]='a';
}
a[i]='\0';
for(i=0;i<3;i++){
if(i==2)
b[i]='b';
else
b[i]='a';

}
b[3]='\0';
cnt=0;

f1=fopen("stringmatch_w.txt","a");
f2=fopen("stringmatch_w_cnt.txt","a");
fprintf(f1,"the main string is %s and matching string is %s\n",a,b);
pos=stringmatch(a,b,n,4);
fprintf(f1,"pos=%d\n\n",pos);
fprintf(f2,"%d\t%d\n",n-1,cnt);
fclose(f1);
fclose(f2);
}
system("gnuplot>load 'plot.txt'");
}



