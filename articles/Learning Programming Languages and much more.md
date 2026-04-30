### Learning Programming Languages

Read and learn language only from its documentation.It takes some time but it is the source and gives deep understanding of concepts.In all languages we have analogous concepts implemented that arent used by people but exist for sure. This way learn the language specific way of implementing concepts. Namely the main things that one should focus while learning language:
1) Type System and Generics: Cpp uses out of box templates and people are doing there all sorts of crazy stuffs using them, Java/Python supports covar,contravar,invar out of box generics. Strictly typed languages wont compile with errors like Rust,Java,Cpp. Python/JavaScript and dynamically typed languages have dual type system static and dynamic where they are actually interpreted hence compilation can be skipped.
2) Interfaces and OOP: GC based languages have root object class supporting entire APIs, whereas without GC not required root object class. Interfaces are supported in Cpp by header files,virtual things. Interfaces in Java are supported directly. Interfaces in Python are supported via Protocols, ABCs. OOP is supported in all languages but kind of language highly influences the underhood impl of OOP i.e. JavaScript and Python are purely functional and object oriented respectively hence everything there is function and object respectively and OOP is just syntactic sugar in JavaScript, whereas controllable in Python using metaclasses. Natural OOP of inheritance,polymorphism,static,overridding,overloading,reference casting,iterators is supported everywhere.
3) Memory Management: Understanding of reference counting and reference kinds mechanism weakrefs,strongrefs,scoping in GC based languages with root object class. Ownership and borrowing concepts in Cpp using std::move and {} based scoping and smart pointers and memory allocators and pmr allocators/arenas. In system level languages directly accessing memory and managing entire lifecycle of objects because no GC. This memory management is reason for very jargon codes boilerplate and bugs hence people prefer Python as cleaner option because being able to read is most important to understand when working under deadlines.
4) Data Structures and Algorithms library of the language and its ecosystem: Cpp has out of box STL alongside with boost DSA libraries. Java has JDK Collections used alongside with Guava/Apache Commons collections. Python has itertools,collections,heapq.
5) Functional Programming: This silently grew alongside the concurrency and event handling spectrums of the ecosystems. But today it stands for immutability and pure functions usage in terms of more maintainable code and one-directional data flow.

The programming languages are actually categorized in these terms:
Deep Inside product.
- 1> High Performance Computing level : Fortran,CUDA, procedural languages(purely imperative language)
- 2> Desktop applications OS GUI level : C/C++,Rust,Zig, systems level languages(OOP and imperative code mostly)
- 3> Platform Engineering API exposure level :  Java,C#,object oriented languages(OOPic code mostly)
- 4> web and backend level : nodejs,golang,Java,C#, concurrency asynchronous server langauges(OOPic + functional code)
- 5> Android and UI level : typescript,kotlin,dart(Mostly functional code), (javascript compulsory).
Outside on the user click.
Python acts as glue language used in everywhere. To make something rapidly working.

Now remember anything thats new service or product or library will always be made 1>,2>,3> languages and this occurs 95% only in product companies like Oracle,Google,etc. And bindings or sdks of those libraries or products will be made in high level languages. For example : Tensorflow made in C/C++ and used world wide using python. Using the low languages mostly mixes with other mathematical physics mechanical civil concepts and subjects and core CS subject stuffs.

3>,4>,5> languages are only used to make web,mobile,desktop applications,data processing and product sdks and most service based companies use these only. Mainly they use Java SE8. Using it is independent from core CS (knowledge of CS subjects is not required here) and even problem solving skills like gained by solving leetcode codeforces consistently are not at all required. Here only remembering where which api or function is located in which library and which is faster and where it is to be used is required. These languages have majorly builtin frameworks like Dart Flutter, Kotlin Android, Java Spring,C# .NET. Learn atleast one framework available with the language you choosen.

**Talking like of what happens is that, industry allows freshers only for Software Developer or Engineer role. In product company we the work by this way**
- 1>For any product we have its UI in Javascript as scripting language adding dynamic user interaction to the UI built in markup languages like XML,XAML,HTML.
- 2>And in the product we have server builtin or browser builtin which hosts the internal webpages or UI page(applets,hta,htm files) which runs the javascript.
- 3>The internal product code handles events and in response renders diffirent things on UI.
- 4>Also we have internal serialisations and data streaming and http client communication going on for data flow which involves message queues like rabbitmq,kafka,protobuf.
- 5>Jenkins or Azure devops pipelines run with automated building code of product, and running tests in it, 
- 6>Product interaction is by two ways, direct UI clicks which can be automated using selenium, directly use APIs which can be automated by writing tests in the language in which APIs are exposed.

**In short for joining as Software Engineer anywhere person should know one platform level language(Java), one systems level language(C++), one scripting language for UI(Javascript) , and Sequel(SQL) alongwith OOP Data Structures in platform or systems level language. Person should be proficient in these all languages.**

Moreover industry has very vast ecosystem evolved over 50 years of IT industry. Same website can be made in JSP and React too. But the boss in company decides what to use and its mostly React because community uses it though JSP is far more superior to it when using with material design 3(UI libary by google).

Depending on the area of your work decide which language you want to learn.

** Never go to do extraordinary thing anywhere because if we even wish to write something from scratch or make any modififcations in existing then we face large millions of lines of code and some existing solutions or products which are paid and have completed our wish far earlier than we wished. **

** One person cannot write everything or make revolutions or develop software products in least effort, only teams can do it that too when they are large enough in number and skilled. And everyone is doing career to earn money and settle , not to make revolutions , because even if someone makes revolution then too his name will be 100 years existing and later people will forget that too,because technology evolves everyday at rapid extent by combined efforts of millions of people. **
