javac Hello.java
javah -jni Hello
gcc -c -I"c:\jdk1.8.0_221\include" -I"c:\jdk1.8.0_221\include\win32" -o hello.o Hello.c
gcc -shared -o hello.dll hello.o hello.def
java Hello