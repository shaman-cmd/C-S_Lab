package eleventhprogram;import java.util.*;
class Book{
	String name,code;
	float unitprice,totalprice;
	int quantity;
	static float total;
	void read() {
		Scanner in =new Scanner(System.in);
		System.out.println("enter the book name or title");
		name=in.next();
		System.out.println("enter the code of the book"+name);
		code=in.next();
		System.out.println("enter the unit price of a book"+name);
		unitprice=in.nextFloat();
		System.out.println("enter the quantity of"+name+"books purchased");
		quantity=in.nextInt();
		totalprice=quantity*unitprice;
		total=total+totalprice;
	}
	void display() {
		System.out.println(name+"\t\t"+code+"\t\t"+unitprice+"\t\t"+quantity+"\t\t"+totalprice);
	}
	
}
public class BooksBillCalculator {
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		System.out.println("enter the number of books:");
		int n=in.nextInt(),i;
		Book books[] =new Book[n];
		for(i=0;i<n;i++) {
			System.out.println("enter the details of book"+(i+1));
			books[i]=new Book();
			books[i].read();
		}
		System.out.println("bookname\tbookcode\tunitprice\tquantity\ttotalprice");
		for(i=0;i<n;i++) {
			books[i].display();
		}
		System.out.println("the totalprice to be paid for all books"+Book.total);
in.close();
}
}
