# interpreter
Simple interpreter with table driven parser

Due to peculiarity of the parser algebraic operation of same level (+ and -; *, / and %) executed in
reverse order. That is from rightmost to the leftmost, e.g. 2 * 9 / 3 fist will be calculated 9 / 3
and only then 2 * 3.

## Parser table
|       | num | plus  | minus | mul   | div   | mod   | lp  | rp    | eol   | eoi   | unknown |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| stmt  | 0   | Error | Error | Error | Error | Error | 0   | Error | 10    | 10    | Error   |
| expr  | 1   | Error | Error | Error | Error | Error | 1   | Error | Error | Error | Error   |
| expr' | 10  | 2     |	3     | 10    | 10    | 10    | 10  | 10    | 10    | 10    | Error   |
| term  | 4   | Error | Error | Error | Error | Error | 4   | Error | Error | Error | Error   |
| term' | 10  | 10    |	10    | 5     |	6     | 7     |	10  | 10    | 10    | 10    | Error   |
| fact  | 8   | Error | Error | Error | Error | Error | 9   | Error | Error | Error | Error   |
---
## Todo table
|     |           |       |      |       |
| :-: | :-------: | :---: | :--: | :---: |
| 0   | expr      |       |      |       |
| 1   | expr'     | term  |	 |       |
| 2   | plus_act  | expr' | term | plus  |
| 3   | minus_act | expr' | term | minus |
| 4   | term'     | fact  |      |       |
| 5   | mul_act   | term' | fact | mul   |
| 6   | div_act   | term' | fact | div   |
| 7   | mod_act   | term' | fact | mod   |
| 8   | num	  |	  |      |       |
| 9   | rp	  | expr  | lp   |       |
| 10  |		  |       |      |       |
