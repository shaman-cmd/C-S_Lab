package eightprogram;
import java.util.*;
public class ArrayMerger {
static int[] merge(int arr1[],int arr2[]) {
	int i=0,m=arr1.length,n=arr2.length,x=0,y=0;
	int mergedarray[] = new int[m+n];
	for (i = 0; i <= m+n && x != m && y != n; i++) {
		if (arr1[x] < arr2[y])
			mergedarray[i] = arr1[x++];
		else
			mergedarray[i] = arr2[y++];
	}
	while (x < m)
		mergedarray[i++]=arr1[x++];
	
	while (y < n)
		mergedarray[i++] = arr2[y++];
	return mergedarray;
	}
public static void main(String[]args) {
	Scanner in = new Scanner(System.in);
	System.out.println("enter the size of array A");
	int m= in.nextInt();
	System.out.println("enter the size of array B");
	int n= in.nextInt();
	int A[]=new int[m],i;
	int B[]=new int[n];
	
	System.out.println("enter the elements of array A  one by one in ascending order\n");
	for( i=0;i<m;i++) {
		A[i]=in.nextInt();
	}
	System.out.println("enter the elements of array B  one by one in ascending order\n");
	for( i=0;i<m;i++) {
		B[i]=in.nextInt();
	}
	System.out.println("the elements of array A is\n");
	for( i=0;i<m;i++) {
		System.out.print(A[i]+" ");
	}
	System.out.println("the elements of array B is\n");
	for( i=0;i<n;i++) {
		System.out.print(B[i]+" ");
	}
	int C[]=merge(A,B);
	System.out.println("the elements of array C by merging both A and B is\n");
	for( i=0;i<m+n;i++) {
		System.out.print(C[i]+" ");
	}
}
}
