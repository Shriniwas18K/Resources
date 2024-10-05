// INHERITANCE
// by default every object we create in js has its
// parent object called as its `[[Prototype]]` which can be
// seen using 
// console.log(Object.getPrototypeOf(childObject))



// In js concept of inheritance is completely diffirent and occurs everywhere silently

// here by default the child object gets all the properties and methods of parent object
// once we manually set parent object , or even of default parent object's too
// the methods and properties go inside child

// NOTE : The parent object of any object(say O) is called `[[Prototype]]` and 
// it is treated as value of the property .__proto__,which it has inherited from Object ( built in object of js)


// whenever any method uses   "this" keyword then it only refers to object that has called it
// not to anyone of its parent or child objects
let child=new String("str");
let parent={'a':'b' , 
        foo:function(){
                console.log(this,"parent foo here");
            }
};
Object.setPrototypeOf(child,parent);
// console.log(
// Object.getPrototypeOf(Object.getPrototypeOf(    Object.getPrototypeOf(s)))
// );
// console.log(Object.getPrototypeOf(child));
// console.log(parent.foo());
// console.log(child.foo());

// OUTPUT
// { a: 'b', foo: [Function: foo] }
// { a: 'b', foo: [Function: foo] } here
// undefined
// { '0': 's', '1': 't', '2': 'r' } here
// undefined



// POLYMORPHISM: same as other languages : child objects override function bodys
child.foo=()=>{console.log('child method overrides parent one')};
console.log(parent.foo());
console.log(child.foo());