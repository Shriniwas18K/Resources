import { SplitScreen } from './SplitScreen'
import {FC} from 'react';
interface ChildPropType{
  msg:string;
}
const LeftHandComponent:FC<ChildPropType>=(msgprop)=><h1 style={{background:'green'}}>{msgprop.msg}</h1>;
const RightHandComponent:FC=()=><h1 style={{background:'red'}}>Right</h1>
function App() {
  return(
      <SplitScreen leftWeight={1} rightWeight={4}>
        <LeftHandComponent msg='Left Child'/>
        <RightHandComponent/>
      </SplitScreen>
  );
}
// Dont pass children component as props , instead use above syntax
// this allows to pass props to children components as well, and
// more developer friendly
// dont do below stuff is meaning of above lines
{/* <SplitScreen left={LeftHandComponent} right={RightHandComponent}/> */}
// This kind approach doesnot allow to pass props to child componentss
export default App
