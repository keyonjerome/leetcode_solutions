# for each string input, process the string character by character
# load its characters into a hash map which counts # of occurences of each character
# after fully processing the word into a hash map, load that hashmap into an array of hashmaps
# if the hashmap already exists in the array of hashmaps, append that word to a hashmap of anagramsa for that word


strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

allwordmaps = []
for word in strs:
	wordmap = {}
	for char in word:
		if wordmap.__contains__(char):
			wordmap[char]+=1
		else:
			wordmap[char]=1
	allwordmaps.append(wordmap)

print(allwordmaps)



