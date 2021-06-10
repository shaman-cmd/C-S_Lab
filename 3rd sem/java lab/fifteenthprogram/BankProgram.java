package fifteenthprogram;
import java.util.*;
abstract class Bank{
    String bankType;
   
    int term;
    double roi, balance;

	String name;

    Bank(String s){
        this.balance=0.0;
        this.term=0;
        this.roi=0;
        bankType=s;
    }

  


    abstract void getRoi();

    void deposit(double amount,int term){
        this.balance+=amount;
        this.term=term;
        getRoi();
    }
    void CreditCardOffer(){
        if(bankType=="international"){
        System.out.println("platinum credit card is offered");
        }
        else if (bankType =="national") {
        	System.out.println("platinum credit card is not  offered");
        }
     }
}

class SBI extends Bank{
	
    SBI(String s){
        super(s);
        
        CreditCardOffer();
        name="SBI";
    }

    void getRoi(){
        if(term>=3){
           roi=7;
        }
    }

   
}

class PNB extends Bank{
    PNB(String s){
        super(s);
        
        name="PNB";
        CreditCardOffer();
        
    }

    void getRoi(){
        if(term>=3){
            roi=7;
        }
    }

    
}

class ANZ extends Bank{
    ANZ(String s){
        super(s);
        
        
        name="ANZ";
        CreditCardOffer();
    }

    void getRoi(){
        if(term>=3){
        	roi=8;
                  }
    }

    
}

class AEBC extends Bank{
 
    AEBC(String s){
        super(s);
      
       name="AEBC";
       
       CreditCardOffer();
    }

    void getRoi(){
        if(term>=3){
             roi=07;
        }
    }

    
}

public class BankProgram {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Bank bank = null;
        
        int choice;

       for(;;) {
           
            

       

            System.out.println("Enter the amount you want to deposit?");
            double amount=sc.nextDouble();

            System.out.println("Enter the term?");
            int term=sc.nextInt();
            System.out.println("\n1.State Bank of India(SBI)\n2.Punjab National Bank(PNB)\n3.ANZ BANK\n4.AEBC\n5.EXIT \nSelect bank:");
            choice=sc.nextInt();


            switch(choice){
                case 1: bank = new SBI("national");
                    bank.deposit(amount,term);
                   break;
                case 2: bank = new PNB("national");
                    bank.deposit(amount,term);
                    break;
                case 3: bank = new ANZ("international");
                    bank.deposit(amount,term);
                    
                    break;
                case 4: bank = new AEBC("international");
                    bank.deposit(amount,term);
                    break;
                default: System.exit(0);
            }
        

        System.out.println("\nBank details:");
       
           
            System.out.println("BANK NAME:"+bank.name);
            System.out.println("Type: "+bank.bankType);
            System.out.println("Balance: "+bank.balance);
            System.out.println("ROI: "+bank.roi);
            System.out.println("Term: "+bank.term);
       }

    }
}