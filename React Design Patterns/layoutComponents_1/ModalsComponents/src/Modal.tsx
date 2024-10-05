import {FC,useState} from "react"
import { styled } from "styled-components";
const ModalBackground=styled.div`
    background:rgba(0,0,0,0.3);
    height:100vh;
    width:100vw;
    display:flex;
    position:fixed;
    top:0;left:0;
    flex-flow:column-wrap;
    justify-content:center;
    align-items:center;
    backdrop-filter:blur(5px);
    z-index:1;
`;//background that covers page on opening modal
const ModalBody=styled.div`
    position:fixed;
    background:white;
    padding:5vw;
    z-index:2;
    height:fit-content;
    width:fit-content;
`;
export const Modal:FC<any>=({children})=>{
    const [shouldShow,setShouldShow]=useState<boolean>(false);
    return(<>
        <button onClick={()=>setShouldShow(!shouldShow)}>Toggle the modal</button>
        {shouldShow && (
        <ModalBackground onClick={()=>setShouldShow(!shouldShow)}>
            <ModalBody onClick={(e)=>e.stopPropagation()}>
                <button onClick={()=>setShouldShow(false)} 
                style={{color:'red' ,padding:'1vw' ,border:'none',fontSize:20}}>x</button>
                {children}
            </ModalBody>
        </ModalBackground>)}
    </>)
}