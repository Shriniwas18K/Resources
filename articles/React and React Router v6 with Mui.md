### React and its powerful ecosystem
- When we deal with frontend using react then we deal ui library offering us to make ui using beautiful libraries like MUI,Material design components to avoid writing css. We can modify css using inline methods of writing css in js objects like sx prop in MUI components, style prop on any html or react components(faster development time and quick and comfortable for developers), or plain css file or tailwind using className attribute on all components(slow development time and more effort,recommended for very granular control on styles of ui).
- It provides us ui rendering stratergies using React Router v6 depending upon which way we choose above 
- 1> CLient Side Rendering for frontend only
- 3> SSR,ISR etc for hybrid architectures
React Router provides render diffirent components binded each with single route.We can create routes in two ways JSX and JSON.Recommended is JSON due to its more clarity and less redudant syntax.Use createBrowserRouter only(other routers arenot as useful as it , it is called data router in react router docs).Error pages can be binded using errorboundary.404 Error page can be bindedRoutes with no path and but only component are called layout components.It provides us Outlet component to use in layout components.Layout component can render default child component by adding index attribute to its route.
React router provides loader prop containing functions on each route to execute before mounting route element component on ui. That element component can make use data given loader using useLoaderData hook as well as if it has Outlet then it can pass that data down to child routes using context prop in Outlet component and access that data in child route element components using useOutletContext hook.
We can navigate someone depending on login or not using useNavigate hook and Navigate,Link component.
We can use Context Provider to pass data down to nested child components not routes.

NOTE : in react router , loaders and actions both are used to load data into element component of route before rendering. loaders functions are automatically executed when url is put in browser before rendering element component and it fetches some data generally which is accessed in element component using useLoaderData hook.we can trigger rendering of component from url to url using useNavigate hook or Navigate component. Whereas actions are functions that are executed or when form submissions are done using react router Form component.actions are same as loaders but only diffirence is loaders are triggered when someone uses useNavigate or redirect or Navigate or client visits url directly and actions are triggered by Form component submission. Dont think action as for handling validation and sending formdata to server.Actions are only meant loaders purposes only.Rather it is recommended to not use actions as thier functionality is 90% similar to loaders only but concept and its examples confuse them for handling form submissions.form submissions should be handled by submitevent handler functions inside the component where that form is defined and not use Form of react router instead use html form.Else whole form submission logic when using react router Form component must be defined in next loading route's action which introduces complexity and logic of submission needs to be kept diffirently where that next loading route after submission of form is written.Its hence recommended to not use actions and Form from react router but use loaders to prefetch data befoire rendering component.

Additionally whatever tokens we recieve from auth sdks functions like supabase can be stored as http-only cookies and localStorage and sessionStorage which can be easily accessed anywhere in codebase directly using getItem and setItem helping in navigation using react router i.e. if user does not have access token then can be redirected to login component or if has token token then to application.localStorage is persistent in browser of clients.
- Mui can mix with react router components like Link using component prop in Link etc Mui components.This can help lot in designing menus with MUI and navigation with Link as RouterLink of react router
- React has other ways as well like React with Redux, React with React Query but they were not used here.
- Content is distributed in src/pages/[section]. Each section directory can have three subdirectories,[section]/components containing all large number of lines components.[section]/shared can have small number of lines components shared or used among many large components in [section]/components and [section]/services should contain .js files
- directory structure recommended to use is
  C:\Users\Admin\Downloads\csr>cd src
<pre>
C:\Users\Admin\Downloads\csr\src>tree
Folder PATH listing
Volume serial number is FE03-A1CE
C:.
├───pages
│   ├───Authentication
│   │   ├───components
│   │   ├───services
│   │   └───shared
│   ├───Dashboard
│   │   ├───Notifications
│   │   ├───Profile
│   │   ├───Property
│   │   └───shared
│   │       └───Nav
│   │           ├───components
│   │           └───Drawer
│   └───Landing
│       ├───sections
│       │   └───HelpandSupport
│       │       └───FAQ
│       └───shared
│           └───icons
├───routers
└───utils
</pre>
There can be two types of routing used : centralized routing and distributed routing
- 1) centralized routing : All pages all components are imported and routing is done in src/routers/routers.jsx.Loaders and actions of components are defined in same directory in loaders.js and actions.js making
  <pre>
    routers
    └───routers.jsx
    └───actions.js
    └───loaders.js
  </pre>
- 2) distributed routing : All pages have their Main component as layout component which will render only shared sections and child routes.This Main component is responsible for data fetching and providing it to child routes components by using context and only this same Main component is imported into App.jsx.Every component stores its actions and loaders locally within its own directory.It is implemented in Shelter-Frontend repository.Officially React ecosystem and community accepts this mechanism as it helps in developing modular applications i.e. multi-page applications independently.
 
Always use formik to create forms they help in schema validation with yup and simplify much boilerplate of validation functions we write.Use new formik syntax as given in last section Reducing Boilerplate of https://formik.org/docs/overview


