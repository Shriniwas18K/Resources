/* eslint-disable react/prop-types */
/* eslint-disable no-unused-vars */
import { VisibilityOff, Visibility } from "@mui/icons-material";
import { FormControl, InputLabel, OutlinedInput, InputAdornment, IconButton } from "@mui/material";
import React from "react";

export const  CustomPasswordField=({ value, valueChangeHandler }) =>{
    const [showPassword, setShowPassword] = React.useState(false);
  
    const handleClickShowPassword = () => setShowPassword((show) => !show);
  
    const handleMouseDownPassword = (event) => {
      event.preventDefault();
    };
  
    return (
      <FormControl sx={{ my: 2 }} fullWidth variant="outlined">
        <InputLabel size="small" htmlFor="outlined-adornment-password">
          Password
        </InputLabel>
        <OutlinedInput
          id="outlined-adornment-password"
          type={showPassword ? 'text' : 'password'}
          name="password"
          size="small"
          endAdornment={
            <InputAdornment position="end">
              <IconButton
                aria-label="toggle password visibility"
                onClick={handleClickShowPassword}
                onMouseDown={handleMouseDownPassword}
                edge="end"
                size="small"
              >
                {showPassword ? (
                  <VisibilityOff fontSize="inherit" />
                ) : (
                  <Visibility fontSize="inherit" />
                )}
              </IconButton>
            </InputAdornment>
          }
          value={value}
          onChange={valueChangeHandler}
          label="Password"
        />
      </FormControl>
    );
  }