import { useState } from "react"
import { ControlledModal } from "./ControlledModal"

function App() {
  const [showModal,setShowModal]=useState(false);
  return (
    <>
     <button onClick={()=>setShowModal(true)}>Click me</button>
     <ControlledModal shouldShow={showModal}
     onRequestClose={()=>setShowModal(false)}>
      <h1>Modal Content</h1>
     </ControlledModal>
    </>
  )
}

export default App
