import { useState,FC } from "react"
export interface userData{
  name:string;
  age:number;
  hairColor:string;
};
import styled from "styled-components";
import { ControlledOnboarding } from "./ControlledOnboardingFlow";
const Card=styled.div`display:grid;place-items:center; 
height:60vh;width:60vw;background:rgba(0,0,0,0.05);`;
const Button=styled.button`border:1px solid white;border-radius:1vw;padding:1vw;background:purple;color:white;`;
const StepOne: FC<any> = ({ goToNext }) => {
  return (<>
     <Card>
    <h1>Step 1</h1>
    <Button onClick={() => goToNext({ name: 'brtuiersuit' })}>Next</Button>
    </Card>
  </>)
}
const StepTwo: FC<any> = ({ goToPrev,goToNext }) => {
  return (<>
  <Card>
    <h1>Step 2</h1>
    <Button onClick={ ()=>goToPrev()}>Prev</Button>
    <Button onClick={() => goToNext({ age: 768 })}>Next</Button>
    </Card>
  </>)
}
const StepThree: FC<any> = ({ goToPrev,goToNext }) => {
  return (<>
  <Card>
    <h1>Step 3</h1>
    <Button onClick={ ()=>goToPrev()}>Prev</Button>
    <Button onClick={() => {goToNext({ hairColor: 'Blonde' })}}>Finish</Button>
    </Card>
  </>)
}
function App() {
  const [onboardingData,setOnboardingData]=useState<userData>({name:'',age:0,hairColor:''});
  const [currentIndex,setCurrentIndex]=useState<number>(0);
  const numberOfWindows:number=2;
  // we need to fix how to finish onboarding process , here we used temporarily numberOfWindows mechanism
  const onNext=(stepData:userData)=>{
    setOnboardingData({...stepData,...onboardingData});
    if(currentIndex+1==numberOfWindows){console.log(onboardingData);
    alert('Onboarding Done');}
    setCurrentIndex(currentIndex+1);
  }
  const onPrev=()=>setCurrentIndex(currentIndex-1);
  return (
    <>
      <ControlledOnboarding currentIndex={currentIndex} 
       onNext={onNext} onPrev={onPrev}>
        <StepOne/>
        {/* This way this step is dislayed only if name is admin i.e. we can
            do conditional rendering of steps */}
        {onboardingData.name=='admin' && <StepTwo/>}
        <StepThree/>
      </ControlledOnboarding>
    </>
  )
}

export default App
