import static java.lang.System.out;
/*
 * static imports are loaded during class loading itself,
 * and mainly these removes need of putting classname while
 * using the import, but has diffirent name resolution order
 * 
 * Named Imports resolution:
 * 1) current class hierarchy
 * 2) current package level
 * 3) current source file imports
 * 
 * Static imports resolution:
 * 1) current class hierarchy
 * 2) explicit imports
 * 3) implicit imports
 * hence no package level checking
 * 
 * and same thing of ambigous references
 * 
 * By default java.lang and current package classes need not be imported
 * they are available in every source file
 * 
 * Imports are fully compile time concept and have no
 * runtime implications, everything is catched compile time itself
 * 
 * JVM does dynamic class loading, i.e. class is loaded into memory
 * only when it is instantiated somewhere, unlike C++ wherein 
 * everything get loaded in memory due to #include which simply
 * copy paste the code from class to the main file.
 */
class Staticimport {
    public static void main(String[] args) {
        out.println("Test 3");
    }
}
