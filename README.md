# interpreter
Simple interpreter with table driven parser
---
## Parser table
|       | num | plus  | minus | mul   | div   | mod   | pow   | lp  | rp    | eol   | eoi   | unknown |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| stmt  | 0   | Error | Error | Error | Error | Error | Error | 0   | Error | 11    | 11    | Error   |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| expr  | 1   | Error | Error | Error | Error | Error | Error | 1   | Error | Error | Error | Error   |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| expr' | 11  | 2     |	3     | 11    | 11    | 11    | 11    | 11  | 11    | 11    | 11    | Error   |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| term  | 4   | Error | Error | Error | Error | Error | Error | 4   | Error | Error | Error | Error   |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| term' | 11  | 11    |	11    | 5     |	6     | 7     |	Error |	11  | 11    | 11    | 11    | Error   |
| :---: | :-: | :---: | :---: | :---: | :---: | :---: | :---: | :-: | :---: | :---: | :---: | :-----: |
| fact  | 8   | Error | Error | Error | Error | Error | 9     |	8   | Error | Error | Error | Error   |
