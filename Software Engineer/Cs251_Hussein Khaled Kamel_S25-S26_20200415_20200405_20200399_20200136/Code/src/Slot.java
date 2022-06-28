
public class Slot {
	private double width, depth;
	private int slotID;
	private Vehicle vehicle = null ;
	private static int totalSlots=0;

	// Default Constructor
	Slot(){
		depth = 0;
		width = 0;
		slotID = ++totalSlots;
	}
	Slot(double width, double depth){
		this.depth = depth;
		this.width = width;
		slotID = ++totalSlots;
	}

	// returns width of slot.
	public double getWidth(){
		return width;
	}

	// returns depth of slot.
	public double getDepth(){
		return depth;
	}

	// returns an ID of slot.
	public int getSlotID(){
		return slotID;
	}

	// returns a vehicle.
	public Vehicle getVehicle(){
		return vehicle;
	}

	// Set width and depth of a slot.
	public void setSlotData(double width, double depth){
		depth=depth;
		width=width;
	}

	// Set a vehicle in a slot.
	public void setVehicleData(Vehicle vehicle){
		this.vehicle=vehicle;
	}
	public void freeSlot(){
		this.vehicle = null;
	}
	
}
