# interpreter
Simple interpreter with table driven parser
---
## Parser table
|       | num | plus  | minus | mul   | div   | mod   | pow   | lp  | rp    | eol   | eoi   | unknown |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| stmt  | 0   | Error | Error | Error | Error | Error | Error | 0   | Error | 11    | 11    | Error   |
| expr  | 1   | Error | Error | Error | Error | Error | Error | 1   | Error | Error | Error | Error   |
| expr' | 11  | 2     |	3     | 11    | 11    | 11    | 11    | 11  | 11    | 11    | 11    | Error   |
| term  | 4   | Error | Error | Error | Error | Error | Error | 4   | Error | Error | Error | Error   |
| term' | 11  | 11    |	11    | 5     |	6     | 7     |	Error |	11  | 11    | 11    | 11    | Error   |
| fact  | 8   | Error | Error | Error | Error | Error | 9     |	8   | Error | Error | Error | Error   |
---
## Todo table
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
| 9   | pow_act   | term' | fact | pow   |
| 10  | lp	  | expr  | rp   |       |
| 11  |		  |       |      |       |
