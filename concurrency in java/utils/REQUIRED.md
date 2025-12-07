## Overview of Asynchronous Features in Java 8
- Lambda Expressions: Provide a clear and concise way to represent one-method interfaces using an expression.

- Functional Interfaces: Introduced several functional interfaces in the java.util.function package, like Function, Consumer, Supplier, and Predicate.

- Streams API: Allows processing sequences of elements in a declarative manner, supporting operations like map, filter, and reduce.

- Optional: A container object used to contain not-null objects, providing a way to represent optional values without explicitly using null.

- Date and Time API: Provides a comprehensive and user-friendly API for handling date and time, useful for managing time-based operations.

## Lambda Expressions

Lambda expressions provide a clear and concise way to represent one-method interfaces using an expression.

```java
List<String> list = Arrays.asList("a", "b", "c");
list.forEach(s -> System.out.println(s));
```

### Functional Interfaces
Functional interfaces such as Function, Consumer, Supplier, and Predicate allow for functional-style operations.

```java
Function<String, Integer> lengthFunction = String::length;
System.out.println(lengthFunction.apply("Hello")); // Output: 5
```

### Streams API
The Streams API allows for the processing of sequences of elements in a declarative manner.They allow intermeditte operations and terminal ones like collect,sum,etc

```java
List<String> list = Arrays.asList("a", "b", "c");
list.stream()
    .map(String::toUpperCase)
    .forEach(System.out::println); // Output: A B C
```

### Optional
The Optional class provides a way to represent optional values without explicitly using null.

```java
Optional<String> optional = Optional.of("Hello");
optional.ifPresent(System.out::println); // Output: Hello
```

### Date and Time API
The new Date and Time API provides a comprehensive and user-friendly way to handle date and time.

```java
LocalDateTime now = LocalDateTime.now();
```