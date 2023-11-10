import arpabet_phoneme_library as apl

#apl = ["HH"]

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
    }}'''

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
        
    }}'''

        foundation_class += transition_class

    foundation_class += '\n}\n'

    with open(f"ARPABETPhone_{ph}.h", 'w', encoding='utf-8') as f:
        f.write(foundation_class)
