package sixthprogram;
import java.util.Scanner;

public class Temperature {
public static void main(String args[]) {
	CitiesTemperature []cities = new CitiesTemperature[5];
	Scanner in = new Scanner(System.in);
	for(int i=0;i<5;i++) {
		cities[i]=new CitiesTemperature();
		System.out.println("enter the name of"+(i+1)+"st city");
		cities[i].cityname =in.next();
		
		System.out.println("enter the temperatures of 6 days of city "+(i+1));
		for(int j=0;j<6;j++) {
			cities[i].temperature[j]=in.nextFloat();
			
		}
		
		
	}
	
	float high=cities[0].temperature[0],low=cities[0].temperature[0];
	int hd=0,hc=0,ld=0,lc=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++) {
			if( low >cities[i].temperature[j]) {
				low=cities[i].temperature[j];
				ld=j;
				lc=i;
			}
			if( high<cities[i].temperature[j]) {
				high=cities[i].temperature[j];
				hd=j;
				hc=i;
			}
		}
		
	}
	System.out.println("the city"+cities[hc].cityname+"has the highest tempeature at day"+(hd+1)+"which is"+high);
	System.out.println("the city"+cities[lc].cityname+"has the lowest tempeature at day"+(ld+1)+"which is"+low);
	in.close();
}

}
