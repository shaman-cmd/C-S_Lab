void bubblesort(int arr[], int n) 
{
  int swapped=0;
  int tmp, i,j;
 

  for(i=0;i<n-1;i++){
  for(j=0;j<n-i-1;j++){
  
  if(arr[j]>arr[j+1]){
  tmp=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=tmp;
  swapped=1;
  }
  }
  if(swapped==0)break;
  }
  
}
