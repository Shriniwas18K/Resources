/*
 * all of these cannot be used with abstract as these are implementation based
 *  synchronized means only one thread can access that method or block
 * native allows to call the methods from C/C++ DLLs
 * transient makes default values to be printed for the variables during serialisation
 */
class Test5 {
    static{
        //System.loadLibrary("DLL");
    }
    public static transient int temp=18;
    public static void main(String[] args) {
        System.out.println(temp);
    }
    public static native int hashCodeNative();
}
