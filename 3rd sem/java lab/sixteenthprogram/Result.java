package sixteenthprogram;
import java.util.*;
  class Student{
	int rollno;
	void getNumber() {
		Scanner in = new Scanner(System.in);
		System.out.println("enter the roll no of the student");
		rollno=in.nextInt();
		
	}
	void putNumber() {
		System.out.println(rollno);
		
	}
}
  class Test extends Student{
	  float marks[]=new float[2];
	  void readmarks() {
		  Scanner in = new Scanner(System.in);
		  System.out.println("enter the marks od subject1 and subject2");
		  marks[0]=in.nextFloat();
		  marks[1]=in.nextFloat();
		  }
	  void displayMarks() {
		 System.out.format("subject1=%f and subject2=%f\n",marks[0],marks[1]);
	  }
	  
  }
  interface Sport{
	  void readWeightage();
	  void displayWeightage();
  }
public class Result  extends Test implements Sport{
float sportsWeightage,totalWeightage;
@Override
public void readWeightage() {
	Scanner in =new Scanner(System.in);
	System.out.println("enter the students sports weightage");
	sportsWeightage=in.nextFloat();
}
public void displayWeightage() {
	System.out.println(sportsWeightage);
}
public void Scorecard() {
	System.out.print("Rollno:");
	putNumber();
	System.out.println("Marks obtained in");
	displayMarks();
	System.out.print("SportsWeight:");
	displayWeightage();
	totalWeightage=sportsWeightage+marks[0]+marks[1];
	System.out.println("total score:"+totalWeightage);	
}
public static void main(String[]args) {
	Result R[]=new Result[5];
	int i=0;
	Scanner in =new Scanner(System.in);
	for(;;) {
		int choice;
		System.out.println("enter choice\n1.create score card of student \n2.display score card of a particular student");
		choice =in.nextInt();
		switch(choice) {
		case 1:
			System.out.println("enter the details");
			R[i]=new Result();
			R[i].getNumber();
			R[i].readmarks();
			R[i++].readWeightage();
			break;
		case 2:
			 System.out.println("enter the sutdent roll no to diplay the score card");
			 int roll=in.nextInt();
			 System.out.println("your Scorecard is ");
			 for(int j=0;j<i;j++) {
				 if(R[j].rollno==roll) {
					 R[j].Scorecard();
					 break;
				 }
			 }
			 break;
	     default:
	    	 System.exit(0);
			
		}
	}
}
}
