package ninthprogram;import java.util.*;
class Cube{
	float side;
	Cube(float side){
		this.side=side;
		
	}
	void volume() {
		System.out.println("the volume of cube with side"+side+"is"+(side*side*side));
	}
	void surfacearea() {
		System.out.println("the surface area of cube with side"+side+"is"+(6.0*side*side));
	}
}
public class CubeCreater {
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
		int i;
		Cube cube[]=new Cube[3];
		for( i=0;i<3;i++) {
			System.out.println("enter the side of cube "+(i+1));
			cube[i]= new Cube(in.nextInt());
		}
		for(i=0;i<3;i++) {
			System.out.println("cube"+(i+1));
			cube[i].volume();
			cube[i].surfacearea();
		}
	}

}
