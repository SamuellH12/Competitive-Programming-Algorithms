from sys import stdin

#NOTE: for corret results it is necesary a blank line in the end of archive
#https://rosalind.info/problems/gc/

data = {}
label = ''
dna = ' '
bigger = ''

for i in stdin:
    if i[0] == '>':

        #save the previous label-data and compare with currently the bigger
        data[label] = (dna.count('C') + dna.count('G'))*100/len(dna)

        if data[bigger] < data[label]:
            bigger = label

        #get the new label and reset the dna string
        label = i[1:len(i)-1]
        dna = ''
    else:
        #increase the dna string with the new information
        dna += i[0:len(i)-1]
        

#save the last label (that the above ifs don't get before)
data[label] = (dna.count('C') + dna.count('G'))*100/len(dna)
if data[bigger] < data[label]:
    bigger = label


print(bigger)
print(data[bigger])