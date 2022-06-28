import java.util.Scanner;
import java.util.Vector;

public class TouchScreen {
	
	private TouchScreenControl touchScreenControl = new TouchScreenControl();
	// Default Constructor
	public TouchScreen(){
		System.out.println("Welcome to System Parking Garage\n");
		touchScreenControl.showSetConfigForm();
		setConfigButton();
		setSlotButton();
		powerOn();
	}
    
	// start the system
	public void powerOn(){
		Scanner Input = new Scanner(System.in);
		while(true){
			touchScreenControl.showMenuList();
			int type;
			do{
				type = Input.nextInt();
				if(type < 1 || type > 5){
					System.out.println("Please enter valid type from 1 to 4");
				}
				else{
					break;
				}
			}while(true);
			if(type == 1){
				parkInButton();
			}
			else if(type == 2){
				parkoutButton();
			}
			else if(type == 3){
				reportButton();
			}
			else if(type == 4){
				
				displayAvSlots();
			}
			else{
				break;
			}
		}
	}
       // set config button
	public void setConfigButton(){
		Scanner Input = new Scanner(System.in);
		int type = Input.nextInt();
		// Validate on type of configuration.
		while(type != 1 && type != 2){
			System.out.println("Please enter valid configuration type (1 or 2)");
			 type = Input.nextInt();
		}
		touchScreenControl.setConfig(type);
	}
     
	// set slot button 
	public void setSlotButton(){
		Scanner Input = new Scanner(System.in);
		touchScreenControl.showSlotForm(0, -1);
		int numberofSlots = Input.nextInt();
		Vector<Slot> slots = new Vector<Slot>();
		for(int i = 0; i < numberofSlots;i++){
			touchScreenControl.showSlotForm(1, i + 1);
			Double width = Input.nextDouble();
			Double depth = Input.nextDouble();
			slots.add(new Slot(width, depth));
		}
		touchScreenControl.setSlots(slots);
	}


	// Add an vehicle to an available slot based on configuration type.
	public void parkInButton(){
		touchScreenControl.showVehicleForm();
		int successfullyParkedIn = 0;
		do{
			successfullyParkedIn = touchScreenControl.parkIn();
			if(successfullyParkedIn == 0){
				showIdError();

			}
		}while(successfullyParkedIn == 0);
		
		if(successfullyParkedIn == -1){
			showNoSlotMessage();
			
		}
		else{
			System.out.println("Successfully Parked In "+"Slot :"+successfullyParkedIn);
		}
	}
     // park out button 
	public void parkoutButton(){
		Scanner Input = new Scanner(System.in);
		int successfullyParkedOut = 0;
		do{
			successfullyParkedOut = touchScreenControl.parkOut();
			if(successfullyParkedOut == 0){
				showIdError();
				showContinueMessage();
				if(Input.next().toUpperCase().equals("NO")){
					break;
				}
			}
		}while(successfullyParkedOut == 0);
		
		if(successfullyParkedOut == -1){
			System.out.println("Parking user chose to continue parking");
		}
		else{
			System.out.println("Thanks for using our Parking Garage");
		}
	}
      // show report form
	public void reportButton(){
		touchScreenControl.showReport();
	}
	

	// Exepction of no available slots or no matching of a width or depth of a vehicle.
	public void showNoSlotMessage(){
		System.out.println("No space available in the Garage!!");
	}

	// continue message 
	public void showContinueMessage(){
		System.out.println("Do you want to continue: (YES or NO)");
	}

	

	// Exception of invalid ID of a vehicle.
	public void showIdError(){
		System.out.println("Please Enter Valid Vehicle ID: ");
	}

	public void displayAvSlots(){
		touchScreenControl.showSlotList();

	}

		
}
