# C++ coursework

My C++ assignments from SCE (2025). Each assignment folder is a self-contained program with its own `driver.cpp` or `main.cpp`.

| Folder | What it builds | Concepts |
| --- | --- | --- |
| [`01_Introduction_and_Basics`](01_Introduction_and_Basics) | Warm-up exercises on arrays and functions | dynamic arrays, pointers, functions |
| [`Class_Assigment_1`](Class_Assigment_1) | A `Time` class plus helpers for time differences and sorting | classes, constructors, function overloading |
| [`Class_Assigment_2`](Class_Assigment_2) | Restaurant ordering system (`Resturant`, `Order`, `Item`) | arrays of pointers, copy constructor, assignment operator, destructor |
| [`Class_Assigment_3`](Class_Assigment_3) | `Complex` numbers and a `ComplexArray` container | operator overloading, conversion operators |
| [`Class_Assigment_4/part1`](Class_Assigment_4/part1) | Zoo simulation with a menu, built on an abstract `Animal` hierarchy | inheritance, pure virtual functions, polymorphism |
| [`Class_Assigment_4/part2`](Class_Assigment_4/part2) | Generic `List<T>` with `Point` and template helpers | class and function templates, exceptions |

## Build and run

Each assignment compiles on its own with any C++17 compiler, for example:

```bash
g++ -std=c++17 -Wall Class_Assigment_3/*.cpp -o complex
./complex
```

## License

MIT
