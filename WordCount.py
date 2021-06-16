
text = input("Enter some text : ")

text = text.replace('.', '')
text = text.replace(',', '')

List = text.split()


Set = set(List)
dic = {}

for ele in Set:
    dic[ele] = List.count(ele)
    print('[', ele, "->", dic[ele], end=']')
