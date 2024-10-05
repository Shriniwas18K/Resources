
// Shared sections
import Header from './shared/Header.tsx'
import Footer from './shared/Footer.tsx'


// landing page sections
import { Outlet } from "react-router-dom";

const Landing = () => {
  return (
  <>
    <Header/>
      <Outlet/>
    <Footer />
  </>
  );
};

export default Landing;
