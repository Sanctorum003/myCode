# 1-变量和简单数据类型
## 1.1-字符串
1.用引号（无论单引号还是双引号）括起来的都是字符串

2.lstrip()删除字符串里左边的空格 

rstrip()删除字符串里右边的空格 

strip()删除字符串里两端的空格 

3.upper() 字符串全大写

lower() 字符串全小写

## 1.2-数字
4.**  (乘方)

//  (整除)

5.str(var) 转换成字符串

## 1.3-注释
> 使用**#**号

# 2-列表简介
> 用（[]）来表示列表，并用逗号来分隔其中的元素

1.索引为-1指定最后一个元素

2.在列表末尾添加元素
> .append()

3.在列表中插入元素
> .insert(位置,value)

4.删除列表中的元素
> del 列表名[位置]

> .pop() 弹出列表中的末尾元素并返回

> .pop(位置) 弹出列表中某个位置的元素并返回

> .remove(元素名) 删除列表中某个特定元素

5.永久性排序
> .sort() 

> .sort(reverse = True) 逆字典顺序

6.临时排序
> .sorted() 

> .sorted(reverse = True) 逆字典顺序

7.倒着打印列表
> .reverse() 永久性改变

8.确定列表长度
> len(列表)

# 3-操作列表
1.遍历列表
```python
for var in list:
    do something
```

2.range()函数
> range(1,5) 生成 **[1,5)**  

> range(2,11,2) 生成[2,10]内的偶数

3.list()函数
> list(range(...)) 生成数字列表[...]

4.数字列表统计计算
> min(list)  
> max(list)  
> sum(list)  

5.列表解析
> 用于快速创建数字列表
```python
squares = [value**2 for value in range(1,11)]
print(squares)
```

6.切片
```python
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[0:3])  # ['charles', 'martina', 'michael']
print(players[:4])   # ['charles', 'martina', 'michael', 'florence']
print(players[-3:]) # ['michael', 'florence', 'eli']
```
> 可以在for循环中使用

> 可以用来复制列表
```python
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]
```

7.元组
> 定义：不可变的列表
```python
dimensions = (200,50)
# 无法改变 元组 中的值 （比如 不能改变200为100）
# 但是能改变元组的引用（重新赋值）
```

# 4-if语句
1.基本语法
```python
if 条件1:
    语句1
elif 条件2：
    语句2
else:
    语句2
```
2.真为**True** 假为**Flase**

3.**and**为且 **or**为或

4.检查特定值是否包含在列表中
```python
 value in list #返回布尔值
```
5.检查特定值是**不**否包含在列表中
```python
 value not in list #返回布尔值
```

6.确定列表不是空的
```python
if list:
    # list不为空返回True
else:
    # list为空返回False
```

# 5-字典
1.字典格式
```python
alien_0 = {'color':'green', 'points':5} # 包含两组键值对的字典
``` 

2.增加键值对
> alien_0[新键] = 新值;

3.删除键值对
> del alien_0[键]

4.遍历字典
> 1.遍历所以的键值对
```python
user_0 = {
 'username': 'efermi',
 'first': 'enrico',
 'last': 'fermi',
 }

for key, value in user_0.items(): 
    # do something
```

> 2.遍历字典中的所有键
```python
favorite_languages = {
 'jen': 'python',
 'sarah': 'c',
 'edward': 'ruby',
 'phil': 'python',
 }

for name in favorite_languages.keys():
    # do something

# for name in favorite_languages:
    # do something
```

> 3.按顺序遍历字典中的所有键
```python
for name in sorted(favorite_languages.keys()): 
    # do something
```

> 4.遍历字典中的所有值
```python
for language in favorite_languages.values(): 
    # do something
```
> 5.剔除重复项遍历
```python
for language in set(favorite_languages.values()): 
    do something
```

5.嵌套
> 字典和列表可以相互嵌套

# 6-用户输入和while循环
1.input()
> input(说明或提示文字)

2.int()
> 转int函数

3.python2.7使用raw_input()

4.while
```python
# 语法
while 条件1：
    语句块

# 其他都类C
```

# 7-函数
1.函数定义
```python
def greet_user(username):
    """显示简单的问候语""" #文档字符串（docstring）
    print("Hello!" + username.title())

greet_user("lsc") 
```

2.传递实参
> 1.位置实参:按参数的位置来关联

> 2.关键字实参:利用键值来赋值，无需位置顺序

> 3.默认值

3.返回值

4.传递列表
> 传递列表副本
```python
function_name(list_name[:])
```

5.传递任意数量的实参
```python
def make_pizza(*toppings): # 创建一个名为toppings的空元组，并将受到的所有值都封装到这个元组中。
    """打印顾客点的所有调料"""
    print(toppings)

make_pizza('pepperoni')
make_pizza('mushrooms','green peppers','extra cheese')
```
```python
**user_info # 创建一个名为user_info的空字典，并将受到的所有键值对都封装到这个元组中。
```

6.将函数存储在模块中
> 1.使用**import**导入模块

> 2.调用方法：**module_name.function_name()**

> 3.导入特定的函数：**from module_name import function_0,function_1,function_2**

> 4.使用as给函数指定别名：**from module_name import function_name as fn**

> 5.使用as给模块指定别名：**import module_name as mn**

> 6.导入模块中的所有函数：**from module_name import \***

# 8-类
1.定义和创建实例
```python
class Dog():
    # 构造函数
    def __init__(self, name, age):  #每个类函数必须有参数self,程序员不必赋值，代表类本身
        self.name = name  
        self.age = age 
    
    def sit(self):
        print(self.name + " sit")

    def askAge(self):
        print(self.name + ':' + self.age)

dog = Dog('lsc','21')
dog.sit()
dog.askAge()
```
2.继承
```python
class ElectricCar(Car): #继承Car的ElectricCar
 """电动汽车的独特之处"""

    def __init__(self, make, model, year):
        """初始化父类的属性"""
        super().__init__(make, model, year) #调用父类的构造函数 super()

my_tesla = ElectricCar('tesla', 'model s', 2016)
print(my_tesla.get_descriptive_name()) 
```

3.重写父类的方法
> 在子类中写一个同名函数

4.python中没有**new**,创建实例直接**ClassName(paras)**

5.导入类
```python
from module_name import ClassName # 从某个模块导入某个类
import module_name # 导入整个模块
from module_name import * #导入模块中的所有类
```

# 9-文件和异常
1.读取全部文件
```python
# with 块的作用是 在不需要访问文件后将其关闭
# 不使用with块需要使用open()配合close()
with open("pi_digits") as file_object
    contents = file_object.read() # read()的作用是读取这个文件的全部内容
    print(contents.rstrip()) # read()到达文末会返回一个空字符串，表现为空行。可以使用 rstrip()来去除
```

2.逐行读取文件
```python
with open("pi_digits.txt") as file_object:
    for line in file_object: #遍历文本对象
        print(line.rstrip())
```

3.利用文件创建列表
```python
with open("pi_digits.txt") as file_object:
    print(file_object.readlines()) # readlines() 返回一个列表
```

4.写入空文件
```python
with open("1.txt","w") as file_object: # 有"w","a"等模式
    file_object.write("123")
# 注意python只能在文件中写入字符串
```
5.异常检测
```python
try:
    语句块1
except 异常类型:
    语句块2
else:
    语句块2
```

5.占位符
> pass 什么都不做

6.以JSON方式存储数据
```python
import json 

json.dump(信息,文件) # 存储文件
json.load(文件) # 读取文件 
```


