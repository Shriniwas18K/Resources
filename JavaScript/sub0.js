// objects as data structures or building blocks of js
// they store property:value pairs
// there are thre types of pairs
// 1] data properties(data members in traditional OOPs)
//      key : seven primitive values 
//      here we have everything public only (no private)
// 2] accessor properties(methods to manipulate data members in traditional OOPs)
//      key : functions
//      usually in modern js , function name becomes key , and its body becomes its value
//      usually these functions are getters and setters
// 3] __proto__ : `[[Prototype]]`



let obj= {
    internalData:[23534,5645,34,5],
    get sum(){
        let sum=0;
        this.internalData.map(e=>sum+=e)
        return sum;
    },
    set data(e){
        this.internalData.push(e);
    }
}
console.log(obj.sum);
obj.data=123432;
console.log(obj.sum);
// getter functions are not treated as functions , they are treated as literals directly
// similarly we have setters here , they are even not treated as functions to be called using () 
// The getter and setter functions can be sent into other functions to set this object's properties values

// we can delete getters and setters using delete keyword
delete obj.data;
console.log(obj)