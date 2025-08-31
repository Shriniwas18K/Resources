/*
 * Object can be created in many ways.
 * 1) new operator
 * 2) newInstance() method
 * 3) clone() method
 * 4) deserialisation
 */
class PQR implements Cloneable{
    PQR(){
        System.out.println("PQR Constructor");
    }
    @Override public PQR clone(){
        return new PQR();
    }
}
class Test4 {
    public static void main(String[] args) throws Exception{
        PQR ref = new PQR();
        ref = (PQR)Class.forName("PQR").newInstance();
        ref = ref.clone();
    }    
}