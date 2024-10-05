import React,{ FC } from "react";
import { userData } from "./App";
export const ControlledOnboarding:FC<any>=({children,currentIndex,onNext,onPrev})=>{
    const goToPrev=()=>onPrev();
    const goToNext=(stepData:userData)=>onNext(stepData);
    const currentChild:any=React.Children.toArray(children)[currentIndex];
    return currentChild ? React.cloneElement(currentChild, { goToPrev,goToNext }) : currentChild;
}