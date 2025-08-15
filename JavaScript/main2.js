let parent={
    getchildfoo(){
        console.log('methods common to all child objects')
        return this.foo
    },
}
// generally parent object contains methods and properties common to all child objects
let child1={
    foo:"child 1 foobar",__proto__:parent
}
let child2={foo:"child 2",__proto__:parent}
console.log(child1.getchildfoo());
console.log(child2.getchildfoo());
// but we needed to manually bind above parent to child objects
// instead of manually binding child objects with parent using __proto__

// to reduce the manual parent object creation we use constructor functions
// and .prototype syntax given below
function childConstructor(bar){
    this.foo=bar;
}
childConstructor.prototype.getchildfoo=function(){
    console.log('no need of parent object manual creation')
    return this.foo
}
// NOTE : here obj.prototype.key=val is just syntax to set key:val pair in prototype object 
//        it should not be confused as property of any function or object 
//        __proto__ can be also used for same purpose like
//        obj.__proto__.key=val
//        but __proto__ is actual property in obj which stores parent object by internal linking
//        we can console.log(obj.__proto__) to see parent object ( also named as `[[Prototype]]` 
//        of its child object)
//        but we cannot do console.log(obj.prototype) because prototype is not property in obj
//        Such confusion is caused due to improper nomeanclature and syntax

let childobj= new childConstructor('new syntax bar');
console.log('child object is created here');
console.log(childobj);
console.log(childobj.getchildfoo());

// here parent object as childobj's [[Prototype]] is initialzed but after child object creation
// in the way at top , parent object was needed to be made first

console.log(Object.getPrototypeOf(childobj));

// same constructor functions can be written inside classes
class childClass{
    constructor(bar){
        this.foo=bar;
    }
    getchildfoo(){
        console.log('no need of parent object manual creation')
        return this.foo
    }
}
let childobj1=new childClass("BAR");
console.log("childClass object created");
console.log(childobj1);
// Thus classes are just syntactic sugar on constructor functions to look like 
// traditional OOPs of other languages and look little familiar to developers
// Thus for any object created from these classes we can still use obj.prototype._______=____
// kind of syntax to define properties and values of its parent object without
// explicitely even creating parent object like above ways



