/*
to use classes/interface from anywhere we need to write fully qualified name (FQN) , this reduces code readability and increases redundancy, thus imports were introduced. 

imports allow us to directly use classNames in our source file.

import statements are of two types : explicit/implicit

imports and FQNs can be used simultaneously.

explicit imports are directly from root java package to class used.

implicit imports use * operator meaning all.

implicit imports are not recommended to use because:
1) they import everything at package level but nothing from its subpackages.
2) in case where same name class/interface exists in multiple packages with diffirent implementation in each then it C.E. (compiler error: reference to ____ is ambigous) ,  in such case we need to use FQN.
*/
import java.util.HashMap; // explicit import
import java.util.*;// implicit import
import java.sql.Date;

@SuppressWarnings("unused")
class FQNImport{
   public static void main(String[] args){
       java.util.ArrayList arr = new java.util.ArrayList(); //FQN
       HashMap<Integer,Integer> map=new HashMap<>();// use className

//       ArrayBlockingQueue arr=new ArrayBlockingQueue(10); // part of util.concurrent , subpackage stuff cannot be used due to implicit imports, we need FQN here
//       Date d=new Date(); reference is ambigous, we need FQN here, Date class is in both sql,util package
   }
}
