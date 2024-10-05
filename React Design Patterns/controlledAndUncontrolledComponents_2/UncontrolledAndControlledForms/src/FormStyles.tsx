// This component contains common reusable components of forms
import styled from 'styled-components';
// Interface to define the form data type
export interface FormData {
  name: string;
  age: number;
  hairColor: string;
}
export const Form=styled.form`
    display:flex;flex-flow:column wrap;
    justify-content:space-evenly;align-items:center;
    background:rgba(0,0,0,0.04);width:60vw;padding:2vw;
    font-family:Segoe UI,san-serif;
`;
export const Input=styled.input`
    width:50vw;padding:1vw;margin:1vw;
    border:1px solid white;border-radius:1vw;
`;
export const SubmitButton=styled.input`
    background:purple;width:20vw;color:white;padding:1vw;
    border:1px solid white;border-radius:1vw;margin:1vw;
`;
export const Error=styled.p`color:red;font-size:smaller;`;
export const ResetButton=styled.button`color:red;
background:rgba(0,0,0,0.04);border:none;font-size:smaller;`;
