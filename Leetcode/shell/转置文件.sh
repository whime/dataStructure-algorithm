#给定一个文件 file.txt，转置它的内容。
#你可以假设每行列数相同，并且每个字段由 ' ' 分隔.

awk '{
    # NF 表示列数，NR表示已读行数
    for(i=1;i<=NF;i++)
    {
        if(NR==1)
        {
            data[i]=$i;
        }
        else
        {
            data[i]=data[i] " " $i;
        }
    }
} END{
    for(i=1;i<=NF;i++)
    {
        # print自动换行，printf不换行
        print data[i];
    }
}' file.txt