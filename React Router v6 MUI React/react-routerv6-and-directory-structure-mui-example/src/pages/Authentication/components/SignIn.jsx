import { Paper as P, Typography as TG, Box as B, Link as L } from '@mui/material';
import * as React from 'react';
import { Link as RouterLink, useNavigate } from 'react-router-dom';
import { CustomEmailField as CEF} from '../shared/CustomEmailField';
import { CustomPasswordField as CPF} from '../shared/CustomPasswordField';
import SubmitButton from '../shared/SubmitButton'
import {signin} from '../services/signin';
// below are controlled components

export default function SignIn() {
  const [email, setEmail] = React.useState('');
  const [pwd, setPwd] = React.useState('');
  const activeUserOnDevice = localStorage.getItem('appwriteId')
  const navigate = useNavigate();

  React.useEffect(() => {
    activeUserOnDevice ? navigate('/dashboard/property/view-active-postings') : null
  }, [activeUserOnDevice])

  function handleSubmit(){
      const req={
        email:email,
        password:pwd
      }
      signin(req);
      
  }

  return (
    <>
      <P elevation={0} sx={{
        w: '100vw', minHeight: '100vh',
        display: 'flex', justifyContent: 'center', alignItems: 'center'
      }}>
        <P elevation={12} square={false}
          sx={{ maxWidth: { sm: '37vw' }, height: 'min-content', padding: { xs: 5, sm: 10 }, marginLeft: 1, marginRight: 1 }}>
          <TG variant='h4' sx={{ textAlign: 'center', padding: 4, fontFamily: 'serif' }}>
            Sign In to Shelter
          </TG>
          <CEF value={email} valueChangeHandler={
            (event) => {
              setEmail(event.target.value);
            }
          } />
          <CPF value={pwd} valueChangeHandler={
            (event) => {
              setPwd(event.target.value);
            }} />
          <SubmitButton title="Sign In" SubmitEventHandler={handleSubmit}/>
          <B sx={{ display: 'flex', justifyContent: 'space-around' }}>
            <B>
              <TG variant='caption'>New to Platform?</TG>
              <L to={'/auth/register'} component={RouterLink} variant="body2">
                Sign up
              </L>
            </B>
          </B>
        </P>
      </P>
    </>
  );
}
