package tenthprogram;
import java.util.*;
public class StudentExamResult {
int rollno;
int marks[]=new int[3];
int totalmarks;

void readmarks() {
	Scanner in = new Scanner(System.in);
	System.out.println("enter the rollno of student\n");
	rollno=in.nextInt();

	for(int i=0;i<3;i++) {
		System.out.println("enter the marks of subject\n"+(i+1));
		marks[i]=in.nextInt();
		totalmarks=totalmarks+marks[i];
	}
	}
void display() {
	System.out.println(rollno+"\t"+marks[0]+"\t\t"+marks[1]+"\t\t"+marks[2]+"\t\t"+totalmarks);
}

public static void main(String[]args) {
	StudentExamResult student[]=new StudentExamResult[20];
	int choice,i,j;
	for(;;) {
		System.out.println("enter choice\n1.read all students marks\n2.display highest marks in each suject and roll no of the student who scored\n3.display topper of the exam\n4.exit");
		Scanner in = new Scanner(System.in);
		choice = in.nextInt();
		switch(choice) {
		case 1:
			for(i=0;i<20;i++) {
				System.out.println("enter the details of student"+(i+1));
				student[i]=new StudentExamResult();
				student[i].readmarks();
			}
			System.out.println("displaying students information");
			System.out.println("rollno\tsubject1\tsubject2\tsubject3\ttotalmarks");
			for(i=0;i<20;i++) {
				student[i].display();		
			}
			break;
		case 2:
			int high,highroll;
			for(i=0;i<3;i++) {
				high =student[0].marks[i];
				highroll=student[0].rollno;
				for(j=0;j<20;j++) {
					if(student[j].marks[i]>high) {
						high=student[j].marks[i];
						highroll=student[j].rollno;
					}		
				}
				System.out.println("the highest subject"+(i+1)+"marks is"+high+"and it is scored by student with rollno"+highroll);	
			 }
		     break;
		case 3:
			System.out.println("the topper of the exam  is");
			int hightotal=student[0].totalmarks,highrollno=student[0].rollno;
			for(i=0;i<20;i++) {
				
				if(student[i].totalmarks>hightotal) {
					hightotal=student[i].totalmarks;
					highrollno=student[i].rollno;
				}
			}
			System.out.print("student with roll no"+highrollno+"with total marks of"+hightotal);
			break;
		default :
			System.exit(0);
		}
	
	}
}

}