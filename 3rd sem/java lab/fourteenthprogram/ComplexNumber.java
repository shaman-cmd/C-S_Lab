package fourteenthprogram;

import java.util.Scanner;

class complex {
float r,i;
complex(float r,float i){
	this.r=r;
	this.i=i;
}
static void display(complex c) {
	System.out.print(c.r+"+"+c.i+"i");
}
public static complex add(complex A,complex B) {
	complex C = new complex((A.r+B.r),(A.i+B.i));
	return C;
}
static complex add1(int a,complex B) {
	complex C = new complex((a+B.r),+B.i);
	return C;
}

}
public class ComplexNumber {
	 public static void main(String[]args) {
		 Scanner in = new Scanner(System.in);
		 System.out.println("enter the real and imaginary parts of complex number Z1");
		 complex Z1=new complex(in.nextFloat(),in.nextFloat());
	
		 System.out.println("enter the real and imaginary parts of complex number Z2");
		 complex Z2=new complex(in.nextFloat(),in.nextFloat());
		 System.out.print("addition of complex number\n Z1 =");
		 complex.display(Z1);
		 System.out.print("and complex number \nZ2 =");
		 complex.display(Z2);
		 System.out.print(" is ");
		 complex C = complex.add(Z1,Z2);
		 complex.display(C);
		 System.out.println("\nenter any  integer a");
		 int a=in.nextInt();
		 complex D= complex.add1(a, Z1);
		 System.out.print("addition of complex number\n Z1 =");
		 complex.display(Z1);
		 System.out.print("and integer "+a+"is");
		 complex.display(D);
		 
	 }
}
