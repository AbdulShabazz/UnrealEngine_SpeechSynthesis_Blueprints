"""
This module creates biometric cards for use in each accent.folder
"""


import os
from accent_folders import accent_folders


BIOMETRIC_CARD_TEMPLATE = """
### Biometric Data Card

Name:
Age:
Gender:
Origins:
"""

for folder_string in accent_folders:
    try:
        # Check if the directory exists; if not, create it
        if not os.path.exists(folder_string):
            print(f"{folder_string} - The directory does not currently exist. Creating directory '{folder_string}'...")
            os.makedirs(folder_string)

        fn_string = "biometrics.txt"
        path_string= f"{folder_string}/{fn_string}"

        # Check if the directory exists; if not, create it
        if not os.path.exists(path_string):
            with open(path_string, "w") as f:
                f.write(BIOMETRIC_CARD_TEMPLATE)

    except Exception as e:
        print(f"{e}")
        continue
