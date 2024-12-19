Jakarta is since inception of Java and Spring came later.To truly understand the deep relationship between Jakarta Servlets and Spring, we need to delve into the architectural details and how Spring leverages the Servlet API.

1. The Servlet API: The Low-Level Contract

  At its core, the Jakarta Servlet API (part of Jakarta EE) defines a set of interfaces and classes that provide a standard way for Java applications to interact with web servers. Key components include:   

Servlet: The fundamental interface that all servlets must implement. It defines methods like init(), service(), and destroy() that govern the servlet's lifecycle.
HttpServletRequest: Represents the client's request, providing access to request parameters, headers, cookies, etc.
HttpServletResponse: Represents the server's response, allowing the servlet to set headers, write data to the response body, etc.
ServletContext: Provides information about the web application's environment.
Filter: Allows interception of requests and responses for pre- and post-processing.
  Web containers (like Tomcat, Jetty, etc.) implement this API, providing the runtime environment for servlets.   

2. Spring MVC's DispatcherServlet: The Orchestrator

Spring MVC's DispatcherServlet is a crucial component that acts as the front controller for all incoming requests. It is itself a servlet, meaning it implements the Servlet interface and is managed by the servlet container.
Here's how the DispatcherServlet interacts with the Servlet API:
Request Reception: The servlet container receives an HTTP request and delegates it to the DispatcherServlet's service() method.
Request Processing: Inside the service() method, the DispatcherServlet:
Creates HttpServletRequest and HttpServletResponse objects (provided by the container).
Uses HandlerMapping to determine the appropriate controller to handle the request based on the URL.
Uses HandlerAdapter to invoke the chosen controller.
Uses ViewResolver to select a view for rendering the response.
Sends the response back to the client using the HttpServletResponse object.

3. Spring's Abstractions Over Servlets

While Spring MVC relies on the Servlet API, it provides higher-level abstractions to simplify web development:
Controllers: Instead of directly dealing with HttpServletRequest and HttpServletResponse, developers work with simple Java classes annotated with @Controller and methods annotated with @RequestMapping.
Data Binding: Spring automatically binds request parameters to controller method arguments, eliminating manual parsing.   
View Resolution: Spring provides mechanisms for resolving views (e.g., JSP, Thymeleaf, FreeMarker) based on logical view names returned by controllers.   
Exception Handling: Spring provides centralized exception handling mechanisms.   
  
4. Filters in Spring and Servlets

Filters, defined by the Servlet API, play a crucial role in request processing. Spring integrates with this by:
Allowing you to register filters that intercept requests before they reach the DispatcherServlet.
Providing its own filters (e.g., CharacterEncodingFilter, HiddenHttpMethodFilter) for common tasks.
Spring Security heavily relies on filters to implement security features.   
  
5. Spring Boot and Embedded Servlet Containers

Spring Boot simplifies the deployment of Spring applications by embedding servlet containers. This means the application runs as a standalone executable, eliminating the need for a separate servlet container installation.   
However, even in this scenario, the Servlet API is still fundamental. Spring Boot uses the embedded container's implementation of the Servlet API to handle web requests.   

Spring MVC is built on top of the Jakarta Servlet API. It uses the Servlet API's core components (Servlet, HttpServletRequest, HttpServletResponse, Filter) to handle HTTP requests and responses. However, it provides higher-level abstractions that make web development more efficient and less cumbersome than working directly with the Servlet API.
