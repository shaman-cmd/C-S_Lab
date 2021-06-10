package fifthprogram;

public class SbiBankAccount {
double accountnumber;
float balance;
String name= new String();
String typeofaccount = new String();

SbiBankAccount(String name,double accountnumber,String typeofaccount){
	this.name=name;
	this.accountnumber=accountnumber;
	this.typeofaccount=typeofaccount;
	
}
void deposit(float a) {
	balance= balance+a;
	System.out.println("amount "+a+"is deposited to your account");
}
void withdraw(float a) {
	if(balance<a) {
		System.out.println("insufficent balance transcation failed");
		return ;
	}
	balance= balance-a;
	System.out.println("amount "+a+"is withdrawn from your account");
	}
void Display() {
	System.out.println("NAME:"+name);
	System.out.println("balance:"+balance);
}
	
}


