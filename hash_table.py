m=int(input("enter size of hash table : "))

def hash_func_1(x):
    key=x % m
    return key

def hash_func_2(x):
       key=p-(x%p)
       return key

def linear_hash(value,nam):
    num = []
    name = []
    for i in range(m):
        num.append(0)
        name.append(0)
    for i in range (len(value)):
        key=hash_func_1(value[i])
        while(num[key]!=0):
            key=(key+1)%m
        num[key]=value[i]
        name[key]=nam[i]
    display(name, num)

def get_prime(n):
    while True:
        if is_prime(n):
            return n
        n-=1

def is_prime(n):
    if n<=1:
        return False
    for i in range(2,int(n/2)+1):
        if n%i==0:
            return False
    return True

p=get_prime(m-1)

def double_hash(value, nam):
    num = []
    name = []
    for i in range(m):
        num.append(0)
        name.append(0)
    for i in range(len(value)):
        key1 = hash_func_1(value[i])
        if (num[key1] == 0):
            num[key1] = value[i]
            name[key1] = nam[i]
        else:
            key2 = hash_func_2(value[i])
            i=1
            while True:
                key = (key1 + i*key2) % m
                if num[key] == 0:
                    num[key] = value[i]
                    name[key] = nam[i]
                    break
                else:
                    key2 += hash_func_2(value[i])
                i=+1
    display(name,num)

def display(nam,no):
    print("index----->Name----->Number")
    for i in range(m):
        print(i, "---->", nam[i], "---->", no[i])

def main():
        n=int(input("enter no of clients : "))
        no=[]
        per=[]
        for i in range(n):
            p = input(f"enter name of client ({i+1}) : ")
            per.append(p)
            tel=int(input(f"enter telephone no ({i+1}) : "))
            while (tel<1000000000 or tel>9999999999):
                print("invalid number : ")
                tel = int(input(f"enter telephone no ({i+1}) : "))
            no.append(tel)
        flag=0
        while(flag==0):
            print("\n1)linear probing\n2)double hashing\n3)exit")
            ch=int(input("enter your choice : "))
            if ch==1:
                linear_hash(no,per)
            if ch==2:
                double_hash(no,per)
            if ch==3:
                flag=1

main()