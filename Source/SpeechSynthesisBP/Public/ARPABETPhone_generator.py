import os
import arpabet_phoneme_library as apl


updateFilesFlag = "False"


def get_yes_or_no_confirmation(prompt: str):
    '''Prompts the user for a yes or no response. Returns 'y' or 'n'. '''
    response_str = {"yes": "y", "y": "y", "no": "n", "n": "n"}
    valid_responses = {"yes": True, "y": True, "no": False, "n": False}

    response = input(prompt).lower()

    while True:
        if response in valid_responses:
            return response_str[response]
        else:
            print("Invalid response. Please enter 'yes' or 'no'.")


for ph in apl.arpabet_phone_library:

    foundation_class = f'''
#pragma once

#include "FPhone.h"
#include "oscillatorConfig.h"

namespace ARPABETPhone
{{

    class ARPABETPhone_{ph} : public FPhone
    {{
    public:

    }};'''

    for ph2 in apl.arpabet_phone_library:

        transition_class = f'''

    class ARPABETPhone_{ph}_to_{ph2} : public FPhone
    {{
    public:

    }};'''

        foundation_class += transition_class

    foundation_class += '\n\n}\n'

    if updateFilesFlag == "False" and os.path.exists(f"ARPABETPhone_{ph}.h"):
        if get_yes_or_no_confirmation(f"ARPABETPhone_{ph}.h and similar \
files already exists. Do you want to overwrite it? (yes/no)") == "y":
            updateFilesFlag = "True"
        else:
            updateFilesFlag = "Skip"

    if updateFilesFlag == "True":
        with open(f"ARPABETPhone_{ph}.h", 'w', encoding='utf-8') as f:
            f.write(foundation_class)
