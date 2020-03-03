#给定一个包含电话号码列表（一行一个电话号码）的文本文件 file.txt，写一个 bash 脚本输出所有有效的电话号码。
#你可以假设一个有效的电话号码必须满足以下两种格式： (xxx) xxx-xxxx 或 xxx-xxx-xxxx。（x 表示一个数字）
#你也可以假设每行前后没有多余的空格字符。

# Read from the file file.txt and output all valid phone numbers to stdout.
#awk 不支持\d,可以使用[0-9],[[:digit:]],不过awk跑起来有点慢
#awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
#awk '/^([[:digit:]]{3}-|\([[:digit:]]{3}\) )[[:digit:]]{3}-[[:digit:]]{4}$/' \file.txt

# grep -P "^(\(\d{3}\) |\d{3}-)\d{3}-\d{4}$" file.txt
# grep -E "^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$" file.txt

# sed不使用-r需要转义{}
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
#sed -n '/^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$/p;/^([0-9]\{3\}) [0-9]\{3\}-[0-9]\{4\}$/p' file.txt