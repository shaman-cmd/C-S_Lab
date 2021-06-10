package fifthprogram;
import java.util.Scanner;

public class ExecuteAccount {
public static void main(String args[]) {
	SbiBankAccount[] obj = new SbiBankAccount[5];
	int i=0;
	Scanner sc =new Scanner(System.in);
	for(;;) {
		System.out.println("enter the choice");
		System.out.println("1.intiate your bank account\n2.to perform deposit or  withdrawl or display your balance");
		
		int choice =sc.nextInt();
		switch(choice) {
		case 1:
			if(i>4) {
				System.out.println("number of account holders limit reached");
			}
			System.out.println("enter the name of account holder ");
			String name =sc.next();
			String Type = new String();
			System.out.println("enter the type of bank account\npress 1 for savings\npress 2 for current type of account" );
			int n;
			
				 n=sc.nextInt();
			
			if(n==1)
				 Type = "Savings";
			else
				 Type = "current";
			obj[i++]=new SbiBankAccount(name,19002020+i,Type);
			System.out.println("your bank account with account number"+(19002020+i )+"as been created");;
			break;
		case 2:
			System.out.println("enter the account number ");
			double number = sc.nextDouble();
			double j;
			j=number-19002020-1;
			int s=(int)j;
			for(;;) {
				System.out.println("enter the choice");
				System.out.println("1.deposit money\n2.withdraw money\n3.display balance\n4.exit");
				int c = sc.nextInt();
				switch(c) {
				case 1:
					System.out.println("enter the amount to be deposited");
					float N =sc.nextFloat();
					obj[s].deposit(N);
					obj[s].Display();
					break;
				case 2:
					System.out.println("enter the amount to be withdraw");
					 N =sc.nextFloat();
					 obj[s].withdraw(N);
					 obj[s].Display();
					 break;
				case 3:
					obj[s].Display();break;
				
				default :
				   break;	
				}			
			}
			
			
		default :
			System.exit(0);
			
			
			


			
			
			
			
			
			
		}
		
		
		
	}
	
	
	
}
}
