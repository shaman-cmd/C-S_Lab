package seventeethprogram;
import java.util.*;

class StackUnderflowExecption extends Exception{  
	

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	StackUnderflowExecption(){  
		super();
	 }  
	} 

class StackOverflowException extends Exception{
	

	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	StackOverflowException(){
		super();
	}
}
class Stack{
	int items[]=new int[10],top;
	Stack(){
		top=-1;
	}
	int pop() throws StackUnderflowExecption  {
		if(top==-1) {
			throw new StackUnderflowExecption(); 
		}
		System.out.println("the element"+items[top]+"has been popped");
		return this.items[top--];
	}
	void push(int a)throws StackOverflowException {
		if(top==9) {
			throw new StackOverflowException();
		}
		top++;
		items[top]=a;
	}
	
	
}
public class StackProgram {
public static void main (String[] args)  {
	int choice;
	Scanner in = new Scanner(System.in);
	Stack A = new Stack();
	for(;;) {
	System.out.println("enter ur choice\n1.push element into stack\n2.pop an element from stack");
	choice=in.nextInt();
	switch(choice){
	case 1:
		System.out.println("enter te element to be pushed");
		
	
		try {
			A.push(in.nextInt());
		} catch (StackOverflowException e) {
			
			System.out.println(e);
		}
	
		break;
	case 2:
		try {
			A.pop();
		}
		catch(StackUnderflowExecption a) {
			System.out.println(a);
		}
		break;
	default:
		System.exit(0);
	}
	}
}
}