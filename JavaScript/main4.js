// Fastest way to create prototype chains
const o={'seores':'trestes','etes':'iuei'};
// 1] use __proto__ way in the syntax { } curly braces constructs
const p = { b: 2, __proto__: o };
// 2] use constructor functions kind of approach
function Graph() {
  this.vertices = [];
  this.edges = [];
} 
Graph.prototype.addVertex = function (v) {
  this.vertices.push(v);
};
const g = new Graph();

console.log(p.__proto__);
// NOTE : Do not set anything using explicitely .__proto__ property to set parent object
p.__proto__="oroietoij";
p.__proto__=434.234;
// above two ways will prohibit the above two line by throwing error , as only any object can 
// be parent i.e. prototype of any object , and direct string and numeric literals are not objects
// instead here the prototype will not be changed by engine
// all objects are combination of these literals , i.e. those level 0 seven building blocks in main0.js
console.log(Object.getPrototypeOf(p));