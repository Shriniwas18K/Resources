import { FC } from "react";
import { person } from "./interfaces";
export const SmallPersonListItem:FC<person>=(personProp)=>{
    const {name,age}:person=personProp;
    return (
        <p>Name:{name}, Age:{age} years</p>
    );
}