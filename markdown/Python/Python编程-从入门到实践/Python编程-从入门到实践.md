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
