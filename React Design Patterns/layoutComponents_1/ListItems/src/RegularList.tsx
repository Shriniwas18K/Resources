import { FC } from "react";
import { ReactElement } from "react";
interface RegularListProps{
    items:any[];
    resourceName:ReactElement|any;
    itemComponent:ReactElement|any;
};
export const RegularList:FC<RegularListProps>=({
    items,
    resourceName,
    itemComponent:ItemComponent,
})=>{
    return(<>
        {
            items.map((item,index)=>{
                <ItemComponent key={index} 
                 {...{[resourceName]:item}}/>
            })
        }
    </>)
};