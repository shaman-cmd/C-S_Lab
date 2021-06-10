package seventhprogram;
import java.util.Scanner;
 class ballot {
int vote;
ballot(int vote){
	this.vote=vote;
}

}
public class ballotcounter {
public static void main(String args[]) {
	ballot[] BallotBox = new ballot[50];
	
	int noOfVotes=0;
	int i=0;
	
	Scanner in = new Scanner(System.in);
	for(;;) {
		
			if(noOfVotes>50) {
			System.out.println("ballotbox is full");
			break;
			                 }
			System.out.println("which contestant do u want to vote press the rescpective choice \n1.contestant A\n2.contestant B\n3.contestant C\n4.contestant D\n5.contestant E\n6.NOTA\n"
					+ "7.to stop counting");
			int choice=in.nextInt();
			if(choice==7) {
				break;
			}
			BallotBox[i++]=new ballot(choice);
			noOfVotes++;
			
			}
	in.close();
	int v[]= new int[5];
	int spoilt=0,NOTA=0;
	for(i=0;i<noOfVotes;i++) {
		
		int vote=BallotBox[i].vote;
		switch(vote) {
		case 1:
			v[0]++;
			break;
		case 2:
			v[1]++;
			break;
		case 3:
			v[2]++;
			break;
		case 4:
			v[3]++;
			break;
		case 5:
			v[4]++;
			break;
		case 6:
			NOTA=NOTA+1;
			break;
			
		default:
			spoilt=spoilt+1;
			break;
			
	
		}
	}
	System.out.println("in this election "+noOfVotes+"people had voted their candidate");
	int high=v[0],highc=1;
	for(i=0;i<5;i++) {
		System.out.println("the no of votes for candidate "+(i+1)+"st is"+v[i]+"votes");
		if(v[i]>high) {
			high =v[i];
			highc=(i+1);
		}
	}
	System.out.println("the winner of the election is "+highc+"st candidate with"+high+"votes");
	System.out.println("no of spoilt ballots are"+spoilt);
	
	in.close();
	}
}

