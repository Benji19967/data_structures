words:
# Create 100'000 words of length 20
	jot -r -c 2000000 a z | rs -g 0 20 > words.txt
