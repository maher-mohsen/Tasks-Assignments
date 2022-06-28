import java.util.Vector;
import java.util.Scanner;

public class GarageControl {
	// Attrubite
    private Garage garage =Garage.addInstanceGarage();
	private SearchControl searchControl;
    private VehicleControl vehicleControl = new VehicleControl();
	
    // Retruns a list of available slots.
	public Vector<Slot> getAVslots(){
		Vector<Slot> avSlots = new Vector<Slot>();
		for(int i=0;i<garage.getSlots().size();++i){
			if(garage.getSlots().get(i).getVehicle() == null) {
				avSlots.add(garage.getSlots().get(i));
			}
		}
		return avSlots;
	}
    // set a vehicle in a available slot and increase number of vehicles.
	public void reserveSlot(int slotNum, Vehicle vehicle){
		garage.getSlots().get(slotNum).setVehicleData(vehicle);
        Report.increaseVehicle();
	}
	 
	// park the vehicle
	public int parkIn(Vehicle vehicle){
		if(vehicleControl.validateID(vehicle.getVId())){
			int index = searchControl.callConfig(this, vehicle);
			if(index == -1){
				// No Available slots
				return -1;
			}
			reserveSlot(index, vehicle);
			vehicleControl.markArrivalTime(vehicle);
			return index+1;
			// successed 
		}
		else{
			return 0;
			// Wrong ID
		}
	}

     // search about vichle in garage 
	public int isFoundInGarage(String vID){
		Vector<Slot> slots = garage.getSlots();
		for(int i = 0; i < slots.size(); i ++){
			if(slots.get(i).getVehicle() != null && slots.get(i).getVehicle().getVId().equals(vID) ){
				return i;
			}
		}
		return -1;
	}

	// make slot free
	public void freeSlot(int index){
		garage.getSlots().get(index).freeSlot();
	}
    
	// vehicle leave the garage
	public int parkOut(String vID){
		int index = isFoundInGarage(vID);
		if(index != -1){
			Scanner scanner = new Scanner(System.in);
			Vehicle vehicle = garage.getSlots().get(index).getVehicle();
			System.out.println("You Have to pay: " + vehicleControl.calculateFees(vehicle));
			System.out.println("YES or NO");
			if(scanner.next().toUpperCase().equals("YES")){
				Report.addIncome(vehicleControl.calculateFees(vehicle));
				freeSlot(index);
				return 1;
				// successed 
			}
			else{
				return -1;
				// continue in parking
			}
			
		}
		else{
			return 0;
		}
	}
    
	// choose the config 
	public void setConfig(int type){
		if(type == 1){
			searchControl = new FirstFit();
		}
		else{
			searchControl = new BestFit();
		}
	}

	// set slots data
	public void setSlots(Vector<Slot> slots){
		garage.setGarageData(slots, slots.size());
	}


}
