# Test Plan For Assignment Four

## 1. Navigate to `/AssignmentFour` directory
```
cd AssignmentFour/
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

## 5. Compile `text_editor.cpp` into an object file
```
cl /c /EHsc text_editor.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/31a50e5e-30be-4f21-8e58-0961652f5894)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/5b7d9fdb-be04-4882-bd24-beb4792411fd)


## 6. Compile `text.cpp` into an object file
```
cl /c /EHsc text.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/32d1c6b6-1cfa-4910-9cc3-17c084fa5a40)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f1a4ee24-c1ce-48d5-84b8-d2835ebec23f)

## 7. Compile `command_line_interface.cpp` into an object file
```
cl /c /EHsc command_line_interface.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f2fd5880-6305-4fdb-a387-8156aca56c62)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/642d580f-6a9f-4353-b516-86d1c57954ec)

## 8. Compile `main.cpp` into an object file
```
cl /c /EHsc main.cpp
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/7eccb324-6606-4c33-89c3-d34b940dc98c)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/f6e09126-8db0-42cf-8523-d65fabf46333)

## 9. Link all object files together into an executable
```
cl main.obj caesar_cipher.obj text.obj command_line_interface.obj text_editor.obj /link caesar.lib
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/23ee49ce-7548-4677-9bc2-25319c2c81f7)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/1f2338b3-7009-4ba9-9edb-4e3358918515)

## 10. Run the executable file, and choose option `1` to add some text
```
.\main.exe
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/39bf209e-e496-4db8-99b4-aff8ffbeb129)

## 11. Choose option `3` to save the text to a file

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/ec883f76-357f-44f2-b254-0b2472168f83)

## 12. Choose option `20` to encrypt the text in the file

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/4d6e80e9-2868-4a53-8b69-36c6cc372ba8)

## 13. Choose option `21` to decrypt the text in a given file

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/3c04e1bc-60a5-47a9-8a84-cb5da3ec8042)

## 14. Compare the contents of `text.txt` and `decrypt.txt`

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/bcfe65c3-b3df-4b2e-af31-479b88e0a44c)
![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/9fe77e74-0ea6-4e50-801c-efb8c072dcef)


## 15. Cleanup the unnecessary files
```
del *.exp, *.dll, *.lib, *.obj, *.exe, decrypt.txt, encrypt.txt, text.txt
```

![image](https://github.com/gkazimirov396/Programming_Paradigms/assets/109133755/c505317c-4843-453e-9336-874342c49bdc)
