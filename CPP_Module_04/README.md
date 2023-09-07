# CPP-Module-04

I don't want to set the world on fire 🔥

### Sub-typing polymorphism

- A virtual member function (or called method), where the definition is dynamic and will be done during the resolution.

### abstract classes

- An abstract class means some behaviours are abstract and some are not. The abstract class itself cannot be instantiated

- An abstract class is a class that cannot be instantiated and is usually implemented as a class that has one or more pure virtual (abstract) functions

- A pure virtual function is one which must be overridden by any concrete derived class. This is indicated in the declaration with the syntax "=0" in the member function's declaration. It is a way of forcing a contract between the class designer and the users of that class

- If a class only has pure virtual functions (and no data), it is called an ```interface```

  ### operator overloading

There are three ways to define operator overloading:
- **Member function**
  - A popular way to overload functions. As it is more of the spirit of object oriented programming and is a bit more efficient since the definition can directly reference member variables.
  - Since the operator is applied on a existing class object, the number of parameters to the operator is one less

- **Non-member function**
  - The function is defined outside of the class definition
  - All operands involved in the operator become the parameters. Binary operators can have 2 parameters and unary operators have 1 parameter
  - Operator cannot access private members in the parameters objects

- **Friend function**
    - Friend functions are declared within a class, but they are NOT class methods
    - A friend function is a regular function which has a privilege to access private members in the parameter objects

**Positional**
    - Even though there are three ways to overload operators, they're called the same way. The parameters to the operators are **positional**: the order of the parameters does matter.
    - So for operators whose 1st argument is not a class object, you must write them as friend or nonmember functions.

**Automatic type promotion**.
  - If an operator is expecting a class object but received a different type, if there's a constructor in the class which can convert it to the class, the conversion / promotion is automatically applied by the compiler.

**Rules on overloading operators**
- The following operator can only be overloaded as member functions: =, [], -> and ().
- The following operator cannot be overloaded: the dot operator (.), the scope resolution operator (::), sizeof, ?: and .*.
- You cannot create a new operator.
- You cannot change the number of arguments that an operator takes.
- You cannot change the precedence of an operator.
- An overloaded operator cannot have default arguments.

### Polymorphism

- The word means having many forms. It is the ability of a message(function / operator) to be displayed in more than one form. In C++, an operator or function can be given different meanings or functions.

- In C++, polymorphism is mainly divided into two types:
    - Compile time polymorphism (early binding / static polymorphism) - static in nature
    - Runtime polymorphism (late binding / dynamic polymorphism)
 
### Virtual functions (virtual keyword)

- By marking the function in the base class as ```virtual```, you have the possibility of overriding this function in the derived class. This is key to allow polymorphism to work.
- **Runtime cost for virtual functions**
  - Additional memory is required to store the V table, which allows us to dispatch to the correct function
  - Every time when we call a virtual function, we need to go through the V table to determine which function to map to use
 
  ### Interface & pure virtual functions (virtual keyword + "= 0")

- "= 0" makes a virtual function a pure virtual function

- It allows us to define a function in the base class that does not have an implementation, and force subclasses to implement that function

- An interface only contains unimplemented methods and acts as a template. It also makes it impossible to instantiate that class. We must instantiate a subclass that has the functions implemented. A derived class can only be instantiated when it implements all of the pure virtual functions
### Shallow vs Deep Copies

