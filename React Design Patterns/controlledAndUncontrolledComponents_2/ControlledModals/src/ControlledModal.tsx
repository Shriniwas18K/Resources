import { FC } from "react";
import { styled } from "styled-components";
const ModalBase=styled.div`height:100vh;width:100vw;background:rgba(0,0,0,0.08);
backdrop-filter:blur(5px);display:grid;place-items:center; position:fixed;
z-index:1;top:0;left:0;`;
const ModalBody=styled.div`display:grid;place-items:center;height:fit-content;
width:fit-content;background:white;position:fixed;z-index:2;padding:10vw;`;
export const ControlledModal:FC<any>=({shouldShow,children,onRequestClose })=>{
    return shouldShow ? (
        <ModalBase onClick={onRequestClose}>
            <ModalBody onClick={(e)=>e.stopPropagation()}>
                    {children}
            </ModalBody>
        </ModalBase>) : null
}