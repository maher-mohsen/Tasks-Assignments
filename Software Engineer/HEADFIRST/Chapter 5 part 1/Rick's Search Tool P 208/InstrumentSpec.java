import java.lang.module.ModuleDescriptor.Builder;

public abstract class InstrumentSpec {
    private Builder builder;
    private String model;
    private Type type;
    private Wood backWood;
    private Wood topWood;

    //Constructors
    public InstrumentSpec (Builder builder,String model,Type type,Wood backWood,Wood topWood){
        this.builder=builder;
        this.model=model;
        this.type=type;
        this.backWood=backWood;
        this.topWood=topWood;
    }
    //Setters and Getters
        //Setters
            public void setBuilder(Builder builder){
                this.builder=builder;
            }
            public void setModel(String model){
                this.model=model;
            }
            public void setType(Type type){
                this.type=type;
            }
            public void setBackwood(Wood backWood){
                this.backWood=backWood;
            }
            public void setTopwood(Wood topWood){
                this.topWood=topWood;
            }
        //Getters
            public Builder getBuilder(){
                return builder;
            }
            public String getModel(){
                return model;
            }
            public Type getType(){
                return type;
            }
            public Wood getBackwood(){
                return backWood;
            }
            public Wood getTopwood(){
                return topWood;
            }

    //Methods
        public boolean matches(InstrumentSpec otherSpec){
            if(builder!=otherSpec.builder)
                return false;
            if((model!=null)&&(!model.equals(" "))&&(!model.equals(otherSpec.model)))
                return false;
            if(type!=otherSpec.type)
                return false;
            if(backWood != otherSpec.backWood)
                return false;
            if(topWood!=otherSpec.topWood)
                return false;
            return true;
        }
}
