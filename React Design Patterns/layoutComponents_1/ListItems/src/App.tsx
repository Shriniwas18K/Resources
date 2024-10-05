
// code written here is correct as typescript does not give errors here
// as well as no errors in console , still nothing is rendered on screen


import { RegularList } from "./RegularList"
import { SmallPersonListItem } from "./people/SmallPersonListItem"
import { LargePersonListItem } from "./people/LargePersonListItem"
import { person } from "./people/interfaces"
//look the way below code is formatted , use such formatting 
const persons: person[] = [{
  name: 'John Doe',
  age: 27,
  hairColor: 'blonde',
  hobbies: ['biology', 'medicine', 'gymnastics'],
},{
  name: 'Lorem Ipsum', 
  age: 10, 
  hairColor: 'scarlet', 
  hobbies: ['shield agent'],
},{
  name: 'Warren Buffet', 
  age: 77, 
  hairColor: 'white', 
  hobbies: ['economy', 'trading', 'news', 'forecasting'],
},]
function App() {
  return (
    <>
    <RegularList 
      items={persons}
      resourceName="personProp"
      itemComponent={SmallPersonListItem}/>
    <RegularList 
      items={persons}
      resourceName="personProp"
      itemComponent={LargePersonListItem}/>
    </>
  )
}
export default App
