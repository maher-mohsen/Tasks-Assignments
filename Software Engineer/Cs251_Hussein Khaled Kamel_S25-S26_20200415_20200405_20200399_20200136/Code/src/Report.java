
public  class Report {

	private static Report report = new Report();
	//Private Constructor to follow Singleton Pattern 
	private Report(){
		totalIncome =0;
		totalNoOfVehicles=0;
	}
	//Lazy Intaitilization
	public static Report addInstanceReport(){
		return report;
	}
	private  static double totalIncome = 0;
	private static int totalNoOfVehicles = 0;
	// retuns a total income.
	public double getTotalIncome(){
		return totalIncome;
	}

	// returns a number of vehicles which are parked in the Garage.
	public int getTotalVehiclesParked(){
		return totalNoOfVehicles;
	}

	// Add a paking out fees on the total income.
	public static void addIncome(double parkoutFees){
		totalIncome +=  parkoutFees;
	}

	// increase number of vehicles.
	public static void increaseVehicle(){
		totalNoOfVehicles++;
	}
}
