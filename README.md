# descmd
DES command on command line.

Command
```
des -e/-d  Key  Data
```
Key and data are in hexa decimal


Source code of DES algorithm from. I just add the command line pprocesing part.
https://github.com/fffaraz/cppDES

example:

```
$ des -e 0102030405060708090A0B0C0D0E0F00 0102030405060708090A0B0C0D0E0F00
encrypting...
3DES double length
b9a8318df3e784ce1ba25078a08dac49
```
