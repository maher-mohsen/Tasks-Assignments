
import java.sql.Time;
import java.sql.Timestamp;
import java.time.Instant;
public class Vehicle {
	
	private String vID;
	private int slotID;
	private String vModelYear, vModelName;
	private double width, depth;
	private boolean payment;
	private Timestamp arrival;

	// Default Constructor.
	Vehicle(){
		this.depth=0;
		this.width=0;
		this.payment=false;
	}

	// Parameterized Constructor.
	Vehicle(String vID, int slotID, String vModelYEAR,String vModelNAME, double width, double depth, boolean payment){
		this.depth =depth;
		this.width = width;
		this.vID = vID;
		this.slotID = slotID;
		this.vModelName =vModelNAME;
		this.vModelYear = vModelYEAR;
		this.payment = payment;
	}

	// Parameterized Constructor.
	Vehicle(String vID, String vModelYEAR,String vModelNAME, double width, double depth, boolean payment){
		this.depth =depth;
		this.width = width;
		this.vID = vID;
		this.vModelName =vModelNAME;
		this.vModelYear = vModelYEAR;
		this.payment = payment;
	}

	// Setter of a vehicle data.
	public void setVehicleData(String vID, int slotID, String vModelYEAR,String vModelNAME, double width, double depth, boolean payment){
		this.depth =depth;
		this.width = width;
		this.vID = vID;
		this.slotID = slotID;
		this.vModelName =vModelNAME;
		this.vModelYear = vModelYEAR;
		
	}
	public void setArrival(Timestamp arrival){
			this.arrival=arrival;
	}
	public void setPayment(boolean pay){
		this.payment=pay;
}
	// returns a vehicle's ID.
	public String getVId(){
		return this.vID;
	}

	// returns a vehicle's slot ID.
	public int getSlotId(){
		return this.slotID;
	}

	// returns a vehicle's Model Year.
	public String getVModelYEAR(){
		return this.vModelYear;
	}

	// returns a vehicle's Model Name;
	public String getVModelNAME(){
		return this.vModelName;
	}

	// returns a vehicle's width.
	public double getWidth(){
		return this.width;
	}

	// returns a vehicle's depth.
	public double getDepth(){
		return this.depth;
	}
	// returns a true or false to know if a vehicle has been paid the fees and park out.

	public boolean getPayment(){
		return this.payment;
	}
	// returns arrival time.
	public Timestamp getArrival(){
		return this.arrival;
	}
	
}
