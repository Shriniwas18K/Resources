// react models library is not required

import { Modal } from "./Modal"

// dont use modern html elements dialog poopover , they wont work in react
function App() {
  return (
    <>
    <Modal>
      <h3 style={{fontFamily:'sans-serif'}}>We are inside modal element, 
      we can click anywhere inside , but if we click 
      outside then modal closes, change this with use-case react component</h3>
    </Modal>
    </>
  )
}

export default App
