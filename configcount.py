import fileinput


bgo=0
labr3=0


config = 'A'
configs = 8

fileout = open("configs.dat","w")

for i in range(configs):
	filein = open(config+".dat","r")

	
	
	for j,line in enumerate(filein):
		if j==0:
			if line[0]+".dat" !=filein.name:
				print("Configuration file name and file content do not match")	
		elif j<31:
			if line[0] == '0':
				bgo+=1
			elif line[0] == '1':
				labr3+=1
		
	filein.close()	

	print("Configuration "+config)
	print(str(bgo)+" BGO; "+str(labr3)+" LaBr3")


	

	fileout.write("Configuration "+config+", ")
	fileout.write(str(bgo)+" BGO detector(s), ")
	fileout.write(str(labr3)+" LaBr3 detector(s)\n")

	config = chr(ord(config)+1) # increasing config by one letter

	bgo=0
	labr3=0

	filein.close()
	
fileout.close()