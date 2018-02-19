# 1-�����ͼ���������
## 1.1-�ַ���
1.�����ţ����۵����Ż���˫���ţ��������Ķ����ַ���

2.lstrip()ɾ���ַ�������ߵĿո� 

rstrip()ɾ���ַ������ұߵĿո� 

strip()ɾ���ַ��������˵Ŀո� 

3.upper() �ַ���ȫ��д

lower() �ַ���ȫСд

## 1.2-����
4.**  (�˷�)

//  (����)

5.str(var) ת�����ַ���

## 1.3-ע��
> ʹ��**#**��

# 2-�б���
> �ã�[]������ʾ�б����ö������ָ����е�Ԫ��

1.����Ϊ-1ָ�����һ��Ԫ��

2.���б�ĩβ���Ԫ��
> .append()

3.���б��в���Ԫ��
> .insert(λ��,value)

4.ɾ���б��е�Ԫ��
> del �б���[λ��]

> .pop() �����б��е�ĩβԪ�ز�����

> .pop(λ��) �����б���ĳ��λ�õ�Ԫ�ز�����

> .remove(Ԫ����) ɾ���б���ĳ���ض�Ԫ��

5.����������
> .sort() 

> .sort(reverse = True) ���ֵ�˳��

6.��ʱ����
> .sorted() 

> .sorted(reverse = True) ���ֵ�˳��

7.���Ŵ�ӡ�б�
> .reverse() �����Ըı�

8.ȷ���б���
> len(�б�)

# 3-�����б�
1.�����б�
```python
for var in list:
    do something
```

2.range()����
> range(1,5) ���� **[1,5)**  

> range(2,11,2) ����[2,10]�ڵ�ż��

3.list()����
> list(range(...)) ���������б�[...]

4.�����б�ͳ�Ƽ���
> min(list)  
> max(list)  
> sum(list)  

5.�б����
> ���ڿ��ٴ��������б�
```python
squares = [value**2 for value in range(1,11)]
print(squares)
```

6.��Ƭ
```python
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[0:3])  # ['charles', 'martina', 'michael']
print(players[:4])   # ['charles', 'martina', 'michael', 'florence']
print(players[-3:]) # ['michael', 'florence', 'eli']
```
> ������forѭ����ʹ��

> �������������б�
```python
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]
```

7.Ԫ��
> ���壺���ɱ���б�
```python
dimensions = (200,50)
# �޷��ı� Ԫ�� �е�ֵ ������ ���ܸı�200Ϊ100��
# �����ܸı�Ԫ������ã����¸�ֵ��
```

# 4-if���
1.�����﷨
```python
if ����1:
    ���1
elif ����2��
    ���2
else:
    ���2
```
2.��Ϊ**True** ��Ϊ**Flase**

3.**and**Ϊ�� **or**Ϊ��

4.����ض�ֵ�Ƿ�������б���
```python
 value in list #���ز���ֵ
```
5.����ض�ֵ��**��**��������б���
```python
 value not in list #���ز���ֵ
```

6.ȷ���б��ǿյ�
```python
if list:
    # list��Ϊ�շ���True
else:
    # listΪ�շ���False
```

# 5-�ֵ�
1.�ֵ��ʽ
```python
alien_0 = {'color':'green', 'points':5} # ���������ֵ�Ե��ֵ�
``` 

2.���Ӽ�ֵ��
> alien_0[�¼�] = ��ֵ;

3.ɾ����ֵ��
> del alien_0[��]

4.�����ֵ�
> 1.�������Եļ�ֵ��
```python
user_0 = {
 'username': 'efermi',
 'first': 'enrico',
 'last': 'fermi',
 }

for key, value in user_0.items(): 
    # do something
```

> 2.�����ֵ��е����м�
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

> 3.��˳������ֵ��е����м�
```python
for name in sorted(favorite_languages.keys()): 
    # do something
```

> 4.�����ֵ��е�����ֵ
```python
for language in favorite_languages.values(): 
    # do something
```
> 5.�޳��ظ������
```python
for language in set(favorite_languages.values()): 
    do something
```

