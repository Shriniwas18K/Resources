/* eslint-disable react/prop-types */
/* eslint-disable no-unused-vars */
import { Button as B} from "@mui/material";


export default function SubmitButton({title,SubmitEventHandler}){
    return(
        <B
            type="submit"
            variant="outlined"
            color="info"
            size="small"
            disableElevation
            fullWidth
            onClick={SubmitEventHandler}
            sx={{ my: 2 }}
          >
            {title}
          </B>
    )
}