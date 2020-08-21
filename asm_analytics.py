f = open("log", "r")
line = f.readline()
instruct=[]
operaciones=[]
repeticiones=[]
funciones=[]


while line:
    print(line)
    instruct=line.split("\t")
    if len(instruct)>2:
        ope=(instruct[2].split())[0]
        if ope in operaciones:
            repeticiones[operaciones.index(ope)]+=1
        else:
            operaciones.append(ope)
            repeticiones.append(1)    
    elif instruct[0].endswith(">:\n"):
        arr=instruct[0].split()
        funciones.append((arr[1])[1:-2]+"\t : Located at "+arr[0]+" addr")
    line = f.readline()
f.close()

print("\nYou have "+ str(len(operaciones)) +" kind of instructions in this object file:")
for x in operaciones:
    print(x+"\t: Executed "+str(repeticiones[operaciones.index(x)])+" times")

print("\nYou have "+str(len(funciones))+" functions:")
for x in funciones:
    print (x)


