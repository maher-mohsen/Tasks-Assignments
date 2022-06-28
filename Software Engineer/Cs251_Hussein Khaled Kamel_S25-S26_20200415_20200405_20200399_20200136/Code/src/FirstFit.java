import java.util.Vector;

public class FirstFit implements SearchControl {

	 // Seach for an available slot which is the fist one fits the vehicle.
    public int callConfig(GarageControl garageControl, Vehicle currentVehicle){
        Vector<Slot> avSlots = garageControl.getAVslots();
        for(int i = 0; i < avSlots.size(); i ++){
            if(avSlots.get(i).getWidth() >= currentVehicle.getWidth() && avSlots.get(i).getDepth() >= currentVehicle.getDepth()){
                return avSlots.get(i).getSlotID() - 1;
            }
        }
        return -1;
    }

}
