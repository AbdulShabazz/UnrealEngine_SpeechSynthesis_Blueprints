import arpabet_phoneme_library as apl
import os


updateFilesFlag = "False"

def get_yes_or_no_confirmation(prompt : str):

    response_str = { "yes": "y", "y": "y", "no": "n", "n": "n" }
    valid_responses = {"yes": True, "y": True, "no": False, "n": False}

    response = input(prompt).lower()

    while True:
        if response in valid_responses:
            return response_str[response]
        else:
            print("Invalid response. Please enter 'yes' or 'no'.")

for ph in apl.arpabet_phone_library:

    foundation_class=f'''
#pragma once

#include "FPhone.h"

namespace ARPABETPhone
{{

    class {ph}_Base : public FPhone
    {{
    public:

        {ph}_Base()
        {{
        
        }}

        ~{ph}_Base()
        {{
        
        }}
    }};'''

    for ph2 in apl.arpabet_phone_library:

        transition_class = f'''

    class {ph}_to_{ph2} : public FPhone
    {{
    public:

        {ph}_to_{ph2}()
        {{
        
        }}

        ~{ph}_to_{ph2}()
        {{
        
        }}
        
    }};'''

        foundation_class += transition_class

    foundation_class += '\n}\n'

    if updateFilesFlag == "False" and os.path.exists(f"ARPABETPhone_{ph}.h"):
        if get_yes_or_no_confirmation(f"ARPABETPhone_{ph}.h and similar files already exists. Do you want to overwrite it? (yes/no)") == "y":
            updateFilesFlag = "True"
    else:
        updateFilesFlag = "Skip"

    if updateFilesFlag == "True":
        with open(f"ARPABETPhone_{ph}.h", 'w', encoding='utf-8') as f:
            f.write(foundation_class)
