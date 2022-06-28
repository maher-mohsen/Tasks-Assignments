import java.util.Vector;
import java.util.Scanner;

public  class Garage {
	private static Garage garage;
	private int noOfSlots = 0;
	private Vector<Slot> slots = new Vector<Slot>();
	
	// Private Constructor to follow Singleton Pattern
	private Garage(){
	
	}
	//Lazy Intaitilization
	public static Garage addInstanceGarage(){
		if(garage==null) garage = new Garage();
		
		return garage;
	}

	
	//Set Garage data (number of slots).
	public void setGarageData(Vector<Slot> slots , int noOfSlots){
		this.noOfSlots = noOfSlots;
		this.slots = slots;
	}

	// return all slots
	public Vector<Slot> getSlots(){
		return slots;
	}
	
}
