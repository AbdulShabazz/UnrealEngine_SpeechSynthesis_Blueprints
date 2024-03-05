''' This script generates the ARPABETPhones.h file, which contains the'''
import os
import arpabet_phoneme_library as apl
import arpabet_phoneme_nonverbals_library as apnl
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

    # for ph2 in apl.arpabet_phone_library:

    #    transition_class = f'''

    # class ARPABETPhone_{ph}_to_{ph2} : public FPhone
    # {{
    # public:

    # }};'''

    #    foundation_class += transition_class

    if updateFilesFlag == "Ask":
        if os.path.exists("ARPABETPhones.h"):
            if get_confirmation.get_yes_or_no_confirmation("\
                    ARPABETPhones.h file already exists. \
                    Do you want to overwrite it? (yes/no)") == "y":
                updateFilesFlag = "True"
            else:
                updateFilesFlag = "False"
        else:
            updateFilesFlag = "True"


foundation_class += '\n\n\t\t// NONVERBALS //'

for ph in apnl.arpabet_phone_nonverbals_library:

    foundation_class += f'''

        /**
        @brief ARPABETPhone class for '{ph[0]}'
        @details {ph[0]}: {ph[1]} */
        class ARPABETPhone_{ph[0]} : public FPhone
        {{
        public:
            ARPABETPhone_{ph[0]}(){{}};
        }};'''


foundation_class += '\n\n\t\t// ARPABETPhone (NONVERBAL) APIs //'

for ph in apnl.arpabet_phone_nonverbals_library:

    foundation_class += f'''

        /** Activates speech synthesis channel phoneme functionality for nonverbal ( {ph[0]} ) */
        UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > {ph[0]}" ))
        void ARPABETSpeechSynthesis_{ph[0]}(
            UPARAM(DisplayName = "Voices") const int Voices)
        {{
            speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_{ph[0]}());
        }};'''


foundation_class += '\n\n}\n'

if updateFilesFlag == "True":
    with open("ARPABETPhones.h", 'w', encoding='utf-8') as f:
        f.write(foundation_class)
