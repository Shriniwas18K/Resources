import { FC, ReactElement } from "react"
import styled from 'styled-components';

const Container = styled.div`display:flex;font-family:sans-serif;color:white;`;
interface PaneWeight{
    children:ReactElement;
    weight:number;
};
const Pane:FC<PaneWeight>= styled.div`
    flex:${props=>props.weight};border:1vw solid purple;
`;
interface PropsType {
    children:[ReactElement,ReactElement];
    leftWeight:number;
    rightWeight:number;
}
export const SplitScreen: FC<PropsType> = ({
    children,
    leftWeight=1,
    rightWeight=1,
}) => {
    const [left,right]:[ReactElement,ReactElement]=children;
    return (
        <>
            <Container>
                <Pane weight={leftWeight}>
                    {left}
                </Pane>    
                <Pane weight={rightWeight}>
                    {right}
                </Pane>
            </Container>
        </>
    );
};