- [source](http://www.fredosaurus.com/notes-cpp/oop-condestructors/shallowdeepcopy.html)

- **A shallow copy of an object copies all of the member field values.** This works well if the fields are values, but may not be what you want for fields that point to dynamically allocated memory. The pointer will be copied, but the memory it points to will not be copied -- the field in both the original object and the copy will then point to the same dynamically allocated memory, which is not usually what you want. The default copy constructor and assignment operator make shallow copies.

- **A deep copy copies all fields, and makes copies of dynamically allocated memory pointed to by the fields.** To make a deep copy, you must write a copy constructor and overload the assignment operator, otherwise the copy will point to the original, with disasterous consequences.

- **If an object has pointers to dynamically allocated memory, and the dynamically allocated memory needs to be copied when the original object is copied, then a deep copy is required.**

- A class that requires deep copies generally needs:
      - A **constructor** to either make an initial allocation or set the pointer to NULL.
      - A **destructor** to delete the dynamically allocated memory.
      - A **copy constructor** to make a copy of the dynamically allocated memory.
      - An **overloaded assignment** operator to make a copy of the dynamically allocated memory.
### copy constructor

- The best practice is to use assignation operation inside the copy constructor, so there's no duplication
- It is important to remember that the copy constructor is a constructor : it initialises data i.e you have to initialise const attributes and call parent classes' constructors in it. Don't remember to initialise values.

### coplien form

- Coplien's form should always include a constructor that takes in no parameter. So if one class can only need to instantiated with parameters, That means either the default constructor must be private, or it must be declared but non-implemented, to comply with Coplien's form.

### virtual member function
- [What is a virtual member function?](http://www.cs.technion.ac.il/users/yechiel/c++-faq/overview-virtual-fns.html)

From an OO perspective, it is the single most important feature of C++:

A virtual function allows derived classes to replace the implementation provided by the base class. The compiler makes sure the replacement is always called whenever the object in question is actually of the derived class, even if the object is accessed by a base pointer rather than a derived pointer. This allows algorithms in the base class to be replaced in the derived class, even if users don't know about the derived class.

The derived class can either fully replace ("override") the base class member function, or the derived class can partially replace ("augment") the base class member function. The latter is accomplished by having the derived class member function call the base class member function, if desired.

### virtual destructor
- [When to set destructors virtual in base class?](http://www.cs.technion.ac.il/users/yechiel/c++-faq/virtual-dtors.html)

When someone will delete a derived-class object via a base-class pointer. In particular, here's when you need to make your destructor virtual:

- if someone will derive from your class,
- and if someone will say new Derived, where Derived is derived from your class,
- and if someone will say delete p, where the actual object's type is Derived but the pointer p's type is your class.

Confused? Here's a simplified rule of thumb that usually protects you and usually doesn't cost you anything: make your destructor virtual if your class has any virtual functions. Rationale:
- that usually protects you because most base classes have at least one virtual function.
- that usually doesn't cost you anything because there is no added per-object space-cost for the second or subsequent virtual in your class. In other words, you've already paid all the per-object space-cost that you'll ever pay once you add the first virtual function, so the virtual destructor doesn't add any additional per-object space cost. (Everything in this bullet is theoretically compiler-specific, but in practice it will be valid on almost all compilers.)

Note: in a derived class, if your base class has a virtual destructor, your own destructor is automatically virtual. You might need an explicitly defined destructor for other reasons, but there's no need to redeclare a destructor simply to make sure it is virtual. No matter whether you declare it with the virtual keyword, declare it without the virtual keyword, or don't declare it at all, it's still virtual.

BTW, if you're interested, here are the mechanical details of why you need a virtual destructor when someone says delete using a Base pointer that's pointing at a Derived object. When you say delete p, and the class of p has a virtual destructor, the destructor that gets invoked is the one associated with the type of the object *p, not necessarily the one associated with the type of the pointer.

### label virtual

- If a function/constructor is virtual in the base class, it's a better practice to label the same function / constructor virtual, to provide more visibilities.

### resources
- [operator overloading](https://condor.depaul.edu/ntomuro/courses/262/notes/lecture3.html)
- [polymorphism](https://www.cplusplus.com/doc/tutorial/polymorphism/)
- [virtual functions](https://www.programiz.com/cpp-programming/virtual-functions)
- [use recursion to create a deep copy of linked list](https://medium.com/spotthedifference/deep-copy-a-linked-list-b90d8376223f)
- [When can I use a forward declaration?](https://stackoverflow.com/questions/553682/when-can-i-use-a-forward-declaration)
- [What are forward declarations in C++?](https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c)
