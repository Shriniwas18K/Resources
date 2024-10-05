import styled,{css} from 'styled-components';
const Button=styled.button`
    font-weight:bold;
    padding:2vw;
    border:none;
    ${props=> props.primarybtn && css`
        background:chartreuse;
        color:white;
    `}
`
export default Button;