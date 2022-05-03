public enum Wood{
    INDIAN_ROSEWOOD,BRAZILIAN_ROSEWOOD,MAHOGANY,MAPLE,COCOBOLO,CEDAR,ADIRONDACK,ALDER,SITKA;
    public String toString(){
        switch(this){
            case INDIAN_ROSEWOOD:
                return "Indian Rosewood";

            case BRAZILIAN_ROSEWOOD:
                return "Brazilian Rosewood";

            case MAHOGANY:
                return "Mahogny";

            case MAPLE:
                return "Maple";

            case COCOBOLO:
                return "CocoBolo";

            case CEDAR:
                return "Cedar";

            case ADIRONDACK:
                return "Adriondack";

            case ALDER:
                return "Alder";

            case SITKA:
                return "Sitka";
        }
        return null;
    }
}