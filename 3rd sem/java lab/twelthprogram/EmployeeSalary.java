package twelthprogram;
import java.util.*;



class Employee{
	String name,id,departmentname;
	double basicpay,grosspay,netpay,incometax;
	void read() {Scanner in = new Scanner(System.in);
		System.out.println("enter the employee id");
		id=in.next();
		System.out.println("enter the employee name");
		name = in.next();
		System.out.println("enter the department of employee"+name);
		departmentname=in.next();
		System.out.println("enter the basic pay of employee"+name);
		basicpay=in.nextDouble();
		grosspay=basicpay+(58*basicpay/100)+(16*basicpay/100);
		}
	void computeNetPay(){
		if(grosspay<=200000) {
			incometax=0;
		}
		else if(200000<grosspay&&grosspay<=300000) {
			incometax=0.1*grosspay;
			}
		else if(30000<grosspay&&grosspay<=500000){
			incometax=0.15*grosspay;
			}
		else if(grosspay>500000){
			incometax=0.3*grosspay;
			incometax=incometax+(incometax*0.2);
			
		}
		netpay=grosspay-incometax;
	}
	void display() {
		System.out.println(id+"\t"+name+"\t"+basicpay+"\t\t"+grosspay+"\t\t"+netpay);
	}
	
	}
public class EmployeeSalary {
	public static void main(String[]args) {
Scanner in = new Scanner(System.in);
System.out.println("enter the no of employees");
int N=in.nextInt(),i;
Employee employee[]=new Employee[N];
for(i=0;i<N;i++) {
	System.out.println("enter the details of employee"+(i+1));
	employee[i]=new Employee();
	employee[i].read();
	employee[i].computeNetPay();
      }
System.out.println("displaying grosspay and net pay of all employees");
System.out.println("id\tname\tbaiscpay\tgrosspay\tnetpay");
for(i=0;i<N;i++) {
	employee[i].display();
}

	}
	
}
