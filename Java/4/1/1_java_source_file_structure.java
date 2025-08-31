/*
Java source file structure. Any .java file ie source file.

A java program can contain any number of classes but atmost one class can be declared as
public. And if there is public class then the name of source file should be the name of
the public class otherwise C.E.

Case 1: If there is no public class then we can use any name on source file
Case 2: If there is public class then name of source should be className
Case 3: Atmost one class can be declared as public in one source file

Conclusions:
1) whenever we compile a java program for every class present in source then for every
   class present in it, a seprate corresponding .class file is generated
2) we can compile a .java source file but we can execute a .class file
3) whenever we are executing a java class .class file then the corresponding class should
   contain main method else R.E. NoSuchMethodError:main and if the corresponding .class
   file isnt available then R.E. NoClassDefFoundError
4) It is recommended to declare only one class per source file to improve readability and
   maintainiblity.

Empty source file is also valid source file like this current source file doesnt contain any class or interface.
*/

