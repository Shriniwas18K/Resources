

// NOTE : writing console.log( ) is reducing readability , we can do it wherever we feel in the code

// {} is also denoted as Object.prototype , also sometimes engine prints them as undefined when accessed with console.log(obj.prototype)


// Here documentation wants to denote Object.prototype as Object.__proto__ which is again due to improper
// nomeancalture in js and mdn docs.

// Sometimes js engine implicitely sets the [[Prototype]] for some literals
// Object literals (without the `__proto__` key) automatically
// have `Object.prototype` as their `[[Prototype]]`
const object = { a: 1 };
Object.getPrototypeOf(object) === Object.prototype; // true

// Array literals automatically have `Array.prototype` as their `[[Prototype]]`
const a = [1, 2, 3];
Object.getPrototypeOf(a) === Array.prototype; // true
// all methods of arrays are not defined on their variable objects but on
// the Array object which is `[[Prototype]]` for every array


// RegExp literals automatically have `RegExp.prototype` as their `[[Prototype]]`
const regexp = /abc/;
Object.getPrototypeOf(regexp) === RegExp.prototype; // true

// We can "de-sugar" them into their constructor form.
const array1 = new Array(1, 2, 3);
const regexp1 = new RegExp("abc");
const n=new Number(10);
const obj=new Object();
// now as `[[Prototypes]]` are chained until null then for above we have chain as
// array1---->Array----->[]----->null
// regexp1--->RegExp---->/(?:)/.------>null
// n----->Number----->0----->null
// obj----->Object----->{}----->null


// However for user defined functions/objects case is diffirent,manual setting of `[[Prototype]]` is required

// For user defined functions `[[Prototype]]` of them is default directly {}
function userDefined(){}
Object.getPrototypeOf(userDefined);// {}
// {} means empty object 

// thus for below we have chain as 
const obj1 = new userDefined();
// obj1 ----->{}----->null
Object.setPrototypeOf(obj1,userDefined);
// obj1 ----->userDefined----->{}----->null
Object.getPrototypeOf(obj1);//Function : userDefined



// here userDefined can also be constructor functions 
// and this can be used to create inheritance chains between objects of them
function Base(){}
function Derived(){}
Object.setPrototypeOf(Derived.prototype,Base.prototype);
const baseObj=new Base();
const derivedObj=new Derived();
//derivedObj---->Base---->{}----->null
Object.getPrototypeOf(derivedObj);//Base

// Note : do not do Object.setPrototypeOf(derivedObj,Base) or (derivedObj.prototype,Base)
//        as here that only specific object derivedObj will be in relation with Base
// instead to set all objects of Derived(), we need those set constructor functions as parent child relationship
// so then thier objects will be in parent child relationship
// so do Object.setPrototypeOf(Derived.prototype,Base.prototype);

// In modern js terminology it is equivalent of saying
class Basec{
    constructor(){}
}
class Derivedc extends Basec{
    
}

const derobj = new Derivedc();
// derobj ---> Basec ---> null
Object.getPrototypeOf(derobj);//Basec   or Basec(){}   both are same

// Now as functions are first class objects so we can define properties on them in js
function func(){
    console.log('i am first class object');
}
func.description="This is intended for understanding puropses"
console.log(func)
// NOTE : it is user defined function so its `[[Prototype]]` by default is {}

// SPECIAL CASE of ARROW FUNCTIONS
// all functions and objects inherit many properties and values from Object ( built in object of js)
// which is an empty object with properties and values(as functions also,i.e. methods)
// like .hasOwnProperty(), .prototype , etc
// but arrow functions dont have such case at all they dont inherit such things
// so they are fast , nor they have any unneccessary properties and methods
// so in sense they dont have prototype object chain with them , so it is advisable to use them

// In js , if code tries to access property of object that is not present in it
// then engine searches for that property in its parent object ,so on till object if final parent (null)
// if not found then error is thrown , else latest occurence of property is accessed and value is given
// or executed(for functions)

// This whole process thence does not occur for arrow functions , as they dont have any parent prototype chains
// as well as if any property not present in them is accessed then error is thrown 
let arr=()=>console.log('i am arrow')
// arr.prototype.foo="bar"
// above will throw error , as thier `[[Prototype]]` is null or i.e. they dont have property prototype which
// stores value as parent object , so we cannot have set any properties on them
// hence they are best to use , if we want performance gains 
// let temp= new arr();
// similarly above line will throw error as they dont have properties so we cant use themas constructors
