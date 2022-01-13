# HARJEET SINGH YADAV
# IIIT-D , CSAI


SYSCALL_DEFINE4(matrix_copy, float**, matrix1, float**, matrix2, int, row, int ,column)
{
    float temp[row][column];

    long copied = copy_from_user(temp, matrix1, row*column*sizeof(float));
   	if(copied){
		return -EFAULT;
	}

    long ret = copy_to_user(matrix2, temp, row*column*sizeof(float));
	
	if(ret){
		return -EFAULT;
	}

    printk("matrix_copy executed successfully !!");

    return 0;
}