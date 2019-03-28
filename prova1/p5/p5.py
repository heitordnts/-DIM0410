
def lexisort(s):
	a = ''.join(sorted(s))
	return a

frase = input()

splitted = frase.split()

mapa = {}

for word in splitted:
	key = lexisort(word)
	try:
		mapa[key] += 1
	except KeyError:
		mapa[key] = 0
		mapa[key] += 1
for k,v in mapa.items():
	print(k,v)

