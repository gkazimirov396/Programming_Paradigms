# Test Plan For Assignment Three

## 1. Navigate to `/AssignmentThree/AssignmentThree` directory
```
cd AssignmentThree/AssignmentThree
```

## 2. Compile `caesar.cpp` into an oblect file `caesar.obj`
```
cl /c /EHsc caesar.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/fd0ae54f-e905-4a91-8e52-6695fa11b247)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/a4c0407b-502b-4822-a352-1bc6c3c8e1de)

## 3. Link the object file caesar.obj to create a DLL. Create a `caesar.dll`, `caesar.lib`, `caesar.exp` files, so that other programs could get access to functions defined in `caesar.cpp`
```
cl /LD caesar.obj /link /OUT:caesar.dll
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/c7d5cac2-d75c-498b-b852-af6477ec33ea)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/d3df82af-54f9-4fad-a2a8-df087282217e)

## 4. Compile `main.cpp` and link it against the library `caesar.lib`, producing an executable `main.exe`
```
cl main.cpp /link caesar.lib
```
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/d4e05468-3ef4-4419-86bd-6bc238782383)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/0b742530-d66c-4877-a90a-3dee6e4b7dd8)

## 5. Run the executable file
```
.\main.exe
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/82c36335-d420-48ce-9c8a-ea9b3c986335)

## 6. Enter a text: "Roses are red"
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f9e6e1c4-1a39-4b2e-9ebc-4636324163c5)

## 7. Remove `main.exe`, `main.obj` files
```
del .\main.exe, .\main.obj
```

## 8. Test a static library. Open `CMakeLists.txt`, and replace: 
``` CMake
add_library(caesar SHARED caesar.cpp)
add_executable("AssignmentThree" main.cpp)
```
with
``` CMake
add_library(caesar STATIC caesar.cpp)
add_executable("AssignmentThree" main_static.cpp)
```
## 9.  Compile `main_static.cpp` and link it against the library `caesar.lib`, producing an executable `main_static.exe`
```
cl main_static.cpp /link caesar.lib
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/081435cf-a374-41b4-8c3a-0c0476f5525e)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/e535c22f-5d0d-40d5-bbc3-0db1f350f04a)

## 10. Run the executable file
```
.\main_static.exe
```
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/c625a382-67c2-4448-8a48-bbc055747b1f)

## 11. Enter a text: "Roses are red"
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f9e6e1c4-1a39-4b2e-9ebc-4636324163c5)
