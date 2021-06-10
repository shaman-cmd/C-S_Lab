package thirteenthprogram;
import java.util.*;

class Shapes{
	
	void area(float l,float b ) {
		if(l!=b)
		System.out.println("the area of rectangle is"+l*b);
		else
			System.out.println("the area of square is"+l*b);
	}
void area(float a,float b,float c ) {
	float s=(float) ((a+b+c)/2.0);
	System.out.println("the area of triangle is"+Math.sqrt(s*(s-a)*(s-b)*(s-c)));
	}
void area (float r) {
	System.out.println("the area of circle is"+3.14*Math.pow(r, 2));
}
void volume(float l,float b,float h) {
	if(l==b&b==h&h==l)
	System.out.println("the volume of cube is"+l*b*h);
	else
    System.out.println("the volume of cuboid is"+l*b*h);
}
void volume(float h,float r) {
	System.out.println("the volume of cylinder is"+3.14*r*r*h);
}
}
public class ShapesMaker {
	public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
     Shapes shape = new Shapes();
     for(;;) {
    	 
     
     System.out.println("enter the shape needed to create\n1.rectangle\n2.square\n3.circle\n4.triangle or 3d shapes such as \n5.cuboid\n6.cube\n7.cylinder");
     switch(in.nextInt()) {
     case 1:System.out.println("enter the length and breath of rectangle");
            shape.area(in.nextFloat(),in.nextFloat());
            break;
     case 2:System.out.println("enter the side of square");
            float  a=in.nextFloat();
             shape.area(a,a);
             break;
     case 3:System.out.println("enter the radius of circle");
            shape.area(in.nextFloat());
            break;
     case 4:System.out.println("enter the all 3 sides of triangle");
            shape.area(in.nextFloat(),in.nextFloat(),in.nextFloat());
            break;
     case 5:System.out.println("enter the length,breath and height of cuboid");
             shape.volume(in.nextFloat(),in.nextFloat(),in.nextFloat());
             break;
     case 6:System.out.println("enter the side of cube");
             a =in.nextFloat();
            shape.volume(a,a,a);
            break;
     case 7:System.out.println("enter the height and radius of cylinder");
            shape.volume(in.nextInt(),in.nextInt());
            break;
     }
     
 	} 
	}
}