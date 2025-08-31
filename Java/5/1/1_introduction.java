/*
 * Data hiding : outside person cannot directly access internal data. It needs some authentiaction/validation.
 * Acheived by declaring variables as private and providing getters(accessors) setters(mutators) 
 * Main advantage is security
 * 
 * Abstraction : hiding internal implementation and just exposing set of services.Act of hiding internal details
 * and providing only essential access points of internal system
 * Acheived by interfaces and abstract classes
 * Main advantage security,ease of usage of clients,enhancement becomes easy,high maintainability
 * 
 * Encapsulation : The process of binding data and corresponding methods(behavior) into single unit is encapsulation
 * Encapsulation = Data hiding + Abstraction
 * Everything of Abstraction and Data hiding + slow execution time + more lines of code
 * Tightly encapsulated class has every variable private and access using getter setters only
 */
class vector3d{
    private int x=0;
    public int getX() {
        return x;
    }
    public void setX(int x) {
        this.x = x;
    }
    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
    public int getZ() {
        return z;
    }
    public void setZ(int z) {
        this.z = z;
    }
    private int y=0;
    private int z=0;   
}