/*
 * HAS-A relationship
 * 
 * - When component objects can exist without the container
 *   object, thus they are having lifecycle independent from 
 *   container object, such is called weak association or
 *   aggregation
 * 
 * - When component objects need container object to exist for
 *   thier existence wherein container object manages the 
 *   lifecycle of component objects such is called strong
 *   association or composition.
 * 
 * - Main advantage is real world modelling and code reusability
 * 
 * Method signature only means method name and the order and data types of the formal parameters
 * Compiler uses Method signature to resolve method calls and has method table for each class
 * storing them. It unique characteristic of each method. It is reason that only the PSVM(String[])
 * can be entry point of program.
 */
class AggregationComponent{
    static AggregationComponent create(){
        System.out.println("Aggregation component manages its own lifecycle");
        return new AggregationComponent();
    }
}
class AggregationContainer{
    public static void main(String[] args) {
        AggregationComponent  aggregationComponents[]=new AggregationComponent[5];
        for(AggregationComponent ref:aggregationComponents)
            ref=AggregationComponent.create();
    }
}
class CompositionContainer{
    class CompositionComponent{

    }
    public static void main(String[] args) {
        System.out.println("mostly composition is for inner classes, and the lifecycle is managed by outer classes");
        CompositionComponent[] components=new CompositionComponent[5];
    }
}

