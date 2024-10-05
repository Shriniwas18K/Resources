// js has three level architecture
// level 3 : classes , containers
// level 2 : functions,inheritance,polymorphism
// level 1 : objects
// level 0 : seven types,loops,conditionals

// level 0 :
let s="string literal"
let n=34324.34
let b=56666666663366
let bo=true
let un=undefined
let nu=null
// string , number , bigInt , boolean , undefined ,null

// level 1 : within 20+ years js evolved a lot and these literals
// i.e. variables used to store them needed frequently used functions
// so all literals got stored into thier respective objects 
// i.e. they got Object wrappers , which became so called 
// primitive data types of js

// null doesnt have such thing

// Number , String , Boolean , Undefined , BigInt 
// one more new wrapper called as Symbol was introduced 2 years ago

s=new String("ihiguyt");
// such kind of declarations are used
// nowadays the wrappers are implicitely added by js interpreter
// so we dont need to write them manually using new keyword



// OBJECTS 

// This is all because js is object-oriented language
// where everything is object or wrapped(stored) inside an object.
//  Here objects are not instances of classes , instead they 
// are just <property : value> pairs
// the concept of class does not exist in javascript like C++
// here directly objects are created , no template like class for them

// functions can be values in js , they can be stored in variables
//  as well as passed to functions as well
// functions define behaviour of object , as well as manipulkate their properties's values

let obj= { 
    'dataMemberOne':'val1',
    foo : function(){
        console.log(this.dataMemberOne);
    }
}

// within years :function was removed from syntax , i.e. shorthand introduced
// hence we directly see foo(){} kind of functions inside objects
// here foo is property and function with its args and body is its value

// we can dynamically add properties in objects
obj.anyProperty="dynamically added"

console.log(obj)

// whenever we console.log(func()) then its return value
// is always printed , if it does not return anything then undefined is returned
// and printed

// more expansion discussion on classes and functions later