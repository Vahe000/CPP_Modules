# CPP-Module-03

Aaaaand... OPEN!

### inheritance introduction

- **Inheritance is the means by which you can create new classes by reusing and expanding on existing class definitions.**
- Inheritance is also fundamental to making ```polymorphism``` possible, and polymorphism is a basic feature of object-oriented programming.
- One class is derived from another by adding extra properties, by specialization and making the new class a specialized version of the more general class

### inheritance in classes

- A ```base class``` is also referred to as a ```superclass``` of a class that is derived from it and the ```derived class``` is a ```subclass``` of its base
- A derived class automatically contains all the data members of its base class, and (with some restrictions) all the function members. A derived class inherits the data members and function members of its base class

> base class and derived class

[![derived_class](https://cdn.programiz.com/sites/tutorial2program/files/cpp-inheritance.png)](https://github.com/achrafelkhnissi/CPP-Modules/wiki/Module03)

### access specifier (base class & class members)
- It determines how the members of the base class can be accessed within the derived class
- ```private```: members are totally private to the class. Not only can they not be accessed from outside of the base class, they also cannot be accessed from inside a class that inherits them
- ```protected```: members of a base class is accessible from within the derived class, but protected from outside interference
- Access to inherited members of a derived class object is not only determined by their access specification in the base class, but by both the access specifier in the base class and the access specifier of the base class in the derived class

- In general, there are three possibilities for the base class specifier:```public```, ```protected```, ```private```. If you omit the base base access specifier, the default is ```private```

- Being able to change the access level of inherited members in a derived class gives you a degree of flexibility, but remember that **you can only make the access level more stringent**, you can't relax the access level that is specifier in the base class

> Effect of the base class specifier on the accessibility of inherited members

[![access_specifier](https://prepinsta.com/wp-content/uploads/2022/03/Access-Specifiers-in-C.png)](https://github.com/achrafelkhnissi/CPP-Modules/wiki/Module03)

- In summary, you need to consider two aspects when defining a hierarchy of classes: **the access specifiers for the members of each class**, and **the base class access specifier in each derived class**

  ### multiple inheritance

- A derived class can have as many direct base classes as an application requires. This is referred to as ```multiple inheritance``` as opposed to ```single inheritance```, in which a single base class is used. Multiple inheritance is used much less frequently than single inheritance and in best avoided as much as possible.

> An example of multiple inheritance

[![multiple_inheirtance](https://i.stack.imgur.com/nVxgj.png)](https://github.com/achrafelkhnissi/CPP-Modules/wiki/Module03)

```C++
class CerealPack : public Carton, public Contents
{
	// details of the class...
};
```

- The CerealPack class will **inherit all the members of both base classes**, so this will include the members of the indirect base, Box. The constructors of inherited classes are called in the same order in which they are inherited. In this case, ```Carton```'s constructor will be called before ```Contents```' constructor

- The access level of each inherited member is determined by two factors: ```the access specifier of the member in the base class``` and ```the base class access specifier```.

