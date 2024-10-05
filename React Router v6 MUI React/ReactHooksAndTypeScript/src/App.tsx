import { useState } from 'react'
import { FC, createContext } from 'react';
import ChildComponent from './components/level1/ChildComponent';
import styled from 'styled-components';
import Button from './utilities/Button';
interface PropsType {
  num?: number; //this ? means optional variable
};
// Interfaces declared are scoped only to thier component of declaration
// To use else where they need to be redeclared

// Component heirarchy being followed here is
// App                                  level0
// |__ChildComponent                    level1
//    |__GrandChildComponent            level2
//       |___GreatGrandChildComponent   level3



// Always follow any component file structure as imports at top ,then js logic in 
// Functional Component , then markup in JSX returned from it , then below its
// CSS in styled components form



// Hooks are special functions built-in react that are to be declared
// only in top-level scope of functional Component


// suppose we want to pass the state to deeply nested child component then we use 
  // Provider in parent Component, and consume it where we require it below in component tree
  // using useContext hook
  const obj={ 
    field1:{
      msg:"hi i came from parent Component at top",
      counter:0
    },
  }
export const ParentContext = createContext(obj);


const App: FC<PropsType> = (props) => {
  const [count, setCount] = useState<number>(0);
  //state means values that change in ui
  //the value in any state is set using its setter function
  //useState hook takes default value of state at first render of component
  //and returns array with state variable and its setter function

  //suppose we listen onClick event of button and want to change the value of state
  //then we call the setter function inside another function that react executes
  //upon listening onClick event 
  return (
    <>
      <Section>
        <ParentContext.Provider value={obj}>
          <h3>I am ParentComponent</h3>
          <Button primarybtn onClick={
            () => {
              setCount(count + 1);
              obj.field1.counter=count+1;//this line only for explanation of useContext hook to give updated value, else ignore this line
            }
          }
          >Click me to increment counter by +1</Button>

          {/* Do not do below mistake and call the setter function directly */}
          {/* <Button onClick={
        setCount(count+1)
      }>
        +1
      </Button> */}

          <ChildComponent num={count} />
        </ParentContext.Provider>
      </Section>
    </>
  )
}

const Section = styled.section`
  padding : 10vw;
`;
export default App
