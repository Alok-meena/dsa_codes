

we can also define the functions outside the class but not the variables they must be declared inside the class only

#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    void setValue(int v);  // Declaration
    int getValue();        // Declaration
};

// Definition of member functions outside the class
void MyClass::setValue(int v) {
    value = v;
}

int MyClass::getValue() {
    return value;
}

int main() {
    MyClass obj;
    obj.setValue(10);
    cout << "Value: " << obj.getValue() << endl;  // Output: Value: 10
    return 0;
}



we basically use scope resolution operator in these cases:-

  The **scope resolution operator (`::`)** in C++ is used to define or access members that are outside their immediate scope. It allows you to specify the context in which a member or function belongs. Here's a breakdown of its primary uses:

---

### 1. **Defining Member Functions Outside the Class**
Used to define a class's member function outside the class definition.

```cpp
class MyClass {
public:
    void display();  // Declaration
};

void MyClass::display() {  // Definition using ::
    cout << "Hello from MyClass!" << endl;
}
```

---

### 2. **Accessing Static Members of a Class**
Used to access or modify a static member variable or function of a class.

```cpp
class MyClass {
public:
    static int count;
};

int MyClass::count = 0;  // Define static member using ::

int main() {
    MyClass::count = 5;  // Access using ::
    cout << MyClass::count << endl;
    return 0;
}
```

---

### 3. **Accessing Global Variables or Functions When They Are Shadowed**
If a local variable or function has the same name as a global variable/function, the scope resolution operator can be used to access the global one.

```cpp
int value = 10;  // Global variable

int main() {
    int value = 20;  // Local variable
    cout << ::value << endl;  // Access global variable: Output 10
    return 0;
}
```

---

### 4. **Specifying a Namespace**
Used to access members of a specific namespace explicitly.

```cpp
#include <iostream>
namespace MyNamespace {
    int value = 42;
}

int main() {
    cout << MyNamespace::value << endl;  // Access namespace variable
    return 0;
}
```

---

### 5. **Accessing Class Members in Inheritance**
Used to explicitly call a base class's function or member in a derived class.

```cpp
class Base {
public:
    void display() { cout << "Base class" << endl; }
};

class Derived : public Base {
public:
    void display() {
        Base::display();  // Call Base class function
        cout << "Derived class" << endl;
    }
};
```

---

### 6. **For Enum Classes**
Access enum values from an enum class.

```cpp
enum class Color { Red, Green, Blue };

int main() {
    Color c = Color::Red;  // Access Red using ::
    return 0;
}
```

---

### Summary
The **scope resolution operator (`::`)** is primarily used for:
- Defining class member functions outside the class.

class MyClass {
public:
    void display();  // Declaration
};

void MyClass::display() {  // Definition using ::
    cout << "Hello from MyClass!" << endl;
}

- Accessing static members of a class.

  Used to access or modify a static member variable or function of a class.

cpp
Copy code
class MyClass {
public:
    static int count;
};

int MyClass::count = 0;  // Define static member using ::

int main() {
    MyClass::count = 5;  // Access using ::
    cout << MyClass::count << endl;
    return 0;
}


- Resolving global scope conflicts.

If a local variable or function has the same name as a global variable/function, the scope resolution operator can be used to access the global one.

cpp
Copy code
int value = 10;  // Global variable

int main() {
    int value = 20;  // Local variable
    cout << ::value << endl;  // Access global variable: Output 10
    return 0;
}
- Specifying namespaces.

  Used to access members of a specific namespace explicitly.

cpp
Copy code
#include <iostream>
namespace MyNamespace {
    int value = 42;
}

int main() {
    cout << MyNamespace::value << endl;  // Access namespace variable
    return 0;
}
- Accessing base class members in inheritance.

  Used to explicitly call a base class's function or member in a derived class.

cpp
Copy code
class Base {
public:
    void display() { cout << "Base class" << endl; }
};

class Derived : public Base {
public:
    void display() {
        Base::display();  // Call Base class function
        cout << "Derived class" << endl;
    }
};
- Accessing `enum class` values.

Access enum values from an enum class.

cpp
Copy code
enum class Color { Red, Green, Blue };

int main() {
    Color c = Color::Red;  // Access Red using ::
    return 0;
}


It helps in specifying the scope explicitly when there is ambiguity or when members/functions are defined outside their declaration scope.
