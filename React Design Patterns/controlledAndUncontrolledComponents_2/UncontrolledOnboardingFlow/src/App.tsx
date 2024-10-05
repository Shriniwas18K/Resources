import { FC } from "react"
import { UncontrolledOnboardingFlow } from "./UncontrolledOnboardingFlow"
import styled from "styled-components";
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
    <Button onClick={() => goToNext({ hairColor: 'Blonde' })}>Next</Button>
    </Card>
  </>)
}

function App() {
  return (
    <>
      <UncontrolledOnboardingFlow>
        <StepOne />
        <StepTwo />
        <StepThree />
      </UncontrolledOnboardingFlow>
    </>
  )
}

export default App
