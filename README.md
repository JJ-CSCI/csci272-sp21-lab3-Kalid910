# Lab 3

## Task: Quaternion

The [quaternion](https://en.wikipedia.org/wiki/Quaternion) number system extends the complex numbers. It's the quotient of two directed lines in a three-dimensional space, or, equivalently, as the quotient of two vectors. Quaternions are generally represented in the form

a + b**i** + c**j** + d **k**

where a, b, c, and d are real numbers; and i, j, and k are the basic quaternions.

- Write a class that defines a quaternion and operations with it.

### Details

- Define a class `Quaternion` that will store 4 coefficients of quaternion
  - The default constructor must accept four `double`-typed parameters.
- Overload an equality operation for your class to compare two quaternion objects.
  - Compare corresponding coefficients of the quaternion objects, and return `true` if they are equal; otherwise return `false`.
  - The operator must accept constant reference to the `Quaternion` object.
- Overload an addition operation for your class to add two quaternion objects.
  - The operator must accept constant reference to the `Quaternion` object.
  - Add corresponding coefficients of the quaternion objects and return result.
    - The operator must return the `Quaternion` object. Do not modify current object.
- Overload a subtraction operation for your class to subtract two quaternion objects.
  - The operator must accept constant reference to the `Quaternion` object.
  - Subtract corresponding coefficients of the quaternion objects.
    - The operator must return the `Quaternion` object. Do not modify current object.
- Overload a multiplication operation for your class to multiply the quaternion object by a scalar number.
  - Multiply all coefficients of the quaternion object by the `double`-typed value
    - The operator must return the `Quaternion` object. Do not modify current object.
- All operators must be `const` members
- Make sure that your program compiles without errors

## Test

Press **Run** button to execute and test your program.

- Or run `make test` command in the command line to verify the correctness of your program.

## Submission

- Commit & push all changes that to the corresponding assignment repository on GitHub, using the **Repl.it** interface - **Version control** tab.
  - Make sure that you committed changes of the following files:
    - `main.cpp`
- Submit the link of the assignment GitHub repository in the corresponding assignment submission the Blackboard.

### Before You Submit

You are required to test that your submission works properly before submission. Make sure that your program compiles without errors. Once you have verified that the submission is correct, you can submit your work.

### Coding Style

In any programming project, matching the existing coding style is important. Having different coding styles intermixed leads to confusion and bugs. Students are required to follow the particular existing coding style that maintains the indentation style in `.cpp` and `.h` files using spaces, not tabs.

In particular, pay close attention to function declarations and how the function name begins the line after the function return type. For helper functions which are limited in scope to a specific file, you must declare the function as `static` in the same file in which it is used.

*Indentation*: The indentation style for your work have to be 4 spaces. Many students are taught to use tabs for indentation, which can make code very hard to read, especially when there are several levels of indentation.

For additional information of C++ coding style see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
