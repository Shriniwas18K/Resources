### Recommended practices for Java SE project
- 1> use full power of vscode as ide. right click any file opened and click refactor in the menu and see available options
- 2> Always use Java17 with Gradle and IntelliJ only to build anything. Use maven to generate bytecode for any jdk version. Likely we can write java source code in any java version and use maven to compile the classes bytecode to desireded java version for runtime. This keeps us stable on java 17 but our code can run on java 22.
- 3> always write documentation of code written after each release and ensure it reaches users as web service.
- 4> be planned before writing that what we will do in project for each release(security,feature).
- 5> always throughly test code , write unit, integration tests using testing library of language before every release.
- 6> perform static analysis and code linting before pushing any code to repository , we can do this by setting up github actions workflow for the repository.
- 7> use github to track issues with diffirent labels and respond them by assigning and proper discussion.Always create Contributing.md guidelines for allowing people to contribute in the project.Always have github repository for every project, even later it can be made private if project goes obsolete.
- 8> Always have development sandbox (local development environment) to test new features or code that can be merged into repository.Dont go for cloud ides etc.They dont offer control on code written to that extent.Keep security standards of code written as LICENSE.md in repository.
- 9> If possible perform code reviews of every line.
- 10>Always write comments in code explaining what args,return,raise any function does,and for what module or the script is written,and for each section in the script like utility functions,driver code.They help in generating documentation using tools like Javadoc.
- 11> Everything should be packaged on github and deployed neatly on any platform or registery when projects are public.
- 12> Any project should have monolithic single repository always which can have many directorys to store code of microservices in it.Always develop any project as microservices only.It helps in code maintainence in long run.Each microservice can be part of repository or even outside repository.
- 13> use third party services if they provide free tier for sure for individual projects.use of PaaS is encouraged due to availability of sdks and good documentations like supabase for individual projects.use of IaaS is encouraged for large scale projects in industry with hybrid arhcitectures.
- 14> use github projects for kanban boards and planning.
- 15> the diffirence in production and development code is that production code is optimized containing only stuff that is minimal required to run with maximum functionality , whereas development code contains tests logging comments which are for intended for knowledge and debugging for developers , such stuff is not in production code.  
- 16> rather than using print statements use debugger that comes with the IDE, its the actual purpose of the IDE.
In industry always oracle database is used because it has ultra-amount of features. Check this website https://asrblogger.com/core_dba/. It contains many of oracle db features ppts for explaination.
