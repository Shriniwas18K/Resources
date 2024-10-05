import { FC,useContext } from 'react';
import styled from 'styled-components'
import { ParentContext } from '../../../../App';
// Note we cannot update value of state using this consumer component , we can
// only retrieve the value of state , for updation we need redux
const GreatGrandChildComponent: FC = () => {
    const countHereobj=useContext(ParentContext);
    return (<>
    <Section>
        <h3>I am GreatGrandChildComponent and value of 
            counter from Context is {countHereobj.field1.counter}</h3>
        </Section>
    </>);
}
 
const Section=styled.section`
background : red;padding:5vw;
`
export default GreatGrandChildComponent;