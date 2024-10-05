import { Box,Button,Typography } from "@mui/material";

import React from "react";
export default function NewPost() {
    return (<>
        <Button variant="contained" sx={{mt:10,mb:10}}>
                <Typography variant="h6" sx={{textAlign:'center',padding:10}}>email us at example@shelter.org</Typography>
            </Button>
        </>)
}