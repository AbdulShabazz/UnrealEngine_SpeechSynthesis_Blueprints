from gtts import gTTS

phones = [
    'beat', 'bit', 'bait', 'bet', 'bat', 'Bob', 'bought', 'boat', 'book',
    'boot', 'bird', 'ago', 'but', 'buy', 'down', 'boy', 'roses',
    'deep', 'go', 'pea', 'tea', 'kick', 'vice', 'then', 'zebra', 'measure',
    'five', 'thing', 'so', 'show', 'love', 'cattle', 'race', 'want', 'when',
    'yard', 'mom', 'noon', 'sing', 'some', 'son', 'church', 'just',
    'help', 'batter'
]

print('Phones.Generator.EN v1.0.0.0')
for phone in phones:
    tts = gTTS(phone)
    tts.save(phone + '.EN.mp3')
    print(phone + ' completed')
# ph_file = phone + '.mp3'
# tts = gTTS(phone)
# tts.save(ph_file)
