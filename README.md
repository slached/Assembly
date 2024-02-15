***

## How To Use

There are 4 register called AX,BX,CX,DX

* HRK to insert data into register.
  (HRK AX,55)
* Math operators are;
    * **TOP** for `sum`.
    * **CIK** for `minus`.
    * **CRP** for `multiply`.
    * **BOL** for `divide`.
* Logical operators are;
    * **DEG** for `not`.
    * **VE** for `and`.
    * **VEYA** for `or`.

****
Example Usages;

| Registers | AX | BX | CX | DX |
|:----------|:--:|---:|----|----|
| HRK BX,52 | 0  | 52 | 0  | 0  |
| HRK CX,3  | 0  |  0 | 3  | 0  |
| TOP CX,BX | 0  | 52 | 55 | 0  |