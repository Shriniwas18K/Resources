import {useEffect} from 'react';
import {FC} from 'react';
import GrandChildComponent from './level2/GrandChildComponent';
import styled from 'styled-components';
interface localPropsType{
    num:number;
};
const ChildComponent:FC<localPropsType>=(props)=>{
    // component lifecycle
    // every component is has three cases
    // 1] when it first time renders/comes on ui , called as unmounting
    // 2] whenever its state changes due to setter function of state , then it is called re-rendering
    //    or showing the updated value of the state
    // 3] component is removed from ui , called as unmounting

    // suppose we want to trigger/execute some function in these all above stages
    // then comes useEffect hook 
    useEffect(()=>{
        console.log(props.num);
        return ()=>console.log('ChildComponent is updated and counter is',props.num);
    },[props.num]);
    // it takes two arguements
    // 1] callback function , i.e. the function to execute in all cases
    // 2] the states on which it has to keep watch or keep track of changing
    //    This function can be executed with multiple states , so 2nd arguement is 
    //    called dependencies array , it contains all states to keep track of thier changes

    // The function is executed whenever it this component (with useEffect hook) mounts
    // as well as whenever any of the state changes in dependencies array
    // The function is also called as side-effect

    // Inside callback function we can again return a callback function to execute
    // similarly we can deeply nest callbacks 
    // else we cannot return anything from these functions inside useEffect hook
    return (<>
        <Section>
        <h3>I am ChildComponent with useEffect hook</h3>
        <h1>{props.num}</h1>
        <GrandChildComponent/>
        </Section>
    </>)
}
const Section=styled.section`
padding:5vw;
background:green;
color:white;
`
export default ChildComponent;