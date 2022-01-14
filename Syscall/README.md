
# matrix_copy ( a custom system call )

matrix_copy is a custom system call that we are going to
add to the linux kernel source code

**mattix_copy syscall defination is in the System_call.c file**

## Explanation of the syscall code
- ### A system call defination always starts with this syntax
```bash
    SYSCALL_DEFINE4( ....... )
```
where 4 is the number of arguments that this syscall will receive, you can change that according to your code. e.g if your syscall only need 2
arguments then your defination would look something like this  ->    SYSCALL_DEFINE2
 
- ### Full signature of the system call
```bash
    SYSCALL_DEFINE4( matrix_copy, float**, matrix1, float**, matrix2, int, row, int ,column)
```

first argument in the parenthesis is always name of the syscall ( system call ) that we are going to add
**Notice** the comma between the Type of the varaibles and name of the varaible that's the syntax not a typo :)
i.e  **int, row**  

**here, I have passed 4 arguments :-**

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `matrix1` | `float**` | stores the address of float matrix1 (double float pointer) |
| `matrix2` | `float**` | stores the address of float matrix2 (double float pointer) |
|`row`      | `int`     | int varaible to stores the no of rows of the matrix |
|`column`      | `int`     | int varaible to stores the no of rows of the matrix |

- ###  Rest of the syscall body
```bash
    float temp[row][column];
```
temp is the temporary matrix that we are going to use to copy the matrix
fisrt we would copy the matrix1 into temp then from temp to the matrix2

```bash
    long copied = copy_from_user(temp, matrix1, row*column*sizeof(float) );
```
**copy_from_user(source , destination, size in bytes that needs to be copied)**
this is kernel system call that we have used to copy content of matrix1 to temp.
This will return 0 if system call has been executed successfully otherwise the number of 
bytes that couldn't be copied. Below if statment checks that and returns -1 if the copying fails
```bash
    if(copied){
		return -EFAULT;
	}

```
similar steps to copy form temp to matrix2

```bash
    long ret = copy_to_user(matrix2, temp, row*column*sizeof(float));
	
	if(ret){
		return -EFAULT;
	}

```
noice little difference between syscall here it is **copy_to_user**

```bash
    printk("matrix_copy executed successfully !!");

    return 0;

```
**printk()** will send message to the kernel if the syscall executed successfully

And if syscall executed successfully then in the end we are returning 0.

**So that was the detailed Explanation syscall definations**

## Author

- [@harjeet-blue](https://www.github.com/harjeet-blue)

