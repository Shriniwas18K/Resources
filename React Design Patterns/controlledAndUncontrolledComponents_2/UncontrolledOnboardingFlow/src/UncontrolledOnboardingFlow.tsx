import React, { FC, useState } from "react"
interface userdata{
    name:string;
    age:number;
    hairColor:string;
};
export const UncontrolledOnboardingFlow:FC<any>=({children})=>{
    const [onboardingData,setOnboardingData]=useState<userdata>({name:'',age:0,hairColor:''});
    const [currentIndex,setCurrentIndex]=useState<number>(0);
    const goToNext=(stepData:userdata)=>{
        const updatedData:userdata={...onboardingData,...stepData};
        if(currentIndex+1<children.length){
            setCurrentIndex(currentIndex+1);
            setOnboardingData(updatedData);
        }else{
            alert('You finished Onboarding');
            console.log(updatedData);
        }
    }
    const goToPrev=()=>currentIndex-1>=0 ? setCurrentIndex(currentIndex-1): null;
    const currentChild:any=React.Children.toArray(children)[currentIndex];
    return currentChild ? React.cloneElement(currentChild, { goToPrev,goToNext }) : currentChild;
}