import java.sql.Timestamp;
import java.time.Instant;
import java.util.Scanner;

public class  VehicleControl {
	
	public Vehicle createVehicle(){
		return (new Vehicle());
	}
	// Showing a form to set the data of a vehicle.	
	
	// Validate on vehicle's ID.
		public boolean validateID (String vID){
			vID = vID.toUpperCase();
			int alphabetCheck=0,numberCheck=0;
			for(int i=0;i<vID.length();++i){
				if(vID.charAt(i)>='A' && vID.charAt(i)<='Z') alphabetCheck++;
				else if (vID.charAt(i)>='0' && vID.charAt(i)<='9') numberCheck++;
			}
			if((alphabetCheck==2 || alphabetCheck==3) && (numberCheck==3 || numberCheck==4)) return true;
			return false;
		}
	
	// Set the time which the vehicle has been parked in.
	public void markArrivalTime(Vehicle vehicle ){
		vehicle.setArrival(new Timestamp(System.currentTimeMillis()));
        
	}
    //mark payment
    public void pay(Vehicle vehicle){
        vehicle.setPayment(true);
    }
    
	// calculate fees
	public double calculateFees(Vehicle vehicle){
		Timestamp currentTime = new Timestamp(System.currentTimeMillis());
		return (((currentTime.getTime() - vehicle.getArrival().getTime()) + 3600000 - 1)/3600000) *5;
	}
}
