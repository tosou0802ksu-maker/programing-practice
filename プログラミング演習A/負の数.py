list1= [21,-6,56,11,-8,34]
list2= []
i = 0 
#for文を使って０以上の値だけリスト２に追加する
for i in list1:
    if i >= 0:
        list2.append(i)
#プリントする
print(list1)
print(list2)
