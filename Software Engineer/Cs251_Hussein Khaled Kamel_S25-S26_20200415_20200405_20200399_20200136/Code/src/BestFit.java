import java.util.Vector;

public class BestFit implements SearchControl {

    // Seach for an available slot which is the lowest width and depth can hold a vehicle.
    public int callConfig(GarageControl garageControl, Vehicle currentVehicle){
        Vector<Slot> avSlots = garageControl.getAVslots();
        double curWidth = 1000, curDepth = 1000;
        int id = -1;
        for(int i = 0; i < avSlots.size(); i ++){
            if(avSlots.get(i).getWidth() >= currentVehicle.getWidth() && avSlots.get(i).getDepth() >= currentVehicle.getDepth()){
                if(avSlots.get(i).getWidth() < curWidth){
                    curWidth = avSlots.get(i).getWidth();
                    curDepth = avSlots.get(i).getDepth();
                    id = avSlots.get(i).getSlotID();
                }
                else if(avSlots.get(i).getWidth() == curWidth && avSlots.get(i).getDepth() < curDepth){
                    curDepth = avSlots.get(i).getDepth();
                    id = avSlots.get(i).getSlotID();
                }

            }
        }
        if(id == -1){
            return -1;
        }
        else{
            return id - 1;
        }
    }
}
