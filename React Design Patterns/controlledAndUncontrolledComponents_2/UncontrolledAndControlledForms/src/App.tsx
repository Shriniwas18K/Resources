import { ControlledForm } from "./ControlledForm"
import { UncontrolledForm } from "./UncontrolledForm"
// Both forms will use same styles
function App() {
  return (<>
    <h3>Uncontrolled Form</h3>
    <UncontrolledForm/>
    <h3>Controlled Form(has validation)</h3>
    <ControlledForm/>
  </>)
}

export default App
