Nowadays all products like Oracle databases or applications like web servers run in production either on-premises or cloud but both are dockerized always and use either manually orchastrated and managed kubernetes service.

Docker is software used for virtualization. It is software with similar concept to jvm like it can contain any os,any language,any product running inside its containers.These are parts of devops and CI/CD. From developers perspective its just important to know that we can download anything and run inside docker. 

As developer we often produce mock objects of results extracted from databases or apis. This approach of creating mock objects is called unit testing. But often there are times where our services are so integrated that result of what we do affects other services, in such cases when we need actual databases for testing or actual dependent services for testing our service in development then we prefer to install local copies of those actual dependent services and setup them running in our development environment.This all stuff becomes easy with docker as it facilitates these all installation and CI/CD stuff and we can use testcontainers platform.Such testing is called as integration testing, i.e how well our developed code works or integrates with other dependent services on it. See more use of test containers in https://testcontainers.com/getting-started/

Always use vscode as ide due to its excellant extensions, it contains excellant testing and debugging features. All courses on youtube teach to mock apis with postman in api development courses. But instead of that manually sending requests we should write tests which send multiple requests using spring testing , there we can put assertions whtere response body etc params match. Similarly use logging , by setting the required log level of the file logger of file or package under observation to DEBUG and setting all remaining loggers log leel to ERROR we can observe each step by step whats happening when each line of code runs.Use debugger it shows call stack , variables under observation , threads , memory during runtime. These all things make our work easy.

#### The iterative cycle of REST API development:
For every new feature:
1) write repository layer with all CRUD operations and test it
2) write controller layer and test it 
3) write service layer by taking out logic from controllers and test it
This cycle is important for robust development because actually REST APIs are just abstraction over database.Service layer is meant when there is too much logic else we dont even write service layer for small projects where all logic is manageable in controllers.