5.Ƕ��
> �ֵ���б�����໥Ƕ��

# 6-�û������whileѭ��
1.input()
> input(˵������ʾ����)

2.int()
> תint����

3.python2.7ʹ��raw_input()

4.while
```python
# �﷨
while ����1��
    ����

# ��������C
```

# 7-����
1.��������
```python
def greet_user(username):
    """��ʾ�򵥵��ʺ���""" #�ĵ��ַ�����docstring��
    print("Hello!" + username.title())

greet_user("lsc") 
```

2.����ʵ��
> 1.λ��ʵ��:��������λ��������

> 2.�ؼ���ʵ��:���ü�ֵ����ֵ������λ��˳��

> 3.Ĭ��ֵ

3.����ֵ

4.�����б�
> �����б���
```python
function_name(list_name[:])
```

5.��������������ʵ��
```python
def make_pizza(*toppings): # ����һ����Ϊtoppings�Ŀ�Ԫ�飬�����ܵ�������ֵ����װ�����Ԫ���С�
    """��ӡ�˿͵�����е���"""
    print(toppings)

make_pizza('pepperoni')
make_pizza('mushrooms','green peppers','extra cheese')
```
```python
**user_info # ����һ����Ϊuser_info�Ŀ��ֵ䣬�����ܵ������м�ֵ�Զ���װ�����Ԫ���С�
```

6.�������洢��ģ����
> 1.ʹ��**import**����ģ��

> 2.���÷�����**module_name.function_name()**

> 3.�����ض��ĺ�����**from module_name import function_0,function_1,function_2**

> 4.ʹ��as������ָ��������**from module_name import function_name as fn**

> 5.ʹ��as��ģ��ָ��������**import module_name as mn**

> 6.����ģ���е����к�����**from module_name import \***

# 8-��
1.����ʹ���ʵ��
```python
class Dog():
    # ���캯��
    def __init__(self, name, age):  #ÿ���ຯ�������в���self,����Ա���ظ�ֵ�������౾��
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
2.�̳�
```python
class ElectricCar(Car): #�̳�Car��ElectricCar
 """�綯�����Ķ���֮��"""

    def __init__(self, make, model, year):
        """��ʼ�����������"""
        super().__init__(make, model, year) #���ø���Ĺ��캯�� super()

my_tesla = ElectricCar('tesla', 'model s', 2016)
print(my_tesla.get_descriptive_name()) 
```

3.��д����ķ���
> ��������дһ��ͬ������

4.python��û��**new**,����ʵ��ֱ��**ClassName(paras)**

5.������
```python
from module_name import ClassName # ��ĳ��ģ�鵼��ĳ����
import module_name # ��������ģ��
from module_name import * #����ģ���е�������
```

# 9-�ļ����쳣
1.��ȡȫ���ļ�
```python
# with ��������� �ڲ���Ҫ�����ļ�����ر�
# ��ʹ��with����Ҫʹ��open()���close()
with open("pi_digits") as file_object
    contents = file_object.read() # read()�������Ƕ�ȡ����ļ���ȫ������
    print(contents.rstrip()) # read()������ĩ�᷵��һ�����ַ���������Ϊ���С�����ʹ�� rstrip()��ȥ��
```

2.���ж�ȡ�ļ�
```python
with open("pi_digits.txt") as file_object:
    for line in file_object: #�����ı�����
        print(line.rstrip())
```

3.�����ļ������б�
```python
with open("pi_digits.txt") as file_object:
    print(file_object.readlines()) # readlines() ����һ���б�
```

4.д����ļ�
```python
with open("1.txt","w") as file_object: # ��"w","a"��ģʽ
    file_object.write("123")
# ע��pythonֻ�����ļ���д���ַ���
```
5.�쳣���
```python
try:
    ����1
except �쳣����:
    ����2
else:
    ����2
```

5.ռλ��
> pass ʲô������

6.��JSON��ʽ�洢����
```python
import json 

json.dump(��Ϣ,�ļ�) # �洢�ļ�
json.load(�ļ�) # ��ȡ�ļ� 
```


