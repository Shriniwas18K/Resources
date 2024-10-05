// Register.tsx
import  { useState } from 'react';
import {
  Button,
  Link as MuiLink,
  Box,
  Paper,
  Typography,
  TextField,
} from '@mui/material';
import { Link as RouterLink } from 'react-router-dom';
import {CustomEmailField} from '../shared/CustomEmailField';
import {CustomPasswordField} from '../shared/CustomPasswordField';
import { signup } from '../services/signup';

const Register = () => {
  const [formState, setFormState] = useState({
    email: '',
    password: '',
    name: '',
    phone: '',
  });


  const handleInputChange = (event) => {
    const { name, value } = event.target;
    setFormState((prev) => ({ ...prev, [name]: value }));
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    const credentials = {
      email: formState.email,
      password: formState.password,
      phone: formState.phone,
      options: {
        data: {
          name: formState.name,
          emailRedirectTo: 'http://localhost:5173/dashboard'
        },
      },
    };
    await signup(credentials);
  };

  return (
    <Paper
      elevation={0}
      sx={{
        width: '100vw',
        minHeight: '100vh',
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center',
      }}
    >
      <Paper
        elevation={12}
        square={false}
        sx={{
          maxWidth: { sm: '37vw' },
          height: 'min-content',
          padding: { xs: 5, sm: 10 },
          marginLeft: 1,
          marginRight: 1,
        }}
      >
        <Typography variant="h4" sx={{ textAlign: 'center', padding: 4, fontFamily: 'serif' }}>
          Register to Shelter
        </Typography>
        <form onSubmit={handleSubmit}>
          <TextField
            required
            fullWidth
            label="Name"
            name="name"
            value={formState.name}
            onChange={handleInputChange}
            variant="outlined"
            type="text"
            size="small"
            sx={{ marginBottom: 2 }}
          />
          <TextField
            required
            fullWidth
            label="Phone"
            name="phone"
            value={formState.phone}
            onChange={handleInputChange}
            variant="outlined"
            type="text"
            size="small"
            sx={{ marginBottom: 2 }}
          />
          <CustomEmailField
            value={formState.email}
            valueChangeHandler={handleInputChange}
          />
          <CustomPasswordField
            value={formState.password}
            valueChangeHandler={handleInputChange}
          />
          <Button type='submit' variant='outlined' fullWidth>
            Register
          </Button>
          <Box sx={{ display: 'flex', justifyContent: 'space-around' ,m:2}}>
            <Box>
              <Typography variant="caption">New to Platform?</Typography>
              <MuiLink to="/auth/signin" component={RouterLink} variant="body2">
                Sign In
              </MuiLink>
            </Box>
          </Box>
        </form>
      </Paper>
    </Paper>
  );
};

export default Register;