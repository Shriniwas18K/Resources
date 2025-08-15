// nowadays traditional oopic inheritance is implemented
// using prototype inheritance
class Rectangle{
    #height; // private field
    width=0 ; // public field
    //thier values can be set using setter functions
    // we can retrieve values using getter functions
    constructor(h,w){
        this.#height=h;
        this.width=w;
        console.log(this.#height);
    }
    description(){console.log('rectangle');}
}

// we can inherit it into other class using extends
class Square extends Rectangle{
    static staticMember;
    static #privateStaticMethod(){}
    constructor(l){
        super(l,l);
    }
    #privateMethod(){}
    publicMethod(){ 
        // call parent class method
        super.description();
    }
    description(){console.log("square");}
}
let sq=new Square(1);
sq.publicMethod();
sq.description();

// Thus by syntaxes it resembles js OOPs are made analogous to
// traditiional OOPs , but underhood is prototype inheritance

// we can add typescript to resemble the syntax to traditional static type OOP
// in typescript decorators are just wrapper functions  that execute at runtime
// and can be used to make the wrapped objects(functions,literals) satisfy some
// requirements and conditions
// in case of multiple decorators , they are like compostion of mathematical functions
// @f @g @h
// function func(){}
// means f(g(h(func())))