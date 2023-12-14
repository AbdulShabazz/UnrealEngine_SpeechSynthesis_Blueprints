import os
import arpabet_phoneme_library as apl
import get_yes_or_no_confirmation as get_confirmation


updateFilesFlag = "Ask"


foundation_class = '''
#pragma once

// This file is the Sara voice definition file. Todo: reimport as a .DLL

#include "FPhone.h"
#include "oscillatorConfig.h"

namespace ARPABETPhone
{'''

for ph in apl.arpabet_phone_library:

    foundation_class += f'''

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

    if updateFilesFlag == "Ask":
        if os.path.exists("ARPABETPhones.h"):
            if get_confirmation.get_yes_or_no_confirmation("ARPABETPhones.h file already exists. Do you want to overwrite it? (yes/no)") == "y":
                updateFilesFlag = "True"
            else:
                updateFilesFlag = "False"
        else:
            updateFilesFlag = "True"


foundation_class += '\n\n}\n'

if updateFilesFlag == "True":
    with open("ARPABETPhones.h", 'w', encoding='utf-8') as f:
        f.write(foundation_class)
