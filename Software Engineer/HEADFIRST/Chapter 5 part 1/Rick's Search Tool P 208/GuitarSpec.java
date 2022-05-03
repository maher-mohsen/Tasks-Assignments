public class GuitarSpec extends InstrumentSpec{
    private int numStrings;
    //Constructors
    public GuitarSpec(java.lang.module.ModuleDescriptor.Builder builder,String model ,Type type, int numStrings,Wood backWood,Wood topWood){
        super(builder, model, type, backWood, topWood);
        this.numStrings=numStrings;
    }
    //Set
    public void setNumberStrings(int numStrings){
        this.numStrings=numStrings;
    }
    //Get 
    public int getNumberStrings(){
        return numStrings;
    }
    //Override matches()
    public boolean matches(InstrumentSpec otherSpec){
        if(!super.matches(otherSpec))
            return false;
        if(!(otherSpec instanceof GuitarSpec))
            return false;
        GuitarSpec spec=(GuitarSpec)otherSpec;
        if(numStrings!=spec.numStrings)
            return false;
        return true;
    }
}
