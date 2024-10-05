/* eslint-disable react/prop-types */
/* eslint-disable no-unused-vars */
import { AccountCircle } from "@mui/icons-material";
import { TextField as TF, InputAdornment } from "@mui/material";
import React from "react";



export const CustomEmailField=({ value, valueChangeHandler })=>{
    return (
      <TF
        id="input-with-icon-textfield-controlled"
        label="Username"
        name="email"
        type="email"
        size="small"
        required
        fullWidth
        slotProps={{
          input: {
            startAdornment: (
              <InputAdornment position="start">
                <AccountCircle fontSize="inherit" />
              </InputAdornment>
            ),
          },
        }}
        value={value}
        onChange={valueChangeHandler}
        variant="outlined"
      />
    );
  }