shape=input("enter an operator: (circle rectangle triangle)") 
side1=int(input("enter the side1: "))
side2=int(input("enter the side2: "))
if(shape=='circle'):
     print(3.14*side1*side1) 
     print(2*3.14*side1)
elif(shape=='rectangle'): 
    print(side1*side2)
    print(2*(side1+side2))
elif(shape=='triangle'):
    print(0.5*side1*side2)  
    print(3*side2)
else:
    print(f"{shape} is not valid")
