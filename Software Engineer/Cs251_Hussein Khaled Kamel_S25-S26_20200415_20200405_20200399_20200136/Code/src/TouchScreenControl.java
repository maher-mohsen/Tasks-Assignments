import java.util.Scanner;
import java.util.Vector;

public class TouchScreenControl {
	private GarageControl garageControl = new GarageControl();

	// make vehicle park
	public int parkIn(){
		Scanner scanner = new Scanner(System.in);
		String vID = scanner.next();
		String modelYear = scanner.next();
		String modelName = scanner.next();
		double width = scanner.nextDouble();
		double depth = scanner.nextDouble();
		Vehicle vehicle = new Vehicle(vID,modelYear,modelName,width,depth,false);
		return garageControl.parkIn(vehicle);
		
	}
	// make vehicle leave
	public int parkOut(){
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please Enter Vehicles'ID: ");
		String vID = scanner.next();
		return garageControl.parkOut(vID);
	}

	 // form vehicle data
	public void showVehicleForm(){
		System.out.println("************************");
		System.out.println("Please Enter the following data...");
		System.out.println("Vehicle ID (String, ex:\"xxx-000\", \"xx-0000\", \"xxx-0000\") : .....");
		System.out.println("Vehicle Model Year : .....");
		System.out.println("Vehicle Model Name (ex: Renault-Logan) : .....");
		System.out.println("Vehicle Width (Double) : .....");
		System.out.println("Vehicle Depth (Double) : .....");
		System.out.println("************************");
	}
	
	// Showing a form to set the data of a slot.
	public void showSlotList() {
		Vector<Slot> slots = new Vector<Slot>();
		slots = garageControl.getAVslots();
		for(int i=0;i<slots.size();i++ ){
			System.out.println("************************");
			System.out.println("slot ID : "+ slots.get(i).getSlotID());
			System.out.println("slot width : " +slots.get(i).getWidth());
			System.out.println("slot depth : " +slots.get(i).getDepth());
		}
	}


	// show option 
	public void showMenuList() {
		System.out.println("************************");
		System.out.println("1- Park In");
		System.out.println("2- Park Out");
		System.out.println("3- Show Report");
		System.out.println("4- Display All Slots");
		System.out.println("5- Exit");
		System.out.println("************************");
	}
      
	// set slot data 
	public void showSlotForm(int ok, int i) {
		if(ok == 0){
			System.out.println("Enter Number of Slots: ");
		}
		else{
			System.out.print("Enter Slot ") ;
			System.out.print(i + " ");
			System.out.println("width and depth: " );
		}
	}


	// show option of config
	public void showSetConfigForm() {
		System.out.println("Enter search configuration type:");
		System.out.println("1- First Fit");
		System.out.println("2- Best Fit");
	}


	// set the config option
	public void setConfig(int type){
		garageControl.setConfig(type);
	}

	// set slots data 
	public void setSlots(Vector<Slot> slots){
		garageControl.setSlots(slots);
	}
	// show report
	public void showReport(){
		Report report = Report.addInstanceReport();
		System.out.println("************************");
		System.out.println("Total income for Garage is :" + report.getTotalIncome());
		System.out.println("Total Number of Vehicles is :" + report.getTotalVehiclesParked());
	}
	
}

