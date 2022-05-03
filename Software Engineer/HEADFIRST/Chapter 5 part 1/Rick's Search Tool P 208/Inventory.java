import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Inventory {
    private LinkedList<Instrument> inventory;
    public Inventory(){
        inventory = new LinkedList<Instrument>();
    }
    public void addInstrument(String serialNumber,double price,InstrumentSpec spec){
        Instrument instrument =null;
        if(spec instanceof GuitarSpec){
            instrument = new Guitar(serialNumber,price,(GuitarSpec)spec);
        }
        else if(spec instanceof MandolinSpec){
            instrument = new Mandolin(serialNumber,price,(MandolinSpec)spec);
        }
        inventory.add(instrument);
    }
public Instrument get(String serialNumber){
    for(Iterator<Instrument> i =inventory.iterator();i.hasNext();){
        Instrument instrument = (Instrument)i.next();
        if(instrument.getSerialNumber().equals(serialNumber)){
            return instrument;
        }
    }
    return null;
}
//Searching for guitars
public LinkedList<Instrument> search(GuitarSpec searchSpec){
    LinkedList<Instrument>  matchingGuitars = new LinkedList<>();
        for(Iterator<Instrument> i=inventory.iterator();i.hasNext();){
            Guitar guitar=(Guitar)i.next();
            if(guitar.getSpec().matches((searchSpec))){
                matchingGuitars.add(guitar);
            }
        }
        return matchingGuitars;
}
//Searching for mandolins
public LinkedList<Instrument> search(MandolinSpec searchSpec){
    LinkedList<Instrument>  matchingMandolins = new LinkedList<>();
    for(Iterator<Instrument> i=inventory.iterator();i.hasNext();){
        Mandolin mandolin=(Mandolin)i.next();
        if(mandolin.getSpec().matches((searchSpec))){
            matchingMandolins.add(mandolin);
        }
    }
    return matchingMandolins;
}
    
}
