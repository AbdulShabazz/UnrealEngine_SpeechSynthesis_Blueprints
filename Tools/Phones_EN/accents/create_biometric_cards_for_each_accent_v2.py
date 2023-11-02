"""
This module creates biometric cards for use in each accent.folder
"""


import os
from accent_folders import accent_folders
from accent_common_names import accent_common_names
from accent_folder_full_names import tld_names as accent_folder_full_names


for folder_string in accent_folders:
    try:
        # Check if the directory exists; if not, create it
        if not os.path.exists(folder_string):
            print(f"{folder_string} - The directory does not currently exist. Creating directory '{folder_string}'...")
            os.makedirs(folder_string)

        fn_string = "biometrics.txt"
        path_string = f"{folder_string}/{fn_string}"
        biometric_card_template = f"Name: {accent_common_names[folder_string]}\nAge: \nGender: \nCountry or Region of Origin: {accent_folder_full_names[folder_string]}\n"

        # Check if file exists; if not, create it
        with open(path_string, "w") as f:
            f.write(biometric_card_template)

    except Exception as e:
        print(f"{e}")
        continue
