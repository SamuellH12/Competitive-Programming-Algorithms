dna = input()
rev = ''

for x in dna:
    if x == 'A':
        rev = 'T' + rev
    elif x == 'T':
        rev = 'A' + rev
    elif x == 'C':
        rev = 'G' + rev
    elif x == 'G':
        rev = 'C' + rev
    
print(rev)