"""
This script moves all mp3 files from the current directory to the directory
specified by the filename in the mp3 file.
"""


import os
import shutil


def move_files_to_subfolder(directory_path_string: str):
    """
    Moves all mp3 files from the current directory to the directory
    specified by the filename in the mp3 file.
    """
    # Check if the directory exists
    if not os.path.exists(directory_path_string):
        raise FileNotFoundError("The directory does not exist.")

    for filename in os.listdir("."):
        # Check if the file is a .mp3 file
        try:
            if filename.endswith(".mp3"):
                # Extracting the final group of letters after the last underscore and before .mp3
                basename_without_extension_string = os.path.splitext(filename)[0]
                last_underscore_index = basename_without_extension_string.rfind("_")
                
                # Construct the new directory path
                destination_directory_path_string = basename_without_extension_string[last_underscore_index + 1:]

                # Check if the directory exists; if not, create it
                if not os.path.exists(destination_directory_path_string):
                    os.makedirs(destination_directory_path_string)
                
                # (re)Build the source and destination paths
                source_path_string = os.path.join(directory_path_string, filename)
                destination_path_string = os.path.join(destination_directory_path_string, filename)

                # Check if the file already exists in the destination directory; if not, move it
                if not os.path.exists(destination_path_string):
                    shutil.move(source_path_string, destination_path_string)
        except Exception as e:
            print(f"{e}")
            continue


if __name__ == '__main__':
    # Specify the directory containing the .mp3 files
    directory_path = '.'
    move_files_to_subfolder(directory_path)

