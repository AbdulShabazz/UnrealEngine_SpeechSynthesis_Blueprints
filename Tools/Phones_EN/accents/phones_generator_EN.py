"""
Module to generate the phones for the English language.
"""
from multiprocessing import Pool
import tld as TopLevelDomain
import arpabet
from gtts import gTTS


def generate_audio(args: tuple):
    """
    Generates the audio files for the English language.
    """
    TopLevelDomain_string, filename_string = args
    # for TopLevelDomain_string in TopLevelDomain.tld:
    #    for filename_string in arpabet.arpabet.keys():
    try:
        word_string = arpabet.arpabet[filename_string]
        tts = gTTS(word_string, lang='en', tld=TopLevelDomain_string)
        tts.save(f'{filename_string}_EN_accent_{TopLevelDomain_string}.mp3')
    except Exception as e:
        print(f'{e}')


if __name__ == '__main__':
    with Pool() as p:
        comment = """
        Generates the audio files (accents) for the English language.
        """
        p.map(generate_audio, [(tld, fn) for tld in TopLevelDomain.tld for fn in arpabet.arpabet.keys()])
