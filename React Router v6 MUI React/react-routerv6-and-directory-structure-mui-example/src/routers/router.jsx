import { publicRoutes } from './public';
import { privateRoutes } from './private';
import { createBrowserRouter, createRoutesFromElements } from 'react-router-dom';


export const router = createBrowserRouter(
  createRoutesFromElements(
    <>
      {privateRoutes}
      {publicRoutes}
    </>
  )
)