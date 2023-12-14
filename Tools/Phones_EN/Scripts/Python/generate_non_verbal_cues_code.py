# Script to generate code for non-verbal cues in ARPABETSpeechSynthesis_nonverbals.h
import os
import non_verbal_cues as nvc
import get_yes_or_no_confirmation as get_confirmation


updateFilesFlag = "Ask"


def generate_code(list_non_verbal_cues: list) -> str:
    blueprint_code = ''
    class_code = ''
    for cue,desc in list_non_verbal_cues:
        # Format cue for class name (remove spaces and make first letter of each word uppercase)
        formatted_cue = cue.capitalize()

        # Generate blueprint function code
        blueprint_code += f'''
/** Activates speech synthesis channel phoneme functionality '{cue}' */
UFUNCTION(BlueprintCallable, Category = TextToSpeech, meta = ( keywords = "TTS, SpeechSynthesis, TextToSpeech", DisplayName = "ARPABETSpeechSynthesis: other > non-verbal > {cue}" ))
void ARPABETSpeechSynthesis_{formatted_cue}(
    UPARAM(DisplayName = "Voices") const int Voices)
{{
    speechSample_FPhoneVec.push_back(ARPABETPhone::ARPABETPhone_{formatted_cue}());
}};
'''

        # Generate class code
        class_code += f'''
/** 
@brief ARPABETPhone class for '{cue}'
@detailed {cue} -- {desc} */
class ARPABETPhone_{formatted_cue} : public FPhone
{{
public:
    ARPABETPhone_{formatted_cue}(){{}};
}};
'''

    # Combine both parts of the code
    full_code = blueprint_code + '\n' + class_code
    return full_code


if updateFilesFlag == "Ask":
    if os.path.exists("ARPABETSpeechSynthesis_nonverbals.h"):
        if get_confirmation.get_yes_or_no_confirmation("ARPABETSpeechSynthesis_nonverbals.h file already exists. Overwrite file? (yes/no)") == "y":
            updateFilesFlag = "True"
        else:
            updateFilesFlag = "False"
    else:
        updateFilesFlag = "True"

if updateFilesFlag == "True":
    # Generate code for non-verbal cues
    non_verbal_cues = nvc.NON_VERBAL_CUES

    # Sort the list alphabetically
    non_verbal_cues.sort()

    # Call the function and save the output to a file
    with open('ARPABETSpeechSynthesis_nonverbals.h', 'w') as file:
        code = generate_code(non_verbal_cues)
        file.write(code)

    print("Code generated and saved to ARPABETSpeechSynthesis_nonverbals.h\n Q.E.D.")
else:
    print("Code generation aborted.")
