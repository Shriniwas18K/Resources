import {FC,useRef} from 'react';
import styled from 'styled-components';
import GreatGrandChildComponent from './level3/GreatGrandChildComponent';
const GrandChildComponent:FC=()=>{
    const stateChangingWithoutRenders=useRef(0);
    // suppose we have a state whose value should change but its component should not re-render,
    // In such case we useRef hook , it means state changes but keeps same object
    // i.e. component does not render on state change
    // In such case the new value of state wont be seen or affected in ui
    // we need to use .current to get the value of state here, its built-in useRef hook
    return (<>
    <Section>
        <h3>I am GrandChildComponent with useRef hook</h3>
        <Button onClick={()=>{
            stateChangingWithoutRenders.current++;
            console.log('useRef is used so ui does not show the updated state value');
            console.log('current value for this stateChangingWithoutRenders is ',stateChangingWithoutRenders.current);
        }}>useRef button incrementer +1</Button>
        <h4>{stateChangingWithoutRenders.current}</h4>
        <GreatGrandChildComponent/>
        </Section>
    </>)
    // the updated current value the state made with useRef will be seen only when component re-renders
    // This may happen when someone of its parent component in the hierarchy re-renders ,
    // here that parents causing the re-render of this component are App.tsx and ChildComponent.tsx
}
const Section=styled.section`
background:orange;
padding:5vw;
`;
const Button=styled.button`
    background:#fff;
    color:#000;
    border:none;
    padding:1vw;
`
export default GrandChildComponent;