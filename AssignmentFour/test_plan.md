# Test Plan For Assignment Four

## 1. Navigate to `/AssignmentFour` directory
```
cd AssignmentThree/AssignmentThree
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f63073b3-e088-4da6-ab3e-25af8cdc334a)

## 2. Compile `caesar.cpp` into an oblect file `caesar.obj`
```
cl /c /EHsc caesar.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/746e9e5f-d9c7-4ba9-9dc0-98aae8652dc4)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/b3dcf48e-1906-4dd5-a270-3b05ad5e3a11)

## 3. Link the object file caesar.obj to create a DLL. Create a `caesar.dll`, `caesar.lib`, `caesar.exp` files, so that other programs could get access to functions defined in `caesar.cpp`
```
cl /LD caesar.obj /link /OUT:caesar.dll
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/59381d52-4127-4b1a-93fb-a4b2471d14ac)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/2392182c-b154-49fd-b6b3-4d8de8c8b60a)

## 4. Compile `caesar_cipher.cpp` into an object file
```
cl /c /EHsc caesar_cipher.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/94b9e02b-8127-458e-a78d-f64c72ba2e13)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/5382b28d-f275-4aef-902b-587c9be7a9ba)

## 5. Compile `text.cpp` into an object file
```
cl /c /EHsc text.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/32d1c6b6-1cfa-4910-9cc3-17c084fa5a40)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f1a4ee24-c1ce-48d5-84b8-d2835ebec23f)

## 6. Compile `command_line_interface.cpp` into an object file
```
cl /c /EHsc command_line_interface.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f2fd5880-6305-4fdb-a387-8156aca56c62)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/642d580f-6a9f-4353-b516-86d1c57954ec)

## 7. Compile `main.cpp` into an object file
```
cl /c /EHsc main.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/7eccb324-6606-4c33-89c3-d34b940dc98c)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f6e09126-8db0-42cf-8523-d65fabf46333)

## 8. Link all object files together into an executable
```
cl main.obj caesar_cipher.obj text.obj command_line_interface.obj /link caesar.lib
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/23ee49ce-7548-4677-9bc2-25319c2c81f7)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/1f2338b3-7009-4ba9-9edb-4e3358918515)

## 9. Run the executable file
```
.\main.exe
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/0050e302-c2fa-4d72-9725-307468b791ea)

## 10. Choose `encrypt` option, and fill out the values

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/1a9aa894-b385-46e8-b20d-22ac8a8e66ef)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/e1e04b7c-fb9e-41a2-999d-eefcf1b64c1f)

## 11. Run the executable file
```
.\main.exe
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/0050e302-c2fa-4d72-9725-307468b791ea)

## 12. Choose `decrypt` option, and fill out the values

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/58994bbf-b34d-49e8-8be3-95b263135433)

## 13. Compare the text in `original.txt` and `decrypt.txt`

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/0b612aa7-e305-4551-b188-462a830eaf61)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/1f83803b-f5d3-48c4-8c3c-8cf9df3582ca)

## 14. Cleanup the unnecessary files
```
del *.exp, *.dll, *.lib, *.obj, *.exe, decrypt.txt, encrypt.txt
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/c505317c-4843-453e-9336-874342c49bdc)
