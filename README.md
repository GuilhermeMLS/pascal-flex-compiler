## Pascal Flex Compiler

A Simplified Pascal compiler that uses [Flex](https://github.com/westes/flex.git) and [Bison](https://www.gnu.org/software/bison/) to compile code to MEPA (abbreviation for Pascal Execution Machine in Portuguese), which is a 
virtual machine to execute Simplified Pascal programs. Simplified Pascal is a subset of the Pascal programming language.

### Example:

Pascal Code (input):

```pascal
program type2 (input, output);
type banana = integer;
var b : banana;
   x  : integer;
begin
   x := 1;
   b:=1; 
	while b <=10 do
      begin
         if (x <= b) 
            then
            x:=x+1;
         write (x);
         b:=b+1;
      end
end.
```
MEPA code (output):

```
     INPP
     AMEM 1
     AMEM 1
     DSVS R00
R00: NADA 
     CRCT 1
     ARMZ 0, 1
     CRCT 1
     ARMZ 0, 0
R01: NADA 
     CRVL 0, 0
     CRCT 10
     CMEG
     DSVF R02
     CRVL 0, 1
     CRVL 0, 0
     CMEG
     DSVF R04
     CRVL 0, 1
     CRCT 1
     SOMA
     ARMZ 0, 1
     DSVS R03
R04: NADA 
R03: NADA 
     CRVL 0, 1
     IMPR
     CRVL 0, 0
     CRCT 1
     SOMA
     ARMZ 0, 0
     DSVS R01
R02: NADA 
     DMEM 2
     PARA
```

### Running the program

```bash
$ make clean
$ make
./compilador {simplified_pascal_file}
```
Notice: there are some Simplified Pascal files in the root directory:
- testebool.pas;
- type1.pas;
- type2.pas;
- type3.pas.
