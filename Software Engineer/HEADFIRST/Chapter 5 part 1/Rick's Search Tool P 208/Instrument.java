public abstract class Instrument {
    private String serialNumber;
    private double price;
    private InstrumentSpec spec;

    //Constructor 
    public Instrument(String serialNumber,double price, InstrumentSpec spec){
        this.serialNumber=serialNumber;
        this.price=price;
        this.spec=spec;

    }
    //Set and Get Methods
        //Setter
            public void setSerialNumber(String serialNumber){
                this.serialNumber=serialNumber;
            }
            public void setPrice(double price){
                this.price=price;
            }
            public void setSpec(InstrumentSpec spec){
                this.spec=spec;
            }
        //getters
            
            public String getSerialNumber(){
                return serialNumber;
            }
            
            public double getPrice(){
                return price;
            }

            public InstrumentSpec getSpec(){
                return spec;
            }
}